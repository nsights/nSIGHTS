///////////////////////////////////////////////////////////////////////////////////
//
// DFO_TransformSATable.h
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
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef DFO_TRANSFORMSATABLE_H
#define DFO_TRANSFORMSATABLE_H

#include <genClass/C_FuncObj.h>
#include <genDataClass/DSC_FunctionSpec.h>

#include <saClass/DO_SATable.h>

class DFO_TransformSATable : public FuncObjC, DSC_FunctionSpec {

    public:
        enum {transformIDLen = 15};
        enum {transformDescLen = 120};

        class TransformDesc {
            public:
                bool    doTransform;
                char    transformID[transformIDLen];
                char    transformDesc[transformDescLen];

                        TransformDesc();
                        TransformDesc(const TransformDesc& a);
                TransformDesc&  operator= (const TransformDesc& a);

            private:
                void         LocalCopy(const TransformDesc& a);  // common to copy constructor and = operator
        };

        enum {maxTransform = 16};

    protected:
        bool            dualInputTables;
        FuncObjRef      table1ObjRef;
        FuncObjRef      table2ObjRef;
        TransformDesc   transformDesc[maxTransform];

    private:
        DO_SATable      outputTable1DO;
        DC_SATable      outputTable1DC;
        DO_SATable      outputTable2DO;
        DC_SATable      outputTable2DC;
        const DC_SATable*   table1DC;
        const DC_SATable*   table2DC;
        T_SC_Array<TransformDesc> activeTransforms;

    public:
                            DFO_TransformSATable();
                            DFO_TransformSATable(const DFO_TransformSATable& a);
                            ~DFO_TransformSATable(){};

        DFO_TransformSATable&       operator= (const DFO_TransformSATable& a);

        void                DoStatusChk();
        void                CalcOutput(FOcalcType  calcType);

    private:
        void                InitCommon();                        // common to normal and copy constructor
        void                LocalCopy(const DFO_TransformSATable& a);  // common to copy constructor and = operator
        int                 GetTranVarClass();
        void                AddToTable(DC_SATable& outTable, int trStart, int varClass, const char* idExt);


};

#endif // !DFO_TRANSFORMSATABLE_H

