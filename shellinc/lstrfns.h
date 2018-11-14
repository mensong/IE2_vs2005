#define OFFSET(x) ((PSTR)(LOWORD((DWORD)(x))))

// extern LPWSTR StrChrW(LPWSTR lpStart, WCHAR wMatch);
// extern LPSTR StrChrA(LPSTR lpStart, CHAR wMatch);
// extern LPWSTR StrRChrW(LPWSTR lpStart, LPWSTR lpEnd, WCHAR wMatch);
// extern LPSTR StrRChrA(LPSTR lptart, LPSTR lpEnd, CHAR wMatch);
// extern LPWSTR StrChrIW(LPWSTR lpStart, WCHAR wMatch);
// extern LPSTR StrChrIA(LPSTR lptart, CHAR wMatch);
// extern LPWSTR StrRChrIW(LPWSTR lpStart, LPWSTR lpEnd, WCHAR wMatch);
// extern LPSTR StrRChrIA(LPSTR lptart, LPSTR lpEnd, CHAR wMatch);
// extern INT StrCmpNW(LPWSTR lpWStr1, LPWSTR lpWStr2, INT nChar);
// extern INT StrCmpNA(LPSTR lptr1, LPSTR lpWStr2, INT nChar);
// extern INT StrCmpNIW(LPWSTR lpWStr1, LPWSTR lpWStr2, INT nChar);
// extern INT StrCmpNIA(LPSTR lptr1, LPSTR lpWStr2, INT nChar);
// extern INT StrCpyNW(LPWSTR lpDest, LPWSTR lpSource, INT nBufSize);
// extern INT StrCpyNA(LPSTR lpest, LPSTR lpSource, INT nBufSize);
// extern INT StrNCmpW(LPWSTR lpWStr1, LPWSTR lpWStr2, INT nChar);
// extern INT StrNCmpA(LPSTR lptr1, LPSTR lpWStr2, INT nChar);
// extern INT StrNCmpIW(LPWSTR lpWStr1, LPWSTR lpWStr2, INT nChar);
// extern INT StrNCmpIA(LPSTR lptr1, LPSTR lpWStr2, INT nChar);
// extern INT StrNCpyW(LPWSTR lpDest, LPWSTR lpSource, INT nChar);
// extern INT StrNCpyA(LPSTR lpest, LPSTR lpSource, INT nChar);
// extern LPWSTR StrStrW(LPWSTR lpFirst, LPWSTR lpSrch);
// extern LPSTR StrStrA(LPSTR lpirst, LPSTR lpSrch);
// extern LPWSTR StrRStrW(LPWSTR lpSource, LPWSTR lpLast, LPWSTR lpSrch);
// extern LPSTR StrRStrA(LPSTR lpource, LPSTR lpLast, LPSTR lpSrch);
// extern LPWSTR StrStrIW(LPWSTR lpFirst, LPWSTR lpSrch);
// extern LPSTR StrStrIA(LPSTR lpirst, LPSTR lpSrch);
// extern LPWSTR StrRStrIW(LPWSTR lpSource, LPWSTR lpLast, LPWSTR lpSrch);
//extern LPSTR StrRStrIA(LPSTR lpSource, LPSTR lpLast, LPSTR lpSrch);

