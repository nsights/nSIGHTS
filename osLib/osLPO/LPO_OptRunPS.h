///////////////////////////////////////////////////////////////////////////////////
//
// LPO_OptRunPS.h
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
//      File I/O and user interface for all osLFO functional objects.
//
//
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef LPO_OPTRUNPS_H
#define LPO_OPTRUNPS_H

#include <genApp/C_MenuBase.h>

#include <osClass/DO_OptSimResults.h>

#include "LPO_OptRun.h"

class LPO_OptRunPS : public MenuBaseC {
    private:
            FuncObjRefUIC           optSimResultsObjRefUI;

            FormWidget              topRowForm;

            BoolRadioBoxUIC         listRunsUI;
            SC_IntArray             currRuns;
            SC_IntArray             currCases;
            BaseUIC                 buttonFrame;
            PushButton              clearAllUI;
            PushButton              selectAllUI;

            BaseUIC                 selectedDataFrame;
            ScrolledListWidget      selectedDataUI;

            FormWidget              covarMosForm;
            BaseUIC                 csFrame;
            ToggleBoxWidget         csActualUI;
            ToggleBoxWidget         csEstimatedUI;
            ToggleBoxWidget         csFitComponentUI;

            BaseUIC                 mosFrame;
            ToggleBoxWidget         mosListAllUI;
            ToggleBoxWidget         mosListBestUI;
            ToggleBoxWidget         mosListStatisticsUI;

            BaseUIC                 listFrame;
            FormWidget              row1Form;
            ToggleBoxWidget         listRunSummaryUI;
            ToggleBoxWidget         listFitValuesUI;
            ToggleBoxWidget         listParameterEstimatesUI;
            FormWidget              row2Form;
            ToggleBoxWidget         listEstimatedDataVariancesUI;
            ToggleBoxWidget         listParameterCorrelationsUI;
            ToggleBoxWidget         listNormalizedCovarianceMatricesUI;
            FormWidget              row3Form;
            ToggleBoxWidget         listDenormalizedCovarianceMatricesUI;
            ToggleBoxWidget         list95ConfidenceLimitsUI;
            ToggleBoxWidget         listJacobianUI;
            FormWidget              row4Form;
            ToggleBoxWidget         listModelStructureUI;
            ToggleBoxWidget         listCovarianceMatrixCorrelationsUI;

            bool                    runDataOK;
            DC_OptSimResults*       runDataDC;

    public:
                        LPO_OptRunPS();
                        ~LPO_OptRunPS(){};

                void    InitMenu();

                void    MenuOpen(LPO_OptRun&   inData);

                void    SetMenuData(LPO_OptRun&    inData);
                bool    UIdataOK();
                void    GetMenuData(LPO_OptRun&   outData);

                void    MenuDefault();
                void    MenuClear();


    private:
                void    ClearAll();
        static  void    ClearAllCB(void* inObj);

                void    SelectAll();
        static  void    SelectAllCB(void* inObj);

        static  void    ChangeListTypeCB(void* inObj);
                void    ChangeListType();

        static  void    SetSelectedDataCB(void* inObj);
                void    SetSelectedData();

        static  void    SetAllSensitiveCB(void* inObj);
                void    SetAllSensitive();

                void    SetAllUI(bool flag);

};

#endif // !LPO_OPTRUNPS_H

