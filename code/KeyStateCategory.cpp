// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

#include "KeyStateCategory.h"

CKeyStateCategoryFactory* CKeyStateCategoryFactory::_instance;

CKeyStateCategoryFactory::CKeyStateCategoryFactory()
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::CKeyStateCategoryFactory"));
    _instance = nullptr;
}

CKeyStateCategoryFactory* CKeyStateCategoryFactory::Instance()
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::Instance"));
    if (nullptr == _instance)
    {
        _instance = new (std::nothrow) CKeyStateCategoryFactory();
    }

    return _instance;
}

CKeyStateCategory* CKeyStateCategoryFactory::MakeKeyStateCategory(KEYSTROKE_CATEGORY keyCategory, _In_ CSampleIME *pTextService)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::MakeKeyStateCategory"));
    CKeyStateCategory* pKeyState = nullptr;

    switch (keyCategory)
    {
    case CATEGORY_NONE:
        pKeyState = new (std::nothrow) CKeyStateNull(pTextService);
        break;

    case CATEGORY_COMPOSING:
        pKeyState = new (std::nothrow) CKeyStateComposing(pTextService);
        break;

    case CATEGORY_CANDIDATE:
        pKeyState = new (std::nothrow) CKeyStateCandidate(pTextService);
        break;

    case CATEGORY_PHRASE:
        pKeyState = new (std::nothrow) CKeyStatePhrase(pTextService);
        break;

    default:
        pKeyState = new (std::nothrow) CKeyStateNull(pTextService);
        break;
    }
    return pKeyState;
}

void CKeyStateCategoryFactory::Release()
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::Release"));
    if (_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
}

/*
class CKeyStateCategory
*/
CKeyStateCategory::CKeyStateCategory(_In_ CSampleIME *pTextService)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::CKeyStateCategory"));
    _pTextService = pTextService;
}

CKeyStateCategory::~CKeyStateCategory(void)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::~CKeyStateCategory"));
}

HRESULT CKeyStateCategory::KeyStateHandler(KEYSTROKE_FUNCTION function, KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::KeyStateHandler"));
    switch(function)
    {
    case FUNCTION_INPUT:
        return HandleKeyInput(dto);

    case FUNCTION_FINALIZE_TEXTSTORE_AND_INPUT:
        return HandleKeyFinalizeTextStoreAndInput(dto);

    case FUNCTION_FINALIZE_TEXTSTORE:
        return HandleKeyFinalizeTextStore(dto);

    case FUNCTION_FINALIZE_CANDIDATELIST_AND_INPUT:
        return HandleKeyFinalizeCandidatelistAndInput(dto);

    case FUNCTION_FINALIZE_CANDIDATELIST:
        return HandleKeyFinalizeCandidatelist(dto);

    case FUNCTION_CONVERT:
        return HandleKeyConvert(dto);

    case FUNCTION_CONVERT_WILDCARD:
        return HandleKeyConvertWildCard(dto);

    case FUNCTION_CANCEL:
        return HandleKeyCancel(dto);

    case FUNCTION_BACKSPACE:
        return HandleKeyBackspace(dto);

    case FUNCTION_MOVE_LEFT:
    case FUNCTION_MOVE_RIGHT:
        return HandleKeyArrow(dto);

    case FUNCTION_MOVE_UP:
    case FUNCTION_MOVE_DOWN:
    case FUNCTION_MOVE_PAGE_UP:
    case FUNCTION_MOVE_PAGE_DOWN:
    case FUNCTION_MOVE_PAGE_TOP:
    case FUNCTION_MOVE_PAGE_BOTTOM:
        return HandleKeyArrow(dto);

    case FUNCTION_DOUBLE_SINGLE_BYTE:
        return HandleKeyDoubleSingleByte(dto);

    case FUNCTION_PUNCTUATION:
        return HandleKeyPunctuation(dto);

    case FUNCTION_SELECT_BY_NUMBER:
        return HandleKeySelectByNumber(dto);

    }
    return E_INVALIDARG;
}

void CKeyStateCategory::Release()
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::Release"));
    delete this;
}

// _HandleCompositionInput
HRESULT CKeyStateCategory::HandleKeyInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyInput"));
	dto;
    return E_NOTIMPL;
}

