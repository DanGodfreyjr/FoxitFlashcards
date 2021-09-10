// NewFlashcard.cpp : implementation file
//

//#include "pch.h"
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
	ON_BN_CLICKED(IDOK, &NewFlashcard::OnBnClickedOk)
END_MESSAGE_MAP()


// NewFlashcard message handlers

void NewFlashcard::OnBnClickedOk() //the new card is created
{
	//whatever text is in the box, is now saved to "question"
	CString temp;
	GetDlgItem(IDC_QUESTION)->GetWindowText(temp);
	if (temp == "") {
		return;
	}
	question = temp;
	FR_Document currDoc = FRAppGetActiveDocOfPDDoc();
	if (currDoc == NULL) {
		return;
	}
	struct card* ptr;
	deck.push_back(card());
	int position = deck.size();
	ptr = &deck.at(position - 1);

	ptr->title = this->question;
	ptr->answer = this->answer;

	FR_DocView currView = FRDocGetCurrentDocView(currDoc);
	FR_PageView currPage = FRDocViewGetCurrentPageView(currView);
	int k = FRPageViewGetPageIndex(currPage);
	page = k;
	this->page = page;
	ptr->pageNumber = page;
	//whatever the current page number is, is now saved to "page"
	GetDlgItem(IDC_QUESTION)->SetWindowText(L"");
	CDialogEx::OnOK();
}

BOOL NewFlashcard::OnInitDialog(CString text) {
	//window.DoModal();
	GetDlgItem(IDC_ANSWER)->SetWindowText(text);
	answer = text; //the text that has been passed in is saved to "answer"
	return true;
}

