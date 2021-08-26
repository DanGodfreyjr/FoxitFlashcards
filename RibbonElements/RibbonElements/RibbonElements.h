// RibbonElements.h : main header file for the RibbonElements DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <vector>


// CRibbonElementsApp
// See RibbonElements.cpp for the implementation of this class
//

struct card {
	CString title = L"";
	int pageNumber = -1;
	CString answer = L"";
};
//CREATE A STRUCTURE THAT SAVES CARDS
//std::vector<card>deck{};

class CRibbonElementsApp : public CWinApp
{
public:
	CRibbonElementsApp();

	DECLARE_MESSAGE_MAP()
public:
	void CreateElementsToNewCategory();
	void AddMenuToFilePage();

	static FS_DIBitmap GetBmpFromRes(UINT uID);
};

