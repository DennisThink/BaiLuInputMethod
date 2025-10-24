// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved



//--------------------------
// Begin By DennisThink
// 不太清楚作用是什么 TODO:
// TSF 的设计是多线程和异步的，
// 为了确保线程安全和一致性，
// 所有对文档上下文 (ITfContext) 的编辑操作必须封装在一个 ITfEditSession 接口中。
// End By DennisThink
//--------------------------
#pragma once

class CSampleIME;

class CEditSessionBase : public ITfEditSession
{
public:
    CEditSessionBase(_In_ CSampleIME *pTextService, _In_ ITfContext *pContext);
    virtual ~CEditSessionBase();

    // IUnknown
    STDMETHODIMP QueryInterface(REFIID riid, _Outptr_ void **ppvObj);
    STDMETHODIMP_(ULONG) AddRef(void);
    STDMETHODIMP_(ULONG) Release(void);

    // ITfEditSession
    virtual STDMETHODIMP DoEditSession(TfEditCookie ec) = 0;

protected:
    ITfContext *_pContext;
    CSampleIME *_pTextService;

private:
    LONG _refCount;     // COM ref count
};
