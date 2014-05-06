///////////////////////////////////////////////////////////////////////////////////
//
// TemplateDirectorySettingsPage.cpp
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

#include "GenLibAfx.h"

#include "GenLibRes.h"

#include "TemplateDirectorySettingsPage.h"
#include <genUIExt/FileDialog.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeViewSettingsPage property page

IMPLEMENT_DYNCREATE(CTemplateDirectorySettingsPage, CPropertyPage)

CTemplateDirectorySettingsPage::CTemplateDirectorySettingsPage() : CPropertyPage(CTemplateDirectorySettingsPage::IDD)
{
    //{{AFX_DATA_INIT(CTreeViewSettingsPage)
    m_szTemplateDirectoryName = _T("");

    //}}AFX_DATA_INIT
}

CTemplateDirectorySettingsPage::~CTemplateDirectorySettingsPage()
{
}

void CTemplateDirectorySettingsPage::DoDataExchange(CDataExchange* pDX)
{
    CPropertyPage::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CTemplateDirectorySettingsPage)
    DDX_Text(pDX, IDC_FULLPATHNAME, m_szTemplateDirectoryName);
    //}}AFX_DATA_MAP
    CheckRestrictions();
}


BEGIN_MESSAGE_MAP(CTemplateDirectorySettingsPage, CPropertyPage)
//{{AFX_MSG_MAP(CTemplateDirectorySettingsPage)
ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
//              ON_BN_CLICKED(IDC_ACCEPT, OnAccept)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTemplateDirectorySettingsPage message handlers

void CTemplateDirectorySettingsPage::OnBrowse()
{
    UpdateData(true);

    NTCompatibleFolderDialog dlg(false, NULL, NULL, 0);

    INT_PTR nResults = dlg.DoModal();

    if (nResults == IDOK)
        {
            m_szTemplateDirectoryName = dlg.GetSelPath();
            UpdateData(false);
            SetWindowText(m_szTemplateDirectoryName);
        }
}



void CTemplateDirectorySettingsPage::CheckRestrictions()
{
    //      GetDlgItem(IDC_RADIO1)->EnableWindow(m_nSingleLine);
    //      GetDlgItem(IDC_RADIO2)->EnableWindow(m_nSingleLine);
    //      GetDlgItem(IDC_RADIO3)->EnableWindow(m_nSingleLine);
}
