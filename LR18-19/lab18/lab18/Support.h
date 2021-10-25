
#pragma once


#if defined(UTILITY_3_0_EXPORTS) 

#define LIBSPEC _declspec(dllexport)

#elif defined(__cplusplus)

#define LIBSPEC extern "C" _declspec(dllimport)

#else

#define LIBSPEC _declspec(dllimport)

#endif


#define EMPTY _T("") 

#define YES _T("y") 

#define NO _T("n") 

#define CR 0x0D 

#define LF 0x0A

#define TSIZE sizeof(TCHAR)




#define TYPE_FILE 1 

#define TYPE_DIR 2

#define TYPE_DOT 3

#define MAX_OPTIONS 20

#define MAX_ARG 1000 

#define MAX_COMMAND_LINE MAX_PATH+50 



#ifdef _UNICODE 

#define _tstrrchr wcsrchr

#else

#define _tstrrchr strrchr

#endif


#ifdef _UNICODE

#define _memtchr wmemchr

#else

#define _memtchr memchr

#endif

#define LUSIZE 1024

#define ACCT_NAME_SIZE LUSIZE
