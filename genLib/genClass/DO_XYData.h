///////////////////////////////////////////////////////////////////////////////////
//
// DO_XYData.h
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
// DESCRIPTION: Platform independent and application independent base classes and
//              support classes.
//              lightweight Data Object (DO) classes derived from DataObjC to
//              wrap data classes DC_XXX.
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef DO_XYDATA_H
#define DO_XYDATA_H

#include <genClass/C_DataObj.h>
#include <genClass/DC_XYData.h>

class DO_XYData : public DataObjC {
private:
    static char*        typeDesc;
public:
    const DC_XYData*    xyData;
public:
    DO_XYData(){xyData = 0;}
    DO_XYData(const DO_XYData& a) {xyData = a.xyData;}
    ~DO_XYData(){};

    DO_XYData&          operator= (const DO_XYData& a);

    bool                DataOK();
    char*               GetType() const {return typeDesc;}

    const DC_XYData&    GetXY() {return *xyData;}


    virtual const char* GetID();

};

#endif // DO_XYDATA_H

