///////////////////////////////////////////////////////////////////////////////////
//
// VaryVarUnitsSuiteDlg.h
//
///////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2012 Sandia Corporation. Under the terms of Contract
// DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government
// retains certain rights in this software.
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


#if !defined(AFX_VARYVARUNITSSUITEDLG_H__6107A9B5_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_)
#define AFX_VARYVARUNITSSUITEDLG_H__6107A9B5_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <osClass/C_VaryVarUnits.h>

#include <genGrid/GridCtrlCell.h>

#include <genUnits/UnitIndexCtrl.h>

class SuiteGridCtrl : public CGridCtrlCell
{
public:
  SuiteGridCtrl();

  void  UpdateGrid();

  void    InitializeGrid(VaryVarUnits&    gridVaryVar,
                         const SC_RealFormat* overrideFormat,
                         const double&    minVal,
                         const double&    maxVal);

protected:
  virtual void FinishEdit(const char* szText, int nValue, int nLastChar);

  // Generated message map functions
protected:
  //{{AFX_MSG(SuiteGridCtrl)
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


class CVaryVarUnitsSuiteDlg : public CDialog, public CCtrlUpdate
{
// Construction
public:
  CVaryVarUnitsSuiteDlg(VaryVarUnits& varyVar,
                        const SC_RealFormat* overrideFormat,
                        const double& minVal, const double& maxVal, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
  //{{AFX_DATA(CVaryVarUnitsSuiteDlg)
  enum { IDD = IDD_VARYVARUNITSSUITEDLG };
  // NOTE: the ClassWizard will add data members here
  //}}AFX_DATA

  //  callback to reset real text after unit change
  virtual void  DoCtrlUpdate();

private:
  const SC_RealFormat* m_poverrideFormat;
  const double&       m_minVal;
  const double&       m_maxVal;
  VaryVarUnits&       m_varyVar;
  int         m_ngridCell;
  SuiteGridCtrl   m_grid;
  CUnitIndexCtrl    m_uiCtrl;




// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CVaryVarUnitsSuiteDlg)
protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL


protected:
  // Generated message map functions
  //{{AFX_MSG(CVaryVarUnitsSuiteDlg)
  virtual BOOL OnInitDialog();
  virtual void OnOK();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VaryVarUnitsSuiteDlg_H__6107A9B5_2A25_11D4_BCE1_00104B4C74FD__INCLUDED_)
