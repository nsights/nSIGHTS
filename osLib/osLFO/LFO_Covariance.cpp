///////////////////////////////////////////////////////////////////////////////////
//
// LFO_Covariance.cpp
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
//      list confidence limits.
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#include "OsLibAfx.h"
#include <genClass/U_Str.h>
#include <genClass/U_Real.h>

#include <osClass/DO_CovarArray.h>

#include <osLFO/LFO_Covariance.h>

LFO_Covariance :: LFO_Covariance(ListDefC& assLst)
    : LFO_OptBase("Covariance", assLst)
{
    InitCommon();
}

LFO_Covariance::LFO_Covariance(const LFO_Covariance& a, ListDefC& assLst) : LFO_OptBase(a, assLst)
{
    LocalCopy(a);
    InitCommon();
}

LFO_Covariance :: ~LFO_Covariance ()
{
}

void LFO_Covariance::InitCommon()
{
    AddInPort(covarObjRef, typeid(DO_CovarArray));
    DoStatusChk();
}

LFO_Covariance& LFO_Covariance::operator= (const LFO_Covariance& a)
{
    if (&a != this)
        LocalCopy(a);
    return *this;
}


void LFO_Covariance::LocalCopy(const LFO_Covariance& a)
{
}


void LFO_Covariance::DoStatusChk()
{
    FuncObjC::DoStatusChk();
    CheckInputFO(covarObjRef, "Covariance");
}


void LFO_Covariance::CreateListing()
{

    DO_CovarArray* objDO = static_cast<DO_CovarArray*>(GetInPortData(covarObjRef));
    DC_CovarArray& covData = *(objDO->covarArrayData);
    DC_CovarHeader& covHeader = *(objDO->covarHeader);

    char titleStr[80];
    MakeString(titleStr, GetID(), ": Covariance Results", 80);

    TextStdTitle(titleStr);

    DC_FullCovar listCov(covHeader);

    for (int i = 0; i < covData.Size(); i++)
    {
        listCov.DC_Covar::operator=(covData[i]);
        ListCovar(listCov);
        AddBlankLine();
    }
}


