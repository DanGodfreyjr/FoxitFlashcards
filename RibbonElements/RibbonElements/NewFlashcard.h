#pragma once

#include "stdafx.h"
#include <vector>
#include <string>
// NewFlashcard dialog

class NewFlashcard : public CDialogEx
{
	DECLARE_DYNAMIC(NewFlashcard)

public:
	NewFlashcard(CWnd* pParent = nullptr);   // standard constructor
	CString question;
	CString answer;
	//CString getQuestion();
	//CString getAnswer();
	virtual ~NewFlashcard();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWCARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Initialize(CString highlight); //takes the highlighted text and saves it to IDC_ANSWER so modal can load it in directly
};
