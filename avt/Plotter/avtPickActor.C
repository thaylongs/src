/*****************************************************************************
*
* Copyright (c) 2000 - 2017, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#include <avtPickActor.h>

#include <vtkActor.h>
#include <vtkFollower.h>
#include <vtkLineSource.h>
#include <vtkMultiLineSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkVectorText.h>
#include <vtkGlyphSource2D.h>
#include <DebugStream.h>

// ****************************************************************************
//  Constructor:  avtPickActor
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Thu Oct  3 14:41:19 PDT 2002 
//    Disable lighting by setting ambient/diffuse coefficients.
//
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003  
//    Added glyph for NodePicking. 
//
//    Brad Whitlock, Fri Aug 27 10:59:33 PDT 2010
//    Initialize designator.
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Added initialization for highlight for zone highlight 
//    actor, mapper and source
//
//    Matt Larsen, Tues July 18 08:11:01 PDT 2016 
//    Added initialization for showPickLetter
//
//    Matt Larsen, Mon September 19 08:34:22 PDT 2016
//    Changed glyph type to circle
// ****************************************************************************
avtPickActor:: avtPickActor()
{
    mode3D  = true;
    useGlyph  = false;
    showPickLetter = true;
    
    attach[0] = attach[1] = attach[2] = 0.;
    designator = "";

    //
    //  Set up the pipeline for the line actor.
    //
    lineSource  = vtkLineSource::New();
        lineSource->SetResolution(1);   // only need one line segment here
    lineMapper  = vtkPolyDataMapper::New();
        lineMapper->SetInputConnection(lineSource->GetOutputPort());
    lineActor   = vtkActor::New();
        lineActor->SetMapper(lineMapper); 
        lineActor->PickableOff(); 
        lineActor->GetProperty()->SetColor(0., 0., 0.);
        lineActor->GetProperty()->SetAmbient(1.);
        lineActor->GetProperty()->SetDiffuse(0.);

    letterActor = vtkFollower::New(); 
        letterActor->GetProperty()->SetColor(0., 0., 0.);
        letterActor->SetScale(0.5);
        letterActor->PickableOff();
        letterActor->GetProperty()->SetAmbient(1.);
        letterActor->GetProperty()->SetDiffuse(0.);

    glyphSource = vtkGlyphSource2D::New();
        glyphSource->SetGlyphTypeToCircle();
        glyphSource->CrossOff();
        glyphSource->FilledOn();
        glyphSource->SetScale(0.5);
    glyphMapper = vtkPolyDataMapper::New();
        glyphMapper->SetInputConnection(glyphSource->GetOutputPort());
        glyphMapper->ScalarVisibilityOff();
    glyphActor = vtkFollower::New();
        glyphActor->SetMapper(glyphMapper);
        glyphActor->SetScale(0.5);
        glyphActor->PickableOff();
        glyphActor->GetProperty()->SetColor(0., 0., 0.);
        glyphActor->GetProperty()->SetAmbient(1.);
        glyphActor->GetProperty()->SetDiffuse(0.);
    
    // Only create highlights if they exist
    highlightSource = NULL;
    highlightMapper = NULL;
    highlightActor = NULL;

    renderer = NULL; 
}


// ****************************************************************************
//  Destructor:  avtPickActor
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Delete glyphActor, glyphMapper, glyphSource
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Delete highlightActor, highlightSource,highlightMapper
//
// ****************************************************************************

avtPickActor::~avtPickActor()
{
    Remove();
    if (glyphActor != NULL)
    {
        glyphActor->Delete();
        glyphActor = NULL;
    }
    if (glyphMapper != NULL)
    {
        glyphMapper->Delete();
        glyphMapper = NULL;
    }
    if (glyphSource != NULL)
    {
        glyphSource->Delete();
        glyphSource = NULL;
    }
    if (letterActor != NULL)
    {
        letterActor->Delete();
        letterActor = NULL;
    }
    if (lineActor != NULL)
    {
        lineActor->Delete();
        lineActor = NULL;
    }
    if (lineMapper != NULL)
    {
        lineMapper->Delete();
        lineMapper = NULL;
    }
    if (lineSource != NULL)
    {
        lineSource->Delete();
        lineSource = NULL;
    }
    if (highlightSource != NULL)
    {
        highlightSource->Delete();
        highlightSource = NULL;
    }
    if (highlightMapper != NULL)
    {
        highlightMapper->Delete();
        highlightMapper = NULL;
    }
    if (highlightActor != NULL)
    {
        highlightActor->Delete();
        highlightActor = NULL;
    }
}



// ****************************************************************************
//  Method:  avtPickActor::Add
//
//  Purpose:  Add actors to the renderer, and renderer to this class.
//
//  Arguments:
//    ren     The renderer to use.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Add glyphActor to renderer when required.
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Add highlightActor to renderer.
//
// ****************************************************************************

void 
avtPickActor::Add(vtkRenderer *ren)
{
    renderer = ren;
    letterActor->SetCamera(renderer->GetActiveCamera());
    renderer->AddActor(letterActor);
    renderer->AddActor(lineActor);

    if(highlightSource != NULL) renderer->AddActor(highlightActor);
    if (useGlyph) 
    {
        glyphActor->SetCamera(renderer->GetActiveCamera());
        renderer->AddActor(glyphActor);
    }
}


// ****************************************************************************
//  Method:  avtPickActor::Remove
//
//  Purpose:  Remove actors from the renderer, and renderer from this class.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Remove glyphActor from renderer when required.
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Remove highlightActor
//
// ****************************************************************************

void 
avtPickActor::Remove()
{
    if (renderer != NULL)
    {
        if(useGlyph)
            renderer->RemoveActor(glyphActor);
        renderer->RemoveActor(lineActor);
        renderer->RemoveActor(letterActor);
        if(highlightSource != NULL) renderer->RemoveActor(highlightActor);
        renderer = NULL;
    }
}


// ****************************************************************************
//  Method:  avtPickActor::Shift
//
//  Purpose:  Shift the pickLetter towards the camera to avoid it being
//            obscured by the plot. 
//
//  Arguments:
//    vec     The vector to use for shifting.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Change glyph's position in 3d.
//
//    Kathleen Bonnell, Tue Jun  8 17:42:59 PDT 2004 
//    For 2d, use correct vec components. 
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Added highlightSource shift.
// ****************************************************************************

void 
avtPickActor::Shift(const double vec[3])
{  
    double newPos[3], newGlyphPos[3], shiftFactor ; 
    if (mode3D)
    {
        shiftFactor = 3.;     // completely arbitrary shift factor!!!
        newPos[0] = attach[0] + vec[0] *shiftFactor;
        newPos[1] = attach[1] + vec[1] *shiftFactor;
        newPos[2] = attach[2] + vec[2] *shiftFactor;
        newGlyphPos[0] = attach[0] + vec[0] *0.25;
        newGlyphPos[1] = attach[1] + vec[1] *0.25;
        newGlyphPos[2] = attach[2] + vec[2] *0.25;
    
        glyphActor->SetPosition(newGlyphPos[0], newGlyphPos[1], newGlyphPos[2]);
        if(highlightSource != NULL) highlightSource->Shift3d(vec, .7);
    }
    else
    {
        shiftFactor = 10.;    // completely arbitrary shift factor!!!
        newPos[0] = attach[0] + vec[0] *shiftFactor;
        newPos[1] = attach[1] + vec[1] *shiftFactor;
        newPos[2] = attach[2];
        double vec2[3];
        vec2[0] = 0.;
        vec2[1] = 0.;
        vec2[2] = vec[2];
        if(highlightSource != NULL) highlightSource->Shift2d(.1);
    }
    lineSource->SetPoint2(newPos[0], newPos[1], newPos[2]);
    letterActor->SetPosition(newPos[0], newPos[1], newPos[2]);
}

// ****************************************************************************
//  Method:  avtPickActor::SetMode3D
//
//  Purpose: Set mode (3d on or off). 
//
//  Arguments:
//    mode   True if 3d mode is on. 
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 26, 2002 
//
// ****************************************************************************

void 
avtPickActor::SetMode3D(const bool mode)
{
    mode3D = mode;
}

// ****************************************************************************
//  Method:  avtPickActor::SetAttachmentPoint
//
//  Purpose: Set actors' postion.
//
//  Arguments:
//    x, y , z   The attachment point in 3d world coordinates.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Wed Jun 25 15:12:24 PDT 2003 
//    Changed argument from double[3] to 3 doubles, set position for glyphActor.
//
// ****************************************************************************

void 
avtPickActor::SetAttachmentPoint(double x, double y, double z)
{
    attach[0] = x;
    attach[1] = y;
    attach[2] = z;
    lineSource->SetPoint1(x, y, z);
    letterActor->SetPosition(x, y, z);
    glyphActor->SetPosition(x, y, z);
}


// ****************************************************************************
//  Method:  avtPickActor::SetScale
//
//  Purpose:  Set the scale for letterActor.
//
//  Arguments:
//    s       The scale factor to use.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Set scale for glyphActor.
//
// ****************************************************************************

void
avtPickActor::SetScale(double s)
{
    letterActor->SetScale(s);
    glyphActor->SetScale(s);
}


// ****************************************************************************
//  Method:  avtPickActor::SetDesignator
//
//  Purpose:  Sets the designator for a pick.  In this instance it
//            is text for letterActor.
//
//  Arguments:
//    l       The designator string.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modification:
//    Brad Whitlock, Fri Aug 27 10:59:01 PDT 2010
//    Save the designator string.
//
// ****************************************************************************

void avtPickActor::SetDesignator(const std::string &l)
{
    designator = l;
    vtkVectorText *vecText = vtkVectorText::New();
    vecText->SetText(l.c_str());

    vtkPolyDataMapper *pickMapper = vtkPolyDataMapper::New();
    pickMapper->SetInputConnection(vecText->GetOutputPort());

    letterActor->SetMapper(pickMapper);

    pickMapper->Delete();
    vecText->Delete();
}

// ****************************************************************************
// Method: avtPickActor::GetDesignator
//
// Purpose: 
//   Return the pick's designator.
//
// Returns:   the pick's designator. 
//
// Programmer: Brad Whitlock
// Creation:   Fri Aug 27 10:57:26 PDT 2010
//
// Modifications:
//   
// ****************************************************************************

std::string
avtPickActor::GetDesignator() const
{
    return designator;
}

// ****************************************************************************
//  Method:  avtPickActor::SetForegroundColor
//
//  Purpose:  Set the actors' color.
//
//  Arguments:
//    fg         The rgb components of the foreground color.
//   
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Set color for glyphActor.
//
// ****************************************************************************

void avtPickActor::SetForegroundColor(double fg[3])
{
    letterActor->GetProperty()->SetColor(fg);
    lineActor->GetProperty()->SetColor(fg);
    glyphActor->GetProperty()->SetColor(fg);
}

// ****************************************************************************
//  Method:  avtPickActor::SetForegroundColor
//
//  Purpose: Set the actors' color.
//
//  Arguments:
//    r      The red component of the foreground color.
//    g      The green component of the foreground color.
//    b      The blue component of the foreground color.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Set color for glyphActor.
//
// ****************************************************************************

void 
avtPickActor::SetForegroundColor(double r, double g, double b)
{
    letterActor->GetProperty()->SetColor(r, g, b);
    lineActor->GetProperty()->SetColor(r, g, b);
    glyphActor->GetProperty()->SetColor(r, g, b);
}


// ****************************************************************************
//  Method:  avtPickActor::Hide
//
//  Purpose: Make the actors invisible.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Hide glyphActor.
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    hide highlightActor.
// ****************************************************************************

void 
avtPickActor::Hide()
{
    letterActor->VisibilityOff();
    lineActor->VisibilityOff();
    glyphActor->VisibilityOff();
    if(highlightSource != NULL) highlightActor->VisibilityOff();
}


// ****************************************************************************
//  Method:  avtPickActor::UnHide
//
//  Purpose:  Make the actors visible.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Unhide glyphActor.
//
//    Matt Larsen, Fri July 1 09:41:01 PDT 2016 
//    Unhide highlightActor.
//
//    Matt Larsen, Tues July 18 09:08:01 PDT 2016 
//    set visibility on only if pick letter is to be shown
//
// ****************************************************************************

void 
avtPickActor::UnHide()
{
    if(showPickLetter)
    {
        letterActor->VisibilityOn();
        lineActor->VisibilityOn();
    }
    
    glyphActor->VisibilityOn();
    if(highlightSource != NULL) highlightActor->VisibilityOn();
}


// ****************************************************************************
//  Method:  avtPickActor::UpdateView
//
//  Purpose:   Peform whatever updates are necessary when the view changes.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    March 22, 2002 
//
//  Modifications:
//    Kathleen Bonnell, Wed May  8 13:50:44 PDT 2002
//    Removed call to ComputeScaleFactor.  Now handled by VisWinQuery.
//
// ****************************************************************************

void 
avtPickActor::UpdateView()
{
    // nothing for now. 
}


// ****************************************************************************
//  Method:  avtPickActor::Translate
//
//  Purpose:   Translates the actor by the given vector. 
//
//  Arguments:
//    vec      The vector to use in translating the actor.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    June 6, 2003
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Translate the glyphActor.
//
//    Kathleen Bonnell, Fri Feb 20 12:34:39 PST 2004 
//    Handle 3D lineSource's Pt1 differently than 2D. 
//
//    Kathleen Bonnell, Fri Feb 20 12:34:39 PST 2004 
//    Handle 2D glyphActor's position differently than 3D. 
//
// ****************************************************************************

void 
avtPickActor::Translate(const double vec[3])
{
    double *newPos = letterActor->GetPosition();
    newPos[0] *= vec[0];
    newPos[1] *= vec[1]; 
    newPos[2] *= vec[2];

    newPos = lineSource->GetPoint1();
    if (mode3D)
    {
        newPos[0] *= vec[0];
        newPos[1] *= vec[1]; 
        newPos[2] *= vec[2];
    }
    else
    {
        newPos[0] = attach[0] * vec[0];
        newPos[1] = attach[1] * vec[1]; 
        newPos[2] = attach[2] * vec[2];
    }

    newPos = lineSource->GetPoint2();
    newPos[0] *= vec[0];
    newPos[1] *= vec[1]; 
    newPos[2] *= vec[2];

    newPos = glyphActor->GetPosition();
    if (mode3D)
    {
        newPos[0] *= vec[0];
        newPos[1] *= vec[1]; 
        newPos[2] *= vec[2];
    }
    else
    {
        newPos[0] = attach[0] * vec[0];
        newPos[1] = attach[1] * vec[1]; 
        newPos[2] = attach[2] * vec[2];
    }

    lineSource->Modified();
}


// ****************************************************************************
//  Method:  avtPickActor::ResetPosition
//
//  Purpose:   Resets the actor's position to the original location, including
//             Shifting towards the camera. 
//
//  Arguments:
//    vec      The vector to use in Shifting the actor. 
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    June 6, 2003
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:57:45 PDT 2003 
//    Reset glyphActor's position.
//
// ****************************************************************************

void 
avtPickActor::ResetPosition(const double vec[3])
{
    lineSource->SetPoint1(attach[0], attach[1], attach[2]);
    letterActor->SetPosition(attach[0], attach[1], attach[2]);
    glyphActor->SetPosition(attach[0], attach[1], attach[2]);
    Shift(vec);
}

// ****************************************************************************
//  Method:  avtPickActor::GetLetterPosition
//
//  Purpose:   Retrieve the position of the letterActor. 
//             Useful for determining scale factor.
//
//  Programmer:  Kathleen Bonnell 
//  Creation:    June 8, 2004
//
//  Modifications:
//
// ****************************************************************************

const double * 
avtPickActor::GetLetterPosition()
{
    return letterActor->GetPosition();
}

// ****************************************************************************
//  Method:  avtPickActor::AddLine
//
//  Purpose:  Adds a line for a zone highlight 
//            
//
//  Programmer:  Matt Larsen 
//  Creation:    June 30, 2016
//
//  Modifications:
//
// ****************************************************************************

void
avtPickActor::AddLine(double p0[3], double p1[3])
{
    if(highlightSource == NULL)
    {
        highlightSource = vtkMultiLineSource::New();
        highlightMapper = vtkPolyDataMapper::New();
            highlightMapper->SetInputConnection(highlightSource->GetOutputPort());
        highlightActor = vtkActor::New();
        highlightActor->SetMapper(highlightMapper);
            highlightActor->PickableOff(); 
            highlightActor->GetProperty()->SetColor(1., 0., 0.);
            highlightActor->GetProperty()->SetAmbient(1.);
            highlightActor->GetProperty()->SetDiffuse(0.); 
            highlightActor->GetProperty()->SetLineWidth(3.);
    }
   
    highlightSource->AddLine(p0,p1);
}

// ****************************************************************************
//  Method:  avtPickActor::GetShowPickLetter
//
//  Purpose: returns a boolean indicating if rhe pick letter is show
//            
//
//  Programmer:  Matt Larsen 
//  Creation:    July 18, 2016
//
//  Modifications:
//
// ****************************************************************************

bool
avtPickActor::GetShowPickLetter() const
{
   return showPickLetter;
}

// ****************************************************************************
//  Method:  avtPickActor::SetShowPickLetter
//
//  Purpose: Sets whether the pick letter is to be shown. It is possilbe to be
//           off if highlights are on and letters are off. In the past, if the 
//           letter was not shown, then no actor was ever created.
//            
//
//  Programmer:  Matt Larsen 
//  Creation:    July 18, 2016
//
//  Modifications:
//
// ****************************************************************************

void
avtPickActor::SetShowPickLetter(const bool val) 
{
   showPickLetter = val;
   if(!showPickLetter)
   {
        letterActor->VisibilityOff();
        lineActor->VisibilityOff();
   }
    
}
