///////////////////////////////////////////////////////////////////////////////////
//
// nsPPOUtil.cpp
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
//      File I/O and user interface for all nsPFOGL functional objects
//
///////////////////////////////////////////////////////////////////////////////////

#include "NsLibAfx.h"

#include <nsClass/DO_ExtendedProfile.h>

#include "nsPPOUtil.h"

namespace nsPPOMenuUtilities {



    ExtendedProfileDataUIC::ExtendedProfileDataUIC() :
        fixedZValueMSUI(typeid(DO_Real), false)
    {
    }

    void ExtendedProfileDataUIC::SetSensitive()
    {
        int zvalueSource = zvalueSourceUI.GetChoice();
        fixedZValueMSUI.SetSensitive(zvalueSource == 1);
    }

    void ExtendedProfileDataUIC::SetSensitiveCB(void* inObj)
    {
        static_cast<ExtendedProfileDataUIC*>(inObj)->SetSensitive();
    }

    void ExtendedProfileDataUIC::StdInit(Widget       parent,
                              FuncObjRefUIC&  gridDataUI,
                              FormWidget&     topRowForm)
    {
        ArgListC    args;

        args.StdFormAttach();
        topRowForm.InitWidget(parent, args);

        args.StdSplitSetup();
        gridDataUI.InitFramedUI("Grid Data To Plot", topRowForm.GetWidget(), args);

        args.StdSplitFinish();
        static const char*   zLabels[]  = {"Same",  "Constant"};
        zvalueSourceUI.PreInitSetUp(zLabels, 2);
        zvalueSourceUI.InitFramedUI("Z Value", topRowForm.GetWidget(), args);
        zvalueSourceUI.AddOtherObjectCallback(SetSensitiveCB, this);

        args.StdTopObjectAttach(topRowForm.GetWidget());
        fixedZValueMSUI.InitUI("Fixed Z Value", args, parent, true, true, SetSensitiveCB, this);
    }


    bool ExtendedProfileDataUIC::UIdataOK(bool& allOK)
    {
        int zvalueSource = zvalueSourceUI.GetChoice();

        if (zvalueSource == 1)
            fixedZValueMSUI.UIdataOK(allOK);

        return allOK;
    }

    void ExtendedProfileDataUIC::MenuOpen(PlotObjC&  inObj,
                                PSC_3DExtendedProfileData& inData)
    {
        fixedZValueMSUI.MenuInit(inData.fixedZValueMS);
    }


    void ExtendedProfileDataUIC::Set3DExtendedProfileData(const PSC_3DExtendedProfileData& inData)
    {
        zvalueSourceUI.SetChoice(int(inData.zvalueSource));
        fixedZValueMSUI.SetValue(inData.fixedZValueMS);
        SetSensitive();
    }
    void ExtendedProfileDataUIC::Get3DExtendedProfileData(PSC_3DExtendedProfileData& outData)
    {
        outData.zvalueSource = PSC_3DExtendedProfileData::ZValueSource(zvalueSourceUI.GetChoice());
        if (outData.zvalueSource == PSC_3DExtendedProfileData::zvs_FixedVal)
            fixedZValueMSUI.GetValue(outData.fixedZValueMS);

    }


};                                      // end namespace

