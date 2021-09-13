// resultBox.cpp : implementation file
//

//#include "pch.h"
#include "stdafx.h"
#include "NewFlashcard.h"
#include "RibbonElements.h"
#include "resultBox.h"
#include "afxdialogex.h"
#include <vector>
#include <algorithm>


// resultBox dialog

IMPLEMENT_DYNAMIC(resultBox, CDialogEx)

resultBox::resultBox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

resultBox::~resultBox()
{
}
void resultBox::setDeck(std::vector<card> cardVec) {
	for (int x = 0; x < cardVec.size(); x++) {
		this->cardDeck.push_back(cardVec.at(x));
	}
	wchar_t page[256];
	swprintf_s(page, L"%d", this->cardDeck.at(0).pageNumber);
	FS_WideString fsShowTop = FSWideStringNew3(page, wcslen(page) * sizeof(WCHAR));
	//FS_LPCWSTR cardName = (FS_LPCWSTR)page;
	//GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(0).title);
	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowTop), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	std::vector<int> k = generateList(); //TODO: make k
	this->LoadListBox(k);
}

void resultBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(resultBox, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &resultBox::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT1, &resultBox::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &resultBox::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &resultBox::OnBnClickedOk)
END_MESSAGE_MAP()


// resultBox message handlers


void resultBox::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	CListBox *pMyList = (CListBox *)GetDlgItem(IDC_LIST1);
	int listIndex = pMyList->GetCurSel();
	GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(listIndex).title);
	GetDlgItem(IDC_EDIT2)->SetWindowText(this->cardDeck.at(listIndex).answer);
}


void resultBox::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void resultBox::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void resultBox::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void resultBox::LoadListBox(std::vector<int> order) {
	CString str = _T("");
	CString temp;
	// int currIndex = 0;
	CListBox *pMyList = (CListBox *)GetDlgItem(IDC_LIST1);
	for (int i = 0; i < this->cardDeck.size(); i++) {
		if (this->cardDeck.at(i).correct) {
			temp = L"Correct";
		}
		else {
			temp = L"Incorrect";
		}
		str.Format(_T("Question %d: %s"), i+1,temp);
		
		pMyList->AddString(str);
		
	}
}

std::vector<int> resultBox::generateList()
{
	std::vector<int> order;
	for (int i = 0; i < cardDeck.size(); ++i) {
		order.push_back(i);
	}

	std::random_shuffle(order.begin(), order.end());

	return order;
}
