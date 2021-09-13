#pragma once


// resultBox dialog

class resultBox : public CDialogEx
{
	DECLARE_DYNAMIC(resultBox)

public:
	resultBox(CWnd* pParent = nullptr);   // standard constructor
	virtual ~resultBox();
	std::vector<card> cardDeck;
	void setDeck(std::vector<card> cardVec);
	void LoadListBox(std::vector<int> order);
	std::vector<int> generateList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
};
