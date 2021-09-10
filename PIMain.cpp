#include "PIMain.h"

#include "../../../include/basic/fs_pidata.h"
#include "../../../include/basic/fs_basicExpT.h"

/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

PIMain.cpp

 - Source code that must be linked into every plug-in.
 
*********************************************************************/


/*Core HFT Manager.*/
FRCoreHFTMgr *_gpCoreHFTMgr = NULL;

/*The plug-in ID*/
void* _gPID = NULL;

extern  FS_BOOL PIHandshake(FS_INT32 handshakeVersion, void *handshakeData);

//#include <windows.h>
#if DEBUG
#include <tchar.h>
#endif

#if (!_USRDLL && !_AFXDLL  && !CUSTOM_DLLMAIN) /* Omit DllMain for MFC plug-ins and plug-ins with custom DllMain */
/*BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{

	case DLL_PROCESS_ATTACH:
	break;
	case DLL_THREAD_ATTACH:
	break;
	case DLL_THREAD_DETACH:
	break;
	case DLL_PROCESS_DETACH:
	break;

	}
    return TRUE;
}*/
#endif /* custom DllMain */


/* 
** This routine is called by the host application to set up the plug-in's SDK-provided functionality.
*/
FS_BOOL PISetupSDK(FS_INT32 handshakeVersion, void *sdkData)
{
	if(handshakeVersion != HANDSHAKE_V0100) return FALSE;
	PISDKData_V0100 *pSDKData = (PISDKData_V0100*)sdkData;
	
	/* Get our globals out */
	_gpCoreHFTMgr = pSDKData->PISDGetCoreHFT();

	/* Get PID */
	_gPID = pSDKData->PISDGetPID(sdkData);

	/* Set the plug-in's handshake routine, which is called next by the host application */
	pSDKData->PISDSetHandshakeProc(sdkData, &PIHandshake);

	/* For compatibility purposes, set the plug-in's SDK version, 
	so that Foxit Reader will not load the plug-in whose version is larger than Foxit Reader. */
	pSDKData->PISetSDKVersion(sdkData, SDK_VERSION);

	return TRUE;
}

#ifdef __cplusplus
extern "C" {
#endif


/* The export function of plug-ins */
__declspec(dllexport) FS_BOOL PlugInMain(FS_INT32* handshakeVersion, PISetupSDKProcType* setupProc)
{
	/*
	** handshakeVersion tells us which version of the handshake struct the application has sent us.
	** The version we want to use is returned to the application so it can adjust accordingly.
	*/

	*handshakeVersion = HANDSHAKE_V0100;
	*setupProc = &PISetupSDK;
	return TRUE;
} 


#ifdef __cplusplus
}
#endif