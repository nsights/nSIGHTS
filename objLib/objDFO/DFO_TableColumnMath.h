///////////////////////////////////////////////////////////////////////////////////
//
// DFO_TableColumnMath.h
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

#ifndef DFO_TABLECOLUMNMATH_H
#define DFO_TABLECOLUMNMATH_H

#include <genClass/C_FuncObj.h>

#include <genClass/DO_TableData.h>
#include <genClass/DO_Real.h>
#include <genClass/DC_XYData.h>
#include <genClass/DO_XYData.h>

#include <objDataClass/DSC_TableColSel.h>

class DFO_TableColumnMath : public FuncObjC, public DSC_TableColSel  {
    protected:
        int                         selectedYCol;  // x is from DSC_TableColSel

        enum                        MathOp {moAdd, moSubtract, moMultiply, moDivide, moIntegrate};

        MathOp                      mathOp;

        bool                        logX;
        bool                        logY;

        bool                        outputFullTable;

        enum                        {columnIDLen = 40};
        char                        columnID[columnIDLen];

    private:
        //  output data
        DC_TableData                outputTableDC;
        DO_TableData                outputTableDO;

    public:
                        DFO_TableColumnMath();
                        DFO_TableColumnMath(const DFO_TableColumnMath& a);
                        ~DFO_TableColumnMath();

        DFO_TableColumnMath& operator= (const DFO_TableColumnMath& a);

        void            DoStatusChk();
        void            CalcOutput(FOcalcType  calcType);

    private:
        void            InitCommon();                        // common to normal and copy constructor
        void            LocalCopy(const DFO_TableColumnMath& a);  // common to copy constructor and = operator
};

#endif //DFO_TABLECOLUMNMATH_H

