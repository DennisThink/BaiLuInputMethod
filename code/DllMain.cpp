// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "Private.h"
#include "Globals.h"

//+---------------------------------------------------------------------------
//
// DllMain
//
//----------------------------------------------------------------------------

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pvReserved)
{
	pvReserved;

    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        Global::OpenLogFile();
        Global::dllInstanceHandle = hInstance;

        if (!InitializeCriticalSectionAndSpinCount(&Global::CS, 0))
        {
            return FALSE;
        }

        if (!Global::RegisterWindowClass()) {
            return FALSE;
        }

        Global::LogInfo(TEXT("DLL_PROCESS_ATTACH"));
        break;

    case DLL_PROCESS_DETACH:
        Global::LogInfo(TEXT("DLL_PROCESS_DETACH"));
        Global::CloseLogFile();
        DeleteCriticalSection(&Global::CS);
        Global::UnRegisterWindowClass();
        break;

    case DLL_THREAD_ATTACH:
        Global::LogInfo(TEXT("DLL_THREAD_ATTACH"));
        break;

    case DLL_THREAD_DETACH:
        Global::LogInfo(TEXT("DLL_THREAD_DETACH"));
        break;
    }

    return TRUE;
}
