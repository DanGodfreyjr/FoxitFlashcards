/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

PIMain.h

  - Include file for PIMain.cpp.
  - Contains #defines, macros, function protos, and global variable
    declarations.
*********************************************************************/

#ifndef PIMAIN_H
#define PIMAIN_H

#include "../../../include/basic/fs_basicExpT.h"
#include "../../../include/basic/fs_common.h"


#ifdef __cplusplus
extern "C" {
#endif

/* The following globals are only needed if functions from them are being accessed */

extern FRCoreHFTMgr* _gpCoreHFTMgr;
extern void* _gPID;

/*
** Prototypes for PI-provided functions in the handshaking.
*/
FS_BOOL PISetupSDK(FS_INT32 handshakeVersion, void *sdkData);

#ifdef __cplusplus
}
#endif
#endif