// FFlashcard.cpp : implementation file
//

#include "pch.h"
#include "stdafx.h"
#include "RibbonElements.h"
#include "FFlashcard.h"
#include "afxdialogex.h"


// FFlashcard dialog

IMPLEMENT_DYNAMIC(FFlashcard, CDialogEx)

FFlashcard::FFlashcard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGPANEL, pParent)
{

}

CString FFlashcard::getuserInput()
{
	return userInput;
}

FFlashcard::~FFlashcard()
{
}

void FFlashcard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_INPUTTEXT, userInput);
}


BEGIN_MESSAGE_MAP(FFlashcard, CDialogEx) //controls what happens when what is clicked
	ON_BN_CLICKED(IDC_STUDY, &FFlashcard::OnBnClickedNew)

END_MESSAGE_MAP()


// FFlashcard message handlers


void FFlashcard::OnBnClickedNew()
{
	// TODO: Adds the text in the entry box as a blank card (no links in vector)
	CString temp;
	GetDlgItem(IDC_INPUTTEXT)->GetWindowText(temp);
	if (temp == "") {
		return;
	}
	userInput = temp; //needs to initialize a new card in the list
}

void FFlashcard::OnBnClickedLink()
{

}

void FFlashcard::OnBnClickedDelete()
{


}