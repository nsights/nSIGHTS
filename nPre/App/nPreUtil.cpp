///////////////////////////////////////////////////////////////////////////////////
//
// nPreUtil.cpp
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
//      Loads/saves app settings in registry.
//
///////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <genPlotClass/C_PlotDef.h>

#include "nPreUtil.h"

void nPreUtilities::ExecuteAndReplot(FuncObjC& inObj)
{
    PlotDefC::ExecuteAndReplot(inObj);
}

void nPreUtilities::Replot()
{
    PlotDefC::ReplotAfterCalc();
}

bool nPreUtilities::bRunWithMinimizedMain = false;

void nPreUtilities::SetDefaultSettings()
{
    bRunWithMinimizedMain = false;
}

void nPreUtilities::LoadSettings()
{
    SetDefaultSettings();

    CWinApp* pApp = AfxGetApp();
    bRunWithMinimizedMain = pApp->GetProfileInt("Settings", "RunWithMinimizedMain", bRunWithMinimizedMain);
}

void nPreUtilities::SaveSettings()
{
    CWinApp* pApp = AfxGetApp();
    pApp->WriteProfileInt("Settings", "RunWithMinimizedMain", bRunWithMinimizedMain);
}

