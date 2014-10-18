///////////////////////////////////////////////////////////////////////////////////
//
// DlgLayerSpec.cpp
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


// DlgLayerSpec.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "DlgLayerSpec.h"

#include <Var/G_Layer.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgLayerSpec dialog

IMPLEMENT_DYNCREATE(DlgLayerSpec, CGenericDialog)

DlgLayerSpec::DlgLayerSpec(CWnd* pParent /*=NULL*/) :
  CGenericDialog(DlgLayerSpec::IDD, pParent)
{
  //{{AFX_DATA_INIT(DlgLayerSpec)
  // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
}


void DlgLayerSpec::DoDataExchange(CDataExchange* pDX)
{
  CGenericDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(DlgLayerSpec)
  // NOTE: the ClassWizard will add DDX and DDV calls here
  //}}AFX_DATA_MAP
};

BEGIN_MESSAGE_MAP(DlgLayerSpec, CGenericDialog)
  //{{AFX_MSG_MAP(DlgLayerSpec)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgLayerSpec message handlers

BOOL DlgLayerSpec::OnInitDialog()
{
  m_uenterLayerDepths.Set(this, IDC_COMBO1, enterLayerDepths, "Elevation", "Depth");
  m_uenterLayerDepths.AddCallback(this);

  m_ubottomLayerDepth.Set(this, IDC_COMBO2, IDC_EDIT1, &bottomLayerDepth,
                          NULL, 0.0, 1.0E+4);
  m_ubottomLayerElevation.Set(this, IDC_COMBO3, IDC_EDIT2, &bottomLayerElevation,
                              NULL, -1.0E+04, 1.0E+04);

  m_uuseCommonHistory.Set(this, IDC_COMBO4, useCommonHistory);

  m_uwellboreZoneDeltaVolumeUnits.Set(this, IDC_COMBO5, &wellboreZoneDeltaVolumeUnits);

  m_uwellboreZoneTZCompUnits.Set(this, IDC_COMBO6, &wellboreZoneTZCompUnits);

  CGenericDialog::OnInitDialog();

  InitData(true);

  return TRUE;
}

void DlgLayerSpec::CheckRestrictions()
{
  m_ubottomLayerDepth.EnableWindowEx(enterLayerDepths);
}


void DlgLayerSpec::ResetAllControls()
{
  m_uenterLayerDepths.DoCtrlReset();
  m_ubottomLayerDepth.DoCtrlReset();
  m_ubottomLayerElevation.DoCtrlReset();
  m_uuseCommonHistory.DoCtrlReset();
  m_uwellboreZoneDeltaVolumeUnits.DoCtrlReset();
  m_uwellboreZoneTZCompUnits.DoCtrlReset();
}
