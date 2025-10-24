// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#pragma once

class CSampleIME;

class CTfTextLayoutSink : public ITfTextLayoutSink
{
public:
    CTfTextLayoutSink(_In_ CSampleIME *pTextService);
    virtual ~CTfTextLayoutSink();

    // IUnknown methods
    STDMETHODIMP QueryInterface(REFIID riid, _Outptr_ void **ppvObj) override;
    STDMETHODIMP_(ULONG) AddRef(void) override;
    STDMETHODIMP_(ULONG) Release(void) override;

    // ITfTextLayoutSink
    STDMETHODIMP OnLayoutChange(_In_ ITfContext *pContext, TfLayoutCode lcode, _In_ ITfContextView *pContextView) override;



    HRESULT _GetTextExt(_Out_ RECT *lpRect);
    ITfContext* _GetContextDocument() { return _pContextDocument; };

    virtual VOID _LayoutChangeNotification(_In_ RECT *lpRect) = 0;
    virtual VOID _LayoutDestroyNotification() = 0;
protected:
    HRESULT _StartLayout(_In_ ITfContext* pContextDocument, TfEditCookie ec, _In_ ITfRange* pRangeComposition);
    VOID _EndLayout();
private:
    HRESULT _AdviseTextLayoutSink();
    HRESULT _UnadviseTextLayoutSink();

private:
    ITfRange* _pRangeComposition;
    ITfContext* _pContextDocument;
    TfEditCookie _tfEditCookie;
    CSampleIME* _pTextService;
    DWORD _dwCookieTextLayoutSink;
    LONG _refCount;
};