// HandleKeyFinalizeTextStore
HRESULT CKeyStateCategory::HandleKeyFinalizeTextStore(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyFinalizeTextStore"));
	dto;
    return E_NOTIMPL;
}
// HandleKeyCompositionFinalizeTextStoreAndInput
HRESULT CKeyStateCategory::HandleKeyFinalizeTextStoreAndInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyFinalizeTextStoreAndInput"));
	dto;
    return E_NOTIMPL;
}

// HandleKeyCompositionFinalizeCandidatelistAndInput
HRESULT CKeyStateCategory::HandleKeyFinalizeCandidatelistAndInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyFinalizeCandidatelistAndInput"));
	dto;
    return E_NOTIMPL;
}

// HandleKeyCompositionFinalizeCandidatelist
HRESULT CKeyStateCategory::HandleKeyFinalizeCandidatelist(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyFinalizeCandidatelist"));
	dto;
    return E_NOTIMPL;
}

// HandleKeyConvert
HRESULT CKeyStateCategory::HandleKeyConvert(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyConvert"));
	dto;
    return E_NOTIMPL;
}

// HandleKeyConvertWildCard
HRESULT CKeyStateCategory::HandleKeyConvertWildCard(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyConvertWildCard"));
	dto;
    return E_NOTIMPL;
}

//_HandleCancel
HRESULT CKeyStateCategory::HandleKeyCancel(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyCancel"));
	dto;
    return E_NOTIMPL;
}

//_HandleCompositionBackspace
HRESULT CKeyStateCategory::HandleKeyBackspace(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyBackspace"));
	dto;
    return E_NOTIMPL;
}

//_HandleCompositionArrowKey
HRESULT CKeyStateCategory::HandleKeyArrow(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyArrow"));
	dto;
    return E_NOTIMPL;
}

//_HandleCompositionDoubleSingleByte
HRESULT CKeyStateCategory::HandleKeyDoubleSingleByte(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyDoubleSingleByte"));
	dto;
    return E_NOTIMPL;
}

//_HandleCompositionPunctuation
HRESULT CKeyStateCategory::HandleKeyPunctuation(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeyPunctuation"));
	dto;
    return E_NOTIMPL;
}

HRESULT CKeyStateCategory::HandleKeySelectByNumber(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCategoryFactory::HandleKeySelectByNumber"));
	dto;
    return E_NOTIMPL;
}

/*
class CKeyStateComposing
*/
CKeyStateComposing::CKeyStateComposing(_In_ CSampleIME *pTextService) : CKeyStateCategory(pTextService)
{
    Global::LogInfo(TEXT("CKeyStateComposing::CKeyStateComposing"));
}

HRESULT CKeyStateComposing::HandleKeyInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyInput"));
    return _pTextService->_HandleCompositionInput(dto.ec, dto.pContext, dto.wch);
}

HRESULT CKeyStateComposing::HandleKeyFinalizeTextStoreAndInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyFinalizeTextStoreAndInput"));
    _pTextService->_HandleCompositionFinalize(dto.ec, dto.pContext, FALSE);
    return _pTextService->_HandleCompositionInput(dto.ec, dto.pContext, dto.wch);
}

HRESULT CKeyStateComposing::HandleKeyFinalizeTextStore(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyFinalizeTextStore"));
    return _pTextService->_HandleCompositionFinalize(dto.ec, dto.pContext, FALSE);
}

HRESULT CKeyStateComposing::HandleKeyFinalizeCandidatelistAndInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyFinalizeCandidatelistAndInput"));
    _pTextService->_HandleCompositionFinalize(dto.ec, dto.pContext, TRUE);
    return _pTextService->_HandleCompositionInput(dto.ec, dto.pContext, dto.wch);
}

HRESULT CKeyStateComposing::HandleKeyFinalizeCandidatelist(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyFinalizeCandidatelist"));
    return _pTextService->_HandleCompositionFinalize(dto.ec, dto.pContext, TRUE);
}

HRESULT CKeyStateComposing::HandleKeyConvert(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyConvert"));
    return _pTextService->_HandleCompositionConvert(dto.ec, dto.pContext, FALSE);
}

HRESULT CKeyStateComposing::HandleKeyConvertWildCard(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyConvertWildCard"));
    return _pTextService->_HandleCompositionConvert(dto.ec, dto.pContext, TRUE);
}

