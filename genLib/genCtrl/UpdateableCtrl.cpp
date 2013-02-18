///////////////////////////////////////////////////////////////////////////////////
//
// UpdateableCtrl.cpp
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
// DESCRIPTION: Windows specific code for implementing basic controls with
//              callbacks on resource defined dialog forms.
//              Defines callback processing for dialog.
//
///////////////////////////////////////////////////////////////////////////////////

#include "GenLibAfx.h"
#include <genCtrl/UpdateableCtrl.h>
#include <genApp/ProjectUtil.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CUpdateableCtrl::CUpdateableCtrl()
{
    ClearCallbacks();
}

void CUpdateableCtrl::AddCallback(CCtrlUpdate* newCtrl)
{
    for (int i = 0; i < maxCallbacks; i++)
        {
            if (normalCallbacks[i] == NULL)
                {
                    normalCallbacks[i] = newCtrl;
                    return;
                }
        }
    ASSERT(false);
}

void CUpdateableCtrl::AddCallback(CCtrlUpdate* newCtrl, int reason)
{
    for (int i = 0; i < maxCallbacks; i++)
        {
            if (reasonCallbacks[i] == NULL)
                {
                    reasonCallbacks[i] = newCtrl;
                    reasonVal[i] = reason;
                    return;
                }
        }
    ASSERT(false);
}

void CUpdateableCtrl::ClearCallbacks()
{
    for (int i = 0; i < maxCallbacks; i++)
        {
            normalCallbacks[i] = NULL;
            reasonCallbacks[i] = NULL;
        }
}

void CUpdateableCtrl::DoCallbacks()
{
    projectUtilities::SetModifiedFlag(true);
    for (int i = 0; i < maxCallbacks; i++)
        {
            if (normalCallbacks[i] != NULL)
                normalCallbacks[i]->DoCtrlUpdate();
            if (reasonCallbacks[i] != NULL)
                reasonCallbacks[i]->DoCtrlUpdate(reasonVal[i]);
        }
}

