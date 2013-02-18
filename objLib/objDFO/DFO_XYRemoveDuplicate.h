///////////////////////////////////////////////////////////////////////////////////
//
// DFO_XYRemoveDuplicate.h
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
//      Removes duplicate X and Y values from a data set
//
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef DFO_XYREMOVEDUPLICATE_H
#define DFO_XYREMOVEDUPLICATE_H

#include <objDFO/DFO_XYBase.h>

class DFO_XYRemoveDuplicate : public DFO_XYBase {
    public:
        //  explicit values for array indexing
        enum RemoveDuplicateOp     {rdMin          = 0,
                                    rdMax          = 1,
                                    rdAvg          = 2,
                                    rdFirst        = 3,
                                    rdLast         = 4};
        enum {maxReductionType = 5};

        // properties
        bool                removeDuplicateXValues;
        RemoveDuplicateOp   yValueToKeepOp;
        double              duplicateXLimit;
        bool                removeOutOfSeq;
        bool                removeDuplicateYValues;
        double              duplicateYLimit;


    private:
        double              currX;
        double              currY;
        double              lastX;
        double              lastY;
        int                 nDup;
        double              yKeepData[maxReductionType]; // for each operation

    public:
                        DFO_XYRemoveDuplicate();
                        DFO_XYRemoveDuplicate(const DFO_XYRemoveDuplicate& a);
                        ~DFO_XYRemoveDuplicate();

        DFO_XYRemoveDuplicate& operator= (const DFO_XYRemoveDuplicate& a);

        void            DoStatusChk();
        void            CalcOutput(FOcalcType  calcType);

    private:
        void            AddCurrXY();
        void            AddXRedu();
        void            AddLastX();
        void            InitCommon();                           // common to normal and copy constructor
        void            LocalCopy(const DFO_XYRemoveDuplicate& a);     // common to copy constructor and = operator
};

#endif //DFO_XYREMOVEDUPLICATE_H

