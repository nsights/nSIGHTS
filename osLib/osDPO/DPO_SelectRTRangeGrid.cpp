///////////////////////////////////////////////////////////////////////////////////
//
// DPO_SelectRTRangeGrid.cpp
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
//      I/O and user interface for all osDFO functional objects.
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#include "OsLibAfx.h"

#include <genApp/AppConfigFile.h>

#ifndef ADCONSOLEAPP
#include "DPO_SelectRTRangeGridPS.h"
#endif
#include "DPO_SelectRTRangeGrid.h"

const char* DPO_SelectRTRangeGrid::objLongDesc = "Select Runtime Range Grid";

DPO_SelectRTRangeGrid :: DPO_SelectRTRangeGrid() :
    DPO_SelectBase(this, objLongDesc, "Grid Index")
{
}

DPO_SelectRTRangeGrid :: DPO_SelectRTRangeGrid(const DPO_SelectRTRangeGrid& a) :
    DFO_SelectRTRangeGrid(a),
    DPO_SelectBase(this, objLongDesc, "Grid Index")
{
}

DPO_SelectRTRangeGrid& DPO_SelectRTRangeGrid::operator= (const DPO_SelectRTRangeGrid& a)
{
    if (&a != this)
       *((DFO_SelectRTRangeGrid*) this) = a;
    return *this;
}


bool  DPO_SelectRTRangeGrid::ReadFromFile()
{
    ReadObjectHeader();

    ReadFuncObjRef(arrayInputObjRef);

    return DPO_SelectBase::ReadFromFile();
}


void DPO_SelectRTRangeGrid::WriteToFile()
{
    const int objMajVer = 0;
    const int objMinVer = 0;

    WriteObjectHeader(objMajVer, objMinVer);

    WriteFuncObjRef(arrayInputObjRef);

    DPO_SelectBase::WriteToFile();
}

#ifndef ADCONSOLEAPP

// ************************* menu stuff


DPO_SelectRTRangeGridPS& DPO_SelectRTRangeGrid::MenuRef()
{
    ASSERT(assocMenu);
    return static_cast<DPO_SelectRTRangeGridPS&>(*assocMenu);
}


void DPO_SelectRTRangeGrid::PropUpdate()
{
    if (UpdateOK())
        MenuRef().SetMenuData(*this);
}


void DPO_SelectRTRangeGrid::PropOpenMenu()
{
    MenuObjC::PropOpenMenu();
    assocMenu = new DPO_SelectRTRangeGridPS();
    MenuRef().InitMenu();
    MenuRef().MenuOpen(*this);

    PropUpdate();
}


void DPO_SelectRTRangeGrid::PropApply()
{
    MenuRef().GetMenuData(*this);
    MenuObjC::PropApply();
}


// ************************* expose support

void DPO_SelectRTRangeGrid::CalcOutput(FOcalcType  calcType)
{
    DFO_SelectRTRangeGrid::CalcOutput(calcType);

    indexStrings.DeAlloc();
    if (StatusOK())
        arrayInputDO->GetIDs(indexStrings);
    UpdateUI();
}

#endif //!ADCONSOLEAPP

