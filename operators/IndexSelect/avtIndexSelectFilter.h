// ************************************************************************* //
//  File: avtIndexSelectFilter.h
// ************************************************************************* //

#ifndef AVT_IndexSelect_FILTER_H
#define AVT_IndexSelect_FILTER_H


#include <avtPluginStreamer.h>
#include <IndexSelectAttributes.h>


class vtkDataSet;
class vtkMaskPoints;
class vtkVisItExtractGrid;
class vtkVisItExtractRectilinearGrid;


// ****************************************************************************
//  Class: avtIndexSelectFilter
//
//  Purpose:
//      A plugin operator for IndexSelect.
//
//  Programmer: childs -- generated by xml2info
//  Creation:   Wed Jun 5 09:09:10 PDT 2002
//
//  Modifications:
//
//    Hank Childs, Sat Jun 29 16:22:48 PDT 2002
//    Added support for groups.
//
//    Mark C. Miller, Tue Sep 28 19:57:42 PDT 2004
//    Added data selection id
//
//    Kathleen Bonnell, Tue May 10 11:19:24 PDT 2005 
//    Use VisIt versions of vtkExtractGrid and vtkExtractRectilinearGrid, 
//    they have been modified to correctly handle cell data when VOI is
//    along max boundary. 
//
//    Kathleen Bonnell, Thu Aug  4 15:47:59 PDT 2005 
//    Added RefashionDataObjectInfo.
//
//    Kathleen Bonnell,  Mon Jan 30 15:10:26 PST 2006 
//    Add vtkMaskPoints for a points filter. 
//
// ****************************************************************************

class avtIndexSelectFilter : public avtPluginStreamer
{
  public:
                         avtIndexSelectFilter();
    virtual             ~avtIndexSelectFilter();

    static avtFilter    *Create();

    virtual const char  *GetType(void)  { return "avtIndexSelectFilter"; };
    virtual const char  *GetDescription(void)
                             { return "Index selecting"; };
    virtual void         ReleaseData(void);

    virtual void         SetAtts(const AttributeGroup*);
    virtual bool         Equivalent(const AttributeGroup*);

  protected:
    IndexSelectAttributes       atts;
    bool                        haveIssuedWarning;
    bool                        successfullyExecuted;
    int                         selID;

    vtkVisItExtractGrid                  *curvilinearFilter;
    vtkVisItExtractRectilinearGrid       *rectilinearFilter;
    vtkMaskPoints                        *pointsFilter;

    void                        PrepareFilters(int [3]);

    virtual vtkDataSet         *ExecuteData(vtkDataSet *, int, std::string);
    virtual void                PreExecute(void);
    virtual void                PostExecute(void);
    virtual void                RefashionDataObjectInfo(void);

    virtual avtPipelineSpecification_p
                            PerformRestriction(avtPipelineSpecification_p);
};


#endif
