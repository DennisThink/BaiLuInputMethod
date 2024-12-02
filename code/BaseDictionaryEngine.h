// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved


#pragma once

#include "File.h"
#include "SampleIMEBaseStructure.h"

//---------------------------------------
// 
// Begin By DennisThink
// 
// 基础的字典引擎，实现根据输入的字符(字符串),获取待选择的多个字或者词。
// End By DennisThink
// 
//---------------------------------------
class CBaseDictionaryEngine
{
public:
    CBaseDictionaryEngine(LCID locale, _In_ CFile *pDictionaryFile);
    virtual ~CBaseDictionaryEngine();

    virtual VOID CollectWord(_In_ CStringRange *psrgKeyCode, _Out_ CSampleImeArray<CStringRange> *pasrgWordString)
    { 
        psrgKeyCode; 
        pasrgWordString = nullptr;
    }

    virtual VOID CollectWord(_In_ CStringRange *psrgKeyCode, _Out_ CSampleImeArray<CCandidateListItem> *pItemList)
    { 
        psrgKeyCode;
        pItemList = nullptr;
    }

    virtual VOID SortListItemByFindKeyCode(_Inout_ CSampleImeArray<CCandidateListItem> *pItemList);

protected:
    CFile* _pDictionaryFile;
    LCID _locale;

private:
    VOID MergeSortByFindKeyCode(_Inout_ CSampleImeArray<CCandidateListItem> *pItemList, int leftRange, int rightRange);
    int CalculateCandidateCount(int leftRange,  int rightRange);
};
