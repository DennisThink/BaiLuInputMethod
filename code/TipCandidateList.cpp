// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "private.h"
#include "TipCandidateList.h"
#include "EnumTfCandidates.h"
#include "TipCandidateString.h"

HRESULT CTipCandidateList::CreateInstance(_Outptr_ ITfCandidateList **ppobj, size_t candStrReserveSize)
{  
    Global::LogInfo(TEXT("CTipCandidateList::CreateInstance"));
    if (ppobj == nullptr)
    {
        return E_INVALIDARG;
    }
    *ppobj = nullptr;

    *ppobj = new (std::nothrow) CTipCandidateList(candStrReserveSize);
    if (*ppobj == nullptr) 
    {
        return E_OUTOFMEMORY;
    }

    return S_OK;
}

HRESULT CTipCandidateList::CreateInstance(REFIID riid, _Outptr_ void **ppvObj, size_t candStrReserveSize)
{  
    Global::LogInfo(TEXT("CTipCandidateList::CreateInstance"));
    if (ppvObj == nullptr)
    {
        return E_INVALIDARG;
    }
    *ppvObj = nullptr;

    *ppvObj = new (std::nothrow) CTipCandidateList(candStrReserveSize);
    if (*ppvObj == nullptr) 
    {
        return E_OUTOFMEMORY;
    }

    return ((CTipCandidateList*)(*ppvObj))->QueryInterface(riid, ppvObj);
}

CTipCandidateList::CTipCandidateList(size_t candStrReserveSize)
{
    Global::LogInfo(TEXT("CTipCandidateList::CTipCandidateList"));
    _refCount = 0;

    if (0 < candStrReserveSize)
    {
        _tfCandStrList.reserve(candStrReserveSize);
    }
}

CTipCandidateList::~CTipCandidateList()
{
    Global::LogInfo(TEXT("CTipCandidateList::~CTipCandidateList"));
}

STDMETHODIMP CTipCandidateList::QueryInterface(REFIID riid, _Outptr_ void **ppvObj)
{
    Global::LogInfo(TEXT("CTipCandidateList::QueryInterface"));
    if (ppvObj == nullptr)
    {
        return E_POINTER;
    }
    *ppvObj = nullptr;

    if (IsEqualIID(riid, IID_IUnknown))
    {
        *ppvObj = (ITfCandidateList*)this;
    }
    else if (IsEqualIID(riid, IID_ITfCandidateList))
    {
        *ppvObj = (ITfCandidateList*)this;
    }

    if (*ppvObj == nullptr)
    {
        return E_NOINTERFACE;
    }

    AddRef();
    return S_OK;
}

STDMETHODIMP_(ULONG) CTipCandidateList::AddRef()
{
    Global::LogInfo(TEXT("CTipCandidateList::AddRef"));
    return (ULONG)InterlockedIncrement((LONG*)&_refCount);
}

STDMETHODIMP_(ULONG) CTipCandidateList::Release()
{
    Global::LogInfo(TEXT("CTipCandidateList::Release"));
    ULONG  cRefT  = (ULONG)InterlockedDecrement((LONG*)&_refCount);
    if (0 < cRefT)
    {
        return cRefT;
    }

    delete this;

    return 0;
}

STDMETHODIMP CTipCandidateList::EnumCandidates(_Outptr_ IEnumTfCandidates **ppEnum)
{
    Global::LogInfo(TEXT("CTipCandidateList::EnumCandidates"));
    return CEnumTfCandidates::CreateInstance(IID_IEnumTfCandidates, (void**)ppEnum, _tfCandStrList);
}

STDMETHODIMP CTipCandidateList::GetCandidate(ULONG nIndex, _Outptr_result_maybenull_ ITfCandidateString **ppCandStr)
{
    Global::LogInfo(TEXT("CTipCandidateList::GetCandidate"));
    if (ppCandStr == nullptr)
    {
        return E_POINTER;
    }
    *ppCandStr = nullptr;

    ULONG sizeCandStr = (ULONG)_tfCandStrList.Count();
    if (sizeCandStr <= nIndex)
    {
        return E_FAIL;
    }

    for (UINT i = 0; i < _tfCandStrList.Count(); i++)
    {
        ITfCandidateString** ppCandStrCur = _tfCandStrList.GetAt(i);
        ULONG indexCur = 0;
        if ((nullptr != ppCandStrCur) && (SUCCEEDED((*ppCandStrCur)->GetIndex(&indexCur))))
        {
            if (nIndex == indexCur)
            {
                BSTR bstr;
                CTipCandidateString* pTipCandidateStrCur = (CTipCandidateString*)(*ppCandStrCur);
                pTipCandidateStrCur->GetString(&bstr);

                CTipCandidateString::CreateInstance(IID_ITfCandidateString, (void**)ppCandStr);

                if (nullptr != (*ppCandStr))
                {
                    CTipCandidateString* pTipCandidateStr = (CTipCandidateString*)(*ppCandStr);
                    pTipCandidateStr->SetString((LPCWSTR)bstr, SysStringLen(bstr));
                }

                SysFreeString(bstr);

                break;
            }
        }
    }
    return S_OK;
}

STDMETHODIMP CTipCandidateList::GetCandidateNum(_Out_ ULONG *pnCnt)
{
    Global::LogInfo(TEXT("CTipCandidateList::GetCandidateNum"));
    if (pnCnt == nullptr)
    {
        return E_POINTER;
    }

    *pnCnt = (ULONG)(_tfCandStrList.Count());
    return S_OK;
}

STDMETHODIMP CTipCandidateList::SetResult(ULONG nIndex, TfCandidateResult imcr)
{
    Global::LogInfo(TEXT("CTipCandidateList::SetResult"));
    nIndex;imcr;

    return E_NOTIMPL;
}

STDMETHODIMP CTipCandidateList::SetCandidate(_In_ ITfCandidateString **ppCandStr)
{
    Global::LogInfo(TEXT("CTipCandidateList::SetCandidate"));
    if (ppCandStr == nullptr)
    {
        return E_POINTER;
    }

    ITfCandidateString** ppCandLast = _tfCandStrList.Append();
    if (ppCandLast)
    {
        *ppCandLast = *ppCandStr;
    }

    return S_OK;
}
