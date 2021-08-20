#pragma once
#include "afxwin.h"


// PropertySheetPageDlg dialog

class PropertySheetPageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PropertySheetPageDlg)

public:
	PropertySheetPageDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~PropertySheetPageDlg();

// Dialog Data
	enum { IDD = IDD_DLG_PROPERTYSHEETPAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

private:
	FR_RibbonStyleStatic	 m_ribbonStatic;
	FR_RibbonStyleListBox	 m_ribbonListBox;
public:
	afx_msg void OnLbnDblclkListBox();
	afx_msg void OnLbnSelchangeListBox();
};
