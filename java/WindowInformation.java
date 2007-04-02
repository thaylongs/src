package llnl.visit;

import java.util.Vector;
import java.lang.Integer;

// ****************************************************************************
// Class: WindowInformation
//
// Purpose:
//    This class contains the attributes that tell the state of a viewer window.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Thu Jul 21 11:12:57 PDT 2005
//
// Modifications:
//   
// ****************************************************************************

public class WindowInformation extends AttributeSubject
{
    public WindowInformation()
    {
        super(25);

        activeSource = new String("");
        activeTimeSlider = -1;
        timeSliders = new Vector();
        timeSliderCurrentStates = new Vector();
        animationMode = 2;
        interactionMode = 0;
        boundingBoxNavigate = true;
        spin = false;
        fullFrame = false;
        perspective = true;
        lockView = false;
        lockTools = false;
        lockTime = false;
        viewExtentsType = 0;
        viewDimension = 2;
        viewKeyframes = new Vector();
        cameraViewMode = false;
        usingScalableRendering = false;
        lastRenderMin = 0f;
        lastRenderAvg = 0f;
        lastRenderMax = 0f;
        numPrimitives = 0;
        extents = new double[6];
        extents[0] = 0;
        extents[1] = 0;
        extents[2] = 0;
        extents[3] = 0;
        extents[4] = 0;
        extents[5] = 0;
        windowSize = new int[2];
        windowSize[0] = 0;
        windowSize[1] = 0;
        winMode = 0;
    }

    public WindowInformation(WindowInformation obj)
    {
        super(25);

        int i;

        activeSource = new String(obj.activeSource);
        activeTimeSlider = obj.activeTimeSlider;
        timeSliders = new Vector(obj.timeSliders.size());
        for(i = 0; i < obj.timeSliders.size(); ++i)
            timeSliders.addElement(new String((String)obj.timeSliders.elementAt(i)));

        timeSliderCurrentStates = new Vector();
        for(i = 0; i < obj.timeSliderCurrentStates.size(); ++i)
        {
            Integer iv = (Integer)obj.timeSliderCurrentStates.elementAt(i);
            timeSliderCurrentStates.addElement(new Integer(iv.intValue()));
        }
        animationMode = obj.animationMode;
        interactionMode = obj.interactionMode;
        boundingBoxNavigate = obj.boundingBoxNavigate;
        spin = obj.spin;
        fullFrame = obj.fullFrame;
        perspective = obj.perspective;
        lockView = obj.lockView;
        lockTools = obj.lockTools;
        lockTime = obj.lockTime;
        viewExtentsType = obj.viewExtentsType;
        viewDimension = obj.viewDimension;
        viewKeyframes = new Vector();
        for(i = 0; i < obj.viewKeyframes.size(); ++i)
        {
            Integer iv = (Integer)obj.viewKeyframes.elementAt(i);
            viewKeyframes.addElement(new Integer(iv.intValue()));
        }
        cameraViewMode = obj.cameraViewMode;
        usingScalableRendering = obj.usingScalableRendering;
        lastRenderMin = obj.lastRenderMin;
        lastRenderAvg = obj.lastRenderAvg;
        lastRenderMax = obj.lastRenderMax;
        numPrimitives = obj.numPrimitives;
        extents = new double[6];
        for(i = 0; i < obj.extents.length; ++i)
            extents[i] = obj.extents[i];

        windowSize = new int[2];
        windowSize[0] = obj.windowSize[0];
        windowSize[1] = obj.windowSize[1];

        winMode = obj.winMode;

        SelectAll();
    }

    public boolean equals(WindowInformation obj)
    {
        int i;

        // Compare the extents arrays.
        boolean extents_equal = true;
        for(i = 0; i < 6 && extents_equal; ++i)
            extents_equal = (extents[i] == obj.extents[i]);

        // Compare the windowSize arrays.
        boolean windowSize_equal = true;
        for(i = 0; i < 2 && windowSize_equal; ++i)
            windowSize_equal = (windowSize[i] == obj.windowSize[i]);

        // Create the return value
        return ((activeSource == obj.activeSource) &&
                (activeTimeSlider == obj.activeTimeSlider) &&
                (timeSliders == obj.timeSliders) &&
                (timeSliderCurrentStates == obj.timeSliderCurrentStates) &&
                (animationMode == obj.animationMode) &&
                (interactionMode == obj.interactionMode) &&
                (boundingBoxNavigate == obj.boundingBoxNavigate) &&
                (spin == obj.spin) &&
                (fullFrame == obj.fullFrame) &&
                (perspective == obj.perspective) &&
                (lockView == obj.lockView) &&
                (lockTools == obj.lockTools) &&
                (lockTime == obj.lockTime) &&
                (viewExtentsType == obj.viewExtentsType) &&
                (viewDimension == obj.viewDimension) &&
                (viewKeyframes == obj.viewKeyframes) &&
                (cameraViewMode == obj.cameraViewMode) &&
                (usingScalableRendering == obj.usingScalableRendering) &&
                (lastRenderMin == obj.lastRenderMin) &&
                (lastRenderAvg == obj.lastRenderAvg) &&
                (lastRenderMax == obj.lastRenderMax) &&
                (numPrimitives == obj.numPrimitives) &&
                extents_equal &&
                windowSize_equal &&
                (winMode == obj.winMode));
    }