HRESULT CKeyStateComposing::HandleKeyCancel(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyCancel"));
    return _pTextService->_HandleCancel(dto.ec, dto.pContext);
}

HRESULT CKeyStateComposing::HandleKeyBackspace(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyBackspace"));
    return _pTextService->_HandleCompositionBackspace(dto.ec, dto.pContext);
}

HRESULT CKeyStateComposing::HandleKeyArrow(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyArrow"));
    return _pTextService->_HandleCompositionArrowKey(dto.ec, dto.pContext, dto.arrowKey);
}

HRESULT CKeyStateComposing::HandleKeyDoubleSingleByte(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyDoubleSingleByte"));
    return _pTextService->_HandleCompositionDoubleSingleByte(dto.ec, dto.pContext, dto.wch);
}

HRESULT CKeyStateComposing::HandleKeyPunctuation(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateComposing::HandleKeyPunctuation"));
    return _pTextService->_HandleCompositionPunctuation(dto.ec, dto.pContext, dto.wch);
}

/*
class CKeyStateCandidate
*/
CKeyStateCandidate::CKeyStateCandidate(_In_ CSampleIME *pTextService) : CKeyStateCategory(pTextService)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::CKeyStateCandidate"));
}

// _HandleCandidateInput
HRESULT CKeyStateCandidate::HandleKeyFinalizeCandidatelist(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeyFinalizeCandidatelist"));
    return _pTextService->_HandleCandidateFinalize(dto.ec, dto.pContext);
}

// HandleKeyFinalizeCandidatelistAndInput
HRESULT CKeyStateCandidate::HandleKeyFinalizeCandidatelistAndInput(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeyFinalizeCandidatelistAndInput"));
    _pTextService->_HandleCandidateFinalize(dto.ec, dto.pContext);
    return _pTextService->_HandleCompositionInput(dto.ec, dto.pContext, dto.wch);
}

//_HandleCandidateConvert
HRESULT CKeyStateCandidate::HandleKeyConvert(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeyConvert"));
    return _pTextService->_HandleCandidateConvert(dto.ec, dto.pContext);
}

//_HandleCancel
HRESULT CKeyStateCandidate::HandleKeyCancel(KeyHandlerEditSessionDTO dto)    
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeyCancel"));
    return _pTextService->_HandleCancel(dto.ec, dto.pContext);
}

//_HandleCandidateArrowKey
HRESULT CKeyStateCandidate::HandleKeyArrow(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeyArrow"));
    return _pTextService->_HandleCandidateArrowKey(dto.ec, dto.pContext, dto.arrowKey);
}

//_HandleCandidateSelectByNumber
HRESULT CKeyStateCandidate::HandleKeySelectByNumber(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStateCandidate::HandleKeySelectByNumber"));
    return _pTextService->_HandleCandidateSelectByNumber(dto.ec, dto.pContext, dto.code);
}

/*
class CKeyStatePhrase
*/

CKeyStatePhrase::CKeyStatePhrase(_In_ CSampleIME *pTextService) : CKeyStateCategory(pTextService)
{
    Global::LogInfo(TEXT("CKeyStatePhrase::CKeyStatePhrase"));
}

//HandleKeyFinalizeCandidatelist
HRESULT CKeyStatePhrase::HandleKeyFinalizeCandidatelist(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStatePhrase::HandleKeyFinalizeCandidatelist"));
    return _pTextService->_HandlePhraseFinalize(dto.ec, dto.pContext);
}

//HandleKeyCancel
HRESULT CKeyStatePhrase::HandleKeyCancel(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStatePhrase::HandleKeyCancel"));
    return _pTextService->_HandleCancel(dto.ec, dto.pContext);
}

//HandleKeyArrow
HRESULT CKeyStatePhrase::HandleKeyArrow(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStatePhrase::HandleKeyArrow"));
    return _pTextService->_HandlePhraseArrowKey(dto.ec, dto.pContext, dto.arrowKey);
}

//HandleKeySelectByNumber
HRESULT CKeyStatePhrase::HandleKeySelectByNumber(KeyHandlerEditSessionDTO dto)
{
    Global::LogInfo(TEXT("CKeyStatePhrase::HandleKeySelectByNumber"));
    return _pTextService->_HandlePhraseSelectByNumber(dto.ec, dto.pContext, dto.code);
}