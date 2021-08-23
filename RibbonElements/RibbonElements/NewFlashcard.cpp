// NewFlashcard.cpp : implementation file
//

#include "pch.h"
#include "stdafx.h"
#include "RibbonElements.h"
#include "NewFlashcard.h"
#include "afxdialogex.h"


// NewFlashcard dialog

IMPLEMENT_DYNAMIC(NewFlashcard, CDialogEx)

NewFlashcard::NewFlashcard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWCARD, pParent)
{

}

void NewFlashcard::setAnswer(CString temp)
{
	answer = temp;
}

NewFlashcard::~NewFlashcard()
{
}

void NewFlashcard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_QUESTION, question);
	DDX_CBString(pDX, IDC_ANSWER, answer);
}

BEGIN_MESSAGE_MAP(NewFlashcard, CDialogEx)
	ON_BN_CLICKED(IDSHOW, &NewFlashcard::Initialize)
END_MESSAGE_MAP()


// NewFlashcard message handlers

void NewFlashcard::Initialize() //called by main to set text in dialog box to highlightanswer
{
	GetDlgItem(IDC_ANSWER)->SetWindowText(answer);
}

void NewFlashcard::OnBnClickedOk()
{

	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_EDIT1)->GetWindowText(userInput);
	

	CDialogEx::OnOK();
}