    // Property setting methods
    public void SetActiveSource(String activeSource_)
    {
        activeSource = activeSource_;
        Select(0);
    }

    public void SetActiveTimeSlider(int activeTimeSlider_)
    {
        activeTimeSlider = activeTimeSlider_;
        Select(1);
    }

    public void SetTimeSliders(Vector timeSliders_)
    {
        timeSliders = timeSliders_;
        Select(2);
    }

    public void SetTimeSliderCurrentStates(Vector timeSliderCurrentStates_)
    {
        timeSliderCurrentStates = timeSliderCurrentStates_;
        Select(3);
    }

    public void SetAnimationMode(int animationMode_)
    {
        animationMode = animationMode_;
        Select(4);
    }

    public void SetInteractionMode(int interactionMode_)
    {
        interactionMode = interactionMode_;
        Select(5);
    }

    public void SetBoundingBoxNavigate(boolean boundingBoxNavigate_)
    {
        boundingBoxNavigate = boundingBoxNavigate_;
        Select(6);
    }

    public void SetSpin(boolean spin_)
    {
        spin = spin_;
        Select(7);
    }

    public void SetFullFrame(boolean fullFrame_)
    {
        fullFrame = fullFrame_;
        Select(8);
    }

    public void SetPerspective(boolean perspective_)
    {
        perspective = perspective_;
        Select(9);
    }

    public void SetLockView(boolean lockView_)
    {
        lockView = lockView_;
        Select(10);
    }

    public void SetLockTools(boolean lockTools_)
    {
        lockTools = lockTools_;
        Select(11);
    }

    public void SetLockTime(boolean lockTime_)
    {
        lockTime = lockTime_;
        Select(12);
    }

    public void SetViewExtentsType(int viewExtentsType_)
    {
        viewExtentsType = viewExtentsType_;
        Select(13);
    }

    public void SetViewDimension(int viewDimension_)
    {
        viewDimension = viewDimension_;
        Select(14);
    }

    public void SetViewKeyframes(Vector viewKeyframes_)
    {
        viewKeyframes = viewKeyframes_;
        Select(15);
    }

    public void SetCameraViewMode(boolean cameraViewMode_)
    {
        cameraViewMode = cameraViewMode_;
        Select(16);
    }

    public void SetUsingScalableRendering(boolean usingScalableRendering_)
    {
        usingScalableRendering = usingScalableRendering_;
        Select(17);
    }

    public void SetLastRenderMin(float lastRenderMin_)
    {
        lastRenderMin = lastRenderMin_;
        Select(18);
    }

    public void SetLastRenderAvg(float lastRenderAvg_)
    {
        lastRenderAvg = lastRenderAvg_;
        Select(19);
    }

    public void SetLastRenderMax(float lastRenderMax_)
    {
        lastRenderMax = lastRenderMax_;
        Select(20);
    }

    public void SetNumPrimitives(int numPrimitives_)
    {
        numPrimitives = numPrimitives_;
        Select(21);
    }

    public void SetExtents(double[] extents_)
    {
        for(int i = 0; i < 6; ++i)
             extents[i] = extents_[i];
        Select(22);
    }

    public void SetWindowSize(int[] windowSize_)
    {
        windowSize[0] = windowSize_[0];
        windowSize[1] = windowSize_[1];
        Select(23);
    }

    public void SetWindowSize(int e0, int e1)
    {
        windowSize[0] = e0;
        windowSize[1] = e1;
        Select(23);
    }

    public void SetWinMode(int winMode_)
    {
        winMode = winMode_;
        Select(24);
    }

