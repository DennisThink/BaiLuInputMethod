// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "Private.h"
#include "BaseWindow.h"
#include "ButtonWindow.h"
#include "Globals.h"

//+---------------------------------------------------------------------------
//
// CButtonWindow
//
//----------------------------------------------------------------------------

CButtonWindow::CButtonWindow()
{
    Global::LogInfo(TEXT("CButtonWindow::CButtonWindow"));
    typeOfControl = 0;
}

//+---------------------------------------------------------------------------
//
// ~CButtonWindow
//
//----------------------------------------------------------------------------

CButtonWindow::~CButtonWindow()
{
    Global::LogInfo(TEXT("CButtonWindow::~CButtonWindow"));
}

//+---------------------------------------------------------------------------
//
// _OnPaint
//
//----------------------------------------------------------------------------

void CButtonWindow::_OnPaint(_In_ HDC dcHandle, _In_ PAINTSTRUCT *pps)
{
    dcHandle;
    pps;
    Global::LogInfo(TEXT("CButtonWindow::_OnPaint"));
}

//+---------------------------------------------------------------------------
//
// _OnLButtonDown
//
//----------------------------------------------------------------------------

void CButtonWindow::_OnLButtonDown(POINT pt)
{
    pt;

    typeOfControl = DFCS_PUSHED;
    _StartCapture();
    Global::LogInfo(TEXT("CButtonWindow::_OnLButtonDown"));
}

//+---------------------------------------------------------------------------
//
// _WindowProcCallback
//
//----------------------------------------------------------------------------
LRESULT CALLBACK CButtonWindow::_WindowProcCallback(_In_ HWND wndHandle, UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) 
{ 
    Global::LogInfo(TEXT("CButtonWindow::_WindowProcCallback"));
    wndHandle;
    uMsg;
    wParam;
    lParam;

    return 0; 
}

//+---------------------------------------------------------------------------
//
// _OnLButtonUp
//
//----------------------------------------------------------------------------

void CButtonWindow::_OnLButtonUp(POINT pt)
{
    Global::LogInfo(TEXT("CButtonWindow::_OnLButtonUp"));
    pt;

    if (_IsCapture())
    {
        _EndCapture();
    }

    typeOfControl = 0;
}
