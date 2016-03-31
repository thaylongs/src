/*****************************************************************************
*
* Copyright (c) 2000 - 2016, Lawrence Livermore National Security, LLC
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

#ifndef CQ_SCORE_H
#define CQ_SCORE_H

#include <qmainwindow.h>
#include <qstring.h>

class QButtonGroup;
class QComboBox;
class QLineEdit;
class QListView;
class QListViewItem;
class QTextEdit;

#include <vector>

// ****************************************************************************
//  Class:  CQScore
//
//  Purpose:
//    Main window for the clearquest scoring tool.
//
//  Programmer:  Jeremy Meredith
//  Creation:    July 25, 2005
//
// ****************************************************************************
class CQScore : public QMainWindow
{
    Q_OBJECT
  public:
    CQScore(QWidget *p, const QString &n);
  public slots:
    void saveExcel();
    void exportHTML();
    void writeCurve();
    void CalculatePercentile(class ResultData*);
    void RepopulateResults();
    void PopulateResults();
    void PopulatePercentileCurve();
    void PopulatePercentileCurve(std::vector<float>&);
    void PopulateSingleResultText(QListViewItem*);
    void PopulateScoringRuleChoices();
  protected:
  private:
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QComboBox *dbCombo;

    QComboBox *scoreRuleCombo;

    QButtonGroup *scoreGroup;
    QLineEdit *projectEdit;
    QLineEdit *dateEdit;
    QLineEdit *stateEdit;
    QLineEdit *vertgtEdit;
    QLineEdit *verresEdit;
    QLineEdit *ownerEdit;
    QLineEdit *idEdit;

    QListView *resultList;
    QTextEdit *resultText;
};

#endif