    // Property getting methods
    public String   GetActiveSource() { return activeSource; }
    public int      GetActiveTimeSlider() { return activeTimeSlider; }
    public Vector   GetTimeSliders() { return timeSliders; }
    public Vector   GetTimeSliderCurrentStates() { return timeSliderCurrentStates; }
    public int      GetAnimationMode() { return animationMode; }
    public int      GetInteractionMode() { return interactionMode; }
    public boolean  GetBoundingBoxNavigate() { return boundingBoxNavigate; }
    public boolean  GetSpin() { return spin; }
    public boolean  GetFullFrame() { return fullFrame; }
    public boolean  GetPerspective() { return perspective; }
    public boolean  GetLockView() { return lockView; }
    public boolean  GetLockTools() { return lockTools; }
    public boolean  GetLockTime() { return lockTime; }
    public int      GetViewExtentsType() { return viewExtentsType; }
    public int      GetViewDimension() { return viewDimension; }
    public Vector   GetViewKeyframes() { return viewKeyframes; }
    public boolean  GetCameraViewMode() { return cameraViewMode; }
    public boolean  GetUsingScalableRendering() { return usingScalableRendering; }
    public float    GetLastRenderMin() { return lastRenderMin; }
    public float    GetLastRenderAvg() { return lastRenderAvg; }
    public float    GetLastRenderMax() { return lastRenderMax; }
    public int      GetNumPrimitives() { return numPrimitives; }
    public double[] GetExtents() { return extents; }
    public int[]    GetWindowSize() { return windowSize; }
    public int      GetWinMode() { return winMode; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteString(activeSource);
        if(WriteSelect(1, buf))
            buf.WriteInt(activeTimeSlider);
        if(WriteSelect(2, buf))
            buf.WriteStringVector(timeSliders);
        if(WriteSelect(3, buf))
            buf.WriteIntVector(timeSliderCurrentStates);
        if(WriteSelect(4, buf))
            buf.WriteInt(animationMode);
        if(WriteSelect(5, buf))
            buf.WriteInt(interactionMode);
        if(WriteSelect(6, buf))
            buf.WriteBool(boundingBoxNavigate);
        if(WriteSelect(7, buf))
            buf.WriteBool(spin);
        if(WriteSelect(8, buf))
            buf.WriteBool(fullFrame);
        if(WriteSelect(9, buf))
            buf.WriteBool(perspective);
        if(WriteSelect(10, buf))
            buf.WriteBool(lockView);
        if(WriteSelect(11, buf))
            buf.WriteBool(lockTools);
        if(WriteSelect(12, buf))
            buf.WriteBool(lockTime);
        if(WriteSelect(13, buf))
            buf.WriteInt(viewExtentsType);
        if(WriteSelect(14, buf))
            buf.WriteInt(viewDimension);
        if(WriteSelect(15, buf))
            buf.WriteIntVector(viewKeyframes);
        if(WriteSelect(16, buf))
            buf.WriteBool(cameraViewMode);
        if(WriteSelect(17, buf))
            buf.WriteBool(usingScalableRendering);
        if(WriteSelect(18, buf))
            buf.WriteFloat(lastRenderMin);
        if(WriteSelect(19, buf))
            buf.WriteFloat(lastRenderAvg);
        if(WriteSelect(20, buf))
            buf.WriteFloat(lastRenderMax);
        if(WriteSelect(21, buf))
            buf.WriteInt(numPrimitives);
        if(WriteSelect(22, buf))
            buf.WriteDoubleArray(extents);
        if(WriteSelect(23, buf))
            buf.WriteIntArray(windowSize);
        if(WriteSelect(24, buf))
            buf.WriteInt(winMode);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetActiveSource(buf.ReadString());
                break;
            case 1:
                SetActiveTimeSlider(buf.ReadInt());
                break;
            case 2:
                SetTimeSliders(buf.ReadStringVector());
                break;
            case 3:
                SetTimeSliderCurrentStates(buf.ReadIntVector());
                break;
            case 4:
                SetAnimationMode(buf.ReadInt());
                break;
            case 5:
                SetInteractionMode(buf.ReadInt());
                break;
            case 6:
                SetBoundingBoxNavigate(buf.ReadBool());
                break;
            case 7:
                SetSpin(buf.ReadBool());
                break;
            case 8:
                SetFullFrame(buf.ReadBool());
                break;
            case 9:
                SetPerspective(buf.ReadBool());
                break;
            case 10:
                SetLockView(buf.ReadBool());
                break;
            case 11:
                SetLockTools(buf.ReadBool());
                break;
            case 12:
                SetLockTime(buf.ReadBool());
                break;
            case 13:
                SetViewExtentsType(buf.ReadInt());
                break;
            case 14:
                SetViewDimension(buf.ReadInt());
                break;
            case 15:
                SetViewKeyframes(buf.ReadIntVector());
                break;
            case 16:
                SetCameraViewMode(buf.ReadBool());
                break;
            case 17:
                SetUsingScalableRendering(buf.ReadBool());
                break;
            case 18:
                SetLastRenderMin(buf.ReadFloat());
                break;
            case 19:
                SetLastRenderAvg(buf.ReadFloat());
                break;
            case 20:
                SetLastRenderMax(buf.ReadFloat());
                break;
            case 21:
                SetNumPrimitives(buf.ReadInt());
                break;
            case 22:
                SetExtents(buf.ReadDoubleArray());
                break;
            case 23:
                SetWindowSize(buf.ReadIntArray());
                break;
            case 24:
                SetWinMode(buf.ReadInt());
                break;
            }
        }
    }


    // Attributes
    private String   activeSource;
    private int      activeTimeSlider;
    private Vector   timeSliders; // vector of String objects
    private Vector   timeSliderCurrentStates; // vector of Integer objects
    private int      animationMode;
    private int      interactionMode;
    private boolean  boundingBoxNavigate;
    private boolean  spin;
    private boolean  fullFrame;
    private boolean  perspective;
    private boolean  lockView;
    private boolean  lockTools;
    private boolean  lockTime;
    private int      viewExtentsType;
    private int      viewDimension;
    private Vector   viewKeyframes; // vector of Integer objects
    private boolean  cameraViewMode;
    private boolean  usingScalableRendering;
    private float    lastRenderMin;
    private float    lastRenderAvg;
    private float    lastRenderMax;
    private int      numPrimitives;
    private double[] extents;
    private int[]    windowSize;
    private int      winMode;
}

