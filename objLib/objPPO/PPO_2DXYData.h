///////////////////////////////////////////////////////////////////////////////////
//
// PPO_2DXYData.h
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

#ifndef PPO_2DXYDATA_H
#define PPO_2DXYDATA_H

#include <objPFOGL/PFO_2DXYDataGL.h>

#include <genPPO/PPO_Base.h>

class PlotDefC;
class PPO_2DXYDataPS;

class PPO_2DXYData : public PPO_Base, protected PFO_2DXYDataGL  {
    private:
        static const char*  objLongDesc;
    public:
        friend class PPO_2DXYDataPS;

                        PPO_2DXYData(PlotDefC* assPlt);
                        PPO_2DXYData(PlotDefC* assPlt, const PPO_2DXYData& a);
                        ~PPO_2DXYData(){};

        PPO_2DXYData& operator= (const PPO_2DXYData& a);

        void            PropOpenMenu();
        void            PropUpdate();
        void            PropApply();

        void            WriteToFile();
        bool            ReadFromFile();

    private:
        PPO_2DXYDataPS& MenuRef();

};

#endif // !PPO_2DXYDATA_H

