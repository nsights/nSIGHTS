///////////////////////////////////////////////////////////////////////////////////
//
// PPO_TableColorSeries.cpp
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
//      File I/O and user interface for all objPFOGL objects
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#include "ObjLibAfx.h"

#include <genPPO/genPPOConfigFile.h>

#include "PPO_TableColorSeriesPS.h"
#include "PPO_TableColorSeries.h"

const char* PPO_TableColorSeries::objLongDesc = "Color Symbols from Columns of a Single Table";

PPO_TableColorSeries :: PPO_TableColorSeries(PlotDefC* assPlt)
                   : PFO_TableColorSeriesGL(*assPlt), PPO_Base(this, objLongDesc)
{
}

PPO_TableColorSeries :: PPO_TableColorSeries(PlotDefC* assPlt, const PPO_TableColorSeries& a)
                            : PFO_TableColorSeriesGL (a, *assPlt), PPO_Base(this, objLongDesc)
{
}

PPO_TableColorSeries& PPO_TableColorSeries::operator= (const PPO_TableColorSeries& a)
{
    if (&a != this)
       *((PFO_TableColorSeries*) this) = a;
    return *this;
}

// ************************* menu ops

PPO_TableColorSeriesPS& PPO_TableColorSeries::MenuRef()
{
    ASSERT(assocMenu);
    return static_cast<PPO_TableColorSeriesPS&>(*assocMenu);
}


void PPO_TableColorSeries::PropUpdate()
{
    if (UpdateOK())
        MenuRef().SetMenuData(*this);
}


void PPO_TableColorSeries::PropOpenMenu()
{
    MenuObjC::PropOpenMenu();
    assocMenu = new PPO_TableColorSeriesPS();
    MenuRef().InitMenu(*this);
    MenuRef().MenuOpen(*this);

    PropUpdate();
}


void PPO_TableColorSeries::PropApply()
{
    MenuRef().GetMenuData(*this);
    MenuObjC::PropApply();
}


bool  PPO_TableColorSeries::ReadFromFile()
{
    ReadObjectHeader();
    PPO_Base::ReadFromFile();
    ReadColorBase(*this);

    xDataIndx = ReadInt();
    yDataIndx = ReadInt();
    zDataIndx = ReadInt();
    colorDataIndx = ReadInt();
    plotAllRows = ReadBool();
    lastNRows = ReadInt();
    if (currentObjReadMajorVersion > 0)
        reversePlotOrder = ReadBool();

    pointSymbol  = PlotSymbol(ReadInt());
    pointSymSize = ReadInt();

    ReadEdgeSpec(edgeSpec);

    CheckForInputFailure("Reading PPO_TableColorSeries");
    return true;
}

void PPO_TableColorSeries::WriteToFile()
{
    // ver 0
    const int objMajVer = 1;  // FB330 - reverse color plotting order
//    const int objMajVer = 0;
    const int objMinVer = 0;

    WriteObjectHeader(objMajVer, objMinVer);
    PPO_Base::WriteToFile();
    WriteColorBase(*this);

    WriteInt(xDataIndx);
    WriteInt(yDataIndx);
    WriteInt(zDataIndx);
    WriteInt(colorDataIndx);
    WriteBool(plotAllRows);
    WriteInt(lastNRows);
    WriteBool(reversePlotOrder);
    WriteLine();

    WriteInt(int(pointSymbol));
    WriteInt(pointSymSize);
    WriteLine();

    WriteEdgeSpec(edgeSpec);
}
