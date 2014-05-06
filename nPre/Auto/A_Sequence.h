///////////////////////////////////////////////////////////////////////////////////
//
// A_Sequence.h
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
//      Implements auto setup procedures.
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef A_SEQUENCE_H
#define A_SEQUENCE_H

namespace nsAutoSetup  {

    //  sequence auto setup
    class SequenceAutoSpec {
        public:
            enum    {maxSpec = 8};

            bool    doExtract;
            bool    doSpec[maxSpec];    
            bool    opOK;
            int     seqCount;   

            const int   nSpec;
            const char* specID[maxSpec];

        public:
                            SequenceAutoSpec(int nS);
                    void    Init() {opOK = false; seqCount = 0;}

            virtual bool    IsEnabled(int indx) const;
            bool            DoSpec(int indx)    const;
            bool            ExtractOK()         const {return doExtract && opOK;}   
    };

    class FlowSequenceAutoSpec : public SequenceAutoSpec {
        public:
                         FlowSequenceAutoSpec();
            virtual bool IsEnabled(int indx) const;
    };
    class HistSequenceAutoSpec : public SequenceAutoSpec {
        public:
                         HistSequenceAutoSpec();
            virtual bool IsEnabled(int indx) const;
    };
    class PulseSequenceAutoSpec : public SequenceAutoSpec {
        public:
                         PulseSequenceAutoSpec();
            virtual bool IsEnabled(int indx) const;
    };


    extern FlowSequenceAutoSpec     flowSpec;
    extern HistSequenceAutoSpec     histSpec;
    extern PulseSequenceAutoSpec    pulseSpec;
    extern PulseSequenceAutoSpec    slugSpec;

    extern bool                     testDesignMode;

    extern void             AutoSequenceCheckOK();

    extern int              AutoSequenceWillDeletePages();
    extern void             AutoSequenceSetup();

};

//  assuming that if it's included, we want to use it and no name clashes with other nSight
using namespace nsAutoSetup;

#endif //A_SEQUENCE_H
