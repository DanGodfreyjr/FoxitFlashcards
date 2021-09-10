#pragma once

#include "stdafx.h"
#include <vector>
// FFlashcard dialog

class FFlashcard : public CDialogEx
{
	DECLARE_DYNAMIC(FFlashcard)

public:
	FFlashcard(CWnd* pParent = nullptr);   // standard constructor
										   // line of text entered as card name
	CString userInput; // line of text entered as card name	//TODO: create a vector [GetLinkAtPoint/FPD_Link]
	CString getuserInput();	
	virtual ~FFlashcard();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGPANEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNew(); //when new is clicked
	afx_msg void OnBnClickedLink();
	afx_msg void OnBnClickedDelete();

};