// #define LWSTDAPI_(type) type
// 
// LWSTDAPI_(LPSTR)    StrChrA(LPCSTR lpStart, WORD wMatch);
// LWSTDAPI_(LPWSTR)   StrChrW(LPCWSTR lpStart, WCHAR wMatch);
// LWSTDAPI_(LPSTR)    StrChrIA(LPCSTR lpStart, WORD wMatch);
// LWSTDAPI_(LPWSTR)   StrChrIW(LPCWSTR lpStart, WCHAR wMatch);
// LWSTDAPI_(int)      StrCmpNA(LPCSTR lpStr1, LPCSTR lpStr2, int nChar);
// LWSTDAPI_(int)      StrCmpNW(LPCWSTR lpStr1, LPCWSTR lpStr2, int nChar);
// LWSTDAPI_(int)      StrCmpNIA(LPCSTR lpStr1, LPCSTR lpStr2, int nChar);
// LWSTDAPI_(int)      StrCmpNIW(LPCWSTR lpStr1, LPCWSTR lpStr2, int nChar);
// LWSTDAPI_(int)      StrCSpnA(LPCSTR lpStr, LPCSTR lpSet);
// LWSTDAPI_(int)      StrCSpnW(LPCWSTR lpStr, LPCWSTR lpSet);
// LWSTDAPI_(int)      StrCSpnIA(LPCSTR lpStr, LPCSTR lpSet);
// LWSTDAPI_(int)      StrCSpnIW(LPCWSTR lpStr, LPCWSTR lpSet);
// LWSTDAPI_(LPSTR)    StrDupA(LPCSTR lpSrch);
// LWSTDAPI_(LPWSTR)   StrDupW(LPCWSTR lpSrch);
// LWSTDAPI_(LPSTR)    StrFormatByteSizeA(DWORD dw, LPSTR szBuf, UINT uiBufSize);
// LWSTDAPI_(LPSTR)    StrFormatByteSize64A(LONGLONG qdw, LPSTR szBuf, UINT uiBufSize);
// LWSTDAPI_(LPWSTR)   StrFormatByteSizeW(LONGLONG qdw, LPWSTR szBuf, UINT uiBufSize);
// LWSTDAPI_(LPWSTR)   StrFormatKBSizeW(LONGLONG qdw, LPWSTR szBuf, UINT uiBufSize);
// LWSTDAPI_(LPSTR)    StrFormatKBSizeA(LONGLONG qdw, LPSTR szBuf, UINT uiBufSize);
// LWSTDAPI_(int)      StrFromTimeIntervalA(LPSTR pszOut, UINT cchMax, DWORD dwTimeMS, int digits);
// LWSTDAPI_(int)      StrFromTimeIntervalW(LPWSTR pszOut, UINT cchMax, DWORD dwTimeMS, int digits);
// LWSTDAPI_(BOOL)     StrIsIntlEqualA(BOOL fCaseSens, LPCSTR lpString1, LPCSTR lpString2, int nChar);
// LWSTDAPI_(BOOL)     StrIsIntlEqualW(BOOL fCaseSens, LPCWSTR lpString1, LPCWSTR lpString2, int nChar);
// LWSTDAPI_(LPSTR)    StrNCatA(LPSTR psz1, LPCSTR psz2, int cchMax);
// LWSTDAPI_(LPWSTR)   StrNCatW(LPWSTR psz1, LPCWSTR psz2, int cchMax);
// LWSTDAPI_(LPSTR)    StrPBrkA(LPCSTR psz, LPCSTR pszSet);
// LWSTDAPI_(LPWSTR)   StrPBrkW(LPCWSTR psz, LPCWSTR pszSet);
// LWSTDAPI_(LPSTR)    StrRChrA(LPCSTR lpStart, LPCSTR lpEnd, WORD wMatch);
// LWSTDAPI_(LPWSTR)   StrRChrW(LPCWSTR lpStart, LPCWSTR lpEnd, WCHAR wMatch);
// LWSTDAPI_(LPSTR)    StrRChrIA(LPCSTR lpStart, LPCSTR lpEnd, WORD wMatch);
// LWSTDAPI_(LPWSTR)   StrRChrIW(LPCWSTR lpStart, LPCWSTR lpEnd, WCHAR wMatch);
// LWSTDAPI_(LPSTR)    StrRStrIA(LPCSTR lpSource, LPCSTR lpLast, LPCSTR lpSrch);
// LWSTDAPI_(LPWSTR)   StrRStrIW(LPCWSTR lpSource, LPCWSTR lpLast, LPCWSTR lpSrch);
// LWSTDAPI_(int)      StrSpnA(LPCSTR psz, LPCSTR pszSet);
// LWSTDAPI_(int)      StrSpnW(LPCWSTR psz, LPCWSTR pszSet);
// LWSTDAPI_(LPSTR)    StrStrA(LPCSTR lpFirst, LPCSTR lpSrch);
// LWSTDAPI_(LPWSTR)   StrStrW(LPCWSTR lpFirst, LPCWSTR lpSrch);
// LWSTDAPI_(LPSTR)    StrStrIA(LPCSTR lpFirst, LPCSTR lpSrch);
// LWSTDAPI_(LPWSTR)   StrStrIW(LPCWSTR lpFirst, LPCWSTR lpSrch);
// LWSTDAPI_(int)      StrToIntA(LPCSTR lpSrc);
// LWSTDAPI_(int)      StrToIntW(LPCWSTR lpSrc);
// LWSTDAPI_(BOOL)     StrToIntExA(LPCSTR pszString, DWORD dwFlags, int * piRet);
// LWSTDAPI_(BOOL)     StrToIntExW(LPCWSTR pszString, DWORD dwFlags, int * piRet);
// #if (_WIN32_IE >= 0x0600)
// LWSTDAPI_(BOOL)     StrToInt64ExA(LPCSTR pszString, DWORD dwFlags, LONGLONG * pllRet);
// LWSTDAPI_(BOOL)     StrToInt64ExW(LPCWSTR pszString, DWORD dwFlags, LONGLONG * pllRet);
// #endif
// LWSTDAPI_(BOOL)     StrTrimA(LPSTR psz, LPCSTR pszTrimChars);
// LWSTDAPI_(BOOL)     StrTrimW(LPWSTR psz, LPCWSTR pszTrimChars);
// 
// LWSTDAPI_(LPWSTR)   StrCatW(LPWSTR psz1, LPCWSTR psz2);
// LWSTDAPI_(int)      StrCmpW(LPCWSTR psz1, LPCWSTR psz2);
// LWSTDAPI_(int)      StrCmpIW(LPCWSTR psz1, LPCWSTR psz2);
// LWSTDAPI_(LPWSTR)   StrCpyW(LPWSTR psz1, LPCWSTR psz2);
// LWSTDAPI_(LPWSTR)   StrCpyNW(LPWSTR psz1, LPCWSTR psz2, int cchMax);
// 
// LWSTDAPI_(LPWSTR)   StrCatBuffW(LPWSTR pszDest, LPCWSTR pszSrc, int cchDestBuffSize);
// LWSTDAPI_(LPSTR)    StrCatBuffA(LPSTR pszDest, LPCSTR pszSrc, int cchDestBuffSize);
// 
// LWSTDAPI_(BOOL)     ChrCmpIA(WORD w1, WORD w2);
// LWSTDAPI_(BOOL)     ChrCmpIW(WCHAR w1, WCHAR w2);
// 
// #undef LWSTDAPI_

#ifndef UNICODE
#define StrChr StrChrA
#define StrRChr StrRChrA
#define StrChrI StrChrIA
#define StrRChrI StrRChrIA
#define StrCmpN StrCmpNA
#define StrCmpNI StrCmpNIA
#define StrCpyN StrCpyNA
#define StrNCmp StrNCmpA
#define StrNCmpI StrNCmpIA
#define StrNCpy StrNCpyA
#define StrStr StrStrA
#define StrRStr StrRStrA
#define StrStrI StrStrIA
#define StrRStrI StrRStrIA
#else
#define StrChr StrChrW
#define StrRChr StrRChrW
#define StrChrI StrChrIW
#define StrRChrI StrRChrIW
#define StrCmpN StrCmpNW
#define StrCmpNI StrCmpNIW
#define StrCpyN StrCpyNW
#define StrNCmp StrNCmpW
#define StrNCmpI StrNCmpIW
#define StrNCpy StrNCpyW
#define StrStr StrStrW
#define StrRStr StrRStrW
#define StrStrI StrStrIW
#define StrRStrI StrRStrIW
#endif
