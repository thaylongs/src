package llnl.visit;

import java.util.Vector;
import java.lang.Integer;

// ****************************************************************************
// Class: GlobalAttributes
//
// Purpose:
//    This class contains attributes associated with the main window.
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Thu Aug 5 16:52:25 PST 2004
//
// Modifications:
//   
// ****************************************************************************

public class GlobalAttributes extends AttributeSubject
{
    public GlobalAttributes()
    {
        super(14);

        sources = new Vector();
        windows = new Vector();
        activeWindow = 1;
        iconifiedFlag = false;
        autoUpdateFlag = false;
        replacePlots = false;
        applyOperator = true;
        executing = false;
        windowLayout = 1;
        makeDefaultConfirm = true;
        cloneWindowOnFirstRef = false;
        maintainView = false;
        maintainData = false;
        automaticallyAddOperator = false;
    }

    public GlobalAttributes(GlobalAttributes obj)
    {
        super(14);

        int i;

        sources = new Vector(obj.sources.size());
        for(i = 0; i < obj.sources.size(); ++i)
            sources.addElement(new String((String)obj.sources.elementAt(i)));

        windows = new Vector();
        for(i = 0; i < obj.windows.size(); ++i)
        {
            Integer iv = (Integer)obj.windows.elementAt(i);
            windows.addElement(new Integer(iv.intValue()));
        }
        activeWindow = obj.activeWindow;
        iconifiedFlag = obj.iconifiedFlag;
        autoUpdateFlag = obj.autoUpdateFlag;
        replacePlots = obj.replacePlots;
        applyOperator = obj.applyOperator;
        executing = obj.executing;
        windowLayout = obj.windowLayout;
        makeDefaultConfirm = obj.makeDefaultConfirm;
        cloneWindowOnFirstRef = obj.cloneWindowOnFirstRef;
        maintainView = obj.maintainView;
        maintainData = obj.maintainData;
        automaticallyAddOperator = obj.automaticallyAddOperator;

        SelectAll();
    }

    public boolean equals(GlobalAttributes obj)
    {
        int i;

        // Create the return value
        return ((sources == obj.sources) &&
                (windows == obj.windows) &&
                (activeWindow == obj.activeWindow) &&
                (iconifiedFlag == obj.iconifiedFlag) &&
                (autoUpdateFlag == obj.autoUpdateFlag) &&
                (replacePlots == obj.replacePlots) &&
                (applyOperator == obj.applyOperator) &&
                (executing == obj.executing) &&
                (windowLayout == obj.windowLayout) &&
                (makeDefaultConfirm == obj.makeDefaultConfirm) &&
                (cloneWindowOnFirstRef == obj.cloneWindowOnFirstRef) &&
                (maintainView == obj.maintainView) &&
                (maintainData == obj.maintainData) &&
                (automaticallyAddOperator == obj.automaticallyAddOperator));
    }

    // Property setting methods
    public void SetSources(Vector sources_)
    {
        sources = sources_;
        Select(0);
    }

    public void SetWindows(Vector windows_)
    {
        windows = windows_;
        Select(1);
    }

    public void SetActiveWindow(int activeWindow_)
    {
        activeWindow = activeWindow_;
        Select(2);
    }

    public void SetIconifiedFlag(boolean iconifiedFlag_)
    {
        iconifiedFlag = iconifiedFlag_;
        Select(3);
    }

    public void SetAutoUpdateFlag(boolean autoUpdateFlag_)
    {
        autoUpdateFlag = autoUpdateFlag_;
        Select(4);
    }

    public void SetReplacePlots(boolean replacePlots_)
    {
        replacePlots = replacePlots_;
        Select(5);
    }

    public void SetApplyOperator(boolean applyOperator_)
    {
        applyOperator = applyOperator_;
        Select(6);
    }

    public void SetExecuting(boolean executing_)
    {
        executing = executing_;
        Select(7);
    }

    public void SetWindowLayout(int windowLayout_)
    {
        windowLayout = windowLayout_;
        Select(8);
    }

    public void SetMakeDefaultConfirm(boolean makeDefaultConfirm_)
    {
        makeDefaultConfirm = makeDefaultConfirm_;
        Select(9);
    }

