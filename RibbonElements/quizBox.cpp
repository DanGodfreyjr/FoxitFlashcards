// quizBox.cpp : implementation file
//

//#include "pch.h"
#include "stdafx.h"
#include "RibbonElements.h"
#include "quizBox.h"
#include "resultBox.h"
#include "afxdialogex.h"
#include <vector>
#include <ctime>
#include <algorithm>


// quizBox dialog

IMPLEMENT_DYNAMIC(quizBox, CDialogEx)

quizBox::quizBox(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

quizBox::~quizBox()
{
}

void quizBox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(quizBox, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &quizBox::OnBnClickedButton1) //show
	ON_EN_CHANGE(IDC_EDIT1, &quizBox::OnEnChangeEdit1) //edit box
	ON_BN_CLICKED(IDC_BUTTON2, &quizBox::OnBnClickedButton2) //correct
	ON_BN_CLICKED(IDC_BUTTON3, &quizBox::OnBnClickedButton3) //wrong
END_MESSAGE_MAP()


// quizBox message handlers
FR_Annot* highlight;
FR_Annot AddHighlightAnnot(FR_PageView frPageView, FS_FloatRect rect, FS_LPCWSTR displayText, FR_Document doc) {

	//FR_DocView docView = FRPageViewGetDocView(frPageView);
	FPD_Object fpdObject = FPDDictionaryNew();
	FS_ByteString strtype = FSByteStringNew3("Annot", -1);
	FPD_Object fpdfstringAnnot = FPDStringNew(strtype, 0);
	FPDDictionaryAddValue(fpdObject, "Type", fpdfstringAnnot);
	FS_ByteString strSubtype = FSByteStringNew3("Highlight", -1);
	FPD_Object fpdfstringSubtype = FPDStringNew(strSubtype, 0);
	FPDDictionaryAddValue(fpdObject, "Subtype", fpdfstringSubtype);
	FPDDictionaryAddValue(fpdObject, "Subj", FPDStringNew(FSByteStringNew3("Highlight", -1), 0));

	FPD_Object quad = FPDArrayNew(); //{x1, y1, x2, y2, x3, y3, x4, y5}
	FPDArrayAddNumber(quad, rect.left);
	FPDArrayAddNumber(quad, rect.top);
	FPDArrayAddNumber(quad, rect.right);
	FPDArrayAddNumber(quad, rect.top);
	FPDArrayAddNumber(quad, rect.left);
	FPDArrayAddNumber(quad, rect.bottom);
	FPDArrayAddNumber(quad, rect.right);
	FPDArrayAddNumber(quad, rect.bottom);

	FPDDictionaryAddValue(fpdObject, "QuadPoints", quad);

	FPD_Object quadColor = FPDArrayNew();
	FPDArrayAddNumber(quadColor, 1); // 1 means RGB Color
	FPDArrayAddNumber(quadColor, 0.929412); // Defines the color
	FPDArrayAddNumber(quadColor, 0); // Defines the color
	FPDDictionaryAddValue(fpdObject, "C", quadColor);

	FS_FLOAT left = FPDArrayGetFloat(quad, 0);
	FS_FLOAT right = FPDArrayGetFloat(quad, 2);
	FS_FLOAT top = FPDArrayGetFloat(quad, 1);
	FS_FLOAT bottom = FPDArrayGetFloat(quad, 5);



	FPD_Object fpdfstringPopout = FPDStringNewW(displayText); // Create string object from wide string
	FPDDictionaryAddValue(fpdObject, "Contents", fpdfstringPopout);
	FPDDictionarySetAtRect(fpdObject, "Rect", rect);
	FR_Annot frAnnot = FRPageViewAddAnnot(frPageView, fpdObject, -1); // Adds the highlight annotation


	//bool check = FRDocViewIsValidPageView(docView, frPageView);
	//int check = FRPageViewGetPageIndex(frPageView);

	wchar_t topNum[256];
	wchar_t bottomNum[256];
	wchar_t leftNum[256];
	wchar_t rightNum[256];

	swprintf_s(topNum, L"%f", top);
	swprintf_s(bottomNum, L"%f", top);
	swprintf_s(leftNum, L"%f", rect.left);
	swprintf_s(rightNum, L"%f", rect.right);
	FS_WideString fsShowTop = FSWideStringNew3(topNum, wcslen(topNum) * sizeof(WCHAR));
	FS_WideString fsShowBottom = FSWideStringNew3(bottomNum, wcslen(bottomNum) * sizeof(WCHAR));
	FS_WideString fsShowLeft = FSWideStringNew3(leftNum, wcslen(leftNum) * sizeof(WCHAR));
	FS_WideString fsShowRight = FSWideStringNew3(rightNum, wcslen(rightNum) * sizeof(WCHAR));

	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowTop), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());

	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowBottom), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowLeft), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowRight), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	return frAnnot;

}
void quizBox::OnBnClickedButton1()
{

	// TODO: Add your control notification handler code here
	FR_Document pDoc = FRAppGetActiveDocOfPDDoc();
	FR_DocView docView = FRDocGetCurrentDocView(pDoc);
	if (this->cardNumber < this->cardDeck.size()) {
		FRDocViewGotoPageView(docView, this->cardDeck.at(cardNumber).pageNumber);
	}
	FR_PageView pageView = FRDocViewGetPageView(docView, this->cardDeck.at(cardNumber).pageNumber);

	FPD_ProgressiveSearch sch = FPDProgressiveSearchNew();


	FPD_Page fpdPage = FPDPageNew(); //initialized fpdfPage
	FPD_Document fpdDocument = FRDocGetPDDoc(pDoc);
	FPD_Object pDict = FPDDocGetPage(fpdDocument, cardDeck.at(cardNumber).pageNumber);
	FPDPageLoad(fpdPage, fpdDocument, pDict, TRUE); //Load page into memory

	FPDProgressiveSearchFindFrom(sch, fpdPage, (FS_LPCWSTR)(this->cardDeck.at(this->cardNumber).answer), 0, FPDTEXT_CONSECUTIVE, NULL);
	FS_FloatRect firstRect = FPDProgressiveSearchGetRect(sch, 0);
	*highlight = AddHighlightAnnot(pageView, firstRect, L" ", pDoc);
}

