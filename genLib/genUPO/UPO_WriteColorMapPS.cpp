///////////////////////////////////////////////////////////////////////////////////
//
// UPO_WriteColorMapPS.cpp
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
//      File I/O and user-interface for genUFO
//
///////////////////////////////////////////////////////////////////////////////////

#include "GenLibAfx.h"

#include <genClass/DO_ColorMap.h>

#include "UPO_WriteColorMapPS.h"


void UPO_WriteColorMapPS::SetAllSensitiveCB(void* inObj)
{
    static_cast<UPO_WriteColorMapPS*>(inObj)->SetAllSensitive();
}

void UPO_WriteColorMapPS::SetAllSensitive()
{
    outField.SetSensitive(dataSource.CheckDataObj());
}

UPO_WriteColorMapPS::UPO_WriteColorMapPS() :
    dataSource(typeid(DO_ColorMap))
{
}

void UPO_WriteColorMapPS::InitMenu()
{
    MenuBaseC::InitMenu();

    ArgListC args;
    args.StdFormAttach();
    args.TopOffset(10);
    dataSource.InitFramedUI("Color Map Source", PPform.GetWidget(), args);
    dataSource.AddOtherObjectCallback(SetAllSensitiveCB, this);

    args.Clear();
    args.StdTopObjectAttach(dataSource);
    args.TopOffset(10);
    outField.InitFramedUI("Color Map Output File", PPform.GetWidget(), args);
    outField.SetPromptAndMask("Color map file to create", 
        "CMap Files (*.cmap)|*.cmap|All Files (*.*)|*.*|||");

}

void UPO_WriteColorMapPS::MenuOpen(UPO_WriteColorMap&   inData)
{
    MenuBaseC::MenuOpen(false, false);
    dataSource.StdMenuInit(inData.colorMapObjRef);
}

void UPO_WriteColorMapPS::MenuClose()
{
    outField.CloseDialog();
    MenuBaseC::MenuClose();
}


void UPO_WriteColorMapPS::SetMenuData(UPO_WriteColorMap&    inData)
{
    dataSource.SetFuncObjRef(inData.colorMapObjRef);
    outField.SetFieldString(inData.outFname);

    MenuBaseC::SetMenuData(inData);

    SetAllSensitive();
}

bool UPO_WriteColorMapPS::UIdataOK()
{
    MenuBaseC::UIdataOK();
    dataSource.FuncObjRefOK(allOK, "Data source");
    outField.FieldFileOK(allOK, "Output file", false, true);
    return allOK;
}

void UPO_WriteColorMapPS::GetMenuData(UPO_WriteColorMap&    outData)
{
    MenuBaseC::GetMenuData(outData);

    outField.GetFieldFile(outData.outFname);
    outData.colorMapObjRef = dataSource.GetFuncObjRef();
}
