///////////////////////////////////////////////////////////////////////////////////
//
// DO_Real.cpp
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
// DESCRIPTION: Platform independent and application independent base classes and
//              support classes.
//              lightweight Data Object (DO) classes derived from DataObjC to
//              wrap data classes DC_XXX:
//
///////////////////////////////////////////////////////////////////////////////////

#include <genClass/C_Common.h>
#include <genClass/DO_Real.h>

char* DO_Real::typeDesc    = "Real";

DO_Real::DO_Real()
{
    realVal = nullReal;
}

DO_Real::DO_Real(const DO_Real& a) : DO_Label(a)
{
    LocalCopy(a);
}

DO_Real& DO_Real::operator= (const DO_Real& a)
{
    if (&a != this)
        FullCopy(a);

    return *this;
}

void DO_Real::Reset(const char* typeLabel)
{
    DO_Label::Reset(typeLabel);
    realVal = nullReal;
}

bool DO_Real::DataOK()
{
    return true;

    //    testing for use of nulls
    //   SetErrMsg("Real is null");
    //    return (! RealIsNull(realVal));
}

void DO_Real::InitLabelAndValue(const double& inVal)
{
    realVal = inVal;
    SetValueLabel(realVal);
}

void DO_Real::InitLabelAndValue(const double&        inVal,
                                const SC_RealFormat& rForm)
{
    realVal = inVal;
    SetValueLabel(realVal, rForm);
}


void  DO_Real::LocalCopy(const DO_Real& a)
{
    realVal = a.realVal;
}

void DO_Real::FullCopy(const DO_Real&  a)
{
    DO_Label::FullCopy(a);
    LocalCopy(a);
}

