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
	
END_MESSAGE_MAP()


// NewFlashcard message handlers

void NewFlashcard::OnBnClickedOk() //the new card is created
{
	card tempcard;
	tempcard.title = question;
	tempcard.answer = this->answer;
	//tempcard.pageNumber = 
	//TODO: fetch page number
	//deck.push_back(tempcard);

	CDialogEx::OnOK();
}

BOOL NewFlashcard::OnInitDialog(CString text) {
	//window.DoModal();
	GetDlgItem(IDC_ANSWER)->SetWindowText(text);
	return true;
}