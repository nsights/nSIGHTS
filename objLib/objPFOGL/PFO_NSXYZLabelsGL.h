///////////////////////////////////////////////////////////////////////////////////
//
// PFO_NSXYZLabelsGL.h
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
//    Implements code to draw objPFO functional objects on a plot.
//
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef PFO_NSXYZLABELSGL_H
#define PFO_NSXYZLABELSGL_H

#include <genPFOGL/OGLBaseObj.h>

#include <objPFO/PFO_NSXYZLabels.h>


class PFO_NSXYZLabelsGL : public PFO_NSXYZLabels, protected OGLBaseObj {

  public:
                      PFO_NSXYZLabelsGL(PlotDefC& assPlt);
                      PFO_NSXYZLabelsGL(const PFO_NSXYZLabelsGL& a, PlotDefC& assPlt);
                      ~PFO_NSXYZLabelsGL();

      PFO_NSXYZLabelsGL& operator= (const PFO_NSXYZLabelsGL& a);

      //  do draw
      void            DrawPlotObject();

};

#endif // !PFO_NSXYZLABELSGL_H

