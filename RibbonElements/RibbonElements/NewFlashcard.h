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
	CString question = L"question here";
	CString answer = L"answer here";
	int page = -1;
	//CString getQuestion();
	void setAnswer(CString temp);
	virtual ~NewFlashcard();
	std::vector<card>deck{};

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWCARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL OnInitDialog(CString text);
	
};
