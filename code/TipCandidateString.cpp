// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "private.h"
#include "TipCandidateString.h"
#include "Globals.h"

HRESULT CTipCandidateString::CreateInstance(_Outptr_ CTipCandidateString **ppobj)
{  
    Global::LogInfo(TEXT("CTipCandidateString::CreateInstance"));
    if (ppobj == nullptr)
    {
        return E_INVALIDARG;
    }
    *ppobj = nullptr;

    *ppobj = new (std::nothrow) CTipCandidateString();
    if (*ppobj == nullptr) 
    {
        return E_OUTOFMEMORY;
    }

    return S_OK;
}

HRESULT CTipCandidateString::CreateInstance(REFIID riid, _Outptr_ void **ppvObj)
{ 
    Global::LogInfo(TEXT("CTipCandidateString::CreateInstance"));
    if (ppvObj == nullptr)
    {
        return E_INVALIDARG;
    }
    *ppvObj = nullptr;

    *ppvObj = new (std::nothrow) CTipCandidateString();
    if (*ppvObj == nullptr) 
    {
        return E_OUTOFMEMORY;
    }

    return ((CTipCandidateString*)(*ppvObj))->QueryInterface(riid, ppvObj);
}

CTipCandidateString::CTipCandidateString(void)
{
    Global::LogInfo(TEXT("CTipCandidateString::CTipCandidateString"));
    _refCount = 0;
    _index = 0;
}

CTipCandidateString::~CTipCandidateString()
{
    Global::LogInfo(TEXT("CTipCandidateString::~CTipCandidateString"));
}

// IUnknown methods
STDMETHODIMP CTipCandidateString::QueryInterface(REFIID riid, _Outptr_ void **ppvObj)
{
    Global::LogInfo(TEXT("CTipCandidateString::QueryInterface"));
    if (ppvObj == nullptr)
    {
        return E_POINTER;
    }
    *ppvObj = nullptr;

    if (IsEqualIID(riid, IID_IUnknown))
    {
        *ppvObj = (CTipCandidateString*)this;
    }
    else if (IsEqualIID(riid, IID_ITfCandidateString))
    {
        *ppvObj = (CTipCandidateString*)this;
    }

    if (*ppvObj == nullptr)
    {
        return E_NOINTERFACE;
    }

    AddRef();
    return S_OK;
}

STDMETHODIMP_(ULONG) CTipCandidateString::AddRef(void)
{
    Global::LogInfo(TEXT("CTipCandidateString::AddRef"));
    return (ULONG)InterlockedIncrement((LONG*)&_refCount);
}

STDMETHODIMP_(ULONG) CTipCandidateString::Release(void)
{
    Global::LogInfo(TEXT("CTipCandidateString::Release"));
    ULONG refT = (ULONG)InterlockedDecrement((LONG*)&_refCount);
    if (0 < refT)
    {
        return refT;
    }

    delete this;

    return 0;
}

// ITfCandidateString methods
STDMETHODIMP CTipCandidateString::GetString(BSTR *pbstr)
{
    Global::LogInfo(TEXT("CTipCandidateString::GetString"));
    *pbstr = SysAllocString(_candidateStr.c_str());
    return S_OK;
}

STDMETHODIMP CTipCandidateString::GetIndex(_Out_ ULONG *pnIndex)
{
    Global::LogInfo(TEXT("CTipCandidateString::GetIndex"));
    if (pnIndex == nullptr)
    {
        return E_POINTER;
    }

    *pnIndex = _index;
    return S_OK;
}

STDMETHODIMP CTipCandidateString::SetIndex(ULONG uIndex)
{
    Global::LogInfo(TEXT("CTipCandidateString::SetIndex"));
    _index = uIndex;
    return S_OK;
}

STDMETHODIMP CTipCandidateString::SetString(_In_ const WCHAR *pch, DWORD_PTR length)
{
    Global::LogInfo(TEXT("CTipCandidateString::SetString"));
    _candidateStr.assign(pch, 0, length);
    return S_OK;
}