    public void SetCloneWindowOnFirstRef(boolean cloneWindowOnFirstRef_)
    {
        cloneWindowOnFirstRef = cloneWindowOnFirstRef_;
        Select(10);
    }

    public void SetMaintainView(boolean maintainView_)
    {
        maintainView = maintainView_;
        Select(11);
    }

    public void SetMaintainData(boolean maintainData_)
    {
        maintainData = maintainData_;
        Select(12);
    }

    public void SetAutomaticallyAddOperator(boolean automaticallyAddOperator_)
    {
        automaticallyAddOperator = automaticallyAddOperator_;
        Select(13);
    }

    // Property getting methods
    public Vector  GetSources() { return sources; }
    public Vector  GetWindows() { return windows; }
    public int     GetActiveWindow() { return activeWindow; }
    public boolean GetIconifiedFlag() { return iconifiedFlag; }
    public boolean GetAutoUpdateFlag() { return autoUpdateFlag; }
    public boolean GetReplacePlots() { return replacePlots; }
    public boolean GetApplyOperator() { return applyOperator; }
    public boolean GetExecuting() { return executing; }
    public int     GetWindowLayout() { return windowLayout; }
    public boolean GetMakeDefaultConfirm() { return makeDefaultConfirm; }
    public boolean GetCloneWindowOnFirstRef() { return cloneWindowOnFirstRef; }
    public boolean GetMaintainView() { return maintainView; }
    public boolean GetMaintainData() { return maintainData; }
    public boolean GetAutomaticallyAddOperator() { return automaticallyAddOperator; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteStringVector(sources);
        if(WriteSelect(1, buf))
            buf.WriteIntVector(windows);
        if(WriteSelect(2, buf))
            buf.WriteInt(activeWindow);
        if(WriteSelect(3, buf))
            buf.WriteBool(iconifiedFlag);
        if(WriteSelect(4, buf))
            buf.WriteBool(autoUpdateFlag);
        if(WriteSelect(5, buf))
            buf.WriteBool(replacePlots);
        if(WriteSelect(6, buf))
            buf.WriteBool(applyOperator);
        if(WriteSelect(7, buf))
            buf.WriteBool(executing);
        if(WriteSelect(8, buf))
            buf.WriteInt(windowLayout);
        if(WriteSelect(9, buf))
            buf.WriteBool(makeDefaultConfirm);
        if(WriteSelect(10, buf))
            buf.WriteBool(cloneWindowOnFirstRef);
        if(WriteSelect(11, buf))
            buf.WriteBool(maintainView);
        if(WriteSelect(12, buf))
            buf.WriteBool(maintainData);
        if(WriteSelect(13, buf))
            buf.WriteBool(automaticallyAddOperator);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetSources(buf.ReadStringVector());
                break;
            case 1:
                SetWindows(buf.ReadIntVector());
                break;
            case 2:
                SetActiveWindow(buf.ReadInt());
                break;
            case 3:
                SetIconifiedFlag(buf.ReadBool());
                break;
            case 4:
                SetAutoUpdateFlag(buf.ReadBool());
                break;
            case 5:
                SetReplacePlots(buf.ReadBool());
                break;
            case 6:
                SetApplyOperator(buf.ReadBool());
                break;
            case 7:
                SetExecuting(buf.ReadBool());
                break;
            case 8:
                SetWindowLayout(buf.ReadInt());
                break;
            case 9:
                SetMakeDefaultConfirm(buf.ReadBool());
                break;
            case 10:
                SetCloneWindowOnFirstRef(buf.ReadBool());
                break;
            case 11:
                SetMaintainView(buf.ReadBool());
                break;
            case 12:
                SetMaintainData(buf.ReadBool());
                break;
            case 13:
                SetAutomaticallyAddOperator(buf.ReadBool());
                break;
            }
        }
    }


    // Attributes
    private Vector  sources; // vector of String objects
    private Vector  windows; // vector of Integer objects
    private int     activeWindow;
    private boolean iconifiedFlag;
    private boolean autoUpdateFlag;
    private boolean replacePlots;
    private boolean applyOperator;
    private boolean executing;
    private int     windowLayout;
    private boolean makeDefaultConfirm;
    private boolean cloneWindowOnFirstRef;
    private boolean maintainView;
    private boolean maintainData;
    private boolean automaticallyAddOperator;
}

