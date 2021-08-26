#include "stdafx.h"
#include "ElementsProc.h"
#include "FFlashcard.h"
#include "NewFlashcard.h"
#include "RibbonElements.h"
#include "resource.h"
#include "PropertySheetPageDlg.h"
#include <vector>

CElementsProc::CElementsProc(void)
{
}


CElementsProc::~CElementsProc(void)
{
}

void CElementsProc::OnSliderExecuteProc(void* clientData)
{
	//Do something when the slider is executed.
	FR_RibbonSlider fr_Slider = (FR_RibbonSlider)clientData;
	FS_INT32 nPos = FRRibbonSliderGetPos(fr_Slider);
	if (nPos == 50)
	{
		FRSysShowMessageBox((FS_LPCWSTR)L"Slider Pos = 50", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	}
	else if (nPos == 100)
	{
		FRSysShowMessageBox((FS_LPCWSTR)L"Slider Pos = 100", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
	}

}

FS_BOOL CElementsProc::OnSliderMarkedProc(void* clientData)
{
	return FALSE;
}

FS_BOOL CElementsProc::OnSliderEnabledProc(void* clientData)
{
	//Used to determine whether the slider is enabled.
	return TRUE;
}
void CElementsProc::OnButtonFreeData(void* clientDate)
{
	FS_WideString fsButtonData = (FS_WideString)clientDate;
	FS_LPCWSTR str = FSWideStringCastToLPCWSTR(fsButtonData);
	FSWideStringDestroy(fsButtonData);
}

void CElementsProc::OnButtonExecuteProc(void* clientDate)//save set
{
		FS_WideString fsButtonData = (FS_WideString)clientDate;
		FRSysShowMessageBox((FS_LPCWSTR)L"Card set and document saved. (TODO: implement save)", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());

		FFlashcard openMenu;
		openMenu.DoModal();
}

void CElementsProc::OnButtonExecuteProc2(void* clientDate) //new card
{
	FS_WideString fsButtonData = (FS_WideString)clientDate;
	
	//DONE: turn the highlighted text into a CString and save it to temp
	CString temp = L"";

	//TODO: set up cardtemp

	FR_Document pDoc = FRAppGetActiveDocOfPDDoc();
	if (pDoc == NULL) {
		return;
	}
	FR_TextSelectTool textSelectTool = FRDocGetTextSelectTool(pDoc);
	FS_WideString wtext = FSWideStringNew(); //Initialize FS_WideString
	FRTextSelectToolGetSelectedText(textSelectTool, &wtext);
	const wchar_t* ctext = FSWideStringCastToLPCWSTR(wtext);//convert to a a data type that can output the in a message box.
	FS_WideString fswsShowMsg = FSWideStringNew3(ctext, wcslen(ctext) * sizeof(WCHAR));

	temp = ctext;

	NewFlashcard* window = new NewFlashcard();
	window->Create(IDD_NEWCARD, NULL);
	window->ShowWindow(SW_NORMAL);

	window->OnInitDialog(temp);

	//NewFlashcard openMenu;
	//openMenu.setAnswer(temp);
	//openMenu.DoModal();

	//CAN BE USED FOR VIEWING STORED CARDS//
	//FS_LPCWSTR inputfile = L"C:\\Users\\Administrator\\Desktop\\PDF\\06ma.pdf";
	//FR_Document frDocument = FRDocOpenFromFile(inputfile, (FS_LPCSTR)L"", true, true); //shows how to load a PDF and display it
}

void CElementsProc::OnButtonExecuteProc3(void* clientDate) //go to first
{
	FS_WideString fsButtonData = (FS_WideString)clientDate;
	CString temp = L"Name of first card"; //cstring element of first object in data type vector

	//TODO:: loops through the study set





	FS_LPCWSTR cardName = (FS_LPCWSTR)temp;

	FRSysShowMessageBox(cardName, MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());

}

void CElementsProc::OnButtonExecuteProc4(void* clientDate) //previous card
{
	FS_WideString fsButtonData = (FS_WideString)clientDate;
	FRSysShowMessageBox((FS_LPCWSTR)L"Card set and document saved. (TODO: implement save)", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());

}

void CElementsProc::OnButtonExecuteProc5(void* clientDate) //next card
{
	//increments one in the vector of card objects and displays it
}

void CElementsProc::OnButtonExecuteProc6(void* clientDate) //delete card
{
	//moves view to adjacent card (if next card exists, next. if not, previous, if last card in stack, delete in place)

}
FS_BOOL CElementsProc::OnButtonMarkedProc(void* clientDate)
{
	return FALSE;
}
FS_BOOL CElementsProc::OnButtonEnableProc(void* clientDate)
{
	return TRUE;
}

HWND CElementsProc::FRRibbonBackstageCreateProc(HWND hParentWnd, void* clientData)
{
	PropertySheetPageDlg *pPage = new PropertySheetPageDlg();
	if (pPage)
	{
		BOOL bCreate = pPage->Create(IDD_DLG_PROPERTYSHEETPAGE, CWnd::FromHandle(hParentWnd));
		if (bCreate)
		{
			return pPage->GetSafeHwnd();
		}
	}	
	return NULL;

}

void CElementsProc::FRRibbonBackstageDestoryProc(void* pDialog, void* clientData)
{
	PropertySheetPageDlg* pPage = (PropertySheetPageDlg*)clientData;
	if (NULL != pPage)
	{
		delete pPage;
		pPage = NULL;
	}
}