std::vector<int> order;
int currOrder = 0;

void quizBox::setDeck(std::vector<card> cardVec) {
	this->cardDeck.clear(); //resets cardDeck at the start of every iteration
	order.clear();
	currOrder = 0;

	for (int x = 0; x < cardVec.size(); x++) {
		this->cardDeck.push_back(cardVec.at(x));
	}



	for (int i = 0; i < cardVec.size(); ++i) {
		order.push_back(i);
	}
	srand(time(NULL));
	//generate a random number, then shuffle the random number's amount of times

	int randomgen = rand() % 10 + 1;

	for (int i = 0; i < randomgen; ++i) {
		std::random_shuffle(order.begin(), order.end());
	}





	wchar_t page[256];
	swprintf_s(page, L"%d", this->cardDeck.at(order.at(0)).pageNumber);
	FS_WideString fsShowTop = FSWideStringNew3(page, wcslen(page) * sizeof(WCHAR));
	//FS_LPCWSTR cardName = (FS_LPCWSTR)page;
	GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(order.at(0)).title);
	//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowTop), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());

}
resultBox *resultWindow = new resultBox();
void quizBox::nextCard() {
	this->cardNumber= cardNumber+1;
	if (this->cardNumber == this->cardDeck.size()) {
		resultWindow->Create(IDD_DIALOG6);
		resultWindow->ShowWindow(SW_NORMAL);
		resultWindow->setDeck(this->cardDeck);
	}
	else {
		wchar_t cNum[256];
		//swprintf_s(cNum, L"%d", this->cardNumber);
		swprintf_s(cNum, L"%d", order.at(this->cardNumber));
		FS_WideString fsShowTop = FSWideStringNew3(cNum, wcslen(cNum) * sizeof(WCHAR));
		//GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(this->cardNumber).title);
		GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(order.at(this->cardNumber)).title);
		//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowTop), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	}
}

void quizBox::nextQuizCard() {

	for (int i = 0; i < order.size(); ++i) {
		wchar_t cNum[256];
		swprintf_s(cNum, L"%d", order.at(i));
		FS_WideString fsShowTop = FSWideStringNew3(cNum, wcslen(cNum) * sizeof(WCHAR));
		GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(order.at(i)).title);
	}
	resultWindow->Create(IDD_DIALOG6);
	resultWindow->ShowWindow(SW_NORMAL);
	resultWindow->setDeck(this->cardDeck);

	//this->cardNumber = cardNumber + 1;
	//if (this->cardNumber == this->cardDeck.size()) {
	//	resultWindow->Create(IDD_DIALOG6);
	//	resultWindow->ShowWindow(SW_NORMAL);
	//	resultWindow->setDeck(this->cardDeck);
	//}
	//else {
	//	wchar_t cNum[256];
	//	swprintf_s(cNum, L"%d", this->cardNumber);
	//	FS_WideString fsShowTop = FSWideStringNew3(cNum, wcslen(cNum) * sizeof(WCHAR));
	//	GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(this->cardNumber).title);
		//FRSysShowMessageBox(FSWideStringCastToLPCWSTR(fsShowTop), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	//}
}

void quizBox::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

}
//BOOL quizBox::OnInitDialog() {
//	GetDlgItem(IDC_EDIT1)->SetWindowText(this->cardDeck.at(0).title);
	//return true;
//}


void quizBox::OnBnClickedButton2() //correct
{
	// TODO: Add your control notification handler code here
	this->cardDeck.at(order.at(currOrder)).correct = true;
	++currOrder;
	this->nextCard();

}


void quizBox::OnBnClickedButton3() //incorrect
{
	// TODO: Add your control notification handler code here
	++currOrder;
	this->nextCard();
}
