///////////////////////////////////////////////////////////////////////////////////
//
// PPO_ShadeRegionPS.h
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
//      File I/O and user interface for all genPFOGL functional objects.
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef PPO_SHADEREGIONPS_H
#define PPO_SHADEREGIONPS_H

#include <genApp/U_MenuDPO.h>
#include <genPPO/PPO_BasePS.h>

#include "PPO_ShadeRegion.h"

class PPO_ShadeRegionPS : public PPO_BasePS {
    private:
        FormWidget                  topRow;
        OptionUIC                   xRegionSpecUI;
        OptionUIC                   yRegionSpecUI;

        RealMSSpecUI                regionXMinUI;
        RealMSSpecUI                regionXMaxUI;
        RealMSSpecUI                regionYMinUI;
        RealMSSpecUI                regionYMaxUI;


        BaseUIC                     optionFrame;
        ToggleBoxWidget             shadeRegionUI;
        ToggleBoxWidget             labelRegionUI;
        ToggleBoxWidget             stippleRegionUI;
        ToggleBoxWidget             frameRegionUI;

        FormWidget                  shadeFormRow;
        BoolOptionUIC               shadeIsColorMapUI;
        FuncObjRefUIC               colorMapObjRefUI;
        IntEntryUIC                 shadeCMIndexUI;
        PenOptionUIC                shadePenUI;


        BaseUIC                     labelFormatFrame;
        RealEntryUIC                labelXPositionUI;
        RealEntryUIC                labelYPositionUI;
        HAlignOptionUIC             halignUI;
        VAlignOptionUIC             valignUI;
        IntEntryUIC                 labelOffsetUI;

        FormWidget                  penFontRow;
        PenOptionUIC                labelPenUI;
        FontUIC                     labelFontUI;

        TextEntryUIC                regionLabelUI;

        StippleSpecUIC              regionStippleUI;

        LineSpecUIC                 frameLineUI;


        bool needXMin;
        bool needXMax;
        bool needYMin;
        bool needYMax;

    public:
                        PPO_ShadeRegionPS();
                        ~PPO_ShadeRegionPS(){};

                void    InitMenu(const PPO_ShadeRegion&   inData);

                void    MenuOpen(PPO_ShadeRegion& inData);

                void    SetMenuData(PPO_ShadeRegion&  inData);
                bool    UIdataOK();
                void    GetMenuData(PPO_ShadeRegion&          outData);


    private:
        static  void    SetAllSensitiveCB(void* inObj);
                void    SetAllSensitive();
                void    SetNeedXY();
};


#endif // !PPO_SHADEREGIONPS_H

