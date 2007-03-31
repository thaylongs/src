package llnl.visit;


// ****************************************************************************
// Class: MaterialAttributes
//
// Purpose:
//    Attributes to control material interface reconstruction
//
// Notes:      Autogenerated by xml2java.
//
// Programmer: xml2java
// Creation:   Thu Jul 31 16:19:17 PST 2003
//
// Modifications:
//   
// ****************************************************************************

public class MaterialAttributes extends AttributeSubject
{
    public MaterialAttributes()
    {
        super(4);

        smoothing = false;
        forceMIR = false;
        cleanZonesOnly = false;
        needValidConnectivity = false;
    }

    public MaterialAttributes(MaterialAttributes obj)
    {
        super(4);

        smoothing = obj.smoothing;
        forceMIR = obj.forceMIR;
        cleanZonesOnly = obj.cleanZonesOnly;
        needValidConnectivity = obj.needValidConnectivity;

        SelectAll();
    }

    public boolean equals(MaterialAttributes obj)
    {
        // Create the return value
        return ((smoothing == obj.smoothing) &&
                (forceMIR == obj.forceMIR) &&
                (cleanZonesOnly == obj.cleanZonesOnly) &&
                (needValidConnectivity == obj.needValidConnectivity));
    }

    // Property setting methods
    public void SetSmoothing(boolean smoothing_)
    {
        smoothing = smoothing_;
        Select(0);
    }

    public void SetForceMIR(boolean forceMIR_)
    {
        forceMIR = forceMIR_;
        Select(1);
    }

    public void SetCleanZonesOnly(boolean cleanZonesOnly_)
    {
        cleanZonesOnly = cleanZonesOnly_;
        Select(2);
    }

    public void SetNeedValidConnectivity(boolean needValidConnectivity_)
    {
        needValidConnectivity = needValidConnectivity_;
        Select(3);
    }

    // Property getting methods
    public boolean GetSmoothing() { return smoothing; }
    public boolean GetForceMIR() { return forceMIR; }
    public boolean GetCleanZonesOnly() { return cleanZonesOnly; }
    public boolean GetNeedValidConnectivity() { return needValidConnectivity; }

    // Write and read methods.
    public void WriteAtts(CommunicationBuffer buf)
    {
        if(WriteSelect(0, buf))
            buf.WriteBool(smoothing);
        if(WriteSelect(1, buf))
            buf.WriteBool(forceMIR);
        if(WriteSelect(2, buf))
            buf.WriteBool(cleanZonesOnly);
        if(WriteSelect(3, buf))
            buf.WriteBool(needValidConnectivity);
    }

    public void ReadAtts(int n, CommunicationBuffer buf)
    {
        for(int i = 0; i < n; ++i)
        {
            int index = (int)buf.ReadByte();
            switch(index)
            {
            case 0:
                SetSmoothing(buf.ReadBool());
                break;
            case 1:
                SetForceMIR(buf.ReadBool());
                break;
            case 2:
                SetCleanZonesOnly(buf.ReadBool());
                break;
            case 3:
                SetNeedValidConnectivity(buf.ReadBool());
                break;
            }
        }
    }


    // Attributes
    private boolean smoothing;
    private boolean forceMIR;
    private boolean cleanZonesOnly;
    private boolean needValidConnectivity;
}

