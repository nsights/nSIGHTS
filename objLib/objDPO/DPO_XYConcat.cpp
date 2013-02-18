///////////////////////////////////////////////////////////////////////////////////
//
// DPO_XYConcat.cpp
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

#include <genApp/AppConfigFile.h>

#ifndef ADCONSOLEAPP
#include "DPO_XYConcatPS.h"
#endif
#include "DPO_XYConcat.h"

static const char* objLongDesc = "Concatenate XY";

DPO_XYConcat :: DPO_XYConcat() :
    MenuObjC(this, objLongDesc)
{
}

DPO_XYConcat :: DPO_XYConcat(const DPO_XYConcat& a) :
    DFO_XYConcat(a),
    MenuObjC(this, objLongDesc)
{
}

DPO_XYConcat& DPO_XYConcat::operator= (const DPO_XYConcat& a)
{
    if (&a != this)
       *((DFO_XYConcat*) this) = a;
    return *this;
}


bool  DPO_XYConcat::ReadFromFile()
{
    ReadObjectHeader();

    deleteOverlaps = ReadBool();

    int nxy  = ReadInt();
    for (int i = 0; i < nxy; i++)
    {
        xyToConcat[i].doXY   = true;
        ReadFuncObjRef(xyToConcat[i].xyObjRef);
    }

    for (int i = nxy; i < maxInputXY; i++)
        xyToConcat[i] = DFO_XYConcat::XYInputData();

    CheckForInputFailure("Reading DPO_XYConcat");
    return true;
}

void DPO_XYConcat::WriteToFile()
{
    // ver 0
    const int objMajVer = 0;
    const int objMinVer = 0;

    WriteObjectHeader(objMajVer, objMinVer);
    WriteBool(deleteOverlaps);
    WriteLine();

    int nSel = 0;
    for (int i = 0; i < maxInputXY; i++)
        if (xyToConcat[i].doXY)
            nSel++;

    WriteInt(nSel);
    WriteLine();
    for (int i = 0; i < maxInputXY; i++)
        if (xyToConcat[i].doXY)
        {
            WriteFuncObjRef(xyToConcat[i].xyObjRef);
        }

    WriteLine();

}


#ifndef ADCONSOLEAPP

DPO_XYConcatPS& DPO_XYConcat::MenuRef()
{
    ASSERT(assocMenu);
    return static_cast<DPO_XYConcatPS&>(*assocMenu);
}

void DPO_XYConcat::PropOpenMenu()
{
    MenuObjC::PropOpenMenu();
    assocMenu = new DPO_XYConcatPS();
    MenuRef().InitMenu();
    MenuRef().MenuOpen(*this);

    PropUpdate();
}

void DPO_XYConcat::PropUpdate()
{
    if (UpdateOK())
        MenuRef().SetMenuData(*this);
}

void DPO_XYConcat::PropApply()
{
    MenuRef().GetMenuData(*this);
    MenuObjC::PropApply();
}


#endif //!ADCONSOLEAPP

