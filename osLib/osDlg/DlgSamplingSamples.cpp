///////////////////////////////////////////////////////////////////////////////////
//
// DlgSamplingSamples.cpp
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
//
//
///////////////////////////////////////////////////////////////////////////////////

#include "OsLibAfx.h"

#include "DlgSamplingSamples.h"

#include <genGrid/TextGridCell.h>

#include <genClass/U_Str.h>
#include <genClass/U_Msg.h>

#include <osMain/G_Sample.h>
#include <osMain/C_Sample.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSamplingSamples dialog

IMPLEMENT_DYNCREATE(DlgSamplingSamples,CGenericDialog)

DlgSamplingSamples::DlgSamplingSamples(CWnd* pParent /*=NULL*/) :
    CGenericDialog(DlgSamplingSamples::IDD, pParent)
{
    //{{AFX_DATA_INIT(DlgSamplingSamples)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void DlgSamplingSamples::DoDataExchange(CDataExchange* pDX)
{
    CGenericDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(DlgSamplingSamples)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSamplingSamples, CGenericDialog)
    //{{AFX_MSG_MAP(DlgSamplingSamples)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSamplingSamples message handlers


///////////////////////////////////////////////////////////////////////////////////
SamplesGridCtrl::SamplesGridCtrl() :
    CGridCtrlCell()
{
}

BEGIN_MESSAGE_MAP(SamplesGridCtrl,CGridCtrlCell)
    //{{AFX_MSG_MAP(SamplesGridCtrl)    SetRowCount(SampVar:: + 1);
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()


void SamplesGridCtrl::InitGrid()
{
    if (!Sampler::SamplesAreAvailable())
    {
        SetRowCount(1);
        SetColCount(1);
        SetCenteredText(0, 0, "Sampling Errors -- no data available");
        return;
    }

    SampVarArray sampVars;

    int nsampVar  = sampVars.Size();
    SetColCount(nsampVar + 1);
    SetRowCount(SampVar::numberOfTrials + 1);

    SetCenteredText(0, 0, "");
    int i;
    for (i = 0; i < nsampVar; i++)
        SetRightText(0, i + 1, sampVars[i]->GetShortID());

    char temp[40];
    SC_SciFormat rf(7);

    for (i = 0; i < SampVar::numberOfTrials; i++)
    {
        IntToString(i + 1, temp, 40);
        SetCenteredText(i + 1, 0, temp);
        for (int j = 0; j < nsampVar; j++)
        {
            rf.RealToString(sampVars[j]->GetFinalValue(i), temp, 40);
            SetRightText(i + 1, j + 1, temp);
        }
    }
    SetBorderThickness(4);
    AutoSize();
}


BOOL DlgSamplingSamples::OnInitDialog()
{
    CGenericDialog::OnInitDialog();

    m_grid.SubclassDlgItem(IDC_GRID, this);
    SetControlInfo(IDC_GRID, resizeBoth);

    ResetAllControls();

    return TRUE;
}


void DlgSamplingSamples::ResetAllControls()
{
    m_grid.InitGrid();
}
