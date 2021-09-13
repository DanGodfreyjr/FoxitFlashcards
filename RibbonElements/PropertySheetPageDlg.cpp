// PropertySheetPageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonElements.h"
#include "PropertySheetPageDlg.h"
#include "afxdialogex.h"


// PropertySheetPageDlg dialog

IMPLEMENT_DYNAMIC(PropertySheetPageDlg, CDialogEx)

PropertySheetPageDlg::PropertySheetPageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PropertySheetPageDlg::IDD, pParent)
{
	m_ribbonStatic = NULL;
	m_ribbonListBox = NULL;
}

PropertySheetPageDlg::~PropertySheetPageDlg()
{
	if (NULL != m_ribbonStatic)
	{
		FRRibbonStyleStaticRelease(m_ribbonStatic);
		m_ribbonStatic = NULL;
	}
	if (NULL != m_ribbonListBox)
	{
		FRRibbonStyleListBoxRelease(m_ribbonListBox);
		m_ribbonListBox = NULL;
	}
}

void PropertySheetPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PropertySheetPageDlg, CDialogEx)
	ON_LBN_DBLCLK(IDC_LIST_BOX, &PropertySheetPageDlg::OnLbnDblclkListBox)
	ON_LBN_SELCHANGE(IDC_LIST_BOX, &PropertySheetPageDlg::OnLbnSelchangeListBox)
END_MESSAGE_MAP()


// PropertySheetPageDlg message handlers


BOOL PropertySheetPageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();	
	// TODO:  Add extra initialization here
	//Set the dlg skin.
	FRSysInstallDialogSkinTheme(this->GetSafeHwnd());

	//set the Static to ribbon style.
	m_ribbonStatic = (FR_RibbonStyleStatic)FRRibbonBackStageViewItemModifiedToRibbonStyleButton(
		GetDlgItem(IDC_STATIC_HELLOWORD), IDC_STATIC_HELLOWORD, FR_RibbonStyle_Static, NULL);
	FRRibbonStyleStaticSetFontStyle(m_ribbonStatic, 20, FALSE, FALSE, FALSE, FALSE); 
	FRRibbonStyleStaticSetTextColor(m_ribbonStatic, RGB(255, 0, 0));
	FRRibbonStyleStaticSetBackgroundColor(m_ribbonStatic, RGB(0, 255, 0));

	//set the ListBox to Ribbon style. 
	//note: The listBox Owner Draw properties must set to Variable.
	m_ribbonListBox = (FR_RibbonStyleListBox)FRRibbonBackStageViewItemModifiedToRibbonStyleButton(
		GetDlgItem(IDC_LIST_BOX), IDC_LIST_BOX, FR_RibbonStyle_ListBox, NULL);

	CListBox* pListbox = (CListBox*)FRRibbonStyleListBoxGetMFCListBox(m_ribbonListBox);
	pListbox->Detach();
	pListbox->Attach(GetDlgItem(IDC_LIST_BOX)->GetSafeHwnd());
	
	FS_DIBitmap fs_bitmap = CRibbonElementsApp::GetBmpFromRes(IDR_PDF1);
	FS_DIBitmap fs_bitmap2 = CRibbonElementsApp::GetBmpFromRes(IDR_PDF2);
	FS_INT32 fs_imageIndex = FRRibbonStyleListBoxAddImage(m_ribbonListBox, fs_bitmap);
	FRRibbonStyleListBoxAddString(m_ribbonListBox, (FS_LPCWSTR)L"ListBoxItem1", fs_imageIndex);
	FRRibbonStyleListBoxAddString(m_ribbonListBox, (FS_LPCWSTR)L"ListBoxItem2", fs_imageIndex);	
	FSDIBitmapDestroy(fs_bitmap);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void PropertySheetPageDlg::OnLbnDblclkListBox()
{
	// TODO: Add your control notification handler code here
	CListBox* pListbox = (CListBox*)FRRibbonStyleListBoxGetMFCListBox(m_ribbonListBox);
	int nCurSel = pListbox->GetCurSel();
	if (nCurSel == 0)
	{
		FRSysShowMessageBox((FS_LPCWSTR)L"On Double Click ListBoxItem1", MB_OK | MB_ICONINFORMATION,
			NULL, NULL, FRAppGetMainFrameWnd());
	}
}


void PropertySheetPageDlg::OnLbnSelchangeListBox()
{
	// TODO: Add your control notification handler code here
	CListBox* pListbox = (CListBox*)FRRibbonStyleListBoxGetMFCListBox(m_ribbonListBox);
	int nCurSel = pListbox->GetCurSel();
	if (nCurSel == 1)
	{
		FRSysShowMessageBox((FS_LPCWSTR)L"On Left Click ListBoxItem2", MB_OK | MB_ICONINFORMATION,
			NULL, NULL, FRAppGetMainFrameWnd());
	}
}
