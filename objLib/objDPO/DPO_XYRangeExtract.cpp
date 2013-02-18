///////////////////////////////////////////////////////////////////////////////////
//
// DPO_XYRangeExtract.cpp
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
//    I/O and user interface for respective ../objDFO/DFO_XXX functional objects
//
//
///////////////////////////////////////////////////////////////////////////////////

#include "ObjLibAfx.h"

#include <objDPO/objDPOConfigFile.h>

#include "DPO_XYRangeExtract.h"
#ifndef ADCONSOLEAPP
#include "DPO_XYRangeExtractPS.h"
#endif

static const char* objLongDesc = "Extract XY Data";

DPO_XYRangeExtract :: DPO_XYRangeExtract() :
    DPO_RangeExtract(this, objLongDesc)
{
}

DPO_XYRangeExtract :: DPO_XYRangeExtract(const DPO_XYRangeExtract& a) :
    DFO_XYRangeExtract(a),
    DPO_RangeExtract(this, objLongDesc)
{
}


DPO_XYRangeExtract& DPO_XYRangeExtract::operator= (const DPO_XYRangeExtract& a)
{
    if (&a != this)
       *((DFO_XYRangeExtract*) this) = a;
    return *this;
}


bool  DPO_XYRangeExtract::ReadFromFile()
{
    ReadObjectHeader();

    ReadFuncObjRef(xyInputObjRef);
    operateOnX = ReadBool();
    ReadText(outputTypeDesc, descLen);

    DPO_RangeExtract::ReadFromFile();

    CheckForInputFailure("Reading DPO_XYRangeExtract");
    return true;
}


void DPO_XYRangeExtract::WriteToFile()
{
    const int objMajVer = 0;
    const int objMinVer = 0;
    WriteObjectHeader(objMajVer, objMinVer);

    WriteFuncObjRef(xyInputObjRef);

    WriteBool(operateOnX);
    WriteLine();

    WriteText(outputTypeDesc);

    DPO_RangeExtract::WriteToFile();
}

#ifndef ADCONSOLEAPP

DPO_XYRangeExtractPS& DPO_XYRangeExtract::MenuRef()
{
    ASSERT(assocMenu);
    return static_cast<DPO_XYRangeExtractPS&>(*assocMenu);
}

void DPO_XYRangeExtract::PropUpdate()
{
    if (UpdateOK())
        MenuRef().SetMenuData(*this);
}


void DPO_XYRangeExtract::PropOpenMenu()
{
    MenuObjC::PropOpenMenu();
    assocMenu = new DPO_XYRangeExtractPS();
    MenuRef().InitMenu();
    MenuRef().MenuOpen(*this);

    PropUpdate();
}

void DPO_XYRangeExtract::PropApply()
{
    MenuRef().GetMenuData(*this);
    MenuObjC::PropApply();
}


// ************************* expose support

void DPO_XYRangeExtract::CalcOutput(FOcalcType  calcType)
{
    DFO_XYRangeExtract::CalcOutput(calcType);
    UpdateUI();
}

#endif //!ADCONSOLEAPP


