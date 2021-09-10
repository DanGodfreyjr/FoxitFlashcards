#pragma once


// quizBox dialog
#include <vector>
#include "NewFlashcard.h"

class quizBox : public CDialogEx
{
	DECLARE_DYNAMIC(quizBox)

public:
	quizBox(CWnd* pParent = nullptr);   // standard constructor
	virtual ~quizBox();
	void setDeck(std::vector<card> cardVec);
	std::vector<card> cardDeck;
	int cardNumber=0;
	void nextCard();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	//BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
