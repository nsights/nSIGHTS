///////////////////////////////////////////////////////////////////////////////////
//
// VaryVarUnitsRangeDlg.h
//
///////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2012 Sandia Corporation. Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of Sandia Corporation nor the
//      names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////////////
//
// DESCRIPTION:
//
//      nPre dialog.
//
///////////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VARYVARUNITSRANGEDLG_H__6107A9B6_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_)
#define AFX_VARYVARUNITSRANGEDLG_H__6107A9B6_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VaryVarUnits.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVaryVarUnitsRangeDlg dialog

#include <osClass/C_VaryVarUnits.h>
#include <genUnits/UnitRealCtrl.h>
#include <genCtrl/ComboBoolCtrl.h>
#include <genCtrl/IntCtrl.h>

class CVaryVarUnitsRangeDlg : public CDialog, public CCtrlUpdate
{
// Construction
public:
    CVaryVarUnitsRangeDlg(VaryVarUnits& varyVarUnits, const SC_RealFormat* overrideFormat,
                          const double& minMetricVal, const double& maxMetricVal,
                          CWnd* pParent = NULL);   // standard constructor


    //  callback to reset real text after unit change
    //  only triggered by first unit
    virtual void    DoCtrlUpdate();


// Dialog Data
    //{{AFX_DATA(CVaryVarUnitsRangeDlg)
    enum { IDD = IDD_VARYVARUNITSRANGEDLG};
    //}}AFX_DATA

    CUnitRealCtrl   m_urangeMinLim;
    CUnitRealCtrl   m_urangeMaxLim;
    CComboBoolCtrl  m_urangeIsLinear;
    CIntCtrl        m_urangeNStep;

    UnitReal    m_rangeMinLim;
    UnitReal    m_rangeMaxLim;
    bool        m_rangeIsLinear;
    int         m_rangeNStep;

     // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CVaryVarUnitsRangeDlg)
    //}}AFX_VIRTUAL
private:
    const SC_RealFormat*        m_poverrideFormat;
    VaryVarUnits&               m_varyVarUnits;
    const double&               m_minMetricVal;
    const double&               m_maxMetricVal;

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CVaryVarUnitsRangeDlg)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAMETEROPTIMIZATIONDLG_H__6107A9B6_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_)

