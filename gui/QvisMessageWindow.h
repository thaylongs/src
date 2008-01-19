/*****************************************************************************
*
* Copyright (c) 2000 - 2008, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400142
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

#ifndef QVIS_MESSAGE_WINDOW_H
#define QVIS_MESSAGE_WINDOW_H
#include <gui_exports.h>
#include <QvisWindowBase.h>
#include <Observer.h>

class QLabel;
class QMultiLineEdit;

// *******************************************************************
// Class: QvisMessageWindow
//
// Purpose:
//   This window observes a MessageAttributes state object and prints
//   the message in the state object into the window when it is
//   updated.
//
// Notes:      
//
// Programmer: Brad Whitlock
// Creation:   Wed Aug 30 18:09:22 PST 2000
//
// Modifications:
//   Brad Whitlock, Fri Jan 18 15:32:51 PST 2008
//   Added preserveInformation flag.
//
// *******************************************************************

class GUI_API QvisMessageWindow : public QvisWindowBase, public Observer
{
    Q_OBJECT
public:
    QvisMessageWindow(MessageAttributes *msgAttr,
                      const char *captionString = 0);
    virtual ~QvisMessageWindow();
    virtual void Update(Subject *);
private slots:
    void doHide();
private:
    QLabel         *severityLabel;
    QMultiLineEdit *messageText;
    bool            preserveInformation;
};

#endif
