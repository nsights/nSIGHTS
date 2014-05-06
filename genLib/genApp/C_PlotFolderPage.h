///////////////////////////////////////////////////////////////////////////////////
//
// C_PlotFolderPage.h
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
// DESCRIPTION: Code which defines and implements the basic framework user-interface (UI)
//              and provides OS platform specific implementation of common facilities
//              such as copy/paste and configuration file I/O.
//              Page type which is child of plot page and contains plot objects only
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef C_PLOTFOLDERPAGE_H
#define C_PLOTFOLDERPAGE_H

#include <genApp/C_MenuPage.h>
#include <genApp/C_AllocPage.h>


class PlotFolderPageC: public MenuPageC {

    friend class PlotFolderPageAlloc;

protected:
    virtual void    ObjectPageChangeComplete(MenuPageC* oldParent) const;

private:
    PlotFolderPageC();

    virtual const MenuPageC*        GetActualParent() const;

    virtual bool         AcceptAsChild(MenuPageC& newChild) const;
    virtual bool         AcceptAsParent(MenuPageC* newParent) const;
    virtual void         ParentChanging(MenuPageC* newParent);
    virtual void         ResetChildren();

    bool                 CheckObjectsOnPage(const MenuPageC& newParent,
                         const MenuPageC& currPage) const;

    void                 ChangeObjectsOnPage(MenuPageC& newParent,
                         MenuPageC& currPage) const;
};

class PlotFolderPageAlloc: public AllocPageC {
public:
    static const char*   pageTypeDesc;

public:
    static const char*   PageTypeName() {return pageTypeDesc;}

protected:
    //  implemented in allocator -- checks objToCreate against name
    virtual MenuPageC*   CreatePage() const;

    virtual const char*  GetPageTypeName() const;

};


#endif // C_PLOTFOLDERPAGE_H
