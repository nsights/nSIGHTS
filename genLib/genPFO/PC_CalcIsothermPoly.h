///////////////////////////////////////////////////////////////////////////////////
//
// PC_CalcIsothermPoly.h
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
//      Basic plotting objects used by all applications, primarily concerned with plot annotation:
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef PC_CALCISOTHERMPOLY_H
#define PC_CALCISOTHERMPOLY_H

#include <genClass/SC_IntArray.h>
#include <genClass/SC_CoordArray.h>
#include <genClass/SC_DoubleArray.h>

class PC_CalcIsothermPoly  {
    public:
        enum            TriType {ttTrapezoid,   // 4 vertex
                                 ttPrism};      // 6 vertex

        SC_CoordArray   polyCoords;
        SC_CoordArray   currTriCoords;
        SC_DoubleArray  currTriData;

    private:
        TriType         triType;

        int             ntriVertex;
        int             ntriEdges;
        int             ntriFace;

        enum            {maxTriVertex = 6};

        int             tcount;
        Line3D          tLine;

        enum            {maxTriEdges = 9};
        bool            tok[maxTriEdges];
        Coord3D         cvals[maxTriEdges];

        int             nseg;
        enum            {maxTriFace = 5};
        int             segStart[maxTriFace];
        int             segEnd[maxTriFace];
        bool            segProcessed[maxTriFace];

        double          isoValue;

    public:
                        PC_CalcIsothermPoly();
                        ~PC_CalcIsothermPoly();

        void            SetTriType(TriType inTriType);

        bool            CalcTriPoly(const double& isoVal);

    private:
        void            AddEdgeSegments(const int edgeList[]);
        void            CalcVals(int stIndx, int endIndx, int tindx);
};

#endif // !PC_CALCISOTHERMPOLY_H

