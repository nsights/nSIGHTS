///////////////////////////////////////////////////////////////////////////////////
//
// DPO_XYScaleTransformPS.cpp
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

#include <genClass/DO_XYData.h>

#include "DPO_XYScaleTransform.h"
#include "DPO_XYScaleTransformPS.h"

void DPO_XYScaleTransformPS::SetAllSensitiveCB(void* inObj)
{
    static_cast<DPO_XYScaleTransformPS*>(inObj)->SetAllSensitive();
}

void DPO_XYScaleTransformPS::SetAllSensitive()
{
    thresholdUI.SetInternalSensitive();
}


DPO_XYScaleTransformPS::DPO_XYScaleTransformPS()
{
}

void DPO_XYScaleTransformPS::InitMenu()
{
    DPO_ScaleTransformPS::InitMenu();

    xyColSelUI.StdInit(URform.GetWidget(), PPform.GetWidget());

    ArgListC args;
    args.Clear();
    args.StdTopObjectAttach(xyColSelUI.operateOnXUI);

    InitSTCommon(args);

    args.Clear();
    args.StdTopObjectAttach(nullFrame);
    thresholdUI.StdInit(PPform.GetWidget(), args, true);
    thresholdUI.minThresholdUI.AddOtherObjectCallback(SetAllSensitiveCB, this);
    thresholdUI.maxThresholdUI.AddOtherObjectCallback(SetAllSensitiveCB, this);

    args.Clear();
    args.StdTopObjectAttach(thresholdUI);
    outputTypeDescUI.SetFieldLen(25);
    outputTypeDescUI.InitFramedUI("Output Description", PPform.GetWidget(), args);
}

void DPO_XYScaleTransformPS::SetMenuData(DPO_XYScaleTransform&  inData)
{
    DPO_ScaleTransformPS::SetMenuData(inData);

    xyColSelUI.SetXYColSel(inData);

    outputTypeDescUI.SetFieldString(inData.outputTypeDesc);
    thresholdUI.SetThreshold(inData.thresholdOp);

    SetAllSensitive();
}

void DPO_XYScaleTransformPS::MenuOpen(DPO_XYScaleTransform& inData)
{
    DPO_ScaleTransformPS::MenuOpen(inData);
    xyColSelUI.MenuOpen(inData);
}


bool DPO_XYScaleTransformPS::UIdataOK()
{
    DPO_ScaleTransformPS::UIdataOK();
    xyColSelUI.UIdataOK(allOK);
    thresholdUI.UIdataOK(allOK);
    return allOK;
}

void DPO_XYScaleTransformPS::GetMenuData(DPO_XYScaleTransform&  outData)
{
    DPO_ScaleTransformPS::GetMenuData(outData);
    xyColSelUI.GetXYColSel(outData);
    outputTypeDescUI.GetFieldString(outData.outputTypeDesc, stdMsgStrLen);
    thresholdUI.GetThreshold(outData.thresholdOp);
}


