#ifndef _MSNSPMH_H_
#define _MSNSPMH_H_

#define SECURITY_WIN32  1

#include <windows.h>

typedef unsigned long ULONG;
typedef char CCHAR;          // winnt
typedef short CSHORT;
typedef ULONG CLONG;

typedef LONG NTSTATUS;

typedef unsigned short RTL_ATOM, *PRTL_ATOM;

typedef enum _NT_PRODUCT_TYPE {
    NtProductWinNt = 1,
    NtProductLanManNt,
    NtProductServer
} NT_PRODUCT_TYPE, *PNT_PRODUCT_TYPE;

typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR  Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;

typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR Buffer;
} STRING;
typedef STRING *PSTRING;

typedef const char *PCSZ;

typedef STRING ANSI_STRING;
typedef PSTRING PANSI_STRING;

typedef STRING OEM_STRING;
typedef PSTRING POEM_STRING;
typedef const STRING* PCOEM_STRING;

#define STATUS_SUCCESS ((NTSTATUS)0x00000000L) 

#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

#include <stdio.h>
//#include <nt.h>
//#include <ntrtl.h>
//#include <nturtl.h>
//#include <ntlsa.h>
#include "win32.h"
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include <sspi.h>
#include <issperr.h>
#include <crypt.h>
#include <ntlmsspi.h>
#include <msnssp.h>

#include <htheader.h>
#include <htspmui.h>
#include <htspm.h>
#include <htspmgui.h>
#include "private.h"
#include "sspspm.h"


#endif  // _MSNSPMH_H_
