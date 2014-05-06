///////////////////////////////////////////////////////////////////////////////////
//
// DlgOptimizationTolerances.h
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

#ifndef DLGOPTIMIZATIONTOLERANES_H
#define DLGOPTIMIZATIONTOLERANES_H

#include <genInterface/GenericDialog.h>

#include <genCtrl/RealCtrl.h>
#include <genCtrl/IntCtrl.h>
#include <genCtrl/CheckBoxCtrl.h>
#include <genCtrl/ComboBoolCtrl.h>

#include "osLibResource.h"

/////////////////////////////////////////////////////////////////////////////
// DlgOptimizationTolerances dialog

class DlgOptimizationTolerances : public CGenericDialog, public CUpdateableCtrl
{
   DECLARE_DYNCREATE(DlgOptimizationTolerances)
   // Construction
public:
   DlgOptimizationTolerances(CWnd* pParent = NULL);   // standard constructor

   CCheckBoxCtrl   m_uuseFitTolerance;
   CCheckBoxCtrl   m_uuseParameterTolerance;

   CRealCtrl       m_ufitTolerance;
   CRealCtrl       m_uparameterTolerance;

   CComboBoolCtrl  m_ucombineToleranceWithOR;


   CRealCtrl   m_utransitionToleranceMultiplier;
   CRealCtrl   m_uderivativeTolerance;
   CIntCtrl    m_umaxOptRun;

   // Dialog Data
   //{{AFX_DATA(DlgOptimizationTolerances)
   enum { IDD = IDD_OPT_TOLERANCE };
       // NOTE: the ClassWizard will add data members here
   //}}AFX_DATA


   // Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(DlgOptimizationTolerances)
   //}}AFX_VIRTUAL

   // Implementation
protected:
   virtual void    ResetAllControls();
   virtual void    CheckRestrictions();

   // Generated message map functions
   //{{AFX_MSG(DlgOptimizationTolerances)
   virtual BOOL OnInitDialog();
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

#endif // _DLGOPTIMIZATIONTOLERANES_H_
