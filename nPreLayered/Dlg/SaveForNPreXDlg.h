///////////////////////////////////////////////////////////////////////////////////
//
// SaveForNPreXDlg.h
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


#if !defined(SAVEFORNPREXDLG_H)
#define SAVEFORNPREXDLG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSaveForNPreXDlg dialog

#include <genCtrl/FolderCtrl.h>
#include <genCtrl/TextCtrl.h>
#include <genCtrl/ComboIntCtrl.h>
#include <genCtrl/CheckBoxCtrl.h>

class CSaveForNPreXDlg : public CDialog, public CCtrlUpdate
{
private:
  CComboIntCtrl m_platform;
  CCheckBoxCtrl m_changePath;
  CComboIntCtrl m_ucurrentPaths;
  CTextCtrl   m_ucurrentPathName;
  CTextCtrl   m_unewPathName;

  enum Platform {p_Win, p_Linux};
  int       platformSel;
  SC_StringArray  currPaths;
  int       currPathSel;
  static char   currentPathName[stdFileStrLen];
  static char   newPathName[stdFileStrLen];
  static bool   firstCall;

public:
  CSaveForNPreXDlg(CWnd* pParent = NULL);   // standard constructor

  virtual void    CheckRestrictions();
  virtual void  DoCtrlUpdate();
  virtual void  DoCtrlUpdate(int reason);

  //{{AFX_DATA(CSaveForNPreXDlg)
  enum {IDD = IDD_FILE_SAVENPREX};
  //}}AFX_DATA

  //{{AFX_VIRTUAL(CSaveForNPreXDlg)
  //}}AFX_VIRTUAL

protected:

  //{{AFX_MSG(CSaveForNPreXDlg)
  virtual BOOL OnInitDialog();
  virtual void OnOK();
  virtual void OnCancel();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
