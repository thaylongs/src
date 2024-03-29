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

#include <PyMapNode.h>
#include <PyVariant.h>
#include <snprintf.h>
#include <DebugStream.h>

///////////////////////////////////////////////////////////////////////////////
//
// VisIt module helper method.
//
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: PyMapNode_Wrap
//
// Purpose:
//   Converts a MapNode to a python dictonary.
//
// Programmer: Cyrus Harrison
// Creation:   Mon Dec 17 15:20:25 PST 2007
//
// Modifications:
//   Eric Brugger, Fri Jan 11 09:54:04 PST 2008
//   I added some Python version specific coding to get around a problem
//   with older versions not having a const qualifier for the string argument
//   to PyDict_SetItemString.
//
// ****************************************************************************

PyObject *
PyMapNode_Wrap(const MapNode &node)
{
    if(node.Type() == MapNode::EMPTY_TYPE && node.GetNumEntries() == 0)
    {
        Py_INCREF(Py_None);
        return Py_None;
    }

    // must be a variant, use variant helper
    if(node.Type() != MapNode::EMPTY_TYPE)
    {
        return PyVariant_Wrap(node);
    }

    // we have a dict with map nodes as entries
    PyObject *dict = PyDict_New();
    stringVector entry_names;
    node.GetEntryNames(entry_names);

    for(size_t i=0;i<entry_names.size();i++)
    {
        const MapNode *child_node = node.GetEntry(entry_names[i]);
        if(child_node == NULL)
            continue;
        PyObject *child = PyMapNode_Wrap(*child_node);
#if (PY_MAJOR_VERSION < 2) || ((PY_MAJOR_VERSION == 2) && (PY_MINOR_VERSION < 5))
        char *str = new char[entry_names[i].length()+1];
        strcpy(str, entry_names[i].c_str());
        PyDict_SetItemString(dict, str, child);
        delete [] str;
#else
        PyDict_SetItemString(dict, entry_names[i].c_str(), child);
#endif
    }

    return dict;
}


// ****************************************************************************
// Method: PyDict_To_MapNode
//
// Purpose:
//   Converts a python Dictionary to a MapNode.
//
// Programmer: Kathleen Bonnell
// Creation:   July 13, 2011
//
// Modifications:
//   Kathleen Biagas, Wed Sep  7 11:56:23 PDT 2011
//   Allow ints and doubles in same sequence.
//
//   Kathleen Biagas, Mon Mar 24 17:00:11 PDT 2014
//   Parse Dict.
//
// ****************************************************************************

bool
PyDict_To_MapNode(PyObject *obj, MapNode &mn)
{
    if (!PyDict_Check(obj))
        return false;

    Py_ssize_t pos = 0;
    PyObject *key = NULL;
    PyObject *value = NULL;

    while(PyDict_Next(obj, &pos, &key, &value))
    {
        std::string mkey;
        if (PyString_Check(key))
            mkey = PyString_AS_STRING(key);
        else
        {
            return false;
        }

        if (PyTuple_Check(value) ||
            PyList_Check(value))
        {
            PyObject *item = PySequence_GetItem(value, 0);
            if (PyFloat_Check(item))
            {
                 doubleVector mval;
                 mval.push_back(PyFloat_AS_DOUBLE(item));
                 for (Py_ssize_t i = 1; i < PySequence_Size(value); ++i)
                 {
                     item = PySequence_GetItem(value, i);
                     if (PyFloat_Check(item))
                         mval.push_back(PyFloat_AS_DOUBLE(item));
                     else if (PyInt_Check(item))
                         mval.push_back((double)PyInt_AS_LONG(item));
                     else
                     {
                         debug3 << "PyDict_To_MapNode: tuples/lists must "
                                << "contain same type." << endl;
                         return false;
                     }
                 }
                 mn[mkey] = mval;
            }
            else if (PyInt_Check(item))
            {
                 int ni = 1, nd = 0, no = 0;
                 for (Py_ssize_t i = 1; i < PySequence_Size(value); ++i)
                 {
                     item = PySequence_GetItem(value, i);
                     if (PyFloat_Check(item))
                         nd++;
                     else if (PyInt_Check(item))
                         ni++;
                     else
                         no++;
                 }
                 if (no != 0)
                 {
                     debug3 << "PyDict_To_MapNode: tuples/lists must "
                            << "contain same type." << endl;
                     return false;
                 }
                 else if (nd != 0)
                 {
                     // process as doubleVector
                     doubleVector mval;
                     for (Py_ssize_t i = 0; i < PySequence_Size(value); ++i)
                     {
                         item = PySequence_GetItem(value, i);
                         if (PyFloat_Check(item))
                             mval.push_back(PyFloat_AS_DOUBLE(item));
                         else if (PyInt_Check(item))
                             mval.push_back((double)PyInt_AS_LONG(item));
                     }
                     mn[mkey] = mval;
                 }
                 else
                 {
                     intVector mval;
                     for (Py_ssize_t i = 0; i < PySequence_Size(value); ++i)
                     {
                         item = PySequence_GetItem(value, i);
                         mval.push_back(PyInt_AS_LONG(item));
                     }
                     mn[mkey] = mval;
                }
            }
            else if (PyString_Check(item))
            {
                 stringVector mval;
                 mval.push_back(PyString_AS_STRING(item));
                 for (Py_ssize_t i = 1; i < PySequence_Size(value); ++i)
                 {
                     item = PySequence_GetItem(value, i);
                     if (!PyString_Check(item))
                     {
                         debug3 << "PyDict_To_MapNode: tuples/lists must "
                                << "contain same type." << endl;
                         return false;
                     }
                     mval.push_back(PyString_AS_STRING(item));
                 }
                 mn[mkey] = mval;
            }
            else
            {
                debug3 << "PyDict_To_MapNode: type "
                       << item->ob_type->tp_name
                       << " not currently implemented." << endl;
                return false;
            }
        }
        else if (PyFloat_Check(value))
        {
            mn[mkey] = (double) PyFloat_AS_DOUBLE(value);
        }
        else if (PyInt_Check(value))
        {
            mn[mkey] = (int) PyInt_AS_LONG(value);
        }
        else if (PyString_Check(value))
        {
            mn[mkey] = (std::string) PyString_AS_STRING(value);
        }
        else if (PyDict_Check(value))
        {
            MapNode tmp;
            if (PyDict_To_MapNode(value, tmp))
                mn[mkey] = tmp;
        }
        else
        {
            debug3 << "PyDict_To_MapNode: type "
                   << value->ob_type->tp_name
                   << " not currently implemented." << endl;
            return false;
        }
    }
    return true;
}
