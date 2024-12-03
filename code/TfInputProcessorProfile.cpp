// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "Private.h"
#include "TfInputProcessorProfile.h"
#include "Globals.h"
CTfInputProcessorProfile::CTfInputProcessorProfile()
{
    Global::LogInfo(TEXT("CTfInputProcessorProfile::CTfInputProcessorProfile"));
    _pInputProcessorProfile = nullptr;
}

CTfInputProcessorProfile::~CTfInputProcessorProfile()
{
    Global::LogInfo(TEXT("CTfInputProcessorProfile::~CTfInputProcessorProfile"));
    if (_pInputProcessorProfile) {
        _pInputProcessorProfile->Release();
        _pInputProcessorProfile = nullptr;
    }
}

HRESULT CTfInputProcessorProfile::CreateInstance()
{
    Global::LogInfo(TEXT("CTfInputProcessorProfile::CreateInstance"));
    HRESULT	hr = CoCreateInstance(CLSID_TF_InputProcessorProfiles, nullptr, CLSCTX_INPROC_SERVER,
        IID_ITfInputProcessorProfiles, (void**)&_pInputProcessorProfile);

    return hr;
}

HRESULT CTfInputProcessorProfile::GetCurrentLanguage(_Out_ LANGID *plangid)
{
    Global::LogInfo(TEXT("CTfInputProcessorProfile::GetCurrentLanguage"));
    if (_pInputProcessorProfile)
    {
        return _pInputProcessorProfile->GetCurrentLanguage(plangid);
    }
    else
    {
        return E_FAIL;
    }
}

HRESULT CTfInputProcessorProfile::GetDefaultLanguageProfile(LANGID langid, REFGUID catid, _Out_ CLSID *pclsid, _Out_ GUID *pguidProfile)
{
    Global::LogInfo(TEXT("CTfInputProcessorProfile::GetDefaultLanguageProfile"));
    if (_pInputProcessorProfile)
    {
        return _pInputProcessorProfile->GetDefaultLanguageProfile(langid, catid, pclsid, pguidProfile);
    }
    else
    {
        return E_FAIL;
    }
}
