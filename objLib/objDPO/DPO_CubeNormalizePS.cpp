///////////////////////////////////////////////////////////////////////////////////
//
// DPO_CubeNormalizePS.cpp
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

#include "DPO_CubeNormalize.h"
#include "DPO_CubeNormalizePS.h"


DPO_CubeNormalizePS::DPO_CubeNormalizePS() :
    DPO_NormalizePS()
{
}

void DPO_CubeNormalizePS::InitMenu()
{
    DPO_NormalizePS::InitMenu();

    cubeInputUI.StdInit(URform.GetWidget());
}

void DPO_CubeNormalizePS::SetMenuData(DPO_CubeNormalize&  inData)
{
    cubeInputUI.SetCubeInput(inData);
    DPO_NormalizePS::SetMenuData(inData);
}


void DPO_CubeNormalizePS::MenuOpen(DPO_CubeNormalize& inData)
{
    DPO_NormalizePS::MenuOpen(inData);
    cubeInputUI.MenuOpen(inData);
}


bool DPO_CubeNormalizePS::UIdataOK()
{
    DPO_NormalizePS::UIdataOK();
    cubeInputUI.UIdataOK(allOK);
    return allOK;
}

void DPO_CubeNormalizePS::GetMenuData(DPO_CubeNormalize&  outData)
{
    DPO_NormalizePS::GetMenuData(outData);
    cubeInputUI.GetCubeInput(outData);
}


