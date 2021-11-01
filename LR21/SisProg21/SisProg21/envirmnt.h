#pragma once
//#define UNICODE 
#undef UNICODE 
#ifdef UNICODE 
#define _UNICODE 
#endif
#ifndef UNICODE 
#undef _UNICODE 
#endif
//#define _STATICLIB
#define LANG_DFLT LANG_ENGLISH 
#define SUBLANG_DFLT SUBLANG_ENGLISH_US