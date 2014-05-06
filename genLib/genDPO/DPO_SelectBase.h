///////////////////////////////////////////////////////////////////////////////////
//
// DPO_SelectBase.h
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
// DESCRIPTION: File I/O and user interface for all genDFO functional objects.
//              All code is platform independent, but relies upon platform dependent
//              code in genApp and genClassPS.
//              File I/O for DFO_XXXX objects.
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef DPO_SELECTBASE_H
#define DPO_SELECTBASE_H

#include <genDFO/DFO_SelectBase.h>
#include <genApp/C_MenuObj.h>
#include <genApp/ExposedList.h>

class DPO_SelectBase : public MenuObjC {
protected:
    friend class DPO_SelectBasePS;

    DFO_SelectBase&     currFO;
    ExposedListWrapper  exposedIndex;
    SC_StringArray      indexStrings;

public:
    DPO_SelectBase(DFO_SelectBase* bFO, const char* longDesc, const char* indexID);

    void                WriteToFile();
    bool                ReadFromFile(bool oldVer = false);  //before MS spec changes

#ifndef ADCONSOLEAPP

    bool                ContainsExposedObject();

protected:
    void                UpdateUI();


private:

    DPO_SelectBasePS&   MenuRef();

#endif
};

#endif // DPO_SELECTBASE_H
