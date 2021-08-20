// NewFlashcard.cpp : implementation file
//

#include "pch.h"
#include "stdafx.h"
#include "RibbonElements.h"
#include "NewFlashcard.h"
#include "afxdialogex.h"
#include <string>


// NewFlashcard dialog

IMPLEMENT_DYNAMIC(NewFlashcard, CDialogEx)

NewFlashcard::NewFlashcard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWCARD, pParent)
{

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

void NewFlashcard::Initialize(CString highlight) //can take in text read by a diff function and set home function to it
{
	
}


BEGIN_MESSAGE_MAP(NewFlashcard, CDialogEx)
END_MESSAGE_MAP()


// NewFlashcard message handlers
