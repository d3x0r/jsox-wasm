#define JSON_PARSER_MAIN_SOURCE
#define NO_OPEN_MACRO
#define __STATIC__
#define __NO_OPTIONS__
#define __NO_ODBC__
#define NO_FILEOP_ALIAS
#define SACK_BAG_EXPORTS
//#define TYPELIB_SOURCE
#define __NO_INTERFACE_SUPPORT__
#include <stdio.h>
#include <stdarg.h>
/* Includes the system platform as required or appropriate. If
   under a linux system, include appropriate basic linux type
   headers, if under windows pull "windows.h".
   Includes the MOST stuff here ( a full windows.h parse is many
   many lines of code.)                                          */
/* A macro to build a wide character string of __FILE__ */
#define _WIDE__FILE__(n) WIDE(n)
#define WIDE__FILE__ _WIDE__FILE__(__FILE__)
#ifndef STANDARD_HEADERS_INCLUDED
/* multiple inclusion protection symbol */
#define STANDARD_HEADERS_INCLUDED
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#if _MSC_VER
#  ifdef EXCLUDE_SAFEINT_H
#    define _INTSAFE_H_INCLUDED_
#  endif
 //_MSC_VER
#endif
#ifndef WINVER
#  define WINVER 0x0601
#endif
#if !defined(__LINUX__)
#  ifndef STRICT
#    define STRICT
#  endif
#  define WIN32_LEAN_AND_MEAN
// #define NOGDICAPMASKS             // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
// #define NOVIRTUALKEYCODES         // VK_*
// #define NOWINMESSAGES             // WM_*, EM_*, LB_*, CB_*
// #define NOWINSTYLES               // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
// #define NOSYSMETRICS              // SM_*
// #define NOMENUS                   // MF_*
// #define NOICONS                   // IDI_*
// #define NOKEYSTATES               // MK_*
// #define NOSYSCOMMANDS             // SC_*
// #define NORASTEROPS               // Binary and Tertiary raster ops
// #define NOSHOWWINDOW              // SW_*
               // OEM Resource values
#  define OEMRESOURCE
// #define NOATOM                    // Atom Manager routines
#  ifndef _INCLUDE_CLIPBOARD
               // Clipboard routines
#    define NOCLIPBOARD
#  endif
// #define NOCOLOR                   // Screen colors
// #define NOCTLMGR                  // Control and Dialog routines
//(spv) #define NODRAWTEXT                // DrawText() and DT_*
// #define NOGDI                     // All GDI defines and routines
// #define NOKERNEL                  // All KERNEL defines and routines
// #define NOUSER                    // All USER defines and routines
#  ifndef _ARM_
#    ifndef _INCLUDE_NLS
                     // All NLS defines and routines
#      define NONLS
#    endif
#  endif
// #define NOMB                      // MB_* and MessageBox()
                  // GMEM_*, LMEM_*, GHND, LHND, associated routines
#  define NOMEMMGR
                // typedef METAFILEPICT
#  define NOMETAFILE
                  // Macros min(a,b) and max(a,b)
#  define NOMINMAX
// #define NOMSG                     // typedef MSG and associated routines
// #define NOOPENFILE                // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
// #define NOSCROLL                  // SB_* and scrolling routines
                 // All Service Controller routines, SERVICE_ equates, etc.
#  define NOSERVICE
//#define NOSOUND                   // Sound driver routines
#  ifndef _INCLUDE_TEXTMETRIC
              // typedef TEXTMETRIC and associated routines
#    define NOTEXTMETRIC
#  endif
// #define NOWH                      // SetWindowsHook and WH_*
// #define NOWINOFFSETS              // GWL_*, GCL_*, associated routines
// #define NOCOMM                    // COMM driver routines
                   // Kanji support stuff.
#  define NOKANJI
                    // Help engine interface.
#  define NOHELP
                // Profiler interface.
#  define NOPROFILER
//#define NODEFERWINDOWPOS          // DeferWindowPos routines
                     // Modem Configuration Extensions
#  define NOMCX
   // no StrCat StrCmp StrCpy etc functions.  (used internally)
#  define NO_SHLWAPI_STRFCNS
  // This also has defines that override StrCmp StrCpy etc... but no override
#  define STRSAFE_NO_DEPRECATE
#  ifdef _MSC_VER
#    ifndef _WIN32_WINDOWS
// needed at least this for what - updatelayeredwindow?
#      define _WIN32_WINDOWS 0x0601
#    endif
#  endif
// INCLUDE WINDOWS.H
#  ifdef __WATCOMC__
#    undef _WINDOWS_
#  endif
#  ifdef UNDER_CE
// just in case windows.h also fails after undef WIN32
// these will be the correct order for primitives we require.
#    include <excpt.h>
#    include <windef.h>
#    include <winnt.h>
#    include <winbase.h>
#    include <wingdi.h>
#    include <wtypes.h>
#    include <winuser.h>
#    undef WIN32
#  endif
#  define _WINSOCKAPI_
#  include <windows.h>
#  undef _WINSOCKAPI_
#  if defined( WIN32 ) && defined( NEED_SHLOBJ )
#    include <shlobj.h>
#  endif
//#  include <windowsx.h>
// we like timeGetTime() instead of GetTickCount()
//#  include <mmsystem.h>
#ifdef __cplusplus
extern "C"
#endif
__declspec(dllimport) DWORD WINAPI timeGetTime(void);
#  if defined( NEED_SHLAPI )
#    include <shlwapi.h>
#    include <shellapi.h>
#  endif
#  ifdef NEED_V4W
#    include <vfw.h>
#  endif
#  if defined( HAVE_ENVIRONMENT )
#    define getenv(name)       OSALOT_GetEnvironmentVariable(name)
#    define setenv(name,val)   SetEnvironmentVariable(name,val)
#  endif
#  define Relinquish()       Sleep(0)
//#pragma pragnoteonly("GetFunctionAddress is lazy and has no library cleanup - needs to be a lib func")
//#define GetFunctionAddress( lib, proc ) GetProcAddress( LoadLibrary( lib ), (proc) )
#  ifdef __cplusplus_cli
#    include <vcclr.h>
 /*lprintf( */
#    define DebugBreak() System::Console::WriteLine(gcnew System::String( WIDE__FILE__ WIDE("(") STRSYM(__LINE__) WIDE(") Would DebugBreak here...") ) );
//typedef unsigned int HANDLE;
//typedef unsigned int HMODULE;
//typedef unsigned int HWND;
//typedef unsigned int HRC;
//typedef unsigned int HMENU;
//typedef unsigned int HICON;
//typedef unsigned int HINSTANCE;
#  endif
 // ifdef unix/linux
#else
#  include <pthread.h>
#  include <sched.h>
#  include <unistd.h>
#  include <sys/time.h>
#  include <errno.h>
#  if defined( __ARM__ )
#    define DebugBreak()
#  else
/* A symbol used to cause a debugger to break at a certain
   point. Sometimes dynamicly loaded plugins can be hard to set
   the breakpoint in the debugger, so it becomes easier to
   recompile with a breakpoint in the right place.
   Example
   <code lang="c++">
   DebugBreak();
	</code>                                                      */
#    ifdef __ANDROID__
#      define DebugBreak()
#    else
#      ifdef __EMSCRIPTEN__
#        define DebugBreak()
#      else
#        define DebugBreak()  asm("int $3\n" )
#      endif
#    endif
#  endif
#  ifdef __ANDROID_OLD_PLATFORM_SUPPORT__
extern __sighandler_t bsd_signal(int, __sighandler_t);
#  endif
// moved into timers - please linnk vs timers to get Sleep...
//#define Sleep(n) (usleep((n)*1000))
#  define Relinquish() sched_yield()
#  define GetLastError() (int32_t)errno
/* return with a THREAD_ID that is a unique, universally
   identifier for the thread for inter process communication. */
#  define GetCurrentProcessId() ((uint32_t)getpid())
#  define GetCurrentThreadId() ((uint32_t)getpid())
  // end if( !__LINUX__ )
#endif
#ifndef NEED_MIN_MAX
#  ifndef NO_MIN_MAX_MACROS
#    define NO_MIN_MAX_MACROS
#  endif
#endif
#ifndef NO_MIN_MAX_MACROS
#  ifdef __cplusplus
#    ifdef __GNUC__
#      ifndef min
#        define min(a,b) ((a)<(b))?(a):(b)
#      endif
#    endif
#  endif
/* Define a min(a,b) macro when the compiler lacks it. */
#  ifndef min
#    define min(a,b) (((a)<(b))?(a):(b))
#  endif
/* Why not add the max macro, also? */
#  ifndef max
#    define max(a,b) (((a)>(b))?(a):(b))
#  endif
#endif
/* please Include sthdrs.h */
/* Define most of the sack core types on which everything else is
   based. Also defines some of the primitive container
   structures. We also handle a lot of platform/compiler
   abstraction here.
   A reFactoring for stdint.h and uint32_t etc would be USEFUL!
   where types don't exist, define them as apprpritate types instead.
But WHO doesn't have stdint?  BTW is sizeof( size_t ) == sizeof( void* )
   This is automatically included with stdhdrs.h; however, when
   including sack_types.h, the minimal headers are pulled. */
#define HAS_STDINT
//#define USE_SACK_CUSTOM_MEMORY_ALLOCATION
	// this has to be a compile option (option from cmake)
   // enables debug dump mem...
#ifdef USE_SACK_CUSTOM_MEMORY_ALLOCATION
#  define USE_CUSTOM_ALLOCER 1
#else
#  define USE_CUSTOM_ALLOCER 0
#endif
#ifndef __64__
#  if defined( _WIN64 ) || defined( ENVIRONMENT64 ) || defined( __x86_64__ ) || defined( __ia64 ) || defined( __ppc64__ ) || defined( __LP64__ )
#    define __64__ 1
#  endif
#endif
#ifdef _MSC_VER
#  ifndef _WIN32_WINNT
#    define _WIN32_WINNT 0x501
#  endif
#  ifndef WIN32
#    ifdef _WIN32
#      define WIN32 _WIN32
#    endif
#  endif
// force windows on __MSVC
#  ifndef WIN32
#    define WIN32
#  endif
#endif
#if !defined( __NO_THREAD_LOCAL__ ) && ( defined( _MSC_VER ) || defined( __WATCOMC__ ) )
#  define HAS_TLS 1
#  define DeclareThreadLocal static __declspec(thread)
#  define DeclareThreadVar __declspec(thread)
#elif !defined( __NO_THREAD_LOCAL__ ) && ( defined( __GNUC__ ) )
#  define HAS_TLS 1
#  define DeclareThreadLocal static __thread
#  define DeclareThreadVar __thread
#else
#  define DeclareThreadLocal static
#  define DeclareThreadVar
#endif
#ifdef __cplusplus_cli
// these things define a type called 'Byte'
	// which causes confusion... so don't include vcclr for those guys.
#  ifdef SACK_BAG_EXPORTS
// maybe only do this while building sack_bag project itself...
#    if !defined( ZCONF_H )        && !defined( __FT2_BUILD_GENERIC_H__ )        && !defined( ZUTIL_H )        && !defined( SQLITE_PRIVATE )        && !defined( NETSERVICE_SOURCE )        && !defined( LIBRARY_DEF )
//using namespace System;
#    endif
#  endif
#endif
// Defined for building visual studio monolithic build.  These symbols are not relavent with cmakelists.
#ifdef SACK_BAG_EXPORTS
#  define SACK_BAG_CORE_EXPORTS
// exports don't really matter with CLI compilation.
#  ifndef BAG
//#ifndef TARGETNAME
//#  define TARGETNAME "sack_bag.dll"  //$(TargetFileName)
//#endif
#    ifndef __cplusplus_cli
// cli mode, we use this directly, and build the exports in sack_bag.dll directly
#    else
#      define LIBRARY_DEADSTART
#    endif
#define USE_SACK_FILE_IO
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define MEM_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSLOG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define _TYPELIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define HTTP_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define TIMER_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define IDLE_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CLIENTMSG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FRACTION_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define NETWORK_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CONFIGURATION_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FILESYSTEM_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSTEM_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FILEMONITOR_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define VECTOR_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SHA1_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CONSTRUCT_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define PROCREG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SQLPROXY_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define TYPELIB_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define JSON_EMITTER_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SERVICE_SOURCE
#  ifndef __NO_SQL__
#    ifndef __NO_OPTIONS__
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.    and not NO_SQL and not NO_OPTIONS   */
#      define SQLGETOPTION_SOURCE
#    endif
#  endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define PSI_SOURCE
#  ifdef _MSC_VER
#    ifndef JPEG_SOURCE
//wouldn't matter... the external things wouldn't need to define this
//#error projects were not generated with CMAKE, and JPEG_SORUCE needs to be defined
#    endif
//#define JPEG_SOURCE
//#define __PNG_LIBRARY_SOURCE__
//#define FT2_BUILD_LIBRARY   // freetype is internal
//#define FREETYPE_SOURCE		// build Dll Export
#  endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define MNG_BUILD_DLL
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define BAGIMAGE_EXPORTS
/* Defined when SACK_BAG_EXPORTS is defined. This was an
 individual library module once upon a time.           */
#ifndef IMAGE_LIBRARY_SOURCE
#  define IMAGE_LIBRARY_SOURCE
#endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSTRAY_LIBRARAY
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SOURCE_PSI2
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define VIDEO_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
	/* define RENDER SOURCE when building monolithic. */
#     ifndef RENDER_LIBRARY_SOURCE
#       define RENDER_LIBRARY_SOURCE
#     endif
// define a type that is a public name struct type...
// good thing that typedef and struct were split
// during the process of port to /clr option.
//#define PUBLIC_TYPE public
#  else
//#define PUBLIC_TYPE
#    ifdef __cplusplus_CLR
//using namespace System;
#    endif
#  endif
#endif
 // wchar for X_16 definition
#include <wchar.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifndef MY_TYPES_INCLUDED
#define MY_TYPES_INCLUDED
// include this before anything else
// thereby allowing us to redefine exit()
 // CHAR_BIT
#include <limits.h>
 // typelib requires this
#ifdef _MSC_VER
#ifndef UNDER_CE
 // memlib requires this, and it MUST be included befoer string.h if it is used.
#include <intrin.h>
#endif
#endif
 // typelib requires this
#include <string.h>
#if !defined( WIN32 ) && !defined( _WIN32 ) && !defined( _PNACL )
#include <dlfcn.h>
#endif
#if defined( _MSC_VER )
// disable pointer conversion warnings - wish I could disable this
// according to types...
//#pragma warning( disable:4312; disable:4311 )
// disable deprication warnings of snprintf, et al.
//#pragma warning( disable:4996 )
#define EMPTY_STRUCT struct { char nothing[]; }
#endif
#if defined( __WATCOMC__ )
#define EMPTY_STRUCT char
#endif
#ifdef __cplusplus
/* Could also consider defining 'SACK_NAMESPACE' as 'extern "C"
   ' {' and '..._END' as '}'                                    */
#define SACK_NAMESPACE namespace sack {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE namespace containers {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE namespace list {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE namespace data_list {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE namespace sets {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE namespace text {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE SACK_NAMESPACE _CONTAINER_NAMESPACE namespace text {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE_END  } _CONTAINER_NAMESPACE_END SACK_NAMESPACE_END
#else
/* Define the sack namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE
/* Define the sack namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE_END
#endif
/* declare composite SACK_CONTAINER namespace to declare sack::container in a single line */
#define SACK_CONTAINER_NAMESPACE SACK_NAMESPACE _CONTAINER_NAMESPACE
/* declare composite SACK_CONTAINER namespace to close sack::container in a single line */
#define SACK_CONTAINER_NAMESPACE_END _CONTAINER_NAMESPACE_END SACK_NAMESPACE_END
/* declare composite SACK_CONTAINER namespace to declare sack::container::list in a single line */
#define SACK_CONTAINER_LINKLIST_NAMESPACE SACK_CONTAINER_NAMESPACE _LISTLIST_NAMESPACE
/* declare composite SACK_CONTAINER namespace to close sack::container::list in a single line */
#define SACK_CONTAINER_LINKLIST_NAMESPACE_END _LISTLIST_NAMESPACE_END SACK_CONTAINER_NAMESPACE
// this symbols is defined to enforce
// the C Procedure standard - using a stack, and resulting
// in EDX:EAX etc...
#define CPROC
#ifdef SACK_BAG_EXPORTS
# ifdef BUILD_GLUE
// this is used as the export method appropriate for C#?
#  define EXPORT_METHOD [DllImport(LibName)] public
# else
#  ifdef __cplusplus_cli
#   if defined( __STATIC__ ) || defined( __LINUX__ ) || defined( __ANDROID__ )
#     define EXPORT_METHOD
#     define IMPORT_METHOD extern
#   else
#     define EXPORT_METHOD __declspec(dllexport)
#     define IMPORT_METHOD __declspec(dllimport)
#   endif
#   define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#   define LITERAL_LIB_IMPORT_METHOD extern
//__declspec(dllimport)
#  else
#   if defined( __STATIC__ ) || defined( __LINUX__ ) || defined( __ANDROID__ )
#      define EXPORT_METHOD
#      define IMPORT_METHOD extern
#    else
/* Method to declare functions exported from a DLL. (nothign on
   LINUX or building statically, but __declspec(dllimport) on
   windows )                                                    */
#      define EXPORT_METHOD __declspec(dllexport)
/* method to define a function which will be Imported from a
   library. Under windows, this is probably
   __declspec(dllimport). Under linux this is probably 'extern'. */
#      define IMPORT_METHOD __declspec(dllimport)
#    endif
#      define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#      define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
#  endif
# endif
#else
# if ( !defined( __STATIC__ ) && defined( WIN32 ) && !defined( __cplusplus_cli) )
#  define EXPORT_METHOD __declspec(dllexport)
#  define IMPORT_METHOD __declspec(dllimport)
#  define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#  define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
# else
// MRT:  This is needed.  Need to see what may be defined wrong and fix it.
#  if defined( __LINUX__ ) || defined( __STATIC__ )
#    define EXPORT_METHOD
#    define IMPORT_METHOD extern
#    define LITERAL_LIB_EXPORT_METHOD
#    define LITERAL_LIB_IMPORT_METHOD extern
#  else
#    define EXPORT_METHOD __declspec(dllexport)
#    define IMPORT_METHOD __declspec(dllimport)
/* Define how methods in LITERAL_LIBRARIES are exported.
   literal_libraries are libraries that are used for plugins,
   and are dynamically loaded by code. They break the rules of
   system prefix and suffix extensions. LITERAL_LIBRARIES are
   always dynamic, and never static.                           */
#    define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
/* Define how methods in LITERAL_LIBRARIES are imported.
   literal_libraries are libraries that are used for plugins,
   and are dynamically loaded by code. They break the rules of
   system prefix and suffix extensions. LITERAL_LIBRARIES are
   always dynamic, and never static.                           */
#    define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
#  endif
# endif
#endif
// used when the keword specifying a structure is packed
// needs to prefix the struct keyword.
#define PREFIX_PACKED
// private thing left as a note, and forgotten.  some compilers did not define offsetof
#define my_offsetof( ppstruc, member ) ((uintptr_t)&((*ppstruc)->member)) - ((uintptr_t)(*ppstruc))
SACK_NAMESPACE
#ifdef BCC16
#define __inline__
#define MAINPROC(type,name)     type _pascal name
// winproc is intended for use at libmain/wep/winmain...
#define WINPROC(type,name)      type _far _pascal _export name
// callbackproc is for things like timers, dlgprocs, wndprocs...
#define CALLBACKPROC(type,name) type _far _pascal _export name
#define PUBLIC(type,name)       type STDPROC _export name
 /* here would be if dwReason == process_attach */
#define LIBMAIN() WINPROC(int, LibMain)(HINSTANCE hInstance, WORD wDataSeg, WORD wHeapSize, LPSTR lpCmdLine )		 { {
 /* end if */
 /*endproc*/
#define LIBEXIT() } }	    int STDPROC WEP(int nSystemExit )  {
#define LIBMAIN_END()  }
// should use this define for all local defines...
// this will allow one place to modify ALL _pascal or not to _pascal decls.
#define STDPROC _far _pascal
#endif
#if defined( __LCC__ ) || defined( _MSC_VER ) || defined(__DMC__) || defined( __WATCOMC__ )
#ifdef __WATCOMC__
#undef CPROC
#define CPROC __cdecl
#define STDPROC __cdecl
#ifndef __WATCOMC__
// watcom windef.h headers define this
#define STDCALL _stdcall
#endif
#if __WATCOMC__ >= 1280
// watcom windef.h headers no longer define this.
#define STDCALL __stdcall
#endif
#undef PREFIX_PACKED
#define PREFIX_PACKED _Packed
#else
#undef CPROC
//#error blah
#define CPROC __cdecl
#define STDPROC
#define STDCALL _stdcall
#endif
#define far
#define huge
#define near
#define _far
#define _huge
#define _near
/* portability type for porting legacy 16 bit applications. */
/* portability macro for legacy 16 bit applications. */
#define __far
#ifndef FAR
#define FAR
#endif
//#define HUGE
//#ifndef NEAR
//#define NEAR
//#endif
#define _fastcall
#ifdef __cplusplus
#ifdef __cplusplus_cli
#define PUBLIC(type,name) extern "C"  LITERAL_LIB_EXPORT_METHOD type CPROC name
#else
//#error what the hell!?
// okay Public functions are meant to be loaded with LoadFuncion( "library" , "function name"  );
#define PUBLIC(type,name) extern "C"  LITERAL_LIB_EXPORT_METHOD type CPROC name
#endif
#else
#define PUBLIC(type,name) LITERAL_LIB_EXPORT_METHOD type CPROC name
#endif
#define MAINPROC(type,name)  type WINAPI name
#define WINPROC(type,name)   type WINAPI name
#define CALLBACKPROC(type,name) type CALLBACK name
#if defined( __WATCOMC__ )
#define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(_WIDE(TARGETNAME)) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#define LIBMAIN_END() }
#else
#ifdef TARGETNAME
#define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(_WIDE(TARGETNAME)) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#else
#define LIBMAIN()   TARGETNAME_NOT_DEFINED
#endif
#define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#define LIBMAIN_END() }
#endif
#define PACKED
#endif
#if defined( __GNUC__ )
#  ifndef STDPROC
#    define STDPROC
#  endif
#  ifndef STDCALL
 // for IsBadCodePtr which isn't a linux function...
#    define STDCALL
#  endif
#  ifndef WINAPI
#    ifdef __LINUX__
#       define WINAPI
#    else
#       define WINAPI __stdcall
#    endif
#  endif
#  ifndef PASCAL
//#define PASCAL
#  endif
#  define WINPROC(type,name)   type WINAPI name
#  define CALLBACKPROC( type, name ) type name
#  define PUBLIC(type,name) EXPORT_METHOD type CPROC name
#  define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(TARGETNAME) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#  define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#  define LIBMAIN_END()  }
/* Portability Macro for porting legacy code forward. */
#  define FAR
#  define NEAR
//#define HUGE
#  define far
#  define near
#  define huge
#  define PACKED __attribute__((packed))
#endif
#if defined( BCC32 )
#define far
#define huge
/* define obsolete keyword for porting purposes */
/* defined for porting from 16 bit environments */
#define near
/* portability macro for legacy 16 bit applications. */
#define _far
#define _huge
#define _near
/* portability type for porting to compilers that don't inline. */
/* portability macro for legacy 16 bit applications. */
#define __inline__
#define MAINPROC(type,name)     type _pascal name
// winproc is intended for use at libmain/wep/winmain...
#define WINPROC(type,name)      EXPORT_METHOD type _pascal name
// callbackproc is for things like timers, dlgprocs, wndprocs...
#define CALLBACKPROC(type,name) EXPORT_METHOD type _stdcall name
#define STDCALL _stdcall
#define PUBLIC(type,name)        type STDPROC name
#ifdef __STATIC__
			/*Log( WIDE("Library Enter" ) );*/
#define LIBMAIN() static WINPROC(int, LibMain)(HINSTANCE hInstance, DWORD dwReason, void *unused )		 { if( dwReason == DLL_PROCESS_ATTACH ) {
 /* end if */
#define LIBEXIT() } if( dwReason == DLL_PROCESS_DETACH ) {
#define LIBMAIN_END()  } return 1; }
#else
			/*Log( WIDE("Library Enter" ) );*/
#define LIBMAIN() WINPROC(int, LibMain)(HINSTANCE hInstance, DWORD dwReason, void *unused )		 { if( dwReason == DLL_PROCESS_ATTACH ) {
 /* end if */
#define LIBEXIT() } if( dwReason == DLL_PROCESS_DETACH ) {
#define LIBMAIN_END()  } return 1; }
#endif
// should use this define for all local defines...
// this will allow one place to modify ALL _pascal or not to _pascal decls.
#define STDPROC _pascal
#define PACKED
#endif
#define TOCHR(n) #n[0]
#define TOSTR(n) WIDE(#n)
#define STRSYM(n) TOSTR(n)
#define _WIDE__FILE__(n) WIDE(n)
#define WIDE__FILE__ _WIDE__FILE__(__FILE__)
/* a constant text string that represents the current source
   filename and line... fourmated as "source.c(11) :"        */
#define FILELINE  TEXT(__FILE__) WIDE("(" ) TEXT(STRSYM(__LINE__))WIDE(" : " ))
#if defined( _MSC_VER ) || defined( __PPCCPP__ )
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnote(msg) message( FILELINE msg )
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnoteonly(msg) message( msg )
#else
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnote(msg) msg
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnoteonly(msg) msg
#endif
/* specify a consistant macro to pass current file and line information.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_SRC         , (CTEXTSTR)_WIDE(__FILE__), __LINE__
/* specify a consistant macro to pass current file and line information, to functions which void param lists.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDSRC     (CTEXTSTR)_WIDE(__FILE__), __LINE__
//#define FILELINE_LEADSRC     (CTEXTSTR)_WIDE(__FILE__), __LINE__,
/* specify a consistant macro to define file and line parameters, to functions with otherwise void param lists.  This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDPASS    CTEXTSTR pFile, uint32_t nLine
//#define FILELINE_LEADPASS    CTEXTSTR pFile, uint32_t nLine,
/* specify a consistant macro to define file and line parameters.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_PASS        , CTEXTSTR pFile, uint32_t nLine
/* specify a consistant macro to forward file and line parameters.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_RELAY       , pFile, nLine
/* specify a consistant macro to forward file and line parameters, to functions which have void parameter lists without this information.  This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDRELAY   pFile, nLine
/* specify a consistant macro to format file and line information for printf formated strings. */
#define FILELINE_FILELINEFMT WIDE("%s(%") _32f WIDE("): ")
#define FILELINE_FILELINEFMT_MIN WIDE("%s(%") _32f WIDE(")")
#define FILELINE_NULL        , NULL, 0
#define FILELINE_VOIDNULL    NULL, 0
/* define static parameters which are the declaration's current file and line, for stubbing in where debugging is being stripped.
  usage
    FILELINE_VARSRC: // declare pFile and nLine variables.
	*/
#define FILELINE_VARSRC       CTEXTSTR pFile = _WIDE(__FILE__); uint32_t nLine = __LINE__
// this is for passing FILE, LINE information to allocate
// useful during DEBUG phases only...
// drop out these debug relay paramters for managed code...
// we're going to have the full call frame managed and known...
#if !defined( _DEBUG ) && !defined( _DEBUG_INFO )
#  if defined( __LINUX__ ) && !defined( __PPCCPP__ )
//#warning "Setting DBG_PASS and DBG_FORWARD to be ignored."
#  else
//#pragma pragnoteonly("Setting DBG_PASS and DBG_FORWARD to be ignored"  )
#  endif
#define DBG_AVAILABLE   0
/* in NDEBUG mode, pass nothing */
#define DBG_SRC
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_VOIDSRC
/* <combine sack::DBG_PASS>
   \#define DBG_LEADSRC in NDEBUG mode, declare (void) */
/* <combine sack::DBG_PASS>
   \ \                      */
#define DBG_VOIDPASS    void
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_PASS
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_RELAY
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_VOIDRELAY
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_FILELINEFMT
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_FILELINEFMT_MIN
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing
   Example
   printf( DBG_FILELINEFMT ": extra message" DBG_PASS ); */
#define DBG_VARSRC
#else
	// these DBG_ formats are commented out from duplication in sharemem.h
#  if defined( __LINUX__ ) && !defined( __PPCCPP__ )
//#warning "Setting DBG_PASS and DBG_FORWARD to work."
#  else
//#pragma pragnoteonly("Setting DBG_PASS and DBG_FORWARD to work"  )
#  endif
// used to specify whether debug information is being passed - can be referenced in compiled code
#define DBG_AVAILABLE   1
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_SRC */
#define DBG_SRC         FILELINE_SRC
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDSRC */
#define DBG_VOIDSRC     FILELINE_VOIDSRC
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDPASS */
#define DBG_VOIDPASS    FILELINE_VOIDPASS
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
/* Example
   This example shows forwarding debug information through a
   chain of routines.
   <code lang="c++">
   void ReportFunction( int sum DBG_PASS )
   {
       printf( "%s(%d):started this whole mess\\n" DBG_RELAY );
   }
   void TrackingFunction( int a, int b DBG_PASS )
   {
       ReportFunction( a+b, DBG_RELAY );
   }
   void CallTrack( void )
   {
       TrackingFunction( 1, 2 DBG_SRC );
   }
   </code>
   In this example, the debug information is passed to the
   logging system. This allows logging to blame the user
   application for allocations, releases, locks, etc...
   <code lang="c++">
   void MyAlloc( int size DBG_PASS )
   {
       _lprintf( DBG_RELAY )( ": alloc %d\\n", size );
   }
   void g( void )
   {
       lprintf( "Will Allocate %d\\n", 32 );
       MyAlloc( 32 DBG_SRC );
   }
   </code>
   This example uses the void argument macros
   <code>
   void SimpleFunction( DBG_VOIDPASS )
   {
       // this function usually has (void) parameters.
   }
   void f( void )
   {
       SimpleFunction( DBG_VOIDSRC );
   }
   </code>
   Description
   in NDEBUG mode, pass nothing.
   This function allows specification of DBG_RELAY or DBG_SRC
   under debug compilation. Otherwise, the simple AddLink macro
   should be used. DBG_RELAY can be used to forward file and
   line information which has been passed via DBG_PASS
   declaration in the function parameters.
   This is a part of a set of macros which allow additional
   logging information to be passed.
   These 3 are the most commonly used.
   DBG_SRC - this passes the current __FILE__, __LINE__
   \parameters.
   DBG_PASS - this is used on a function declaration, is a
   filename and line number from DBG_SRC or DBG_RELAY.
   DBG_RELAY - this passes the file and line passed to this
   function to another function with DBG_PASS defined on it.
   DBG_VOIDPASS - used when the argument list is ( void )
   without debugging information.
   DBG_VOIDSRC - used to call a function who's argument list is
   ( void ) without debugging information.
   DBG_VOIDRELAY - pass file and line information forward to
   another function, who's argument list is ( void ) without
   debugging information.
   Remarks
   The SACK library is highly instrumented with this sort of
   information. Very commonly the only difference between a
   specific function called 'MyFunctionName' and
   'MyFunctionNameEx' is the addition of debug information
   tracking.
   The following code blocks show the evolution added to add
   instrumentation...
   <code lang="c++">
   int MyFunction( int param )
   {
       // do stuff
   }
   int CallingFunction( void )
   {
       return MyFunction();
   }
   </code>
   Pretty simple code, a function that takes a parameter, and a
   function that calls it.
   The first thing is to extend the called function.
   <code>
   int MyFunctionEx( int param DBG_PASS )
   {
       // do stuff
   }
   </code>
   And provide a macro for everyone else calling the function to
   automatically pass their file and line information
   <code lang="c++">
   \#define MyFunction(param)  MyFunctionEx(param DBG_SRC)
   </code>
   Then all-together
   <code>
   \#define MyFunction(param)  MyFunctionEx(param DBG_SRC)
   int MyFunctionEx( int param DBG_PASS )
   {
       // do stuff
   }
   int CallingFunction( void )
   {
       // and this person calling doesn't matter
       // does require a recompile of source.
       return MyFunction( 3 );
   }
   </code>
   But then... what if CallingFunction decided wasn't really the
   one at fault, or responsible for the allocation, or other
   issue being tracked, then she could be extended....
   <code>
   int CallingFunctionEx( DBG_VOIDPASS )
   \#define CallingFunction() CallingFunction( DBG_VOIDSRC )
   {
       // and this person calling doesn't matter
       // does require a recompile of source.
       return MyFunction( 1 DBG_RELAY );
   }
   </code>
   Now, calling function will pass it's callers information to
   MyFunction....
   Why?
   Now, when you call CreateList, your code callng the list
   creation method is marked as the one who allocates the space.
   Or on a DeleteList, rather than some internal library code
   being blamed, the actual culprit can be tracked and
   identified, because it's surely not the fault of CreateList
   that the reference to the memory for the list wasn't managed
   correctly.
   Note
   It is important to note, every usage of these macros does not
   have a ',' before them. This allows non-debug code to
   eliminate these extra parameters cleanly. If the ',' was
   outside of the macro, then it would remain on the line, and
   an extra parameter would have be be passed that was unused.
   This is also why DBG_VOIDPASS exists, because in release mode
   this is substituted with 'void'.
   In Release mode, DBG_VOIDRELAY becomes nothing, but when in
   debug mode, DBG_RELAY has a ',' in the macro, so without a
   paramter f( DBG_RELAY ) would fail; on expansion this would
   be f( , pFile, nLine ); (note the extra comma, with no
   parameter would be a syntax error.                            */
#define DBG_PASS        FILELINE_PASS
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_RELAY */
#define DBG_RELAY       FILELINE_RELAY
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDRELAY */
#define DBG_VOIDRELAY   FILELINE_VOIDRELAY
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_FILELINEFMT */
#define DBG_FILELINEFMT FILELINE_FILELINEFMT
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_FILELINEFMT_MIN */
#define DBG_FILELINEFMT_MIN FILELINE_FILELINEFMT_MIN
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VARSRC */
#define DBG_VARSRC      FILELINE_VARSRC
#endif
// cannot declare _0 since that overloads the
// vector library definition for origin (0,0,0,0,...)
//typedef void             _0; // totally unusable to declare 0 size things.
/* the only type other than when used in a function declaration that void is valid is as a pointer to void. no _0 type exists (it does, but it's in vectlib, and is an origin vector)*/
typedef void             *P_0;
/*
 * several compilers are rather picky about the types of data
 * used for bit field declaration, therefore this type
 * should be used instead of uint32_t (DWORD)
 */
typedef unsigned int  BIT_FIELD;
// have to do this on a per structure basis - otherwise
// any included headers with structures to use will get FUCKED
#ifndef PACKED
#define PACKED
#endif
/* An pointer to a volatile unsigned integer type that is 64 bits long. */
//typedef volatile uint64_t  *volatile int64_t*;
/* An pointer to a volatile pointer size type that is as long as a pointer. */
typedef volatile uintptr_t        *PVPTRSZVAL;
/* an unsigned type meant to index arrays.  (By convention, arrays are not indexed negatively.)  An index which is not valid is INVALID_INDEX, which equates to 0xFFFFFFFFUL or negative one cast as an INDEX... ((INDEX)-1). */
typedef size_t         INDEX;
/* An index which is not valid; equates to 0xFFFFFFFFUL or negative one cast as an INDEX... ((INDEX)-1). */
#define INVALID_INDEX ((INDEX)-1)
#ifdef __CYGWIN__
typedef unsigned short wchar_t;
#endif
// may consider changing this to uint16_t* for unicode...
typedef wchar_t X_16;
/* This is a pointer to wchar_t. A 16 bit value that is
   character data, and is not signed or unsigned.       */
typedef wchar_t *PX_16;
#if defined( UNICODE ) || defined( SACK_COM_OBJECT )
//should also consider revisiting code that was updated for TEXTCHAR to char conversion methods...
#  ifdef _MSC_VER
#    ifdef UNDER_CE
#      define NULTERM
#    else
#      define NULTERM __nullterminated
#    endif
#  else
#    define NULTERM
#  endif
#define WIDE(s)  L##s
#define _WIDE(s)  WIDE(s)
#define cWIDE(s)  s
#define _cWIDE(s)  cWIDE(s)
 // constant text string content
typedef NULTERM          const X_16      *CTEXTSTR;
 // pointer to constant text string content
typedef NULTERM          CTEXTSTR        *PCTEXTSTR;
typedef NULTERM          X_16            *TEXTSTR;
/* a text 16 bit character  */
typedef X_16             TEXTCHAR;
#else
#define WIDE(s)   s
#define _WIDE(s)  s
#define cWIDE(s)   s
/* Modified WIDE wrapper that actually forces non-unicode
   string.                                                */
#define _cWIDE(s)  s
// constant text string content
typedef const char     *CTEXTSTR;
/* A non constant array of TEXTCHAR. A pointer to TEXTCHAR. A
   pointer to non-constant characters. (A non-static string
   probably)                                                  */
typedef char           *TEXTSTR;
#if defined( __LINUX__ ) && defined( __cplusplus )
// pointer to constant text string content
typedef TEXTSTR const  *PCTEXTSTR;
#else
// char const *const *
typedef CTEXTSTR const *PCTEXTSTR;
#endif
/* a text 8 bit character  */
typedef char            TEXTCHAR;
#endif
/* a character rune.  Strings should be interpreted as UTF-8 or 16 depending on UNICODE compile option.
   GetUtfChar() from strings.  */
typedef uint32_t             TEXTRUNE;
/* Used to handle returned values that are invalid runes; past end or beginning of string for instance */
#define INVALID_RUNE  0x80000000
//typedef enum { FALSE, TRUE } LOGICAL; // smallest information
#ifndef FALSE
#define FALSE 0
/* Define TRUE when not previously defined in the platform. TRUE
   is (!FALSE) so anything not 0 is true.                        */
#define TRUE (!FALSE)
#endif
/* Meant to hold boolean and only boolean values. Should be
   implemented per-platform as appropriate for the bool type the
   compiler provides.                                            */
typedef uint32_t LOGICAL;
/* This is a pointer. It is a void*. It is meant to point to a
   single thing, and cannot be used to reference arrays of bytes
   without recasting.                                            */
typedef P_0 POINTER;
/* This is a pointer to constant data. void const *. Compatible
   with things like char const *.                               */
typedef const void *CPOINTER;
SACK_NAMESPACE_END
//------------------------------------------------------
// formatting macro defintions for [vsf]printf output of the above types
#if !defined( _MSC_VER ) || ( _MSC_VER >= 1900 )
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#endif
SACK_NAMESPACE
/* 16 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16f   WIDE("u" )
/* 16 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16fx   WIDE("x" )
/* 16 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16fX   WIDE("X" )
/* 16 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\>               */
#define _16fs   WIDE("d" )
/* 8 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8f   WIDE("u" )
/* 8 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8fx   WIDE("x" )
/* 8 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8fX   WIDE("X" )
/* 8 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\>               */
#define _8fs   WIDE("d" )
#if defined( __STDC_FORMAT_MACROS )
#  define _32f   _WIDE( PRIu32 )
#  define _32fx   _WIDE( PRIx32 )
#  define _32fX   _WIDE( PRIX32 )
#  define _32fs   _WIDE( PRId32 )
#  define _64f    _WIDE(PRIu64)
#  define _64fx   _WIDE(PRIx64)
#  define _64fX   _WIDE(PRIX64)
#  define _64fs   _WIDE(PRId64)
#  define _64f    _WIDE(PRIu64)
#  define _64fx   _WIDE(PRIx64)
#  define _64fX   _WIDE(PRIX64)
#  define _64fs   _WIDE(PRId64)
// non-unicode strings
#  define c_32f    PRIu32
#  define c_32fx   PRIx32
#  define c_32fX   PRIX32
#  define c_32fs   PRId32
#  define c_64f    PRIu64
#  define c_64fx   PRIx64
#  define c_64fX   PRIX64
#  define c_64fs   PRId64
#else
#  define _32f   WIDE("u" )
#  define _32fx   WIDE("x" )
#  define _32fX   WIDE("X" )
#  define _32fs   WIDE("d" )
#  define c_32f   "u"
#  define c_32fx  "x"
#  define c_32fX  "X"
#  define c_32fs  "d"
#  define c_64f    "llu"
#  define c_64fx   "llx"
#  define c_64fX   "llX"
#  define c_64fs   "lld"
#endif
#if defined( UNICODE )
#  define _cstring_f WIDE("s")
#  define _string_f WIDE("S")
#  define _ustring_f WIDE("S")
#else
#  define _cstring_f WIDE("s")
#  define _string_f WIDE("s")
#  define _ustring_f WIDE("S")
#endif
#if defined( __64__ )
#  if defined( __STDC_FORMAT_MACROS )
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _WIDE( PRIu64 )
#      define _size_fx   _WIDE( PRIx64 )
#      define _size_fX   _WIDE( PRIX64 )
#      define _size_fs   _WIDE( PRId64 )
#      define c_size_f    PRIu64
#      define c_size_fx   PRIx64
#      define c_size_fX   PRIX64
#      define c_size_fs   PRId64
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  else
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _64f
#      define _size_fx   _64fx
#      define _size_fX   _64fX
#      define _size_fs   _64fs
#      define c_size_f   c_64f
#      define c_size_fx  c_64fx
#      define c_size_fX  c_64fX
#      define c_size_fs  c_64fs
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  endif
#else
#  if defined( __STDC_FORMAT_MACROS )
      // this HAS been fixed in UCRT - 2015!  but it'll take 5 years before everyone has that...
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _WIDE( PRIu32 )
#      define _size_fx   _WIDE( PRIx32 )
#      define _size_fX   _WIDE( PRIX32 )
#      define _size_fs   _WIDE( PRId32 )
#      define c_size_f    PRIu32
#      define c_size_fx   PRIx32
#      define c_size_fX   PRIX32
#      define c_size_fs   PRId32
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  else
      // this HAS been fixed in UCRT - 2015!  but it'll take 5 years before everyone has that...
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _32f
#      define _size_fx   _32fx
#      define _size_fX   _32fX
#      define _size_fs   _32fs
#      define c_size_f    c_32f
#      define c_size_fx   c_32fx
#      define c_size_fX   c_32fX
#      define c_size_fs   c_32fs
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  endif
#endif
#define PTRSZVALf WIDE("p" )
#define _PTRSZVALf WIDE("p" )
#if defined( _MSC_VER ) && ( _MSC_VER < 1900 )
/* 64 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIu64              */
#define _64f    WIDE("llu")
/* 64 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIxFAST64                */
#define _64fx   WIDE("llx")
/* 64 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIxFAST64                */
#define _64fX   WIDE("llX")
/* 64 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\> as PRIdFAST64               */
#define _64fs   WIDE("lld")
#endif
// This should be for several years a
// sufficiently large type to represent
// threads and processes.
typedef uint64_t THREAD_ID;
#define GetMyThreadIDNL GetMyThreadID
#if defined( _WIN32 ) || defined( __CYGWIN__ )
#define _GetMyThreadID()  ( (( ((uint64_t)GetCurrentProcessId()) << 32 ) | ( (uint64_t)GetCurrentThreadId() ) ) )
#define GetMyThreadID()  (GetThisThreadID())
#else
// this is now always the case
// it's a safer solution anyhow...
#ifndef GETPID_RETURNS_PPID
#define GETPID_RETURNS_PPID
#endif
#ifdef GETPID_RETURNS_PPID
#ifdef __ANDROID__
#define GetMyThreadID()  (( ((uint64_t)getpid()) << 32 ) | ( (uint64_t)(gettid()) ) )
#else
#define GetMyThreadID()  (( ((uint64_t)getpid()) << 32 ) | ( (uint64_t)(pthread_self()) ) )
#endif
#else
#define GetMyThreadID()  (( ((uint64_t)getppid()) << 32 ) | ( (uint64_t)(getpid()|0x40000000)) )
#endif
#define _GetMyThreadID GetMyThreadID
#endif
//#error blah
// general macros for linking lists using
#define DeclareLink( type )  type *next;type **me
#define RelinkThing( root, node )	   ((( node->me && ( (*node->me)=node->next ) )?	  node->next->me = node->me:0),(node->next = NULL),(node->me = NULL),node),	 ((( node->next = root )?	        (root->me = &node->next):0),	  (node->me = &root),	             (root = node) )
/* Link a new node into the list.
   Example
   struct mynode
   {
   DeclareLink( struct mynode );
   } *node;
   struct mynode *list;
   LinkThing( list_root, node );  */
#define LinkThing( root, node )		     ((( (node)->next = (root) )?	        (((root)->me) = &((node)->next)):0),	  (((node)->me) = &(root)),	             ((root) = (node)) )
/* Link a node to the end of a list. Link thing inserts the new
   node as the new head of the list.                            */
#define LinkLast( root, type, node ) if( node ) do { if( !root )	 { root = node; (node)->me=&root; }	 else { type tmp;	 for( tmp = root; tmp->next; tmp = tmp->next );	 tmp->next = (node);	 (node)->me = &tmp->next;	 } } while (0)
// put 'Thing' after 'node'
#define LinkThingAfter( node, thing )	 ( ( (thing)&&(node))	   ?(((((thing)->next = (node)->next))?((node)->next->me = &(thing)->next):0)	  ,((thing)->me = &(node)->next), ((node)->next = thing))	  :((node)=(thing)) )
//
// put 'Thing' before 'node'... so (*node->me) = thing
#define LinkThingBefore( node, thing )	 {  thing->next = (*node->me);	(*node->me) = thing;    thing->me = node->me;       node->me = &thing->next;     }
/* Remove a node from a list. Requires only the node. */
#define UnlinkThing( node )	                      ((( (node) && (node)->me && ( (*(node)->me)=(node)->next ) )?	  (node)->next->me = (node)->me:0),((node)->next = NULL),((node)->me = NULL),(node))
// this has two expressions duplicated...
// but in being so safe in this expression,
// the self-circular link needs to be duplicated.
// GrabThing is used for nodes which are circularly bound
#define GrabThing( node )	    ((node)?(((node)->me)?(((*(node)->me)=(node)->next)?	 ((node)->next->me=(node)->me),((node)->me=&(node)->next):NULL):((node)->me=&(node)->next)):NULL)
/* Go to the next node with links declared by DeclareLink */
#define NextLink(node) ((node)?(node)->next:NULL)
// everything else is called a thing... should probably migrate to using this...
#define NextThing(node) ((node)?(node)->next:NULL)
//#ifndef FALSE
//#define FALSE 0
//#endif
//#ifndef TRUE
//#define TRUE (!FALSE)
//#endif
/* the default type to use for flag sets - flag sets are arrays of bits which can be toggled on and off by an index. */
#define FLAGSETTYPE uint32_t
/* the number of bits a specific type is.
   Example
   int bit_size_int = FLAGTYPEBITS( int ); */
#define FLAGTYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* how many bits to add to make sure we round to the next greater index if even 1 bit overflows */
#define FLAGROUND(t) (FLAGTYPEBITS(t)-1)
/* the index of the FLAGSETTYPE which contains the bit in question */
#define FLAGTYPE_INDEX(t,n)  (((n)+FLAGROUND(t))/FLAGTYPEBITS(t))
/* how big the flag set is in count of FLAGSETTYPEs required in a row ( size of the array of FLAGSETTYPE that contains n bits) */
#define FLAGSETSIZE(t,n) (FLAGTYPE_INDEX(t,n) * sizeof( FLAGSETTYPE ) )
// declare a set of flags...
#define FLAGSET(v,n)   FLAGSETTYPE (v)[((n)+FLAGROUND(FLAGSETTYPE))/FLAGTYPEBITS(FLAGSETTYPE)]
// set a single flag index
#define SETFLAG(v,n)   ( (v)[(n)/FLAGTYPEBITS((v)[0])] |= 1 << ( (n) & FLAGROUND((v)[0]) ))
// clear a single flag index
#define RESETFLAG(v,n) ( (v)[(n)/FLAGTYPEBITS((v)[0])] &= ~( 1 << ( (n) & FLAGROUND((v)[0]) ) ) )
// test if a flags is set
#define TESTFLAG(v,n)  ( (v)[(n)/FLAGTYPEBITS((v)[0])] & ( 1 << ( (n) & FLAGROUND((v)[0]) ) ) )
// reverse a flag from 1 to 0 and vice versa
#define TOGGLEFLAG(v,n)   ( (v)[(n)/FLAGTYPEBITS((v)[0])] ^= 1 << ( (n) & FLAGROUND((v)[0]) ))
// 32 bits max for range on mask
#define MASK_MAX_LENGTH 32
// gives a 32 bit mask possible from flagset..
#define MASKSET_READTYPE uint32_t
// gives byte index...
#define MASKSETTYPE uint8_t
/* how many bits the type specified can hold
   Parameters
   t :  data type to measure (int, uint32_t, ... ) */
#define MASKTYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* the maximum number of bits storable in a type */
#define MASK_MAX_TYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* round up to the next count of types that fits 1 bit - used as a cieling round factor */
#define MASKROUND(t) (MASKTYPEBITS(t)-1)
/* define MAX_MAX_ROUND factor based on MASKSET_READTYPE - how to read it... */
#define MASK_MAX_ROUND() (MASK_MAX_TYPEBITS(MASKSET_READTYPE)-1)
/* byte index of the start of the mask
   Parameters
   t :  type to measure with
   n :  mask index                     */
#define MASKTYPE_INDEX(t,n)  (((n)+MASKROUND(t))/MASKTYPEBITS(t))
/* The number of bytes the set would be.
   Parameters
   t :  the given type to measure with
   n :  the count of masks to fit.       */
#define MASKSETSIZE(t,n) (MASKTYPE_INDEX(t,(n+1)))
// declare a set of flags...
#define MASK_TOP_MASK_VAL(length,val) ((val)&( (0xFFFFFFFFUL) >> (32-(length)) ))
/* the mask in the dword resulting from shift-right.   (gets a mask of X bits in length) */
#define MASK_TOP_MASK(length) ( (0xFFFFFFFFUL) >> (32-(length)) )
/* the mast in the dword shifted to the left to overlap the field in the word */
#define MASK_MASK(n,length)   (MASK_TOP_MASK(length) << (((n)*(length))&0x7) )
// masks value with the mask size, then applies that mask back to the correct word indexing
#define MASK_MASK_VAL(n,length,val)   (MASK_TOP_MASK_VAL(length,val) << (((n)*(length))&0x7) )
/* declare a mask set. */
#define MASKSET(v,n,r)  MASKSETTYPE  (v)[(((n)*(r))+MASK_MAX_ROUND())/MASKTYPEBITS(MASKSETTYPE)]; const int v##_mask_size = r;
// set a field index to a value
#define SETMASK(v,n,val)    (((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS((v)[0])))[0] =    ( ((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS(uint8_t)))[0]                                  & (~(MASK_MASK(n,v##_mask_size))) )	                                                                           | MASK_MASK_VAL(n,v##_mask_size,val) )
// get the value of a field
#define GETMASK(v,n)  ( ( ((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS((v)[0])))[0]                                  & MASK_MASK(n,v##_mask_size) )	                                                                           >> (((n)*(v##_mask_size))&0x7))
/* This type stores data, it has a self-contained length in
   bytes of the data stored.  Length is in characters       */
_CONTAINER_NAMESPACE
#define DECLDATA(name,length) struct {size_t size; TEXTCHAR data[length];} name
// Hmm - this can be done with MemLib alone...
// although this library is not nessecarily part of that?
// and it's not nessecarily allocated.
typedef struct SimpleDataBlock {
   size_t size;
/* unsigned size; size is sometimes a pointer value... this
                    means bad thing when we change platforms... Defined as
                    uintptr_t now, so it's relative to the size of the platform
                    anyhow.                                                    */
#ifdef _MSC_VER
#pragma warning (disable:4200)
#endif
   uint8_t  data[
#ifndef __cplusplus
   1
#endif
 // beginning of var data - this is created size+sizeof(uint8_t)
   ];
#ifdef _MSC_VER
#pragma warning (default:4200)
#endif
} DATA, *PDATA;
/* This is a slab array of pointers, each pointer may be
   assigned to point to any user data.
   Remarks
   When the list is filled to the capacity of Cnt elements, the
   list is reallocated to be larger.
   Cannot add NULL pointer to list, empty elements in the list
   are represented with NULL, and may be filled by any non-NULL
   value.                                                       */
_LINKLIST_NAMESPACE
/* <combine sack::containers::list::LinkBlock>
   \ \                                         */
typedef struct LinkBlock
{
	/* How many pointers the list can contain now. */
	INDEX     Cnt;
	/* \ \  */
	POINTER pNode[1];
} LIST, *PLIST;
_LINKLIST_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::containers::list;
#endif
_DATALIST_NAMESPACE
/* a list of data structures... a slab array of N members of X size */
typedef struct DataBlock  DATALIST;
/* A typedef of a pointer to a DATALIST struct DataList. */
typedef struct DataBlock *PDATALIST;
/* Data Blocks are like LinkBlocks, and store blocks of data in
   slab format. If the count of elements exceeds available, the
   structure is grown, to always contain a continuous array of
   structures of Size size.
   Remarks
   When blocks are deleted, all subsequent blocks are shifted
   down in the array. So the free blocks are always at the end. */
struct DataBlock
{
	/* How many elements are used. */
	INDEX     Cnt;
	/* How many elements are available in his array. */
	INDEX     Avail;
	/* A simple exchange lock on the data for insert and delete. For
	   thread safety.                                                */
	//volatile uint32_t     Lock;
	/* How big each element of the array is. */
	INDEX     Size;
	/* The physical array. */
	uint8_t      data[1];
};
_DATALIST_NAMESPACE_END
/* This is a stack that contains pointers to user objects.
   Remarks
   This is a stack 'by reference'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct LinkStack
{
	/* This is the index of the next pointer to be pushed or popped.
	   If top == 0, the stack is empty, until a pointer is added and
	   top is incremented.                                           */
	INDEX     Top;
	/* How many pointers the stack can contain. */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore. For
	                  thread safety.                                            */
	//volatile uint32_t     Lock;
	/*  a defined maximum capacity of stacked values... values beyond this are lost from the bottom  */
	uint32_t     Max;
	/* Reserved data portion that stores the pointers. */
	POINTER pNode[1];
} LINKSTACK, *PLINKSTACK;
/* A Stack that stores information in an array of structures of
   known size.
   Remarks
   The size of each element must be known at stack creation
   time. Structures are literally copied to and from this stack.
   This is a stack 'by value'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct DataListStack
{
	volatile INDEX     Top;
 /* enable logging the program executable (probably the same for
	                all messages, unless they are network)
	                                                                             */
 // How many elements are on the stack.
	INDEX     Cnt;
	//volatile uint32_t     Lock;  /* thread interlock using InterlockedExchange semaphore. For
	//                  thread safety.                                            */
	INDEX     Size;
	INDEX     Max;
	uint8_t      data[1];
} DATASTACK, *PDATASTACK;
/* A queue which contains pointers to user objects. If the queue
   is filled to capacity and new queue is allocated, and all
   existing pointers are transferred.                            */
typedef struct LinkQueue
{
	/* This is the index of the next pointer to be added to the
	   queue. If Top==Bottom, then the queue is empty, until a
	   pointer is added to the queue, and Top is incremented.   */
	volatile INDEX     Top;
	/* This is the index of the next element to leave the queue. */
	volatile INDEX     Bottom;
	/* This is the current count of pointers that can be stored in
	   the queue.                                                  */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore. For
	   thread safety.                                            */
#if USE_CUSTOM_ALLOCER
	volatile uint32_t     Lock;
#endif
 // need two to have distinct empty/full conditions
	POINTER pNode[2];
} LINKQUEUE, *PLINKQUEUE;
/* A queue of structure elements.
   Remarks
   The size of each element must be known at stack creation
   time. Structures are literally copied to and from this stack.
   This is a stack 'by value'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct DataQueue
{
	/* This is the next index to be added to. If Top==Bottom, the
	   queue is empty, until an entry is added at Top, and Top
	   increments.                                                */
	volatile INDEX     Top;
	/* The current bottom index. This is the next one to be
	   returned.                                            */
	volatile INDEX     Bottom;
	/* How many elements the queue can hold. If a queue has more
	   elements added to it than it has count, it will be expanded,
	   and a new queue returned.                                    */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore */
	//volatile uint32_t     Lock;
	/* How big each element in the queue is. */
	INDEX     Size;
	/* How many elements to expand the queue by, when its capacity
	   is reached.                                                 */
	INDEX     ExpandBy;
	/* The data area of the queue. */
	uint8_t      data[1];
} DATAQUEUE, *PDATAQUEUE;
/* A mostly obsolete function, but can return the status of
   whether all initially scheduled startups are completed. (Or
   maybe whether we are not complete, and are processing
   startups)                                                   */
_CONTAINER_NAMESPACE_END
SACK_NAMESPACE_END
/* This contains the methods to use the base container types
   defined in sack_types.h.                                  */
#ifndef LINKSTUFF
#define LINKSTUFF
	SACK_NAMESPACE
	_CONTAINER_NAMESPACE
#    define TYPELIB_CALLTYPE
#  if defined( _TYPELIBRARY_SOURCE_STEAL )
#    define TYPELIB_PROC extern
#  elif defined( NO_EXPORTS )
#    if defined( _TYPELIBRARY_SOURCE )
#      define TYPELIB_PROC
#    else
#      define TYPELIB_PROC extern
#    endif
#  elif defined( _TYPELIBRARY_SOURCE )
#    define TYPELIB_PROC EXPORT_METHOD
#  else
#    define TYPELIB_PROC IMPORT_METHOD
#  endif
_LINKLIST_NAMESPACE
//--------------------------------------------------------
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        CreateListEx   ( DBG_VOIDPASS );
/* Destroy a PLIST. */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        DeleteListEx   ( PLIST *plist DBG_PASS );
/* See <link AddLink>.
   See <link DBG_PASS>. */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        AddLinkEx      ( PLIST *pList, POINTER p DBG_PASS );
/* Sets the value of a link at the specified index.
   Parameters
   pList :     address of a PLIST
   idx :       index of the element to set
   p :         new link value to be set at the specified index
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        SetLinkEx      ( PLIST *pList, INDEX idx, POINTER p DBG_PASS );
/* Gets the link at the specified index.
   Parameters
   pList :  address of a PLIST pointer.
   idx :    index to get the link from.  */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      GetLink        ( PLIST *pList, INDEX idx );
/* Gets the address of the link node in the PLIST.
   Parameters
   pList :  address of a PLIST to get the node address
   idx :    index of the node to get the adddress of
   Example
   <code lang="c++">
   PLIST list = NULL; // don't have to use CreateList();
   POINTER *a;
   POINTER b;
   POINTER *result;
   a = &amp;b;
   AddLink( &amp;list, a );
   \result = GetLinkAddress( &amp;list, 0 );
    ( (*result) == b )
   </code>                                               */
TYPELIB_PROC  POINTER* TYPELIB_CALLTYPE     GetLinkAddress ( PLIST *pList, INDEX idx );
/* Locate a pointer in a PLIST. Return the index.
   Parameters
   pList :  address of a list pointer to locate link
   value :  link to find in the list
   Return Value List
   INVALID_INDEX :  Not found in the list
   0\-n :           Index of the first occurance of the link in the
                    list.                                           */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        FindLink       ( PLIST *pList, POINTER value );
/* return the count of used members in a PLIST
    pList : the list to count
	Return Value
	   number of things in the list.
*/
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        GetLinkCount   ( PLIST pList );
/* Uses FindLink on the list for the value to delete, and then
   sets the index of the found link to NULL.
   Parameters
   pList :  Address of a PLIST pointer
   value :  the link to find and remove from the list.
   Example
   <code lang="c++">
   PLIST list = NULL;
	POINTER a = &#47;*some address*&#47;;
   </code>
   <code>
   AddLink( &amp;list, a );
   DeleteLink( &amp;list, a );
   </code>                                                     */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      DeleteLink     ( PLIST *pList, CPOINTER value );
/* Remove all links from a PLIST. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyList      ( PLIST *pList );
#ifdef __cplusplus
/* This was a basic attempt to make list into a C++ class. I
   gave up doing this sort of thing afterwards after realizing
   the methods of a library and these static methods for a class
   aren't much different.                                        */
typedef class iList
{
public:
	PLIST list;
	INDEX idx;
	inline iList() { list = CreateListEx( DBG_VOIDSRC ); }
	inline ~iList() { DeleteListEx( &list DBG_SRC ); }
	inline iList &operator+=( POINTER &p ){ AddLinkEx( &list, p DBG_SRC ); return *this; }
	inline void add( POINTER p ) { AddLinkEx( &list, p DBG_SRC ); }
	inline void remove( POINTER p ) { DeleteLink( &list, p ); }
	inline POINTER first( void ) { POINTER p; for( idx = 0, p = NULL;list && (idx < list->Cnt) && (( p = GetLink( &list, idx ) )==0); )idx++; return p; }
	inline POINTER next( void ) { POINTER p; for( idx++;list && (( p = GetLink( &list, idx ) )==0) && idx < list->Cnt; )idx++; return p; }
	inline POINTER get(INDEX idx) { return GetLink( &list, idx ); }
} *piList;
#endif
// address of the thing...
typedef uintptr_t (CPROC *ForProc)( uintptr_t user, INDEX idx, POINTER *item );
// if the callback function returns non 0 - then the looping is aborted,
// and the value is returned... the user value is passed to the callback.
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE     ForAllLinks    ( PLIST *pList, ForProc func, uintptr_t user );
/* This is a iterator which can be used to check each member in
   a PLIST.
   Parameters
   list :     List to iterate through
   index :    variable to use to index the list
   type :     type of the elements stored in the list (for C++)
   pointer :  variable used to get the current member of the
              list.
   Example
   <code lang="c++">
   POINTER p;  // the pointer to receive the list member pointer (should be a user type)
   INDEX idx; // indexer
   PLIST pList; // some list.
   LIST_FORALL( pList, idx, POINTER, p )
   {
       // p will never be NULL here.
       // each link stored in the list is set to p here..
       // this is a way to remove this item from the list...
       SetLink( &amp;pList, idx, NULL );
       if( some condition )
          break;
   }
   </code>
   Another example that uses data and searches..
   <code lang="c++">
   PLIST pList = NULL;
   INDEX idx;
   CTEXTSTR string;
   AddLink( &amp;pList, (POINTER)"hello" );
   </code>
   <code>
   AddLink( &amp;pList, (POINTER)"world" );
   LITS_FORALL( pList, idx, CTEXTSTR, string )
   {
       if( strcmp( string, "hello" ) == 0 )
           break;
   }
   // here 'string' will be NULL if not found, else will be what was found
   </code>
   Remarks
   This initializes the parameters passed to the macro so that
   if the list is NULL or empty, then p will be set to NULL. If
   there are no non-nulll members in the list, p will be set to
   NULL. If you break in the loop, like in the case of searching
   the list for something, then p will be non-null at the end of
   the loop.
                                                                                         */
#define LIST_FORALL( l, i, t, v )  if(((v)=(t)NULL),(l))                                                        for( ((i)=0); ((i) < ((l)->Cnt))?                                         (((v)=(t)((l)->pNode[i])),1):(((v)=(t)NULL),0); (i)++ )  if( v )
/* This can be used to continue iterating through a list after a
   LIST_FORALL has been interrupted.
   Parameters
   list :     \Description
   index :    index variable for stepping through the list
   type :     type of the members in the list.
   pointer :  variable name to use to store the the current list
              element.
   Example
   <code lang="c++">
   PLIST pList = NULL;
   CTEXTSTR p;
   INDEX idx;
   </code>
   <code>
   AddLink( &amp;pList, "this" );
   AddLink( &amp;pList, "is" );
   AddLink( &amp;pList, "a" );
   AddLink( &amp;pList, "test" );
   LIST_FORALL( pList, idx, CTEXTSTR, p )
   {
       if( strcmp( p, "is" ) == 0 )
           break;
   }
   LIST_NEXTALL( pList, idx, CTEXTSTR, p )
   {
       printf( "remaining element : %s", p );
   }
   </code>
   <code lang="c++">
   j
   </code>                                                       */
#define LIST_NEXTALL( l, i, t, v )  if(l)                for( ++(i),((v)=(t)NULL); ((i) < ((l)->Cnt))?     (((v)=(t)(l)->pNode[i]),1):(((v)=(t)NULL),0); (i)++ )  if( v )
/* <combine sack::containers::list::CreateListEx@DBG_VOIDPASS>
   \ \                                                         */
#define CreateList()       ( CreateListEx( DBG_VOIDSRC ) )
/* <combine sack::containers::list::DeleteListEx@PLIST *plist>
   \ \                                                         */
#ifndef FIX_RELEASE_COM_COLLISION
#  define DeleteList(p)      ( DeleteListEx( (p) DBG_SRC ) )
#endif
/* Adds a pointer to a user object to a list.
   Example
   <code lang="c++">
   // the list can be initialized to NULL,
   // it does not have to be assigned the result of a CreateList().
   // this allows the list to only be allocated if it is used.
   PLIST list = NULL;
   AddLink( &amp;list, (POINTER)user_pointer );
   {
       POINTER p; // this should be USER_DATA_TYPE *p;
       INDEX idx; // just a generic counter.
       LIST_FORALL( list, idx, POINTER, p )
       {
           // for each item in the list, p will be not null.
           if( p-\>something == some_other_thing )
               break;
       }
       // p will be NULL if the list is empty
       // p will be NULL if the LIST_FORALL loop completes to termination.
       // p will be not NULL if the LIST_FORALL loop executed a 'break;'
   }
   </code>                                                                 */
#define AddLink(p,v)       ( AddLinkEx( (p),((POINTER)(v)) DBG_SRC ) )
/* <combine sack::containers::list::SetLinkEx@PLIST *@INDEX@POINTER p>
   \ \                                                                 */
#define SetLink(p,i,v)     ( SetLinkEx( (p),(i),((POINTER)(v)) DBG_SRC ) )
#ifdef __cplusplus
//		namespace list;
	};
#endif
//--------------------------------------------------------
_DATALIST_NAMESPACE
/* Creates a data list which hold data elements of the specified
   size.
                                                                 */
TYPELIB_PROC  PDATALIST TYPELIB_CALLTYPE  CreateDataListEx ( uintptr_t nSize DBG_PASS );
/* <combine sack::containers::data_list::DeleteDataList>
   \ \                                                   */
TYPELIB_PROC  void TYPELIB_CALLTYPE       DeleteDataListEx ( PDATALIST *ppdl DBG_PASS );
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    SetDataItemEx ( PDATALIST *ppdl, INDEX idx, POINTER data DBG_PASS );
/* Adds an item to a DataList.
   Example
   <code lang="c++">
   PDATALIST datalist = CreateDataList();
   struct my_struct {
       uint32_t my_data;
   }
   struct my_struct my_item;
   my_item.my_data = 0;
   AddDataItem( &amp;datalist, &amp;my_item );
   </code>                                     */
#define AddDataItem(list,data) (((list)&&(*(list)))?SetDataItemEx((list),(*list)->Cnt,data DBG_SRC ):NULL)
/* Sets the item at a specific nodes to the new data.
   Parameters
   ppdl :      address of a PDATALIST.
   idx :       index of element in list to set
   data :      POINTER to data to set element to
   DBG_PASS :  optional debug file/line information
   Example
   <code lang="c++">
      PDATALIST pdl;
      int oldval = 3;
      int newval = 5;
      pdl = CreateDataList( sizeof( int ) ); // store int's as data
      AddDataItem( &amp;pdl, &amp;oldval );
      SetDataItem( &amp;pdl, 0, &amp;newval );
   </code>                                                          */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    SetDataItemEx ( PDATALIST *ppdl, INDEX idx, POINTER data DBG_PASS );
/* \Returns a pointer to the data at a specified index.
   Parameters
   \ \
   ppdl :  address of a PDATALIST
   idx :   index of element to get                      */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    GetDataItem ( PDATALIST *ppdl, INDEX idx );
/* Removes a data element from the list (moves all other
   elements down over it since there is no used indicator.
   Parameters
   ppdl :  address of a PDATALIST.
   idx :   index of element to delete                      */
TYPELIB_PROC  void TYPELIB_CALLTYPE       DeleteDataItem ( PDATALIST *ppdl, INDEX idx );
/* Empties a PDATALIST of all content.
   Parameters
   ppdl :  address of a PDATALIST
   Example
   <code lang="c++">
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) ); // store int's as data
   EmptyDataList( &amp;pdl );
   </code>                                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE       EmptyDataList ( PDATALIST *ppdl );
/* For loop to iterate through all items in a PDATALIST.
   <code lang="c++">
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) );
   {
      INDEX index;
      int *value;
      DATA_FORALL( pdl, index, int, value )
      {
      }
   }
   </code>                                               */
#define DATA_FORALL( l, i, t, v )  if(((v)=(t)NULL),(l)&&((l)->Cnt != INVALID_INDEX))	   for( ((i)=0);	                         (((i) < (l)->Cnt)                                             ?(((v)=(t)((l)->data + (uintptr_t)(((l)->Size) * (i)))),1)	         :(((v)=(t)NULL),0))&&(v); (i)++ )
/* <code>
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) );
   {
      INDEX index;
      int *value;
      DATA_FORALL( pdl, index, int, value )
      {
          // abort loop early
      }
      DATA_NEXTALL( pdl, index, int, value )
      {
      }
   }
   </code>                                   */
#define DATA_NEXTALL( l, i, t, v )  if(((v)=(t)NULL),(l))	   for( ((i)++);	                         ((i) < (l)->Cnt)                                             ?((v)=(t)((l)->data + (((l)->Size) * (i))))	         :(((v)=(t)NULL),0); (i)++ )
/* <combine sack::containers::data_list::CreateDataListEx@uintptr_t nSize>
   Creates a DataList specifying just the size. Uses the current
   source and line for debugging parameter.                               */
#define CreateDataList(sz) ( CreateDataListEx( (sz) DBG_SRC ) )
/* Destroy a DataList.
   Example
   <code>
   PDATALIST datalist = CreateDataList( 4 );
   DeleteDataList( &amp;datalist );
   </code>
   Parameters
   ppDataList :  pointer to the PDATALIST.   */
#define DeleteDataList(p)  ( DeleteDataListEx( (p) DBG_SRC ) )
/* <combine sack::containers::data_list::SetDataItemEx@PDATALIST *@INDEX@POINTER data>
   \ \                                                                                 */
#define SetDataItem(p,i,v) ( SetDataItemEx( (p),(i),(v) DBG_SRC ) )
   _DATALIST_NAMESPACE_END
//--------------------------------------------------------
#ifdef __cplusplus
		namespace link_stack {
#endif
/* Creates a new stack for links (POINTERS).
   Parameters
   DBG_PASS :  Debug file and line information to use for the
               allocation of the stack.
   Returns
   Pointer to a new link stack.                               */
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE   CreateLinkStackEx( DBG_VOIDPASS );
/* Creates a new stack for links (POINTERS).  Link stack has a limited number of entries.
    When the stack fills, the oldest item on the stack is removed automatically.
	 Parameters
	 max_entries : maximum depth of the stack.
   DBG_PASS :  Debug file and line information to use for the
               allocation of the stack.
   Returns
   Pointer to a new link stack.                               */
         // creates a link stack with maximum entries - any extra entries are pushed off the bottom into NULL
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE      CreateLinkStackLimitedEx        ( int max_entries  DBG_PASS );
/* <combine sack::containers::link_stack::CreateLinkStackLimitedEx@int max_entries>
   Macro to pass default debug file and line information.                           */
#define CreateLinkStackLimited(n) CreateLinkStackLimitedEx(n DBG_SRC)
/* Destroy a link stack. Sets the pointer to the stack to NULL
   on deletion.
   Parameters
   pls :       address of a link stack pointer
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteLinkStackEx( PLINKSTACK *pls DBG_PASS);
/* Pushes a new link on the stack.
   Parameters
   pls :       address of a link stack pointer
   p :         new pointer to push on the stack
   DBG_PASS :  debug source file and line information.
   Returns
   New link stack pointer if the stack was reallocated to have
   more space. Since the address of the pointer is passed, the
   pointer is already updated, and the return value is
   unimportant.                                                */
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE   PushLinkEx       ( PLINKSTACK *pls, POINTER p DBG_PASS);
/* Reads the top value of the stack and returns it, removes top
   link on the stack.
   Parameters
   pls :  address of a link stack pointer
   Return Value List
   NULL :      Stack was empty
   not NULL :  Link that was on the top of the stack.           */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopLink          ( PLINKSTACK *pls );
/* Look at the top link on the stack.
   Parameters
   pls :  address of a link stack pointer
   Return Value List
   NULL :      Nothing on stack.
   not NULL :  link on the top of the stack. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekLink         ( PLINKSTACK *pls );
/* Look at links in the stack.
   Parameters
	pls :  address of a link stack pointer
	n : index of the element from the top to look at
   Return Value List
   NULL :      Nothing on stack at the position specified.
   not NULL :  link on the top of the stack. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekLinkEx         ( PLINKSTACK *pls, INDEX n );
// thought about adding these, but decided on creating a limited stack instead.
//TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      StackLength      ( PLINKSTACK *pls );
//TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopLinkEx        ( PLINKSTACK *pls, int position );
/* <combine sack::containers::link_stack::CreateLinkStackEx@DBG_VOIDPASS>
   Macro to pass default file and line information.                       */
#define CreateLinkStack()  CreateLinkStackEx( DBG_VOIDSRC )
/* <combine sack::containers::link_stack::DeleteLinkStackEx@PLINKSTACK *pls>
   Macro to pass default file and line information.                          */
#define DeleteLinkStack(p) DeleteLinkStackEx((p) DBG_SRC)
/* <combine sack::containers::link_stack::PushLinkEx@PLINKSTACK *@POINTER p>
   Macro to pass default debug file and line information.                    */
#define PushLink(p, v)     PushLinkEx((p),(v) DBG_SRC)
#ifdef __cplusplus
//		namespace link_stack {
		};
#endif
//--------------------------------------------------------
#ifdef __cplusplus
		namespace data_stack {
#endif
/* Creates a data stack for data element of the specified size.
   Parameters
   size :       size of elements in the stack
   DBG_PASS :  debug file and line information.                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   CreateDataStackEx( size_t size DBG_PASS );
/* Creates a data stack for data element of the specified size.
   Parameters
   size :       size of items in the stack
   count :      max items in stack (oldest gets deleted)
   DBG_PASS :  debug file and line information.                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   CreateDataStackLimitedEx( size_t size, INDEX count DBG_PASS );
/* Destroys a data stack.
   Parameters
   pds :       address of a data stack pointer. The pointer will
               be set to NULL when the queue is destroyed.
   DBG_PASS :  Debug file and line information.                  */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteDataStackEx( PDATASTACK *pds DBG_PASS);
/* Push a data element onto the stack. The size of the element
   is known at the stack creation time.
   Parameters
   pds :       address of a data stack pointer
   p :         pointer to data to push on stack
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   PushDataEx     ( PDATASTACK *pds, POINTER pdata DBG_PASS );
/* \Returns an allocated buffer containing the data on the
   stack. Removes item from the stack.
   Parameters
   pds :  address of a data stack to get data from         */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopData        ( PDATASTACK *pds );
/* Clear all data stored in the stack.
   Parameters
   pds :  address of a data stack pointer. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyDataStack ( PDATASTACK *pds );
/* Look at top item in the stack without removing it.
   Parameters
   pds :  address of a data stack to look at          */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekData       ( PDATASTACK *pds );
// Incrementing Item moves progressivly down the stack
// final(invalid) stack, and/or empty stack will return NULL;
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekDataEx     ( PDATASTACK *pds, INDEX Item );
 /* keeps data on stack (can be used)
                                                                                      Parameters
                                                                                      pds :   address of a data stack pointer
                                                                                      Item :  Item to peek at; 0 is the top, 1 is just below it...
                                                                                              (maybe \-1 is last and further up)
                                                                                      Returns
                                                                                      \returns the address of the data item in the data stack.     */
/* <combine sack::containers::data_stack::CreateDataStackEx@INDEX size>
   Macro to pass default file and line information.                     */
#define CreateDataStack(size) CreateDataStackEx( size DBG_SRC )
/* <combine sack::containers::data_stack::CreateDataStackEx@INDEX size>
   Macro to pass default file and line information.                     */
#define CreateDataStackLimited(size,items) CreateDataStackLimitedEx( size,items DBG_SRC )
/* <combine sack::containers::data_stack::DeleteDataStackEx@PDATASTACK *pds>
   Macro to pass default file and line information.                          */
#define DeleteDataStack(p) DeleteDataStackEx((p) DBG_SRC)
/* <combine sack::containers::data_stack::PushDataEx@PDATASTACK *@POINTER pdata>
   Macro to pass default file and line information.                              */
#define PushData(pds,p) PushDataEx(pds,p DBG_SRC )
#ifdef __cplusplus
 //		namespace data_stack {
		}
#endif
/* Queue container - can enque (at tail) deque (from head) and preque (at head). Can also browse the queue with peekqueue. */
#ifdef __cplusplus
		namespace queue {
#endif
/* Creates a <link sack::containers::PLINKQUEUE, LinkQueue>. In
   debug mode, gets passed the current source and file so it can
   blame the user for the allocation.                            */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   CreateLinkQueueEx( DBG_VOIDPASS );
/* Delete a link queue. Pass the address of the pointer to the
   queue to delete, this function sets the pointer to NULL if
   the queue is actually deleted.                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteLinkQueueEx( PLINKQUEUE *pplq DBG_PASS );
/* Enque a link to the queue.  */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   EnqueLinkEx      ( PLINKQUEUE *pplq, POINTER link DBG_PASS );
TYPELIB_PROC  void TYPELIB_CALLTYPE   EnqueLinkNLEx( PLINKQUEUE *pplq, POINTER link DBG_PASS );
/* EnqueLink adds the new item at the end of the list. PrequeueLink
   puts the new item at the head of the queue (so it's the next
   one to be retrieved).                                            */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   PrequeLinkEx      ( PLINKQUEUE *pplq, POINTER link DBG_PASS );
/* If the queue is not empty, returns the address of the next
   element in the queue and removes the element from the queue.
                                                                */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      DequeLink        ( PLINKQUEUE *pplq );
TYPELIB_PROC POINTER  TYPELIB_CALLTYPE      DequeLinkNL      ( PLINKQUEUE *pplq );
/* Return TRUE/FALSE if the queue is empty or not. */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      IsQueueEmpty     ( PLINKQUEUE *pplq );
/* Gets the number of elements current in the queue. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        GetQueueLength   ( PLINKQUEUE plq );
// get a PLINKQUEUE element at index
//  If idx < 0 then count from the end of the queue, otherwise count from the start of the queue
// start of the queue is the next element to be dequeue, end of the queue is the last element added to the queue.
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekQueueEx    ( PLINKQUEUE plq, int idx );
/* Can be used to look at the next element in the queue without
   removing it from the queue. PeekQueueEx allows you to specify
   an index of an item in the queue to get.                      */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekQueue    ( PLINKQUEUE plq );
/* <combinewith sack::containers::queue::CreateLinkQueueEx@DBG_VOIDPASS>
   \ \                                                                   */
#define     CreateLinkQueue()     CreateLinkQueueEx( DBG_VOIDSRC )
/* <combine sack::containers::queue::PrequeLinkEx@PLINKQUEUE *@POINTER link>
   \ \                                                                       */
#define     PrequeLink(pplq,link) PrequeLinkEx( pplq, link DBG_SRC )
/* <combine sack::containers::queue::DeleteLinkQueueEx@PLINKQUEUE *pplq>
   \ \                                                                   */
#define     DeleteLinkQueue(pplq) DeleteLinkQueueEx( pplq DBG_SRC )
/* <combine sack::containers::queue::EnqueLinkEx@PLINKQUEUE *@POINTER link>
   \ \                                                                      */
#define     EnqueLink(pplq, link) EnqueLinkEx( pplq, link DBG_SRC )
#define     EnqueLinkNL(pplq, link) EnqueLinkNLEx( pplq, link DBG_SRC )
#ifdef __cplusplus
//		namespace queue {
		}
#endif
/* Functions related to PDATAQUEUE container. DataQueue stores
   literal data elements in the list instead of just a pointer. (could
   be used for optimized vertex arrays for instance).
   int data = 3;
   int result;
   PDATAQUEUE pdq = CreateDataQueue( sizeof( int ) );
   EnqueData( &amp;pdq, &amp;data );
   DequeData( &amp;pdq, &amp;result );
   DestroyDataQueue( &amp;pdq );                                       */
#ifdef __cplusplus
		namespace data_queue {
#endif
/* Creates a PDATAQUEUE. Can pass DBG_FILELINE information to
   blame other code for the allocation.                       */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   CreateDataQueueEx( INDEX size DBG_PASS );
/* Creates a PDATAQUEUE that has an overridden expand-by amount
   and initial amount of entries in the queue. (expecting
   something like 1000 to start and expand by 500, instead of
   the default 0, and expand by 1.                              */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   CreateLargeDataQueueEx( INDEX size, INDEX entries, INDEX expand DBG_PASS );
/* Destroys a data queue. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteDataQueueEx( PDATAQUEUE *pplq DBG_PASS );
/* Add a data element into the queue. */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   EnqueDataEx      ( PDATAQUEUE *pplq, POINTER Data DBG_PASS );
/* Enque data at the head of the queue instead of the tail. (Normally
   add at tail, take from head).                                      */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   PrequeDataEx      ( PDATAQUEUE *pplq, POINTER Data DBG_PASS );
/* Removes data from a queue, resulting with the data in the
   specified buffer, and result TRUE if there was an element
   else FALSE, and the buffer is not modified.               */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      DequeData        ( PDATAQUEUE *pplq, POINTER Data );
/* Removes the last element in the queue. (takes from the tail). */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      UnqueData        ( PDATAQUEUE *pplq, POINTER Data );
/* Checks if the queue is empty, result TRUE if nothing in it,
   else FALSE.                                                 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      IsDataQueueEmpty ( PDATAQUEUE *pplq );
/* Empty a dataqueue of all data. (Sets head=tail). */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyDataQueue ( PDATAQUEUE *pplq );
/*
 * get a PDATAQUEUE element at index
 * result buffer is a pointer to the type of structure expected to be
 * stored within this.  The buffer result is a copy of the data stored in the queue.
 * This enforces that data stored in the list is immutable.
 * Also on the basic DequeData function, after resulting, if the pointer to the
 * data within the queue were returned, it could become invalid immediatly after
 * returning by having another enque happen which overwrites that position in the buffer.
 * One could, in theory, set a flag in the queue that a deque was done, and not update the
 * bottom until that flag is encountered while within DequeData again...
 * the pointer to the data in the queue may also not be returned because the queue may be
 * reallocated and moved.
 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  PeekDataQueueEx    ( PDATAQUEUE *pplq, POINTER ResultBuffer, INDEX idx );
/* <combine sack::containers::data_queue::PeekDataQueueEx@PDATAQUEUE *@POINTER@INDEX>
   \ \                                                                                */
#define PeekDataQueueEx( q, type, result, idx ) PeekDataQueueEx( q, (POINTER)result, idx )
/*
 * Result buffer is filled with the last element, and the result is true, otherwise the return
 * value is FALSE, and the data was not filled in.
 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  PeekDataQueue    ( PDATAQUEUE *pplq, POINTER ResultBuffer );
/* <combine sack::containers::data_queue::PeekDataQueue@PDATAQUEUE *@POINTER>
   \ \                                                                        */
#define PeekDataQueue( q, type, result ) PeekDataQueue( q, (POINTER)result )
/* <combine sack::containers::data_queue::CreateDataQueueEx@INDEX size>
   \ \                                                                  */
#define     CreateDataQueue(size)     CreateDataQueueEx( size DBG_SRC )
/* <combine sack::containers::data_queue::CreateLargeDataQueueEx@INDEX@INDEX@INDEX expand>
   \ \                                                                                     */
#define     CreateLargeDataQueue(size,entries)     CreateLargeDataQueueEx( size,entries, 0 DBG_SRC )
/* <combine sack::containers::data_queue::DeleteDataQueueEx@PDATAQUEUE *pplq>
   \ \                                                                        */
#define     DeleteDataQueue(pplq) DeleteDataQueueEx( pplq DBG_SRC )
/* <combine sack::containers::data_queue::EnqueDataEx@PDATAQUEUE *@POINTER Data>
   \ \                                                                           */
#define     EnqueData(pplq, Data) EnqueDataEx( pplq, Data DBG_SRC )
/* <combine sack::containers::data_queue::PrequeDataEx@PDATAQUEUE *@POINTER Data>
   \ \                                                                            */
#define     PrequeData(pplq, Data) PrequeDataEx( pplq, Data DBG_SRC )
#ifdef __cplusplus
//		namespace data_queue {
		}
#endif
//---------------------------------------------------------------------------
#ifdef __cplusplus
namespace message {
#endif
/* handle to a message queue. */
typedef struct MsgDataHandle *PMSGHANDLE;
//typedef struct MsgDataQueue *PMSGQUEUE;
// messages sent - the first dword of them must be
// a message ID.
typedef void (CPROC *MsgQueueReadCallback)( uintptr_t psv, CPOINTER p, uintptr_t sz );
/* Create a named shared memory message queue.
   Parameters
   name :     name of the queue to create
   size :     size of the queue.
   Read :     read callback, called when a message is received on
              the queue.
   psvRead :  user data associated with the queue. Passed to the
              read callback.                                      */
TYPELIB_PROC  PMSGHANDLE TYPELIB_CALLTYPE  SackCreateMsgQueue ( CTEXTSTR name, size_t size
                                                      , MsgQueueReadCallback Read
                                                      , uintptr_t psvRead );
/* Open a message queue. Opens if it exists, does not create.
   Parameters
   name :     name of the queue.
   Read :     read callback called when a message is received.
   psvRead :  user data associated with this queue, and passed to
              the read callback.                                  */
TYPELIB_PROC  PMSGHANDLE TYPELIB_CALLTYPE  SackOpenMsgQueue ( CTEXTSTR name
													 , MsgQueueReadCallback Read
													 , uintptr_t psvRead );
/* Destroys a message queue.
   Parameters
   ppmh :  address of the message queue handle to close (sets
           pointer to NULL when deleted)                      */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteMsgQueue ( PMSGHANDLE **ppmh );
 // if enque, fail send, return immediate on fail
#define MSGQUE_NOWAIT 0x0001
                             // if deque, fail no msg ready to get...
 // read any msg BUT MsgID
#define MSGQUE_EXCEPT 0x0002
 // enque this message... it is a task ID which is waiting.
#define MSGQUE_WAIT_ID 0x0004
/* Error result if there is no message to read. (GetLastError()
   after peekmsg or readmsg returns -1)                         */
#define MSGQUE_ERROR_NOMSG 1
/* Error result if the message to read is bigger than the buffer
   passed to read the message.                                   */
#define MSGQUE_ERROR_E2BIG 2
/* Error result. Unexpected error (queue head/tail out of
   bounds)                                                */
#define MSGQUE_ERROR_EABORT 5
// result is the size of the message, or 0 if no message.
// -1 if some other error?
TYPELIB_PROC  int TYPELIB_CALLTYPE  DequeMsgEx ( PMSGHANDLE pmh, long *MsgID, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Receives a message from the message queue.
   Parameters
   Message Queue :  PMSGHANDLE to read from
   Message ID * :   a Pointer to the message ID to read. Updated
                    with the message ID from the queue.
   buffer :         buffer to read message into
   buffer length :  length of the buffer to read
   options :        extra options for the read
   Return Value List
   \-1 :  Error
   0 :    No Message to read
   \>0 :  size of message read.
   Returns
   \ \                                                           */
#define DequeMsg(q,b,s,i,o) DequeMsgEx(q,b,s,i,o DBG_SRC )
/* <combine sack::containers::message::PeekMsg>
   \ \                                          */
TYPELIB_PROC  int TYPELIB_CALLTYPE  PeekMsgEx ( PMSGHANDLE pmh, long MsgID, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Just peek at the next message.
   Parameters
   queue :        The PMSGHANDLE queue to read.
   MsgID :        what message to read. 0 is read any message.
   buffer :       where to read the message data into.
   buffer_size :  the length of the message buffer.
   options :      Options controlling the read
   Returns
   \-1 on error
   0 if no message
   length of the message read                                  */
#define PeekMsg(q,b,s,i,o) PeekMsgEx(q,b,s,i,o DBG_SRC )
/* <combine sack::containers::message::EnqueMsg>
   \ \                                          */
TYPELIB_PROC  int TYPELIB_CALLTYPE  EnqueMsgEx ( PMSGHANDLE pmh, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Add a message to the queue.
   Parameters
   Message Queue :  PMSGQUEUE to write to.
   Buffer :         pointer to the message to send. THe MSgID is
                    the first part of the message buffer.
   Buffer Length :  how long the message to send is
   Options :        Extra options for send
   Return Value List
   \-1 :  Error
   \>0 :  bytes of message sent                                  */
#define EnqueMsg(q,b,s,o) EnqueMsgEx(q,b,s,o DBG_SRC )
/* Check if the message queue is empty.
   Parameters
   pmh :  queue to check if it's empty. */
TYPELIB_PROC  int TYPELIB_CALLTYPE  IsMsgQueueEmpty ( PMSGHANDLE pmh );
#ifdef __cplusplus
 //namespace message {
};
#endif
/* Routines to deal with SLAB allocated blocks of structures.
   Each slab has multiple elements of a type in it, and the
   blocks are tracked as a linked list. Each block also has a
   bitmask of allocated elements in the set.
   \---------------------------------------------------------------------------
   Set type
   Usage:
   typedef struct name_tag { } \<name\>;
   \#define MAX\<name\>SPERSET
   DeclareSet( \<name\> );
   Should alias GetFromset, DeleteFromSet, CountUsedInSet,
   GetLinearSetArray
   etc so that the type name is reflected there
   another good place where #define defining defines is good.
   \---------------------------------------------------------------------------
                                                                                */
_SETS_NAMESPACE
//---------------------------------------------------------------------------
// Set type
//   Usage:
//      typedef struct name_tag { } <name>;
//      #define MAX<name>SPERSET
//      DeclareSet( <name> );
//    Should alias GetFromset, DeleteFromSet, CountUsedInSet, GetLinearSetArray
//       etc so that the type name is reflected there
//       another good place where #define defining defines is good.
//---------------------------------------------------------------------------
/* Hard coded 32 bit division for getting word index. (x\>\>5) */
#define UNIT_USED_IDX(n)   ((n) >> 5)
/* Hard coded 32 bit division for getting bit index. (x &amp;
   0x1f)                                                      */
#define UNIT_USED_MASK(n)  (1 << ((n) &0x1f))
/* A macro for use by internal code that marks a member of a set
   as used.
   Parameters
   set :    pointer to a genericset
   index :  item to mark used.                                   */
#define SetUsed(set,n)   ((((set)->bUsed[UNIT_USED_IDX(n)]) |= UNIT_USED_MASK(n)), (++(set)->nUsed) )
/* A macro for use by internal code that marks a member of a set
   as available.
   Parameters
   set :    pointer to a genericset
   index :  item to mark available.                              */
#define ClearUsed(set,n) ((((set)->bUsed[UNIT_USED_IDX(n)]) &= ~UNIT_USED_MASK(n)), (--(set)->nUsed) )
/* A macro for use by internal code that tests a whole set of
   bits for used. (32 bits, can check to see if any in 32 is
   free)
   Parameters
   set :    pointer to a genericset
   index :  index of an one in the set of 32 being tested.
   Returns
   0 if not all are used.
   1 if all in this block of bits are used.                   */
#define AllUsed(set,n)   (((set)->bUsed[UNIT_USED_IDX(n)]) == 0xFFFFFFFF )
/* A macro for use by internal code that tests a member of a set
   as used.
   Parameters
   set :    pointer to a genericset
   index :  item to test used.
   Returns
   not zero if is used, otherwise is free.                       */
#define IsUsed(set,n)    (((set)->bUsed[UNIT_USED_IDX(n)]) & UNIT_USED_MASK(n) )
#ifdef __cplusplus
#define CPP_(n)
/* A macro which is used to emit code in C++ mode... */
#else
#define CPP_(n)
#endif
// requires a symbol of MAX<insert name>SPERSET to declare max size...
 //ndef __cplusplus
#if 1
#define SizeOfSet(size,count)  (sizeof(POINTER)*2+sizeof(int)+sizeof( uint32_t[((count)+31)/32] ) + ((size)*(count)))
#define DeclareSet( name )  typedef struct name##set_tag {	   struct name##set_tag *next, *prior;	                      uint32_t nUsed;	                                               uint32_t nBias;	                                               uint32_t bUsed[(MAX##name##SPERSET + 31 ) / 32];	              name p[MAX##name##SPERSET];	                           CPP_(int forall(uintptr_t(CPROC*f)(void*,uintptr_t),uintptr_t psv) {if( this ) return _ForAllInSet( (struct genericset_tag*)this, sizeof(name), MAX##name##SPERSET, f, psv ); else return 0; })	 CPP_(name##set_tag() { next = NULL;prior = NULL;nUsed = 0; nBias = 0; MemSet( bUsed, 0, sizeof( bUsed ) ); MemSet( p, 0, sizeof( p ) );} )	} name##SET, *P##name##SET
#define DeclareClassSet( name ) typedef struct name##set_tag {	   struct name##set_tag *next, *prior;	                      uint32_t nUsed;	                                               uint32_t nBias;	                                               uint32_t bUsed[(MAX##name##SPERSET + 31 ) / 32];	              class name p[MAX##name##SPERSET];	                        CPP_(int forall(uintptr_t(CPROC*)(void*f,uintptr_t),uintptr_t psv) {if( this ) return _ForAllInSet( (struct genericset_tag*)this, sizeof(class name), MAX##name##SPERSET, f, psv ); else return 0; })	 } name##SET, *P##name##SET
#endif
/* This represents the basic generic set structure. Addtional
   data is allocated at the end of this strcture to fit the bit
   array that maps usage of the set, and for the set size of
   elements.
   Remarks
   \ \
   Summary
   Generic sets are good for tracking lots of tiny structures.
   They track slabs of X structures at a time. They allocate a
   slab of X structures with an array of X bits indicating
   whether a node is used or not. The structure overall has how
   many are used, so once full, a block can be quickly checked
   whether there is anything free. Then when checking a block
   that might have room, the availablility is checked 32 bits at
   a time, until a free spot is found.
   Sets of 1024 members of x,y coordinates for example are good
   for this sort of storage. the points are often static, once
   loaded they all exist until none of them do. This storage has
   gross deletion methods too, quickly evaporate all allocated
   chunks. Storing tiny chunks in a slab is more efficient
   because every allocation method has some sort of tracking
   associated with it - an overhead of having it. Plus, when
   operating on sets of data, a single solid slab of exatly the
   structures you are working with is more efficient to cache.
   Example
   <code lang="c++">
   struct treenode_tag {
       uint32_t treenode_data;  // abitrary structure data
   };
   typedef struct treenode_tag TREENODE;
   \#define MAXTREENODESPERSET 256
   DeclareSet( TREENODE );
   </code>
   The important part of the prior code is the last two lines.
   \#define MAX\<your type name\>SPERSET \<how many\>
   This defines how many of your structure are kept per set
   block.
   The DeclareSet( type ) declares a typedefed structure called
   'struct type##set_tag', 'name##SET', and '*P##name##SET'; in
   the above case, it would be 'struct TREENODEset_tag',
   'TREENODESET', and 'PTREENODESET'.
   Then to actually use the set...
   <code lang="c#">
   // declare a set pointer with one of the magic names.
   PTREENODESET nodeset = NULL;
   // get a node from the set.
   TREENODE *node = GetFromSet( TREENODE, nodeset );
   </code>
   Notice there is no CreateSet, getting a set member will
   create the set as required. Many operations may expend the
   set, except for GetUsedSetMember which will only result with
   \members that are definatly in the set. Accesses to the set
   are all prefixed by the type name the set was created with,
   'TREENODE' in this example.
   <code lang="c++">
   DeleteFromSet( TREENODE, nodeset, node );
   node = GetFromSet( TREENODE, nodeset );
   {
      int index = GetMemberIndex( TREENODE, nodeset, node );
   }
   </code>
   The accessor macros take care of expanding several parameters
   that require sizeof structure expansion.                      */
typedef struct genericset_tag {
	// wow might be nice to have some flags...
	// first flag - bSetSet - meaning that this is a set of sets of
	// the type specified...
	struct genericset_tag *next;
	/* This is the pointer that's pointing at the pointer pointing
	   to me. (did you get that?) See <link DeclareLink>.          */
	struct genericset_tag **me;
	/* number of spots in this set block that are used. */
	uint32_t nUsed;
 // hmm if I change this here? we're hozed... so.. we'll do it anyhow :) evil - recompile please
	uint32_t nBias;
 // after this p * unit must be computed
	uint32_t bUsed[1];
} GENERICSET, *PGENERICSET;
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetFromSetEx( GENERICSET **pSet, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetFromSetEx@GENERICSET **@int@int@int maxcnt>
   \ \                                                                             */
#define GetFromSeta(ps, ss, us, max) GetFromSetPoolEx( NULL, 0, 0, 0, (ps), (ss), (us), (max) DBG_SRC )
/* <combine sack::containers::sets::GetFromSetEx@GENERICSET **@int@int@int maxcnt>
   \ \
   Parameters
   name :  name of type the set contains.
   pSet :  pointer to a set to get an element from.                                */
#define GetFromSet( name, pset ) (name*)GetFromSeta( (GENERICSET**)(pset), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  PGENERICSET  TYPELIB_CALLTYPE GetFromSetPoolEx( GENERICSET **pSetSet
													 , int setsetsize, int setunitsize, int setmaxcnt
													 , GENERICSET **pSet
													 , int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetFromSetPoolEx@GENERICSET **@int@int@int@GENERICSET **@int@int@int maxcnt>
   \ \                                                                                                           */
#define GetFromSetPoola(pl, sss, sus, smax, ps, ss, us, max) GetFromSetPoolEx( (pl), (sss), (sus), (smax), (ps), (ss), (us), (max) DBG_SRC )
/* <combine sack::containers::sets::GetFromSetPoolEx@GENERICSET **@int@int@int@GENERICSET **@int@int@int maxcnt>
   \ \                                                                                                           */
#define GetFromSetPool( name, pool, pset ) (name*)GetFromSetPoola( (GENERICSET**)(pool)	    , sizeof( name##SETSET ), sizeof( name##SET ), MAX##name##SETSPERSET	, (GENERICSET**)(pset), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetSetMemberEx( GENERICSET **pSet, INDEX nMember, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                     */
#define GetSetMembera(ps, member, ss, us, max) (GetSetMemberEx( (ps), (member), (ss), (us), (max) DBG_SRC ))
/* <combine sack::containers::sets::GetSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                     */
#define GetSetMember( name, pset, member ) ((name*)GetSetMembera( (GENERICSET**)(pset), (member), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET ))
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetUsedSetMemberEx( GENERICSET **pSet, INDEX nMember, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetUsedSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                         */
#define GetUsedSetMembera(ps, member, ss, us, max) (GetUsedSetMemberEx( (ps), (member), (ss), (us), (max) DBG_SRC ))
/* <combine sack::containers::sets::GetUsedSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                         */
#define GetUsedSetMember( name, pset, member ) ((name*)GetUsedSetMembera( (GENERICSET**)(pset), (member), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET ))
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetMemberIndex(GENERICSET **set, POINTER unit, int unitsize, int max );
/* Gets the index of a member passed as a pointer.
   Parameters
   set :       pointer to the set the member is in
   unit :      pointer to the member in the set to get the index
               of.
   unitsize :  size of each member in the set
   max :       count of members in each set block.
   Returns
   \Returns the index of the member passed in as a pointer.      */
#define GetMemberIndex(name,set,member) GetMemberIndex( (GENERICSET**)set, member, sizeof( name ), MAX##name##SPERSET )
/* <combine sack::containers::sets::GetMemberIndex>
   \ \                                              */
#define GetIndexFromSet( name, pset ) GetMemberIndex( name, pset, GetFromSet( name, pset ) )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteFromSetExx( GENERICSET *set, POINTER unit, int unitsize, int max DBG_PASS );
/* <combine sack::containers::sets::DeleteFromSetExx@GENERICSET *@POINTER@int@int max>
   \ \                                                                                 */
#define DeleteFromSetEx( name, set, member, xx ) DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC )
/* <combine sack::containers::sets::DeleteFromSetExx@GENERICSET *@POINTER@int@int max>
   \ \                                                                                 */
#ifdef _DEBUG
#define DeleteFromSet( name, set, member ) do { P##name##SET testset = set; DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC ); } while(0)
#else
#define DeleteFromSet( name, set, member ) DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC )
#endif
/* Marks a member in a set as usable.
   Parameters
   set :       pointer to a genericset pointer
   iMember :   index of member to delete
   unitsize :  (filled by macro) size of element in set
   max :       (filled by macro) size of a block of elements. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteSetMemberEx( GENERICSET *set, INDEX iMember, uintptr_t unitsize, INDEX max );
/* <combine sack::containers::sets::DeleteSetMemberEx@GENERICSET *@INDEX@uintptr_t@INDEX>
   \ \                                                                                   */
#define DeleteSetMember( name, set, member ) DeleteSetMemberEx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET )
/* This function can check to see if a pointer is a valid
   element from a set.
   Parameters
   set :       pointer to a set to check
   unit :      pointer to an element from the set
   unitsize :  size of element structures in the set.
   max :       count of structures per set block
   Returns
   TRUE if unit is in the set, else FALSE.                */
TYPELIB_PROC  int TYPELIB_CALLTYPE  MemberValidInSetEx( GENERICSET *set, POINTER unit, int unitsize, int max );
/* <combine sack::containers::sets::MemberValidInSetEx@GENERICSET *@POINTER@int@int>
   \ \                                                                               */
#define MemberValidInSet( name, set, member ) MemberValidInSetEx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET )
TYPELIB_PROC  int TYPELIB_CALLTYPE  CountUsedInSetEx( GENERICSET *set, int max );
/* Count number of elements that are allocated in the set.
   Parameters
   set :  The set to check
   max :  max items per set (may be unused, since this is stored
          internally now)
   Returns
   The number of items in the step.                              */
#define CountUsedInSet( name, set ) CountUsedInSetEx( (GENERICSET*)set, MAX##name##SPERSET )
TYPELIB_PROC  POINTER * TYPELIB_CALLTYPE GetLinearSetArrayEx( GENERICSET *pSet, int *pCount, int unitsize, int max );
/* Converts a set into a copy of the objects in the set
   organized in a flat array.
   Parameters
   pSet :      set to convert to an array
   pCount :    address of an integer to receive the count of
               elements put in the array.
   unitsize :  size of each element in the set
   max :       count of elements per set block
   Returns
   Pointer to an array that are a copy of the objects in the
   set.                                                      */
#define GetLinearSetArray( name, set, pCount ) GetLinearSetArrayEx( (GENERICSET*)set, pCount, sizeof( name ), MAX##name##SPERSET )
/* Returned the index of an item in a linear array returned from
   a set.
   Parameters
   pArray :      pointer to an array which has been returned from
                 the set
   nArraySize :  size fo the array
   unit :        pointer to an element in the array
   Returns
   Index of the unit in the array, INVALID_INDEX if not in the
   array.                                                         */
TYPELIB_PROC  int TYPELIB_CALLTYPE  FindInArray( POINTER *pArray, int nArraySize, POINTER unit );
/* Delete all allocated slabs.
   Parameters
   ppSet :  pointer to a generic set pointer to delete. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteSet( GENERICSET **ppSet );
/* <combine sack::containers::sets::DeleteSet@GENERICSET **>
   \ \                                                       */
#define DeleteSetEx( name, ppset ) { name##SET **delete_me = ppset; DeleteSet( (GENERICSET**)delete_me ); }
/* <combine sack::containers::sets::ForAllInSet>
   ForAllinSet Callback - callback fucntion used with
   ForAllInSet                                        */
typedef uintptr_t (CPROC *FAISCallback)(void*,uintptr_t);
/* \ \
   Parameters
   pSet :      poiner to a set
   unitsize :  size of elements in the array
   max :       count of elements per set block
   f :         user callback function to call for each element in
               the set
   psv :       user data passed to the user callback when it is
               invoked for a member of the set.
   Returns
   If the user callback returns 0, the loop continues. If the
   user callback returns non zero then the looping through the
   set ends, and that result is returned.                         */
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE  _ForAllInSet( GENERICSET *pSet, int unitsize, int max, FAISCallback f, uintptr_t psv );
/* <combine sack::containers::sets::ForEachSetMember>
   ForEachSetMember Callback function - for the function '
   ForEachSetMember'                                       */
typedef uintptr_t (CPROC *FESMCallback)(INDEX,uintptr_t);
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE  ForEachSetMember ( GENERICSET *pSet, int unitsize, int max, FESMCallback f, uintptr_t psv );
 //def __cplusplus
#if 0
#define DeclareSet(name)	                                struct name##set_tag {	               uint32_t set_size;	                             uint32_t element_size;	                         uint32_t element_cnt;	                          PGENERICSET pool;	                        name##set_tag() {	                        element_size = sizeof( name );	             element_cnt = MAX##name##SPERSET;	          set_size = (element_size * element_cnt )+ ((((element_cnt + 31 )/ 32 )- 1 ) * 4) + sizeof( GENERICSET );	 pool = NULL;	                               }	    ~name##set_tag() { DeleteSet( &pool ); }	 name* grab() { return (name*)GetFromSetEx( &pool, set_size, element_size, element_cnt DBG_SRC ); }	 name* grab(INDEX member) { return (name*)GetSetMemberEx( &pool, member, set_size, element_size, element_cnt DBG_SRC ); }	 name* get(INDEX member) { return (this)?(name*)GetUsedSetMemberEx( &pool, member, set_size, element_size, element_cnt DBG_SRC ):(NULL); }	 void drop( name* member ) { DeleteFromSetEx( pool, (POINTER)member, element_size, element_cnt ); }	 int valid( name* member ) { return MemberValidInSetEx( pool, (POINTER)member, element_size, element_cnt ); }	 uintptr_t forall( FAISCallback f, uintptr_t psv ) { if( this ) return _ForAllInSet( pool, element_size, element_cnt, f, psv ); else return 0; }	 };	       typedef struct name##set_tag *P##name##SET, name##SET;
#define ForAllInSet(name, pset,f,psv) _ForAllInSet( (GENERICSET*)(pset), sizeof( name ), MAX##name##SPERSET, (f), (psv) )
#else
/* <combine sack::containers::sets::_ForAllInSet@GENERICSET *@int@int@FAISCallback@uintptr_t>
   \ \                                                                                       */
#define ForAllInSet(name, pset,f,psv) _ForAllInSet( (GENERICSET*)(pset), sizeof( name ), MAX##name##SPERSET, (f), (psv) )
/* Performs an iteration over each allocated set member. Calls
   the user provided callback routine with each element in the
   set.
   Parameters
   pSet :      pointer to the set to iterate
   unitsize :  size of each element
   max :       max count of elements per set block
   f :         function to call ( uintptr_t (*)(INDEX,uintptr_t) )
   psv :       user data value to pass to function as uintptr_t
   Returns
   uintptr_t - this value is the return of the user function if
   the function does not return 0. A non zero return from the
   user callback stops iteration.                                */
#define ForEachSetMember(name,pset,f,psv) ForEachSetMember( (GENERICSET*)(pset),sizeof(name),MAX##name##SPERSET, (f), (psv) )
#endif
//---------------------------------------------------------------------------
_SETS_NAMESPACE_END
_TEXT_NAMESPACE
// this defines more esoteric formatting notions...
// these data blocks will be zero sized, and ahve the TF_FORMATEX
// bit set.
//#define DEFAULT_COLOR 0xF7
//#define PRIOR_COLOR 0xF6 // this does not change the color....
// these enumerated ops put in the foreground field of a format
// with a flag of TF_FORMATEX will cause the specified operation
// to be carried out on a display (not files) or generated into
// the appropriate sequence (ansi out encode)
// -- correction
//  this is encoded into its own field for the format
// size, due to machine optimization, 16 bits were free
// this was expanded and used for all information
// a segment may contain extended op, color, attributes,
// and text, everything short of a font for it...
//  - not sure how to address that issue... there's
// certainly modifications to current font... italic for
// instance..
	enum FORMAT_OPS {
      /* this segment clears to the end of the line.  Its content is then added to the output */
		FORMAT_OP_CLEAR_END_OF_LINE = 1
        ,FORMAT_OP_CLEAR_START_OF_LINE
                   ,
						  FORMAT_OP_CLEAR_LINE
						 ,
						  FORMAT_OP_CLEAR_END_OF_PAGE
                   ,
						  FORMAT_OP_CLEAR_START_OF_PAGE
						 ,
/* clear the entire vieable page (pushes all content to history)
                    set cursor home ;6*/
						  FORMAT_OP_CLEAR_PAGE
						 ,
						  FORMAT_OP_CONCEAL
                   ,
						  FORMAT_OP_DELETE_CHARS
                   ,
						  FORMAT_OP_SET_SCROLL_REGION
                   ,
						  FORMAT_OP_GET_CURSOR
						 ,
						  FORMAT_OP_SET_CURSOR
						 ,
						  FORMAT_OP_PAGE_BREAK
						 ,
/* break between paragraphs - kinda same as lines...
						  since lines are as long as possible... ;13 */
						 FORMAT_OP_PARAGRAPH_BREAK
						 ,
/* Justify line(s if wrapped) to the right
						   This attribute should be passed through to renderer;14*/
                   FORMAT_OP_JUSTIFY_RIGHT
						 ,
/* Justify line(s if wrapped) to the center
						 This attribute should be passed through to renderer;15*/
                   FORMAT_OP_JUSTIFY_CENTER
};
//typedef struct text_color_tag { uint32_t color: 8; } TEXTCOLOR;
// this was a 32 bit structure, but 8 fore, 8 back
// 8 x, 8 y failed for positioning...
// extended position, added more information
// reduced color, 16 colors is really all that there
// are... 4 bits... added bits for extended formatting
// like blink, bold, wide, high
// foreground/background  values will be
// sufficient... they retain full informaiton
//
typedef struct format_info_tag
{
   /* bit-packed flags indicating the type of format information that is applied to this segment.*/
	struct {
		// extended operation from enumeration above...
		// might shrink if more attributes are desired...
		// if many more are needed, one might consider
      // adding FONT!
     /* this segment uses the prior foreground, not its own. */
		BIT_FIELD prior_foreground : 1;
     /* this segment uses the prior background, not its own. */
		BIT_FIELD prior_background : 1;
     /* this segment uses the default foreground, not its own. */
		BIT_FIELD default_foreground : 1;
      /* this segment uses the default background, not its own. */
		BIT_FIELD default_background : 1;
      /* the foreground color of this segment (0-16 standard console text [ANSI text]) */
		BIT_FIELD foreground : 4;
      /* the background color of this segment (0-16 standard console text [ANSI text]) */
		BIT_FIELD background : 4;
      /* a bit indicating the text should blink if supported */
		BIT_FIELD blink : 1;
      /* a bit indicating the foreground and background color should be reversed */
		BIT_FIELD reverse : 1;
		// usually highly is bolder, perhaps it's
      // a highlighter effect and changes the background
		BIT_FIELD highlight : 1;
		// this is double height modifications to the font...
		BIT_FIELD tall : 1;
      // this is thicker characters...
		BIT_FIELD bold : 1;
      // draw a line under the text...
		BIT_FIELD underline : 1;
		// strike through - if able, draw a line right
		// through the middle of the text... maybe
		// it's a wiggly scribble line?  maybe that
      // could be extended again?
		BIT_FIELD strike : 1;
      // text is drawn wide (printer kinda font?)
		BIT_FIELD wide : 1;
       // this is pretty common......
		BIT_FIELD italic : 1;
		// --
		// these flags are free, but since we already have text segments
		// and I'm bringing in consoles, perhaps we should consider using
		// this to describe captions, but provide the api layer for CTEXTSTR
		// --
		// position data remains constant.
		// text is mounted at the top/left of the
		// first character... (unless center, then
		// the position specifies the middle of the text
		// draw vertical instead of horizontal
		BIT_FIELD bVertical:1;
		// draw opposite/upside down from normal
		// vertical/down, right/left upside down if not centered
		// if centered, the text pivots around position.
		BIT_FIELD bInvert:1;
		// 0 = default alignment 1 = left, 2 = center 3 = right
		// 0 is not set, the flag set in the lower 32 bit flags
		// is not needed any longer.... anything non zero
		// is that operation to apply.
		BIT_FIELD bAlign:2;
      /* format op indicates one of the enum FORMAT_OPS applies to this segment */
		BIT_FIELD format_op : 7;
	} flags;
	// if x,y are valid segment will have TF_POSFORMAT set...
	union {
		/* Coordinate information attached to a text segment. */
		/* Positioning specification of this text segment. with
		   basically 0 format options, position is used.
		   Position represents the distance from this segment to the
		   prior segment in count of tabs and spaces.
		   coords specifies an x,y coordinate location for the segment.
		   Usage of this union is dependant on <link text::format_info_tag::flags@1::format_op, format_op>. */
		struct {
         // Signed coordinate of this segment on a text display.  May be relative depending on format_op.
			int16_t x;
         // Signed coordinate of this segment on a text display.  May be relative depending on format_op.
			int16_t y;
		} coords;
		/* Defines the distance from the prior segment in count of tabs
		   and spaces (mostly count of spaces).                         */
		struct {
   // tabs preceed spaces....
			uint16_t tabs;
 // not sure what else to put with this...
			uint16_t spaces;
		} offset;
	} position;
} FORMAT, *PFORMAT;
 // special coordinate which is NO coordinate
#define IGNORE_CURSOR_POS -16384
/* test flag, format has position data */
#define TF_FORMATPOS (TF_FORMATABS|TF_FORMATREL|TF_FORMATEX)
/* these flags are used in PTEXT.flags member
 applications may use these flags to group expressions
 will affect the BuildLine but is not generated by library.
( TF_QUOTE, TF_SQUOTE, TF_BRACKET, TF_BRACE, TF_PAREN, and TF_TAG).
*/
enum TextFlags {
   // declared in program data.... do NOT release
 TF_STATIC    = 0x00000001,
   // double quoted string segment " "
 TF_QUOTE     = 0x00000002,
   // single quoted string ' '
 TF_SQUOTE    = 0x00000004,
   // bracketed expression []
 TF_BRACKET   = 0x00000008,
   // braced expression {}
 TF_BRACE     = 0x00000010,
   // parenthised expression ()
 TF_PAREN     = 0x00000020,
   // HTML tag like expression &lt;&gt;
 TF_TAG       = 0x00000040,
   // foreground is FORMAT_OP
 TF_FORMATEX  = 0x00000080,
   // x,y position used (relative)
 TF_FORMATREL = 0x00000100,
   // size field extually points at PTEXT
 TF_INDIRECT  = 0x00000200,
   // format position is x/y - else space count
 TF_FORMATABS = 0x00000800,
   // set during burst for last segment...
 TF_COMPLETE  = 0x00001000,
   // set for non-text variable
 TF_BINARY    = 0x00002000,
   // on release release indrect also...
 TF_DEEP      = 0x00004000,
   // set on first segment to send to omit lead \r\n
 TF_NORETURN  = 0x00008000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
// Low bound of value...
  TF_LOWER     = 0x00010000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
  // Upper bound of a value...
  TF_UPPER     = 0x00020000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
// boundry may be ON this value...
 TF_EQUAL     = 0x00040000,
   // this segment is not a permanent part (SubstToken)
 TF_TEMP      = 0x00080000,
  // this is something special do not treat as text indirect.
 TF_APPLICATION = 0x00100000,
};
//--------------------------------------------------------------------------
// flag combinatoin which represents actual data is present even with 0 size
// extended format operations (position, ops) are also considered data.
#define IS_DATA_FLAGS (TF_QUOTE|TF_SQUOTE|TF_BRACKET|TF_BRACE|                              TF_PAREN|TF_TAG|TF_FORMATEX|TF_FORMATABS|TF_FORMATREL)
#define DECLTEXTSZTYPE( name, size ) struct {    uint32_t flags;    struct text_segment_tag *Next, *Prior;    FORMAT format;    DECLDATA(data, size); } name
/* A macro to declare a structure which is the same physically
   as a PTEXT, (for declaring static buffers). Has to be cast to
   (PTEXT) is used. Is defined as a size, but no string content.
   Parameters
   name :  name of the variable to create
   size :  size of the static text element. (0 content)          */
#define DECLTEXTSZ( name, size ) DECLTEXTSZTYPE( name,(size) )	 = { TF_STATIC, NULL, NULL, {{1,1}} }
/* Defines an initializer block which can be used to satisfy a
   TEXT elemnt of a structure
   Parameters
   str :  string content of the TEXT
   Example
   <code lang="c++">
   TEXT something = DEFTEXT( "abc" );
   </code>                                                     */
#define DEFTEXT(str) {TF_STATIC,NULL,NULL,{{1,1}},{(sizeof(str)/sizeof(str[0]))-1,str}}
/* A macro to declare a structure which is the same physically
   as a PTEXT, (for declaring constant static strings
   basically). Has to be cast to (PTEXT) is used.
   Parameters
   name :   name of the variable to create
   value :  static string constant to initialize variable to.  */
#define DECLTEXT(name, str) static DECLTEXTSZTYPE( name, (sizeof(str)/sizeof(str[0])) ) = DEFTEXT(str)
/* Description
   A Text segment, it is based on DataBlock that has a length
   and an addtional region at the end of the structure which
   contains the text of the segment. Segments may have
   formatting attributes. Segments may be linked to other
   segments in a NEXTLINE/PRIORLINE. Segments may have indirect
   content, which may represent phrases. Sets of segments may
   represent sentence diagrams. A Pointer to a <link text::TEXT, TEXT>
   type.
   TEXT is a type I created to provide a variety of functions.
   One particular application was a common language processor,
   and I created the TEXT structure to store elements which are
   described by language. Sentences are words, and phases. A
   phrase is a set of words, but sometimes a word is a phrase.
   (sentence) = ( word ) ... (phrase ) ...
   (phrase) = (word)...
   hmm.. how to describe this.
   <code lang="c++">
   PTEXT phrase = NULL;
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   </code>
   <code>
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   </code>
   PTEXT segments point at other segments. A list of segments is
   a sentence. Segments can have information encoded on them
   that remove text from them. For instance, \< and \> tags
   might be removed around a phrase and stored as an attribute
   of the segment. A segment with such an attribute could be an
   indirect segment that points at a list of words which are the
   phrases in the tag.
   <code lang="c++">
   a map of two segments, and their content...
       (segment with TF_TAG) -\> (segment with TF_TAG)
             |                        |
             \+ - ("html")             + - (body) -\> (background="#000000")
   would actually expand to
      \<html\>\<body background="#000000"\>
   </code>
   See Also
   SegCreate
   burst
   TextParse
   SegAppend
   SegSubst
   SegSplit
   SegGrab
   SegDelete
   LineRelease
   BuildLine
   and also.....
   PVARTEXT                                                                  */
typedef struct text_segment_tag
{
	// then here I could overlap with pEnt .bshadow, bmacro, btext ?
   uint32_t flags;
	/* This points to the next segment in the sentence or phrase. NULL
	   if at the end of the line.                                      */
		struct text_segment_tag *Next;
	/* This points to the prior segment in the sentence or phrase. (NULL
	   if at the first segment)                                          */
		struct text_segment_tag *Prior;
	/* format is 64 bits.
      it's two 32 bit bitfields (position, expression)
	 valid if TF_FORMAT is set... */
	FORMAT format;
   /* A description of the data stored here.  It is compatible with a DATABLOCk.... */
   struct {
	   /* unsigned size; size is sometimes a pointer value...
                  this means bad thing when we change platforms... Or not, since we went to uintptr_t which is big enough for a pointer. */
		uintptr_t size;
		/* the data of the test segment
		 beginning of var data - this is created size+sizeof(TEXT) */
		   TEXTCHAR  data[1];
	} data;
} TEXT, *PTEXT;
//
// PTEXT DumpText( PTEXT somestring )
//    PTExT (single data segment with full description \r in text)
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  DumpText ( PTEXT text );
//SegCreateFromText( ".." );
// Burst, SegAppend, SegGrab
// segments are ment to be lines, the meaninful tag "TF_NORETURN" means it's part of the prior line.
//--------------------------------------------------------------------------
#define HAS_WHITESPACE(pText) ( pText && ( (pText)->format.position.offset.spaces || (pText)->format.position.offset.tabs ) )
/* A convenient macro to go from one segment in a line of text
   to the next segment.                                        */
#define NEXTLINE(line)   ((PTEXT)(((PTEXT)line)?(((PTEXT)line)->Next):(NULL)))
/* A convenient macro to go from one segment in a line of text
   to the prior segment.                                       */
#define PRIORLINE(line)  ((PTEXT)(((PTEXT)line)?(((PTEXT)line)->Prior):(NULL)))
/* Link one PTEXT segment to another. Sets one half of the links
   appropriate for usage.
   Example
   This example sets the prior pointer of 'word' to 'line'.
   <code>
   PTEXT line;
   PTEXT word;
   SETPRIORLINE( word, line );
   </code>                                                       */
#define SETPRIORLINE(line,p) ((line)?(((line)->Prior) = (PTEXT)(p)):0)
/* Link one PTEXT segment to another. Sets one half of the links
   appropriate for usage.
   Example
   This example sets the next pointer of 'line' to 'word'.
   <code lang="c#">
   PTEXT line;
   PTEXT word;
   SETNEXTLINE( line, word );
   </code>                                                       */
#define SETNEXTLINE(line,p)  ((line)?(((line)->Next ) = (PTEXT)(p)):0)
/* Sets a pointer to PTEXT to the first text segment in the
   list.                                                    */
#define SetStart(line)     for(; line && PRIORLINE(line);line=PRIORLINE(line))
/* Sets a PTEXT to the last segment that it points to.
   Parameters
   line :  segment in the line to move to the end of.
   Remarks
   Updates the variable passed to point to the last segment. */
#define SetEnd(line)      for(; line && NEXTLINE(line); line=NEXTLINE(line))
// might also check to see if pseg is an indirect - setting this size would be BAD
#define SetTextSize(pseg, sz ) ((pseg)?((pseg)->data.size = (sz )):0)
/* gets the indect segment content (if any) from a PTEXT
   segment.                                              */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GetIndirect(PTEXT segment );
/* Get the format flags of a PTEXT.
                                    */
TYPELIB_PROC  uint32_t TYPELIB_CALLTYPE  GetTextFlags( PTEXT segment );
/* Gets the text segment length. */
TYPELIB_PROC  size_t TYPELIB_CALLTYPE  GetTextSize( PTEXT segment );
/* Gets the text of a PTEXT segment. (convert to a CTEXTSTR)
   Parameters
   segment :  segment to get the string content from         */
TYPELIB_PROC  TEXTSTR TYPELIB_CALLTYPE  GetText( PTEXT segment );
// by registering for TF_APPLICTION is set on the segment
// and flags anded with the segment flags match, the
// function is called.... the result is the actual
// segment of this - since a TF_APPLICATION is also
// TF_INDIRECT - using the size to point to some application
// defined structure instead of a PTEXT structure.
TYPELIB_PROC  void TYPELIB_CALLTYPE  RegisterTextExtension ( uint32_t flags, PTEXT(CPROC*)(uintptr_t,POINTER), uintptr_t );
// similar to GetIndirect - but results in the literal pointer
// instead of the text that the application may have registered to result with.
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE  GetApplicationPointer ( PTEXT text );
/* Used to set the content of a segment to some application
   defined value. This allows a users application to store
   chunks of data in lists of text. These external chunks are
   handled like other words.
   Parameters
   text :  this is the text segment to set application data on
   p :     this is a pointer to application data               */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetApplicationPointer ( PTEXT text, POINTER p);
/* Set segment's indirect data.
   Parameters
   segment :  pointer to a TEXT segment to set the indirect content
              of.
   data :     pointer to a PTEXT to be referenced indirectly.       */
#define SetIndirect(Seg,Where)  ( (Seg)->data.size = ((uintptr_t)(Where)-(uintptr_t)NULL) )
		/* these return 1 for more(l1&gt;l2) -1 for (l1&lt;l2) and 0 for match.
       */
TYPELIB_PROC  int TYPELIB_CALLTYPE  SameText ( PTEXT l1, PTEXT l2 );
/* A test if one PTEXT is similar to another PTEXT.
   Parameters
   l1 :  PTEXT segment one
   l2 :  PTEXT segment two
   Return Value List
   \<0 :  l1 with case insensitive comparison is less then l2
   0 :    Texts compare case insenitive match
   \>0 :  l1 with case insensitive comparison is more than l2 */
TYPELIB_PROC  int TYPELIB_CALLTYPE  LikeText ( PTEXT l1, PTEXT l2 );
/* Compares if text is like a C string. Case Sensitive.
   <b>Returns</b>
   TRUE if they are alike.
   FALSE if they are different.
   <b>Parameters</b>                                    */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextIs  ( PTEXT pText, CTEXTSTR text );
/* Compares if text is like a C string. Case insensitive (like).
   Returns
   TRUE if they are alike.
   FALSE if they are different.
   Parameters
   pText :  PTEXT segment to compare
   text :   C string buffer to compare against                   */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextLike  ( PTEXT pText, CTEXTSTR text );
/* Compares if text is like a C string. Case insensitive (like). Uses min string length for max match.
   Returns
   TRUE if they are similar (both case insensitive using shorter of the strings for maxlen).
   FALSE if they are different.
   Parameters
   pText :  PTEXT segment to compare
   text :   C string buffer to compare against                   */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextSimilar  ( PTEXT pText, CTEXTSTR text );
//#define SameText( l1, l2 )  ( strcmp( GetText(l1), GetText(l2) ) )
#define textmin(a,b) ( (((a)>0)&&((b)>0))?(((a)<(b))?(a):(b)):(((a)>0)?(a):((b)>0)?(b):0) )
#ifdef __LINUX__
/* windows went with stricmp() and strnicmp(), whereas linux
 went with strcasecmp() and strncasecmp()                  */
#  ifdef UNICODE
#    ifndef NO_UNICODE_C
#      define strnicmp strncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#      define stricmp strcasecmp
#    else
#      define strnicmp wcsncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#      define stricmp wcscasecmp
#    endif
#  else
#    define strnicmp strncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#     define stricmp strcasecmp
#  endif
#endif
/* Copy segment formatting to another segment... */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SegCopyFormat( PTEXT to_this, PTEXT copy_this );
/* Create a text segment of sepecified size; inclues one more character for NUL terminator */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateEx( size_t nSize DBG_PASS );
/* Create a PTEXT with specified number of character capacity.
   Example
   <code lang="c#">
   PTEXT text = SegCreate( 10 );
   </code>                                                     */
#define SegCreate(s) SegCreateEx(s DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromText> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromTextEx( CTEXTSTR text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromText( WIDE("Around the world in a day.") );
   </code>                                                         */
#define SegCreateFromText(t) SegCreateFromTextEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromCharLenEx( const char *text, size_t len DBG_PASS );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromCharEx( const char *text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromChar( "Around the world in a day." );
   </code>                                                         */
#define SegCreateFromChar(t) SegCreateFromCharEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
#define SegCreateFromCharLen(t,len) SegCreateFromCharLenEx((t),(len) DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromWideLenEx( const wchar_t *text, size_t len DBG_PASS );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromWideEx( const wchar_t *text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromWideLen( L"Around the world in a day.", 26 );
   </code>                                                         */
#define SegCreateFromWideLen(t,len) SegCreateFromWideLenEx((t),(len) DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
#define SegCreateFromWide(t) SegCreateFromWideEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateIndirect> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateIndirectEx( PTEXT pText DBG_PASS );
/* Creates a text segment that refers to the parameter
   indirectly. The new segment is not really a clone, but a
   reference of the original PTEXT.
   Example
   <code lang="c#">
   PTEXT phrase = SegCreateIndirect( SegAppend( SegCreateFromText( "Hello" )
                                              , SegCreateFromText( "World" ) ) );
   </code>
   The resulting phrase is a single segment with no prior or
   next, but its content is "HelloWorld" if it was passed to
   buildline... it's go the content of the two text segments
   linked together, but not in its buffer. It is actually a 0
   length buffer for a TEXT segment.
                                                                                  */
#define SegCreateIndirect(t) SegCreateIndirectEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegDuplicate> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegDuplicateEx( PTEXT pText DBG_PASS);
/* This duplicates a specific segment. It duplicates the first
   segment of a string. If the segment has indirect data, then
   the first segment of the indirect data is duplicated.       */
#define SegDuplicate(pt) SegDuplicateEx( pt DBG_SRC )
/* Duplicates a linked list of segments.
   Duplicates the structure of a line. The resulting line is an
   exact duplicate of the input line. All segments linked in
   exactly the same sorts of ways.
   Parameters
   line :  list of segments to duplicate                        */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  LineDuplicateEx( PTEXT pText DBG_PASS );
/* <combine sack::containers::text::LineDuplicateEx@PTEXT pText>
   \ \                                                           */
#define LineDuplicate(pt) LineDuplicateEx(pt DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link TextDuplicate> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  TextDuplicateEx( PTEXT pText, int bSingle DBG_PASS );
/* Duplicate the whole string of text to another string with
   exactly the same content.                                 */
#define TextDuplicate(pt,s) TextDuplicateEx(pt,s DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromInt> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromIntEx( int value DBG_PASS );
/* Creates a text segment from a 64 bit integer.
   Example
   <code>
   PTEXT number = SegCreateFromInt( 3314 );
   </code>                                       */
#define SegCreateFromInt(v) SegCreateFromIntEx( v DBG_SRC )
/* Converts an integer to a PTEXT segment.
   Parameters
   _64bit_value :  integer value to convert to a PTEXT segment. */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFrom_64Ex( int64_t value DBG_PASS );
/* Create a text segment from a uint64_t bit value. (long long int) */
#define SegCreateFrom_64(v) SegCreateFrom_64Ex( v DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromFloat> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromFloatEx( float value DBG_PASS );
/* Creates a text segment from a floating point value. Probably
   uses something like '%g' to format output. Fairly limited.
   Example
   <code lang="c++">
   PTEXT short_PI = SegCreateFromFloat( 3.14 );
   </code>                                                      */
#define SegCreateFromFloat(v) SegCreateFromFloatEx( v DBG_SRC )
/* Appends a list of segments to an existing list of segments. This
   assumes that the additional segment is referncing the head of
   the segment list.
   Parameters
   source :  source list to add to
   other :   additional segments to add to source.                  */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegAppend   ( PTEXT source, PTEXT other );
/* Inserts a segment before another segment.
   Parameters
   what :    what to insert into the list
   before :  insert the segments before this segment
   Returns
   The parameter 'what'.                             */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegInsert   ( PTEXT what, PTEXT before );
/* This expands a segment by a number of characters.
   Parameters
   PTEXT :  the segment to expand
   int :    count of character to expand by
   Returns
   A pointer to a new segment that is bigger, but has the same
   existing content.                                           */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegExpandEx (PTEXT source, INDEX nSize DBG_PASS );
/* <combine sack::containers::text::SegExpandEx@PTEXT@INDEX nSize>
   \ \                                                             */
#define SegExpand(s,n) SegExpandEx( s,n DBG_SRC )
/* Release a linked list of PTEXT segments.
   Parameters
   segments :  a segment in a list of segments to delete, first
               this routine goes to the start of the segment
               list, and then deletes all segments in the list.
   DBG_PASS :  debug file and line information                  */
TYPELIB_PROC  void TYPELIB_CALLTYPE   LineReleaseEx (PTEXT line DBG_PASS );
/* Release a line of text.
   A line may be a single segment.
   This is the proper way to dispose of PTEXT segments.
   Any segment in the line may be passed, the first segment is
   found, and then all segments in the line are deleted.       */
#define LineRelease(l) LineReleaseEx(l DBG_SRC )
/* \ \
   <b>See Also</b>
   <link DBG_PASS>
   <link SegRelease> */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SegReleaseEx( PTEXT seg DBG_PASS );
/* Release a single segment. UNSAFE. Does not respect that it is
   in a list.
   See Also
   <link LineRelease>                                            */
#define SegRelease(l) SegReleaseEx(l DBG_SRC )
/* Adds a part of input to the segment list of output.
   Parameters
   output\ :   the segment list to append to.
   input\ :    the input buffer to append from
   offset :    starting offset in 'input' to start from
   length :    how much from 'offset' in input to append as a new
               segment to output.
   DBG_PASS :  \file and line debugging information               */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegConcatEx   (PTEXT output,PTEXT input,int32_t offset,size_t length DBG_PASS);
/* <combine sack::containers::text::SegConcatEx@PTEXT@PTEXT@int32_t@size_t length>
   looks like it takes a peice of one segment and appends it to
   another....
   Needs More research to document correctly and exemplify.                     */
#define SegConcat(out,in,ofs,len) SegConcatEx(out,in,ofs,len DBG_SRC)
/* Removes a segment from a list of segments. Links what was
   prior and what was after together. Sets both next and prior
   of the segment unlinked to NULL.
   Example
   <code lang="c++">
   SegUnlink( segment );
   </code>
   Returns
   The segment passed.                                         */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegUnlink   (PTEXT segment);
/* Breaks a list of PTEXT segments at the specified segment and
   \returns a segment that was before the specified.
   Parameters
   segment :  segment to break the chain at
   Returns
   Any existing segment before the segment to break at.
   Example
   <code lang="c++">
   {
      PTEXT segs;
      PTEXT breakat;
      PTEXT leftover;
		&#47;* ... segs gets populated with some segments ... *&#47;
      breakat = NEXTLINE( segs );
   </code>
   <code>
      breakat = NEXTLINE( segs );
      leftover = segbreak( breakat );
      // now breakat begins a new chain of segments
      // leftover is the segment that was just before breakat
      SegStart( leftover );  // leftover would be equal to segs...
   }
   </code>                                                         */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegBreak    (PTEXT segment);
/* Removes a segment from a list. It also releases the segment.
    Example
    <code lang="c#">
    SegDelete( segment );
    </code>
    the result is NULL;                                          */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegDelete   (PTEXT segment);
/* removes segment from any list it might be in, returns
   segment.                                              */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegGrab     (PTEXT segment);
/* Substitute one PTEXT segment for another in a list of PTEXT
   segments.
   Parameters
   _this :  This is the segment to remove
   that :   This is the segment to subustitute with. This may be
            a list of segments, and it is linked in from the
            first segment to the prior to '_this' and the last to
            the next after '_this'
   Returns
   \Returns the '_this' that was substituted.                     */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegSubst    ( PTEXT _this, PTEXT that );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegSplit> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegSplitEx( PTEXT *pLine, INDEX nPos DBG_PASS);
/* Split a PTEXT segment.
   Example
   \ \
   <code lang="c++">
   PTEXT result = SegSplit( &amp;old_string, 5 );
   </code>
   Returns
   PTEXT new_string;
   Remarks
   the old string segment is split at the position indicated. The
   pointer to the old segment is modified to point to now two
   segments linked dynamically, each part of the segment after
   the split. If the index is beyond the bounds of the segment,
   the segment remains unmodified.                                */
#define SegSplit(line,pos) SegSplitEx( line, pos DBG_SRC )
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  FlattenLine ( PTEXT pLine );
/* Create a highest precision signed integer from a PTEXT. */
TYPELIB_PROC  int64_t TYPELIB_CALLTYPE  IntCreateFromSeg( PTEXT pText );
/* Converts a text to the longest precision signed integer
   value.                                                  */
TYPELIB_PROC  int64_t TYPELIB_CALLTYPE  IntCreateFromText( CTEXTSTR p );
/* Create a high precision floating point value from PTEXT
   segment.                                                */
TYPELIB_PROC  double TYPELIB_CALLTYPE  FloatCreateFromSeg( PTEXT pText );
/* Create a high precision floating point value from text
   string.                                                */
TYPELIB_PROC  double TYPELIB_CALLTYPE  FloatCreateFromText( CTEXTSTR p, CTEXTSTR *pp );
//
// IsSegAnyNumber returns 0 if no, 1 if is int, 2 if is float
//   if pfNumber or piNumber are available then the text pointer
//   will be updated to the next segment after what was used to resolve
//   the number.
//   bUseAllSegs is for testing pTexts which are indirect, such that
//      only all segments within the indirect segment will result valid.
//   pfNumber and piNumber may be passed as NULL, and the function can still
// be used to determine ifnumber
//   the number resulting in the values pointed to will be filled in
//    with (*pfNumber)=FltCreateFromSeg(p) (or Int as appropriate)
//
//#define IsNumber(p) IsSegAnyNumberEx( &(p), NULL, NULL, NULL, 0 )
#define IsIntNumber(p, pint) IsSegAnyNumberEx( &(p), NULL, pint, NULL, 0 )
/* Tests a PTEXT segment to see if it might be a floating point
   number.                                                      */
#define IsFltNumber(p, pflt) IsSegAnyNumberEx( &(p), pflt, NULL, NULL, 0 )
/* Tests the content of a PTEXT to see if it might be a number.
   Parameters
   ppText :       pointer to PTEXT to check
   pfNumber :     pointer to double to get result of number it's
                  a float
   piNumber :     pointer to a signed 64 bit value to get the
                  \result if it's not a float.
   pbIsInt :      point to a integer \- receives boolean result
                  if the segment was an integer is TRUE else it's
                  a double.
   bUseAllSegs :  if TRUE, use all the segments starting with the
                  first, and update the pointer to the next
                  stgment. If false, use only the first segment. if
                  uses all segments, it must also use ALL
                  segments to get the number.
   Returns
   0 if not a number or fails.
   1 if a valid conversion took place.                              */
TYPELIB_PROC  int TYPELIB_CALLTYPE  IsSegAnyNumberEx ( PTEXT *ppText, double *pfNumber, int64_t *piNumber, int *pbIsInt, int bUseAllSegs );
/* <combine sack::containers::text::IsSegAnyNumberEx@PTEXT *@double *@int64_t *@int *@int>
   \ \                                                                                  */
#define IsSegAnyNumber(pptext, pfNum, piNum, pbIsInt) IsSegAnyNumberEx( pptext, pfNum, piNum, pbIsInt, 0 )
/* \Returns the amount of space required to store this segment,
   and all indirect statements it contains.
   Parameters
   segment :   segment to measure
   position :  starting position in the segment to measure from
   nTabSize :  how big tabs are supposed to be
   tabs :      list of tab positions (for arbitrary tab
               positioning\- table column alignment?)           */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentSpaceEx ( PTEXT segment, INDEX position, int nTabs, INDEX *tabs);
/* \Returns the amount of space required to store this segment,
   and all indirect statements it contains.
   Parameters
   segment :   segment to measure
   position :  starting position in the segment to measure
               from
   nTabSize :  how big tabs are supposed to be                  */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentSpace ( PTEXT segment, INDEX position, int nTabSize );
/* Simlar to getsegment space... */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentLengthEx ( PTEXT segment, INDEX position, int nTabs, INDEX *tabs );
/* \Returns the length of a single PTEXT segment.
   Parameters
   segment :   segment to measure
   position :  string position in the string to measure
   nTabSize :  how many characters a tab is supposed to be. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentLength ( PTEXT segment, INDEX position, int nTabSize );
/* Measure the length of a list of segments (combined length of
   all linked segments)                                         */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  LineLengthExEx( PTEXT pt, LOGICAL bSingle, int nTabsize, PTEXT pEOL );
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  LineLengthExx( PTEXT pt, LOGICAL bSingle,PTEXT pEOL );
/* <combine sack::containers::text::LineLengthExEx@PTEXT@LOGICAL@int@PTEXT>
   \ \                                                                      */
#define LineLengthExx(pt,single,eol) LineLengthExEx( pt,single,8,eol)
/* \ \
   Parameters
   Text segment :  PTEXT line or segment to get the length of
   single :        boolean, if set then only a single segment is
                   measured, otherwise all segments from this to
                   the end are measured.                         */
#define LineLengthEx(pt,single) LineLengthExx( pt,single,NULL)
/* Computes the length of characters in a line, if all segments
   in the line are flattened into a single word.                */
#define LineLength(pt) LineLengthEx( pt, FALSE )
/* Collapses an indirect segment or a while list of segments
   into a single segment with content expanded. When passed to
   things like TextParse and Burst, segments have their
   positioning encoded to counters for tabs and spaces; the
   segment itself contains only text without whitespace. Buildline
   expands these segments into their plain text representation.
   Parameters
   pt :        pointer to a PTEXT segment.
   bSingle :   if TRUE, build only the first segment. If the
               segment is indirect, builds entire content of
               indirect.
   nTabsize :  how wide tabs are. When written into a line, tabs
               are written as spaces. (maybe if 0, tabs are
               emitted directly?)
   pEOL :      the segment to use to represent an end of line. Often
               this is a SegCreate(0) segment.                       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  BuildLineExEx( PTEXT pt, LOGICAL bSingle, int nTabsize, PTEXT pEOL DBG_PASS );
/* Collapses an indirect segment or a while list of segments
into a single segment with content expanded. When passed to
things like TextParse and Burst, segments have their
positioning encoded to counters for tabs and spaces; the
segment itself contains only text without whitespace. Buildline
expands these segments into their plain text representation.
Parameters
pt :        pointer to a PTEXT segment.
bSingle :   if TRUE, build only the first segment. If the
segment is indirect, builds entire content of
indirect.
pEOL :      the segment to use to represent an end of line. Often
this is a SegCreate(0) segment.                       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  BuildLineExx( PTEXT pt, LOGICAL bSingle, PTEXT pEOL DBG_PASS );
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
\ \                                                                          */
#define BuildLineExx(from,single,eol) BuildLineExEx( from,single,8,NULL DBG_SRC )
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
   \ \                                                                          */
#define BuildLineEx(from,single) BuildLineExEx( from,single,8,NULL DBG_SRC )
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
   \ \
    Flattens all segments in a line to a single segment result.
*/
#define BuildLine(from) BuildLineExEx( from, FALSE,8,NULL DBG_SRC )
//
// text parse - more generic flavor of burst.
//
//static CTEXTSTR normal_punctuation=WIDE("\'\"\\({[<>]}):@%/,;!?=*&$^~#`");
// filter_to_space WIDE(" \t")
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  TextParse ( PTEXT input, CTEXTSTR punctuation, CTEXTSTR filter_tospace, int bTabs, int bSpaces  DBG_PASS );
/* normal_punctuation=WIDE("'"\\({[\<\>]}):@%/,;!?=*&amp;$^~#`");
   Process a line of PTEXT into another line of PTEXT, but with
   words parsed as appropriate for common language.
   Parameters
   input\ :  pointer to a list of PTEXT segments to parse.
   Remarks
   Burst is a simple method of breaking a sentence into its word
   and phrase parts. It collapses space and tabs before words
   into the word. Any space representation is space preceeding
   the word. Sentences are also broken on any punctuation.
   "({[\<\>]})'";;.,/?\\!@#$%^&amp;*=" for instances. + and - are
   treated specially if they prefix numbers, otherwise they are
   also punctuation. Also groups of '.' like '...' are kept
   together. if the '.' is in a number, it is stored as part of
   the number. Otherwise a '.' used in an abbreviation like P.S.
   will be a '.' with 0 spaces followed by a segment also with 0
   spaces. (unless it's the lsat one)
   so initials are encoded badly.
   Bugs
   There is an exploit in the parser such that . followed by a
   number will cause fail to break into seperate words. This is
   used by configuration scripts to write binary blocks, and
   read them back in, having the block parsed into a segment
   correctly.
   See Also
   <link sack::containers::text::TextParse@PTEXT@CTEXTSTR@CTEXTSTR@int@int bSpaces, TextParse> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  burstEx( PTEXT input DBG_PASS);
/* <combine sack::containers::text::burstEx@PTEXT input>
   \ \                                                   */
#define burst( input ) burstEx( (input) DBG_SRC )
/* Compares a couple lists of text segments.
   Parameters
   pt1 :      pointer to a phrase
   single1 :  use only the first word, not the whole phrase
   pt2 :      pointer to a phrase
   single2 :  use only the first segment, not the whole phrase
   bExact :   if FALSE, match case insensitive, otherwise match
              exact case.                                       */
TYPELIB_PROC  int TYPELIB_CALLTYPE  CompareStrings( PTEXT pt1, int single1
                            , PTEXT pt2, int single2
                            , int bExact );
/* This removes indirect segments, replacing them with their
   indirect content.
   Parameters
   pLine :  pointer to a PTEXT segment list to flatten.      */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  FlattenLine ( PTEXT pLine );
/* Steps through a linked list of segments, just a convenient
   for loop wrapper.                                          */
#define FORALLTEXT(start,var)  for(var=start;var; var=NEXTLINE(var))
/* returns number of characters filled into output.  Output needs to be at maximum 6 chars */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF8( char *output, TEXTRUNE rune );
/* returns number of characters filled into output.  Output needs to be at maximum 6 chars;  if overlong is set
   characters are deliberatly padded to be overlong */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF8Ex( char *output, TEXTRUNE rune, LOGICAL overlong );
/* returns number of wchar filled into output.  Output needs to be at maximum 2 wchar. */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF16( wchar_t *output, TEXTRUNE rune );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfChar( const char **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharIndexed( const char *from, size_t *index, size_t length );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfChar( const char *start, const char **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharIndexed( const char *from, size_t *index );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharW( const wchar_t **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharIndexedW( const wchar_t *from, size_t *index );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharW( const wchar_t *start, const wchar_t **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharIndexedW( const wchar_t *from, size_t *index );
TYPELIB_PROC size_t TYPELIB_CALLTYPE GetDisplayableCharacterCount( const char *string, size_t max_bytes );
TYPELIB_PROC CTEXTSTR TYPELIB_CALLTYPE GetDisplayableCharactersAtCount( const char *string, size_t character_index );
TYPELIB_PROC size_t TYPELIB_CALLTYPE  GetDisplayableCharacterBytes( const char *string, size_t character_count );
/* You Must Deallocate the result */
TYPELIB_PROC  char * TYPELIB_CALLTYPE  WcharConvertExx ( const wchar_t *wch, size_t len DBG_PASS );
/* You Must Deallocate the result */
TYPELIB_PROC  char * TYPELIB_CALLTYPE  WcharConvertEx ( const wchar_t *wch DBG_PASS );
/* <combine sack::containers::text::WcharConvertExx@wchar_t *@size_t len>
   \ \                                                                    */
#define WcharConvertLen(s,len) WcharConvertExx(s, len DBG_SRC )
/* <combine sack::containers::text::WcharConvertExx@wchar_t *@size_t len>
   \ \                                                                    */
#define WcharConvert(s) WcharConvertEx(s DBG_SRC )
/* You Must Deallocate the result */
TYPELIB_PROC wchar_t * TYPELIB_CALLTYPE CharWConvertExx ( const char *wch, size_t len DBG_PASS );
/* Convert wchar_t strings to char strings.
   Parameters
   string :    wchar_t string to convert
   DBG_PASS :  debug file and line information
   Returns
   A char * string. This string must be Release()'ed or
   Deallocate()'ed by the user.                         */
TYPELIB_PROC wchar_t * TYPELIB_CALLTYPE CharWConvertEx ( const char *wch DBG_PASS );
/* <combine sack::containers::text::CharWConvertExx@char *@size_t len>
   \ \                                                                 */
#define CharWConvertLen(s,len) CharWConvertExx(s,len DBG_SRC )
/* <combine sack::containers::text::CharWConvertExx@char *@size_t len>
   \ \                                                                 */
#define CharWConvert(s) CharWConvertEx(s DBG_SRC )
//--------------------------------------------------------------------------
/* This is a string collector type.  It has an interface to be able to vtprintf( vartext, "format string", ... ); which appends the specified string to the collected text.
  Example
   PVARTEXT pvt = VarTextCreate();
   vtprintf( pvt, "hello world!" );
   {
      PTEXT text = VarTextGet( pvt );
	  printf( "Text is : %s(%d)", GetText( text ), GetTextSize( text ) );
	  LineRelease( text );
   }
   VarTextDestroy( &pvt );
   */
typedef struct vartext_tag *PVARTEXT;
/* Creates a variable text collector. Allows specification of
   initial size and amount to expand by. SQL Command line sample
   utility uses this and allocates like 10,000 initial and sets
   expand as 40,000, because it expects to build very large
   strings, and expansion of 32 at a time is ludicrous; if the
   space required is more than the expansion factor, then it is
   expanded by the amount required plus the expansion factor.
   Parameters
   initial :   amount of initial buffer
   exand_by :  how much to expand the buffer by when more room
               is needed
   DBG_PASS :  debug file and line parameters.                   */
TYPELIB_PROC  PVARTEXT TYPELIB_CALLTYPE  VarTextCreateExEx ( uint32_t initial, uint32_t expand DBG_PASS );
/* <combine sack::containers::text::VarTextCreateExEx@uint32_t@uint32_t expand>
   \ \                                                                */
#define VarTextCreateExx(i,e) VarTextCreateExEx(i,e DBG_SRC )
/* <combine sack::containers::text::VarTextCreateExEx@uint32_t@uint32_t expand>
   Creates a variable text collector. Default initial size and
   expansion is 0 and 32.
                                                                      */
TYPELIB_PROC  PVARTEXT TYPELIB_CALLTYPE  VarTextCreateEx ( DBG_VOIDPASS );
/* The simplest, most general way to create a PVARTEXT
   collector. The most extended vartext creator allows
   specification of how long the initial buffer is, and how much
   the buffer expands by when required. This was added to
   optimize building HUGE SQL queries, working withing 100k
   buffers that expanded by 50k at a time was a lot less
   operations than expanding 32 bytes or something at a time.    */
#define VarTextCreate() VarTextCreateEx( DBG_VOIDSRC )
/* Empties and destroys all resources associated with the
   variable text collector.
   Parameters
   pvt * :     address of a PVARTEXT reference to destroy. Sets
               the pointer to NULL when it's destroyed.
   DBG_PASS :  debugging file and line parameters
   Example
   <code lang="c++">
   {
      PVARTEXT pvt = VarTextCreate();
      VarTextDestroy( &amp;pvt );
   }
   void Function( int something DBG_PASS )
   {
      pvt = VarTextCreateEx( DBG_RELAY );
      VarTextDestroyEx( &amp;pvt DBG_RELAY );
   }
   </code>
   C++ Syntax
   \ \                                                          */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextDestroyEx ( PVARTEXT* DBG_PASS );
/* Destroy a VarText collector. */
#define VarTextDestroy(pvt) VarTextDestroyEx( pvt DBG_SRC )
/* \Internal function - used to initialize a VARTEXT structure. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextInitEx( PVARTEXT pvt DBG_PASS);
/* Probably should not be exported. Initializes a VARTEXT
   structure to prepare it for subsequent VarText operations. */
#define VarTextInit(pvt) VarTextInitEx( (pvt) DBG_SRC )
/* Empties a PVARTEXT structure.
   Parameters
   pvt :  PVARTEXT to empty.     */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextEmptyEx( PVARTEXT pvt DBG_PASS);
/* <combine sack::containers::text::VarTextEmptyEx@PVARTEXT pvt>
   \ \                                                           */
#define VarTextEmpty(pvt) VarTextEmptyEx( (pvt) DBG_SRC )
/* Add a single character to a vartext collector.
   Note
   \ \
   Parameters
   pvt :       PVARTEXT to add character to
   c :         character to add
   DBG_PASS :  optional debug information         */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddCharacterEx( PVARTEXT pvt, TEXTCHAR c DBG_PASS );
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddRuneEx( PVARTEXT pvt, TEXTRUNE c, LOGICAL overlong DBG_PASS );
/* Adds a single character to a PVARTEXT collector.
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddCharacter( pvt, 'a' );
   </code>                                          */
#define VarTextAddCharacter(pvt,c) VarTextAddCharacterEx( (pvt),(c) DBG_SRC )
/* Adds a single rune to a PVARTEXT collector. (may be multiple characters convert to UTF8)
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddRune( pvt, 'a' );
   </code>                                          */
#define VarTextAddRune(pvt,c) VarTextAddRuneEx( (pvt),(c), FALSE DBG_SRC )
/* Adds a length of data to the vartext. This allows strings
   with nuls included to be added.
   Parameters
   pvt :       PVARTEXT to add data to
   block :     pointer to data to add
   size :      length of data block to add
	DBG_PASS :  optional file and line parameters             */
#define VARTEXT_ADD_DATA_NULTERM ((size_t)0xFF000000)
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddDataEx( PVARTEXT pvt, CTEXTSTR block, size_t length DBG_PASS );
/* Adds a single character to a PVARTEXT collector.
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddData( pvt, "test one", 8 );
   </code>                                          */
#define VarTextAddData(pvt,block,length) VarTextAddDataEx( (pvt),(block),(length) DBG_SRC )
/* Commits the currently collected text to segment, and adds the
   segment to the internal line accumulator.
		 returns true if any data was added...
       move any collected text to commit... */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  VarTextEndEx( PVARTEXT pvt DBG_PASS );
/* <combine sack::containers::text::VarTextEndEx@PVARTEXT pvt>
   \ \                                                         */
#define VarTextEnd(pvt) VarTextEndEx( (pvt) DBG_SRC )
/* Gets the length of the current collection in the VARTEXT.
   Parameters
   pvt :  PVARTEXT collector to get the length.              */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  VarTextLength( PVARTEXT pvt );
/* Gets the text segment built in the VarText. The PVARTEXT is
   set to empty. Clears the collector.
   Parameters
   pvt :  PVARTEXT to get text from.                           */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  VarTextGetEx( PVARTEXT pvt DBG_PASS );
/* <combine sack::containers::text::VarTextGetEx@PVARTEXT pvt>
   \ \                                                         */
#define VarTextGet(pvt) VarTextGetEx( (pvt) DBG_SRC )
/* Used to look at the vartext collector and get the current
   collection. Does not clear the collector.
   Parameters
   pvt :       PVARTEXT collector to peek at
   DBG_PASS :  debugging file and line parameters
   Return Value List
   NULL :      No data
   not NULL :  text segment which is in the collector.       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  VarTextPeekEx ( PVARTEXT pvt DBG_PASS );
/* \Returns the PTEXT that is currently in a PVARTEXT. It does
   not alter the contents of the PVARTEXT. Do not LineRelease
   this peeked value.                                          */
#define VarTextPeek(pvt) VarTextPeekEx( (pvt) DBG_SRC )
/* Increases the internal storage size of the variable text
   collector.
   Parameters
   pvt :       the var text collector to expand
   amount :    amount of size to expand the collector
   DBG_PASS :  debugging file and line parameters           */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextExpandEx( PVARTEXT pvt, INDEX size DBG_PASS );
/* Add a specified number of characters to the amount of space
   in the VARTEXT collector.                                   */
#define VarTextExpand(pvt, sz) VarTextExpandEx( (pvt), (sz) DBG_SRC )
//TYPELIB_PROC  int vtprintfEx( PVARTEXT pvt DBG_PASS TYPELIB_CALLTYPE  CTEXTSTR format, ... ;
// note - don't include format - MUST have at least one parameter passed to ...
//#define vtprintf(pvt, ...) vtprintfEx( (pvt) DBG_SRC, __VA_ARGS__ )
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  vtprintfEx( PVARTEXT pvt, CTEXTSTR format, ... );
/* <combine sack::containers::text::vtprintfEx@PVARTEXT@CTEXTSTR@...>
   Note                                                               */
#define vtprintf vtprintfEx
/* variable argument VARTEXT printf. Is passed a PVARTEXT to
   collect the formatted output using printf sort of formatting. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  vvtprintf( PVARTEXT pvt, CTEXTSTR format, va_list args );
/* encode binary buffer into base64 encoding.
   outsize is updated with the length of the buffer.
 */
TYPELIB_PROC  TEXTCHAR * TYPELIB_CALLTYPE  EncodeBase64Ex( uint8_t* buf, size_t length, size_t *outsize, const char *encoding );
/* decode base64 buffer into binary buffer
   outsize is updated with the length of the buffer.
   result should be Release()'d
 */
TYPELIB_PROC  uint8_t * TYPELIB_CALLTYPE  DecodeBase64Ex( char* buf, size_t length, size_t *outsize, const char *encoding );
/* xor a base64 encoded string over a utf8 string, keeping the utf8 characters in the same length...
   although technically this can result in invalid character encoding where upper bits get zeroed
   result should be Release()'d
*/
TYPELIB_PROC  char * TYPELIB_CALLTYPE  u8xor( const char *a, size_t alen, const char *b, size_t blen, int *ofs );
/* xor two base64 encoded strings, resulting in a base64 string
   result should be Release()'d
*/
TYPELIB_PROC  char * TYPELIB_CALLTYPE  b64xor( const char *a, const char *b );
//--------------------------------------------------------------------------
// extended command entry stuff... handles editing buffers with insert/overwrite/copy/paste/etc...
typedef struct user_input_buffer_tag {
	// -------------------- custom cmd buffer extension
  // position counter for pulling history
	INDEX nHistory;
  // a link queue which contains the prior lines of text entered for commands.
	PLINKQUEUE InputHistory;
 // set to TRUE when nHistory has wrapped...
	int   bRecallBegin;
   /* A exchange-lock variable for controlling access to the
      \history (so things aren't being read from it while it is
      scrolling old data out).                                  */
	uint32_t   CollectionBufferLock;
  // used to store index.. for insert type operations...
	INDEX CollectionIndex;
 // flag for whether we are inserting or overwriting
	int   CollectionInsert;
 // flag for whether we are inserting or overwriting
	int   storeCR;
 // used to store partial from GatherLine
	PTEXT CollectionBuffer;
 // called when a buffer is complete.
	void (CPROC*CollectedEvent)( uintptr_t psv, PTEXT text );
  // passed to the event callback when a line is completed
	uintptr_t psvCollectedEvent;
} USER_INPUT_BUFFER, *PUSER_INPUT_BUFFER;
/* Creates a buffer structure which behaves like the command
   line command recall queue.
                                                             */
TYPELIB_PROC  PUSER_INPUT_BUFFER TYPELIB_CALLTYPE  CreateUserInputBuffer ( void );
/* Destroy a created user input buffer. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DestroyUserInputBuffer ( PUSER_INPUT_BUFFER *pci );
// negative with SEEK_SET is SEEK_END -nPos
enum CommandPositionOps {
	// defined that the x,y position in the segment should be used for absolute positioning.
   // can also be SEEK_SET
 COMMAND_POS_SET = 0,
 // defined that the x,y position in the segment should be used for relative positioning.
 // can also be SEEK_CUR
 COMMAND_POS_CUR = 1
};
/* Updates the current input position, for things like input,
   etc. Some external process indicates where in the line to set
   the cursor position.                                          */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  SetUserInputPosition ( PUSER_INPUT_BUFFER pci, int nPos, int whence );
// bInsert < 0 toggle insert.  bInsert == 0 clear isnert(set overwrite) else
// set insert (clear overwrite )
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetUserInputInsert ( PUSER_INPUT_BUFFER pci, int bInsert );
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetUserInputSaveCR( PUSER_INPUT_BUFFER pci, int bSaveCR );
/* Get the next command in the queue in the speicifed direction
   Parameters
   pci :  pointer to command input buffer
   bUp :  if TRUE \- get older command; else get the newer
          command.                                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RecallUserInput ( PUSER_INPUT_BUFFER pci, int bUp );
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GetUserInputLine( PUSER_INPUT_BUFFER pOutput );
/* Add a buffer to the history buffer.
                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  EnqueUserInputHistory ( PUSER_INPUT_BUFFER pci, PTEXT pHistory );
/* Arbitrary PTEXT blocks are fed to the user input queue with
   this.
   Parameters
   pci :     pointer to command buffer
   stroke :  the stroke to add to the buffer (may be a whole
             String or linked list of segments). or NULL if
             getting existing input...
   Return Value List
   NULL :      There is no command available \- no text followed
               by a newline.
   not NULL :  A command line collected from the input text. There
               may be multiple commands in a single 'stroke'
               buffer.
   Example
   This may be used something like .... to add the storke to the
   \input buffer, and while there is a result, get the result
   from the buffer.
   <code lang="c++">
   {
       PUSER_INPUT_BUFFER pci = CreateUserInputBuffer();
       PTEXT result;
       for( result = GatherUserInput( pci, new_stroke ); result; result = GatherUserInput( pci, NULL ) )
       {
       }
   }
   </code>                                                                                               */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GatherUserInput ( PUSER_INPUT_BUFFER pci, PTEXT stroke );
/* delete 1 character at current user input index */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteUserInput( PUSER_INPUT_BUFFER pci );
/* Converts ascii character set to ebcidc. */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE  ConvertAsciiEbdic( TEXTSTR text, INDEX length );
/* Routine to convert from ebcdic character set to ascii. */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE  ConvertEbcdicAscii( TEXTSTR text, INDEX length );
/* Converts ascii 85 to ascii */
TYPELIB_PROC TEXTSTR FtnATA( TEXTSTR buf );
/* Converts ascii character set to ascii 85  */
TYPELIB_PROC TEXTSTR ATFtnA( TEXTSTR buf );
/* Expand characters which are outside of standard ascii to URI
   compatible escapes.
   Parameters
   text :        Text to convert
   length :      max length of text to convert
   skip_slash :  if TRUE, keep slash characters as literal,
                 otherwise they get converted.                  */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE ConvertTextURI( CTEXTSTR text, INDEX length, int skip_slash );
/* Converts URI escape characters like %3B to the appropriate
   ascii characters. The resulting string must be released by
   the application.
   Parameters
   text :    TEXTCHAR * string to convert.
   length :  max length of text to convert.
   Example
   <code lang="c++">
   TEXTCHAR *sample = WIDE( "https://www.google.com/#hl=en&amp;sugexp=eqn&amp;cp=11&amp;gs_id=1a&amp;xhr=t&amp;q=%3B+%5C+%2B+:+";
   TEXTCHAR *result;
   \result = ConvertURIText( sample, StrLen( sample ) );
   \result == https://www.google.com/#hl=en&amp;sugexp=eqn&amp;cp=11&amp;gs_id=1a&amp;xhr=t&amp;q=;+\\+++:+
   </code>                                                                                                                        */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE ConvertURIText( CTEXTSTR text, INDEX length );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE ParseStringVector( CTEXTSTR data, CTEXTSTR **pData, int *nData );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE ParseIntVector( CTEXTSTR data, int **pData, int *nData );
#ifdef __cplusplus
 //namespace text {
};
#endif
//--------------------------------------------------------------------------
#ifdef __cplusplus
	namespace BinaryTree {
#endif
/* This type defines a specific node in the tree. It is entirely
   private, and is a useless definition.                         */
typedef struct treenode_tag *PTREENODE;
/* Defines a Binary Tree.
   See Also
   <link CreateBinaryTree> */
typedef struct treeroot_tag *PTREEROOT;
/* This option may be passed to extended CreateBinaryTree
   methods to disallow adding of duplicates. Otherwise
   duplicates will be added; they will be added to the side of
   the node with the same value that has less children. Trees
   are created by default without this option, allowing the
   addition of duplicates.
   Example
   <code lang="c++">
   PTREEROOT = <link CreateBinaryTreeExtended>( BT_OPT_NODUPLICATES, NULL, NULL DBG_SRC );
   </code>                                                                                 */
#define BT_OPT_NODUPLICATES 1
/* Generic Compare is the type declaration for the callback routine for user custom comparisons.
  This routine should return -1 if new is less than old, it should return 1 if new is more than old, and it
  should return 0 if new and old are the same key. */
typedef int (CPROC *GenericCompare)( uintptr_t oldnode,uintptr_t newnode );
/* Signature for the user callback passed to CreateBinaryTreeEx
   that will be called for each node removed from the binary
   list.                                                        */
typedef void (CPROC *GenericDestroy)( CPOINTER user, uintptr_t key);
/* when adding a node if Compare is NULL the default method of a
   basic unsigned integer compare on the key value is done. if
   Compare is specified the specified key value of the orginal
   node (old) and of the new node (new) is added. Result of
   compare should be ( \<0 (lesser)) ( 0 (equal)) ( \>0
   (greater))
   Example
   <code lang="c++">
   int CPROC MyGenericCompare( uintptr_t oldnode,uintptr_t newnode )
   {
   </code>
   <code>
      if(oldnode\>newnode)
          return 1;
      else if(oldnode\<newnode)
          return -1;
      else return 0;
   </code>
   <code lang="c++">
      return (oldnode\>newnode)? 1
             \:(oldnode\<newnode)? -1
             \:0;
   }
   void CPROC MyGenericDestroy(POINTER user, uintptr_t key)
   {
      // do something custom with your user data and or key value
   }
   PTREEROOT tree = CreateBinaryTreeExtended( 0 // BT_OPT_NODUPLICATES
                                            , MyGenericCompare
                                            , MyGenericDestroy
                                            <link DBG_PASS, DBG_SRC> );
   </code>
   See Also
   <link CreateBinaryTreeExx>
   <link CreateBinaryTreeEx>
   <link CreateBinaryTree>                                               */
TYPELIB_PROC  PTREEROOT TYPELIB_CALLTYPE  CreateBinaryTreeExtended( uint32_t flags
															, GenericCompare Compare
															, GenericDestroy Destroy DBG_PASS);
/* This is the simpler case of <link CreateBinaryTreeExtended>,
   which does not make you pass DBG_SRC.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTreeExx( BT_OPT_NODUPLICATES, NULL, NULL );
   </code>                                                                  */
#define CreateBinaryTreeExx(flags,compare,destroy) CreateBinaryTreeExtended(flags,compare,destroy DBG_SRC)
/* Creates a binary tree, allowing specification of comparison
   and destruction routines.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTreeEx( <link CreateBinaryTreeExtended, MyGenericCompare>, <link CreateBinaryTreeExtended, MyGenericDestroy> );
   </code>                                                                                                                                      */
#define CreateBinaryTreeEx(compare,destroy) CreateBinaryTreeExx( 0, compare, destroy )
/* This is the simplest way to create a binary tree.
   The default compare routine treats 'key' as an integer value
   that is compared against other for lesser/greater condition.
   This tree also allows duplicates to be added.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   </code>                                                      */
#define CreateBinaryTree() CreateBinaryTreeEx( NULL, NULL )
/* \ \
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   DestroyBinaryTree( tree );
   tree = NULL;
   </code>                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DestroyBinaryTree( PTREEROOT root );
/* Drops all the nodes in a tree so it becomes empty...
   \ \
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   ResetBinaryTree( tree );
   tree = NULL;
   </code>                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  ResetBinaryTree( PTREEROOT root );
/* Balances a binary tree. If data is added to a binary list in
   a linear way (from least to most), the tree can become
   unbalanced, and all be on the left or right side of data. This
   routine can analyze branches and perform rotations so that
   the tree can be discretely rebalanced.
   Example
   <code lang="c++">
   <link PTREEROOT> tree;
   // <link AddBinaryNode>...
   BalanceBinaryTree( tree );
   </code>                                                        */
TYPELIB_PROC  void TYPELIB_CALLTYPE  BalanceBinaryTree( PTREEROOT root );
/* \ \
   See Also
   <link AddBinaryNode>
   <link DBG_PASS>
                        */
TYPELIB_PROC  int TYPELIB_CALLTYPE  AddBinaryNodeEx( PTREEROOT root
                                                   , CPOINTER userdata
                                                   , uintptr_t key DBG_PASS );
/* Adds a user pointer identified by key to a binary list.
   See Also
   <link BinaryTree::CreateBinaryTree, CreateBinaryTree>
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   uintptr_t key = 1;
   POINTER data = NewArray( TEXTCHAR, 32 );
   AddBinaryNode( tree, data, key );
   </code>
   Parameters
   root :  PTREEROOT binary tree instance.
   data :  POINTER to some user object.
   key :   uintptr_t a integer type which can be used to identify
           the data. (used to compare in the tree).<p /><p />If
           the user has specified a custom comparison routine in
           an extended CreateBinaryTree(), then this value might
           be a pointer to some other data. Often the thing used
           to key into a binary tree is a <link CTEXTSTR>.
   Returns
   The tree may be created with <link BT_OPT_NODUPLICATES>, in
   which case this will result FALSE if the key is found
   duplicated in the list. Otherwise this returns TRUE. if the
   root parameter is NULL, the result is FALSE.                  */
#define AddBinaryNode(r,u,k) AddBinaryNodeEx((r),(u),(k) DBG_SRC )
//TYPELIB_PROC  int TYPELIB_CALLTYPE  AddBinaryNode( PTREEROOT root
//                                    , POINTER userdata
//                                    , uintptr_t key );
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveBinaryNode( PTREEROOT root, POINTER use, uintptr_t key );
/* Search in a binary tree for the specified key.
   Returns
   user data POINTER if found, else NULL.
   Example
   <code lang="c++">
   PTREEROOT tree;
   void f( void )
   {
      CPOINTER mydata = FindInBinaryTree( tree, 5 );
      if( mydata )
      {
          // found '5' as the key in the tree
      }
   }
   </code>                                          */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  FindInBinaryTree( PTREEROOT root, uintptr_t key );
// result of fuzzy routine is 0 = match.  100 = inexact match
// 1 = no match, actual may be larger
// -1 = no match, actual may be lesser
// 100 = inexact match- checks nodes near for better match.
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  LocateInBinaryTree( PTREEROOT root, uintptr_t key
														, int (CPROC*fuzzy)( uintptr_t psv, uintptr_t node_key ) );
/* During FindInBinaryTree and LocateInBinaryTree, the last
   found result is stored. This function allows deletion of that
   node.
   Example
   <code lang="c++">
   FindInBinaryTree( tree, 5 );
   RemoveLastFoundNode( tree );
   </code>                                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveLastFoundNode(PTREEROOT root );
/* Removes the currently browsed node from the tree.
   See Also
   <link GetChildNode>                               */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveCurrentNode(PTREEROOT root );
/* Basically this is meant to dump to a log, if the print
   function is passed as NULL, then the tree's contents are
   dumped to the log. It dumps a very cryptic log of how all
   nodes in the tree are arranged. But by allowing the user to
   provide a method to log his data and key, the logging is more
   meaningful based on the application. The basic code for
   managing trees and nodes works....
   Example
   <code>
   int ForEachNode( POINTER user, uintptr_t key )
   {
       // return not 1 to dump to log the internal tree structure
       return 0; // probably did own logging here, so don't log tree internal
   }
   <link PTREEROOT> tree;
   void f( void )
   {
       DumpTree( tree, ForEachNode );
   }
   </code>                                                                    */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DumpTree( PTREEROOT root
                          , int (*Dump)( CPOINTER user, uintptr_t key ) );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLeastNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLeastNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreatestNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreatestNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLesserNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLesserNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreaterNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreaterNode( PTREEROOT root );
/* \Returns the node that is set as 'current' in the tree. There
   is a cursor within the tree that can be used for browsing.
   See Also
   <link GetChildNode>                                           */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetCurrentNodeEx( PTREEROOT root, POINTER *cursor );
/* \Returns the node that is set as 'current' in the tree. There
   is a cursor within the tree that can be used for browsing.
   See Also
   <link GetChildNode>                                           */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetCurrentNode( PTREEROOT root );
/* This sets the current node cursor to the root of the node.
   See Also
   <link GetChildNode>                                        */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetRootNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetParentNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetParentNode( PTREEROOT root );
/* While browsing the tree after a find operation move to the
   next child node, direction 0 is lesser direction !0 is
   greater.
   Binary Trees have a 'current' cursor. These operations may be
   used to browse the tree.
   Example
   \ \
   <code>
   // this assumes you have a tree, and it's fairly populated, then this demonstrates
   // all steps of browsing.
   POINTER my_data;
   // go to the 'leftmost' least node. (as determined by the compare callback)
   my_data = GetLeastNode( tree );
   // go to the 'rightmost' greatest node. (as determined by the compare callback)
   my_data = GetGreatestNode( tree );
   // move to the node that is less than the current node.  (move to the 'left')
   my_data = GetLesserNode( tree );
   // move to the node that is greater than the current node.  (move to the 'right')
   my_data = GetGreaterNode( tree );
   // follow the tree to the left down from here
   my_data = GetChildNode( tree, 0 );
   // follow the tree to the right down from here
   my_data = GetChildNode( tree, 1 );
   // follow the tree up to the node above the current one.
   //  (the one who's lesser or greater points at this)
   my_data = GetParentNode( tree );
   // this is probably the least useful, but someone clever might find a trick for it
   // Move back to the node we were just at.
   //  (makes the current the prior, and moves to what the prior was,
   //     but then it's just back and forth between the last two; it's not a stack ).
   my_data = GetPriorNode( tree );
   </code>
   A more practical example...
   <code lang="c++">
   POINTER my_data;
   for( my_data = GetLeastNode( tree );
        my_data;
        my_data = GetGreaterNode( tree ) )
   {
        // browse the tree from least to most.
   }
   </code>                                                                            */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetChildNode( PTREEROOT root, int direction );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetChildNodeEx( PTREEROOT root, POINTER *cursor, int direction );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetPriorNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetPriorNode( PTREEROOT root );
/* \Returns the total number of nodes in the tree.
   Example
   <code lang="c++">
   uint32_t total_nodes = GetNodeCount(tree);
   </code>                                         */
TYPELIB_PROC  uint32_t TYPELIB_CALLTYPE  GetNodeCount ( PTREEROOT root );
 // returns a shadow of the original.
TYPELIB_PROC  PTREEROOT TYPELIB_CALLTYPE  ShadowBinaryTree( PTREEROOT root );
#ifdef __cplusplus
 //namespace BinaryTree {
	};
#endif
//--------------------------------------------------------------------------
#ifdef __cplusplus
namespace family {
#endif
/* A family tree structure, for tracking elements that have
   multiple children.
                                                            */
typedef struct familyroot_tag *PFAMILYTREE;
typedef struct familynode_tag *PFAMILYNODE;
/* <unfinished>
   Incomplete Work in progress (maybe) */
TYPELIB_PROC  PFAMILYTREE TYPELIB_CALLTYPE  CreateFamilyTree ( int (CPROC *Compare)(uintptr_t key1, uintptr_t key2)
															, void (CPROC *Destroy)(POINTER user, uintptr_t key) );
/* <unfinished>
   Incomplete, Family tree was never completed. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE  FamilyTreeFindChild ( PFAMILYTREE root
														  , uintptr_t psvKey );
/* <unfinished>
   Incomplete, Family tree was never completed. */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE FamilyTreeFindChildEx ( PFAMILYTREE root, PFAMILYNODE root_node
													 , uintptr_t psvKey );
/* Resets the search cursors in the tree... */
TYPELIB_PROC  void TYPELIB_CALLTYPE  FamilyTreeReset ( PFAMILYTREE *option_tree );
/* Resets the content of the tree (should call destroy methods, at this time it does not) */
TYPELIB_PROC  void TYPELIB_CALLTYPE  FamilyTreeClear ( PFAMILYTREE option_tree );
/* <unfinished>
   Incomplete Work in progress (maybe) */
TYPELIB_PROC  PFAMILYNODE TYPELIB_CALLTYPE  FamilyTreeAddChild ( PFAMILYTREE *root, PFAMILYNODE parent, POINTER userdata, uintptr_t key );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE FamilyTreeForEachChild( PFAMILYTREE root, PFAMILYNODE node
			, LOGICAL (CPROC *ProcessNode)( uintptr_t psvForeach, uintptr_t psvNodeData )
			, uintptr_t psvUserData );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE FamilyTreeForEach( PFAMILYTREE root, PFAMILYNODE node
			, LOGICAL (CPROC *ProcessNode)( uintptr_t psvForeach, uintptr_t psvNodeData, int level )
			, uintptr_t psvUserData );
#ifdef __cplusplus
 //namespace family {
};
#endif
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifdef __cplusplus
//} // extern "c"
 // namespace containers
};
 // namespace sack
};
using namespace sack::containers::link_stack;
using namespace sack::containers::data_stack;
using namespace sack::containers::data_list;
using namespace sack::containers::data_queue;
using namespace sack::containers::queue;
using namespace sack::containers::BinaryTree;
using namespace sack::containers::text;
using namespace sack::containers::message;
using namespace sack::containers::sets;
using namespace sack::containers::family;
using namespace sack::containers;
#else
// should 'class'ify these things....
#endif
#ifndef _TYPELIBRARY_SOURCE
//#undef TYPELIB_PROC // we don't need this symbol after having built the right prototypes
#endif
#endif
// $Log: sack_typelib.h,v $
// Revision 1.99  2005/07/10 23:56:25  d3x0r
// Fix types for C++...
//
//
// Revision 1.39  2003/03/25 08:38:11  panther
// Add logging
//
SACK_NAMESPACE
#ifndef IS_DEADSTART
// this is always statically linked with libraries, so they may contact their
// core executable to know when it's done loading everyone else also...
#  ifdef __cplusplus
extern "C"
#  endif
#  if defined( WIN32 ) && !defined( __STATIC__ ) && !defined( __ANDROID__ )
#    ifdef __NO_WIN32API__
// DllImportAttribute ?
#    else
__declspec(dllimport)
#    endif
#  else
#ifndef __cplusplus
extern
#endif
#  endif
/* a function true/false which indicates whether the root
   deadstart has been invoked already. If not, one should call
   InvokeDeadstart and MarkDeadstartComplete.
   <code lang="c++">
   int main( )
   {
       if( !is_deadstart_complete() )
       {
           InvokeDeadstart();
           MarkDeadstartComplete()
       }
       ... your code here ....
       return 0;  // or some other appropriate return.
   }
   </code>
   sack::app::deadstart                                        */
LOGICAL
#  if defined( __WATCOMC__ )
__cdecl
#  endif
is_deadstart_complete( void );
#endif
/* Define a routine to call for exit().  This triggers specific code to handle shutdown event registration */
#ifndef NO_EXPORTS
#  ifdef SACK_BAG_CORE_EXPORTS
EXPORT_METHOD
#  else
IMPORT_METHOD
#  endif
#else
#  ifndef SACK_BAG_CORE_EXPORTS
	extern
#  endif
#endif
		void CPROC BAG_Exit( int code );
#ifndef NO_SACK_EXIT_OVERRIDE
#define exit(n) BAG_Exit(n)
#endif
 // namespace sack {
SACK_NAMESPACE_END
// this should become common to all libraries and programs...
 // pronounced 'kahn-struct'
/* Defines interface for Construct API.
   Description
   This API is for distributed process tracking. A launching
   program will receive notifications to cause certain events to
   happen. Applications built for use by this execution tracking
   program will register that they are loading while they are
   loading, and before the application Main() is invoked. the
   application should then call LoadComplete() once they have
   initialized and are ready to process. This allows a
   quick-wait to wait for the process to register that it is
   loading, and a longer wait for process completion. Certain
   processes may not require others to be completely loaded, but
   maybe just loading. (Two peer processes that have to
   coordinate together to have either one complete
   initialization).                                              */
/* Define the procedure call type for construct API methods. */
#define CONSTRUCT_API CPROC
#ifdef CONSTRUCT_SOURCE
#define CONSTRUCT_PROC EXPORT_METHOD
#else
/* Library linkage specification. */
#define CONSTRUCT_PROC IMPORT_METHOD
#endif
#ifdef __cplusplus
/* Defines TASK namespace (unused?) */
#define _TASK_NAMESPACE namespace task {
/* Define Construct namespace. Construct is for distributed
   process tracking project. Applications will register on-load
   that they are loading, and should register load completed
   when they are done loading, or exit.                         */
#define _CONSTRUCT_NAMESPACE namespace construct {
/* Defines TASK namespace ending.(unused?) */
#define _TASK_NAMESPACE_END }
/* Define Construct namespace end. Construct is for distributed
   process tracking project. Applications will register on-load
   that they are loading, and should register load completed
   when they are done loading, or exit.                         */
#define _CONSTRUCT_NAMESPACE_END }
#else
#define _TASK_NAMESPACE
#define _CONSTRUCT_NAMESPACE
#define _TASK_NAMESPACE_END
#define _CONSTRUCT_NAMESPACE_END
#endif
/* Define a symbol to specify full sack::task::construct
   namespace.                                            */
#define CONSTRUCT_NAMESPACE SACK_NAMESPACE _TASK_NAMESPACE _CONSTRUCT_NAMESPACE
/* Define a symbol to specify full sack::task::construct
   namespace ending.                                     */
#define CONSTRUCT_NAMESPACE_END _CONSTRUCT_NAMESPACE_END _TASK_NAMESPACE_END SACK_NAMESPACE_END
	SACK_NAMESPACE
	_TASK_NAMESPACE
	/* Registers with message service, assuming the summoner message service is active.
	 Provides communication methods with a task manager, so the application can notify,
	 start has completed.   The service is ready to work.*/
_CONSTRUCT_NAMESPACE
/* Called to indicate that a process is done initializing and is
   ready to process. Notifies summoner service of Loading
   completed. If enabled, there is also a library component that
   will run at deadstart to just confirm initializing, this
   would actually indicate the service is now ready to serve.    */
CONSTRUCT_PROC void CONSTRUCT_API LoadComplete( void );
CONSTRUCT_NAMESPACE_END
#ifdef __cplusplus
	using namespace sack::task::construct;
#endif
/*
 *  Crafted by James Buckeyne
 *  Part of SACK github.com/d3x0r/SACK
 *
 *   (c) Freedom Collective 2000-2006++, 2016++
 *
 *   created to provide standard logging features
 *   lprintf( format, ... ); simple, basic
 *   if DEBUG, then logs to a file of the same name as the program
 *   if RELEASE most of this logging goes away at compile time.
 *
 *  standardized to never use int.
 */
#ifndef LOGGING_MACROS_DEFINED
#define LOGGING_MACROS_DEFINED
#define SYSLOG_API CPROC
#ifdef SYSLOG_SOURCE
#define SYSLOG_PROC EXPORT_METHOD
#else
#define SYSLOG_PROC IMPORT_METHOD
#endif
#ifdef __cplusplus
#define LOGGING_NAMESPACE namespace sack { namespace logging {
#define LOGGING_NAMESPACE_END }; };
#else
#define LOGGING_NAMESPACE
#define LOGGING_NAMESPACE_END
#endif
#ifdef __cplusplus
	namespace sack {
/* Handles log output. Logs can be directed to UDP directed, or
   broadcast, or localhost, or to a file location, and under
   windows the debugging console log.
   lprintf
   SetSystemLog
   SystemLogTime
   there are options, when options code is enabled, which
   control logging output and format. Log file location can be
   specified generically for instance.... see Options.
	This namespace contains the logging functions. The most basic
   thing you can do to start logging is use 'lprintf'.
   <code lang="c++">
   lprintf( "My printf like format %s %d times", "string", 15 );
   </code>
   This function takes a format string and arguments compatible
   with vsnprintf. Internally strings are truncated to 4k
   length. (that is no single logging message can be more than
   4k in length).
   There are functions to control logging behavior.
   See Also
   SetSystemLog
   SystemLogTime
   SystemLogOptions
   lprintf
   _lprintf
   xlprintf
   _xlprintf
                                                                 */
		namespace logging {
#endif
/* \Parameters for SetSystemLog() to specify where the logging
   should go.                                                  */
enum syslog_types {
 // disable any log output.
SYSLOG_NONE     =   -1
,
SYSLOG_UDP      =    0
,
SYSLOG_FILE     =    1
,
 /* Set logging to output to a file. The file passed is a FILE*. This
   may be a FILE* like stdout, stderr, or some file the
   application opens.                                                */
SYSLOG_FILENAME =    2
,
 /* Set logging to go to a file, pass the string text name of the
   \file to open as the second parameter of SetSystemLog.        */
SYSLOG_SYSTEM   =    3
,
 /* Specify that logging should go to system (this actually means
   Windows system debugging channel. OutputDebugString() ).      */
SYSLOG_UDPBROADCAST= 4
// Allow user to specify a void UserCallback( char * )
// which recieves the formatted output.
,
SYSLOG_CALLBACK    = 5
,
 /* Send Logging to a specified user callback to handle. This
   lets logging go anywhere else that's not already thought of. */
SYSLOG_AUTO_FILE = SYSLOG_FILE + 100
 /* Send logging to a file. If the file is not open, open the
   \file. If no logging happens, no log file is created.     */
,
SYSLOG_SOCKET_SYSLOGD
};
#if !defined( NO_LOGGING )
#define DO_LOGGING
#endif
// this was forced, force no_logging off...
#if defined( DO_LOGGING )
#undef NO_LOGGING
#endif
#ifdef __LINUX__
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
SYSLOG_PROC  LOGICAL SYSLOG_API  IsBadReadPtr ( CPOINTER pointer, uintptr_t len );
#endif
SYSLOG_PROC  CTEXTSTR SYSLOG_API  GetPackedTime ( void );
//
typedef void (CPROC*UserLoggingCallback)( CTEXTSTR log_string );
SYSLOG_PROC  void SYSLOG_API  SetSystemLog ( enum syslog_types type, const void *data );
SYSLOG_PROC  void SYSLOG_API  ProtectLoggedFilenames ( LOGICAL bEnable );
SYSLOG_PROC  void SYSLOG_API  SystemLogFL ( CTEXTSTR FILELINE_PASS );
SYSLOG_PROC  void SYSLOG_API  SystemLogEx ( CTEXTSTR DBG_PASS );
SYSLOG_PROC  void SYSLOG_API  SystemLog ( CTEXTSTR );
SYSLOG_PROC  void SYSLOG_API  LogBinaryFL ( const uint8_t* buffer, size_t size FILELINE_PASS );
SYSLOG_PROC  void SYSLOG_API  LogBinaryEx ( const uint8_t* buffer, size_t size DBG_PASS );
SYSLOG_PROC  void SYSLOG_API  LogBinary ( const uint8_t* buffer, size_t size );
// logging level defaults to 1000 which is log everything
SYSLOG_PROC  void SYSLOG_API  SetSystemLoggingLevel ( uint32_t nLevel );
#if defined( _DEBUG ) || defined( _DEBUG_INFO )
/* Log a binary buffer. Logs lines representing 16 bytes of data
   at a time. The hex of each byte in a buffer followed by the
   text is logged.
   Example
   <code lang="c#">
   char sample[] = "sample string";
   LogBinary( sample, sizeof( sample ) );
   </code>
   Results with the following output in the log...
   <code>
    73 61 6D 70 6C 65 20 73 74 72 69 6E 67 00 sample string.
   </code>
   The '.' at the end of 'sample string' is a non printable
   character. characters 0-31 and 127+ are printed as '.'.       */
#define LogBinary(buf,sz) LogBinaryFL((uint8_t*)(buf),sz DBG_SRC )
#define SystemLog(buf)    SystemLogFL(buf DBG_SRC )
#else
// need to include the typecast... binary logging doesn't really care what sort of pointer it gets.
#define LogBinary(buf,sz) LogBinary((uint8_t*)(buf),sz )
//#define LogBinaryEx(buf,sz,...) LogBinaryFL(buf,sz FILELINE_NULL)
//#define SystemLogEx(buf,...) SystemLogFL(buf FILELINE_NULL )
#endif
// int result is useless... but allows this to be
// within expressions, which with this method should be easy.
typedef INDEX (CPROC*RealVLogFunction)(CTEXTSTR format, va_list args )
//#if defined( __GNUC__ ) && !defined( _UNICODE )
//	__attribute__ ((__format__ (__vprintf__, 1, 2)))
//#endif
	;
typedef INDEX (CPROC*RealLogFunction)(CTEXTSTR format,...)
#if defined( __GNUC__ ) && !defined( _UNICODE )
	__attribute__ ((__format__ (__printf__, 1, 2)))
#endif
	;
SYSLOG_PROC  RealVLogFunction SYSLOG_API  _vxlprintf ( uint32_t level DBG_PASS );
SYSLOG_PROC  RealLogFunction SYSLOG_API  _xlprintf ( uint32_t level DBG_PASS );
// utility function to format a cpu delta into a buffer...
// end-start is always printed... therefore tick_end-0 is
// print absolute time... formats as millisecond.NNN
SYSLOG_PROC  void SYSLOG_API  PrintCPUDelta ( TEXTCHAR *buffer, size_t buflen, uint64_t tick_start, uint64_t tick_end );
// return the current CPU tick
SYSLOG_PROC  uint64_t SYSLOG_API  GetCPUTick ( void );
// result in nano seconds - thousanths of a millisecond...
SYSLOG_PROC  uint32_t SYSLOG_API  ConvertTickToMicrosecond ( uint64_t tick );
SYSLOG_PROC  uint64_t SYSLOG_API  GetCPUFrequency ( void );
SYSLOG_PROC  CTEXTSTR SYSLOG_API  GetTimeEx ( int bUseDay );
SYSLOG_PROC  void SYSLOG_API  SetSyslogOptions ( FLAGSETTYPE *options );
/* When setting options using SetSyslogOptions() these are the
   defines for the bits passed.
   SYSLOG_OPT_OPENAPPEND - the file, when opened, will be opened
   for append.
   SYSLOG_OPT_OPEN_BACKUP - the file, if it exists, will be
   renamed automatically.
   SYSLOG_OPT_LOG_PROGRAM_NAME - enable logging the program
   executable (probably the same for all messages, unless they
   are network)
   SYSLOG_OPT_LOG_THREAD_ID - enables logging the unique process
   and thread ID.
   SYSLOG_OPT_LOG_SOURCE_FILE - enable logging source file
   information. See <link DBG_PASS>
   SYSLOG_OPT_MAX - used for declaring a flagset to pass to
   setoptions.                                                   */
enum system_logging_option_list {
		/* the file, when opened, will be opened for append.
		 */
		SYSLOG_OPT_OPENAPPEND
										  ,
  /* the file, if it exists, will be renamed automatically.
										  */
										  SYSLOG_OPT_OPEN_BACKUP
                                ,
 /* enable logging the program executable (probably the same for
                                   all messages, unless they are network)
                                                                                                */
                                 SYSLOG_OPT_LOG_PROGRAM_NAME
										  ,
 /* enables logging the unique process and thread ID.
										                                                       */
                                 SYSLOG_OPT_LOG_THREAD_ID
                                ,
 /* enable logging source file information. See <link DBG_PASS>
                                                                                               */
										   SYSLOG_OPT_LOG_SOURCE_FILE
										  ,
										  SYSLOG_OPT_MAX
};
// this solution was developed to provide the same
// functionality for compilers that refuse to implement __VA_ARGS__
// this therefore means that the leader of the function is replace
// and that extra parenthesis exist after this... therefore the remaining
// expression must be ignored... thereofre when defining a NULL function
// this will result in other warnings, about ignored, or meaningless expressions
# if defined( DO_LOGGING )
#  define vlprintf      _vxlprintf(LOG_NOISE DBG_SRC)
#  define lprintf       _xlprintf(LOG_NOISE DBG_SRC)
#  define _lprintf(file_line,...)       _xlprintf(LOG_NOISE file_line,##__VA_ARGS__)
#  define xlprintf(level)       _xlprintf(level DBG_SRC)
#  define vxlprintf(level)       _vxlprintf(level DBG_SRC)
# else
#  ifdef _MSC_VER
#   define vlprintf      (1)?(0):
#   define lprintf       (1)?(0):
#   define _lprintf(DBG_VOIDRELAY)       (1)?(0):
#   define xlprintf(level)       (1)?(0):
#   define vxlprintf(level)      (1)?(0):
#  else
#   define vlprintf(f,...)
/* use printf formating to output to the log. (log printf).
   Parameters
   Format :  Just like printf, the format string to print.
   ... :     extra arguments passed as required for the format.
   Example
   <code lang="c++">
      lprintf( "Test Logging %d %d", 13, __LINE__ );
   </code>                                                      */
#   define lprintf(f,...)
#   define  _lprintf(DBG_VOIDRELAY)       lprintf
#   define xlprintf(level) lprintf
#   define vxlprintf(level) lprintf
#  endif
# endif
#undef LOG_WARNING
#undef LOG_ADVISORIES
#undef LOG_INFO
// Defined Logging Levels
enum {
	  // and you are free to use any numerical value,
	  // this is a rough guideline for wide range
	  // to provide a good scaling for levels of logging
 // unless logging is disabled, this will be logged
	LOG_ALWAYS = 1
 // logging level set to 50 or more will cause this to log
	, LOG_ERRORS = 50
	,
 /* Specify a logging level which only ERROR level logging is
	   logged.                                                   */
 // logging level set to 50 or more will cause this to log
	 LOG_ERROR = LOG_ERRORS
	,
 // .......
	 LOG_WARNINGS = 500
	,
 // .......
	 LOG_WARNING = LOG_WARNINGS
   ,
 /* Use to specify that the log message is a warning level
      message.                                               */
    LOG_ADVISORY = 625
   ,
    LOG_ADVISORIES = LOG_ADVISORY
	,
 /* A symbol to specify to log Adviseries, Warnings and Error
	   level messages only.                                      */
	 LOG_INFO = 750
	  ,
 /* A moderate logging level, which is near maximum verbosity of
	     logging.                                                     */
	   LOG_NOISE = 1000
     ,
 /* Define that the message is just noisy - though verbosly
	  informative, it's level is less critical than even INFO.
	  default iS LOG_NOISE which is 1000, an ddefault for disabling most messages
	  is to set log level to 999.  Have to increase to 2000 to see debug, and this name
     has beviously
	  */
      LOG_LEVEL_DEBUG = 2000
	,
 /* Specify the message is of DEBUG importance, which is far
	   above even NOISY. If debug logging is enabled, all logging,
	   ERROR, WARNING, ADVISORY, INFO, NOISY and DEBUG will be
	   logged.                                                     */
 // not quite a negative number, but really big
	 LOG_CUSTOM = 0x40000000
	,
 /* A bit with LOG_CUSTOM might be enabled, and the lower bits
	   under 0x40000000 (all bits 0x3FFFFFFF ) can be used to
	   indicate a logging type. Then SetLoggingLevel can be passed a
	   mask of bits to filter types of messages.                     */
 // not quite a negative number, but really big
	 LOG_CUSTOM_DISABLE = 0x20000000
	// bits may be user specified or'ed with this value
	// such that ...
	// Example 1:SetSystemLoggingLevel( LOG_CUSTOM | 1 ) will
	// enable custom logging messages which have the '1' bit on... a logical
	// and is used to test the low bits of this value.
	// example 2:SetSystemLogging( LOG_CUSTOM_DISABLE | 1 ) will disable logging
	// of messages with the 1 bit set.
  // mask of bits which may be used to enable and disable custom logging
#define LOG_CUSTOM_BITS 0xFFFFFF
};
 // this is a flag set consisting of 0 or more or'ed symbols
enum SyslogTimeSpecifications {
 // disable time logging
 SYSLOG_TIME_DISABLE = 0,
 // enable is anything not zero.
 SYSLOG_TIME_ENABLE  = 1,
 // specify to log milliseconds
 SYSLOG_TIME_HIGH    = 2,
 // log the year/month/day also
 SYSLOG_TIME_LOG_DAY = 4,
 // log the difference in time instead of the absolute time
 SYSLOG_TIME_DELTA   = 8,
 // logs cpu ticks... implied delta
 SYSLOG_TIME_CPU     =16
};
/* Specify how time is logged. */
SYSLOG_PROC void SYSLOG_API SystemLogTime( uint32_t enable );
#ifndef NO_LOGGING
#define OutputLogString(s) SystemLog(s)
/* Depricated. Logs a format string that takes 0 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log(s)                                   SystemLog( s )
#else
#define OutputLogString(s)
/* Depricated. Logs a format string that takes 0 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log(s)
#endif
/* Depricated. Logs a format string that takes 1 parameter.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log1(s,p1)                               lprintf( s, p1 )
/* Depricated. Logs a format string that takes 2 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log2(s,p1,p2)                            lprintf( s, p1, p2 )
/* Depricated. Logs a format string that takes 3 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log3(s,p1,p2,p3)                         lprintf( s, p1, p2, p3 )
/* Depricated. Logs a format string that takes 4 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log4(s,p1,p2,p3,p4)                      lprintf( s, p1, p2, p3,p4)
/* Depricated. Logs a format string that takes 5 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log5(s,p1,p2,p3,p4,p5)                   lprintf( s, p1, p2, p3,p4,p5)
/* Depricated. Logs a format string that takes 6 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log6(s,p1,p2,p3,p4,p5,p6)                lprintf( s, p1, p2, p3,p4,p5,p6)
/* Depricated. Logs a format string that takes 7 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log7(s,p1,p2,p3,p4,p5,p6,p7)             lprintf( s, p1, p2, p3,p4,p5,p6,p7 )
/* Depricated. Logs a format string that takes 8 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log8(s,p1,p2,p3,p4,p5,p6,p7,p8)          lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8 )
/* Depricated. Logs a format string that takes 9 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log9(s,p1,p2,p3,p4,p5,p6,p7,p8,p9)       lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8,p9 )
/* Depricated. Logs a format string that takes 10 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log10(s,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)  lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8,p9,p10 )
LOGGING_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::logging;
#endif
#endif
#if defined( _MSC_VER ) || (1)
// huh, apparently all compiles are messed the hell up.
#  define COMPILER_THROWS_SIGNED_UNSIGNED_MISMATCH
#endif
#ifdef COMPILER_THROWS_SIGNED_UNSIGNED_MISMATCH
#  define SUS_GT(a,at,b,bt)   (((a)<0)?0:(((bt)a)>(b)))
#  define USS_GT(a,at,b,bt)   (((b)<0)?1:((a)>((at)b)))
#  define SUS_LT(a,at,b,bt)   (((a)<0)?1:(((bt)a)<(b)))
#  define USS_LT(a,at,b,bt)   (((b)<0)?0:((a)<((at)b)))
#  define SUS_GTE(a,at,b,bt)  (((a)<0)?0:(((bt)a)>=(b)))
#  define USS_GTE(a,at,b,bt)  (((b)<0)?1:((a)>=((at)b)))
#  define SUS_LTE(a,at,b,bt)  (((a)<0)?1:(((bt)a)<=(b)))
#  define USS_LTE(a,at,b,bt)  (((b)<0)?0:((a)<=((at)b)))
#else
#  define SUS_GT(a,at,b,bt)   ((a)>(b))
#  define USS_GT(a,at,b,bt)   ((a)>(b))
#  define SUS_LT(a,at,b,bt)   ((a)<(b))
#  define USS_LT(a,at,b,bt)   ((a)<(b))
#  define SUS_GTE(a,at,b,bt)  ((a)>=(b))
#  define USS_GTE(a,at,b,bt)  ((a)>=(b))
#  define SUS_LTE(a,at,b,bt)  ((a)<=(b))
#  define USS_LTE(a,at,b,bt)  ((a)<=(b))
#endif
#ifdef __cplusplus
using namespace sack;
using namespace sack::containers;
#endif
#endif
// incldue this first so we avoid a conflict.
// hopefully this comes from sack system?
/*
 *  Created by Jim Buckeyne
 *
 *  Purpose
 *    Generalization of system routines which began in
 *   dekware development.
 *   - Process control (load,start,stop)
 *   - Library runtime link control (load, unload)
 *
 */
#ifndef SYSTEM_LIBRARY_DEFINED
#define SYSTEM_LIBRARY_DEFINED
#ifdef SYSTEM_SOURCE
#define SYSTEM_PROC(type,name) EXPORT_METHOD type CPROC name
#else
#define SYSTEM_PROC(type,name) IMPORT_METHOD type CPROC name
#endif
#ifdef __LINUX__
// Hmm I thought that dlopen resulted in an int...
// but this doc says void * (redhat9)
//typedef void *HLIBRARY;
#else
//typedef HMODULE HLIBRARY;
#endif
#ifdef __cplusplus
#define _SYSTEM_NAMESPACE namespace system {
#define _SYSTEM_NAMESPACE_END }
#else
#define _SYSTEM_NAMESPACE
#define _SYSTEM_NAMESPACE_END
#endif
#define SACK_SYSTEM_NAMESPACE SACK_NAMESPACE _SYSTEM_NAMESPACE
#define SACK_SYSTEM_NAMESPACE_END _SYSTEM_NAMESPACE_END SACK_NAMESPACE_END
#ifndef UNDER_CE
#define HAVE_ENVIRONMENT
#endif
SACK_NAMESPACE
	_SYSTEM_NAMESPACE
typedef struct task_info_tag *PTASK_INFO;
typedef void (CPROC*TaskEnd)(uintptr_t, PTASK_INFO task_ended);
typedef void (CPROC*TaskOutput)(uintptr_t, PTASK_INFO task, CTEXTSTR buffer, size_t size );
// Run a program completely detached from the current process
// it runs independantly.  Program does not suspend until it completes.
// Use GetTaskExitCode() to get the return code of the process
#define LPP_OPTION_DO_NOT_HIDE           1
// for services to launch normal processes (never got it to work; used to work in XP/NT?)
#define LPP_OPTION_IMPERSONATE_EXPLORER  2
#define LPP_OPTION_FIRST_ARG_IS_ARG      4
#define LPP_OPTION_NEW_GROUP             8
#define LPP_OPTION_NEW_CONSOLE          16
#define LPP_OPTION_SUSPEND              32
SYSTEM_PROC( PTASK_INFO, LaunchPeerProgramExx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args
                                               , int flags
                                               , TaskOutput OutputHandler
                                               , TaskEnd EndNotice
                                               , uintptr_t psv
                                                DBG_PASS
                                               );
SYSTEM_PROC( PTASK_INFO, LaunchProgramEx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args, TaskEnd EndNotice, uintptr_t psv );
// launch a process, program name (including leading path), a optional path to start in (defaults to
// current process' current working directory.  And a array of character pointers to args
// args should be the NULL.
SYSTEM_PROC( PTASK_INFO, LaunchProgram )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR  args );
// abort task, no kill signal, sigabort basically.  Use StopProgram for a more graceful terminate.
// if (!StopProgram(task)) TerminateProgram(task) would be appropriate.
SYSTEM_PROC( uintptr_t, TerminateProgram )( PTASK_INFO task );
SYSTEM_PROC( void, ResumeProgram )( PTASK_INFO task );
// get first address of program startup code(?) Maybe first byte of program code?
SYSTEM_PROC( uintptr_t, GetProgramAddress )( PTASK_INFO task );
// before luanchProgramEx, there was no userdata...
SYSTEM_PROC( void, SetProgramUserData )( PTASK_INFO task, uintptr_t psv );
// attempt to implement a method on windows that allows a service to launch a user process
// current systems don't have such methods
SYSTEM_PROC( void, ImpersonateInteractiveUser )( void );
// after launching a process should revert to a protected state.
SYSTEM_PROC( void, EndImpersonation )( void );
// generate a Ctrl-C to the task.
// maybe also signal systray icon
// maybe also signal process.lock region
// maybe end process?
// maybe then terminate process?
SYSTEM_PROC( LOGICAL, StopProgram )( PTASK_INFO task );
// ctextstr as its own type is a pointer so a
//  PcTextStr is a pointer to strings -
//   char ** - returns a quoted string if args have spaces (and escape quotes in args?)
SYSTEM_PROC( TEXTSTR, GetArgsString )( PCTEXTSTR pArgs );
// after a task has exited, this can return its code.
// undefined if task has not exited (probably 0)
SYSTEM_PROC( uint32_t, GetTaskExitCode )( PTASK_INFO task );
// returns the name of the executable that is this process (without last . extension   .exe for instance)
SYSTEM_PROC( CTEXTSTR, GetProgramName )( void );
// returns the path of the executable that is this process
SYSTEM_PROC( CTEXTSTR, GetProgramPath )( void );
// returns the path that was the working directory when the program started
SYSTEM_PROC( CTEXTSTR, GetStartupPath )( void );
// returns the path of the current sack library.
SYSTEM_PROC( CTEXTSTR, GetLibraryPath )( void );
// on windows, queries an event that indicates the system is rebooting.
SYSTEM_PROC( LOGICAL, IsSystemShuttingDown )( void );
// HandlePeerOutput is called whenever a peer task has generated output on stdout or stderr
//   - someday evolution may require processing stdout and stderr with different event handlers
SYSTEM_PROC( PTASK_INFO, LaunchPeerProgramEx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args
                                              , TaskOutput HandlePeerOutput
                                              , TaskEnd EndNotice
                                              , uintptr_t psv
                                               DBG_PASS
                                              );
#define LaunchPeerProgram(prog,path,args,out,end,psv) LaunchPeerProgramEx(prog,path,args,out,end,psv DBG_SRC)
SYSTEM_PROC( PTASK_INFO, SystemEx )( CTEXTSTR command_line
                                   , TaskOutput OutputHandler
                                   , uintptr_t psv
                                   DBG_PASS
                                   );
#define System(command_line,output_handler,user_data) SystemEx( command_line, output_handler, user_data DBG_SRC )
// generate output to a task... read by peer task on standard input pipe
// if a task has been opened with an output handler, than IO is trapped, and this is a method of
// sending output to a task.
SYSTEM_PROC( int, pprintf )( PTASK_INFO task, CTEXTSTR format, ... );
// if a task has been opened with an otuput handler, than IO is trapped, and this is a method of
// sending output to a task.
SYSTEM_PROC( int, vpprintf )( PTASK_INFO task, CTEXTSTR format, va_list args );
typedef void (CPROC*generic_function)(void);
SYSTEM_PROC( generic_function, LoadFunctionExx )( CTEXTSTR library, CTEXTSTR function, LOGICAL bPrivate DBG_PASS);
SYSTEM_PROC( generic_function, LoadFunctionEx )( CTEXTSTR library, CTEXTSTR function DBG_PASS);
SYSTEM_PROC( void *, GetPrivateModuleHandle )( CTEXTSTR libname );
/*
  Add a custom loaded library; attach a name to the DLL space; this should allow
  getcustomsybmol to resolve these
  */
SYSTEM_PROC( void, AddMappedLibrary )( CTEXTSTR libname, POINTER image_memory );
SYSTEM_PROC( LOGICAL, IsMappedLibrary )( CTEXTSTR libname );
SYSTEM_PROC( void, DeAttachThreadToLibraries )( LOGICAL attach );
#define LoadFunction(l,f) LoadFunctionEx(l,f DBG_SRC )
SYSTEM_PROC( generic_function, LoadPrivateFunctionEx )( CTEXTSTR libname, CTEXTSTR funcname DBG_PASS );
#define LoadPrivateFunction(l,f) LoadPrivateFunctionEx(l,f DBG_SRC )
#define OnLibraryLoad(name)	  __DefineRegistryMethod(WIDE("SACK"),_OnLibraryLoad,WIDE("system/library"),WIDE("load_event"),name WIDE("_LoadEvent"),void,(void), __LINE__)
// the callback passed will be called during LoadLibrary to allow an external
// handler to download or extract the library; the resulting library should also
// be loaded by the callback using the standard 'LoadFunction' methods
SYSTEM_PROC( void, SetExternalLoadLibrary )( LOGICAL (CPROC*f)(const char *) );
// please Release or Deallocate the reutrn value
// the callback should search for the file specified, if required, download or extract it
// and then return with a Release'able utf-8 char *.
SYSTEM_PROC( void, SetExternalFindProgram )( char * (CPROC*f)(const char *) );
// override the default program name.
// Certain program wrappers might use this to change log location, configuration, etc other defaults.
SYSTEM_PROC( void, SetProgramName )( CTEXTSTR filename );
// this is a pointer pointer - being that generic_fucntion is
// a pointer...
SYSTEM_PROC( int, UnloadFunctionEx )( generic_function* DBG_PASS );
#ifdef HAVE_ENVIRONMENT
SYSTEM_PROC( CTEXTSTR, OSALOT_GetEnvironmentVariable )(CTEXTSTR name);
SYSTEM_PROC( void, OSALOT_SetEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
SYSTEM_PROC( void, OSALOT_AppendEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
SYSTEM_PROC( void, OSALOT_PrependEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
#endif
/* this needs to have 'GetCommandLine()' passed to it.
 * Otherwise, the command line needs to have the program name, and arguments passed in the string
 * the parameter to winmain has the program name skipped
 */
SYSTEM_PROC( void, ParseIntoArgs )( TEXTCHAR *lpCmdLine, int *pArgc, TEXTCHAR ***pArgv );
#define UnloadFunction(p) UnloadFunctionEx(p DBG_SRC )
SACK_SYSTEM_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::system;
#endif
#endif
//----------------------------------------------------------------------
// $Log: system.h,v $
// Revision 1.14  2005/07/06 00:33:55  jim
// Fixes for all sorts of mangilng with the system.h header.
//
//
// Revision 1.2  2003/10/24 14:59:21  panther
// Added Load/Unload Function for system shared library abstraction
//
// Revision 1.1  2003/10/24 13:22:06  panther
// Initial commit
//
//
#if defined( _MSC_VER )|| defined(__LCC__) || defined( __WATCOMC__ ) || defined( __GNUC__ )
/* Includes networking as appropriate for the target platform. Providing
   compatibility definitions as are lacking between platforms...
   or perhaps appropriate name aliasing to the correct types.            */
#ifndef INCLUDED_SOCKET_LIBRARY
#define INCLUDED_SOCKET_LIBRARY
#if defined( _WIN32 ) || defined( __CYGWIN__ )
//#ifndef __cplusplus_cli
#ifdef UNDER_CE
#define USE_WSA_EVENTS
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#if defined( MINGW_SUX ) && ( __GNUC__ < 5 )
/* Address information */
typedef struct addrinfoA {
    int             ai_flags;
    int             ai_family;
    int             ai_socktype;
    int             ai_protocol;
    size_t          ai_addrlen;
    char            *ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfoA *ai_next;
} ADDRINFOA;
typedef ADDRINFOA   *PADDRINFOA;
typedef struct addrinfoW {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr     *ai_addr;
    struct addrinfoW    *ai_next;
} ADDRINFOW;
typedef ADDRINFOW   *PADDRINFOW;
#ifdef UNICODE
typedef ADDRINFOW   ADDRINFOT;
typedef ADDRINFOW   *PADDRINFOT;
#else
typedef ADDRINFOA   ADDRINFOT;
typedef ADDRINFOA   *PADDRINFOT;
#endif
typedef ADDRINFOA   ADDRINFO;
typedef ADDRINFOA   *LPADDRINFO;
#endif
#ifdef __CYGWIN__
// just need this simple symbol
typedef int socklen_t;
#endif
//#endif
#elif defined( __LINUX__ )
#if defined( FBSD )
#endif
 // INADDR_ANY/NONE
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#if !defined( _PNACL )
#  include <net/if.h>
#endif
#define SOCKET int
#define SOCKADDR struct sockaddr
#define SOCKET_ERROR -1
//#define HWND int // unused params...
#define WSAEWOULDBLOCK EAGAIN
#define INVALID_SOCKET -1
#define WSAAsynchSelect( a,b,c,d ) (0)
#define WSAGetLastError()  (errno)
#define closesocket(s) close(s)
typedef struct hostent *PHOSTENT;
#ifndef __LINUX__
#define INADDR_ANY (-1)
#define INADDR_NONE (0)
#endif
struct win_in_addr {
	union {
		struct { uint8_t s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { uint16_t s_w1,s_w2; } S_un_w;
		uint32_t S_addr;
	} S_un;
#ifndef __ANDROID__
#define s_addr  S_un.S_addr
/* can be used for most tcp & ip code */
#define s_host  S_un.S_un_b.s_b2
	/* host on imp */
#define s_net   S_un.S_un_b.s_b1
	/* network */
#define s_imp   S_un.S_un_w.s_w2
	/* imp */
#define s_impno S_un.S_un_b.s_b4
	/* imp # */
#define s_lh    S_un.S_un_b.s_b3
	/* logical host */
#endif
};
struct win_sockaddr_in {
#ifdef __MAC__
	uint8_t sa_len;
	uint8_t sin_family;
#else
	short   sin_family;
#endif
	uint16_t sin_port;
	struct  win_in_addr sin_addr;
	char    sin_zero[8];
};
typedef struct win_sockaddr_in SOCKADDR_IN;
#endif
#endif
// $Log: loadsock.h,v $
// Revision 1.7  2005/01/27 08:09:25  panther
// Linux cleaned.
//
// Revision 1.6  2003/06/04 11:38:01  panther
// Define PACKED
//
// Revision 1.5  2003/03/25 08:38:11  panther
// Add logging
//
#  if defined( __MAC__ )
#  else
               // _heapmin() included here
#    include <malloc.h>
#  endif
#else
//#include "loadsock.h"
#endif
//#include <stdlib.h>
#ifdef __CYGWIN__
 // provided by -lgcc
// lots of things end up including 'setjmp.h' which lacks sigset_t defined here.
// lots of things end up including 'setjmp.h' which lacks sigset_t defined here.
#  include <sys/signal.h>
#endif
// GetTickCount() and Sleep(n) Are typically considered to be defined by including stdhdrs...
/*
 *  Crafted by Jim Buckeyne
 *
 *  (c)2001-2006++ Freedom Collective
 *
 *  Provide API interface for timers, critical sections
 *  and other thread things.
 *
 */
#ifndef TIMERS_DEFINED
/* timers.h mutliple inclusion protection symbol. */
#define TIMERS_DEFINED
#if defined( _WIN32 )
// on windows, we add a function that returns HANDLE
#endif
#ifndef SHARED_MEM_DEFINED
/* Multiple inclusion protection symbol. */
#define SHARED_MEM_DEFINED
#if defined (_WIN32)
//#define USE_NATIVE_CRITICAL_SECTION
#endif
#if defined( _SHLWAPI_H ) || defined( _INC_SHLWAPI )
#undef StrChr
#undef StrCpy
#undef StrDup
#undef StrRChr
#undef StrStr
#endif
#ifdef __cplusplus
#define SACK_MEMORY_NAMESPACE SACK_NAMESPACE namespace memory {
#define SACK_MEMORY_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define SACK_MEMORY_NAMESPACE
#define SACK_MEMORY_NAMESPACE_END
#endif
/* A declaration of the call type for memory library routines. */
#define MEM_API CPROC
#    ifdef MEM_LIBRARY_SOURCE
#      define MEM_PROC EXPORT_METHOD
#    else
/* Defines library linkage specification. */
#      define MEM_PROC IMPORT_METHOD
#    endif
#ifndef TIMER_NAMESPACE
#ifdef __cplusplus
#define _TIMER_NAMESPACE namespace timers {
/* define a timer library namespace in C++. */
#define TIMER_NAMESPACE SACK_NAMESPACE namespace timers {
/* define a timer library namespace in C++ end. */
#define TIMER_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define TIMER_NAMESPACE
#define TIMER_NAMESPACE_END
#endif
#endif
	TIMER_NAMESPACE
   // enables file/line monitoring of sections and a lot of debuglogging
//#define DEBUG_CRITICAL_SECTIONS
   /* this symbol controls the logging in timers.c... (higher level interface to NoWait primatives)*/
//#define LOG_DEBUG_CRITICAL_SECTIONS
/* A custom implementation of windows CRITICAL_SECTION api.
   Provides same capability for Linux type systems. Can be
   checked as a study in how to implement safe locks.
   See Also
   InitCriticalSec
   EnterCriticalSec
   LeaveCriticalSec
   Example
   <c>For purposes of this example this is declared in global
   memory, known to initialize to all 0.</c>
   <code lang="c++">
   CRITICALSECTION cs_lock_test;
   </code>
   In some bit of code that can be executed by several
   threads...
   <code lang="c++">
   {
      EnterCriticalSec( &amp;cs_lock_test );
      // the code in here will only be run by a single thread
      LeaveCriticalSec( &amp;cs_lock_test );
   }
   </code>
   Remarks
   The __Ex versions of functions passes source file and line
   information in debug mode. This can be used if critical
   section debugging is turned on, or if critical section
   logging is turned on. (See ... ) This allows applications to
   find deadlocks by tracking who is entering critical sections
   and probably failing to leave them.                          */
struct critical_section_tag {
 // this is set when entering or leaving (updating)...
	uint32_t dwUpdating;
  // count of locks entered.  (only low 24 bits may count for 16M entries, upper bits indicate internal statuses.
	uint32_t dwLocks;
 // windows upper 16 is process ID, lower is thread ID
	THREAD_ID dwThreadID;
 // ID of thread waiting for this..
	THREAD_ID dwThreadWaiting;
#ifdef DEBUG_CRITICAL_SECTIONS
#define MAX_SECTION_LOG_QUEUE 16
	uint32_t bCollisions ;
	CTEXTSTR pFile[16];
	uint32_t  nLine[16];
	uint32_t  nLineCS[16];
 // windows upper 16 is process ID, lower is thread ID
	THREAD_ID dwThreadPrior[16];
 // windows upper 16 is process ID, lower is thread ID
	uint8_t isLock[16];
	int nPrior;
#endif
};
#if !defined( _WIN32 )
#undef USE_NATIVE_CRITICAL_SECTION
#endif
/* <combine sack::timers::critical_section_tag>
   \ \                                          */
#if defined( USE_NATIVE_CRITICAL_SECTION )
#define CRITICALSECTION CRITICAL_SECTION
#else
typedef struct critical_section_tag CRITICALSECTION;
#endif
/* <combine sack::timers::critical_section_tag>
   defines a pointer to a CRITICALSECTION type  */
#if defined( USE_NATIVE_CRITICAL_SECTION )
#define PCRITICALSECTION LPCRITICAL_SECTION
#else
#define InitializeCriticalSection InitializeCriticalSec
typedef struct critical_section_tag *PCRITICALSECTION;
#endif
/* attempts to enter the critical section, and does not block.
   Returns
   If it enters the return is 1, else the return is 0.
   Parameters
   pcs :    pointer to a critical section
   prior :  if not NULL, prior will be set to the current thread
            ID of the owning thread.                             */
#ifndef USE_NATIVE_CRITICAL_SECTION
MEM_PROC  int32_t MEM_API  EnterCriticalSecNoWaitEx ( PCRITICALSECTION pcs, THREAD_ID *prior DBG_PASS );
#define EnterCriticalSecNoWait( pcs,prior ) EnterCriticalSecNoWaitEx( pcs, prior DBG_SRC )
#else
#define EnterCriticalSecNoWait( pcs,prior ) TryEnterCriticalSection( (pcs) )
#endif
/* <combine sack::timers::EnterCriticalSecNoWaitEx@PCRITICALSECTION@THREAD_ID *prior>
   \ \                                                                                */
//#define EnterCriticalSecNoWait( pcs,prior ) EnterCriticalSecNoWaitEx( (pcs),(prior) DBG_SRC )
/* clears all members of a CRITICALSECTION.  Same as memset( pcs, 0, sizeof( CRITICALSECTION ) ); */
#ifndef USE_NATIVE_CRITICAL_SECTION
MEM_PROC  void MEM_API  InitializeCriticalSec ( PCRITICALSECTION pcs );
#else
#define InitializeCriticalSec(pcs)  InitializeCriticalSection(pcs)
#endif
/* Get a count of how many times a critical section is locked */
//MEM_PROC  uint32_t MEM_API  CriticalSecOwners ( PCRITICALSECTION pcs );
/* Namespace of all memory related functions for allocating and
   releasing memory.                                            */
#ifdef __cplusplus
 // namespace timers
};
 // namespace sack
};
using namespace sack::timers;
#endif
#ifdef __cplusplus
namespace sack {
/* Memory namespace contains functions for allocating and
   releasing memory. Also contains methods for accessing shared
   memory (if available on the target platform).
   Allocate
   Release
   Hold
   OpenSpace                                                    */
namespace memory {
#endif
typedef struct memory_block_tag* PMEM;
// what is an abstract name for the memory mapping handle...
// where is a filename for the filebacking of the shared memory
// DigSpace( WIDE(TEXT( "Picture Memory" )), WIDE(TEXT( "Picture.mem" )), 100000 );
/* <combinewith sack::memory::OpenSpaceExx@CTEXTSTR@CTEXTSTR@uintptr_t@uintptr_t *@uint32_t*>
   \ \                                                                                 */
MEM_PROC  POINTER MEM_API  OpenSpace ( CTEXTSTR pWhat, CTEXTSTR pWhere, uintptr_t *dwSize );
/* <unfinished>
   Open a shared memory region. The region may be named with a
   text string (this does not work under linux platforms, and
   the name of the file to back the shared region is the sharing
   point). The region may be backed with a file (and must be if
   it is to be shared on linux.
   If the region exists by name, the region is opened, and a
   pointer to that region is returned.
   If the file exists, the file is opened, and mapped into
   memory, and a pointer to the file backed memory is returned.
   if the file does not exist, and the size parameter passed is
   not 0, then the file is created, and expanded to the size
   requested. The bCreate flag is set to true.
   If NULL is passed for pWhat and pWhere, then a block of
   memory is allocated in system memory, backed by pagefile.
   if dwSize is 0, then the region is specified for open only,
   and will not create.
   Parameters
   pWhat :     String to a named shared memory region. NULL is
               unnamed.
   pWhere :    Filename to back the shared memory with. The file
               name itself may also be used to share the memory.
   address :   A base address to map the memory at. If 0,
               specifies do not care.
   dwSize :    pointer to a uintptr_t that defines the size to
               create. If 0, then the region is only opened. The
               size of the region opened is set back into this
               value after it is opened.
   bCreated :  pointer to a boolean to indicate whether the space
               was created or not.
   Returns
   Pointer to region requested to be opened. NULL on failure.
   Example
   Many examples of this are appropriate.
   1) Open or create a file backed shared space.
   2) Open a file for direct memory access, the file is loaded
   into memory by system paging routines and not any API.         */
MEM_PROC  POINTER MEM_API  OpenSpaceExx ( CTEXTSTR pWhat, CTEXTSTR pWhere, uintptr_t address
	, uintptr_t *dwSize, uint32_t* bCreated );
/* <combine sack::memory::OpenSpaceExx@CTEXTSTR@CTEXTSTR@uintptr_t@uintptr_t *@uint32_t*>
   \ \                                                                             */
#define OpenSpaceEx( what,where,address,psize) OpenSpaceExx( what,where,address,psize,NULL )
/* Closes a shared memory region. Calls CloseSpaceEx() with
   bFinal set TRUE.
   Parameters
   pMem :  pointer to a memory region opened by OpenSpace.  */
MEM_PROC  void MEM_API  CloseSpace ( POINTER pMem );
/* Closes a memory region. Release can also be used to close
   opened spaces.
   Parameters
   pMem :    pointer to a memory region opened with OpenSpace()
   bFinal :  If final is set, the file used for backing the shared
             region is deleted.                                    */
MEM_PROC  void MEM_API  CloseSpaceEx ( POINTER pMem, int bFinal );
/* This can give the size back of a memory space.
   Returns
   The size of the memory block.
   Parameters
   pMem :  pointer to a block of memory that was opened with
           OpenSpace().                                      */
MEM_PROC  uintptr_t MEM_API  GetSpaceSize ( POINTER pMem );
/* even if pMem is just a POINTER returned from OpenSpace this
   will create a valid heap pointer.
   will result TRUE if a valid heap is present will result FALSE
   if heap is not able to init (has content)
   Parameters
   pMem :    pointer to a memory space to setup as a heap.
   dwSize :  size of the memory space pointed at by pMem.        */
MEM_PROC  int MEM_API  InitHeap( PMEM pMem, uintptr_t dwSize );
/* Dumps all blocks into the log.
   Parameters
   pHeap :     Heap to dump. If NULL or unspecified, dump the
               default heap.
   bVerbose :  Specify to dump each block's information,
               otherwise only summary information is generated. */
MEM_PROC  void MEM_API  DebugDumpHeapMemEx ( PMEM pHeap, LOGICAL bVerbose );
/* <combine sack::memory::DebugDumpHeapMemEx@PMEM@LOGICAL>
   Logs all of the blocks tracked in a specific heap.
   Parameters
   Heap :  Heap to dump the memory blocks of.              */
#define DebugDumpHeapMem(h)     DebugDumpMemEx( (h), TRUE )
/* <combine sack::memory::DebugDumpHeapMemEx@PMEM@LOGICAL>
   \ \                                                     */
MEM_PROC  void MEM_API  DebugDumpMemEx ( LOGICAL bVerbose );
/* Dumps all tracked heaps.
   Parameters
   None.                    */
#define DebugDumpMem()     DebugDumpMemEx( TRUE )
/* Dumps a heap to a specific file.
   Parameters
   pHeap :      Heap. If NULL or unspecified, dumps default heap.
   pFilename :  name of the file to write output to.              */
MEM_PROC  void MEM_API  DebugDumpHeapMemFile ( PMEM pHeap, CTEXTSTR pFilename );
/* <combine sack::memory::DebugDumpHeapMemFile@PMEM@CTEXTSTR>
   \ \                                                        */
MEM_PROC  void MEM_API  DebugDumpMemFile ( CTEXTSTR pFilename );
#ifdef __GNUC__
MEM_PROC  POINTER MEM_API  HeapAllocateAlignedEx ( PMEM pHeap, uintptr_t dwSize, uint16_t alignment DBG_PASS ) __attribute__( (malloc) );
MEM_PROC  POINTER MEM_API  HeapAllocateEx ( PMEM pHeap, uintptr_t nSize DBG_PASS ) __attribute__((malloc));
MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS ) __attribute__((malloc));
#else
/* \ \
   Parameters
   pHeap :  pointer to a heap which was initialized with
            InitHeap()
   Size :   Size of block to allocate                    */
MEM_PROC  POINTER MEM_API  HeapAllocateEx ( PMEM pHeap, uintptr_t nSize DBG_PASS );
/* \ Parameters
pHeap :  pointer to a heap which was initialized with
InitHeap()
Size :   Size of block to allocate
Alignment : count of bytes to return block on (1,2,4,8,16,32)  */
MEM_PROC  POINTER MEM_API  HeapAllocateAlignedEx( PMEM pHeap, uintptr_t nSize, uint16_t alignment DBG_PASS );
/* Allocates a block of memory of specific size. Debugging
   information if passed is recorded on the block.
   Parameters
   size :  size of the memory block to create              */
MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS );
#endif
/* A simple macro to allocate a new single unit of a structure. Adds
   a typecast automatically to be (type*) so C++ compilation is
   clean. Does not burden the user with extra typecasts. This,
   being in definition use means that all other things that are
   typecast are potentially error prone. Memory is considered
   uninitialized.
   Parameters
   type :  type to allocate
   Example
   <code lang="c++">
   int *p_int = New( int );
   </code>                                                           */
#define New(type) ((type*)HeapAllocate(0,sizeof(type)))
/* Reallocates an array of type.
   Parameters
   type :  type to use for sizeof(type) * sz for resulting size.
   p :     pointer to realloc
   sz :    count of elements in the array                        */
#define Renew(type,p,sz) ((type*)HeapReallocate(0,p, sizeof(type)*sz))
/* an advantage of C, can define extra space at end of structure
   which is allowed to carry extra data, which is unknown by
   other code room for exploits rock.
   Parameters
   type :   passed to sizeof()
   extra :  Number of additional bytes to allocate beyond the
            sizeof( type )
   Example
   Create a text segment plus 18 characters of data. (This
   should not be done, use SegCreate instead)
   <code lang="c#">
   PTEXT text = NewPlus( TEXT, 18 );
   </code>                                                       */
#define NewPlus(type,extra) ((type*)HeapAllocate(0,sizeof(type)+(extra)))
/* Allocate a new array of type.
   Parameters
   type :   type to determine size of array element to allocate.
   count :  count of elements to allocate in the array.
   Returns
   A pointer to type. (this is important, since in C++ it's cast
   correctly to the destination type).                           */
#define NewArray(type,count) ((type*)HeapAllocate(0,sizeof(type)*(count)))
/* Allocate sizeof(type). Will invoke some sort of registered
   initializer
   Parameters
   type :  type to allocate for. Passes the name of the type so
           the allocator can do a registered procedure lookup and
           invok an initializer for the type.                     */
//#define NewObject(type) ((type*)FancyAllocate(sizeof(type),#type DBG_SRC))
#ifdef __cplusplus
/* A 'safe' release macro. casts the block to the type to
   release. Makes sure the pointer being released is the type
   specified.
   Parameters
   type :   type of the variable
   thing :  the thing to actually release.                    */
#  ifdef _DEBUG
#    define Deallocate(type,thing) for(type _zzqz_tmp=thing;ReleaseEx((POINTER)(_zzqz_tmp)DBG_SRC),0;)
#  else
#    define Deallocate(type,thing) ReleaseEx((POINTER)(thing)DBG_SRC)
#  endif
#else
#  define Deallocate(type,thing) (ReleaseEx((POINTER)(thing)DBG_SRC))
#endif
/* <combine sack::memory::HeapAllocateEx@PMEM@uintptr_t nSize>
   \ \                                                        */
#define HeapAllocate(heap, n) HeapAllocateEx( (heap), (n) DBG_SRC )
   /* <combine sack::memory::HeapAllocateAlignedEx@PMEM@uintptr_t@uint32_t>
   \ \                                                        */
#define HeapAllocateAligned(heap, n, m) HeapAllocateAlignedEx( (heap), (n), m DBG_SRC )
   /* <combine sack::memory::AllocateEx@uintptr_t nSize>
   \ \                                               */
#ifdef FIX_RELEASE_COM_COLLISION
#else
#define Allocate( n ) HeapAllocateEx( (PMEM)0, (n) DBG_SRC )
#endif
//MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS );
//#define Allocate(n) AllocateEx(n DBG_SRC )
MEM_PROC  POINTER MEM_API  GetFirstUsedBlock ( PMEM pHeap );
/* Releases an allocated block. Memory becomes free to allocate
   again. If debugging information is passed, the releasing
   source and line is recorded in the block. (can be used to
   find code deallocating memory it shouldn't).
   This also works with Hold(), and decrements the hold counter.
   If there are no more holds on the block, then the block is
   released.
   Parameters
   p :  pointer to allocated block to release.                   */
MEM_PROC  POINTER MEM_API  ReleaseEx ( POINTER pData DBG_PASS ) ;
/* <combine sack::memory::ReleaseEx@POINTER pData>
   \ \                                             */
#ifdef FIX_RELEASE_COM_COLLISION
#else
/* <combine sack::memory::ReleaseEx@POINTER pData>
   \ \                                             */
#define Release(p) ReleaseEx( (p) DBG_SRC )
#endif
/* Adds a usage count to a block of memory. For each count
   added, an additional release must be used. This can be used
   to keep a copy of the block, even if some other code
   automatically releases it.
   Parameters
   pointer :  pointer to a block of memory that was Allocate()'d.
   Example
   Allocate a block of memory, and release it properly. But we
   passed it to some function. That function wanted to keep a
   copy of the block, so it can apply a hold. It needs to later
   do a Release again to actually free the memory.
   <code lang="c++">
   POINTER p = Allocate( 32 );
   call_some_function( p );
   Release( p );
   void call_some_function( POINTER p )
   {
      static POINTER my_p_copy;
      my_p_copy = p;
      Hold( p );
   }
   </code>                                                        */
MEM_PROC  POINTER MEM_API  HoldEx ( POINTER pData DBG_PASS  );
/* <combine sack::memory::HoldEx@POINTER pData>
   \ \                                          */
#define Hold(p) HoldEx(p DBG_SRC )
/* This can be used to add additional space after the end of a
   memory block.
   Parameters
   pHeap :   If NULL or not specified, uses the common memory heap.
   source :  pointer to the block to pre\-allocate. If NULL, a new
             memory block will be allocated that is filled with 0.
   size :    the new size of the block.
   Returns
   A pointer to a new block of memory that is the new size.
   Remarks
   If the size specified for the new block is larger than the
   previous size of the block, the curernt data is copied to the
   beginning of the new block, and the memory after the existing
   content is cleared to 0.
   If the size specified for the new block is smaller than the
   previous size, the end of the original block is not copied to
   the new block.
   If NULL is passed as the source block, then a new block
   filled with 0 is created.                                        */
MEM_PROC  POINTER MEM_API  HeapReallocateAlignedEx ( PMEM pHeap, POINTER source, uintptr_t size, uint16_t alignment DBG_PASS );
MEM_PROC  POINTER MEM_API  HeapReallocateEx ( PMEM pHeap, POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::HeapReallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                 */
#define HeapReallocateAligned(heap,p,sz,al) HeapReallocateEx( (heap),(p),(sz),(al) DBG_SRC )
#define HeapReallocate(heap,p,sz) HeapReallocateEx( (heap),(p),(sz) DBG_SRC )
/* <combine sack::memory::HeapReallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                 */
MEM_PROC  POINTER MEM_API  ReallocateEx ( POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::ReallocateEx@POINTER@uintptr_t size>
   \ \                                                        */
#ifdef FIX_RELEASE_COM_COLLISION
#else
#define Reallocate(p,sz) ReallocateEx( (p),(sz) DBG_SRC )
#endif
/* This can be used to add additional space before the beginning
   of a memory block.
   Parameters
   pHeap :   If NULL or not specified, uses the common memory heap.
   source :  pointer to the block to pre\-allocate. If NULL, a new
             memory block will be allocated that is filled with 0.
   size :    the new size of the block.
   Returns
   A pointer to a new block of memory that is the new size.
   Remarks
   If the size specified for the new block is larger than the
   previous size of the block, the content data is copied to the
   end of the new block, and the memory leading up to the block
   is cleared to 0.
   If the size specified for the new block is smaller than the
   previous size, the end of the original block is not copied to
   the new block.
   If NULL is passed as the source block, then a new block
   filled with 0 is created.                                        */
MEM_PROC  POINTER MEM_API  HeapPreallocateEx ( PMEM pHeap, POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::HeapPreallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                  */
#define HeapPreallocate(heap,p,sz) HeapPreallocateEx( (heap),(p),(sz) DBG_SRC )
/* <combine sack::memory::HeapPreallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                  */
MEM_PROC  POINTER MEM_API  PreallocateAlignedEx ( POINTER source, uintptr_t size, uint16_t alignment DBG_PASS );
MEM_PROC  POINTER MEM_API  PreallocateEx ( POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::PreallocateEx@POINTER@uintptr_t size>
   \ \                                                         */
#define PreallocateAligned(p,sz,al) PreallocateAlignedEx( (p),(sz),(al) DBG_SRC )
#define Preallocate(p,sz) PreallocateEx( (p),(sz) DBG_SRC )
/* Moves a block of memory from one heap to another.
   Parameters
   pNewHeap :  heap target to move the block to.
   source :    source block to move \- pointer to the data in the
               block.
   Remarks
   Since each block remembers its own size, it is possible to
   move a block from one heap to another. A heap might be a
   memory mapped file at a specific address for instance.         */
MEM_PROC  POINTER MEM_API  HeapMoveEx ( PMEM pNewHeap, POINTER source DBG_PASS );
/* <combine sack::memory::HeapMoveEx@PMEM@POINTER source>
   \ \                                                    */
#define HeapMove(h,s) HeapMoveEx( (h), (s) DBG_SRC )
/* \returns the size of a memory block which was Allocate()'d.
   Parameters
   pData :  pointer to a allocated memory block.
   Returns
   The size of the block that was specified by the Allocate(). */
MEM_PROC uintptr_t MEM_API  SizeOfMemBlock ( CPOINTER pData );
/* \returns the allocation alignment of a memory block which was Allocate()'d.
Parameters
pData :  pointer to a allocated memory block.
Returns
The alignment of the block that was specified from Allocate(). */
MEM_PROC uint16_t  AlignOfMemBlock( CPOINTER pData );
/* not so much of a fragment as a consolidation. Finds a free
   spot earlier in the heap and attempts to move the block
   there. This can help alleviate heap fragmentation.
   Parameters
   ppMemory :  pointer to a pointer to memory which might move */
MEM_PROC  LOGICAL MEM_API  Defragment ( POINTER *ppMemory );
/* \ \
   Parameters
   pHeap :        pointer to a heap
   pFree :        pointer to a 32 bit value to receive the size
                  of free space
   pUsed :        pointer to a 32 bit value to receive the size
                  of used space
   pChunks :      pointer to a 32 bit value to receive the total
                  count of chunks.
   pFreeChunks :  pointer to a 32 bit value to receive the total
                  count of free chunks.
   Remarks
   It looks like DBG_PASS parameter isn't used... not sure why
   it would here, there is no allocate or delete.
   The count of allocated chunks can be gotten by subtracting
   FreeChunks from Chunks.
   Example
   <code lang="c++">
   uint32_t free;
   uint32_t used;
   uint32_t chunks;
   uint32_t free_chunks;
   GetHeapMemStatsEx( NULL, &amp;free, &amp;used, &amp;chunks, &amp;free_chunks );
   </code>                                                                         */
MEM_PROC  void MEM_API  GetHeapMemStatsEx ( PMEM pHeap, uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks DBG_PASS );
/* <combine sack::memory::GetHeapMemStatsEx@PMEM@uint32_t *@uint32_t *@uint32_t *@uint32_t *pFreeChunks>
   \ \                                                                               */
#define GetHeapMemStats(h,f,u,c,fc) GetHeapMemStatsEx( h,f,u,c,fc DBG_SRC )
//MEM_PROC  void MEM_API  GetHeapMemStats ( PMEM pHeap, uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks );
MEM_PROC  void MEM_API  GetMemStats ( uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks );
/* Sets whether to log allocations or not.
   \returns the prior state of logging...
   Parameters
   bTrueFalse :  if TRUE, allocation logging is turned on. Enables
                 logging when each block is Allocated, Released,
                 or Held.                                          */
MEM_PROC  int MEM_API  SetAllocateLogging ( LOGICAL bTrueFalse );
/* disables storing file/line, also disables auto GetMemStats
   checking
   Parameters
   bDisable :  set to TRUE to disable allocate debug logging. */
MEM_PROC  int MEM_API  SetAllocateDebug ( LOGICAL bDisable );
/* disables auto GemMemStats on every allocate/release/Hold
   GetMemStats will evaluate each and every block allocated in
   memory and inspect it for corruption.
   Parameters
   bDisable :  set to TRUE to disable auto mem check.          */
MEM_PROC  int MEM_API  SetManualAllocateCheck ( LOGICAL bDisable );
/* Sets whether to log critical sections or not.
   \returns the prior state of logging...
   Parameters
   bTrueFalse :  if TRUE, critical section logging is turned on. Logs
                 when each thread enters or leaves a
                 CRITICIALSECTION.                                    */
MEM_PROC  int MEM_API  SetCriticalLogging ( LOGICAL bTrueFalse );
/* Sets the minimum size to allocate. If a block size less than
   this is allocated, then this much is actually allocated.
   Parameters
   nSize :  Specify the minimum allocation size                 */
MEM_PROC  void MEM_API  SetMinAllocate ( size_t nSize );
/* Sets how much a heap is expanded by when it is out of space. Default
   is like 512k.
   Parameters
   dwSize :  the new size to expand heaps by.
   Remarks
   Probably internally, this is rounded up to the next 4k
   boundary.                                                            */
MEM_PROC  void MEM_API  SetHeapUnit ( size_t dwSize );
/* Multi-processor safe exchange operation. Returns the prior
   value at the pointer.
   Parameters
   p :    pointer to a volatile 64 bit value.
   val :  a new 64 bit value to put at (*p)
   Example
   <code lang="c#">
   uint64_t value = 13;
   uint64_t oldvalue = LockedExchange64( &amp;value, 15 );
   // old value will be 13
   // value will be 15
   </code>                                                    */
MEM_PROC  uint64_t MEM_API  LockedExchange64 ( volatile uint64_t* p, uint64_t val );
/* A multi-processor safe increment of a variable.
   Parameters
   p :  pointer to a 32 bit value to increment.    */
MEM_PROC  uint32_t MEM_API  LockedIncrement ( uint32_t* p );
/* Does a multi-processor safe decrement on a variable.
   Parameters
   p :  pointer to a 32 bit value to decrement.         */
MEM_PROC  uint32_t MEM_API  LockedDecrement ( uint32_t* p );
#ifdef __cplusplus
// like also __if_assembly__
//extern "C" {
#endif
#ifdef __64__
#define LockedExchangePtrSzVal(a,b) LockedExchange64((volatile uint64_t*)(a),b)
#else
#define LockedExchangePtrSzVal(a,b) LockedExchange((volatile uint32_t*)(a),b)
#endif
/* Multiprocessor safe swap of the contents of a variable with a
   new value, and result with the old variable.
   Parameters
   p :    pointer to a 32 bit value to exchange
   val :  value to set into the variable
   Returns
   The prior value in p.
   Example
   <code>
   uint32_t variable = 0;
   uint32_t oldvalue = LockedExchange( &amp;variable, 1 );
   </code>                                                       */
MEM_PROC  uint32_t MEM_API  LockedExchange ( volatile uint32_t* p, uint32_t val );
/* Sets a 32 bit value into memory. If the length to set is not
   a whole number of 32 bit words, the last bytes may contain
   the low 16 bits of the value and the low 8 bits.
   Parameters
   p :   pointer to memory to set
   n :   32 bit value to set memory with
   sz :  length to set
   Remarks
   Writes as many 32 it values as will fit in sz.
   If (sz &amp; 2), the low 16 bits of n are written at the end.
   then if ( sz &amp; 1 ) the low 8 bits of n are written at the
   end.                                                          */
MEM_PROC  void MEM_API  MemSet ( POINTER p, uintptr_t n, size_t sz );
//#define _memset_ MemSet
/* memory copy operation. not safe when buffers overlap. Performs
   platform-native memory stream operation to copy from one
   place in memory to another. (32 or 64 bit operations as
   possible).
   Parameters
   pTo :    Memory to copy to
   pFrom :  memory to copy from
   sz :     size of block of memory to copy                       */
MEM_PROC  void MEM_API  MemCpy ( POINTER pTo, CPOINTER pFrom, size_t sz );
//#define _memcpy_ MemCpy
/* Binary byte comparison of one block of memory to another. Results
   \-1 if less, 1 if more and 0 if equal.
   Parameters
   pOne :  pointer to memory one
   pTwo :  pointer to some other memory
   sz :    count of bytes to compare
   Returns
   0 if equal
   \-1 if the first different byte in pOne is less than pTwo.
   1 if the first different byte in pOne is more than pTwo.          */
MEM_PROC  int MEM_API  MemCmp ( CPOINTER pOne, CPOINTER pTwo, size_t sz );
	/* nothing.
   does nothing, returns nothing. */
//#define memnop(mem,sz,comment)
#ifdef __cplusplus
//};
#endif
/* Compares two strings. Must match exactly.
   Parameters
   s1 :  string to compare
   s2 :  string to compare
   Returns
   0 if equal.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
	if s1 and s2 are NULL return is 0.              */
#ifdef StrCmp
#undef StrCmp
 // StrCmp
#endif
MEM_PROC  int MEM_API  StrCmp ( CTEXTSTR pOne, CTEXTSTR pTwo );
/* Compares two strings, case insensitively.
   Parameters
   s1 :  string to compare
   s2 :  string to compare
   Returns
   0 if equal.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
   if s1 and s2 are NULL return is 0.              */
MEM_PROC  int MEM_API  StrCaseCmp ( CTEXTSTR s1, CTEXTSTR s2 );
/* String insensitive case comparison with maximum length
   specified.
   Parameters
   s1 :      string to compare
   s2 :      string to compare
   maxlen :  maximum character required to match
   Returns
   0 if equal up to the number of characters.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
   if s1 and s2 are NULL return is 0.                     */
MEM_PROC  int MEM_API  StrCaseCmpEx ( CTEXTSTR s1, CTEXTSTR s2, size_t maxlen );
/* This searches a string for the first character that matches
   some specified character.
   A custom strchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This flavor is the only one on C where operator overloading
   cannot switch between CTEXTSTR and TEXTSTR parameters, to
   \result with the correct type. If a CTEXTSTR is passed to
   this it should result with a CTEXTSTR, but if that's the only
   choice, then the result of this is never modifiable, even if
	it is a pointer to a non-const TEXTSTR.                       */
MEM_PROC  CTEXTSTR MEM_API  StrChr ( CTEXTSTR s1, TEXTCHAR c );
/* copy S2 to S1, with a maximum of N characters.
   The last byte of S1 will always be a 'nul'. If S2 was longer
   than S1, then it will be truncated to fit within S1. Perferred
   method over this is SaveText or StrDup.
   Parameters
   s1 :      desitnation TEXTCHAR buffer
   s2 :      source string
   length :  the maximum number of characters that S1 can hold. (this
             is not a size, but is a character count)                 */
MEM_PROC  TEXTSTR MEM_API  StrCpyEx ( TEXTSTR s1, CTEXTSTR s2, size_t n );
/* copy S2 to S1. This is 'unsafe', since neither paramter's
   size is known. Prefer StrCpyEx which passes the maximum
   length for S1.
   Parameters
   s1 :  desitnation TEXTCHAR buffer
   s2 :  source string                                       */
MEM_PROC  TEXTSTR MEM_API  StrCpy ( TEXTSTR s1, CTEXTSTR s2 );
/* \Returns the count of characters in a string.
   Parameters
   s :  string to measure
   Returns
   length of string.                             */
MEM_PROC  size_t MEM_API  StrLen ( CTEXTSTR s );
/* Get the length of a string in C chars.
   Parameters
   s :  char * to count.
   Returns
   the length of s. If s is NULL, return 0. */
MEM_PROC  size_t MEM_API  CStrLen ( char const*s );
/* Finds the last instance of a character in a string.
   Parameters
   s1 :  String to search in
   c :   character to find
   Returns
   NULL if character is not in the string.
   a pointer to the last character in s1 that matches c. */
MEM_PROC  CTEXTSTR MEM_API  StrRChr ( CTEXTSTR s1, TEXTCHAR c );
#ifdef __cplusplus
/* This searches a string for the first character that matches
   some specified character.
   A custom strchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This second flavor is only available on C++ where operator
   overloading will switch between CTEXTSTR and TEXTSTR
   \parameters, to result with the correct type. If a CTEXTSTR
   is passed to this it should result with a CTEXTSTR, but if
   that's the only choice, then the result of this is never
   modifiable, even if it is a pointer to a non-const TEXTSTR.  */
MEM_PROC  TEXTSTR MEM_API  StrChr ( TEXTSTR s1, TEXTCHAR c );
/* This searches a string for the last character that matches
   some specified character.
   A custom strrchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This second flavor is only available on C++ where operator
   overloading will switch between CTEXTSTR and TEXTSTR
   \parameters, to result with the correct type. If a CTEXTSTR
   is passed to this it should result with a CTEXTSTR, but if
   that's the only choice, then the result of this is never
   modifiable, even if it is a pointer to a non-const TEXTSTR.  */
MEM_PROC  TEXTSTR MEM_API  StrRChr ( TEXTSTR s1, TEXTCHAR c );
/* <combine sack::memory::StrCmp@CTEXTSTR@CTEXTSTR>
   \ \                                              */
MEM_PROC  int MEM_API  StrCmp ( const char * s1, CTEXTSTR s2 );
#endif
/* <combine sack::memory::StrCmp@char *@CTEXTSTR>
   \ \                                            */
MEM_PROC  int MEM_API  StrCmpEx ( CTEXTSTR s1, CTEXTSTR s2, INDEX maxlen );
/* Finds an instance of a string in another string.
   Custom implementation because strstr is declared unsafe, and
   to handle switching between unicode and char.
   Parameters
   s1 :  the string to search in
   s2 :  the string to locate
   Returns
   NULL if s2 is not in s1.
   The beginning of the string in s1 that matches s2.
   Example
   <code lang="c++">
   TEXTCHAR const *found = StrStr( WIDE( "look in this string" ), WIDE( "in" ) );
                                               ^returns a pointer to here.
   </code>                                                                        */
MEM_PROC  CTEXTSTR MEM_API  StrStr ( CTEXTSTR s1, CTEXTSTR s2 );
#ifdef __cplusplus
/* Finds an instance of a string in another string.
   Custom implementation because strstr is declared unsafe, and
   to handle switching between unicode and char.
   Parameters
   s1 :  the string to search in
   s2 :  the string to locate
   Returns
   NULL if s2 is not in s1.
   The beginning of the string in s1 that matches s2.
   Example
   <code>
   TEXTCHAR *writable_string = StrDup( WIDE( "look in this string" ) );
   TEXTCHAR *found = StrStr( writable_string, WIDE( "in" ) );
   // returns a pointer to 'in' in the writable string, which can then be modified.
   </code>                                                                          */
MEM_PROC  TEXTSTR MEM_API  StrStr ( TEXTSTR s1, CTEXTSTR s2 );
#endif
/* Searches for one string in another. Compares case
   insensitively.
   Parameters
   s1 :  string to search in
   s2 :  string to locate
   See Also
   <link sack::memory::StrStr@CTEXTSTR@CTEXTSTR, StrStr> */
MEM_PROC  CTEXTSTR MEM_API  StrCaseStr ( CTEXTSTR s1, CTEXTSTR s2 );
/* This duplicates a block of memory.
   Parameters
   p :  pointer to a block of memory that was allocated.
   Returns
   a pointer to a new block of memory that has the same content
   as the original.                                             */
MEM_PROC  POINTER MEM_API  MemDupEx ( CPOINTER thing DBG_PASS );
/* <combine sack::memory::MemDupEx@CPOINTER thing>
   \ \                                             */
#define MemDup(thing) MemDupEx(thing DBG_SRC )
/* Duplicates a string, and returns a pointer to the copy.
   Parameters
   original :  string to duplicate                         */
MEM_PROC  TEXTSTR MEM_API  StrDupEx ( CTEXTSTR original DBG_PASS );
/* Translates from a TEXTCHAR string to a char string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  char *  MEM_API  CStrDupEx ( CTEXTSTR original DBG_PASS );
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  wchar_t *  MEM_API  DupTextToWideEx( CTEXTSTR original DBG_PASS );
#define DupTextToWide(s) DupTextToWideEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  char *     MEM_API  DupTextToCharEx( CTEXTSTR original DBG_PASS );
#define DupTextToChar(s) DupTextToCharEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC TEXTSTR     MEM_API  DupWideToTextEx( const wchar_t *original DBG_PASS );
#define DupWideToText(s) DupWideToTextEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC TEXTSTR     MEM_API  DupCharToTextEx( const char *original DBG_PASS );
#define DupCharToText(s) DupCharToTextEx( s DBG_SRC )
/* Converts from 8 bit char to 16 bit wchar (or no-op if not
   UNICODE compiled)
   Parameters
   original :  original string of C char.
   Returns
   a pointer to a wide character string.                     */
MEM_PROC  TEXTSTR MEM_API  DupCStrEx ( const char * original DBG_PASS );
/* Converts from 8 bit char to 16 bit wchar (or no-op if not
UNICODE compiled)
Parameters
original :  original string of C char.
Returns
a pointer to a wide character string.                     */
MEM_PROC  TEXTSTR MEM_API  DupCStrLenEx( const char * original, size_t chars DBG_PASS );
/* <combine sack::memory::StrDupEx@CTEXTSTR original>
   \ \                                                */
#define StrDup(o) StrDupEx( (o) DBG_SRC )
/* <combine sack::memory::CStrDupEx@CTEXTSTR original>
   \ \                                                 */
#define CStrDup(o) CStrDupEx( (o) DBG_SRC )
/* <combine sack::memory::DupCStrEx@char * original>
   \ \                                               */
#define DupCStr(o) DupCStrEx( (o) DBG_SRC )
/* <combine sack::memory::DupCStrLenEx@char * original@size_t chars>
   \ \                                               */
#define DupCStrLen(o,l) DupCStrLenEx( (o),(l) DBG_SRC )
//------------------------------------------------------------------------
#if 0
// this code was going to provide network oriented shared memory.
#ifndef TRANSPORT_STRUCTURE_DEFINED
typedef uintptr_t PTRANSPORT_QUEUE;
struct transport_queue_tag { uint8_t private_data_here; };
#endif
MEM_PROC  struct transport_queue_tag * MEM_API  CreateQueue ( int size );
MEM_PROC  int MEM_API  EnqueMessage ( struct transport_queue_tag *queue, POINTER msg, int size );
MEM_PROC  int MEM_API  DequeMessage ( struct transport_queue_tag *queue, POINTER msg, int *size );
MEM_PROC  int MEM_API  PequeMessage ( struct transport_queue_tag *queue, POINTER *msg, int *size );
#endif
//------------------------------------------------------------------------
#ifdef __cplusplus
 // namespace memory
};
 // namespace sack
};
using namespace sack::memory;
#if defined( _DEBUG ) || defined( _DEBUG_INFO )
/*
inline void operator delete( void * p )
{ Release( p ); }
#ifdef DELETE_HANDLES_OPTIONAL_ARGS
inline void operator delete (void * p DBG_PASS )
{ ReleaseEx( p DBG_RELAY ); }
#define delete delete( DBG_VOIDSRC )
#endif
//#define deleteEx(file,line) delete(file,line)
#ifdef USE_SACK_ALLOCER
inline void * operator new( size_t size DBG_PASS )
{ return AllocateEx( (uintptr_t)size DBG_RELAY ); }
static void * operator new[]( size_t size DBG_PASS )
{ return AllocateEx( (uintptr_t)size DBG_RELAY ); }
#define new new( DBG_VOIDSRC )
#define newEx(file,line) new(file,line)
#endif
*/
// common names - sometimes in conflict when declaring
// other functions... AND - release is a common
// component of iComObject
//#undef Allocate
//#undef Release
// Hmm wonder where this conflicted....
//#undef LineDuplicate
#else
#ifdef USE_SACK_ALLOCER
inline void * operator new(size_t size)
{ return AllocateEx( size ); }
inline void operator delete (void * p)
{ ReleaseEx( p ); }
#endif
#endif
#endif
#endif
#ifndef _TIMER_NAMESPACE
#ifdef __cplusplus
#define _TIMER_NAMESPACE namespace timers {
/* define a timer library namespace in C++. */
#define TIMER_NAMESPACE SACK_NAMESPACE namespace timers {
/* define a timer library namespace in C++ end. */
#define TIMER_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define _TIMER_NAMESPACE
#define TIMER_NAMESPACE
#define TIMER_NAMESPACE_END
#endif
#endif
// this is a method replacement to use PIPEs instead of SEMAPHORES
// replacement code only affects linux.
#if defined( __QNX__ ) || defined( __MAC__) || defined( __LINUX__ ) || defined( __ANDROID__ )
#  define USE_PIPE_SEMS
// no semtimedop; no semctl, etc
//#include <sys/sem.h>
#endif
#ifdef USE_PIPE_SEMS
#  define _NO_SEMTIMEDOP_
#endif
SACK_NAMESPACE
/* This namespace contains methods for working with timers and
   threads. Since timers are implemented in an asynchronous
   thread, the thread creation and control can be exposed here
   also.
   ThreadTo
   WakeThread
   WakeableSleep [Example]
   AddTimer
   RemoveTimer
   RescheduleTimer
   EnterCriticalSec see Also
 EnterCriticalSecNoWait
   LeaveCriticalSec                                            */
_TIMER_NAMESPACE
#ifdef TIMER_SOURCE
#define TIMER_PROC(type,name) EXPORT_METHOD type CPROC name
#else
/* Defines import export and call method for timers. Looks like
   timers are native calltype by default instead of CPROC.      */
#define TIMER_PROC(type,name) IMPORT_METHOD type CPROC name
#endif
#if defined( __LINUX__ ) || defined( __ANDROID__ )
TIMER_PROC( uint32_t, timeGetTime )( void );
TIMER_PROC( uint32_t, GetTickCount )( void );
TIMER_PROC( void, Sleep )( uint32_t ms );
#endif
/* Function signature for user callbacks passed to AddTimer. */
typedef void (CPROC *TimerCallbackProc)( uintptr_t psv );
/* Adds a new periodic timer. From now, until the timer is
   removed with RemoveTimer, it will call the timer procedure at
   the specified frequency of milliseconds. The delay until the
   first time the timer fires can be specified independant of
   frequency. If it is not specified, the first time the timer
   will get invoked is at +1 frequency from now.
   Parameters
   start :      how long in milliseconds until the timer starts. Can
                be 0 and timer will fire at the next opportunity.
   frequency :  how long the delay is between event invocations,
                in milliseconds.
   callback :   user routine to call when the timer's delay
                expires.
   user :       user data to pass to the callback when it is
                invoked.
   Returns
   a 32 bit ID that identifies the timer for this application.
   Example
   First some setup valid for all timer creations...
   <code lang="c++">
   void CPROC TimerProc( uintptr_t user_data )
   {
       // user_data of the timer is the 'user' parameter passed to AddTimer(Exx)
   }
   </code>
   you might want to save this for something like
   RescheduleTimer
   <code>
   uint32_t timer_id;
   </code>
   Create a simple timer, it will fire at 250 milliseconds from
   now, and again every 250 milliseconds from the time it
   starts.
   <code lang="c++">
   timer_id = AddTimer( 250, TimerProc, 0 );
   </code>
   Create a timer that fires immediately, and 732 milliseconds
   after, passing some value 1234 as user data...
   <code lang="c++">
   timer_id = AddTimerEx( 0, 732, TimerProc, 1234 );
	</code>
	Remarks
	if a timer is dispatched and needs to wait - please link with idlelib, and call Idle.
	this will allow other timers to fire on schedule.  The timer that is waiting is not
	in the list of timers to process.
	*/
TIMER_PROC( uint32_t, AddTimerExx )( uint32_t start, uint32_t frequency
					, TimerCallbackProc callback
					, uintptr_t user DBG_PASS);
/* <combine sack::timers::AddTimerExx@uint32_t@uint32_t@TimerCallbackProc@uintptr_t user>
   \ \                                                                         */
#define AddTimerEx( s,f,c,u ) AddTimerExx( (s),(f),(c),(u) DBG_SRC )
/* <combine sack::timers::AddTimerExx@uint32_t@uint32_t@TimerCallbackProc@uintptr_t user>
   \ \                                                                         */
#define AddTimer( f, c, u ) AddTimerExx( (f), (f), (c), (u) DBG_SRC)
/* Stops a timer. The next time this timer would run, it will be
   removed. If it is currently dispatched, it is safe to remove
   from within the timer itself.
   Parameters
   timer :  32 bit timer ID from AddTimer.                       */
TIMER_PROC( void, RemoveTimer )( uint32_t timer );
/* Reschedule when a timer can fire. The delay can be 0 to make
   wake the timer.
   Parameters
   timer :  32 bit timer identifier from AddTimer.
   delay :  How long before the timer should run now.<p />If 0,
            will issue timer immediately.<p />If not specified,
            using the macro, the default delay is the timer's
            frequency. (can prevent the timer from firing until
            it's frequency from now.)                           */
TIMER_PROC( void, RescheduleTimerEx )( uint32_t timer, uint32_t delay );
/* <combine sack::timers::RescheduleTimerEx@uint32_t@uint32_t>
   \ \                                               */
TIMER_PROC( void, RescheduleTimer )( uint32_t timer );
/* Changes the frequency of a timer. Reschedule timer only
   changes the next time it fires, this can adjust the
   frequency. The simple ChangeTimer macro is sufficient.
   Parameters
   ID :         32 bit ID of the time created by AddTimer.
   initial :    initial delay of the timer. (Might matter if the
                timer hasn't fired the first time)
   frequency :  new delay between timer callback invokations.    */
TIMER_PROC( void, ChangeTimerEx )( uint32_t ID, uint32_t initial, uint32_t frequency );
/* <combine sack::timers::ChangeTimerEx@uint32_t@uint32_t@uint32_t>
   \ \                                               */
#define ChangeTimer( ID, Freq ) ChangeTimerEx( ID, Freq, Freq )
/* This is the type returned by MakeThread, and passed to
   ThreadTo. This is a private structure, and no definition is
   publicly available, this should be treated like a handle.   */
typedef struct threads_tag *PTHREAD;
/* Function signature for a thread entry point passed to
   ThreadTo.                                             */
typedef uintptr_t (CPROC*ThreadStartProc)( PTHREAD );
/* Function signature for a thread entry point passed to
   ThreadToSimple.                                             */
typedef uintptr_t (*ThreadSimpleStartProc)( POINTER );
/* Create a separate thread that starts in the routine
   specified. The uintptr_t value (something that might be a
   pointer), is passed in the PTHREAD structure. (See
   GetThreadParam)
   Parameters
   proc :       starting routine for the thread
   user_data :  some value that can be stored in the number of
                bits that a pointer is. This is passed to the
                proc when the thread starts.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( PTHREAD, ThreadToEx )( ThreadStartProc proc, uintptr_t param DBG_PASS );
/* <combine sack::timers::ThreadToEx@ThreadStartProc@uintptr_t param>
   \ \                                                               */
#define ThreadTo(proc,param) ThreadToEx( proc,param DBG_SRC )
/* Create a separate thread that starts in the routine
   specified. The uintptr_t value (something that might be a
   pointer), is passed in the PTHREAD structure. (See
   GetThreadParam)
   Parameters
   proc :       starting routine for the thread
   user_data :  some value that can be stored in the number of
                bits that a pointer is. This is passed to the
                proc when the thread starts.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( PTHREAD, ThreadToSimpleEx )( ThreadSimpleStartProc proc, POINTER param DBG_PASS );
/* <combine sack::timers::ThreadToEx@ThreadStartProc@uintptr_t param>
   \ \                                                               */
#define ThreadToSimple(proc,param) ThreadToSimpleEx( proc,param DBG_SRC )
/* \Returns a PTHREAD that represents the current thread. This
   can be used to create a PTHREAD identifier for the main
   thread.
   Parameters
   None.
   Returns
   a pointer to a thread structure that identifies the current
   thread. If this thread already has this structure created,
   the same one results on subsequent MakeThread calls.        */
TIMER_PROC( PTHREAD, MakeThread )( void );
/* Releases resources associated with a PTHREAD. For purposes of
   waking a thread, and providing a wakeable point for the
   thread, a system blocking event object is allocated, named
   with the THREAD_ID so it can be referenced by other
   processes. This is only allowed to be done by the thread
   itself.
   Parameters
   Param1 :  \Description
   Param2 :  \Description
   Example
   <code lang="c++">
   int main( void )
   {
       PTHREAD myself = MakeThread();
       // create threads, do stuff...
       UnmakeThread();
       At this point the pointer in 'myself' is invalid, and should be cleared.
       myself = NULL;
   }
   </code>                                                                      */
TIMER_PROC( void, UnmakeThread )( void );
/* This returns the parameter passed as user data to ThreadTo.
   Parameters
   thread :  thread to get the parameter from.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( uintptr_t, GetThreadParam )( PTHREAD thread );
/* \returns the numeric THREAD_ID from a PTHREAD.
   Parameters
   thread :  thread to get the system wide unique ID of. */
TIMER_PROC( THREAD_ID, GetThreadID )( PTHREAD thread );
/* \returns the numeric THREAD_ID from a PTHREAD.
   Parameters
   thread :  thread to get the system wide unique ID of. */
TIMER_PROC( THREAD_ID, GetThisThreadID )( void );
/* Symbol defined to pass to Wakeable_Sleep to sleep until
   someone calls WakeThread.                               */
#define SLEEP_FOREVER 0xFFFFFFFF
/* Sleeps a number of milliseconds or until the thread is passed
   to WakeThread.
   Parameters
   dwMilliseconds :  How long to sleep. Can be indefinite if
                     value is SLEEP_FOREVER.
   Example
   <code lang="c++">
   PTHREAD main_thread;
   uintptr_t CPROC WakeMeThread( PTHREAD thread )
   {
      // get the value passed to ThreadTo as user_data.
      uintptr_t user_data = GetThreadParam( thread );
      // let the main thread sleep a little wile
       WakeableSleep( 250 );
      // then wake it up
       WakeThread( main_thread );
       return 0;
   }
   int main( void )
   {
       // save my PTHREAD globally.
       main_thread = MakeThread();
       // create a thread that can wake us
       ThreadTo( WakeMeThread, 0 );
       // demonstrate sleeping
       WakableSleep( SLEEP_FOREVER );
       return 0;
   }
   </code>                                                       */
TIMER_PROC( void, WakeableSleepEx )( uint32_t milliseconds DBG_PASS );
TIMER_PROC( void, WakeableSleep )( uint32_t milliseconds );
TIMER_PROC( void, WakeableNamedSleepEx )( CTEXTSTR name, uint32_t n DBG_PASS );
#define WakeableNamedSleep( name, n )   WakeableNamedSleepEx( name, n DBG_SRC )
TIMER_PROC( void, WakeNamedSleeperEx )( CTEXTSTR name DBG_PASS );
#define WakeNamedSleeper( name )   WakeNamedSleeperEx( name DBG_SRC )
TIMER_PROC( void, WakeableNamedThreadSleepEx )( CTEXTSTR name, uint32_t n DBG_PASS );
#define WakeableNamedThreadSleep( name, n )   WakeableNamedThreadSleepEx( name, n DBG_SRC )
TIMER_PROC( void, WakeNamedThreadSleeperEx )( CTEXTSTR name, THREAD_ID therad DBG_PASS );
#define WakeNamedThreadSleeper( name, thread )   WakeNamedThreadSleeperEx( name, thread DBG_SRC )
#ifdef USE_PIPE_SEMS
TIMER_PROC( int, GetThreadSleeper )( PTHREAD thread );
#endif
/* <combine sack::timers::WakeableSleepEx@uint32_t milliseconds>
   \ \                                                      */
#define WakeableSleep(n) WakeableSleepEx(n DBG_SRC )
/* Wake a thread by ID, if the pThread is not available. Can be
   used cross-process for instance. Although someone could add a
   method to provide a PTHREAD wrapper around THREAD_ID for
   threads in remote processes, this may not be a best practice.
   Parameters
   thread_id :  THREAD_ID from GetMyThreadID, which is a macro
                appropriate for a platform.                      */
TIMER_PROC( void, WakeThreadIDEx )( THREAD_ID thread DBG_PASS );
/* Wake a thread.
   Example
   See WakeableSleepEx.
   Parameters
   pThread :  thread to wake up from a WakeableSleep. */
TIMER_PROC( void, WakeThreadEx )( PTHREAD thread DBG_PASS );
/* <combine sack::timers::WakeThreadIDEx@THREAD_ID thread>
   \ \                                                     */
#define WakeThreadID(thread) WakeThreadIDEx( thread DBG_SRC )
/* <combine sack::timers::WakeThreadEx@PTHREAD thread>
   \ \                                                 */
#define WakeThread(t) WakeThreadEx(t DBG_SRC )
/* This can be checked to see if the THREAD_ID to wake still has
   an event. Sometimes threads end.
   Parameters
   thread :  thread identifier to check to see if it exists/can be
             woken.
   Returns
   TRUE if the thread can be signaled to wake up.
   FALSE if the thread cannot be found or cannot be woken up.      */
TIMER_PROC( int, TestWakeThreadID )( THREAD_ID thread );
/* This can be checked to see if the PTHREAD to wake still has
   an event. Sometimes threads call UnmakeThread(). This is a
   more practical test using a THREAD_ID instead. See
   TestWakeThreadID.
   Returns
   TRUE if the thread can be signaled to wake up.
   FALSE if the thread cannot be found or cannot be woken up.  */
TIMER_PROC( int, TestWakeThread )( PTHREAD thread );
//TIMER_PROC( void, WakeThread )( PTHREAD thread );
TIMER_PROC( void, EndThread )( PTHREAD thread );
/* This tests to see if a pointer to a thread references the
   current thread.
   Parameters
   thread :  thread to check to see if it is the current thread.
   Returns
   TRUE if this thread is the same as the PTHREAD passed.
   otherwise FALSE.
   Example
   <code lang="c++">
   PTHREAD main_thread;
   LOGICAL thread_finished_check;
   uintptr_t CPROC ThreadProc( PTHREAD thread )
   {
       if( IsThisThread( main_thread ) )
            printf( "This thread is not the main thread.\\n" );
       else
            printf( "This is the main thread - cannot happen :)\\n" );
   </code>
   <code>
       // mark that this thread is complete
       thread_finished_check = TRUE;
   </code>
   <code lang="c++">
       // hmm - for some reason, just pass the uintptr_t that was passed to ThreadTo as the result.
       return GetThreadParam( thread );
   }
   int main( void )
   {
        main_thread = MakeThread();
        ThreadTo( ThreadProc, 0 );
        // wait for the thread to finish its thread identity check.
        while( !thread_finished_check )
            Relinquish();
        return 0;
   }
   </code>                                                                                         */
TIMER_PROC( int, IsThisThreadEx )( PTHREAD pThreadTest DBG_PASS );
/* <combine sack::timers::IsThisThreadEx@PTHREAD pThreadTest>
   \ \                                                        */
#define IsThisThread(thread) IsThisThreadEx(thread DBG_SRC)
/* Enter a critical section. Only a single thread may be in a
   critical section, if a second thread attempts to enter the
   section while another thread is in it will block until the
   original thread leaves the section. The same thread may enter
   a critical section multiple times. For each time a critical
   section is entered, the thread must also leave the critical
   section (See LeaveCriticalSection).
   Parameters
   pcs :  pointer to a critical section to enter                 */
TIMER_PROC( LOGICAL, EnterCriticalSecEx )( PCRITICALSECTION pcs DBG_PASS );
/* Leaves a critical section. See EnterCriticalSecEx.
   Parameters
   pcs :  pointer to a critical section.              */
TIMER_PROC( LOGICAL, LeaveCriticalSecEx )( PCRITICALSECTION pcs DBG_PASS );
/* Does nothing. There are no extra resources required for
   critical sections, and the memory is allocated by the
   application.
   Parameters
   pcs :  pointer to critical section to do nothing with.  */
TIMER_PROC( void, DeleteCriticalSec )( PCRITICALSECTION pcs );
#ifdef _WIN32
	TIMER_PROC( HANDLE, GetWakeEvent )( void );
	TIMER_PROC( HANDLE, GetThreadHandle )( PTHREAD thread );
#endif
#ifdef __LINUX__
	TIMER_PROC( pthread_t, GetThreadHandle )(PTHREAD thread);
#endif
#ifdef USE_NATIVE_CRITICAL_SECTION
#define EnterCriticalSec(pcs) EnterCriticalSection( pcs )
#define LeaveCriticalSec(pcs) LeaveCriticalSection( pcs )
#else
/* <combine sack::timers::EnterCriticalSecEx@PCRITICALSECTION pcs>
   \ \                                                             */
#define EnterCriticalSec( pcs ) EnterCriticalSecEx( (pcs) DBG_SRC )
/* <combine sack::timers::LeaveCriticalSecEx@PCRITICALSECTION pcs>
   \ \                                                             */
#define LeaveCriticalSec( pcs ) LeaveCriticalSecEx( (pcs) DBG_SRC )
#endif
TIMER_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::timers;
#endif
#endif
// $Log: timers.h,v $
// Revision 1.37  2005/05/16 19:06:58  jim
// Extend wakeable sleep to know the originator of the sleep.
//
// Revision 1.36  2004/09/29 16:42:51  d3x0r
// fixed queues a bit - added a test wait function for timers/threads
//
// Revision 1.35  2004/07/07 15:33:54  d3x0r
// Cleaned c++ warnings, bad headers, fixed make system, fixed reallocate...
//
// Revision 1.34  2004/05/02 02:04:16  d3x0r
// Begin border exclusive option, define PushMethod explicitly, fix LaunchProgram in timers.h
//
// Revision 1.33  2003/12/10 15:38:25  panther
// Move Sleep and GetTickCount to real code
//
// Revision 1.32  2003/11/02 00:31:47  panther
// Added debuginfo pass to wakethread
//
// Revision 1.31  2003/10/24 14:59:21  panther
// Added Load/Unload Function for system shared library abstraction
//
// Revision 1.30  2003/10/17 00:56:04  panther
// Rework critical sections.
// Moved most of heart of these sections to timers.
// When waiting, sleep forever is used, waking only when
// released... This is preferred rather than continuous
// polling of section with a Relinquish.
// Things to test, event wakeup order uner linxu and windows.
// Even see if the wake ever happens.
// Wake should be able to occur across processes.
// Also begin implmeenting MessageQueue in containers....
// These work out of a common shared memory so multiple
// processes have access to this region.
//
// Revision 1.29  2003/09/21 04:03:30  panther
// Build thread ID with pthread_self and getgid
//
// Revision 1.28  2003/07/29 10:41:25  panther
// Predefine struct threads_tag to avoid warning
//
// Revision 1.27  2003/07/24 22:49:20  panther
// Define callback procs as CDECL
//
// Revision 1.26  2003/07/24 16:56:41  panther
// Updates to expliclity define C procedure model for callbacks and assembly modules - incomplete
//
// Revision 1.25  2003/07/22 15:33:19  panther
// Added comment about idle()
//
// Revision 1.24  2003/04/03 10:10:20  panther
// Add file/line debugging to addtimer
//
// Revision 1.23  2003/03/27 13:47:14  panther
// Immplement a EndThread
//
// Revision 1.22  2003/03/25 08:38:11  panther
// Add logging
//
#ifndef MAXPATH
// windef.h has MAX_PATH
#  define MAXPATH MAX_PATH
#  if (!MAXPATH)
#    undef MAXPATH
#    define MAXPATH 256
#  endif
#endif
#ifndef PATH_MAX
// sometimes PATH_MAX is what's used, well it's should be MAXPATH which is MAX_PATH
# define PATH_MAX MAXPATH
#endif
#ifdef _UNICODE
#  ifdef _WIN32
#    ifdef CONSOLE_SHELL
    // in order to get wide characters from the commandline we have to use the GetCommandLineW function, convert it to utf8 for internal usage.
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { char *tmp; TEXTCHAR **b; ParseIntoArgs( GetCommandLineW(), &a, &b ); Deallocate( char*, tmp ); {
	//int n; TEXTCHAR **b; b = NewArray( TEXTSTR, a + 1 ); for( n = 0; n < a; n++ ) b[n] = DupCharToText( argv_real[n] ); b[n] = NULL; {
#      define EndSaneWinMain() } }
#    else
#      define SaneWinMain(a,b) int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow ) { char *tmp; int a; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); Deallocate( char*, tmp ); {
#      define EndSaneWinMain() } }
#    endif
#  else
#    if defined( __ANDROID__ ) && !defined( ANDROID_CONSOLE_UTIL )
#      define SaneWinMain(a,b) int SACK_Main( int a, char **b )
#      define EndSaneWinMain()
#    else
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { int n; TEXTCHAR **b; b = NewArray( TEXTSTR, a + 1 ); for( n = 0; n < a; n++ ) b[n] = DupCharToText( argv_real[n] ); b[n] = NULL; {
#      define EndSaneWinMain() } }
#    endif
#  endif
#else
#  ifdef _WIN32
#    ifdef CONSOLE_SHELL
// in order to get wide characters from the commandline we have to use the GetCommandLineW function, convert it to utf8 for internal usage.
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { char *tmp; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); Deallocate( char*, tmp ); {
#      define EndSaneWinMain() } }
#    else
#      define SaneWinMain(a,b) int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow ) { int a; char *tmp; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); {
#      define EndSaneWinMain() } }
#    endif
#  else
#    if defined( __ANDROID__ ) && !defined( ANDROID_CONSOLE_UTIL )
#      define SaneWinMain(a,b) int SACK_Main( int a, char **b )
#      define EndSaneWinMain()
#    else
#      define SaneWinMain(a,b) int main( int a, char **b ) { char **argv_real = b; {
#      define EndSaneWinMain() } }
#    endif
#  endif
#endif
//  these are rude defines overloading otherwise very practical types
// but - they have to be dispatched after all standard headers.
#ifndef FINAL_TYPES
#define FINAL_TYPES
#  ifdef __WATCOMC__
 //__WATCOMC__
#  endif
#  ifdef _WIN32
#    include <basetsd.h>
  // this redefines lprintf sprintf etc... and strsafe is preferred
 // more things that need override by strsafe.h
#    include <tchar.h>
 // added for mingw64 actually
#    ifdef __GNUC__
#      undef __CRT__NO_INLINE
#    endif
#    ifndef MINGW_SUX
#      include <strsafe.h>
#    else
#      define STRSAFE_E_INSUFFICIENT_BUFFER  0x8007007AL
#    endif
#  else
#  endif
// may consider changing this to uint16_t* for unicode...
#ifdef UNICODE
#  ifndef NO_UNICODE_C
#    define strrchr          wcsrchr
#    define strchr           wcschr
#    define strncpy          wcsncpy
#    ifdef strcpy
#      undef strcpy
#    endif
#    define strcpy           wcscpy
#    define strcmp           wcscmp
#    ifndef __LINUX__
// linux also translates 'i' to 'case' in sack_typelib.h
#      define stricmp          wcsicmp
#      define strnicmp         wcsnicmp
//#  define strlen           mbrlen
#    endif
#    define strlen           wcslen
#    ifdef WIN32
#      define stat(a,b)        _wstat(a,b)
#    else
#    endif
#    define printf           wprintf
#    define fprintf          fwprintf
#    define fputs            fputws
#    define fgets            fgetws
#    define atoi             _wtoi
#    ifdef __WATCOMC__
#      undef atof
#    endif
//#    define atof             _wtof
#    ifdef _MSC_VER
#      ifndef __cplusplus_cli
#        define fprintf   fwprintf
#        define atoi      _wtoi
// define sprintf here.
#      endif
#    endif
#    if defined( _ARM_ ) && defined( WIN32 )
// len should be passed as character count. this was the wrongw ay to default this.
#      define snprintf StringCbPrintf
//#define snprintf StringCbPrintf
#    endif
#  else
//#    define atoi             wtoi
#  endif
 // not unicode...
#else
#endif
#  ifdef _MSC_VER
#    define SUFFER_WITH_NO_SNPRINTF
#    ifndef SUFFER_WITH_NO_SNPRINTF
#      define vnsprintf protable_vsnprintf
//   this one gives deprication warnings
//   #    define vsnprintf _vsnprintf
//   this one doesn't work to measure strings
//   #    define vsnprintf(buf,len,format,args) _vsnprintf_s(buf,len,(len)/sizeof(TEXTCHAR),format,args)
//   this one doesn't macro well, and doesnt' measure strings
//  (SUCCEEDED(StringCbVPrintf( buf, len, format, args ))?StrLen(buf):-1)
#      define snprintf portable_snprintf
//   this one gives deprication warnings
//   #    define snprintf _snprintf
//   this one doesn't work to measure strings
//   #    define snprintf(buf,len,format,...) _snprintf_s(buf,len,(len)/sizeof(TEXTCHAR),format,##__VA_ARGS__)
//   this one doesn't macro well, and doesnt' measure strings
//   (SUCCEEDED(StringCbPrintf( buf, len, format,##__VA_ARGS__ ))?StrLen(buf):-1)
// make sure this is off, cause we really don't, and have to include the following
#      undef HAVE_SNPRINTF
 // define this anyhow so we can avoid name collisions
#      define PREFER_PORTABLE_SNPRINTF
#      ifdef SACK_CORE_BUILD
#        include <../src/snprintf_2.2/snprintf.h>
#      else
#        include <snprintf-2.2/snprintf.h>
 // SACK_CORE_BUILD
#      endif
 // SUFFER_WITH_WARNININGS
#    else
#      define snprintf _snprintf
#      define vsnprintf _vsnprintf
#      if defined( _UNICODE )
#        define tnprintf _snwprintf
#        define vtnprintf _vsnwprintf
#      else
#        define tnprintf _snprintf
#        define vtnprintf _vsnprintf
#      endif
#    define snwprintf _snwprintf
// suffer_with_warnings
#    endif
#    if defined( _UNICODE ) && !defined( NO_UNICODE_C )
#    define tscanf swscanf_s
#    else
#    define tscanf sscanf_s
#    endif
#    define scanf sscanf_s
#    define swcanf swscanf_s
 // _MSC_VER
#  endif
#  ifdef  __GNUC__
#      if defined( _UNICODE )
#        define VSNPRINTF_FAILS_RETURN_SIZE
#        define tnprintf  swprintf
#        define vtnprintf vswprintf
#        if !defined( NO_UNICODE_C )
#           define snprintf   swprintf
#           define vsnprintf  vswprintf
//#           define sscanf     swscanf
#        else
#        endif
#      else
#        define tnprintf snprintf
#        define vtnprintf vsnprintf
//#        define snprintf snprintf
//#        define vsnprintf vsnprintf
#    if defined( _UNICODE ) && !defined( NO_UNICODE_C )
#    define tscanf swscanf
#    else
#    define tscanf sscanf
#    endif
#      endif
 // __GNUC__
#  endif
#  ifdef __WATCOMC__
#      if defined( _UNICODE )
#        define tnprintf  _snwprintf
#        define vtnprintf _vsnwprintf
#        if !defined( NO_UNICODE_C )
#           define snprintf  _snwprintf
#           define vsnprintf _vsnwprintf
#           define sscanf     swscanf
#        else
#        endif
#      else
#         define tnprintf  snprintf
#         define vtnprintf vsnprintf
//#        define snprintf snprintf
//#        define vsnprintf vsnprintf
#      endif
#        define snwprintf  _snwprintf
 // __WATCOMC__
#  endif
#endif
#endif
/***************************************************************
 * JSOX Parser
 *
 * Parses JSOX (github.com/d3x0r/jsox)
 *
 * This function is meant for a simple utility to just take a known completed packet,
 * and get the values from it.  There may be mulitple top level values, although
 * the JSON standard will only supply a single object or array as the first value.
 * jsox_parse_message( "utf8 data", sizeof( "utf8 data" )-1, &pdlMessage );
 *
 *
 * Example :
 // call to parse a message... and iterate through each value.
 {
parse_message
    PDATALIST pdlMessage;
    LOGICAL gotMessage;
	 if( jsox_parse_message( "utf8 data", sizeof( "utf8 data" )-1, &pdlMessage ) ) {
		  int index;
        struct jsox_value_container *value;
		  DATALIST_FORALL( pdlMessage, index, struct jsox_value_container *. value ) {
           /* for each value in the result.... the first layer will
           always be just one element, either a simple type, or a VALUE_ARRAY or VALUE_OBJECT, which
           then for each value->contains (as a datalist like above), process each of those values.
		  }
        jsox_dispose_mesage( &pdlMessage );
    }
 }
 *
 *  This is a streaming setup, where a data block can be added,
 *  and the stream of objects can be returned from it....
 *
 *  Example 2:
 // allocate a parser to keep track of the parsing state...
 struct jsox_parse_state *parser = jsox_begin_parse();
 // at some point later, add some data to it...
 jsox_parse_add_data( parser, "utf8-data", sizeof( "utf8-data" ) - 1 );
 // and then get any objects that have been parsed from the stream so far...
 {
    PDATALIST pdlMessage;
	 pdlMessage = jsox_parse_get_data( parser );
    if( pdlMessage )
	 {
        int index;
        struct jsox_value_container *value;
        DATALIST_FORALL( pdlMessage, index, struct jsox_value_container *. value ) {
           /* for each value in the result.... the first layer will
           always be just one element, either a simple type, or a VALUE_ARRAY or VALUE_OBJECT, which
           then for each value->contains (as a datalist like above), process each of those values.
        }
        jsox_dispose_mesage( &pdlMessage );
		  jsox_parse_add_data( parser, NULL, 0 ); // trigger parsing next message.
	 }
 }
 *
 ***************************************************************/
#ifndef JSOX_PARSER_HEADER_INCLUDED
#define JSOX_PARSER_HEADER_INCLUDED
#define JSON_EMITTER_HEADER_INCLUDED
// include types to get namespace, and, well PDATALIST types
/* Includes the system platform as required or appropriate. If
   under a linux system, include appropriate basic linux type
   headers, if under windows pull "windows.h".
   Includes the MOST stuff here ( a full windows.h parse is many
   many lines of code.)                                          */
/* A macro to build a wide character string of __FILE__ */
#define _WIDE__FILE__(n) WIDE(n)
#define WIDE__FILE__ _WIDE__FILE__(__FILE__)
#ifndef STANDARD_HEADERS_INCLUDED
/* multiple inclusion protection symbol */
#define STANDARD_HEADERS_INCLUDED
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#if _MSC_VER
#  ifdef EXCLUDE_SAFEINT_H
#    define _INTSAFE_H_INCLUDED_
#  endif
 //_MSC_VER
#endif
#ifndef WINVER
#  define WINVER 0x0601
#endif
#if !defined(__LINUX__)
#  ifndef STRICT
#    define STRICT
#  endif
#  define WIN32_LEAN_AND_MEAN
// #define NOGDICAPMASKS             // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
// #define NOVIRTUALKEYCODES         // VK_*
// #define NOWINMESSAGES             // WM_*, EM_*, LB_*, CB_*
// #define NOWINSTYLES               // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
// #define NOSYSMETRICS              // SM_*
// #define NOMENUS                   // MF_*
// #define NOICONS                   // IDI_*
// #define NOKEYSTATES               // MK_*
// #define NOSYSCOMMANDS             // SC_*
// #define NORASTEROPS               // Binary and Tertiary raster ops
// #define NOSHOWWINDOW              // SW_*
               // OEM Resource values
#  define OEMRESOURCE
// #define NOATOM                    // Atom Manager routines
#  ifndef _INCLUDE_CLIPBOARD
               // Clipboard routines
#    define NOCLIPBOARD
#  endif
// #define NOCOLOR                   // Screen colors
// #define NOCTLMGR                  // Control and Dialog routines
//(spv) #define NODRAWTEXT                // DrawText() and DT_*
// #define NOGDI                     // All GDI defines and routines
// #define NOKERNEL                  // All KERNEL defines and routines
// #define NOUSER                    // All USER defines and routines
#  ifndef _ARM_
#    ifndef _INCLUDE_NLS
                     // All NLS defines and routines
#      define NONLS
#    endif
#  endif
// #define NOMB                      // MB_* and MessageBox()
                  // GMEM_*, LMEM_*, GHND, LHND, associated routines
#  define NOMEMMGR
                // typedef METAFILEPICT
#  define NOMETAFILE
                  // Macros min(a,b) and max(a,b)
#  define NOMINMAX
// #define NOMSG                     // typedef MSG and associated routines
// #define NOOPENFILE                // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
// #define NOSCROLL                  // SB_* and scrolling routines
                 // All Service Controller routines, SERVICE_ equates, etc.
#  define NOSERVICE
//#define NOSOUND                   // Sound driver routines
#  ifndef _INCLUDE_TEXTMETRIC
              // typedef TEXTMETRIC and associated routines
#    define NOTEXTMETRIC
#  endif
// #define NOWH                      // SetWindowsHook and WH_*
// #define NOWINOFFSETS              // GWL_*, GCL_*, associated routines
// #define NOCOMM                    // COMM driver routines
                   // Kanji support stuff.
#  define NOKANJI
                    // Help engine interface.
#  define NOHELP
                // Profiler interface.
#  define NOPROFILER
//#define NODEFERWINDOWPOS          // DeferWindowPos routines
                     // Modem Configuration Extensions
#  define NOMCX
   // no StrCat StrCmp StrCpy etc functions.  (used internally)
#  define NO_SHLWAPI_STRFCNS
  // This also has defines that override StrCmp StrCpy etc... but no override
#  define STRSAFE_NO_DEPRECATE
#  ifdef _MSC_VER
#    ifndef _WIN32_WINDOWS
// needed at least this for what - updatelayeredwindow?
#      define _WIN32_WINDOWS 0x0601
#    endif
#  endif
// INCLUDE WINDOWS.H
#  ifdef __WATCOMC__
#    undef _WINDOWS_
#  endif
#  ifdef UNDER_CE
// just in case windows.h also fails after undef WIN32
// these will be the correct order for primitives we require.
#    include <excpt.h>
#    include <windef.h>
#    include <winnt.h>
#    include <winbase.h>
#    include <wingdi.h>
#    include <wtypes.h>
#    include <winuser.h>
#    undef WIN32
#  endif
#  define _WINSOCKAPI_
#  include <windows.h>
#  undef _WINSOCKAPI_
#  if defined( WIN32 ) && defined( NEED_SHLOBJ )
#    include <shlobj.h>
#  endif
//#  include <windowsx.h>
// we like timeGetTime() instead of GetTickCount()
//#  include <mmsystem.h>
#ifdef __cplusplus
extern "C"
#endif
__declspec(dllimport) DWORD WINAPI timeGetTime(void);
#  if defined( NEED_SHLAPI )
#    include <shlwapi.h>
#    include <shellapi.h>
#  endif
#  ifdef NEED_V4W
#    include <vfw.h>
#  endif
#  if defined( HAVE_ENVIRONMENT )
#    define getenv(name)       OSALOT_GetEnvironmentVariable(name)
#    define setenv(name,val)   SetEnvironmentVariable(name,val)
#  endif
#  define Relinquish()       Sleep(0)
//#pragma pragnoteonly("GetFunctionAddress is lazy and has no library cleanup - needs to be a lib func")
//#define GetFunctionAddress( lib, proc ) GetProcAddress( LoadLibrary( lib ), (proc) )
#  ifdef __cplusplus_cli
#    include <vcclr.h>
 /*lprintf( */
#    define DebugBreak() System::Console::WriteLine(gcnew System::String( WIDE__FILE__ WIDE("(") STRSYM(__LINE__) WIDE(") Would DebugBreak here...") ) );
//typedef unsigned int HANDLE;
//typedef unsigned int HMODULE;
//typedef unsigned int HWND;
//typedef unsigned int HRC;
//typedef unsigned int HMENU;
//typedef unsigned int HICON;
//typedef unsigned int HINSTANCE;
#  endif
 // ifdef unix/linux
#else
#  include <pthread.h>
#  include <sched.h>
#  include <unistd.h>
#  include <sys/time.h>
#  include <errno.h>
#  if defined( __ARM__ )
#    define DebugBreak()
#  else
/* A symbol used to cause a debugger to break at a certain
   point. Sometimes dynamicly loaded plugins can be hard to set
   the breakpoint in the debugger, so it becomes easier to
   recompile with a breakpoint in the right place.
   Example
   <code lang="c++">
   DebugBreak();
	</code>                                                      */
#    ifdef __ANDROID__
#      define DebugBreak()
#    else
#      ifdef __EMSCRIPTEN__
#        define DebugBreak()
#      else
#        define DebugBreak()  asm("int $3\n" )
#      endif
#    endif
#  endif
#  ifdef __ANDROID_OLD_PLATFORM_SUPPORT__
extern __sighandler_t bsd_signal(int, __sighandler_t);
#  endif
// moved into timers - please linnk vs timers to get Sleep...
//#define Sleep(n) (usleep((n)*1000))
#  define Relinquish() sched_yield()
#  define GetLastError() (int32_t)errno
/* return with a THREAD_ID that is a unique, universally
   identifier for the thread for inter process communication. */
#  define GetCurrentProcessId() ((uint32_t)getpid())
#  define GetCurrentThreadId() ((uint32_t)getpid())
  // end if( !__LINUX__ )
#endif
#ifndef NEED_MIN_MAX
#  ifndef NO_MIN_MAX_MACROS
#    define NO_MIN_MAX_MACROS
#  endif
#endif
#ifndef NO_MIN_MAX_MACROS
#  ifdef __cplusplus
#    ifdef __GNUC__
#      ifndef min
#        define min(a,b) ((a)<(b))?(a):(b)
#      endif
#    endif
#  endif
/* Define a min(a,b) macro when the compiler lacks it. */
#  ifndef min
#    define min(a,b) (((a)<(b))?(a):(b))
#  endif
/* Why not add the max macro, also? */
#  ifndef max
#    define max(a,b) (((a)>(b))?(a):(b))
#  endif
#endif
/* please Include sthdrs.h */
/* Define most of the sack core types on which everything else is
   based. Also defines some of the primitive container
   structures. We also handle a lot of platform/compiler
   abstraction here.
   A reFactoring for stdint.h and uint32_t etc would be USEFUL!
   where types don't exist, define them as apprpritate types instead.
But WHO doesn't have stdint?  BTW is sizeof( size_t ) == sizeof( void* )
   This is automatically included with stdhdrs.h; however, when
   including sack_types.h, the minimal headers are pulled. */
#define HAS_STDINT
//#define USE_SACK_CUSTOM_MEMORY_ALLOCATION
	// this has to be a compile option (option from cmake)
   // enables debug dump mem...
#ifdef USE_SACK_CUSTOM_MEMORY_ALLOCATION
#  define USE_CUSTOM_ALLOCER 1
#else
#  define USE_CUSTOM_ALLOCER 0
#endif
#ifndef __64__
#  if defined( _WIN64 ) || defined( ENVIRONMENT64 ) || defined( __x86_64__ ) || defined( __ia64 ) || defined( __ppc64__ ) || defined( __LP64__ )
#    define __64__ 1
#  endif
#endif
#ifdef _MSC_VER
#  ifndef _WIN32_WINNT
#    define _WIN32_WINNT 0x501
#  endif
#  ifndef WIN32
#    ifdef _WIN32
#      define WIN32 _WIN32
#    endif
#  endif
// force windows on __MSVC
#  ifndef WIN32
#    define WIN32
#  endif
#endif
#if !defined( __NO_THREAD_LOCAL__ ) && ( defined( _MSC_VER ) || defined( __WATCOMC__ ) )
#  define HAS_TLS 1
#  define DeclareThreadLocal static __declspec(thread)
#  define DeclareThreadVar __declspec(thread)
#elif !defined( __NO_THREAD_LOCAL__ ) && ( defined( __GNUC__ ) )
#  define HAS_TLS 1
#  define DeclareThreadLocal static __thread
#  define DeclareThreadVar __thread
#else
#  define DeclareThreadLocal static
#  define DeclareThreadVar
#endif
#ifdef __cplusplus_cli
// these things define a type called 'Byte'
	// which causes confusion... so don't include vcclr for those guys.
#  ifdef SACK_BAG_EXPORTS
// maybe only do this while building sack_bag project itself...
#    if !defined( ZCONF_H )        && !defined( __FT2_BUILD_GENERIC_H__ )        && !defined( ZUTIL_H )        && !defined( SQLITE_PRIVATE )        && !defined( NETSERVICE_SOURCE )        && !defined( LIBRARY_DEF )
//using namespace System;
#    endif
#  endif
#endif
// Defined for building visual studio monolithic build.  These symbols are not relavent with cmakelists.
#ifdef SACK_BAG_EXPORTS
#  define SACK_BAG_CORE_EXPORTS
// exports don't really matter with CLI compilation.
#  ifndef BAG
//#ifndef TARGETNAME
//#  define TARGETNAME "sack_bag.dll"  //$(TargetFileName)
//#endif
#    ifndef __cplusplus_cli
// cli mode, we use this directly, and build the exports in sack_bag.dll directly
#    else
#      define LIBRARY_DEADSTART
#    endif
#define USE_SACK_FILE_IO
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define MEM_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSLOG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define _TYPELIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define HTTP_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define TIMER_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define IDLE_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CLIENTMSG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FRACTION_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define NETWORK_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CONFIGURATION_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FILESYSTEM_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSTEM_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define FILEMONITOR_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define VECTOR_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SHA1_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define CONSTRUCT_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define PROCREG_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SQLPROXY_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define TYPELIB_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define JSON_EMITTER_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SERVICE_SOURCE
#  ifndef __NO_SQL__
#    ifndef __NO_OPTIONS__
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.    and not NO_SQL and not NO_OPTIONS   */
#      define SQLGETOPTION_SOURCE
#    endif
#  endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define PSI_SOURCE
#  ifdef _MSC_VER
#    ifndef JPEG_SOURCE
//wouldn't matter... the external things wouldn't need to define this
//#error projects were not generated with CMAKE, and JPEG_SORUCE needs to be defined
#    endif
//#define JPEG_SOURCE
//#define __PNG_LIBRARY_SOURCE__
//#define FT2_BUILD_LIBRARY   // freetype is internal
//#define FREETYPE_SOURCE		// build Dll Export
#  endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define MNG_BUILD_DLL
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define BAGIMAGE_EXPORTS
/* Defined when SACK_BAG_EXPORTS is defined. This was an
 individual library module once upon a time.           */
#ifndef IMAGE_LIBRARY_SOURCE
#  define IMAGE_LIBRARY_SOURCE
#endif
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SYSTRAY_LIBRARAY
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define SOURCE_PSI2
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
#define VIDEO_LIBRARY_SOURCE
/* Defined when SACK_BAG_EXPORTS is defined. This was an
   individual library module once upon a time.           */
	/* define RENDER SOURCE when building monolithic. */
#     ifndef RENDER_LIBRARY_SOURCE
#       define RENDER_LIBRARY_SOURCE
#     endif
// define a type that is a public name struct type...
// good thing that typedef and struct were split
// during the process of port to /clr option.
//#define PUBLIC_TYPE public
#  else
//#define PUBLIC_TYPE
#    ifdef __cplusplus_CLR
//using namespace System;
#    endif
#  endif
#endif
 // wchar for X_16 definition
#include <wchar.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifndef MY_TYPES_INCLUDED
#define MY_TYPES_INCLUDED
// include this before anything else
// thereby allowing us to redefine exit()
 // CHAR_BIT
#include <limits.h>
 // typelib requires this
#include <stdarg.h>
#ifdef _MSC_VER
#ifndef UNDER_CE
 // memlib requires this, and it MUST be included befoer string.h if it is used.
#include <intrin.h>
#endif
#endif
 // typelib requires this
#include <string.h>
#if !defined( WIN32 ) && !defined( _WIN32 ) && !defined( _PNACL )
#include <dlfcn.h>
#endif
#if defined( _MSC_VER )
// disable pointer conversion warnings - wish I could disable this
// according to types...
//#pragma warning( disable:4312; disable:4311 )
// disable deprication warnings of snprintf, et al.
//#pragma warning( disable:4996 )
#define EMPTY_STRUCT struct { char nothing[]; }
#endif
#if defined( __WATCOMC__ )
#define EMPTY_STRUCT char
#endif
#ifdef __cplusplus
/* Could also consider defining 'SACK_NAMESPACE' as 'extern "C"
   ' {' and '..._END' as '}'                                    */
#define SACK_NAMESPACE namespace sack {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE namespace containers {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE namespace list {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE namespace data_list {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE namespace sets {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE namespace text {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE_END }
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE SACK_NAMESPACE _CONTAINER_NAMESPACE namespace text {
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE_END  } _CONTAINER_NAMESPACE_END SACK_NAMESPACE_END
#else
/* Define the sack namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE
/* Define the sack namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define SACK_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _CONTAINER_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _LINKLIST_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _DATALIST_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _SETS_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define _TEXT_NAMESPACE_END
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE
/* Define the container namespace (when building with C++, the
   wrappers are namespace{} instead of extern"c"{} )           */
#define TEXT_NAMESPACE_END
#endif
/* declare composite SACK_CONTAINER namespace to declare sack::container in a single line */
#define SACK_CONTAINER_NAMESPACE SACK_NAMESPACE _CONTAINER_NAMESPACE
/* declare composite SACK_CONTAINER namespace to close sack::container in a single line */
#define SACK_CONTAINER_NAMESPACE_END _CONTAINER_NAMESPACE_END SACK_NAMESPACE_END
/* declare composite SACK_CONTAINER namespace to declare sack::container::list in a single line */
#define SACK_CONTAINER_LINKLIST_NAMESPACE SACK_CONTAINER_NAMESPACE _LISTLIST_NAMESPACE
/* declare composite SACK_CONTAINER namespace to close sack::container::list in a single line */
#define SACK_CONTAINER_LINKLIST_NAMESPACE_END _LISTLIST_NAMESPACE_END SACK_CONTAINER_NAMESPACE
// this symbols is defined to enforce
// the C Procedure standard - using a stack, and resulting
// in EDX:EAX etc...
#define CPROC
#ifdef SACK_BAG_EXPORTS
# ifdef BUILD_GLUE
// this is used as the export method appropriate for C#?
#  define EXPORT_METHOD [DllImport(LibName)] public
# else
#  ifdef __cplusplus_cli
#   if defined( __STATIC__ ) || defined( __LINUX__ ) || defined( __ANDROID__ )
#     define EXPORT_METHOD
#     define IMPORT_METHOD extern
#   else
#     define EXPORT_METHOD __declspec(dllexport)
#     define IMPORT_METHOD __declspec(dllimport)
#   endif
#   define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#   define LITERAL_LIB_IMPORT_METHOD extern
//__declspec(dllimport)
#  else
#   if defined( __STATIC__ ) || defined( __LINUX__ ) || defined( __ANDROID__ )
#      define EXPORT_METHOD
#      define IMPORT_METHOD extern
#    else
/* Method to declare functions exported from a DLL. (nothign on
   LINUX or building statically, but __declspec(dllimport) on
   windows )                                                    */
#      define EXPORT_METHOD __declspec(dllexport)
/* method to define a function which will be Imported from a
   library. Under windows, this is probably
   __declspec(dllimport). Under linux this is probably 'extern'. */
#      define IMPORT_METHOD __declspec(dllimport)
#    endif
#      define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#      define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
#  endif
# endif
#else
# if ( !defined( __STATIC__ ) && defined( WIN32 ) && !defined( __cplusplus_cli) )
#  define EXPORT_METHOD __declspec(dllexport)
#  define IMPORT_METHOD __declspec(dllimport)
#  define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
#  define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
# else
// MRT:  This is needed.  Need to see what may be defined wrong and fix it.
#  if defined( __LINUX__ ) || defined( __STATIC__ )
#    define EXPORT_METHOD
#    define IMPORT_METHOD extern
#    define LITERAL_LIB_EXPORT_METHOD
#    define LITERAL_LIB_IMPORT_METHOD extern
#  else
#    define EXPORT_METHOD __declspec(dllexport)
#    define IMPORT_METHOD __declspec(dllimport)
/* Define how methods in LITERAL_LIBRARIES are exported.
   literal_libraries are libraries that are used for plugins,
   and are dynamically loaded by code. They break the rules of
   system prefix and suffix extensions. LITERAL_LIBRARIES are
   always dynamic, and never static.                           */
#    define LITERAL_LIB_EXPORT_METHOD __declspec(dllexport)
/* Define how methods in LITERAL_LIBRARIES are imported.
   literal_libraries are libraries that are used for plugins,
   and are dynamically loaded by code. They break the rules of
   system prefix and suffix extensions. LITERAL_LIBRARIES are
   always dynamic, and never static.                           */
#    define LITERAL_LIB_IMPORT_METHOD __declspec(dllimport)
#  endif
# endif
#endif
// used when the keword specifying a structure is packed
// needs to prefix the struct keyword.
#define PREFIX_PACKED
// private thing left as a note, and forgotten.  some compilers did not define offsetof
#define my_offsetof( ppstruc, member ) ((uintptr_t)&((*ppstruc)->member)) - ((uintptr_t)(*ppstruc))
SACK_NAMESPACE
#ifdef BCC16
#define __inline__
#define MAINPROC(type,name)     type _pascal name
// winproc is intended for use at libmain/wep/winmain...
#define WINPROC(type,name)      type _far _pascal _export name
// callbackproc is for things like timers, dlgprocs, wndprocs...
#define CALLBACKPROC(type,name) type _far _pascal _export name
#define PUBLIC(type,name)       type STDPROC _export name
 /* here would be if dwReason == process_attach */
#define LIBMAIN() WINPROC(int, LibMain)(HINSTANCE hInstance, WORD wDataSeg, WORD wHeapSize, LPSTR lpCmdLine )		 { {
 /* end if */
 /*endproc*/
#define LIBEXIT() } }	    int STDPROC WEP(int nSystemExit )  {
#define LIBMAIN_END()  }
// should use this define for all local defines...
// this will allow one place to modify ALL _pascal or not to _pascal decls.
#define STDPROC _far _pascal
#endif
#if defined( __LCC__ ) || defined( _MSC_VER ) || defined(__DMC__) || defined( __WATCOMC__ )
#ifdef __WATCOMC__
#undef CPROC
#define CPROC __cdecl
#define STDPROC __cdecl
#ifndef __WATCOMC__
// watcom windef.h headers define this
#define STDCALL _stdcall
#endif
#if __WATCOMC__ >= 1280
// watcom windef.h headers no longer define this.
#define STDCALL __stdcall
#endif
#undef PREFIX_PACKED
#define PREFIX_PACKED _Packed
#else
#undef CPROC
//#error blah
#define CPROC __cdecl
#define STDPROC
#define STDCALL _stdcall
#endif
#define far
#define huge
#define near
#define _far
#define _huge
#define _near
/* portability type for porting legacy 16 bit applications. */
/* portability macro for legacy 16 bit applications. */
#define __far
#ifndef FAR
#define FAR
#endif
//#define HUGE
//#ifndef NEAR
//#define NEAR
//#endif
#define _fastcall
#ifdef __cplusplus
#ifdef __cplusplus_cli
#define PUBLIC(type,name) extern "C"  LITERAL_LIB_EXPORT_METHOD type CPROC name
#else
//#error what the hell!?
// okay Public functions are meant to be loaded with LoadFuncion( "library" , "function name"  );
#define PUBLIC(type,name) extern "C"  LITERAL_LIB_EXPORT_METHOD type CPROC name
#endif
#else
#define PUBLIC(type,name) LITERAL_LIB_EXPORT_METHOD type CPROC name
#endif
#define MAINPROC(type,name)  type WINAPI name
#define WINPROC(type,name)   type WINAPI name
#define CALLBACKPROC(type,name) type CALLBACK name
#if defined( __WATCOMC__ )
#define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(_WIDE(TARGETNAME)) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#define LIBMAIN_END() }
#else
#ifdef TARGETNAME
#define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(_WIDE(TARGETNAME)) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#else
#define LIBMAIN()   TARGETNAME_NOT_DEFINED
#endif
#define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#define LIBMAIN_END() }
#endif
#define PACKED
#endif
#if defined( __GNUC__ )
#  ifndef STDPROC
#    define STDPROC
#  endif
#  ifndef STDCALL
 // for IsBadCodePtr which isn't a linux function...
#    define STDCALL
#  endif
#  ifndef WINAPI
#    ifdef __LINUX__
#       define WINAPI
#    else
#       define WINAPI __stdcall
#    endif
#  endif
#  ifndef PASCAL
//#define PASCAL
#  endif
#  define WINPROC(type,name)   type WINAPI name
#  define CALLBACKPROC( type, name ) type name
#  define PUBLIC(type,name) EXPORT_METHOD type CPROC name
#  define LIBMAIN()   static int __LibMain( HINSTANCE ); PRELOAD( LibraryInitializer ) {	 __LibMain( GetModuleHandle(TARGETNAME) );   }	 static int __LibMain( HINSTANCE hInstance ) {
#  define LIBEXIT() } static int LibExit( void ); ATEXIT( LiraryUninitializer ) { LibExit(); } int LibExit(void) {
#  define LIBMAIN_END()  }
/* Portability Macro for porting legacy code forward. */
#  define FAR
#  define NEAR
//#define HUGE
#  define far
#  define near
#  define huge
#  define PACKED __attribute__((packed))
#endif
#if defined( BCC32 )
#define far
#define huge
/* define obsolete keyword for porting purposes */
/* defined for porting from 16 bit environments */
#define near
/* portability macro for legacy 16 bit applications. */
#define _far
#define _huge
#define _near
/* portability type for porting to compilers that don't inline. */
/* portability macro for legacy 16 bit applications. */
#define __inline__
#define MAINPROC(type,name)     type _pascal name
// winproc is intended for use at libmain/wep/winmain...
#define WINPROC(type,name)      EXPORT_METHOD type _pascal name
// callbackproc is for things like timers, dlgprocs, wndprocs...
#define CALLBACKPROC(type,name) EXPORT_METHOD type _stdcall name
#define STDCALL _stdcall
#define PUBLIC(type,name)        type STDPROC name
#ifdef __STATIC__
			/*Log( WIDE("Library Enter" ) );*/
#define LIBMAIN() static WINPROC(int, LibMain)(HINSTANCE hInstance, DWORD dwReason, void *unused )		 { if( dwReason == DLL_PROCESS_ATTACH ) {
 /* end if */
#define LIBEXIT() } if( dwReason == DLL_PROCESS_DETACH ) {
#define LIBMAIN_END()  } return 1; }
#else
			/*Log( WIDE("Library Enter" ) );*/
#define LIBMAIN() WINPROC(int, LibMain)(HINSTANCE hInstance, DWORD dwReason, void *unused )		 { if( dwReason == DLL_PROCESS_ATTACH ) {
 /* end if */
#define LIBEXIT() } if( dwReason == DLL_PROCESS_DETACH ) {
#define LIBMAIN_END()  } return 1; }
#endif
// should use this define for all local defines...
// this will allow one place to modify ALL _pascal or not to _pascal decls.
#define STDPROC _pascal
#define PACKED
#endif
#define TOCHR(n) #n[0]
#define TOSTR(n) WIDE(#n)
#define STRSYM(n) TOSTR(n)
#define _WIDE__FILE__(n) WIDE(n)
#define WIDE__FILE__ _WIDE__FILE__(__FILE__)
/* a constant text string that represents the current source
   filename and line... fourmated as "source.c(11) :"        */
#define FILELINE  TEXT(__FILE__) WIDE("(" ) TEXT(STRSYM(__LINE__))WIDE(" : " ))
#if defined( _MSC_VER ) || defined( __PPCCPP__ )
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnote(msg) message( FILELINE msg )
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnoteonly(msg) message( msg )
#else
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnote(msg) msg
/* try and define a way to emit comipler messages... but like no compilers support standard ways to do this accross the board.*/
#define pragnoteonly(msg) msg
#endif
/* specify a consistant macro to pass current file and line information.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_SRC         , (CTEXTSTR)_WIDE(__FILE__), __LINE__
/* specify a consistant macro to pass current file and line information, to functions which void param lists.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDSRC     (CTEXTSTR)_WIDE(__FILE__), __LINE__
//#define FILELINE_LEADSRC     (CTEXTSTR)_WIDE(__FILE__), __LINE__,
/* specify a consistant macro to define file and line parameters, to functions with otherwise void param lists.  This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDPASS    CTEXTSTR pFile, uint32_t nLine
//#define FILELINE_LEADPASS    CTEXTSTR pFile, uint32_t nLine,
/* specify a consistant macro to define file and line parameters.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_PASS        , CTEXTSTR pFile, uint32_t nLine
/* specify a consistant macro to forward file and line parameters.   This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_RELAY       , pFile, nLine
/* specify a consistant macro to forward file and line parameters, to functions which have void parameter lists without this information.  This are appended parameters, and common usage is to only use these with _DEBUG set. */
#define FILELINE_VOIDRELAY   pFile, nLine
/* specify a consistant macro to format file and line information for printf formated strings. */
#define FILELINE_FILELINEFMT WIDE("%s(%") _32f WIDE("): ")
#define FILELINE_FILELINEFMT_MIN WIDE("%s(%") _32f WIDE(")")
#define FILELINE_NULL        , NULL, 0
#define FILELINE_VOIDNULL    NULL, 0
/* define static parameters which are the declaration's current file and line, for stubbing in where debugging is being stripped.
  usage
    FILELINE_VARSRC: // declare pFile and nLine variables.
	*/
#define FILELINE_VARSRC       CTEXTSTR pFile = _WIDE(__FILE__); uint32_t nLine = __LINE__
// this is for passing FILE, LINE information to allocate
// useful during DEBUG phases only...
// drop out these debug relay paramters for managed code...
// we're going to have the full call frame managed and known...
#if !defined( _DEBUG ) && !defined( _DEBUG_INFO )
#  if defined( __LINUX__ ) && !defined( __PPCCPP__ )
//#warning "Setting DBG_PASS and DBG_FORWARD to be ignored."
#  else
//#pragma pragnoteonly("Setting DBG_PASS and DBG_FORWARD to be ignored"  )
#  endif
#define DBG_AVAILABLE   0
/* in NDEBUG mode, pass nothing */
#define DBG_SRC
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_VOIDSRC
/* <combine sack::DBG_PASS>
   \#define DBG_LEADSRC in NDEBUG mode, declare (void) */
/* <combine sack::DBG_PASS>
   \ \                      */
#define DBG_VOIDPASS    void
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_PASS
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_RELAY
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_VOIDRELAY
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_FILELINEFMT
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
#define DBG_FILELINEFMT_MIN
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing
   Example
   printf( DBG_FILELINEFMT ": extra message" DBG_PASS ); */
#define DBG_VARSRC
#else
	// these DBG_ formats are commented out from duplication in sharemem.h
#  if defined( __LINUX__ ) && !defined( __PPCCPP__ )
//#warning "Setting DBG_PASS and DBG_FORWARD to work."
#  else
//#pragma pragnoteonly("Setting DBG_PASS and DBG_FORWARD to work"  )
#  endif
// used to specify whether debug information is being passed - can be referenced in compiled code
#define DBG_AVAILABLE   1
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_SRC */
#define DBG_SRC         FILELINE_SRC
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDSRC */
#define DBG_VOIDSRC     FILELINE_VOIDSRC
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDPASS */
#define DBG_VOIDPASS    FILELINE_VOIDPASS
/* <combine sack::DBG_PASS>
   in NDEBUG mode, pass nothing */
/* Example
   This example shows forwarding debug information through a
   chain of routines.
   <code lang="c++">
   void ReportFunction( int sum DBG_PASS )
   {
       printf( "%s(%d):started this whole mess\\n" DBG_RELAY );
   }
   void TrackingFunction( int a, int b DBG_PASS )
   {
       ReportFunction( a+b, DBG_RELAY );
   }
   void CallTrack( void )
   {
       TrackingFunction( 1, 2 DBG_SRC );
   }
   </code>
   In this example, the debug information is passed to the
   logging system. This allows logging to blame the user
   application for allocations, releases, locks, etc...
   <code lang="c++">
   void MyAlloc( int size DBG_PASS )
   {
       _lprintf( DBG_RELAY )( ": alloc %d\\n", size );
   }
   void g( void )
   {
       lprintf( "Will Allocate %d\\n", 32 );
       MyAlloc( 32 DBG_SRC );
   }
   </code>
   This example uses the void argument macros
   <code>
   void SimpleFunction( DBG_VOIDPASS )
   {
       // this function usually has (void) parameters.
   }
   void f( void )
   {
       SimpleFunction( DBG_VOIDSRC );
   }
   </code>
   Description
   in NDEBUG mode, pass nothing.
   This function allows specification of DBG_RELAY or DBG_SRC
   under debug compilation. Otherwise, the simple AddLink macro
   should be used. DBG_RELAY can be used to forward file and
   line information which has been passed via DBG_PASS
   declaration in the function parameters.
   This is a part of a set of macros which allow additional
   logging information to be passed.
   These 3 are the most commonly used.
   DBG_SRC - this passes the current __FILE__, __LINE__
   \parameters.
   DBG_PASS - this is used on a function declaration, is a
   filename and line number from DBG_SRC or DBG_RELAY.
   DBG_RELAY - this passes the file and line passed to this
   function to another function with DBG_PASS defined on it.
   DBG_VOIDPASS - used when the argument list is ( void )
   without debugging information.
   DBG_VOIDSRC - used to call a function who's argument list is
   ( void ) without debugging information.
   DBG_VOIDRELAY - pass file and line information forward to
   another function, who's argument list is ( void ) without
   debugging information.
   Remarks
   The SACK library is highly instrumented with this sort of
   information. Very commonly the only difference between a
   specific function called 'MyFunctionName' and
   'MyFunctionNameEx' is the addition of debug information
   tracking.
   The following code blocks show the evolution added to add
   instrumentation...
   <code lang="c++">
   int MyFunction( int param )
   {
       // do stuff
   }
   int CallingFunction( void )
   {
       return MyFunction();
   }
   </code>
   Pretty simple code, a function that takes a parameter, and a
   function that calls it.
   The first thing is to extend the called function.
   <code>
   int MyFunctionEx( int param DBG_PASS )
   {
       // do stuff
   }
   </code>
   And provide a macro for everyone else calling the function to
   automatically pass their file and line information
   <code lang="c++">
   \#define MyFunction(param)  MyFunctionEx(param DBG_SRC)
   </code>
   Then all-together
   <code>
   \#define MyFunction(param)  MyFunctionEx(param DBG_SRC)
   int MyFunctionEx( int param DBG_PASS )
   {
       // do stuff
   }
   int CallingFunction( void )
   {
       // and this person calling doesn't matter
       // does require a recompile of source.
       return MyFunction( 3 );
   }
   </code>
   But then... what if CallingFunction decided wasn't really the
   one at fault, or responsible for the allocation, or other
   issue being tracked, then she could be extended....
   <code>
   int CallingFunctionEx( DBG_VOIDPASS )
   \#define CallingFunction() CallingFunction( DBG_VOIDSRC )
   {
       // and this person calling doesn't matter
       // does require a recompile of source.
       return MyFunction( 1 DBG_RELAY );
   }
   </code>
   Now, calling function will pass it's callers information to
   MyFunction....
   Why?
   Now, when you call CreateList, your code callng the list
   creation method is marked as the one who allocates the space.
   Or on a DeleteList, rather than some internal library code
   being blamed, the actual culprit can be tracked and
   identified, because it's surely not the fault of CreateList
   that the reference to the memory for the list wasn't managed
   correctly.
   Note
   It is important to note, every usage of these macros does not
   have a ',' before them. This allows non-debug code to
   eliminate these extra parameters cleanly. If the ',' was
   outside of the macro, then it would remain on the line, and
   an extra parameter would have be be passed that was unused.
   This is also why DBG_VOIDPASS exists, because in release mode
   this is substituted with 'void'.
   In Release mode, DBG_VOIDRELAY becomes nothing, but when in
   debug mode, DBG_RELAY has a ',' in the macro, so without a
   paramter f( DBG_RELAY ) would fail; on expansion this would
   be f( , pFile, nLine ); (note the extra comma, with no
   parameter would be a syntax error.                            */
#define DBG_PASS        FILELINE_PASS
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_RELAY */
#define DBG_RELAY       FILELINE_RELAY
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VOIDRELAY */
#define DBG_VOIDRELAY   FILELINE_VOIDRELAY
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_FILELINEFMT */
#define DBG_FILELINEFMT FILELINE_FILELINEFMT
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_FILELINEFMT_MIN */
#define DBG_FILELINEFMT_MIN FILELINE_FILELINEFMT_MIN
/* <combine sack::DBG_PASS>
   in _DEBUG mode, pass FILELINE_VARSRC */
#define DBG_VARSRC      FILELINE_VARSRC
#endif
// cannot declare _0 since that overloads the
// vector library definition for origin (0,0,0,0,...)
//typedef void             _0; // totally unusable to declare 0 size things.
/* the only type other than when used in a function declaration that void is valid is as a pointer to void. no _0 type exists (it does, but it's in vectlib, and is an origin vector)*/
typedef void             *P_0;
/*
 * several compilers are rather picky about the types of data
 * used for bit field declaration, therefore this type
 * should be used instead of uint32_t (DWORD)
 */
typedef unsigned int  BIT_FIELD;
// have to do this on a per structure basis - otherwise
// any included headers with structures to use will get FUCKED
#ifndef PACKED
#define PACKED
#endif
/* An pointer to a volatile unsigned integer type that is 64 bits long. */
//typedef volatile uint64_t  *volatile int64_t*;
/* An pointer to a volatile pointer size type that is as long as a pointer. */
typedef volatile uintptr_t        *PVPTRSZVAL;
/* an unsigned type meant to index arrays.  (By convention, arrays are not indexed negatively.)  An index which is not valid is INVALID_INDEX, which equates to 0xFFFFFFFFUL or negative one cast as an INDEX... ((INDEX)-1). */
typedef size_t         INDEX;
/* An index which is not valid; equates to 0xFFFFFFFFUL or negative one cast as an INDEX... ((INDEX)-1). */
#define INVALID_INDEX ((INDEX)-1)
#ifdef __CYGWIN__
typedef unsigned short wchar_t;
#endif
// may consider changing this to uint16_t* for unicode...
typedef wchar_t X_16;
/* This is a pointer to wchar_t. A 16 bit value that is
   character data, and is not signed or unsigned.       */
typedef wchar_t *PX_16;
#if defined( UNICODE ) || defined( SACK_COM_OBJECT )
//should also consider revisiting code that was updated for TEXTCHAR to char conversion methods...
#  ifdef _MSC_VER
#    ifdef UNDER_CE
#      define NULTERM
#    else
#      define NULTERM __nullterminated
#    endif
#  else
#    define NULTERM
#  endif
#define WIDE(s)  L##s
#define _WIDE(s)  WIDE(s)
#define cWIDE(s)  s
#define _cWIDE(s)  cWIDE(s)
 // constant text string content
typedef NULTERM          const X_16      *CTEXTSTR;
 // pointer to constant text string content
typedef NULTERM          CTEXTSTR        *PCTEXTSTR;
typedef NULTERM          X_16            *TEXTSTR;
/* a text 16 bit character  */
typedef X_16             TEXTCHAR;
#else
#define WIDE(s)   s
#define _WIDE(s)  s
#define cWIDE(s)   s
/* Modified WIDE wrapper that actually forces non-unicode
   string.                                                */
#define _cWIDE(s)  s
// constant text string content
typedef const char     *CTEXTSTR;
/* A non constant array of TEXTCHAR. A pointer to TEXTCHAR. A
   pointer to non-constant characters. (A non-static string
   probably)                                                  */
typedef char           *TEXTSTR;
#if defined( __LINUX__ ) && defined( __cplusplus )
// pointer to constant text string content
typedef TEXTSTR const  *PCTEXTSTR;
#else
// char const *const *
typedef CTEXTSTR const *PCTEXTSTR;
#endif
/* a text 8 bit character  */
typedef char            TEXTCHAR;
#endif
/* a character rune.  Strings should be interpreted as UTF-8 or 16 depending on UNICODE compile option.
   GetUtfChar() from strings.  */
typedef uint32_t             TEXTRUNE;
/* Used to handle returned values that are invalid runes; past end or beginning of string for instance */
#define INVALID_RUNE  0x80000000
//typedef enum { FALSE, TRUE } LOGICAL; // smallest information
#ifndef FALSE
#define FALSE 0
/* Define TRUE when not previously defined in the platform. TRUE
   is (!FALSE) so anything not 0 is true.                        */
#define TRUE (!FALSE)
#endif
/* Meant to hold boolean and only boolean values. Should be
   implemented per-platform as appropriate for the bool type the
   compiler provides.                                            */
typedef uint32_t LOGICAL;
/* This is a pointer. It is a void*. It is meant to point to a
   single thing, and cannot be used to reference arrays of bytes
   without recasting.                                            */
typedef P_0 POINTER;
/* This is a pointer to constant data. void const *. Compatible
   with things like char const *.                               */
typedef const void *CPOINTER;
SACK_NAMESPACE_END
//------------------------------------------------------
// formatting macro defintions for [vsf]printf output of the above types
#if !defined( _MSC_VER ) || ( _MSC_VER >= 1900 )
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#endif
SACK_NAMESPACE
/* 16 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16f   WIDE("u" )
/* 16 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16fx   WIDE("x" )
/* 16 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _16fX   WIDE("X" )
/* 16 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\>               */
#define _16fs   WIDE("d" )
/* 8 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8f   WIDE("u" )
/* 8 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8fx   WIDE("x" )
/* 8 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\>                */
#define _8fX   WIDE("X" )
/* 8 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\>               */
#define _8fs   WIDE("d" )
#if defined( __STDC_FORMAT_MACROS )
#  define _32f   _WIDE( PRIu32 )
#  define _32fx   _WIDE( PRIx32 )
#  define _32fX   _WIDE( PRIX32 )
#  define _32fs   _WIDE( PRId32 )
#  define _64f    _WIDE(PRIu64)
#  define _64fx   _WIDE(PRIx64)
#  define _64fX   _WIDE(PRIX64)
#  define _64fs   _WIDE(PRId64)
#  define _64f    _WIDE(PRIu64)
#  define _64fx   _WIDE(PRIx64)
#  define _64fX   _WIDE(PRIX64)
#  define _64fs   _WIDE(PRId64)
// non-unicode strings
#  define c_32f    PRIu32
#  define c_32fx   PRIx32
#  define c_32fX   PRIX32
#  define c_32fs   PRId32
#  define c_64f    PRIu64
#  define c_64fx   PRIx64
#  define c_64fX   PRIX64
#  define c_64fs   PRId64
#else
#  define _32f   WIDE("u" )
#  define _32fx   WIDE("x" )
#  define _32fX   WIDE("X" )
#  define _32fs   WIDE("d" )
#  define c_32f   "u"
#  define c_32fx  "x"
#  define c_32fX  "X"
#  define c_32fs  "d"
#  define c_64f    "llu"
#  define c_64fx   "llx"
#  define c_64fX   "llX"
#  define c_64fs   "lld"
#endif
#if defined( UNICODE )
#  define _cstring_f WIDE("s")
#  define _string_f WIDE("S")
#  define _ustring_f WIDE("S")
#else
#  define _cstring_f WIDE("s")
#  define _string_f WIDE("s")
#  define _ustring_f WIDE("S")
#endif
#if defined( __64__ )
#  if defined( __STDC_FORMAT_MACROS )
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _WIDE( PRIu64 )
#      define _size_fx   _WIDE( PRIx64 )
#      define _size_fX   _WIDE( PRIX64 )
#      define _size_fs   _WIDE( PRId64 )
#      define c_size_f    PRIu64
#      define c_size_fx   PRIx64
#      define c_size_fX   PRIX64
#      define c_size_fs   PRId64
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  else
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _64f
#      define _size_fx   _64fx
#      define _size_fX   _64fX
#      define _size_fs   _64fs
#      define c_size_f   c_64f
#      define c_size_fx  c_64fx
#      define c_size_fX  c_64fX
#      define c_size_fs  c_64fs
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  endif
#else
#  if defined( __STDC_FORMAT_MACROS )
      // this HAS been fixed in UCRT - 2015!  but it'll take 5 years before everyone has that...
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _WIDE( PRIu32 )
#      define _size_fx   _WIDE( PRIx32 )
#      define _size_fX   _WIDE( PRIX32 )
#      define _size_fs   _WIDE( PRId32 )
#      define c_size_f    PRIu32
#      define c_size_fx   PRIx32
#      define c_size_fX   PRIX32
#      define c_size_fs   PRId32
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  else
      // this HAS been fixed in UCRT - 2015!  but it'll take 5 years before everyone has that...
#    if !defined( __GNUC__ ) || defined( _WIN32 )
#      define _size_f    _32f
#      define _size_fx   _32fx
#      define _size_fX   _32fX
#      define _size_fs   _32fs
#      define c_size_f    c_32f
#      define c_size_fx   c_32fx
#      define c_size_fX   c_32fX
#      define c_size_fs   c_32fs
#    else
#      define _size_f    WIDE( "zu" )
#      define _size_fx   WIDE( "zx" )
#      define _size_fX   WIDE( "zX" )
#      define _size_fs   WIDE( "zd" )
#      define c_size_f    "zu"
#      define c_size_fx   "zx"
#      define c_size_fX   "zX"
#      define c_size_fs   "zd"
#    endif
#    define _PTRSZVALfs _WIDE( PRIuPTR )
#    define _PTRSZVALfx _WIDE( PRIxPTR )
#    define cPTRSZVALfs PRIuPTR
#    define cPTRSZVALfx PRIxPTR
#  endif
#endif
#define PTRSZVALf WIDE("p" )
#define _PTRSZVALf WIDE("p" )
#if defined( _MSC_VER ) && ( _MSC_VER < 1900 )
/* 64 bit unsigned decimal output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIu64              */
#define _64f    WIDE("llu")
/* 64 bit hex output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIxFAST64                */
#define _64fx   WIDE("llx")
/* 64 bit HEX output printf format specifier. This would
   otherwise be defined in \<inttypes.h\> as PRIxFAST64                */
#define _64fX   WIDE("llX")
/* 64 bit signed decimal output printf format specifier. This
   would otherwise be defined in \<inttypes.h\> as PRIdFAST64               */
#define _64fs   WIDE("lld")
#endif
// This should be for several years a
// sufficiently large type to represent
// threads and processes.
typedef uint64_t THREAD_ID;
#define GetMyThreadIDNL GetMyThreadID
#if defined( _WIN32 ) || defined( __CYGWIN__ )
#define _GetMyThreadID()  ( (( ((uint64_t)GetCurrentProcessId()) << 32 ) | ( (uint64_t)GetCurrentThreadId() ) ) )
#define GetMyThreadID()  (GetThisThreadID())
#else
// this is now always the case
// it's a safer solution anyhow...
#ifndef GETPID_RETURNS_PPID
#define GETPID_RETURNS_PPID
#endif
#ifdef GETPID_RETURNS_PPID
#ifdef __ANDROID__
#define GetMyThreadID()  (( ((uint64_t)getpid()) << 32 ) | ( (uint64_t)(gettid()) ) )
#else
#define GetMyThreadID()  (( ((uint64_t)getpid()) << 32 ) | ( (uint64_t)(pthread_self()) ) )
#endif
#else
#define GetMyThreadID()  (( ((uint64_t)getppid()) << 32 ) | ( (uint64_t)(getpid()|0x40000000)) )
#endif
#define _GetMyThreadID GetMyThreadID
#endif
//#error blah
// general macros for linking lists using
#define DeclareLink( type )  type *next;type **me
#define RelinkThing( root, node )	   ((( node->me && ( (*node->me)=node->next ) )?	  node->next->me = node->me:0),(node->next = NULL),(node->me = NULL),node),	 ((( node->next = root )?	        (root->me = &node->next):0),	  (node->me = &root),	             (root = node) )
/* Link a new node into the list.
   Example
   struct mynode
   {
   DeclareLink( struct mynode );
   } *node;
   struct mynode *list;
   LinkThing( list_root, node );  */
#define LinkThing( root, node )		     ((( (node)->next = (root) )?	        (((root)->me) = &((node)->next)):0),	  (((node)->me) = &(root)),	             ((root) = (node)) )
/* Link a node to the end of a list. Link thing inserts the new
   node as the new head of the list.                            */
#define LinkLast( root, type, node ) if( node ) do { if( !root )	 { root = node; (node)->me=&root; }	 else { type tmp;	 for( tmp = root; tmp->next; tmp = tmp->next );	 tmp->next = (node);	 (node)->me = &tmp->next;	 } } while (0)
// put 'Thing' after 'node'
#define LinkThingAfter( node, thing )	 ( ( (thing)&&(node))	   ?(((((thing)->next = (node)->next))?((node)->next->me = &(thing)->next):0)	  ,((thing)->me = &(node)->next), ((node)->next = thing))	  :((node)=(thing)) )
//
// put 'Thing' before 'node'... so (*node->me) = thing
#define LinkThingBefore( node, thing )	 {  thing->next = (*node->me);	(*node->me) = thing;    thing->me = node->me;       node->me = &thing->next;     }
/* Remove a node from a list. Requires only the node. */
#define UnlinkThing( node )	                      ((( (node) && (node)->me && ( (*(node)->me)=(node)->next ) )?	  (node)->next->me = (node)->me:0),((node)->next = NULL),((node)->me = NULL),(node))
// this has two expressions duplicated...
// but in being so safe in this expression,
// the self-circular link needs to be duplicated.
// GrabThing is used for nodes which are circularly bound
#define GrabThing( node )	    ((node)?(((node)->me)?(((*(node)->me)=(node)->next)?	 ((node)->next->me=(node)->me),((node)->me=&(node)->next):NULL):((node)->me=&(node)->next)):NULL)
/* Go to the next node with links declared by DeclareLink */
#define NextLink(node) ((node)?(node)->next:NULL)
// everything else is called a thing... should probably migrate to using this...
#define NextThing(node) ((node)?(node)->next:NULL)
//#ifndef FALSE
//#define FALSE 0
//#endif
//#ifndef TRUE
//#define TRUE (!FALSE)
//#endif
/* the default type to use for flag sets - flag sets are arrays of bits which can be toggled on and off by an index. */
#define FLAGSETTYPE uint32_t
/* the number of bits a specific type is.
   Example
   int bit_size_int = FLAGTYPEBITS( int ); */
#define FLAGTYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* how many bits to add to make sure we round to the next greater index if even 1 bit overflows */
#define FLAGROUND(t) (FLAGTYPEBITS(t)-1)
/* the index of the FLAGSETTYPE which contains the bit in question */
#define FLAGTYPE_INDEX(t,n)  (((n)+FLAGROUND(t))/FLAGTYPEBITS(t))
/* how big the flag set is in count of FLAGSETTYPEs required in a row ( size of the array of FLAGSETTYPE that contains n bits) */
#define FLAGSETSIZE(t,n) (FLAGTYPE_INDEX(t,n) * sizeof( FLAGSETTYPE ) )
// declare a set of flags...
#define FLAGSET(v,n)   FLAGSETTYPE (v)[((n)+FLAGROUND(FLAGSETTYPE))/FLAGTYPEBITS(FLAGSETTYPE)]
// set a single flag index
#define SETFLAG(v,n)   ( (v)[(n)/FLAGTYPEBITS((v)[0])] |= 1 << ( (n) & FLAGROUND((v)[0]) ))
// clear a single flag index
#define RESETFLAG(v,n) ( (v)[(n)/FLAGTYPEBITS((v)[0])] &= ~( 1 << ( (n) & FLAGROUND((v)[0]) ) ) )
// test if a flags is set
#define TESTFLAG(v,n)  ( (v)[(n)/FLAGTYPEBITS((v)[0])] & ( 1 << ( (n) & FLAGROUND((v)[0]) ) ) )
// reverse a flag from 1 to 0 and vice versa
#define TOGGLEFLAG(v,n)   ( (v)[(n)/FLAGTYPEBITS((v)[0])] ^= 1 << ( (n) & FLAGROUND((v)[0]) ))
// 32 bits max for range on mask
#define MASK_MAX_LENGTH 32
// gives a 32 bit mask possible from flagset..
#define MASKSET_READTYPE uint32_t
// gives byte index...
#define MASKSETTYPE uint8_t
/* how many bits the type specified can hold
   Parameters
   t :  data type to measure (int, uint32_t, ... ) */
#define MASKTYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* the maximum number of bits storable in a type */
#define MASK_MAX_TYPEBITS(t) (sizeof(t)*CHAR_BIT)
/* round up to the next count of types that fits 1 bit - used as a cieling round factor */
#define MASKROUND(t) (MASKTYPEBITS(t)-1)
/* define MAX_MAX_ROUND factor based on MASKSET_READTYPE - how to read it... */
#define MASK_MAX_ROUND() (MASK_MAX_TYPEBITS(MASKSET_READTYPE)-1)
/* byte index of the start of the mask
   Parameters
   t :  type to measure with
   n :  mask index                     */
#define MASKTYPE_INDEX(t,n)  (((n)+MASKROUND(t))/MASKTYPEBITS(t))
/* The number of bytes the set would be.
   Parameters
   t :  the given type to measure with
   n :  the count of masks to fit.       */
#define MASKSETSIZE(t,n) (MASKTYPE_INDEX(t,(n+1)))
// declare a set of flags...
#define MASK_TOP_MASK_VAL(length,val) ((val)&( (0xFFFFFFFFUL) >> (32-(length)) ))
/* the mask in the dword resulting from shift-right.   (gets a mask of X bits in length) */
#define MASK_TOP_MASK(length) ( (0xFFFFFFFFUL) >> (32-(length)) )
/* the mast in the dword shifted to the left to overlap the field in the word */
#define MASK_MASK(n,length)   (MASK_TOP_MASK(length) << (((n)*(length))&0x7) )
// masks value with the mask size, then applies that mask back to the correct word indexing
#define MASK_MASK_VAL(n,length,val)   (MASK_TOP_MASK_VAL(length,val) << (((n)*(length))&0x7) )
/* declare a mask set. */
#define MASKSET(v,n,r)  MASKSETTYPE  (v)[(((n)*(r))+MASK_MAX_ROUND())/MASKTYPEBITS(MASKSETTYPE)]; const int v##_mask_size = r;
// set a field index to a value
#define SETMASK(v,n,val)    (((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS((v)[0])))[0] =    ( ((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS(uint8_t)))[0]                                  & (~(MASK_MASK(n,v##_mask_size))) )	                                                                           | MASK_MASK_VAL(n,v##_mask_size,val) )
// get the value of a field
#define GETMASK(v,n)  ( ( ((MASKSET_READTYPE*)((v)+((n)*(v##_mask_size))/MASKTYPEBITS((v)[0])))[0]                                  & MASK_MASK(n,v##_mask_size) )	                                                                           >> (((n)*(v##_mask_size))&0x7))
/* This type stores data, it has a self-contained length in
   bytes of the data stored.  Length is in characters       */
_CONTAINER_NAMESPACE
#define DECLDATA(name,length) struct {size_t size; TEXTCHAR data[length];} name
// Hmm - this can be done with MemLib alone...
// although this library is not nessecarily part of that?
// and it's not nessecarily allocated.
typedef struct SimpleDataBlock {
   size_t size;
/* unsigned size; size is sometimes a pointer value... this
                    means bad thing when we change platforms... Defined as
                    uintptr_t now, so it's relative to the size of the platform
                    anyhow.                                                    */
#ifdef _MSC_VER
#pragma warning (disable:4200)
#endif
   uint8_t  data[
#ifndef __cplusplus
   1
#endif
 // beginning of var data - this is created size+sizeof(uint8_t)
   ];
#ifdef _MSC_VER
#pragma warning (default:4200)
#endif
} DATA, *PDATA;
/* This is a slab array of pointers, each pointer may be
   assigned to point to any user data.
   Remarks
   When the list is filled to the capacity of Cnt elements, the
   list is reallocated to be larger.
   Cannot add NULL pointer to list, empty elements in the list
   are represented with NULL, and may be filled by any non-NULL
   value.                                                       */
_LINKLIST_NAMESPACE
/* <combine sack::containers::list::LinkBlock>
   \ \                                         */
typedef struct LinkBlock
{
	/* How many pointers the list can contain now. */
	INDEX     Cnt;
	/* \ \  */
	POINTER pNode[1];
} LIST, *PLIST;
_LINKLIST_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::containers::list;
#endif
_DATALIST_NAMESPACE
/* a list of data structures... a slab array of N members of X size */
typedef struct DataBlock  DATALIST;
/* A typedef of a pointer to a DATALIST struct DataList. */
typedef struct DataBlock *PDATALIST;
/* Data Blocks are like LinkBlocks, and store blocks of data in
   slab format. If the count of elements exceeds available, the
   structure is grown, to always contain a continuous array of
   structures of Size size.
   Remarks
   When blocks are deleted, all subsequent blocks are shifted
   down in the array. So the free blocks are always at the end. */
struct DataBlock
{
	/* How many elements are used. */
	INDEX     Cnt;
	/* How many elements are available in his array. */
	INDEX     Avail;
	/* A simple exchange lock on the data for insert and delete. For
	   thread safety.                                                */
	//volatile uint32_t     Lock;
	/* How big each element of the array is. */
	INDEX     Size;
	/* The physical array. */
	uint8_t      data[1];
};
_DATALIST_NAMESPACE_END
/* This is a stack that contains pointers to user objects.
   Remarks
   This is a stack 'by reference'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct LinkStack
{
	/* This is the index of the next pointer to be pushed or popped.
	   If top == 0, the stack is empty, until a pointer is added and
	   top is incremented.                                           */
	INDEX     Top;
	/* How many pointers the stack can contain. */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore. For
	                  thread safety.                                            */
	//volatile uint32_t     Lock;
	/*  a defined maximum capacity of stacked values... values beyond this are lost from the bottom  */
	uint32_t     Max;
	/* Reserved data portion that stores the pointers. */
	POINTER pNode[1];
} LINKSTACK, *PLINKSTACK;
/* A Stack that stores information in an array of structures of
   known size.
   Remarks
   The size of each element must be known at stack creation
   time. Structures are literally copied to and from this stack.
   This is a stack 'by value'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct DataListStack
{
	volatile INDEX     Top;
 /* enable logging the program executable (probably the same for
	                all messages, unless they are network)
	                                                                             */
 // How many elements are on the stack.
	INDEX     Cnt;
	//volatile uint32_t     Lock;  /* thread interlock using InterlockedExchange semaphore. For
	//                  thread safety.                                            */
	INDEX     Size;
	INDEX     Max;
	uint8_t      data[1];
} DATASTACK, *PDATASTACK;
/* A queue which contains pointers to user objects. If the queue
   is filled to capacity and new queue is allocated, and all
   existing pointers are transferred.                            */
typedef struct LinkQueue
{
	/* This is the index of the next pointer to be added to the
	   queue. If Top==Bottom, then the queue is empty, until a
	   pointer is added to the queue, and Top is incremented.   */
	volatile INDEX     Top;
	/* This is the index of the next element to leave the queue. */
	volatile INDEX     Bottom;
	/* This is the current count of pointers that can be stored in
	   the queue.                                                  */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore. For
	   thread safety.                                            */
#if USE_CUSTOM_ALLOCER
	volatile uint32_t     Lock;
#endif
 // need two to have distinct empty/full conditions
	POINTER pNode[2];
} LINKQUEUE, *PLINKQUEUE;
/* A queue of structure elements.
   Remarks
   The size of each element must be known at stack creation
   time. Structures are literally copied to and from this stack.
   This is a stack 'by value'. When extended, the stack will
   occupy different memory, care must be taken to not duplicate
   pointers to this stack.                                       */
typedef struct DataQueue
{
	/* This is the next index to be added to. If Top==Bottom, the
	   queue is empty, until an entry is added at Top, and Top
	   increments.                                                */
	volatile INDEX     Top;
	/* The current bottom index. This is the next one to be
	   returned.                                            */
	volatile INDEX     Bottom;
	/* How many elements the queue can hold. If a queue has more
	   elements added to it than it has count, it will be expanded,
	   and a new queue returned.                                    */
	INDEX     Cnt;
	/* thread interlock using InterlockedExchange semaphore */
	//volatile uint32_t     Lock;
	/* How big each element in the queue is. */
	INDEX     Size;
	/* How many elements to expand the queue by, when its capacity
	   is reached.                                                 */
	INDEX     ExpandBy;
	/* The data area of the queue. */
	uint8_t      data[1];
} DATAQUEUE, *PDATAQUEUE;
/* A mostly obsolete function, but can return the status of
   whether all initially scheduled startups are completed. (Or
   maybe whether we are not complete, and are processing
   startups)                                                   */
_CONTAINER_NAMESPACE_END
SACK_NAMESPACE_END
/* This contains the methods to use the base container types
   defined in sack_types.h.                                  */
#ifndef LINKSTUFF
#define LINKSTUFF
	SACK_NAMESPACE
	_CONTAINER_NAMESPACE
#    define TYPELIB_CALLTYPE
#  if defined( _TYPELIBRARY_SOURCE_STEAL )
#    define TYPELIB_PROC extern
#  elif defined( NO_EXPORTS )
#    if defined( _TYPELIBRARY_SOURCE )
#      define TYPELIB_PROC
#    else
#      define TYPELIB_PROC extern
#    endif
#  elif defined( _TYPELIBRARY_SOURCE )
#    define TYPELIB_PROC EXPORT_METHOD
#  else
#    define TYPELIB_PROC IMPORT_METHOD
#  endif
_LINKLIST_NAMESPACE
//--------------------------------------------------------
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        CreateListEx   ( DBG_VOIDPASS );
/* Destroy a PLIST. */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        DeleteListEx   ( PLIST *plist DBG_PASS );
/* See <link AddLink>.
   See <link DBG_PASS>. */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        AddLinkEx      ( PLIST *pList, POINTER p DBG_PASS );
/* Sets the value of a link at the specified index.
   Parameters
   pList :     address of a PLIST
   idx :       index of the element to set
   p :         new link value to be set at the specified index
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  PLIST TYPELIB_CALLTYPE        SetLinkEx      ( PLIST *pList, INDEX idx, POINTER p DBG_PASS );
/* Gets the link at the specified index.
   Parameters
   pList :  address of a PLIST pointer.
   idx :    index to get the link from.  */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      GetLink        ( PLIST *pList, INDEX idx );
/* Gets the address of the link node in the PLIST.
   Parameters
   pList :  address of a PLIST to get the node address
   idx :    index of the node to get the adddress of
   Example
   <code lang="c++">
   PLIST list = NULL; // don't have to use CreateList();
   POINTER *a;
   POINTER b;
   POINTER *result;
   a = &amp;b;
   AddLink( &amp;list, a );
   \result = GetLinkAddress( &amp;list, 0 );
    ( (*result) == b )
   </code>                                               */
TYPELIB_PROC  POINTER* TYPELIB_CALLTYPE     GetLinkAddress ( PLIST *pList, INDEX idx );
/* Locate a pointer in a PLIST. Return the index.
   Parameters
   pList :  address of a list pointer to locate link
   value :  link to find in the list
   Return Value List
   INVALID_INDEX :  Not found in the list
   0\-n :           Index of the first occurance of the link in the
                    list.                                           */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        FindLink       ( PLIST *pList, POINTER value );
/* return the count of used members in a PLIST
    pList : the list to count
	Return Value
	   number of things in the list.
*/
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        GetLinkCount   ( PLIST pList );
/* Uses FindLink on the list for the value to delete, and then
   sets the index of the found link to NULL.
   Parameters
   pList :  Address of a PLIST pointer
   value :  the link to find and remove from the list.
   Example
   <code lang="c++">
   PLIST list = NULL;
	POINTER a = &#47;*some address*&#47;;
   </code>
   <code>
   AddLink( &amp;list, a );
   DeleteLink( &amp;list, a );
   </code>                                                     */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      DeleteLink     ( PLIST *pList, CPOINTER value );
/* Remove all links from a PLIST. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyList      ( PLIST *pList );
#ifdef __cplusplus
/* This was a basic attempt to make list into a C++ class. I
   gave up doing this sort of thing afterwards after realizing
   the methods of a library and these static methods for a class
   aren't much different.                                        */
typedef class iList
{
public:
	PLIST list;
	INDEX idx;
	inline iList() { list = CreateListEx( DBG_VOIDSRC ); }
	inline ~iList() { DeleteListEx( &list DBG_SRC ); }
	inline iList &operator+=( POINTER &p ){ AddLinkEx( &list, p DBG_SRC ); return *this; }
	inline void add( POINTER p ) { AddLinkEx( &list, p DBG_SRC ); }
	inline void remove( POINTER p ) { DeleteLink( &list, p ); }
	inline POINTER first( void ) { POINTER p; for( idx = 0, p = NULL;list && (idx < list->Cnt) && (( p = GetLink( &list, idx ) )==0); )idx++; return p; }
	inline POINTER next( void ) { POINTER p; for( idx++;list && (( p = GetLink( &list, idx ) )==0) && idx < list->Cnt; )idx++; return p; }
	inline POINTER get(INDEX idx) { return GetLink( &list, idx ); }
} *piList;
#endif
// address of the thing...
typedef uintptr_t (CPROC *ForProc)( uintptr_t user, INDEX idx, POINTER *item );
// if the callback function returns non 0 - then the looping is aborted,
// and the value is returned... the user value is passed to the callback.
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE     ForAllLinks    ( PLIST *pList, ForProc func, uintptr_t user );
/* This is a iterator which can be used to check each member in
   a PLIST.
   Parameters
   list :     List to iterate through
   index :    variable to use to index the list
   type :     type of the elements stored in the list (for C++)
   pointer :  variable used to get the current member of the
              list.
   Example
   <code lang="c++">
   POINTER p;  // the pointer to receive the list member pointer (should be a user type)
   INDEX idx; // indexer
   PLIST pList; // some list.
   LIST_FORALL( pList, idx, POINTER, p )
   {
       // p will never be NULL here.
       // each link stored in the list is set to p here..
       // this is a way to remove this item from the list...
       SetLink( &amp;pList, idx, NULL );
       if( some condition )
          break;
   }
   </code>
   Another example that uses data and searches..
   <code lang="c++">
   PLIST pList = NULL;
   INDEX idx;
   CTEXTSTR string;
   AddLink( &amp;pList, (POINTER)"hello" );
   </code>
   <code>
   AddLink( &amp;pList, (POINTER)"world" );
   LITS_FORALL( pList, idx, CTEXTSTR, string )
   {
       if( strcmp( string, "hello" ) == 0 )
           break;
   }
   // here 'string' will be NULL if not found, else will be what was found
   </code>
   Remarks
   This initializes the parameters passed to the macro so that
   if the list is NULL or empty, then p will be set to NULL. If
   there are no non-nulll members in the list, p will be set to
   NULL. If you break in the loop, like in the case of searching
   the list for something, then p will be non-null at the end of
   the loop.
                                                                                         */
#define LIST_FORALL( l, i, t, v )  if(((v)=(t)NULL),(l))                                                        for( ((i)=0); ((i) < ((l)->Cnt))?                                         (((v)=(t)((l)->pNode[i])),1):(((v)=(t)NULL),0); (i)++ )  if( v )
/* This can be used to continue iterating through a list after a
   LIST_FORALL has been interrupted.
   Parameters
   list :     \Description
   index :    index variable for stepping through the list
   type :     type of the members in the list.
   pointer :  variable name to use to store the the current list
              element.
   Example
   <code lang="c++">
   PLIST pList = NULL;
   CTEXTSTR p;
   INDEX idx;
   </code>
   <code>
   AddLink( &amp;pList, "this" );
   AddLink( &amp;pList, "is" );
   AddLink( &amp;pList, "a" );
   AddLink( &amp;pList, "test" );
   LIST_FORALL( pList, idx, CTEXTSTR, p )
   {
       if( strcmp( p, "is" ) == 0 )
           break;
   }
   LIST_NEXTALL( pList, idx, CTEXTSTR, p )
   {
       printf( "remaining element : %s", p );
   }
   </code>
   <code lang="c++">
   j
   </code>                                                       */
#define LIST_NEXTALL( l, i, t, v )  if(l)                for( ++(i),((v)=(t)NULL); ((i) < ((l)->Cnt))?     (((v)=(t)(l)->pNode[i]),1):(((v)=(t)NULL),0); (i)++ )  if( v )
/* <combine sack::containers::list::CreateListEx@DBG_VOIDPASS>
   \ \                                                         */
#define CreateList()       ( CreateListEx( DBG_VOIDSRC ) )
/* <combine sack::containers::list::DeleteListEx@PLIST *plist>
   \ \                                                         */
#ifndef FIX_RELEASE_COM_COLLISION
#  define DeleteList(p)      ( DeleteListEx( (p) DBG_SRC ) )
#endif
/* Adds a pointer to a user object to a list.
   Example
   <code lang="c++">
   // the list can be initialized to NULL,
   // it does not have to be assigned the result of a CreateList().
   // this allows the list to only be allocated if it is used.
   PLIST list = NULL;
   AddLink( &amp;list, (POINTER)user_pointer );
   {
       POINTER p; // this should be USER_DATA_TYPE *p;
       INDEX idx; // just a generic counter.
       LIST_FORALL( list, idx, POINTER, p )
       {
           // for each item in the list, p will be not null.
           if( p-\>something == some_other_thing )
               break;
       }
       // p will be NULL if the list is empty
       // p will be NULL if the LIST_FORALL loop completes to termination.
       // p will be not NULL if the LIST_FORALL loop executed a 'break;'
   }
   </code>                                                                 */
#define AddLink(p,v)       ( AddLinkEx( (p),((POINTER)(v)) DBG_SRC ) )
/* <combine sack::containers::list::SetLinkEx@PLIST *@INDEX@POINTER p>
   \ \                                                                 */
#define SetLink(p,i,v)     ( SetLinkEx( (p),(i),((POINTER)(v)) DBG_SRC ) )
#ifdef __cplusplus
//		namespace list;
	};
#endif
//--------------------------------------------------------
_DATALIST_NAMESPACE
/* Creates a data list which hold data elements of the specified
   size.
                                                                 */
TYPELIB_PROC  PDATALIST TYPELIB_CALLTYPE  CreateDataListEx ( uintptr_t nSize DBG_PASS );
/* <combine sack::containers::data_list::DeleteDataList>
   \ \                                                   */
TYPELIB_PROC  void TYPELIB_CALLTYPE       DeleteDataListEx ( PDATALIST *ppdl DBG_PASS );
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    SetDataItemEx ( PDATALIST *ppdl, INDEX idx, POINTER data DBG_PASS );
/* Adds an item to a DataList.
   Example
   <code lang="c++">
   PDATALIST datalist = CreateDataList();
   struct my_struct {
       uint32_t my_data;
   }
   struct my_struct my_item;
   my_item.my_data = 0;
   AddDataItem( &amp;datalist, &amp;my_item );
   </code>                                     */
#define AddDataItem(list,data) (((list)&&(*(list)))?SetDataItemEx((list),(*list)->Cnt,data DBG_SRC ):NULL)
/* Sets the item at a specific nodes to the new data.
   Parameters
   ppdl :      address of a PDATALIST.
   idx :       index of element in list to set
   data :      POINTER to data to set element to
   DBG_PASS :  optional debug file/line information
   Example
   <code lang="c++">
      PDATALIST pdl;
      int oldval = 3;
      int newval = 5;
      pdl = CreateDataList( sizeof( int ) ); // store int's as data
      AddDataItem( &amp;pdl, &amp;oldval );
      SetDataItem( &amp;pdl, 0, &amp;newval );
   </code>                                                          */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    SetDataItemEx ( PDATALIST *ppdl, INDEX idx, POINTER data DBG_PASS );
/* \Returns a pointer to the data at a specified index.
   Parameters
   \ \
   ppdl :  address of a PDATALIST
   idx :   index of element to get                      */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE    GetDataItem ( PDATALIST *ppdl, INDEX idx );
/* Removes a data element from the list (moves all other
   elements down over it since there is no used indicator.
   Parameters
   ppdl :  address of a PDATALIST.
   idx :   index of element to delete                      */
TYPELIB_PROC  void TYPELIB_CALLTYPE       DeleteDataItem ( PDATALIST *ppdl, INDEX idx );
/* Empties a PDATALIST of all content.
   Parameters
   ppdl :  address of a PDATALIST
   Example
   <code lang="c++">
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) ); // store int's as data
   EmptyDataList( &amp;pdl );
   </code>                                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE       EmptyDataList ( PDATALIST *ppdl );
/* For loop to iterate through all items in a PDATALIST.
   <code lang="c++">
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) );
   {
      INDEX index;
      int *value;
      DATA_FORALL( pdl, index, int, value )
      {
      }
   }
   </code>                                               */
#define DATA_FORALL( l, i, t, v )  if(((v)=(t)NULL),(l)&&((l)->Cnt != INVALID_INDEX))	   for( ((i)=0);	                         (((i) < (l)->Cnt)                                             ?(((v)=(t)((l)->data + (uintptr_t)(((l)->Size) * (i)))),1)	         :(((v)=(t)NULL),0))&&(v); (i)++ )
/* <code>
   PDATALIST pdl;
   pdl = CreateDataList( sizeof( int ) );
   {
      INDEX index;
      int *value;
      DATA_FORALL( pdl, index, int, value )
      {
          // abort loop early
      }
      DATA_NEXTALL( pdl, index, int, value )
      {
      }
   }
   </code>                                   */
#define DATA_NEXTALL( l, i, t, v )  if(((v)=(t)NULL),(l))	   for( ((i)++);	                         ((i) < (l)->Cnt)                                             ?((v)=(t)((l)->data + (((l)->Size) * (i))))	         :(((v)=(t)NULL),0); (i)++ )
/* <combine sack::containers::data_list::CreateDataListEx@uintptr_t nSize>
   Creates a DataList specifying just the size. Uses the current
   source and line for debugging parameter.                               */
#define CreateDataList(sz) ( CreateDataListEx( (sz) DBG_SRC ) )
/* Destroy a DataList.
   Example
   <code>
   PDATALIST datalist = CreateDataList( 4 );
   DeleteDataList( &amp;datalist );
   </code>
   Parameters
   ppDataList :  pointer to the PDATALIST.   */
#define DeleteDataList(p)  ( DeleteDataListEx( (p) DBG_SRC ) )
/* <combine sack::containers::data_list::SetDataItemEx@PDATALIST *@INDEX@POINTER data>
   \ \                                                                                 */
#define SetDataItem(p,i,v) ( SetDataItemEx( (p),(i),(v) DBG_SRC ) )
   _DATALIST_NAMESPACE_END
//--------------------------------------------------------
#ifdef __cplusplus
		namespace link_stack {
#endif
/* Creates a new stack for links (POINTERS).
   Parameters
   DBG_PASS :  Debug file and line information to use for the
               allocation of the stack.
   Returns
   Pointer to a new link stack.                               */
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE   CreateLinkStackEx( DBG_VOIDPASS );
/* Creates a new stack for links (POINTERS).  Link stack has a limited number of entries.
    When the stack fills, the oldest item on the stack is removed automatically.
	 Parameters
	 max_entries : maximum depth of the stack.
   DBG_PASS :  Debug file and line information to use for the
               allocation of the stack.
   Returns
   Pointer to a new link stack.                               */
         // creates a link stack with maximum entries - any extra entries are pushed off the bottom into NULL
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE      CreateLinkStackLimitedEx        ( int max_entries  DBG_PASS );
/* <combine sack::containers::link_stack::CreateLinkStackLimitedEx@int max_entries>
   Macro to pass default debug file and line information.                           */
#define CreateLinkStackLimited(n) CreateLinkStackLimitedEx(n DBG_SRC)
/* Destroy a link stack. Sets the pointer to the stack to NULL
   on deletion.
   Parameters
   pls :       address of a link stack pointer
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteLinkStackEx( PLINKSTACK *pls DBG_PASS);
/* Pushes a new link on the stack.
   Parameters
   pls :       address of a link stack pointer
   p :         new pointer to push on the stack
   DBG_PASS :  debug source file and line information.
   Returns
   New link stack pointer if the stack was reallocated to have
   more space. Since the address of the pointer is passed, the
   pointer is already updated, and the return value is
   unimportant.                                                */
TYPELIB_PROC  PLINKSTACK TYPELIB_CALLTYPE   PushLinkEx       ( PLINKSTACK *pls, POINTER p DBG_PASS);
/* Reads the top value of the stack and returns it, removes top
   link on the stack.
   Parameters
   pls :  address of a link stack pointer
   Return Value List
   NULL :      Stack was empty
   not NULL :  Link that was on the top of the stack.           */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopLink          ( PLINKSTACK *pls );
/* Look at the top link on the stack.
   Parameters
   pls :  address of a link stack pointer
   Return Value List
   NULL :      Nothing on stack.
   not NULL :  link on the top of the stack. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekLink         ( PLINKSTACK *pls );
/* Look at links in the stack.
   Parameters
	pls :  address of a link stack pointer
	n : index of the element from the top to look at
   Return Value List
   NULL :      Nothing on stack at the position specified.
   not NULL :  link on the top of the stack. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekLinkEx         ( PLINKSTACK *pls, INDEX n );
// thought about adding these, but decided on creating a limited stack instead.
//TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      StackLength      ( PLINKSTACK *pls );
//TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopLinkEx        ( PLINKSTACK *pls, int position );
/* <combine sack::containers::link_stack::CreateLinkStackEx@DBG_VOIDPASS>
   Macro to pass default file and line information.                       */
#define CreateLinkStack()  CreateLinkStackEx( DBG_VOIDSRC )
/* <combine sack::containers::link_stack::DeleteLinkStackEx@PLINKSTACK *pls>
   Macro to pass default file and line information.                          */
#define DeleteLinkStack(p) DeleteLinkStackEx((p) DBG_SRC)
/* <combine sack::containers::link_stack::PushLinkEx@PLINKSTACK *@POINTER p>
   Macro to pass default debug file and line information.                    */
#define PushLink(p, v)     PushLinkEx((p),(v) DBG_SRC)
#ifdef __cplusplus
//		namespace link_stack {
		};
#endif
//--------------------------------------------------------
#ifdef __cplusplus
		namespace data_stack {
#endif
/* Creates a data stack for data element of the specified size.
   Parameters
   size :       size of elements in the stack
   DBG_PASS :  debug file and line information.                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   CreateDataStackEx( size_t size DBG_PASS );
/* Creates a data stack for data element of the specified size.
   Parameters
   size :       size of items in the stack
   count :      max items in stack (oldest gets deleted)
   DBG_PASS :  debug file and line information.                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   CreateDataStackLimitedEx( size_t size, INDEX count DBG_PASS );
/* Destroys a data stack.
   Parameters
   pds :       address of a data stack pointer. The pointer will
               be set to NULL when the queue is destroyed.
   DBG_PASS :  Debug file and line information.                  */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteDataStackEx( PDATASTACK *pds DBG_PASS);
/* Push a data element onto the stack. The size of the element
   is known at the stack creation time.
   Parameters
   pds :       address of a data stack pointer
   p :         pointer to data to push on stack
   DBG_PASS :  debug file and line information                 */
TYPELIB_PROC  PDATASTACK TYPELIB_CALLTYPE   PushDataEx     ( PDATASTACK *pds, POINTER pdata DBG_PASS );
/* \Returns an allocated buffer containing the data on the
   stack. Removes item from the stack.
   Parameters
   pds :  address of a data stack to get data from         */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PopData        ( PDATASTACK *pds );
/* Clear all data stored in the stack.
   Parameters
   pds :  address of a data stack pointer. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyDataStack ( PDATASTACK *pds );
/* Look at top item in the stack without removing it.
   Parameters
   pds :  address of a data stack to look at          */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekData       ( PDATASTACK *pds );
// Incrementing Item moves progressivly down the stack
// final(invalid) stack, and/or empty stack will return NULL;
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekDataEx     ( PDATASTACK *pds, INDEX Item );
 /* keeps data on stack (can be used)
                                                                                      Parameters
                                                                                      pds :   address of a data stack pointer
                                                                                      Item :  Item to peek at; 0 is the top, 1 is just below it...
                                                                                              (maybe \-1 is last and further up)
                                                                                      Returns
                                                                                      \returns the address of the data item in the data stack.     */
/* <combine sack::containers::data_stack::CreateDataStackEx@INDEX size>
   Macro to pass default file and line information.                     */
#define CreateDataStack(size) CreateDataStackEx( size DBG_SRC )
/* <combine sack::containers::data_stack::CreateDataStackEx@INDEX size>
   Macro to pass default file and line information.                     */
#define CreateDataStackLimited(size,items) CreateDataStackLimitedEx( size,items DBG_SRC )
/* <combine sack::containers::data_stack::DeleteDataStackEx@PDATASTACK *pds>
   Macro to pass default file and line information.                          */
#define DeleteDataStack(p) DeleteDataStackEx((p) DBG_SRC)
/* <combine sack::containers::data_stack::PushDataEx@PDATASTACK *@POINTER pdata>
   Macro to pass default file and line information.                              */
#define PushData(pds,p) PushDataEx(pds,p DBG_SRC )
#ifdef __cplusplus
 //		namespace data_stack {
		}
#endif
/* Queue container - can enque (at tail) deque (from head) and preque (at head). Can also browse the queue with peekqueue. */
#ifdef __cplusplus
		namespace queue {
#endif
/* Creates a <link sack::containers::PLINKQUEUE, LinkQueue>. In
   debug mode, gets passed the current source and file so it can
   blame the user for the allocation.                            */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   CreateLinkQueueEx( DBG_VOIDPASS );
/* Delete a link queue. Pass the address of the pointer to the
   queue to delete, this function sets the pointer to NULL if
   the queue is actually deleted.                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteLinkQueueEx( PLINKQUEUE *pplq DBG_PASS );
/* Enque a link to the queue.  */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   EnqueLinkEx      ( PLINKQUEUE *pplq, POINTER link DBG_PASS );
TYPELIB_PROC  void TYPELIB_CALLTYPE   EnqueLinkNLEx( PLINKQUEUE *pplq, POINTER link DBG_PASS );
/* EnqueLink adds the new item at the end of the list. PrequeueLink
   puts the new item at the head of the queue (so it's the next
   one to be retrieved).                                            */
TYPELIB_PROC  PLINKQUEUE TYPELIB_CALLTYPE   PrequeLinkEx      ( PLINKQUEUE *pplq, POINTER link DBG_PASS );
/* If the queue is not empty, returns the address of the next
   element in the queue and removes the element from the queue.
                                                                */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      DequeLink        ( PLINKQUEUE *pplq );
TYPELIB_PROC POINTER  TYPELIB_CALLTYPE      DequeLinkNL      ( PLINKQUEUE *pplq );
/* Return TRUE/FALSE if the queue is empty or not. */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      IsQueueEmpty     ( PLINKQUEUE *pplq );
/* Gets the number of elements current in the queue. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE        GetQueueLength   ( PLINKQUEUE plq );
// get a PLINKQUEUE element at index
//  If idx < 0 then count from the end of the queue, otherwise count from the start of the queue
// start of the queue is the next element to be dequeue, end of the queue is the last element added to the queue.
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekQueueEx    ( PLINKQUEUE plq, int idx );
/* Can be used to look at the next element in the queue without
   removing it from the queue. PeekQueueEx allows you to specify
   an index of an item in the queue to get.                      */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE      PeekQueue    ( PLINKQUEUE plq );
/* <combinewith sack::containers::queue::CreateLinkQueueEx@DBG_VOIDPASS>
   \ \                                                                   */
#define     CreateLinkQueue()     CreateLinkQueueEx( DBG_VOIDSRC )
/* <combine sack::containers::queue::PrequeLinkEx@PLINKQUEUE *@POINTER link>
   \ \                                                                       */
#define     PrequeLink(pplq,link) PrequeLinkEx( pplq, link DBG_SRC )
/* <combine sack::containers::queue::DeleteLinkQueueEx@PLINKQUEUE *pplq>
   \ \                                                                   */
#define     DeleteLinkQueue(pplq) DeleteLinkQueueEx( pplq DBG_SRC )
/* <combine sack::containers::queue::EnqueLinkEx@PLINKQUEUE *@POINTER link>
   \ \                                                                      */
#define     EnqueLink(pplq, link) EnqueLinkEx( pplq, link DBG_SRC )
#define     EnqueLinkNL(pplq, link) EnqueLinkNLEx( pplq, link DBG_SRC )
#ifdef __cplusplus
//		namespace queue {
		}
#endif
/* Functions related to PDATAQUEUE container. DataQueue stores
   literal data elements in the list instead of just a pointer. (could
   be used for optimized vertex arrays for instance).
   int data = 3;
   int result;
   PDATAQUEUE pdq = CreateDataQueue( sizeof( int ) );
   EnqueData( &amp;pdq, &amp;data );
   DequeData( &amp;pdq, &amp;result );
   DestroyDataQueue( &amp;pdq );                                       */
#ifdef __cplusplus
		namespace data_queue {
#endif
/* Creates a PDATAQUEUE. Can pass DBG_FILELINE information to
   blame other code for the allocation.                       */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   CreateDataQueueEx( INDEX size DBG_PASS );
/* Creates a PDATAQUEUE that has an overridden expand-by amount
   and initial amount of entries in the queue. (expecting
   something like 1000 to start and expand by 500, instead of
   the default 0, and expand by 1.                              */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   CreateLargeDataQueueEx( INDEX size, INDEX entries, INDEX expand DBG_PASS );
/* Destroys a data queue. */
TYPELIB_PROC  void TYPELIB_CALLTYPE         DeleteDataQueueEx( PDATAQUEUE *pplq DBG_PASS );
/* Add a data element into the queue. */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   EnqueDataEx      ( PDATAQUEUE *pplq, POINTER Data DBG_PASS );
/* Enque data at the head of the queue instead of the tail. (Normally
   add at tail, take from head).                                      */
TYPELIB_PROC  PDATAQUEUE TYPELIB_CALLTYPE   PrequeDataEx      ( PDATAQUEUE *pplq, POINTER Data DBG_PASS );
/* Removes data from a queue, resulting with the data in the
   specified buffer, and result TRUE if there was an element
   else FALSE, and the buffer is not modified.               */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      DequeData        ( PDATAQUEUE *pplq, POINTER Data );
/* Removes the last element in the queue. (takes from the tail). */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      UnqueData        ( PDATAQUEUE *pplq, POINTER Data );
/* Checks if the queue is empty, result TRUE if nothing in it,
   else FALSE.                                                 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE      IsDataQueueEmpty ( PDATAQUEUE *pplq );
/* Empty a dataqueue of all data. (Sets head=tail). */
TYPELIB_PROC  void TYPELIB_CALLTYPE         EmptyDataQueue ( PDATAQUEUE *pplq );
/*
 * get a PDATAQUEUE element at index
 * result buffer is a pointer to the type of structure expected to be
 * stored within this.  The buffer result is a copy of the data stored in the queue.
 * This enforces that data stored in the list is immutable.
 * Also on the basic DequeData function, after resulting, if the pointer to the
 * data within the queue were returned, it could become invalid immediatly after
 * returning by having another enque happen which overwrites that position in the buffer.
 * One could, in theory, set a flag in the queue that a deque was done, and not update the
 * bottom until that flag is encountered while within DequeData again...
 * the pointer to the data in the queue may also not be returned because the queue may be
 * reallocated and moved.
 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  PeekDataQueueEx    ( PDATAQUEUE *pplq, POINTER ResultBuffer, INDEX idx );
/* <combine sack::containers::data_queue::PeekDataQueueEx@PDATAQUEUE *@POINTER@INDEX>
   \ \                                                                                */
#define PeekDataQueueEx( q, type, result, idx ) PeekDataQueueEx( q, (POINTER)result, idx )
/*
 * Result buffer is filled with the last element, and the result is true, otherwise the return
 * value is FALSE, and the data was not filled in.
 */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  PeekDataQueue    ( PDATAQUEUE *pplq, POINTER ResultBuffer );
/* <combine sack::containers::data_queue::PeekDataQueue@PDATAQUEUE *@POINTER>
   \ \                                                                        */
#define PeekDataQueue( q, type, result ) PeekDataQueue( q, (POINTER)result )
/* <combine sack::containers::data_queue::CreateDataQueueEx@INDEX size>
   \ \                                                                  */
#define     CreateDataQueue(size)     CreateDataQueueEx( size DBG_SRC )
/* <combine sack::containers::data_queue::CreateLargeDataQueueEx@INDEX@INDEX@INDEX expand>
   \ \                                                                                     */
#define     CreateLargeDataQueue(size,entries)     CreateLargeDataQueueEx( size,entries, 0 DBG_SRC )
/* <combine sack::containers::data_queue::DeleteDataQueueEx@PDATAQUEUE *pplq>
   \ \                                                                        */
#define     DeleteDataQueue(pplq) DeleteDataQueueEx( pplq DBG_SRC )
/* <combine sack::containers::data_queue::EnqueDataEx@PDATAQUEUE *@POINTER Data>
   \ \                                                                           */
#define     EnqueData(pplq, Data) EnqueDataEx( pplq, Data DBG_SRC )
/* <combine sack::containers::data_queue::PrequeDataEx@PDATAQUEUE *@POINTER Data>
   \ \                                                                            */
#define     PrequeData(pplq, Data) PrequeDataEx( pplq, Data DBG_SRC )
#ifdef __cplusplus
//		namespace data_queue {
		}
#endif
//---------------------------------------------------------------------------
#ifdef __cplusplus
namespace message {
#endif
/* handle to a message queue. */
typedef struct MsgDataHandle *PMSGHANDLE;
//typedef struct MsgDataQueue *PMSGQUEUE;
// messages sent - the first dword of them must be
// a message ID.
typedef void (CPROC *MsgQueueReadCallback)( uintptr_t psv, CPOINTER p, uintptr_t sz );
/* Create a named shared memory message queue.
   Parameters
   name :     name of the queue to create
   size :     size of the queue.
   Read :     read callback, called when a message is received on
              the queue.
   psvRead :  user data associated with the queue. Passed to the
              read callback.                                      */
TYPELIB_PROC  PMSGHANDLE TYPELIB_CALLTYPE  SackCreateMsgQueue ( CTEXTSTR name, size_t size
                                                      , MsgQueueReadCallback Read
                                                      , uintptr_t psvRead );
/* Open a message queue. Opens if it exists, does not create.
   Parameters
   name :     name of the queue.
   Read :     read callback called when a message is received.
   psvRead :  user data associated with this queue, and passed to
              the read callback.                                  */
TYPELIB_PROC  PMSGHANDLE TYPELIB_CALLTYPE  SackOpenMsgQueue ( CTEXTSTR name
													 , MsgQueueReadCallback Read
													 , uintptr_t psvRead );
/* Destroys a message queue.
   Parameters
   ppmh :  address of the message queue handle to close (sets
           pointer to NULL when deleted)                      */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteMsgQueue ( PMSGHANDLE **ppmh );
 // if enque, fail send, return immediate on fail
#define MSGQUE_NOWAIT 0x0001
                             // if deque, fail no msg ready to get...
 // read any msg BUT MsgID
#define MSGQUE_EXCEPT 0x0002
 // enque this message... it is a task ID which is waiting.
#define MSGQUE_WAIT_ID 0x0004
/* Error result if there is no message to read. (GetLastError()
   after peekmsg or readmsg returns -1)                         */
#define MSGQUE_ERROR_NOMSG 1
/* Error result if the message to read is bigger than the buffer
   passed to read the message.                                   */
#define MSGQUE_ERROR_E2BIG 2
/* Error result. Unexpected error (queue head/tail out of
   bounds)                                                */
#define MSGQUE_ERROR_EABORT 5
// result is the size of the message, or 0 if no message.
// -1 if some other error?
TYPELIB_PROC  int TYPELIB_CALLTYPE  DequeMsgEx ( PMSGHANDLE pmh, long *MsgID, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Receives a message from the message queue.
   Parameters
   Message Queue :  PMSGHANDLE to read from
   Message ID * :   a Pointer to the message ID to read. Updated
                    with the message ID from the queue.
   buffer :         buffer to read message into
   buffer length :  length of the buffer to read
   options :        extra options for the read
   Return Value List
   \-1 :  Error
   0 :    No Message to read
   \>0 :  size of message read.
   Returns
   \ \                                                           */
#define DequeMsg(q,b,s,i,o) DequeMsgEx(q,b,s,i,o DBG_SRC )
/* <combine sack::containers::message::PeekMsg>
   \ \                                          */
TYPELIB_PROC  int TYPELIB_CALLTYPE  PeekMsgEx ( PMSGHANDLE pmh, long MsgID, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Just peek at the next message.
   Parameters
   queue :        The PMSGHANDLE queue to read.
   MsgID :        what message to read. 0 is read any message.
   buffer :       where to read the message data into.
   buffer_size :  the length of the message buffer.
   options :      Options controlling the read
   Returns
   \-1 on error
   0 if no message
   length of the message read                                  */
#define PeekMsg(q,b,s,i,o) PeekMsgEx(q,b,s,i,o DBG_SRC )
/* <combine sack::containers::message::EnqueMsg>
   \ \                                          */
TYPELIB_PROC  int TYPELIB_CALLTYPE  EnqueMsgEx ( PMSGHANDLE pmh, POINTER buffer, size_t msgsize, uint32_t options DBG_PASS );
/* Add a message to the queue.
   Parameters
   Message Queue :  PMSGQUEUE to write to.
   Buffer :         pointer to the message to send. THe MSgID is
                    the first part of the message buffer.
   Buffer Length :  how long the message to send is
   Options :        Extra options for send
   Return Value List
   \-1 :  Error
   \>0 :  bytes of message sent                                  */
#define EnqueMsg(q,b,s,o) EnqueMsgEx(q,b,s,o DBG_SRC )
/* Check if the message queue is empty.
   Parameters
   pmh :  queue to check if it's empty. */
TYPELIB_PROC  int TYPELIB_CALLTYPE  IsMsgQueueEmpty ( PMSGHANDLE pmh );
#ifdef __cplusplus
 //namespace message {
};
#endif
/* Routines to deal with SLAB allocated blocks of structures.
   Each slab has multiple elements of a type in it, and the
   blocks are tracked as a linked list. Each block also has a
   bitmask of allocated elements in the set.
   \---------------------------------------------------------------------------
   Set type
   Usage:
   typedef struct name_tag { } \<name\>;
   \#define MAX\<name\>SPERSET
   DeclareSet( \<name\> );
   Should alias GetFromset, DeleteFromSet, CountUsedInSet,
   GetLinearSetArray
   etc so that the type name is reflected there
   another good place where #define defining defines is good.
   \---------------------------------------------------------------------------
                                                                                */
_SETS_NAMESPACE
//---------------------------------------------------------------------------
// Set type
//   Usage:
//      typedef struct name_tag { } <name>;
//      #define MAX<name>SPERSET
//      DeclareSet( <name> );
//    Should alias GetFromset, DeleteFromSet, CountUsedInSet, GetLinearSetArray
//       etc so that the type name is reflected there
//       another good place where #define defining defines is good.
//---------------------------------------------------------------------------
/* Hard coded 32 bit division for getting word index. (x\>\>5) */
#define UNIT_USED_IDX(n)   ((n) >> 5)
/* Hard coded 32 bit division for getting bit index. (x &amp;
   0x1f)                                                      */
#define UNIT_USED_MASK(n)  (1 << ((n) &0x1f))
/* A macro for use by internal code that marks a member of a set
   as used.
   Parameters
   set :    pointer to a genericset
   index :  item to mark used.                                   */
#define SetUsed(set,n)   ((((set)->bUsed[UNIT_USED_IDX(n)]) |= UNIT_USED_MASK(n)), (++(set)->nUsed) )
/* A macro for use by internal code that marks a member of a set
   as available.
   Parameters
   set :    pointer to a genericset
   index :  item to mark available.                              */
#define ClearUsed(set,n) ((((set)->bUsed[UNIT_USED_IDX(n)]) &= ~UNIT_USED_MASK(n)), (--(set)->nUsed) )
/* A macro for use by internal code that tests a whole set of
   bits for used. (32 bits, can check to see if any in 32 is
   free)
   Parameters
   set :    pointer to a genericset
   index :  index of an one in the set of 32 being tested.
   Returns
   0 if not all are used.
   1 if all in this block of bits are used.                   */
#define AllUsed(set,n)   (((set)->bUsed[UNIT_USED_IDX(n)]) == 0xFFFFFFFF )
/* A macro for use by internal code that tests a member of a set
   as used.
   Parameters
   set :    pointer to a genericset
   index :  item to test used.
   Returns
   not zero if is used, otherwise is free.                       */
#define IsUsed(set,n)    (((set)->bUsed[UNIT_USED_IDX(n)]) & UNIT_USED_MASK(n) )
#ifdef __cplusplus
#define CPP_(n)
/* A macro which is used to emit code in C++ mode... */
#else
#define CPP_(n)
#endif
// requires a symbol of MAX<insert name>SPERSET to declare max size...
 //ndef __cplusplus
#if 1
#define SizeOfSet(size,count)  (sizeof(POINTER)*2+sizeof(int)+sizeof( uint32_t[((count)+31)/32] ) + ((size)*(count)))
#define DeclareSet( name )  typedef struct name##set_tag {	   struct name##set_tag *next, *prior;	                      uint32_t nUsed;	                                               uint32_t nBias;	                                               uint32_t bUsed[(MAX##name##SPERSET + 31 ) / 32];	              name p[MAX##name##SPERSET];	                           CPP_(int forall(uintptr_t(CPROC*f)(void*,uintptr_t),uintptr_t psv) {if( this ) return _ForAllInSet( (struct genericset_tag*)this, sizeof(name), MAX##name##SPERSET, f, psv ); else return 0; })	 CPP_(name##set_tag() { next = NULL;prior = NULL;nUsed = 0; nBias = 0; MemSet( bUsed, 0, sizeof( bUsed ) ); MemSet( p, 0, sizeof( p ) );} )	} name##SET, *P##name##SET
#define DeclareClassSet( name ) typedef struct name##set_tag {	   struct name##set_tag *next, *prior;	                      uint32_t nUsed;	                                               uint32_t nBias;	                                               uint32_t bUsed[(MAX##name##SPERSET + 31 ) / 32];	              class name p[MAX##name##SPERSET];	                        CPP_(int forall(uintptr_t(CPROC*)(void*f,uintptr_t),uintptr_t psv) {if( this ) return _ForAllInSet( (struct genericset_tag*)this, sizeof(class name), MAX##name##SPERSET, f, psv ); else return 0; })	 } name##SET, *P##name##SET
#endif
/* This represents the basic generic set structure. Addtional
   data is allocated at the end of this strcture to fit the bit
   array that maps usage of the set, and for the set size of
   elements.
   Remarks
   \ \
   Summary
   Generic sets are good for tracking lots of tiny structures.
   They track slabs of X structures at a time. They allocate a
   slab of X structures with an array of X bits indicating
   whether a node is used or not. The structure overall has how
   many are used, so once full, a block can be quickly checked
   whether there is anything free. Then when checking a block
   that might have room, the availablility is checked 32 bits at
   a time, until a free spot is found.
   Sets of 1024 members of x,y coordinates for example are good
   for this sort of storage. the points are often static, once
   loaded they all exist until none of them do. This storage has
   gross deletion methods too, quickly evaporate all allocated
   chunks. Storing tiny chunks in a slab is more efficient
   because every allocation method has some sort of tracking
   associated with it - an overhead of having it. Plus, when
   operating on sets of data, a single solid slab of exatly the
   structures you are working with is more efficient to cache.
   Example
   <code lang="c++">
   struct treenode_tag {
       uint32_t treenode_data;  // abitrary structure data
   };
   typedef struct treenode_tag TREENODE;
   \#define MAXTREENODESPERSET 256
   DeclareSet( TREENODE );
   </code>
   The important part of the prior code is the last two lines.
   \#define MAX\<your type name\>SPERSET \<how many\>
   This defines how many of your structure are kept per set
   block.
   The DeclareSet( type ) declares a typedefed structure called
   'struct type##set_tag', 'name##SET', and '*P##name##SET'; in
   the above case, it would be 'struct TREENODEset_tag',
   'TREENODESET', and 'PTREENODESET'.
   Then to actually use the set...
   <code lang="c#">
   // declare a set pointer with one of the magic names.
   PTREENODESET nodeset = NULL;
   // get a node from the set.
   TREENODE *node = GetFromSet( TREENODE, nodeset );
   </code>
   Notice there is no CreateSet, getting a set member will
   create the set as required. Many operations may expend the
   set, except for GetUsedSetMember which will only result with
   \members that are definatly in the set. Accesses to the set
   are all prefixed by the type name the set was created with,
   'TREENODE' in this example.
   <code lang="c++">
   DeleteFromSet( TREENODE, nodeset, node );
   node = GetFromSet( TREENODE, nodeset );
   {
      int index = GetMemberIndex( TREENODE, nodeset, node );
   }
   </code>
   The accessor macros take care of expanding several parameters
   that require sizeof structure expansion.                      */
typedef struct genericset_tag {
	// wow might be nice to have some flags...
	// first flag - bSetSet - meaning that this is a set of sets of
	// the type specified...
	struct genericset_tag *next;
	/* This is the pointer that's pointing at the pointer pointing
	   to me. (did you get that?) See <link DeclareLink>.          */
	struct genericset_tag **me;
	/* number of spots in this set block that are used. */
	uint32_t nUsed;
 // hmm if I change this here? we're hozed... so.. we'll do it anyhow :) evil - recompile please
	uint32_t nBias;
 // after this p * unit must be computed
	uint32_t bUsed[1];
} GENERICSET, *PGENERICSET;
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetFromSetEx( GENERICSET **pSet, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetFromSetEx@GENERICSET **@int@int@int maxcnt>
   \ \                                                                             */
#define GetFromSeta(ps, ss, us, max) GetFromSetPoolEx( NULL, 0, 0, 0, (ps), (ss), (us), (max) DBG_SRC )
/* <combine sack::containers::sets::GetFromSetEx@GENERICSET **@int@int@int maxcnt>
   \ \
   Parameters
   name :  name of type the set contains.
   pSet :  pointer to a set to get an element from.                                */
#define GetFromSet( name, pset ) (name*)GetFromSeta( (GENERICSET**)(pset), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  PGENERICSET  TYPELIB_CALLTYPE GetFromSetPoolEx( GENERICSET **pSetSet
													 , int setsetsize, int setunitsize, int setmaxcnt
													 , GENERICSET **pSet
													 , int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetFromSetPoolEx@GENERICSET **@int@int@int@GENERICSET **@int@int@int maxcnt>
   \ \                                                                                                           */
#define GetFromSetPoola(pl, sss, sus, smax, ps, ss, us, max) GetFromSetPoolEx( (pl), (sss), (sus), (smax), (ps), (ss), (us), (max) DBG_SRC )
/* <combine sack::containers::sets::GetFromSetPoolEx@GENERICSET **@int@int@int@GENERICSET **@int@int@int maxcnt>
   \ \                                                                                                           */
#define GetFromSetPool( name, pool, pset ) (name*)GetFromSetPoola( (GENERICSET**)(pool)	    , sizeof( name##SETSET ), sizeof( name##SET ), MAX##name##SETSPERSET	, (GENERICSET**)(pset), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetSetMemberEx( GENERICSET **pSet, INDEX nMember, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                     */
#define GetSetMembera(ps, member, ss, us, max) (GetSetMemberEx( (ps), (member), (ss), (us), (max) DBG_SRC ))
/* <combine sack::containers::sets::GetSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                     */
#define GetSetMember( name, pset, member ) ((name*)GetSetMembera( (GENERICSET**)(pset), (member), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET ))
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE GetUsedSetMemberEx( GENERICSET **pSet, INDEX nMember, int setsize, int unitsize, int maxcnt DBG_PASS );
/* <combine sack::containers::sets::GetUsedSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                         */
#define GetUsedSetMembera(ps, member, ss, us, max) (GetUsedSetMemberEx( (ps), (member), (ss), (us), (max) DBG_SRC ))
/* <combine sack::containers::sets::GetUsedSetMemberEx@GENERICSET **@INDEX@int@int@int maxcnt>
   \ \                                                                                         */
#define GetUsedSetMember( name, pset, member ) ((name*)GetUsedSetMembera( (GENERICSET**)(pset), (member), sizeof( name##SET ), sizeof( name ), MAX##name##SPERSET ))
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetMemberIndex(GENERICSET **set, POINTER unit, int unitsize, int max );
/* Gets the index of a member passed as a pointer.
   Parameters
   set :       pointer to the set the member is in
   unit :      pointer to the member in the set to get the index
               of.
   unitsize :  size of each member in the set
   max :       count of members in each set block.
   Returns
   \Returns the index of the member passed in as a pointer.      */
#define GetMemberIndex(name,set,member) GetMemberIndex( (GENERICSET**)set, member, sizeof( name ), MAX##name##SPERSET )
/* <combine sack::containers::sets::GetMemberIndex>
   \ \                                              */
#define GetIndexFromSet( name, pset ) GetMemberIndex( name, pset, GetFromSet( name, pset ) )
/* \ \
   Parameters
   pSet :      pointer to a generic set
   nMember :   index of the member
   setsize :   number of elements in each block
   unitsize :  set block
   maxcnt :    max elements per set block       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteFromSetExx( GENERICSET *set, POINTER unit, int unitsize, int max DBG_PASS );
/* <combine sack::containers::sets::DeleteFromSetExx@GENERICSET *@POINTER@int@int max>
   \ \                                                                                 */
#define DeleteFromSetEx( name, set, member, xx ) DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC )
/* <combine sack::containers::sets::DeleteFromSetExx@GENERICSET *@POINTER@int@int max>
   \ \                                                                                 */
#ifdef _DEBUG
#define DeleteFromSet( name, set, member ) do { P##name##SET testset = set; DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC ); } while(0)
#else
#define DeleteFromSet( name, set, member ) DeleteFromSetExx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET DBG_SRC )
#endif
/* Marks a member in a set as usable.
   Parameters
   set :       pointer to a genericset pointer
   iMember :   index of member to delete
   unitsize :  (filled by macro) size of element in set
   max :       (filled by macro) size of a block of elements. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteSetMemberEx( GENERICSET *set, INDEX iMember, uintptr_t unitsize, INDEX max );
/* <combine sack::containers::sets::DeleteSetMemberEx@GENERICSET *@INDEX@uintptr_t@INDEX>
   \ \                                                                                   */
#define DeleteSetMember( name, set, member ) DeleteSetMemberEx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET )
/* This function can check to see if a pointer is a valid
   element from a set.
   Parameters
   set :       pointer to a set to check
   unit :      pointer to an element from the set
   unitsize :  size of element structures in the set.
   max :       count of structures per set block
   Returns
   TRUE if unit is in the set, else FALSE.                */
TYPELIB_PROC  int TYPELIB_CALLTYPE  MemberValidInSetEx( GENERICSET *set, POINTER unit, int unitsize, int max );
/* <combine sack::containers::sets::MemberValidInSetEx@GENERICSET *@POINTER@int@int>
   \ \                                                                               */
#define MemberValidInSet( name, set, member ) MemberValidInSetEx( (GENERICSET*)set, member, sizeof( name ), MAX##name##SPERSET )
TYPELIB_PROC  int TYPELIB_CALLTYPE  CountUsedInSetEx( GENERICSET *set, int max );
/* Count number of elements that are allocated in the set.
   Parameters
   set :  The set to check
   max :  max items per set (may be unused, since this is stored
          internally now)
   Returns
   The number of items in the step.                              */
#define CountUsedInSet( name, set ) CountUsedInSetEx( (GENERICSET*)set, MAX##name##SPERSET )
TYPELIB_PROC  POINTER * TYPELIB_CALLTYPE GetLinearSetArrayEx( GENERICSET *pSet, int *pCount, int unitsize, int max );
/* Converts a set into a copy of the objects in the set
   organized in a flat array.
   Parameters
   pSet :      set to convert to an array
   pCount :    address of an integer to receive the count of
               elements put in the array.
   unitsize :  size of each element in the set
   max :       count of elements per set block
   Returns
   Pointer to an array that are a copy of the objects in the
   set.                                                      */
#define GetLinearSetArray( name, set, pCount ) GetLinearSetArrayEx( (GENERICSET*)set, pCount, sizeof( name ), MAX##name##SPERSET )
/* Returned the index of an item in a linear array returned from
   a set.
   Parameters
   pArray :      pointer to an array which has been returned from
                 the set
   nArraySize :  size fo the array
   unit :        pointer to an element in the array
   Returns
   Index of the unit in the array, INVALID_INDEX if not in the
   array.                                                         */
TYPELIB_PROC  int TYPELIB_CALLTYPE  FindInArray( POINTER *pArray, int nArraySize, POINTER unit );
/* Delete all allocated slabs.
   Parameters
   ppSet :  pointer to a generic set pointer to delete. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteSet( GENERICSET **ppSet );
/* <combine sack::containers::sets::DeleteSet@GENERICSET **>
   \ \                                                       */
#define DeleteSetEx( name, ppset ) { name##SET **delete_me = ppset; DeleteSet( (GENERICSET**)delete_me ); }
/* <combine sack::containers::sets::ForAllInSet>
   ForAllinSet Callback - callback fucntion used with
   ForAllInSet                                        */
typedef uintptr_t (CPROC *FAISCallback)(void*,uintptr_t);
/* \ \
   Parameters
   pSet :      poiner to a set
   unitsize :  size of elements in the array
   max :       count of elements per set block
   f :         user callback function to call for each element in
               the set
   psv :       user data passed to the user callback when it is
               invoked for a member of the set.
   Returns
   If the user callback returns 0, the loop continues. If the
   user callback returns non zero then the looping through the
   set ends, and that result is returned.                         */
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE  _ForAllInSet( GENERICSET *pSet, int unitsize, int max, FAISCallback f, uintptr_t psv );
/* <combine sack::containers::sets::ForEachSetMember>
   ForEachSetMember Callback function - for the function '
   ForEachSetMember'                                       */
typedef uintptr_t (CPROC *FESMCallback)(INDEX,uintptr_t);
TYPELIB_PROC  uintptr_t TYPELIB_CALLTYPE  ForEachSetMember ( GENERICSET *pSet, int unitsize, int max, FESMCallback f, uintptr_t psv );
 //def __cplusplus
#if 0
#define DeclareSet(name)	                                struct name##set_tag {	               uint32_t set_size;	                             uint32_t element_size;	                         uint32_t element_cnt;	                          PGENERICSET pool;	                        name##set_tag() {	                        element_size = sizeof( name );	             element_cnt = MAX##name##SPERSET;	          set_size = (element_size * element_cnt )+ ((((element_cnt + 31 )/ 32 )- 1 ) * 4) + sizeof( GENERICSET );	 pool = NULL;	                               }	    ~name##set_tag() { DeleteSet( &pool ); }	 name* grab() { return (name*)GetFromSetEx( &pool, set_size, element_size, element_cnt DBG_SRC ); }	 name* grab(INDEX member) { return (name*)GetSetMemberEx( &pool, member, set_size, element_size, element_cnt DBG_SRC ); }	 name* get(INDEX member) { return (this)?(name*)GetUsedSetMemberEx( &pool, member, set_size, element_size, element_cnt DBG_SRC ):(NULL); }	 void drop( name* member ) { DeleteFromSetEx( pool, (POINTER)member, element_size, element_cnt ); }	 int valid( name* member ) { return MemberValidInSetEx( pool, (POINTER)member, element_size, element_cnt ); }	 uintptr_t forall( FAISCallback f, uintptr_t psv ) { if( this ) return _ForAllInSet( pool, element_size, element_cnt, f, psv ); else return 0; }	 };	       typedef struct name##set_tag *P##name##SET, name##SET;
#define ForAllInSet(name, pset,f,psv) _ForAllInSet( (GENERICSET*)(pset), sizeof( name ), MAX##name##SPERSET, (f), (psv) )
#else
/* <combine sack::containers::sets::_ForAllInSet@GENERICSET *@int@int@FAISCallback@uintptr_t>
   \ \                                                                                       */
#define ForAllInSet(name, pset,f,psv) _ForAllInSet( (GENERICSET*)(pset), sizeof( name ), MAX##name##SPERSET, (f), (psv) )
/* Performs an iteration over each allocated set member. Calls
   the user provided callback routine with each element in the
   set.
   Parameters
   pSet :      pointer to the set to iterate
   unitsize :  size of each element
   max :       max count of elements per set block
   f :         function to call ( uintptr_t (*)(INDEX,uintptr_t) )
   psv :       user data value to pass to function as uintptr_t
   Returns
   uintptr_t - this value is the return of the user function if
   the function does not return 0. A non zero return from the
   user callback stops iteration.                                */
#define ForEachSetMember(name,pset,f,psv) ForEachSetMember( (GENERICSET*)(pset),sizeof(name),MAX##name##SPERSET, (f), (psv) )
#endif
//---------------------------------------------------------------------------
_SETS_NAMESPACE_END
_TEXT_NAMESPACE
// this defines more esoteric formatting notions...
// these data blocks will be zero sized, and ahve the TF_FORMATEX
// bit set.
//#define DEFAULT_COLOR 0xF7
//#define PRIOR_COLOR 0xF6 // this does not change the color....
// these enumerated ops put in the foreground field of a format
// with a flag of TF_FORMATEX will cause the specified operation
// to be carried out on a display (not files) or generated into
// the appropriate sequence (ansi out encode)
// -- correction
//  this is encoded into its own field for the format
// size, due to machine optimization, 16 bits were free
// this was expanded and used for all information
// a segment may contain extended op, color, attributes,
// and text, everything short of a font for it...
//  - not sure how to address that issue... there's
// certainly modifications to current font... italic for
// instance..
	enum FORMAT_OPS {
      /* this segment clears to the end of the line.  Its content is then added to the output */
		FORMAT_OP_CLEAR_END_OF_LINE = 1
        ,FORMAT_OP_CLEAR_START_OF_LINE
                   ,
						  FORMAT_OP_CLEAR_LINE
						 ,
						  FORMAT_OP_CLEAR_END_OF_PAGE
                   ,
						  FORMAT_OP_CLEAR_START_OF_PAGE
						 ,
/* clear the entire vieable page (pushes all content to history)
                    set cursor home ;6*/
						  FORMAT_OP_CLEAR_PAGE
						 ,
						  FORMAT_OP_CONCEAL
                   ,
						  FORMAT_OP_DELETE_CHARS
                   ,
						  FORMAT_OP_SET_SCROLL_REGION
                   ,
						  FORMAT_OP_GET_CURSOR
						 ,
						  FORMAT_OP_SET_CURSOR
						 ,
						  FORMAT_OP_PAGE_BREAK
						 ,
/* break between paragraphs - kinda same as lines...
						  since lines are as long as possible... ;13 */
						 FORMAT_OP_PARAGRAPH_BREAK
						 ,
/* Justify line(s if wrapped) to the right
						   This attribute should be passed through to renderer;14*/
                   FORMAT_OP_JUSTIFY_RIGHT
						 ,
/* Justify line(s if wrapped) to the center
						 This attribute should be passed through to renderer;15*/
                   FORMAT_OP_JUSTIFY_CENTER
};
//typedef struct text_color_tag { uint32_t color: 8; } TEXTCOLOR;
// this was a 32 bit structure, but 8 fore, 8 back
// 8 x, 8 y failed for positioning...
// extended position, added more information
// reduced color, 16 colors is really all that there
// are... 4 bits... added bits for extended formatting
// like blink, bold, wide, high
// foreground/background  values will be
// sufficient... they retain full informaiton
//
typedef struct format_info_tag
{
   /* bit-packed flags indicating the type of format information that is applied to this segment.*/
	struct {
		// extended operation from enumeration above...
		// might shrink if more attributes are desired...
		// if many more are needed, one might consider
      // adding FONT!
     /* this segment uses the prior foreground, not its own. */
		BIT_FIELD prior_foreground : 1;
     /* this segment uses the prior background, not its own. */
		BIT_FIELD prior_background : 1;
     /* this segment uses the default foreground, not its own. */
		BIT_FIELD default_foreground : 1;
      /* this segment uses the default background, not its own. */
		BIT_FIELD default_background : 1;
      /* the foreground color of this segment (0-16 standard console text [ANSI text]) */
		BIT_FIELD foreground : 4;
      /* the background color of this segment (0-16 standard console text [ANSI text]) */
		BIT_FIELD background : 4;
      /* a bit indicating the text should blink if supported */
		BIT_FIELD blink : 1;
      /* a bit indicating the foreground and background color should be reversed */
		BIT_FIELD reverse : 1;
		// usually highly is bolder, perhaps it's
      // a highlighter effect and changes the background
		BIT_FIELD highlight : 1;
		// this is double height modifications to the font...
		BIT_FIELD tall : 1;
      // this is thicker characters...
		BIT_FIELD bold : 1;
      // draw a line under the text...
		BIT_FIELD underline : 1;
		// strike through - if able, draw a line right
		// through the middle of the text... maybe
		// it's a wiggly scribble line?  maybe that
      // could be extended again?
		BIT_FIELD strike : 1;
      // text is drawn wide (printer kinda font?)
		BIT_FIELD wide : 1;
       // this is pretty common......
		BIT_FIELD italic : 1;
		// --
		// these flags are free, but since we already have text segments
		// and I'm bringing in consoles, perhaps we should consider using
		// this to describe captions, but provide the api layer for CTEXTSTR
		// --
		// position data remains constant.
		// text is mounted at the top/left of the
		// first character... (unless center, then
		// the position specifies the middle of the text
		// draw vertical instead of horizontal
		BIT_FIELD bVertical:1;
		// draw opposite/upside down from normal
		// vertical/down, right/left upside down if not centered
		// if centered, the text pivots around position.
		BIT_FIELD bInvert:1;
		// 0 = default alignment 1 = left, 2 = center 3 = right
		// 0 is not set, the flag set in the lower 32 bit flags
		// is not needed any longer.... anything non zero
		// is that operation to apply.
		BIT_FIELD bAlign:2;
      /* format op indicates one of the enum FORMAT_OPS applies to this segment */
		BIT_FIELD format_op : 7;
	} flags;
	// if x,y are valid segment will have TF_POSFORMAT set...
	union {
		/* Coordinate information attached to a text segment. */
		/* Positioning specification of this text segment. with
		   basically 0 format options, position is used.
		   Position represents the distance from this segment to the
		   prior segment in count of tabs and spaces.
		   coords specifies an x,y coordinate location for the segment.
		   Usage of this union is dependant on <link text::format_info_tag::flags@1::format_op, format_op>. */
		struct {
         // Signed coordinate of this segment on a text display.  May be relative depending on format_op.
			int16_t x;
         // Signed coordinate of this segment on a text display.  May be relative depending on format_op.
			int16_t y;
		} coords;
		/* Defines the distance from the prior segment in count of tabs
		   and spaces (mostly count of spaces).                         */
		struct {
   // tabs preceed spaces....
			uint16_t tabs;
 // not sure what else to put with this...
			uint16_t spaces;
		} offset;
	} position;
} FORMAT, *PFORMAT;
 // special coordinate which is NO coordinate
#define IGNORE_CURSOR_POS -16384
/* test flag, format has position data */
#define TF_FORMATPOS (TF_FORMATABS|TF_FORMATREL|TF_FORMATEX)
/* these flags are used in PTEXT.flags member
 applications may use these flags to group expressions
 will affect the BuildLine but is not generated by library.
( TF_QUOTE, TF_SQUOTE, TF_BRACKET, TF_BRACE, TF_PAREN, and TF_TAG).
*/
enum TextFlags {
   // declared in program data.... do NOT release
 TF_STATIC    = 0x00000001,
   // double quoted string segment " "
 TF_QUOTE     = 0x00000002,
   // single quoted string ' '
 TF_SQUOTE    = 0x00000004,
   // bracketed expression []
 TF_BRACKET   = 0x00000008,
   // braced expression {}
 TF_BRACE     = 0x00000010,
   // parenthised expression ()
 TF_PAREN     = 0x00000020,
   // HTML tag like expression &lt;&gt;
 TF_TAG       = 0x00000040,
   // foreground is FORMAT_OP
 TF_FORMATEX  = 0x00000080,
   // x,y position used (relative)
 TF_FORMATREL = 0x00000100,
   // size field extually points at PTEXT
 TF_INDIRECT  = 0x00000200,
   // format position is x/y - else space count
 TF_FORMATABS = 0x00000800,
   // set during burst for last segment...
 TF_COMPLETE  = 0x00001000,
   // set for non-text variable
 TF_BINARY    = 0x00002000,
   // on release release indrect also...
 TF_DEEP      = 0x00004000,
   // set on first segment to send to omit lead \r\n
 TF_NORETURN  = 0x00008000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
// Low bound of value...
  TF_LOWER     = 0x00010000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
  // Upper bound of a value...
  TF_UPPER     = 0x00020000,
// these values used originally for ODBC query construction....
// these values are flags stored on the indirect following a value
// label...
// boundry may be ON this value...
 TF_EQUAL     = 0x00040000,
   // this segment is not a permanent part (SubstToken)
 TF_TEMP      = 0x00080000,
  // this is something special do not treat as text indirect.
 TF_APPLICATION = 0x00100000,
};
//--------------------------------------------------------------------------
// flag combinatoin which represents actual data is present even with 0 size
// extended format operations (position, ops) are also considered data.
#define IS_DATA_FLAGS (TF_QUOTE|TF_SQUOTE|TF_BRACKET|TF_BRACE|                              TF_PAREN|TF_TAG|TF_FORMATEX|TF_FORMATABS|TF_FORMATREL)
#define DECLTEXTSZTYPE( name, size ) struct {    uint32_t flags;    struct text_segment_tag *Next, *Prior;    FORMAT format;    DECLDATA(data, size); } name
/* A macro to declare a structure which is the same physically
   as a PTEXT, (for declaring static buffers). Has to be cast to
   (PTEXT) is used. Is defined as a size, but no string content.
   Parameters
   name :  name of the variable to create
   size :  size of the static text element. (0 content)          */
#define DECLTEXTSZ( name, size ) DECLTEXTSZTYPE( name,(size) )	 = { TF_STATIC, NULL, NULL, {{1,1}} }
/* Defines an initializer block which can be used to satisfy a
   TEXT elemnt of a structure
   Parameters
   str :  string content of the TEXT
   Example
   <code lang="c++">
   TEXT something = DEFTEXT( "abc" );
   </code>                                                     */
#define DEFTEXT(str) {TF_STATIC,NULL,NULL,{{1,1}},{(sizeof(str)/sizeof(str[0]))-1,str}}
/* A macro to declare a structure which is the same physically
   as a PTEXT, (for declaring constant static strings
   basically). Has to be cast to (PTEXT) is used.
   Parameters
   name :   name of the variable to create
   value :  static string constant to initialize variable to.  */
#define DECLTEXT(name, str) static DECLTEXTSZTYPE( name, (sizeof(str)/sizeof(str[0])) ) = DEFTEXT(str)
/* Description
   A Text segment, it is based on DataBlock that has a length
   and an addtional region at the end of the structure which
   contains the text of the segment. Segments may have
   formatting attributes. Segments may be linked to other
   segments in a NEXTLINE/PRIORLINE. Segments may have indirect
   content, which may represent phrases. Sets of segments may
   represent sentence diagrams. A Pointer to a <link text::TEXT, TEXT>
   type.
   TEXT is a type I created to provide a variety of functions.
   One particular application was a common language processor,
   and I created the TEXT structure to store elements which are
   described by language. Sentences are words, and phases. A
   phrase is a set of words, but sometimes a word is a phrase.
   (sentence) = ( word ) ... (phrase ) ...
   (phrase) = (word)...
   hmm.. how to describe this.
   <code lang="c++">
   PTEXT phrase = NULL;
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   </code>
   <code>
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   SegAppend( phrase, SegCreateFromText( "Test" ) );
   </code>
   PTEXT segments point at other segments. A list of segments is
   a sentence. Segments can have information encoded on them
   that remove text from them. For instance, \< and \> tags
   might be removed around a phrase and stored as an attribute
   of the segment. A segment with such an attribute could be an
   indirect segment that points at a list of words which are the
   phrases in the tag.
   <code lang="c++">
   a map of two segments, and their content...
       (segment with TF_TAG) -\> (segment with TF_TAG)
             |                        |
             \+ - ("html")             + - (body) -\> (background="#000000")
   would actually expand to
      \<html\>\<body background="#000000"\>
   </code>
   See Also
   SegCreate
   burst
   TextParse
   SegAppend
   SegSubst
   SegSplit
   SegGrab
   SegDelete
   LineRelease
   BuildLine
   and also.....
   PVARTEXT                                                                  */
typedef struct text_segment_tag
{
	// then here I could overlap with pEnt .bshadow, bmacro, btext ?
   uint32_t flags;
	/* This points to the next segment in the sentence or phrase. NULL
	   if at the end of the line.                                      */
		struct text_segment_tag *Next;
	/* This points to the prior segment in the sentence or phrase. (NULL
	   if at the first segment)                                          */
		struct text_segment_tag *Prior;
	/* format is 64 bits.
      it's two 32 bit bitfields (position, expression)
	 valid if TF_FORMAT is set... */
	FORMAT format;
   /* A description of the data stored here.  It is compatible with a DATABLOCk.... */
   struct {
	   /* unsigned size; size is sometimes a pointer value...
                  this means bad thing when we change platforms... Or not, since we went to uintptr_t which is big enough for a pointer. */
		uintptr_t size;
		/* the data of the test segment
		 beginning of var data - this is created size+sizeof(TEXT) */
		   TEXTCHAR  data[1];
	} data;
} TEXT, *PTEXT;
//
// PTEXT DumpText( PTEXT somestring )
//    PTExT (single data segment with full description \r in text)
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  DumpText ( PTEXT text );
//SegCreateFromText( ".." );
// Burst, SegAppend, SegGrab
// segments are ment to be lines, the meaninful tag "TF_NORETURN" means it's part of the prior line.
//--------------------------------------------------------------------------
#define HAS_WHITESPACE(pText) ( pText && ( (pText)->format.position.offset.spaces || (pText)->format.position.offset.tabs ) )
/* A convenient macro to go from one segment in a line of text
   to the next segment.                                        */
#define NEXTLINE(line)   ((PTEXT)(((PTEXT)line)?(((PTEXT)line)->Next):(NULL)))
/* A convenient macro to go from one segment in a line of text
   to the prior segment.                                       */
#define PRIORLINE(line)  ((PTEXT)(((PTEXT)line)?(((PTEXT)line)->Prior):(NULL)))
/* Link one PTEXT segment to another. Sets one half of the links
   appropriate for usage.
   Example
   This example sets the prior pointer of 'word' to 'line'.
   <code>
   PTEXT line;
   PTEXT word;
   SETPRIORLINE( word, line );
   </code>                                                       */
#define SETPRIORLINE(line,p) ((line)?(((line)->Prior) = (PTEXT)(p)):0)
/* Link one PTEXT segment to another. Sets one half of the links
   appropriate for usage.
   Example
   This example sets the next pointer of 'line' to 'word'.
   <code lang="c#">
   PTEXT line;
   PTEXT word;
   SETNEXTLINE( line, word );
   </code>                                                       */
#define SETNEXTLINE(line,p)  ((line)?(((line)->Next ) = (PTEXT)(p)):0)
/* Sets a pointer to PTEXT to the first text segment in the
   list.                                                    */
#define SetStart(line)     for(; line && PRIORLINE(line);line=PRIORLINE(line))
/* Sets a PTEXT to the last segment that it points to.
   Parameters
   line :  segment in the line to move to the end of.
   Remarks
   Updates the variable passed to point to the last segment. */
#define SetEnd(line)      for(; line && NEXTLINE(line); line=NEXTLINE(line))
// might also check to see if pseg is an indirect - setting this size would be BAD
#define SetTextSize(pseg, sz ) ((pseg)?((pseg)->data.size = (sz )):0)
/* gets the indect segment content (if any) from a PTEXT
   segment.                                              */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GetIndirect(PTEXT segment );
/* Get the format flags of a PTEXT.
                                    */
TYPELIB_PROC  uint32_t TYPELIB_CALLTYPE  GetTextFlags( PTEXT segment );
/* Gets the text segment length. */
TYPELIB_PROC  size_t TYPELIB_CALLTYPE  GetTextSize( PTEXT segment );
/* Gets the text of a PTEXT segment. (convert to a CTEXTSTR)
   Parameters
   segment :  segment to get the string content from         */
TYPELIB_PROC  TEXTSTR TYPELIB_CALLTYPE  GetText( PTEXT segment );
// by registering for TF_APPLICTION is set on the segment
// and flags anded with the segment flags match, the
// function is called.... the result is the actual
// segment of this - since a TF_APPLICATION is also
// TF_INDIRECT - using the size to point to some application
// defined structure instead of a PTEXT structure.
TYPELIB_PROC  void TYPELIB_CALLTYPE  RegisterTextExtension ( uint32_t flags, PTEXT(CPROC*)(uintptr_t,POINTER), uintptr_t );
// similar to GetIndirect - but results in the literal pointer
// instead of the text that the application may have registered to result with.
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE  GetApplicationPointer ( PTEXT text );
/* Used to set the content of a segment to some application
   defined value. This allows a users application to store
   chunks of data in lists of text. These external chunks are
   handled like other words.
   Parameters
   text :  this is the text segment to set application data on
   p :     this is a pointer to application data               */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetApplicationPointer ( PTEXT text, POINTER p);
/* Set segment's indirect data.
   Parameters
   segment :  pointer to a TEXT segment to set the indirect content
              of.
   data :     pointer to a PTEXT to be referenced indirectly.       */
#define SetIndirect(Seg,Where)  ( (Seg)->data.size = ((uintptr_t)(Where)-(uintptr_t)NULL) )
		/* these return 1 for more(l1&gt;l2) -1 for (l1&lt;l2) and 0 for match.
       */
TYPELIB_PROC  int TYPELIB_CALLTYPE  SameText ( PTEXT l1, PTEXT l2 );
/* A test if one PTEXT is similar to another PTEXT.
   Parameters
   l1 :  PTEXT segment one
   l2 :  PTEXT segment two
   Return Value List
   \<0 :  l1 with case insensitive comparison is less then l2
   0 :    Texts compare case insenitive match
   \>0 :  l1 with case insensitive comparison is more than l2 */
TYPELIB_PROC  int TYPELIB_CALLTYPE  LikeText ( PTEXT l1, PTEXT l2 );
/* Compares if text is like a C string. Case Sensitive.
   <b>Returns</b>
   TRUE if they are alike.
   FALSE if they are different.
   <b>Parameters</b>                                    */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextIs  ( PTEXT pText, CTEXTSTR text );
/* Compares if text is like a C string. Case insensitive (like).
   Returns
   TRUE if they are alike.
   FALSE if they are different.
   Parameters
   pText :  PTEXT segment to compare
   text :   C string buffer to compare against                   */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextLike  ( PTEXT pText, CTEXTSTR text );
/* Compares if text is like a C string. Case insensitive (like). Uses min string length for max match.
   Returns
   TRUE if they are similar (both case insensitive using shorter of the strings for maxlen).
   FALSE if they are different.
   Parameters
   pText :  PTEXT segment to compare
   text :   C string buffer to compare against                   */
TYPELIB_PROC  int TYPELIB_CALLTYPE  TextSimilar  ( PTEXT pText, CTEXTSTR text );
//#define SameText( l1, l2 )  ( strcmp( GetText(l1), GetText(l2) ) )
#define textmin(a,b) ( (((a)>0)&&((b)>0))?(((a)<(b))?(a):(b)):(((a)>0)?(a):((b)>0)?(b):0) )
#ifdef __LINUX__
/* windows went with stricmp() and strnicmp(), whereas linux
 went with strcasecmp() and strncasecmp()                  */
#  ifdef UNICODE
#    ifndef NO_UNICODE_C
#      define strnicmp strncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#      define stricmp strcasecmp
#    else
#      define strnicmp wcsncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#      define stricmp wcscasecmp
#    endif
#  else
#    define strnicmp strncasecmp
/* windows went with stricmp() and strnicmp(), whereas linux
   went with strcasecmp() and strncasecmp()                  */
#     define stricmp strcasecmp
#  endif
#endif
/* Copy segment formatting to another segment... */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SegCopyFormat( PTEXT to_this, PTEXT copy_this );
/* Create a text segment of sepecified size; inclues one more character for NUL terminator */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateEx( size_t nSize DBG_PASS );
/* Create a PTEXT with specified number of character capacity.
   Example
   <code lang="c#">
   PTEXT text = SegCreate( 10 );
   </code>                                                     */
#define SegCreate(s) SegCreateEx(s DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromText> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromTextEx( CTEXTSTR text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromText( WIDE("Around the world in a day.") );
   </code>                                                         */
#define SegCreateFromText(t) SegCreateFromTextEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromCharLenEx( const char *text, size_t len DBG_PASS );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromCharEx( const char *text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromChar( "Around the world in a day." );
   </code>                                                         */
#define SegCreateFromChar(t) SegCreateFromCharEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromChar> */
#define SegCreateFromCharLen(t,len) SegCreateFromCharLenEx((t),(len) DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromWideLenEx( const wchar_t *text, size_t len DBG_PASS );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromWideEx( const wchar_t *text DBG_PASS );
/* Creates a PTEXT segment from a string.
   Example
   <code lang="c++">
   PTEXT line = SegCreateFromWideLen( L"Around the world in a day.", 26 );
   </code>                                                         */
#define SegCreateFromWideLen(t,len) SegCreateFromWideLenEx((t),(len) DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromWide> */
#define SegCreateFromWide(t) SegCreateFromWideEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateIndirect> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateIndirectEx( PTEXT pText DBG_PASS );
/* Creates a text segment that refers to the parameter
   indirectly. The new segment is not really a clone, but a
   reference of the original PTEXT.
   Example
   <code lang="c#">
   PTEXT phrase = SegCreateIndirect( SegAppend( SegCreateFromText( "Hello" )
                                              , SegCreateFromText( "World" ) ) );
   </code>
   The resulting phrase is a single segment with no prior or
   next, but its content is "HelloWorld" if it was passed to
   buildline... it's go the content of the two text segments
   linked together, but not in its buffer. It is actually a 0
   length buffer for a TEXT segment.
                                                                                  */
#define SegCreateIndirect(t) SegCreateIndirectEx(t DBG_SRC)
/* \ \
   See Also
   <link DBG_PASS>
   <link SegDuplicate> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegDuplicateEx( PTEXT pText DBG_PASS);
/* This duplicates a specific segment. It duplicates the first
   segment of a string. If the segment has indirect data, then
   the first segment of the indirect data is duplicated.       */
#define SegDuplicate(pt) SegDuplicateEx( pt DBG_SRC )
/* Duplicates a linked list of segments.
   Duplicates the structure of a line. The resulting line is an
   exact duplicate of the input line. All segments linked in
   exactly the same sorts of ways.
   Parameters
   line :  list of segments to duplicate                        */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  LineDuplicateEx( PTEXT pText DBG_PASS );
/* <combine sack::containers::text::LineDuplicateEx@PTEXT pText>
   \ \                                                           */
#define LineDuplicate(pt) LineDuplicateEx(pt DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link TextDuplicate> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  TextDuplicateEx( PTEXT pText, int bSingle DBG_PASS );
/* Duplicate the whole string of text to another string with
   exactly the same content.                                 */
#define TextDuplicate(pt,s) TextDuplicateEx(pt,s DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromInt> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromIntEx( int value DBG_PASS );
/* Creates a text segment from a 64 bit integer.
   Example
   <code>
   PTEXT number = SegCreateFromInt( 3314 );
   </code>                                       */
#define SegCreateFromInt(v) SegCreateFromIntEx( v DBG_SRC )
/* Converts an integer to a PTEXT segment.
   Parameters
   _64bit_value :  integer value to convert to a PTEXT segment. */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFrom_64Ex( int64_t value DBG_PASS );
/* Create a text segment from a uint64_t bit value. (long long int) */
#define SegCreateFrom_64(v) SegCreateFrom_64Ex( v DBG_SRC )
/* \ \
   See Also
   <link DBG_PASS>
   <link SegCreateFromFloat> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegCreateFromFloatEx( float value DBG_PASS );
/* Creates a text segment from a floating point value. Probably
   uses something like '%g' to format output. Fairly limited.
   Example
   <code lang="c++">
   PTEXT short_PI = SegCreateFromFloat( 3.14 );
   </code>                                                      */
#define SegCreateFromFloat(v) SegCreateFromFloatEx( v DBG_SRC )
/* Appends a list of segments to an existing list of segments. This
   assumes that the additional segment is referncing the head of
   the segment list.
   Parameters
   source :  source list to add to
   other :   additional segments to add to source.                  */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegAppend   ( PTEXT source, PTEXT other );
/* Inserts a segment before another segment.
   Parameters
   what :    what to insert into the list
   before :  insert the segments before this segment
   Returns
   The parameter 'what'.                             */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegInsert   ( PTEXT what, PTEXT before );
/* This expands a segment by a number of characters.
   Parameters
   PTEXT :  the segment to expand
   int :    count of character to expand by
   Returns
   A pointer to a new segment that is bigger, but has the same
   existing content.                                           */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegExpandEx (PTEXT source, INDEX nSize DBG_PASS );
/* <combine sack::containers::text::SegExpandEx@PTEXT@INDEX nSize>
   \ \                                                             */
#define SegExpand(s,n) SegExpandEx( s,n DBG_SRC )
/* Release a linked list of PTEXT segments.
   Parameters
   segments :  a segment in a list of segments to delete, first
               this routine goes to the start of the segment
               list, and then deletes all segments in the list.
   DBG_PASS :  debug file and line information                  */
TYPELIB_PROC  void TYPELIB_CALLTYPE   LineReleaseEx (PTEXT line DBG_PASS );
/* Release a line of text.
   A line may be a single segment.
   This is the proper way to dispose of PTEXT segments.
   Any segment in the line may be passed, the first segment is
   found, and then all segments in the line are deleted.       */
#define LineRelease(l) LineReleaseEx(l DBG_SRC )
/* \ \
   <b>See Also</b>
   <link DBG_PASS>
   <link SegRelease> */
TYPELIB_PROC  void TYPELIB_CALLTYPE  SegReleaseEx( PTEXT seg DBG_PASS );
/* Release a single segment. UNSAFE. Does not respect that it is
   in a list.
   See Also
   <link LineRelease>                                            */
#define SegRelease(l) SegReleaseEx(l DBG_SRC )
/* Adds a part of input to the segment list of output.
   Parameters
   output\ :   the segment list to append to.
   input\ :    the input buffer to append from
   offset :    starting offset in 'input' to start from
   length :    how much from 'offset' in input to append as a new
               segment to output.
   DBG_PASS :  \file and line debugging information               */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegConcatEx   (PTEXT output,PTEXT input,int32_t offset,size_t length DBG_PASS);
/* <combine sack::containers::text::SegConcatEx@PTEXT@PTEXT@int32_t@size_t length>
   looks like it takes a peice of one segment and appends it to
   another....
   Needs More research to document correctly and exemplify.                     */
#define SegConcat(out,in,ofs,len) SegConcatEx(out,in,ofs,len DBG_SRC)
/* Removes a segment from a list of segments. Links what was
   prior and what was after together. Sets both next and prior
   of the segment unlinked to NULL.
   Example
   <code lang="c++">
   SegUnlink( segment );
   </code>
   Returns
   The segment passed.                                         */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegUnlink   (PTEXT segment);
/* Breaks a list of PTEXT segments at the specified segment and
   \returns a segment that was before the specified.
   Parameters
   segment :  segment to break the chain at
   Returns
   Any existing segment before the segment to break at.
   Example
   <code lang="c++">
   {
      PTEXT segs;
      PTEXT breakat;
      PTEXT leftover;
		&#47;* ... segs gets populated with some segments ... *&#47;
      breakat = NEXTLINE( segs );
   </code>
   <code>
      breakat = NEXTLINE( segs );
      leftover = segbreak( breakat );
      // now breakat begins a new chain of segments
      // leftover is the segment that was just before breakat
      SegStart( leftover );  // leftover would be equal to segs...
   }
   </code>                                                         */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegBreak    (PTEXT segment);
/* Removes a segment from a list. It also releases the segment.
    Example
    <code lang="c#">
    SegDelete( segment );
    </code>
    the result is NULL;                                          */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegDelete   (PTEXT segment);
/* removes segment from any list it might be in, returns
   segment.                                              */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegGrab     (PTEXT segment);
/* Substitute one PTEXT segment for another in a list of PTEXT
   segments.
   Parameters
   _this :  This is the segment to remove
   that :   This is the segment to subustitute with. This may be
            a list of segments, and it is linked in from the
            first segment to the prior to '_this' and the last to
            the next after '_this'
   Returns
   \Returns the '_this' that was substituted.                     */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegSubst    ( PTEXT _this, PTEXT that );
/* \ \
   See Also
   <link DBG_PASS>
   <link SegSplit> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  SegSplitEx( PTEXT *pLine, INDEX nPos DBG_PASS);
/* Split a PTEXT segment.
   Example
   \ \
   <code lang="c++">
   PTEXT result = SegSplit( &amp;old_string, 5 );
   </code>
   Returns
   PTEXT new_string;
   Remarks
   the old string segment is split at the position indicated. The
   pointer to the old segment is modified to point to now two
   segments linked dynamically, each part of the segment after
   the split. If the index is beyond the bounds of the segment,
   the segment remains unmodified.                                */
#define SegSplit(line,pos) SegSplitEx( line, pos DBG_SRC )
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  FlattenLine ( PTEXT pLine );
/* Create a highest precision signed integer from a PTEXT. */
TYPELIB_PROC  int64_t TYPELIB_CALLTYPE  IntCreateFromSeg( PTEXT pText );
/* Converts a text to the longest precision signed integer
   value.                                                  */
TYPELIB_PROC  int64_t TYPELIB_CALLTYPE  IntCreateFromText( CTEXTSTR p );
/* Create a high precision floating point value from PTEXT
   segment.                                                */
TYPELIB_PROC  double TYPELIB_CALLTYPE  FloatCreateFromSeg( PTEXT pText );
/* Create a high precision floating point value from text
   string.                                                */
TYPELIB_PROC  double TYPELIB_CALLTYPE  FloatCreateFromText( CTEXTSTR p, CTEXTSTR *pp );
//
// IsSegAnyNumber returns 0 if no, 1 if is int, 2 if is float
//   if pfNumber or piNumber are available then the text pointer
//   will be updated to the next segment after what was used to resolve
//   the number.
//   bUseAllSegs is for testing pTexts which are indirect, such that
//      only all segments within the indirect segment will result valid.
//   pfNumber and piNumber may be passed as NULL, and the function can still
// be used to determine ifnumber
//   the number resulting in the values pointed to will be filled in
//    with (*pfNumber)=FltCreateFromSeg(p) (or Int as appropriate)
//
//#define IsNumber(p) IsSegAnyNumberEx( &(p), NULL, NULL, NULL, 0 )
#define IsIntNumber(p, pint) IsSegAnyNumberEx( &(p), NULL, pint, NULL, 0 )
/* Tests a PTEXT segment to see if it might be a floating point
   number.                                                      */
#define IsFltNumber(p, pflt) IsSegAnyNumberEx( &(p), pflt, NULL, NULL, 0 )
/* Tests the content of a PTEXT to see if it might be a number.
   Parameters
   ppText :       pointer to PTEXT to check
   pfNumber :     pointer to double to get result of number it's
                  a float
   piNumber :     pointer to a signed 64 bit value to get the
                  \result if it's not a float.
   pbIsInt :      point to a integer \- receives boolean result
                  if the segment was an integer is TRUE else it's
                  a double.
   bUseAllSegs :  if TRUE, use all the segments starting with the
                  first, and update the pointer to the next
                  stgment. If false, use only the first segment. if
                  uses all segments, it must also use ALL
                  segments to get the number.
   Returns
   0 if not a number or fails.
   1 if a valid conversion took place.                              */
TYPELIB_PROC  int TYPELIB_CALLTYPE  IsSegAnyNumberEx ( PTEXT *ppText, double *pfNumber, int64_t *piNumber, int *pbIsInt, int bUseAllSegs );
/* <combine sack::containers::text::IsSegAnyNumberEx@PTEXT *@double *@int64_t *@int *@int>
   \ \                                                                                  */
#define IsSegAnyNumber(pptext, pfNum, piNum, pbIsInt) IsSegAnyNumberEx( pptext, pfNum, piNum, pbIsInt, 0 )
/* \Returns the amount of space required to store this segment,
   and all indirect statements it contains.
   Parameters
   segment :   segment to measure
   position :  starting position in the segment to measure from
   nTabSize :  how big tabs are supposed to be
   tabs :      list of tab positions (for arbitrary tab
               positioning\- table column alignment?)           */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentSpaceEx ( PTEXT segment, INDEX position, int nTabs, INDEX *tabs);
/* \Returns the amount of space required to store this segment,
   and all indirect statements it contains.
   Parameters
   segment :   segment to measure
   position :  starting position in the segment to measure
               from
   nTabSize :  how big tabs are supposed to be                  */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentSpace ( PTEXT segment, INDEX position, int nTabSize );
/* Simlar to getsegment space... */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentLengthEx ( PTEXT segment, INDEX position, int nTabs, INDEX *tabs );
/* \Returns the length of a single PTEXT segment.
   Parameters
   segment :   segment to measure
   position :  string position in the string to measure
   nTabSize :  how many characters a tab is supposed to be. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  GetSegmentLength ( PTEXT segment, INDEX position, int nTabSize );
/* Measure the length of a list of segments (combined length of
   all linked segments)                                         */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  LineLengthExEx( PTEXT pt, LOGICAL bSingle, int nTabsize, PTEXT pEOL );
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  LineLengthExx( PTEXT pt, LOGICAL bSingle,PTEXT pEOL );
/* <combine sack::containers::text::LineLengthExEx@PTEXT@LOGICAL@int@PTEXT>
   \ \                                                                      */
#define LineLengthExx(pt,single,eol) LineLengthExEx( pt,single,8,eol)
/* \ \
   Parameters
   Text segment :  PTEXT line or segment to get the length of
   single :        boolean, if set then only a single segment is
                   measured, otherwise all segments from this to
                   the end are measured.                         */
#define LineLengthEx(pt,single) LineLengthExx( pt,single,NULL)
/* Computes the length of characters in a line, if all segments
   in the line are flattened into a single word.                */
#define LineLength(pt) LineLengthEx( pt, FALSE )
/* Collapses an indirect segment or a while list of segments
   into a single segment with content expanded. When passed to
   things like TextParse and Burst, segments have their
   positioning encoded to counters for tabs and spaces; the
   segment itself contains only text without whitespace. Buildline
   expands these segments into their plain text representation.
   Parameters
   pt :        pointer to a PTEXT segment.
   bSingle :   if TRUE, build only the first segment. If the
               segment is indirect, builds entire content of
               indirect.
   nTabsize :  how wide tabs are. When written into a line, tabs
               are written as spaces. (maybe if 0, tabs are
               emitted directly?)
   pEOL :      the segment to use to represent an end of line. Often
               this is a SegCreate(0) segment.                       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  BuildLineExEx( PTEXT pt, LOGICAL bSingle, int nTabsize, PTEXT pEOL DBG_PASS );
/* Collapses an indirect segment or a while list of segments
into a single segment with content expanded. When passed to
things like TextParse and Burst, segments have their
positioning encoded to counters for tabs and spaces; the
segment itself contains only text without whitespace. Buildline
expands these segments into their plain text representation.
Parameters
pt :        pointer to a PTEXT segment.
bSingle :   if TRUE, build only the first segment. If the
segment is indirect, builds entire content of
indirect.
pEOL :      the segment to use to represent an end of line. Often
this is a SegCreate(0) segment.                       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  BuildLineExx( PTEXT pt, LOGICAL bSingle, PTEXT pEOL DBG_PASS );
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
\ \                                                                          */
#define BuildLineExx(from,single,eol) BuildLineExEx( from,single,8,NULL DBG_SRC )
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
   \ \                                                                          */
#define BuildLineEx(from,single) BuildLineExEx( from,single,8,NULL DBG_SRC )
/* <combine sack::containers::text::BuildLineExEx@PTEXT@LOGICAL@int@PTEXT pEOL>
   \ \
    Flattens all segments in a line to a single segment result.
*/
#define BuildLine(from) BuildLineExEx( from, FALSE,8,NULL DBG_SRC )
//
// text parse - more generic flavor of burst.
//
//static CTEXTSTR normal_punctuation=WIDE("\'\"\\({[<>]}):@%/,;!?=*&$^~#`");
// filter_to_space WIDE(" \t")
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  TextParse ( PTEXT input, CTEXTSTR punctuation, CTEXTSTR filter_tospace, int bTabs, int bSpaces  DBG_PASS );
/* normal_punctuation=WIDE("'"\\({[\<\>]}):@%/,;!?=*&amp;$^~#`");
   Process a line of PTEXT into another line of PTEXT, but with
   words parsed as appropriate for common language.
   Parameters
   input\ :  pointer to a list of PTEXT segments to parse.
   Remarks
   Burst is a simple method of breaking a sentence into its word
   and phrase parts. It collapses space and tabs before words
   into the word. Any space representation is space preceeding
   the word. Sentences are also broken on any punctuation.
   "({[\<\>]})'";;.,/?\\!@#$%^&amp;*=" for instances. + and - are
   treated specially if they prefix numbers, otherwise they are
   also punctuation. Also groups of '.' like '...' are kept
   together. if the '.' is in a number, it is stored as part of
   the number. Otherwise a '.' used in an abbreviation like P.S.
   will be a '.' with 0 spaces followed by a segment also with 0
   spaces. (unless it's the lsat one)
   so initials are encoded badly.
   Bugs
   There is an exploit in the parser such that . followed by a
   number will cause fail to break into seperate words. This is
   used by configuration scripts to write binary blocks, and
   read them back in, having the block parsed into a segment
   correctly.
   See Also
   <link sack::containers::text::TextParse@PTEXT@CTEXTSTR@CTEXTSTR@int@int bSpaces, TextParse> */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  burstEx( PTEXT input DBG_PASS);
/* <combine sack::containers::text::burstEx@PTEXT input>
   \ \                                                   */
#define burst( input ) burstEx( (input) DBG_SRC )
/* Compares a couple lists of text segments.
   Parameters
   pt1 :      pointer to a phrase
   single1 :  use only the first word, not the whole phrase
   pt2 :      pointer to a phrase
   single2 :  use only the first segment, not the whole phrase
   bExact :   if FALSE, match case insensitive, otherwise match
              exact case.                                       */
TYPELIB_PROC  int TYPELIB_CALLTYPE  CompareStrings( PTEXT pt1, int single1
                            , PTEXT pt2, int single2
                            , int bExact );
/* This removes indirect segments, replacing them with their
   indirect content.
   Parameters
   pLine :  pointer to a PTEXT segment list to flatten.      */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  FlattenLine ( PTEXT pLine );
/* Steps through a linked list of segments, just a convenient
   for loop wrapper.                                          */
#define FORALLTEXT(start,var)  for(var=start;var; var=NEXTLINE(var))
/* returns number of characters filled into output.  Output needs to be at maximum 6 chars */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF8( char *output, TEXTRUNE rune );
/* returns number of characters filled into output.  Output needs to be at maximum 6 chars;  if overlong is set
   characters are deliberatly padded to be overlong */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF8Ex( char *output, TEXTRUNE rune, LOGICAL overlong );
/* returns number of wchar filled into output.  Output needs to be at maximum 2 wchar. */
TYPELIB_PROC int TYPELIB_CALLTYPE ConvertToUTF16( wchar_t *output, TEXTRUNE rune );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfChar( const char **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharIndexed( const char *from, size_t *index, size_t length );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfChar( const char *start, const char **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharIndexed( const char *from, size_t *index );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharW( const wchar_t **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetUtfCharIndexedW( const wchar_t *from, size_t *index );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharW( const wchar_t *start, const wchar_t **from );
TYPELIB_PROC TEXTRUNE TYPELIB_CALLTYPE GetPriorUtfCharIndexedW( const wchar_t *from, size_t *index );
TYPELIB_PROC size_t TYPELIB_CALLTYPE GetDisplayableCharacterCount( const char *string, size_t max_bytes );
TYPELIB_PROC CTEXTSTR TYPELIB_CALLTYPE GetDisplayableCharactersAtCount( const char *string, size_t character_index );
TYPELIB_PROC size_t TYPELIB_CALLTYPE  GetDisplayableCharacterBytes( const char *string, size_t character_count );
/* You Must Deallocate the result */
TYPELIB_PROC  char * TYPELIB_CALLTYPE  WcharConvertExx ( const wchar_t *wch, size_t len DBG_PASS );
/* You Must Deallocate the result */
TYPELIB_PROC  char * TYPELIB_CALLTYPE  WcharConvertEx ( const wchar_t *wch DBG_PASS );
/* <combine sack::containers::text::WcharConvertExx@wchar_t *@size_t len>
   \ \                                                                    */
#define WcharConvertLen(s,len) WcharConvertExx(s, len DBG_SRC )
/* <combine sack::containers::text::WcharConvertExx@wchar_t *@size_t len>
   \ \                                                                    */
#define WcharConvert(s) WcharConvertEx(s DBG_SRC )
/* You Must Deallocate the result */
TYPELIB_PROC wchar_t * TYPELIB_CALLTYPE CharWConvertExx ( const char *wch, size_t len DBG_PASS );
/* Convert wchar_t strings to char strings.
   Parameters
   string :    wchar_t string to convert
   DBG_PASS :  debug file and line information
   Returns
   A char * string. This string must be Release()'ed or
   Deallocate()'ed by the user.                         */
TYPELIB_PROC wchar_t * TYPELIB_CALLTYPE CharWConvertEx ( const char *wch DBG_PASS );
/* <combine sack::containers::text::CharWConvertExx@char *@size_t len>
   \ \                                                                 */
#define CharWConvertLen(s,len) CharWConvertExx(s,len DBG_SRC )
/* <combine sack::containers::text::CharWConvertExx@char *@size_t len>
   \ \                                                                 */
#define CharWConvert(s) CharWConvertEx(s DBG_SRC )
//--------------------------------------------------------------------------
/* This is a string collector type.  It has an interface to be able to vtprintf( vartext, "format string", ... ); which appends the specified string to the collected text.
  Example
   PVARTEXT pvt = VarTextCreate();
   vtprintf( pvt, "hello world!" );
   {
      PTEXT text = VarTextGet( pvt );
	  printf( "Text is : %s(%d)", GetText( text ), GetTextSize( text ) );
	  LineRelease( text );
   }
   VarTextDestroy( &pvt );
   */
typedef struct vartext_tag *PVARTEXT;
/* Creates a variable text collector. Allows specification of
   initial size and amount to expand by. SQL Command line sample
   utility uses this and allocates like 10,000 initial and sets
   expand as 40,000, because it expects to build very large
   strings, and expansion of 32 at a time is ludicrous; if the
   space required is more than the expansion factor, then it is
   expanded by the amount required plus the expansion factor.
   Parameters
   initial :   amount of initial buffer
   exand_by :  how much to expand the buffer by when more room
               is needed
   DBG_PASS :  debug file and line parameters.                   */
TYPELIB_PROC  PVARTEXT TYPELIB_CALLTYPE  VarTextCreateExEx ( uint32_t initial, uint32_t expand DBG_PASS );
/* <combine sack::containers::text::VarTextCreateExEx@uint32_t@uint32_t expand>
   \ \                                                                */
#define VarTextCreateExx(i,e) VarTextCreateExEx(i,e DBG_SRC )
/* <combine sack::containers::text::VarTextCreateExEx@uint32_t@uint32_t expand>
   Creates a variable text collector. Default initial size and
   expansion is 0 and 32.
                                                                      */
TYPELIB_PROC  PVARTEXT TYPELIB_CALLTYPE  VarTextCreateEx ( DBG_VOIDPASS );
/* The simplest, most general way to create a PVARTEXT
   collector. The most extended vartext creator allows
   specification of how long the initial buffer is, and how much
   the buffer expands by when required. This was added to
   optimize building HUGE SQL queries, working withing 100k
   buffers that expanded by 50k at a time was a lot less
   operations than expanding 32 bytes or something at a time.    */
#define VarTextCreate() VarTextCreateEx( DBG_VOIDSRC )
/* Empties and destroys all resources associated with the
   variable text collector.
   Parameters
   pvt * :     address of a PVARTEXT reference to destroy. Sets
               the pointer to NULL when it's destroyed.
   DBG_PASS :  debugging file and line parameters
   Example
   <code lang="c++">
   {
      PVARTEXT pvt = VarTextCreate();
      VarTextDestroy( &amp;pvt );
   }
   void Function( int something DBG_PASS )
   {
      pvt = VarTextCreateEx( DBG_RELAY );
      VarTextDestroyEx( &amp;pvt DBG_RELAY );
   }
   </code>
   C++ Syntax
   \ \                                                          */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextDestroyEx ( PVARTEXT* DBG_PASS );
/* Destroy a VarText collector. */
#define VarTextDestroy(pvt) VarTextDestroyEx( pvt DBG_SRC )
/* \Internal function - used to initialize a VARTEXT structure. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextInitEx( PVARTEXT pvt DBG_PASS);
/* Probably should not be exported. Initializes a VARTEXT
   structure to prepare it for subsequent VarText operations. */
#define VarTextInit(pvt) VarTextInitEx( (pvt) DBG_SRC )
/* Empties a PVARTEXT structure.
   Parameters
   pvt :  PVARTEXT to empty.     */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextEmptyEx( PVARTEXT pvt DBG_PASS);
/* <combine sack::containers::text::VarTextEmptyEx@PVARTEXT pvt>
   \ \                                                           */
#define VarTextEmpty(pvt) VarTextEmptyEx( (pvt) DBG_SRC )
/* Add a single character to a vartext collector.
   Note
   \ \
   Parameters
   pvt :       PVARTEXT to add character to
   c :         character to add
   DBG_PASS :  optional debug information         */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddCharacterEx( PVARTEXT pvt, TEXTCHAR c DBG_PASS );
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddRuneEx( PVARTEXT pvt, TEXTRUNE c, LOGICAL overlong DBG_PASS );
/* Adds a single character to a PVARTEXT collector.
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddCharacter( pvt, 'a' );
   </code>                                          */
#define VarTextAddCharacter(pvt,c) VarTextAddCharacterEx( (pvt),(c) DBG_SRC )
/* Adds a single rune to a PVARTEXT collector. (may be multiple characters convert to UTF8)
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddRune( pvt, 'a' );
   </code>                                          */
#define VarTextAddRune(pvt,c) VarTextAddRuneEx( (pvt),(c), FALSE DBG_SRC )
/* Adds a length of data to the vartext. This allows strings
   with nuls included to be added.
   Parameters
   pvt :       PVARTEXT to add data to
   block :     pointer to data to add
   size :      length of data block to add
	DBG_PASS :  optional file and line parameters             */
#define VARTEXT_ADD_DATA_NULTERM ((size_t)0xFF000000)
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextAddDataEx( PVARTEXT pvt, CTEXTSTR block, size_t length DBG_PASS );
/* Adds a single character to a PVARTEXT collector.
   Example
   <code lang="c++">
   PVARTEXT pvt = VarTextCreate();
   VarTextAddData( pvt, "test one", 8 );
   </code>                                          */
#define VarTextAddData(pvt,block,length) VarTextAddDataEx( (pvt),(block),(length) DBG_SRC )
/* Commits the currently collected text to segment, and adds the
   segment to the internal line accumulator.
		 returns true if any data was added...
       move any collected text to commit... */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  VarTextEndEx( PVARTEXT pvt DBG_PASS );
/* <combine sack::containers::text::VarTextEndEx@PVARTEXT pvt>
   \ \                                                         */
#define VarTextEnd(pvt) VarTextEndEx( (pvt) DBG_SRC )
/* Gets the length of the current collection in the VARTEXT.
   Parameters
   pvt :  PVARTEXT collector to get the length.              */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  VarTextLength( PVARTEXT pvt );
/* Gets the text segment built in the VarText. The PVARTEXT is
   set to empty. Clears the collector.
   Parameters
   pvt :  PVARTEXT to get text from.                           */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  VarTextGetEx( PVARTEXT pvt DBG_PASS );
/* <combine sack::containers::text::VarTextGetEx@PVARTEXT pvt>
   \ \                                                         */
#define VarTextGet(pvt) VarTextGetEx( (pvt) DBG_SRC )
/* Used to look at the vartext collector and get the current
   collection. Does not clear the collector.
   Parameters
   pvt :       PVARTEXT collector to peek at
   DBG_PASS :  debugging file and line parameters
   Return Value List
   NULL :      No data
   not NULL :  text segment which is in the collector.       */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  VarTextPeekEx ( PVARTEXT pvt DBG_PASS );
/* \Returns the PTEXT that is currently in a PVARTEXT. It does
   not alter the contents of the PVARTEXT. Do not LineRelease
   this peeked value.                                          */
#define VarTextPeek(pvt) VarTextPeekEx( (pvt) DBG_SRC )
/* Increases the internal storage size of the variable text
   collector.
   Parameters
   pvt :       the var text collector to expand
   amount :    amount of size to expand the collector
   DBG_PASS :  debugging file and line parameters           */
TYPELIB_PROC  void TYPELIB_CALLTYPE  VarTextExpandEx( PVARTEXT pvt, INDEX size DBG_PASS );
/* Add a specified number of characters to the amount of space
   in the VARTEXT collector.                                   */
#define VarTextExpand(pvt, sz) VarTextExpandEx( (pvt), (sz) DBG_SRC )
//TYPELIB_PROC  int vtprintfEx( PVARTEXT pvt DBG_PASS TYPELIB_CALLTYPE  CTEXTSTR format, ... ;
// note - don't include format - MUST have at least one parameter passed to ...
//#define vtprintf(pvt, ...) vtprintfEx( (pvt) DBG_SRC, __VA_ARGS__ )
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  vtprintfEx( PVARTEXT pvt, CTEXTSTR format, ... );
/* <combine sack::containers::text::vtprintfEx@PVARTEXT@CTEXTSTR@...>
   Note                                                               */
#define vtprintf vtprintfEx
/* variable argument VARTEXT printf. Is passed a PVARTEXT to
   collect the formatted output using printf sort of formatting. */
TYPELIB_PROC  INDEX TYPELIB_CALLTYPE  vvtprintf( PVARTEXT pvt, CTEXTSTR format, va_list args );
/* encode binary buffer into base64 encoding.
   outsize is updated with the length of the buffer.
 */
TYPELIB_PROC  TEXTCHAR * TYPELIB_CALLTYPE  EncodeBase64Ex( uint8_t* buf, size_t length, size_t *outsize, const char *encoding );
/* decode base64 buffer into binary buffer
   outsize is updated with the length of the buffer.
   result should be Release()'d
 */
TYPELIB_PROC  uint8_t * TYPELIB_CALLTYPE  DecodeBase64Ex( char* buf, size_t length, size_t *outsize, const char *encoding );
/* xor a base64 encoded string over a utf8 string, keeping the utf8 characters in the same length...
   although technically this can result in invalid character encoding where upper bits get zeroed
   result should be Release()'d
*/
TYPELIB_PROC  char * TYPELIB_CALLTYPE  u8xor( const char *a, size_t alen, const char *b, size_t blen, int *ofs );
/* xor two base64 encoded strings, resulting in a base64 string
   result should be Release()'d
*/
TYPELIB_PROC  char * TYPELIB_CALLTYPE  b64xor( const char *a, const char *b );
//--------------------------------------------------------------------------
// extended command entry stuff... handles editing buffers with insert/overwrite/copy/paste/etc...
typedef struct user_input_buffer_tag {
	// -------------------- custom cmd buffer extension
  // position counter for pulling history
	INDEX nHistory;
  // a link queue which contains the prior lines of text entered for commands.
	PLINKQUEUE InputHistory;
 // set to TRUE when nHistory has wrapped...
	int   bRecallBegin;
   /* A exchange-lock variable for controlling access to the
      \history (so things aren't being read from it while it is
      scrolling old data out).                                  */
	uint32_t   CollectionBufferLock;
  // used to store index.. for insert type operations...
	INDEX CollectionIndex;
 // flag for whether we are inserting or overwriting
	int   CollectionInsert;
 // flag for whether we are inserting or overwriting
	int   storeCR;
 // used to store partial from GatherLine
	PTEXT CollectionBuffer;
 // called when a buffer is complete.
	void (CPROC*CollectedEvent)( uintptr_t psv, PTEXT text );
  // passed to the event callback when a line is completed
	uintptr_t psvCollectedEvent;
} USER_INPUT_BUFFER, *PUSER_INPUT_BUFFER;
/* Creates a buffer structure which behaves like the command
   line command recall queue.
                                                             */
TYPELIB_PROC  PUSER_INPUT_BUFFER TYPELIB_CALLTYPE  CreateUserInputBuffer ( void );
/* Destroy a created user input buffer. */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DestroyUserInputBuffer ( PUSER_INPUT_BUFFER *pci );
// negative with SEEK_SET is SEEK_END -nPos
enum CommandPositionOps {
	// defined that the x,y position in the segment should be used for absolute positioning.
   // can also be SEEK_SET
 COMMAND_POS_SET = 0,
 // defined that the x,y position in the segment should be used for relative positioning.
 // can also be SEEK_CUR
 COMMAND_POS_CUR = 1
};
/* Updates the current input position, for things like input,
   etc. Some external process indicates where in the line to set
   the cursor position.                                          */
TYPELIB_PROC  LOGICAL TYPELIB_CALLTYPE  SetUserInputPosition ( PUSER_INPUT_BUFFER pci, int nPos, int whence );
// bInsert < 0 toggle insert.  bInsert == 0 clear isnert(set overwrite) else
// set insert (clear overwrite )
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetUserInputInsert ( PUSER_INPUT_BUFFER pci, int bInsert );
TYPELIB_PROC  void TYPELIB_CALLTYPE  SetUserInputSaveCR( PUSER_INPUT_BUFFER pci, int bSaveCR );
/* Get the next command in the queue in the speicifed direction
   Parameters
   pci :  pointer to command input buffer
   bUp :  if TRUE \- get older command; else get the newer
          command.                                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RecallUserInput ( PUSER_INPUT_BUFFER pci, int bUp );
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GetUserInputLine( PUSER_INPUT_BUFFER pOutput );
/* Add a buffer to the history buffer.
                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  EnqueUserInputHistory ( PUSER_INPUT_BUFFER pci, PTEXT pHistory );
/* Arbitrary PTEXT blocks are fed to the user input queue with
   this.
   Parameters
   pci :     pointer to command buffer
   stroke :  the stroke to add to the buffer (may be a whole
             String or linked list of segments). or NULL if
             getting existing input...
   Return Value List
   NULL :      There is no command available \- no text followed
               by a newline.
   not NULL :  A command line collected from the input text. There
               may be multiple commands in a single 'stroke'
               buffer.
   Example
   This may be used something like .... to add the storke to the
   \input buffer, and while there is a result, get the result
   from the buffer.
   <code lang="c++">
   {
       PUSER_INPUT_BUFFER pci = CreateUserInputBuffer();
       PTEXT result;
       for( result = GatherUserInput( pci, new_stroke ); result; result = GatherUserInput( pci, NULL ) )
       {
       }
   }
   </code>                                                                                               */
TYPELIB_PROC  PTEXT TYPELIB_CALLTYPE  GatherUserInput ( PUSER_INPUT_BUFFER pci, PTEXT stroke );
/* delete 1 character at current user input index */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DeleteUserInput( PUSER_INPUT_BUFFER pci );
/* Converts ascii character set to ebcidc. */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE  ConvertAsciiEbdic( TEXTSTR text, INDEX length );
/* Routine to convert from ebcdic character set to ascii. */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE  ConvertEbcdicAscii( TEXTSTR text, INDEX length );
/* Converts ascii 85 to ascii */
TYPELIB_PROC TEXTSTR FtnATA( TEXTSTR buf );
/* Converts ascii character set to ascii 85  */
TYPELIB_PROC TEXTSTR ATFtnA( TEXTSTR buf );
/* Expand characters which are outside of standard ascii to URI
   compatible escapes.
   Parameters
   text :        Text to convert
   length :      max length of text to convert
   skip_slash :  if TRUE, keep slash characters as literal,
                 otherwise they get converted.                  */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE ConvertTextURI( CTEXTSTR text, INDEX length, int skip_slash );
/* Converts URI escape characters like %3B to the appropriate
   ascii characters. The resulting string must be released by
   the application.
   Parameters
   text :    TEXTCHAR * string to convert.
   length :  max length of text to convert.
   Example
   <code lang="c++">
   TEXTCHAR *sample = WIDE( "https://www.google.com/#hl=en&amp;sugexp=eqn&amp;cp=11&amp;gs_id=1a&amp;xhr=t&amp;q=%3B+%5C+%2B+:+";
   TEXTCHAR *result;
   \result = ConvertURIText( sample, StrLen( sample ) );
   \result == https://www.google.com/#hl=en&amp;sugexp=eqn&amp;cp=11&amp;gs_id=1a&amp;xhr=t&amp;q=;+\\+++:+
   </code>                                                                                                                        */
TYPELIB_PROC TEXTSTR TYPELIB_CALLTYPE ConvertURIText( CTEXTSTR text, INDEX length );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE ParseStringVector( CTEXTSTR data, CTEXTSTR **pData, int *nData );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE ParseIntVector( CTEXTSTR data, int **pData, int *nData );
#ifdef __cplusplus
 //namespace text {
};
#endif
//--------------------------------------------------------------------------
#ifdef __cplusplus
	namespace BinaryTree {
#endif
/* This type defines a specific node in the tree. It is entirely
   private, and is a useless definition.                         */
typedef struct treenode_tag *PTREENODE;
/* Defines a Binary Tree.
   See Also
   <link CreateBinaryTree> */
typedef struct treeroot_tag *PTREEROOT;
/* This option may be passed to extended CreateBinaryTree
   methods to disallow adding of duplicates. Otherwise
   duplicates will be added; they will be added to the side of
   the node with the same value that has less children. Trees
   are created by default without this option, allowing the
   addition of duplicates.
   Example
   <code lang="c++">
   PTREEROOT = <link CreateBinaryTreeExtended>( BT_OPT_NODUPLICATES, NULL, NULL DBG_SRC );
   </code>                                                                                 */
#define BT_OPT_NODUPLICATES 1
/* Generic Compare is the type declaration for the callback routine for user custom comparisons.
  This routine should return -1 if new is less than old, it should return 1 if new is more than old, and it
  should return 0 if new and old are the same key. */
typedef int (CPROC *GenericCompare)( uintptr_t oldnode,uintptr_t newnode );
/* Signature for the user callback passed to CreateBinaryTreeEx
   that will be called for each node removed from the binary
   list.                                                        */
typedef void (CPROC *GenericDestroy)( CPOINTER user, uintptr_t key);
/* when adding a node if Compare is NULL the default method of a
   basic unsigned integer compare on the key value is done. if
   Compare is specified the specified key value of the orginal
   node (old) and of the new node (new) is added. Result of
   compare should be ( \<0 (lesser)) ( 0 (equal)) ( \>0
   (greater))
   Example
   <code lang="c++">
   int CPROC MyGenericCompare( uintptr_t oldnode,uintptr_t newnode )
   {
   </code>
   <code>
      if(oldnode\>newnode)
          return 1;
      else if(oldnode\<newnode)
          return -1;
      else return 0;
   </code>
   <code lang="c++">
      return (oldnode\>newnode)? 1
             \:(oldnode\<newnode)? -1
             \:0;
   }
   void CPROC MyGenericDestroy(POINTER user, uintptr_t key)
   {
      // do something custom with your user data and or key value
   }
   PTREEROOT tree = CreateBinaryTreeExtended( 0 // BT_OPT_NODUPLICATES
                                            , MyGenericCompare
                                            , MyGenericDestroy
                                            <link DBG_PASS, DBG_SRC> );
   </code>
   See Also
   <link CreateBinaryTreeExx>
   <link CreateBinaryTreeEx>
   <link CreateBinaryTree>                                               */
TYPELIB_PROC  PTREEROOT TYPELIB_CALLTYPE  CreateBinaryTreeExtended( uint32_t flags
															, GenericCompare Compare
															, GenericDestroy Destroy DBG_PASS);
/* This is the simpler case of <link CreateBinaryTreeExtended>,
   which does not make you pass DBG_SRC.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTreeExx( BT_OPT_NODUPLICATES, NULL, NULL );
   </code>                                                                  */
#define CreateBinaryTreeExx(flags,compare,destroy) CreateBinaryTreeExtended(flags,compare,destroy DBG_SRC)
/* Creates a binary tree, allowing specification of comparison
   and destruction routines.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTreeEx( <link CreateBinaryTreeExtended, MyGenericCompare>, <link CreateBinaryTreeExtended, MyGenericDestroy> );
   </code>                                                                                                                                      */
#define CreateBinaryTreeEx(compare,destroy) CreateBinaryTreeExx( 0, compare, destroy )
/* This is the simplest way to create a binary tree.
   The default compare routine treats 'key' as an integer value
   that is compared against other for lesser/greater condition.
   This tree also allows duplicates to be added.
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   </code>                                                      */
#define CreateBinaryTree() CreateBinaryTreeEx( NULL, NULL )
/* \ \
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   DestroyBinaryTree( tree );
   tree = NULL;
   </code>                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DestroyBinaryTree( PTREEROOT root );
/* Drops all the nodes in a tree so it becomes empty...
   \ \
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   ResetBinaryTree( tree );
   tree = NULL;
   </code>                              */
TYPELIB_PROC  void TYPELIB_CALLTYPE  ResetBinaryTree( PTREEROOT root );
/* Balances a binary tree. If data is added to a binary list in
   a linear way (from least to most), the tree can become
   unbalanced, and all be on the left or right side of data. This
   routine can analyze branches and perform rotations so that
   the tree can be discretely rebalanced.
   Example
   <code lang="c++">
   <link PTREEROOT> tree;
   // <link AddBinaryNode>...
   BalanceBinaryTree( tree );
   </code>                                                        */
TYPELIB_PROC  void TYPELIB_CALLTYPE  BalanceBinaryTree( PTREEROOT root );
/* \ \
   See Also
   <link AddBinaryNode>
   <link DBG_PASS>
                        */
TYPELIB_PROC  int TYPELIB_CALLTYPE  AddBinaryNodeEx( PTREEROOT root
                                                   , CPOINTER userdata
                                                   , uintptr_t key DBG_PASS );
/* Adds a user pointer identified by key to a binary list.
   See Also
   <link BinaryTree::CreateBinaryTree, CreateBinaryTree>
   Example
   <code lang="c++">
   PTREEROOT tree = CreateBinaryTree();
   uintptr_t key = 1;
   POINTER data = NewArray( TEXTCHAR, 32 );
   AddBinaryNode( tree, data, key );
   </code>
   Parameters
   root :  PTREEROOT binary tree instance.
   data :  POINTER to some user object.
   key :   uintptr_t a integer type which can be used to identify
           the data. (used to compare in the tree).<p /><p />If
           the user has specified a custom comparison routine in
           an extended CreateBinaryTree(), then this value might
           be a pointer to some other data. Often the thing used
           to key into a binary tree is a <link CTEXTSTR>.
   Returns
   The tree may be created with <link BT_OPT_NODUPLICATES>, in
   which case this will result FALSE if the key is found
   duplicated in the list. Otherwise this returns TRUE. if the
   root parameter is NULL, the result is FALSE.                  */
#define AddBinaryNode(r,u,k) AddBinaryNodeEx((r),(u),(k) DBG_SRC )
//TYPELIB_PROC  int TYPELIB_CALLTYPE  AddBinaryNode( PTREEROOT root
//                                    , POINTER userdata
//                                    , uintptr_t key );
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveBinaryNode( PTREEROOT root, POINTER use, uintptr_t key );
/* Search in a binary tree for the specified key.
   Returns
   user data POINTER if found, else NULL.
   Example
   <code lang="c++">
   PTREEROOT tree;
   void f( void )
   {
      CPOINTER mydata = FindInBinaryTree( tree, 5 );
      if( mydata )
      {
          // found '5' as the key in the tree
      }
   }
   </code>                                          */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  FindInBinaryTree( PTREEROOT root, uintptr_t key );
// result of fuzzy routine is 0 = match.  100 = inexact match
// 1 = no match, actual may be larger
// -1 = no match, actual may be lesser
// 100 = inexact match- checks nodes near for better match.
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  LocateInBinaryTree( PTREEROOT root, uintptr_t key
														, int (CPROC*fuzzy)( uintptr_t psv, uintptr_t node_key ) );
/* During FindInBinaryTree and LocateInBinaryTree, the last
   found result is stored. This function allows deletion of that
   node.
   Example
   <code lang="c++">
   FindInBinaryTree( tree, 5 );
   RemoveLastFoundNode( tree );
   </code>                                                       */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveLastFoundNode(PTREEROOT root );
/* Removes the currently browsed node from the tree.
   See Also
   <link GetChildNode>                               */
TYPELIB_PROC  void TYPELIB_CALLTYPE  RemoveCurrentNode(PTREEROOT root );
/* Basically this is meant to dump to a log, if the print
   function is passed as NULL, then the tree's contents are
   dumped to the log. It dumps a very cryptic log of how all
   nodes in the tree are arranged. But by allowing the user to
   provide a method to log his data and key, the logging is more
   meaningful based on the application. The basic code for
   managing trees and nodes works....
   Example
   <code>
   int ForEachNode( POINTER user, uintptr_t key )
   {
       // return not 1 to dump to log the internal tree structure
       return 0; // probably did own logging here, so don't log tree internal
   }
   <link PTREEROOT> tree;
   void f( void )
   {
       DumpTree( tree, ForEachNode );
   }
   </code>                                                                    */
TYPELIB_PROC  void TYPELIB_CALLTYPE  DumpTree( PTREEROOT root
                          , int (*Dump)( CPOINTER user, uintptr_t key ) );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLeastNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLeastNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreatestNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreatestNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLesserNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetLesserNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreaterNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetGreaterNode( PTREEROOT root );
/* \Returns the node that is set as 'current' in the tree. There
   is a cursor within the tree that can be used for browsing.
   See Also
   <link GetChildNode>                                           */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetCurrentNodeEx( PTREEROOT root, POINTER *cursor );
/* \Returns the node that is set as 'current' in the tree. There
   is a cursor within the tree that can be used for browsing.
   See Also
   <link GetChildNode>                                           */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetCurrentNode( PTREEROOT root );
/* This sets the current node cursor to the root of the node.
   See Also
   <link GetChildNode>                                        */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetRootNode( PTREEROOT root );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetParentNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetParentNode( PTREEROOT root );
/* While browsing the tree after a find operation move to the
   next child node, direction 0 is lesser direction !0 is
   greater.
   Binary Trees have a 'current' cursor. These operations may be
   used to browse the tree.
   Example
   \ \
   <code>
   // this assumes you have a tree, and it's fairly populated, then this demonstrates
   // all steps of browsing.
   POINTER my_data;
   // go to the 'leftmost' least node. (as determined by the compare callback)
   my_data = GetLeastNode( tree );
   // go to the 'rightmost' greatest node. (as determined by the compare callback)
   my_data = GetGreatestNode( tree );
   // move to the node that is less than the current node.  (move to the 'left')
   my_data = GetLesserNode( tree );
   // move to the node that is greater than the current node.  (move to the 'right')
   my_data = GetGreaterNode( tree );
   // follow the tree to the left down from here
   my_data = GetChildNode( tree, 0 );
   // follow the tree to the right down from here
   my_data = GetChildNode( tree, 1 );
   // follow the tree up to the node above the current one.
   //  (the one who's lesser or greater points at this)
   my_data = GetParentNode( tree );
   // this is probably the least useful, but someone clever might find a trick for it
   // Move back to the node we were just at.
   //  (makes the current the prior, and moves to what the prior was,
   //     but then it's just back and forth between the last two; it's not a stack ).
   my_data = GetPriorNode( tree );
   </code>
   A more practical example...
   <code lang="c++">
   POINTER my_data;
   for( my_data = GetLeastNode( tree );
        my_data;
        my_data = GetGreaterNode( tree ) )
   {
        // browse the tree from least to most.
   }
   </code>                                                                            */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetChildNode( PTREEROOT root, int direction );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetChildNodeEx( PTREEROOT root, POINTER *cursor, int direction );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetPriorNodeEx( PTREEROOT root, POINTER *cursor );
/* See Also
   <link GetChildNode> */
TYPELIB_PROC  CPOINTER TYPELIB_CALLTYPE  GetPriorNode( PTREEROOT root );
/* \Returns the total number of nodes in the tree.
   Example
   <code lang="c++">
   uint32_t total_nodes = GetNodeCount(tree);
   </code>                                         */
TYPELIB_PROC  uint32_t TYPELIB_CALLTYPE  GetNodeCount ( PTREEROOT root );
 // returns a shadow of the original.
TYPELIB_PROC  PTREEROOT TYPELIB_CALLTYPE  ShadowBinaryTree( PTREEROOT root );
#ifdef __cplusplus
 //namespace BinaryTree {
	};
#endif
//--------------------------------------------------------------------------
#ifdef __cplusplus
namespace family {
#endif
/* A family tree structure, for tracking elements that have
   multiple children.
                                                            */
typedef struct familyroot_tag *PFAMILYTREE;
typedef struct familynode_tag *PFAMILYNODE;
/* <unfinished>
   Incomplete Work in progress (maybe) */
TYPELIB_PROC  PFAMILYTREE TYPELIB_CALLTYPE  CreateFamilyTree ( int (CPROC *Compare)(uintptr_t key1, uintptr_t key2)
															, void (CPROC *Destroy)(POINTER user, uintptr_t key) );
/* <unfinished>
   Incomplete, Family tree was never completed. */
TYPELIB_PROC  POINTER TYPELIB_CALLTYPE  FamilyTreeFindChild ( PFAMILYTREE root
														  , uintptr_t psvKey );
/* <unfinished>
   Incomplete, Family tree was never completed. */
TYPELIB_PROC  POINTER  TYPELIB_CALLTYPE FamilyTreeFindChildEx ( PFAMILYTREE root, PFAMILYNODE root_node
													 , uintptr_t psvKey );
/* Resets the search cursors in the tree... */
TYPELIB_PROC  void TYPELIB_CALLTYPE  FamilyTreeReset ( PFAMILYTREE *option_tree );
/* Resets the content of the tree (should call destroy methods, at this time it does not) */
TYPELIB_PROC  void TYPELIB_CALLTYPE  FamilyTreeClear ( PFAMILYTREE option_tree );
/* <unfinished>
   Incomplete Work in progress (maybe) */
TYPELIB_PROC  PFAMILYNODE TYPELIB_CALLTYPE  FamilyTreeAddChild ( PFAMILYTREE *root, PFAMILYNODE parent, POINTER userdata, uintptr_t key );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE FamilyTreeForEachChild( PFAMILYTREE root, PFAMILYNODE node
			, LOGICAL (CPROC *ProcessNode)( uintptr_t psvForeach, uintptr_t psvNodeData )
			, uintptr_t psvUserData );
TYPELIB_PROC LOGICAL TYPELIB_CALLTYPE FamilyTreeForEach( PFAMILYTREE root, PFAMILYNODE node
			, LOGICAL (CPROC *ProcessNode)( uintptr_t psvForeach, uintptr_t psvNodeData, int level )
			, uintptr_t psvUserData );
#ifdef __cplusplus
 //namespace family {
};
#endif
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#ifdef __cplusplus
//} // extern "c"
 // namespace containers
};
 // namespace sack
};
using namespace sack::containers::link_stack;
using namespace sack::containers::data_stack;
using namespace sack::containers::data_list;
using namespace sack::containers::data_queue;
using namespace sack::containers::queue;
using namespace sack::containers::BinaryTree;
using namespace sack::containers::text;
using namespace sack::containers::message;
using namespace sack::containers::sets;
using namespace sack::containers::family;
using namespace sack::containers;
#else
// should 'class'ify these things....
#endif
#ifndef _TYPELIBRARY_SOURCE
//#undef TYPELIB_PROC // we don't need this symbol after having built the right prototypes
#endif
#endif
// $Log: sack_typelib.h,v $
// Revision 1.99  2005/07/10 23:56:25  d3x0r
// Fix types for C++...
//
//
// Revision 1.39  2003/03/25 08:38:11  panther
// Add logging
//
SACK_NAMESPACE
#ifndef IS_DEADSTART
// this is always statically linked with libraries, so they may contact their
// core executable to know when it's done loading everyone else also...
#  ifdef __cplusplus
extern "C"
#  endif
#  if defined( WIN32 ) && !defined( __STATIC__ ) && !defined( __ANDROID__ )
#    ifdef __NO_WIN32API__
// DllImportAttribute ?
#    else
__declspec(dllimport)
#    endif
#  else
#ifndef __cplusplus
extern
#endif
#  endif
/* a function true/false which indicates whether the root
   deadstart has been invoked already. If not, one should call
   InvokeDeadstart and MarkDeadstartComplete.
   <code lang="c++">
   int main( )
   {
       if( !is_deadstart_complete() )
       {
           InvokeDeadstart();
           MarkDeadstartComplete()
       }
       ... your code here ....
       return 0;  // or some other appropriate return.
   }
   </code>
   sack::app::deadstart                                        */
LOGICAL
#  if defined( __WATCOMC__ )
__cdecl
#  endif
is_deadstart_complete( void );
#endif
/* Define a routine to call for exit().  This triggers specific code to handle shutdown event registration */
#ifndef NO_EXPORTS
#  ifdef SACK_BAG_CORE_EXPORTS
EXPORT_METHOD
#  else
IMPORT_METHOD
#  endif
#else
#  ifndef SACK_BAG_CORE_EXPORTS
	extern
#  endif
#endif
		void CPROC BAG_Exit( int code );
#ifndef NO_SACK_EXIT_OVERRIDE
#define exit(n) BAG_Exit(n)
#endif
 // namespace sack {
SACK_NAMESPACE_END
// this should become common to all libraries and programs...
 // pronounced 'kahn-struct'
/* Defines interface for Construct API.
   Description
   This API is for distributed process tracking. A launching
   program will receive notifications to cause certain events to
   happen. Applications built for use by this execution tracking
   program will register that they are loading while they are
   loading, and before the application Main() is invoked. the
   application should then call LoadComplete() once they have
   initialized and are ready to process. This allows a
   quick-wait to wait for the process to register that it is
   loading, and a longer wait for process completion. Certain
   processes may not require others to be completely loaded, but
   maybe just loading. (Two peer processes that have to
   coordinate together to have either one complete
   initialization).                                              */
/* Define the procedure call type for construct API methods. */
#define CONSTRUCT_API CPROC
#ifdef CONSTRUCT_SOURCE
#define CONSTRUCT_PROC EXPORT_METHOD
#else
/* Library linkage specification. */
#define CONSTRUCT_PROC IMPORT_METHOD
#endif
#ifdef __cplusplus
/* Defines TASK namespace (unused?) */
#define _TASK_NAMESPACE namespace task {
/* Define Construct namespace. Construct is for distributed
   process tracking project. Applications will register on-load
   that they are loading, and should register load completed
   when they are done loading, or exit.                         */
#define _CONSTRUCT_NAMESPACE namespace construct {
/* Defines TASK namespace ending.(unused?) */
#define _TASK_NAMESPACE_END }
/* Define Construct namespace end. Construct is for distributed
   process tracking project. Applications will register on-load
   that they are loading, and should register load completed
   when they are done loading, or exit.                         */
#define _CONSTRUCT_NAMESPACE_END }
#else
#define _TASK_NAMESPACE
#define _CONSTRUCT_NAMESPACE
#define _TASK_NAMESPACE_END
#define _CONSTRUCT_NAMESPACE_END
#endif
/* Define a symbol to specify full sack::task::construct
   namespace.                                            */
#define CONSTRUCT_NAMESPACE SACK_NAMESPACE _TASK_NAMESPACE _CONSTRUCT_NAMESPACE
/* Define a symbol to specify full sack::task::construct
   namespace ending.                                     */
#define CONSTRUCT_NAMESPACE_END _CONSTRUCT_NAMESPACE_END _TASK_NAMESPACE_END SACK_NAMESPACE_END
	SACK_NAMESPACE
	_TASK_NAMESPACE
	/* Registers with message service, assuming the summoner message service is active.
	 Provides communication methods with a task manager, so the application can notify,
	 start has completed.   The service is ready to work.*/
_CONSTRUCT_NAMESPACE
/* Called to indicate that a process is done initializing and is
   ready to process. Notifies summoner service of Loading
   completed. If enabled, there is also a library component that
   will run at deadstart to just confirm initializing, this
   would actually indicate the service is now ready to serve.    */
CONSTRUCT_PROC void CONSTRUCT_API LoadComplete( void );
CONSTRUCT_NAMESPACE_END
#ifdef __cplusplus
	using namespace sack::task::construct;
#endif
/*
 *  Crafted by James Buckeyne
 *  Part of SACK github.com/d3x0r/SACK
 *
 *   (c) Freedom Collective 2000-2006++, 2016++
 *
 *   created to provide standard logging features
 *   lprintf( format, ... ); simple, basic
 *   if DEBUG, then logs to a file of the same name as the program
 *   if RELEASE most of this logging goes away at compile time.
 *
 *  standardized to never use int.
 */
#ifndef LOGGING_MACROS_DEFINED
#define LOGGING_MACROS_DEFINED
#define SYSLOG_API CPROC
#ifdef SYSLOG_SOURCE
#define SYSLOG_PROC EXPORT_METHOD
#else
#define SYSLOG_PROC IMPORT_METHOD
#endif
#ifdef __cplusplus
#define LOGGING_NAMESPACE namespace sack { namespace logging {
#define LOGGING_NAMESPACE_END }; };
#else
#define LOGGING_NAMESPACE
#define LOGGING_NAMESPACE_END
#endif
#ifdef __cplusplus
	namespace sack {
/* Handles log output. Logs can be directed to UDP directed, or
   broadcast, or localhost, or to a file location, and under
   windows the debugging console log.
   lprintf
   SetSystemLog
   SystemLogTime
   there are options, when options code is enabled, which
   control logging output and format. Log file location can be
   specified generically for instance.... see Options.
	This namespace contains the logging functions. The most basic
   thing you can do to start logging is use 'lprintf'.
   <code lang="c++">
   lprintf( "My printf like format %s %d times", "string", 15 );
   </code>
   This function takes a format string and arguments compatible
   with vsnprintf. Internally strings are truncated to 4k
   length. (that is no single logging message can be more than
   4k in length).
   There are functions to control logging behavior.
   See Also
   SetSystemLog
   SystemLogTime
   SystemLogOptions
   lprintf
   _lprintf
   xlprintf
   _xlprintf
                                                                 */
		namespace logging {
#endif
/* \Parameters for SetSystemLog() to specify where the logging
   should go.                                                  */
enum syslog_types {
 // disable any log output.
SYSLOG_NONE     =   -1
,
SYSLOG_UDP      =    0
,
SYSLOG_FILE     =    1
,
 /* Set logging to output to a file. The file passed is a FILE*. This
   may be a FILE* like stdout, stderr, or some file the
   application opens.                                                */
SYSLOG_FILENAME =    2
,
 /* Set logging to go to a file, pass the string text name of the
   \file to open as the second parameter of SetSystemLog.        */
SYSLOG_SYSTEM   =    3
,
 /* Specify that logging should go to system (this actually means
   Windows system debugging channel. OutputDebugString() ).      */
SYSLOG_UDPBROADCAST= 4
// Allow user to specify a void UserCallback( char * )
// which recieves the formatted output.
,
SYSLOG_CALLBACK    = 5
,
 /* Send Logging to a specified user callback to handle. This
   lets logging go anywhere else that's not already thought of. */
SYSLOG_AUTO_FILE = SYSLOG_FILE + 100
 /* Send logging to a file. If the file is not open, open the
   \file. If no logging happens, no log file is created.     */
,
SYSLOG_SOCKET_SYSLOGD
};
#if !defined( NO_LOGGING )
#define DO_LOGGING
#endif
// this was forced, force no_logging off...
#if defined( DO_LOGGING )
#undef NO_LOGGING
#endif
#ifdef __LINUX__
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
SYSLOG_PROC  LOGICAL SYSLOG_API  IsBadReadPtr ( CPOINTER pointer, uintptr_t len );
#endif
SYSLOG_PROC  CTEXTSTR SYSLOG_API  GetPackedTime ( void );
//
typedef void (CPROC*UserLoggingCallback)( CTEXTSTR log_string );
SYSLOG_PROC  void SYSLOG_API  SetSystemLog ( enum syslog_types type, const void *data );
SYSLOG_PROC  void SYSLOG_API  ProtectLoggedFilenames ( LOGICAL bEnable );
SYSLOG_PROC  void SYSLOG_API  SystemLogFL ( CTEXTSTR FILELINE_PASS );
SYSLOG_PROC  void SYSLOG_API  SystemLogEx ( CTEXTSTR DBG_PASS );
SYSLOG_PROC  void SYSLOG_API  SystemLog ( CTEXTSTR );
SYSLOG_PROC  void SYSLOG_API  LogBinaryFL ( const uint8_t* buffer, size_t size FILELINE_PASS );
SYSLOG_PROC  void SYSLOG_API  LogBinaryEx ( const uint8_t* buffer, size_t size DBG_PASS );
SYSLOG_PROC  void SYSLOG_API  LogBinary ( const uint8_t* buffer, size_t size );
// logging level defaults to 1000 which is log everything
SYSLOG_PROC  void SYSLOG_API  SetSystemLoggingLevel ( uint32_t nLevel );
#if defined( _DEBUG ) || defined( _DEBUG_INFO )
/* Log a binary buffer. Logs lines representing 16 bytes of data
   at a time. The hex of each byte in a buffer followed by the
   text is logged.
   Example
   <code lang="c#">
   char sample[] = "sample string";
   LogBinary( sample, sizeof( sample ) );
   </code>
   Results with the following output in the log...
   <code>
    73 61 6D 70 6C 65 20 73 74 72 69 6E 67 00 sample string.
   </code>
   The '.' at the end of 'sample string' is a non printable
   character. characters 0-31 and 127+ are printed as '.'.       */
#define LogBinary(buf,sz) LogBinaryFL((uint8_t*)(buf),sz DBG_SRC )
#define SystemLog(buf)    SystemLogFL(buf DBG_SRC )
#else
// need to include the typecast... binary logging doesn't really care what sort of pointer it gets.
#define LogBinary(buf,sz) LogBinary((uint8_t*)(buf),sz )
//#define LogBinaryEx(buf,sz,...) LogBinaryFL(buf,sz FILELINE_NULL)
//#define SystemLogEx(buf,...) SystemLogFL(buf FILELINE_NULL )
#endif
// int result is useless... but allows this to be
// within expressions, which with this method should be easy.
typedef INDEX (CPROC*RealVLogFunction)(CTEXTSTR format, va_list args )
//#if defined( __GNUC__ ) && !defined( _UNICODE )
//	__attribute__ ((__format__ (__vprintf__, 1, 2)))
//#endif
	;
typedef INDEX (CPROC*RealLogFunction)(CTEXTSTR format,...)
#if defined( __GNUC__ ) && !defined( _UNICODE )
	__attribute__ ((__format__ (__printf__, 1, 2)))
#endif
	;
SYSLOG_PROC  RealVLogFunction SYSLOG_API  _vxlprintf ( uint32_t level DBG_PASS );
SYSLOG_PROC  RealLogFunction SYSLOG_API  _xlprintf ( uint32_t level DBG_PASS );
// utility function to format a cpu delta into a buffer...
// end-start is always printed... therefore tick_end-0 is
// print absolute time... formats as millisecond.NNN
SYSLOG_PROC  void SYSLOG_API  PrintCPUDelta ( TEXTCHAR *buffer, size_t buflen, uint64_t tick_start, uint64_t tick_end );
// return the current CPU tick
SYSLOG_PROC  uint64_t SYSLOG_API  GetCPUTick ( void );
// result in nano seconds - thousanths of a millisecond...
SYSLOG_PROC  uint32_t SYSLOG_API  ConvertTickToMicrosecond ( uint64_t tick );
SYSLOG_PROC  uint64_t SYSLOG_API  GetCPUFrequency ( void );
SYSLOG_PROC  CTEXTSTR SYSLOG_API  GetTimeEx ( int bUseDay );
SYSLOG_PROC  void SYSLOG_API  SetSyslogOptions ( FLAGSETTYPE *options );
/* When setting options using SetSyslogOptions() these are the
   defines for the bits passed.
   SYSLOG_OPT_OPENAPPEND - the file, when opened, will be opened
   for append.
   SYSLOG_OPT_OPEN_BACKUP - the file, if it exists, will be
   renamed automatically.
   SYSLOG_OPT_LOG_PROGRAM_NAME - enable logging the program
   executable (probably the same for all messages, unless they
   are network)
   SYSLOG_OPT_LOG_THREAD_ID - enables logging the unique process
   and thread ID.
   SYSLOG_OPT_LOG_SOURCE_FILE - enable logging source file
   information. See <link DBG_PASS>
   SYSLOG_OPT_MAX - used for declaring a flagset to pass to
   setoptions.                                                   */
enum system_logging_option_list {
		/* the file, when opened, will be opened for append.
		 */
		SYSLOG_OPT_OPENAPPEND
										  ,
  /* the file, if it exists, will be renamed automatically.
										  */
										  SYSLOG_OPT_OPEN_BACKUP
                                ,
 /* enable logging the program executable (probably the same for
                                   all messages, unless they are network)
                                                                                                */
                                 SYSLOG_OPT_LOG_PROGRAM_NAME
										  ,
 /* enables logging the unique process and thread ID.
										                                                       */
                                 SYSLOG_OPT_LOG_THREAD_ID
                                ,
 /* enable logging source file information. See <link DBG_PASS>
                                                                                               */
										   SYSLOG_OPT_LOG_SOURCE_FILE
										  ,
										  SYSLOG_OPT_MAX
};
// this solution was developed to provide the same
// functionality for compilers that refuse to implement __VA_ARGS__
// this therefore means that the leader of the function is replace
// and that extra parenthesis exist after this... therefore the remaining
// expression must be ignored... thereofre when defining a NULL function
// this will result in other warnings, about ignored, or meaningless expressions
# if defined( DO_LOGGING )
#  define vlprintf      _vxlprintf(LOG_NOISE DBG_SRC)
#  define lprintf       _xlprintf(LOG_NOISE DBG_SRC)
#  define _lprintf(file_line,...)       _xlprintf(LOG_NOISE file_line,##__VA_ARGS__)
#  define xlprintf(level)       _xlprintf(level DBG_SRC)
#  define vxlprintf(level)       _vxlprintf(level DBG_SRC)
# else
#  ifdef _MSC_VER
#   define vlprintf      (1)?(0):
#   define lprintf       (1)?(0):
#   define _lprintf(DBG_VOIDRELAY)       (1)?(0):
#   define xlprintf(level)       (1)?(0):
#   define vxlprintf(level)      (1)?(0):
#  else
#   define vlprintf(f,...)
/* use printf formating to output to the log. (log printf).
   Parameters
   Format :  Just like printf, the format string to print.
   ... :     extra arguments passed as required for the format.
   Example
   <code lang="c++">
      lprintf( "Test Logging %d %d", 13, __LINE__ );
   </code>                                                      */
#   define lprintf(f,...)
#   define  _lprintf(DBG_VOIDRELAY)       lprintf
#   define xlprintf(level) lprintf
#   define vxlprintf(level) lprintf
#  endif
# endif
#undef LOG_WARNING
#undef LOG_ADVISORIES
#undef LOG_INFO
// Defined Logging Levels
enum {
	  // and you are free to use any numerical value,
	  // this is a rough guideline for wide range
	  // to provide a good scaling for levels of logging
 // unless logging is disabled, this will be logged
	LOG_ALWAYS = 1
 // logging level set to 50 or more will cause this to log
	, LOG_ERRORS = 50
	,
 /* Specify a logging level which only ERROR level logging is
	   logged.                                                   */
 // logging level set to 50 or more will cause this to log
	 LOG_ERROR = LOG_ERRORS
	,
 // .......
	 LOG_WARNINGS = 500
	,
 // .......
	 LOG_WARNING = LOG_WARNINGS
   ,
 /* Use to specify that the log message is a warning level
      message.                                               */
    LOG_ADVISORY = 625
   ,
    LOG_ADVISORIES = LOG_ADVISORY
	,
 /* A symbol to specify to log Adviseries, Warnings and Error
	   level messages only.                                      */
	 LOG_INFO = 750
	  ,
 /* A moderate logging level, which is near maximum verbosity of
	     logging.                                                     */
	   LOG_NOISE = 1000
     ,
 /* Define that the message is just noisy - though verbosly
	  informative, it's level is less critical than even INFO.
	  default iS LOG_NOISE which is 1000, an ddefault for disabling most messages
	  is to set log level to 999.  Have to increase to 2000 to see debug, and this name
     has beviously
	  */
      LOG_LEVEL_DEBUG = 2000
	,
 /* Specify the message is of DEBUG importance, which is far
	   above even NOISY. If debug logging is enabled, all logging,
	   ERROR, WARNING, ADVISORY, INFO, NOISY and DEBUG will be
	   logged.                                                     */
 // not quite a negative number, but really big
	 LOG_CUSTOM = 0x40000000
	,
 /* A bit with LOG_CUSTOM might be enabled, and the lower bits
	   under 0x40000000 (all bits 0x3FFFFFFF ) can be used to
	   indicate a logging type. Then SetLoggingLevel can be passed a
	   mask of bits to filter types of messages.                     */
 // not quite a negative number, but really big
	 LOG_CUSTOM_DISABLE = 0x20000000
	// bits may be user specified or'ed with this value
	// such that ...
	// Example 1:SetSystemLoggingLevel( LOG_CUSTOM | 1 ) will
	// enable custom logging messages which have the '1' bit on... a logical
	// and is used to test the low bits of this value.
	// example 2:SetSystemLogging( LOG_CUSTOM_DISABLE | 1 ) will disable logging
	// of messages with the 1 bit set.
  // mask of bits which may be used to enable and disable custom logging
#define LOG_CUSTOM_BITS 0xFFFFFF
};
 // this is a flag set consisting of 0 or more or'ed symbols
enum SyslogTimeSpecifications {
 // disable time logging
 SYSLOG_TIME_DISABLE = 0,
 // enable is anything not zero.
 SYSLOG_TIME_ENABLE  = 1,
 // specify to log milliseconds
 SYSLOG_TIME_HIGH    = 2,
 // log the year/month/day also
 SYSLOG_TIME_LOG_DAY = 4,
 // log the difference in time instead of the absolute time
 SYSLOG_TIME_DELTA   = 8,
 // logs cpu ticks... implied delta
 SYSLOG_TIME_CPU     =16
};
/* Specify how time is logged. */
SYSLOG_PROC void SYSLOG_API SystemLogTime( uint32_t enable );
#ifndef NO_LOGGING
#define OutputLogString(s) SystemLog(s)
/* Depricated. Logs a format string that takes 0 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log(s)                                   SystemLog( s )
#else
#define OutputLogString(s)
/* Depricated. Logs a format string that takes 0 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log(s)
#endif
/* Depricated. Logs a format string that takes 1 parameter.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log1(s,p1)                               lprintf( s, p1 )
/* Depricated. Logs a format string that takes 2 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log2(s,p1,p2)                            lprintf( s, p1, p2 )
/* Depricated. Logs a format string that takes 3 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log3(s,p1,p2,p3)                         lprintf( s, p1, p2, p3 )
/* Depricated. Logs a format string that takes 4 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log4(s,p1,p2,p3,p4)                      lprintf( s, p1, p2, p3,p4)
/* Depricated. Logs a format string that takes 5 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log5(s,p1,p2,p3,p4,p5)                   lprintf( s, p1, p2, p3,p4,p5)
/* Depricated. Logs a format string that takes 6 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log6(s,p1,p2,p3,p4,p5,p6)                lprintf( s, p1, p2, p3,p4,p5,p6)
/* Depricated. Logs a format string that takes 7 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log7(s,p1,p2,p3,p4,p5,p6,p7)             lprintf( s, p1, p2, p3,p4,p5,p6,p7 )
/* Depricated. Logs a format string that takes 8 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log8(s,p1,p2,p3,p4,p5,p6,p7,p8)          lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8 )
/* Depricated. Logs a format string that takes 9 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log9(s,p1,p2,p3,p4,p5,p6,p7,p8,p9)       lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8,p9 )
/* Depricated. Logs a format string that takes 10 parameters.
   See Also
   <link sack::logging::lprintf, lprintf>                    */
#define Log10(s,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)  lprintf( s, p1, p2, p3,p4,p5,p6,p7,p8,p9,p10 )
LOGGING_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::logging;
#endif
#endif
#if defined( _MSC_VER ) || (1)
// huh, apparently all compiles are messed the hell up.
#  define COMPILER_THROWS_SIGNED_UNSIGNED_MISMATCH
#endif
#ifdef COMPILER_THROWS_SIGNED_UNSIGNED_MISMATCH
#  define SUS_GT(a,at,b,bt)   (((a)<0)?0:(((bt)a)>(b)))
#  define USS_GT(a,at,b,bt)   (((b)<0)?1:((a)>((at)b)))
#  define SUS_LT(a,at,b,bt)   (((a)<0)?1:(((bt)a)<(b)))
#  define USS_LT(a,at,b,bt)   (((b)<0)?0:((a)<((at)b)))
#  define SUS_GTE(a,at,b,bt)  (((a)<0)?0:(((bt)a)>=(b)))
#  define USS_GTE(a,at,b,bt)  (((b)<0)?1:((a)>=((at)b)))
#  define SUS_LTE(a,at,b,bt)  (((a)<0)?1:(((bt)a)<=(b)))
#  define USS_LTE(a,at,b,bt)  (((b)<0)?0:((a)<=((at)b)))
#else
#  define SUS_GT(a,at,b,bt)   ((a)>(b))
#  define USS_GT(a,at,b,bt)   ((a)>(b))
#  define SUS_LT(a,at,b,bt)   ((a)<(b))
#  define USS_LT(a,at,b,bt)   ((a)<(b))
#  define SUS_GTE(a,at,b,bt)  ((a)>=(b))
#  define USS_GTE(a,at,b,bt)  ((a)>=(b))
#  define SUS_LTE(a,at,b,bt)  ((a)<=(b))
#  define USS_LTE(a,at,b,bt)  ((a)<=(b))
#endif
#ifdef __cplusplus
using namespace sack;
using namespace sack::containers;
#endif
#endif
// incldue this first so we avoid a conflict.
// hopefully this comes from sack system?
/*
 *  Created by Jim Buckeyne
 *
 *  Purpose
 *    Generalization of system routines which began in
 *   dekware development.
 *   - Process control (load,start,stop)
 *   - Library runtime link control (load, unload)
 *
 */
#ifndef SYSTEM_LIBRARY_DEFINED
#define SYSTEM_LIBRARY_DEFINED
#ifdef SYSTEM_SOURCE
#define SYSTEM_PROC(type,name) EXPORT_METHOD type CPROC name
#else
#define SYSTEM_PROC(type,name) IMPORT_METHOD type CPROC name
#endif
#ifdef __LINUX__
// Hmm I thought that dlopen resulted in an int...
// but this doc says void * (redhat9)
//typedef void *HLIBRARY;
#else
//typedef HMODULE HLIBRARY;
#endif
#ifdef __cplusplus
#define _SYSTEM_NAMESPACE namespace system {
#define _SYSTEM_NAMESPACE_END }
#else
#define _SYSTEM_NAMESPACE
#define _SYSTEM_NAMESPACE_END
#endif
#define SACK_SYSTEM_NAMESPACE SACK_NAMESPACE _SYSTEM_NAMESPACE
#define SACK_SYSTEM_NAMESPACE_END _SYSTEM_NAMESPACE_END SACK_NAMESPACE_END
#ifndef UNDER_CE
#define HAVE_ENVIRONMENT
#endif
SACK_NAMESPACE
	_SYSTEM_NAMESPACE
typedef struct task_info_tag *PTASK_INFO;
typedef void (CPROC*TaskEnd)(uintptr_t, PTASK_INFO task_ended);
typedef void (CPROC*TaskOutput)(uintptr_t, PTASK_INFO task, CTEXTSTR buffer, size_t size );
// Run a program completely detached from the current process
// it runs independantly.  Program does not suspend until it completes.
// Use GetTaskExitCode() to get the return code of the process
#define LPP_OPTION_DO_NOT_HIDE           1
// for services to launch normal processes (never got it to work; used to work in XP/NT?)
#define LPP_OPTION_IMPERSONATE_EXPLORER  2
#define LPP_OPTION_FIRST_ARG_IS_ARG      4
#define LPP_OPTION_NEW_GROUP             8
#define LPP_OPTION_NEW_CONSOLE          16
#define LPP_OPTION_SUSPEND              32
SYSTEM_PROC( PTASK_INFO, LaunchPeerProgramExx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args
                                               , int flags
                                               , TaskOutput OutputHandler
                                               , TaskEnd EndNotice
                                               , uintptr_t psv
                                                DBG_PASS
                                               );
SYSTEM_PROC( PTASK_INFO, LaunchProgramEx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args, TaskEnd EndNotice, uintptr_t psv );
// launch a process, program name (including leading path), a optional path to start in (defaults to
// current process' current working directory.  And a array of character pointers to args
// args should be the NULL.
SYSTEM_PROC( PTASK_INFO, LaunchProgram )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR  args );
// abort task, no kill signal, sigabort basically.  Use StopProgram for a more graceful terminate.
// if (!StopProgram(task)) TerminateProgram(task) would be appropriate.
SYSTEM_PROC( uintptr_t, TerminateProgram )( PTASK_INFO task );
SYSTEM_PROC( void, ResumeProgram )( PTASK_INFO task );
// get first address of program startup code(?) Maybe first byte of program code?
SYSTEM_PROC( uintptr_t, GetProgramAddress )( PTASK_INFO task );
// before luanchProgramEx, there was no userdata...
SYSTEM_PROC( void, SetProgramUserData )( PTASK_INFO task, uintptr_t psv );
// attempt to implement a method on windows that allows a service to launch a user process
// current systems don't have such methods
SYSTEM_PROC( void, ImpersonateInteractiveUser )( void );
// after launching a process should revert to a protected state.
SYSTEM_PROC( void, EndImpersonation )( void );
// generate a Ctrl-C to the task.
// maybe also signal systray icon
// maybe also signal process.lock region
// maybe end process?
// maybe then terminate process?
SYSTEM_PROC( LOGICAL, StopProgram )( PTASK_INFO task );
// ctextstr as its own type is a pointer so a
//  PcTextStr is a pointer to strings -
//   char ** - returns a quoted string if args have spaces (and escape quotes in args?)
SYSTEM_PROC( TEXTSTR, GetArgsString )( PCTEXTSTR pArgs );
// after a task has exited, this can return its code.
// undefined if task has not exited (probably 0)
SYSTEM_PROC( uint32_t, GetTaskExitCode )( PTASK_INFO task );
// returns the name of the executable that is this process (without last . extension   .exe for instance)
SYSTEM_PROC( CTEXTSTR, GetProgramName )( void );
// returns the path of the executable that is this process
SYSTEM_PROC( CTEXTSTR, GetProgramPath )( void );
// returns the path that was the working directory when the program started
SYSTEM_PROC( CTEXTSTR, GetStartupPath )( void );
// returns the path of the current sack library.
SYSTEM_PROC( CTEXTSTR, GetLibraryPath )( void );
// on windows, queries an event that indicates the system is rebooting.
SYSTEM_PROC( LOGICAL, IsSystemShuttingDown )( void );
// HandlePeerOutput is called whenever a peer task has generated output on stdout or stderr
//   - someday evolution may require processing stdout and stderr with different event handlers
SYSTEM_PROC( PTASK_INFO, LaunchPeerProgramEx )( CTEXTSTR program, CTEXTSTR path, PCTEXTSTR args
                                              , TaskOutput HandlePeerOutput
                                              , TaskEnd EndNotice
                                              , uintptr_t psv
                                               DBG_PASS
                                              );
#define LaunchPeerProgram(prog,path,args,out,end,psv) LaunchPeerProgramEx(prog,path,args,out,end,psv DBG_SRC)
SYSTEM_PROC( PTASK_INFO, SystemEx )( CTEXTSTR command_line
                                   , TaskOutput OutputHandler
                                   , uintptr_t psv
                                   DBG_PASS
                                   );
#define System(command_line,output_handler,user_data) SystemEx( command_line, output_handler, user_data DBG_SRC )
// generate output to a task... read by peer task on standard input pipe
// if a task has been opened with an output handler, than IO is trapped, and this is a method of
// sending output to a task.
SYSTEM_PROC( int, pprintf )( PTASK_INFO task, CTEXTSTR format, ... );
// if a task has been opened with an otuput handler, than IO is trapped, and this is a method of
// sending output to a task.
SYSTEM_PROC( int, vpprintf )( PTASK_INFO task, CTEXTSTR format, va_list args );
typedef void (CPROC*generic_function)(void);
SYSTEM_PROC( generic_function, LoadFunctionExx )( CTEXTSTR library, CTEXTSTR function, LOGICAL bPrivate DBG_PASS);
SYSTEM_PROC( generic_function, LoadFunctionEx )( CTEXTSTR library, CTEXTSTR function DBG_PASS);
SYSTEM_PROC( void *, GetPrivateModuleHandle )( CTEXTSTR libname );
/*
  Add a custom loaded library; attach a name to the DLL space; this should allow
  getcustomsybmol to resolve these
  */
SYSTEM_PROC( void, AddMappedLibrary )( CTEXTSTR libname, POINTER image_memory );
SYSTEM_PROC( LOGICAL, IsMappedLibrary )( CTEXTSTR libname );
SYSTEM_PROC( void, DeAttachThreadToLibraries )( LOGICAL attach );
#define LoadFunction(l,f) LoadFunctionEx(l,f DBG_SRC )
SYSTEM_PROC( generic_function, LoadPrivateFunctionEx )( CTEXTSTR libname, CTEXTSTR funcname DBG_PASS );
#define LoadPrivateFunction(l,f) LoadPrivateFunctionEx(l,f DBG_SRC )
#define OnLibraryLoad(name)	  __DefineRegistryMethod(WIDE("SACK"),_OnLibraryLoad,WIDE("system/library"),WIDE("load_event"),name WIDE("_LoadEvent"),void,(void), __LINE__)
// the callback passed will be called during LoadLibrary to allow an external
// handler to download or extract the library; the resulting library should also
// be loaded by the callback using the standard 'LoadFunction' methods
SYSTEM_PROC( void, SetExternalLoadLibrary )( LOGICAL (CPROC*f)(const char *) );
// please Release or Deallocate the reutrn value
// the callback should search for the file specified, if required, download or extract it
// and then return with a Release'able utf-8 char *.
SYSTEM_PROC( void, SetExternalFindProgram )( char * (CPROC*f)(const char *) );
// override the default program name.
// Certain program wrappers might use this to change log location, configuration, etc other defaults.
SYSTEM_PROC( void, SetProgramName )( CTEXTSTR filename );
// this is a pointer pointer - being that generic_fucntion is
// a pointer...
SYSTEM_PROC( int, UnloadFunctionEx )( generic_function* DBG_PASS );
#ifdef HAVE_ENVIRONMENT
SYSTEM_PROC( CTEXTSTR, OSALOT_GetEnvironmentVariable )(CTEXTSTR name);
SYSTEM_PROC( void, OSALOT_SetEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
SYSTEM_PROC( void, OSALOT_AppendEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
SYSTEM_PROC( void, OSALOT_PrependEnvironmentVariable )(CTEXTSTR name, CTEXTSTR value);
#endif
/* this needs to have 'GetCommandLine()' passed to it.
 * Otherwise, the command line needs to have the program name, and arguments passed in the string
 * the parameter to winmain has the program name skipped
 */
SYSTEM_PROC( void, ParseIntoArgs )( TEXTCHAR *lpCmdLine, int *pArgc, TEXTCHAR ***pArgv );
#define UnloadFunction(p) UnloadFunctionEx(p DBG_SRC )
SACK_SYSTEM_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::system;
#endif
#endif
//----------------------------------------------------------------------
// $Log: system.h,v $
// Revision 1.14  2005/07/06 00:33:55  jim
// Fixes for all sorts of mangilng with the system.h header.
//
//
// Revision 1.2  2003/10/24 14:59:21  panther
// Added Load/Unload Function for system shared library abstraction
//
// Revision 1.1  2003/10/24 13:22:06  panther
// Initial commit
//
//
#if defined( _MSC_VER )|| defined(__LCC__) || defined( __WATCOMC__ ) || defined( __GNUC__ )
/* Includes networking as appropriate for the target platform. Providing
   compatibility definitions as are lacking between platforms...
   or perhaps appropriate name aliasing to the correct types.            */
#ifndef INCLUDED_SOCKET_LIBRARY
#define INCLUDED_SOCKET_LIBRARY
#if defined( _WIN32 ) || defined( __CYGWIN__ )
//#ifndef __cplusplus_cli
#ifdef UNDER_CE
#define USE_WSA_EVENTS
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#if defined( MINGW_SUX ) && ( __GNUC__ < 5 )
/* Address information */
typedef struct addrinfoA {
    int             ai_flags;
    int             ai_family;
    int             ai_socktype;
    int             ai_protocol;
    size_t          ai_addrlen;
    char            *ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfoA *ai_next;
} ADDRINFOA;
typedef ADDRINFOA   *PADDRINFOA;
typedef struct addrinfoW {
    int                 ai_flags;
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    size_t              ai_addrlen;
    PWSTR               ai_canonname;
    struct sockaddr     *ai_addr;
    struct addrinfoW    *ai_next;
} ADDRINFOW;
typedef ADDRINFOW   *PADDRINFOW;
#ifdef UNICODE
typedef ADDRINFOW   ADDRINFOT;
typedef ADDRINFOW   *PADDRINFOT;
#else
typedef ADDRINFOA   ADDRINFOT;
typedef ADDRINFOA   *PADDRINFOT;
#endif
typedef ADDRINFOA   ADDRINFO;
typedef ADDRINFOA   *LPADDRINFO;
#endif
#ifdef __CYGWIN__
// just need this simple symbol
typedef int socklen_t;
#endif
//#endif
#elif defined( __LINUX__ )
#if defined( FBSD )
#endif
 // INADDR_ANY/NONE
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#if !defined( _PNACL )
#  include <net/if.h>
#endif
#define SOCKET int
#define SOCKADDR struct sockaddr
#define SOCKET_ERROR -1
//#define HWND int // unused params...
#define WSAEWOULDBLOCK EAGAIN
#define INVALID_SOCKET -1
#define WSAAsynchSelect( a,b,c,d ) (0)
#define WSAGetLastError()  (errno)
#define closesocket(s) close(s)
typedef struct hostent *PHOSTENT;
#ifndef __LINUX__
#define INADDR_ANY (-1)
#define INADDR_NONE (0)
#endif
struct win_in_addr {
	union {
		struct { uint8_t s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { uint16_t s_w1,s_w2; } S_un_w;
		uint32_t S_addr;
	} S_un;
#ifndef __ANDROID__
#define s_addr  S_un.S_addr
/* can be used for most tcp & ip code */
#define s_host  S_un.S_un_b.s_b2
	/* host on imp */
#define s_net   S_un.S_un_b.s_b1
	/* network */
#define s_imp   S_un.S_un_w.s_w2
	/* imp */
#define s_impno S_un.S_un_b.s_b4
	/* imp # */
#define s_lh    S_un.S_un_b.s_b3
	/* logical host */
#endif
};
struct win_sockaddr_in {
#ifdef __MAC__
	uint8_t sa_len;
	uint8_t sin_family;
#else
	short   sin_family;
#endif
	uint16_t sin_port;
	struct  win_in_addr sin_addr;
	char    sin_zero[8];
};
typedef struct win_sockaddr_in SOCKADDR_IN;
#endif
#endif
// $Log: loadsock.h,v $
// Revision 1.7  2005/01/27 08:09:25  panther
// Linux cleaned.
//
// Revision 1.6  2003/06/04 11:38:01  panther
// Define PACKED
//
// Revision 1.5  2003/03/25 08:38:11  panther
// Add logging
//
#  if defined( __MAC__ )
#  else
               // _heapmin() included here
#    include <malloc.h>
#  endif
#else
//#include "loadsock.h"
#endif
//#include <stdlib.h>
#ifdef __CYGWIN__
 // provided by -lgcc
// lots of things end up including 'setjmp.h' which lacks sigset_t defined here.
// lots of things end up including 'setjmp.h' which lacks sigset_t defined here.
#  include <sys/signal.h>
#endif
// GetTickCount() and Sleep(n) Are typically considered to be defined by including stdhdrs...
/*
 *  Crafted by Jim Buckeyne
 *
 *  (c)2001-2006++ Freedom Collective
 *
 *  Provide API interface for timers, critical sections
 *  and other thread things.
 *
 */
#ifndef TIMERS_DEFINED
/* timers.h mutliple inclusion protection symbol. */
#define TIMERS_DEFINED
#if defined( _WIN32 )
// on windows, we add a function that returns HANDLE
#endif
#ifndef SHARED_MEM_DEFINED
/* Multiple inclusion protection symbol. */
#define SHARED_MEM_DEFINED
#if defined (_WIN32)
//#define USE_NATIVE_CRITICAL_SECTION
#endif
#if defined( _SHLWAPI_H ) || defined( _INC_SHLWAPI )
#undef StrChr
#undef StrCpy
#undef StrDup
#undef StrRChr
#undef StrStr
#endif
#ifdef __cplusplus
#define SACK_MEMORY_NAMESPACE SACK_NAMESPACE namespace memory {
#define SACK_MEMORY_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define SACK_MEMORY_NAMESPACE
#define SACK_MEMORY_NAMESPACE_END
#endif
/* A declaration of the call type for memory library routines. */
#define MEM_API CPROC
#    ifdef MEM_LIBRARY_SOURCE
#      define MEM_PROC EXPORT_METHOD
#    else
/* Defines library linkage specification. */
#      define MEM_PROC IMPORT_METHOD
#    endif
#ifndef TIMER_NAMESPACE
#ifdef __cplusplus
#define _TIMER_NAMESPACE namespace timers {
/* define a timer library namespace in C++. */
#define TIMER_NAMESPACE SACK_NAMESPACE namespace timers {
/* define a timer library namespace in C++ end. */
#define TIMER_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define TIMER_NAMESPACE
#define TIMER_NAMESPACE_END
#endif
#endif
	TIMER_NAMESPACE
   // enables file/line monitoring of sections and a lot of debuglogging
//#define DEBUG_CRITICAL_SECTIONS
   /* this symbol controls the logging in timers.c... (higher level interface to NoWait primatives)*/
//#define LOG_DEBUG_CRITICAL_SECTIONS
/* A custom implementation of windows CRITICAL_SECTION api.
   Provides same capability for Linux type systems. Can be
   checked as a study in how to implement safe locks.
   See Also
   InitCriticalSec
   EnterCriticalSec
   LeaveCriticalSec
   Example
   <c>For purposes of this example this is declared in global
   memory, known to initialize to all 0.</c>
   <code lang="c++">
   CRITICALSECTION cs_lock_test;
   </code>
   In some bit of code that can be executed by several
   threads...
   <code lang="c++">
   {
      EnterCriticalSec( &amp;cs_lock_test );
      // the code in here will only be run by a single thread
      LeaveCriticalSec( &amp;cs_lock_test );
   }
   </code>
   Remarks
   The __Ex versions of functions passes source file and line
   information in debug mode. This can be used if critical
   section debugging is turned on, or if critical section
   logging is turned on. (See ... ) This allows applications to
   find deadlocks by tracking who is entering critical sections
   and probably failing to leave them.                          */
struct critical_section_tag {
 // this is set when entering or leaving (updating)...
	uint32_t dwUpdating;
  // count of locks entered.  (only low 24 bits may count for 16M entries, upper bits indicate internal statuses.
	uint32_t dwLocks;
 // windows upper 16 is process ID, lower is thread ID
	THREAD_ID dwThreadID;
 // ID of thread waiting for this..
	THREAD_ID dwThreadWaiting;
#ifdef DEBUG_CRITICAL_SECTIONS
#define MAX_SECTION_LOG_QUEUE 16
	uint32_t bCollisions ;
	CTEXTSTR pFile[16];
	uint32_t  nLine[16];
	uint32_t  nLineCS[16];
 // windows upper 16 is process ID, lower is thread ID
	THREAD_ID dwThreadPrior[16];
 // windows upper 16 is process ID, lower is thread ID
	uint8_t isLock[16];
	int nPrior;
#endif
};
#if !defined( _WIN32 )
#undef USE_NATIVE_CRITICAL_SECTION
#endif
/* <combine sack::timers::critical_section_tag>
   \ \                                          */
#if defined( USE_NATIVE_CRITICAL_SECTION )
#define CRITICALSECTION CRITICAL_SECTION
#else
typedef struct critical_section_tag CRITICALSECTION;
#endif
/* <combine sack::timers::critical_section_tag>
   defines a pointer to a CRITICALSECTION type  */
#if defined( USE_NATIVE_CRITICAL_SECTION )
#define PCRITICALSECTION LPCRITICAL_SECTION
#else
#define InitializeCriticalSection InitializeCriticalSec
typedef struct critical_section_tag *PCRITICALSECTION;
#endif
/* attempts to enter the critical section, and does not block.
   Returns
   If it enters the return is 1, else the return is 0.
   Parameters
   pcs :    pointer to a critical section
   prior :  if not NULL, prior will be set to the current thread
            ID of the owning thread.                             */
#ifndef USE_NATIVE_CRITICAL_SECTION
MEM_PROC  int32_t MEM_API  EnterCriticalSecNoWaitEx ( PCRITICALSECTION pcs, THREAD_ID *prior DBG_PASS );
#define EnterCriticalSecNoWait( pcs,prior ) EnterCriticalSecNoWaitEx( pcs, prior DBG_SRC )
#else
#define EnterCriticalSecNoWait( pcs,prior ) TryEnterCriticalSection( (pcs) )
#endif
/* <combine sack::timers::EnterCriticalSecNoWaitEx@PCRITICALSECTION@THREAD_ID *prior>
   \ \                                                                                */
//#define EnterCriticalSecNoWait( pcs,prior ) EnterCriticalSecNoWaitEx( (pcs),(prior) DBG_SRC )
/* clears all members of a CRITICALSECTION.  Same as memset( pcs, 0, sizeof( CRITICALSECTION ) ); */
#ifndef USE_NATIVE_CRITICAL_SECTION
MEM_PROC  void MEM_API  InitializeCriticalSec ( PCRITICALSECTION pcs );
#else
#define InitializeCriticalSec(pcs)  InitializeCriticalSection(pcs)
#endif
/* Get a count of how many times a critical section is locked */
//MEM_PROC  uint32_t MEM_API  CriticalSecOwners ( PCRITICALSECTION pcs );
/* Namespace of all memory related functions for allocating and
   releasing memory.                                            */
#ifdef __cplusplus
 // namespace timers
};
 // namespace sack
};
using namespace sack::timers;
#endif
#ifdef __cplusplus
namespace sack {
/* Memory namespace contains functions for allocating and
   releasing memory. Also contains methods for accessing shared
   memory (if available on the target platform).
   Allocate
   Release
   Hold
   OpenSpace                                                    */
namespace memory {
#endif
typedef struct memory_block_tag* PMEM;
// what is an abstract name for the memory mapping handle...
// where is a filename for the filebacking of the shared memory
// DigSpace( WIDE(TEXT( "Picture Memory" )), WIDE(TEXT( "Picture.mem" )), 100000 );
/* <combinewith sack::memory::OpenSpaceExx@CTEXTSTR@CTEXTSTR@uintptr_t@uintptr_t *@uint32_t*>
   \ \                                                                                 */
MEM_PROC  POINTER MEM_API  OpenSpace ( CTEXTSTR pWhat, CTEXTSTR pWhere, uintptr_t *dwSize );
/* <unfinished>
   Open a shared memory region. The region may be named with a
   text string (this does not work under linux platforms, and
   the name of the file to back the shared region is the sharing
   point). The region may be backed with a file (and must be if
   it is to be shared on linux.
   If the region exists by name, the region is opened, and a
   pointer to that region is returned.
   If the file exists, the file is opened, and mapped into
   memory, and a pointer to the file backed memory is returned.
   if the file does not exist, and the size parameter passed is
   not 0, then the file is created, and expanded to the size
   requested. The bCreate flag is set to true.
   If NULL is passed for pWhat and pWhere, then a block of
   memory is allocated in system memory, backed by pagefile.
   if dwSize is 0, then the region is specified for open only,
   and will not create.
   Parameters
   pWhat :     String to a named shared memory region. NULL is
               unnamed.
   pWhere :    Filename to back the shared memory with. The file
               name itself may also be used to share the memory.
   address :   A base address to map the memory at. If 0,
               specifies do not care.
   dwSize :    pointer to a uintptr_t that defines the size to
               create. If 0, then the region is only opened. The
               size of the region opened is set back into this
               value after it is opened.
   bCreated :  pointer to a boolean to indicate whether the space
               was created or not.
   Returns
   Pointer to region requested to be opened. NULL on failure.
   Example
   Many examples of this are appropriate.
   1) Open or create a file backed shared space.
   2) Open a file for direct memory access, the file is loaded
   into memory by system paging routines and not any API.         */
MEM_PROC  POINTER MEM_API  OpenSpaceExx ( CTEXTSTR pWhat, CTEXTSTR pWhere, uintptr_t address
	, uintptr_t *dwSize, uint32_t* bCreated );
/* <combine sack::memory::OpenSpaceExx@CTEXTSTR@CTEXTSTR@uintptr_t@uintptr_t *@uint32_t*>
   \ \                                                                             */
#define OpenSpaceEx( what,where,address,psize) OpenSpaceExx( what,where,address,psize,NULL )
/* Closes a shared memory region. Calls CloseSpaceEx() with
   bFinal set TRUE.
   Parameters
   pMem :  pointer to a memory region opened by OpenSpace.  */
MEM_PROC  void MEM_API  CloseSpace ( POINTER pMem );
/* Closes a memory region. Release can also be used to close
   opened spaces.
   Parameters
   pMem :    pointer to a memory region opened with OpenSpace()
   bFinal :  If final is set, the file used for backing the shared
             region is deleted.                                    */
MEM_PROC  void MEM_API  CloseSpaceEx ( POINTER pMem, int bFinal );
/* This can give the size back of a memory space.
   Returns
   The size of the memory block.
   Parameters
   pMem :  pointer to a block of memory that was opened with
           OpenSpace().                                      */
MEM_PROC  uintptr_t MEM_API  GetSpaceSize ( POINTER pMem );
/* even if pMem is just a POINTER returned from OpenSpace this
   will create a valid heap pointer.
   will result TRUE if a valid heap is present will result FALSE
   if heap is not able to init (has content)
   Parameters
   pMem :    pointer to a memory space to setup as a heap.
   dwSize :  size of the memory space pointed at by pMem.        */
MEM_PROC  int MEM_API  InitHeap( PMEM pMem, uintptr_t dwSize );
/* Dumps all blocks into the log.
   Parameters
   pHeap :     Heap to dump. If NULL or unspecified, dump the
               default heap.
   bVerbose :  Specify to dump each block's information,
               otherwise only summary information is generated. */
MEM_PROC  void MEM_API  DebugDumpHeapMemEx ( PMEM pHeap, LOGICAL bVerbose );
/* <combine sack::memory::DebugDumpHeapMemEx@PMEM@LOGICAL>
   Logs all of the blocks tracked in a specific heap.
   Parameters
   Heap :  Heap to dump the memory blocks of.              */
#define DebugDumpHeapMem(h)     DebugDumpMemEx( (h), TRUE )
/* <combine sack::memory::DebugDumpHeapMemEx@PMEM@LOGICAL>
   \ \                                                     */
MEM_PROC  void MEM_API  DebugDumpMemEx ( LOGICAL bVerbose );
/* Dumps all tracked heaps.
   Parameters
   None.                    */
#define DebugDumpMem()     DebugDumpMemEx( TRUE )
/* Dumps a heap to a specific file.
   Parameters
   pHeap :      Heap. If NULL or unspecified, dumps default heap.
   pFilename :  name of the file to write output to.              */
MEM_PROC  void MEM_API  DebugDumpHeapMemFile ( PMEM pHeap, CTEXTSTR pFilename );
/* <combine sack::memory::DebugDumpHeapMemFile@PMEM@CTEXTSTR>
   \ \                                                        */
MEM_PROC  void MEM_API  DebugDumpMemFile ( CTEXTSTR pFilename );
#ifdef __GNUC__
MEM_PROC  POINTER MEM_API  HeapAllocateAlignedEx ( PMEM pHeap, uintptr_t dwSize, uint16_t alignment DBG_PASS ) __attribute__( (malloc) );
MEM_PROC  POINTER MEM_API  HeapAllocateEx ( PMEM pHeap, uintptr_t nSize DBG_PASS ) __attribute__((malloc));
MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS ) __attribute__((malloc));
#else
/* \ \
   Parameters
   pHeap :  pointer to a heap which was initialized with
            InitHeap()
   Size :   Size of block to allocate                    */
MEM_PROC  POINTER MEM_API  HeapAllocateEx ( PMEM pHeap, uintptr_t nSize DBG_PASS );
/* \ Parameters
pHeap :  pointer to a heap which was initialized with
InitHeap()
Size :   Size of block to allocate
Alignment : count of bytes to return block on (1,2,4,8,16,32)  */
MEM_PROC  POINTER MEM_API  HeapAllocateAlignedEx( PMEM pHeap, uintptr_t nSize, uint16_t alignment DBG_PASS );
/* Allocates a block of memory of specific size. Debugging
   information if passed is recorded on the block.
   Parameters
   size :  size of the memory block to create              */
MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS );
#endif
/* A simple macro to allocate a new single unit of a structure. Adds
   a typecast automatically to be (type*) so C++ compilation is
   clean. Does not burden the user with extra typecasts. This,
   being in definition use means that all other things that are
   typecast are potentially error prone. Memory is considered
   uninitialized.
   Parameters
   type :  type to allocate
   Example
   <code lang="c++">
   int *p_int = New( int );
   </code>                                                           */
#define New(type) ((type*)HeapAllocate(0,sizeof(type)))
/* Reallocates an array of type.
   Parameters
   type :  type to use for sizeof(type) * sz for resulting size.
   p :     pointer to realloc
   sz :    count of elements in the array                        */
#define Renew(type,p,sz) ((type*)HeapReallocate(0,p, sizeof(type)*sz))
/* an advantage of C, can define extra space at end of structure
   which is allowed to carry extra data, which is unknown by
   other code room for exploits rock.
   Parameters
   type :   passed to sizeof()
   extra :  Number of additional bytes to allocate beyond the
            sizeof( type )
   Example
   Create a text segment plus 18 characters of data. (This
   should not be done, use SegCreate instead)
   <code lang="c#">
   PTEXT text = NewPlus( TEXT, 18 );
   </code>                                                       */
#define NewPlus(type,extra) ((type*)HeapAllocate(0,sizeof(type)+(extra)))
/* Allocate a new array of type.
   Parameters
   type :   type to determine size of array element to allocate.
   count :  count of elements to allocate in the array.
   Returns
   A pointer to type. (this is important, since in C++ it's cast
   correctly to the destination type).                           */
#define NewArray(type,count) ((type*)HeapAllocate(0,sizeof(type)*(count)))
/* Allocate sizeof(type). Will invoke some sort of registered
   initializer
   Parameters
   type :  type to allocate for. Passes the name of the type so
           the allocator can do a registered procedure lookup and
           invok an initializer for the type.                     */
//#define NewObject(type) ((type*)FancyAllocate(sizeof(type),#type DBG_SRC))
#ifdef __cplusplus
/* A 'safe' release macro. casts the block to the type to
   release. Makes sure the pointer being released is the type
   specified.
   Parameters
   type :   type of the variable
   thing :  the thing to actually release.                    */
#  ifdef _DEBUG
#    define Deallocate(type,thing) for(type _zzqz_tmp=thing;ReleaseEx((POINTER)(_zzqz_tmp)DBG_SRC),0;)
#  else
#    define Deallocate(type,thing) ReleaseEx((POINTER)(thing)DBG_SRC)
#  endif
#else
#  define Deallocate(type,thing) (ReleaseEx((POINTER)(thing)DBG_SRC))
#endif
/* <combine sack::memory::HeapAllocateEx@PMEM@uintptr_t nSize>
   \ \                                                        */
#define HeapAllocate(heap, n) HeapAllocateEx( (heap), (n) DBG_SRC )
   /* <combine sack::memory::HeapAllocateAlignedEx@PMEM@uintptr_t@uint32_t>
   \ \                                                        */
#define HeapAllocateAligned(heap, n, m) HeapAllocateAlignedEx( (heap), (n), m DBG_SRC )
   /* <combine sack::memory::AllocateEx@uintptr_t nSize>
   \ \                                               */
#ifdef FIX_RELEASE_COM_COLLISION
#else
#define Allocate( n ) HeapAllocateEx( (PMEM)0, (n) DBG_SRC )
#endif
//MEM_PROC  POINTER MEM_API  AllocateEx ( uintptr_t nSize DBG_PASS );
//#define Allocate(n) AllocateEx(n DBG_SRC )
MEM_PROC  POINTER MEM_API  GetFirstUsedBlock ( PMEM pHeap );
/* Releases an allocated block. Memory becomes free to allocate
   again. If debugging information is passed, the releasing
   source and line is recorded in the block. (can be used to
   find code deallocating memory it shouldn't).
   This also works with Hold(), and decrements the hold counter.
   If there are no more holds on the block, then the block is
   released.
   Parameters
   p :  pointer to allocated block to release.                   */
MEM_PROC  POINTER MEM_API  ReleaseEx ( POINTER pData DBG_PASS ) ;
/* <combine sack::memory::ReleaseEx@POINTER pData>
   \ \                                             */
#ifdef FIX_RELEASE_COM_COLLISION
#else
/* <combine sack::memory::ReleaseEx@POINTER pData>
   \ \                                             */
#define Release(p) ReleaseEx( (p) DBG_SRC )
#endif
/* Adds a usage count to a block of memory. For each count
   added, an additional release must be used. This can be used
   to keep a copy of the block, even if some other code
   automatically releases it.
   Parameters
   pointer :  pointer to a block of memory that was Allocate()'d.
   Example
   Allocate a block of memory, and release it properly. But we
   passed it to some function. That function wanted to keep a
   copy of the block, so it can apply a hold. It needs to later
   do a Release again to actually free the memory.
   <code lang="c++">
   POINTER p = Allocate( 32 );
   call_some_function( p );
   Release( p );
   void call_some_function( POINTER p )
   {
      static POINTER my_p_copy;
      my_p_copy = p;
      Hold( p );
   }
   </code>                                                        */
MEM_PROC  POINTER MEM_API  HoldEx ( POINTER pData DBG_PASS  );
/* <combine sack::memory::HoldEx@POINTER pData>
   \ \                                          */
#define Hold(p) HoldEx(p DBG_SRC )
/* This can be used to add additional space after the end of a
   memory block.
   Parameters
   pHeap :   If NULL or not specified, uses the common memory heap.
   source :  pointer to the block to pre\-allocate. If NULL, a new
             memory block will be allocated that is filled with 0.
   size :    the new size of the block.
   Returns
   A pointer to a new block of memory that is the new size.
   Remarks
   If the size specified for the new block is larger than the
   previous size of the block, the curernt data is copied to the
   beginning of the new block, and the memory after the existing
   content is cleared to 0.
   If the size specified for the new block is smaller than the
   previous size, the end of the original block is not copied to
   the new block.
   If NULL is passed as the source block, then a new block
   filled with 0 is created.                                        */
MEM_PROC  POINTER MEM_API  HeapReallocateAlignedEx ( PMEM pHeap, POINTER source, uintptr_t size, uint16_t alignment DBG_PASS );
MEM_PROC  POINTER MEM_API  HeapReallocateEx ( PMEM pHeap, POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::HeapReallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                 */
#define HeapReallocateAligned(heap,p,sz,al) HeapReallocateEx( (heap),(p),(sz),(al) DBG_SRC )
#define HeapReallocate(heap,p,sz) HeapReallocateEx( (heap),(p),(sz) DBG_SRC )
/* <combine sack::memory::HeapReallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                 */
MEM_PROC  POINTER MEM_API  ReallocateEx ( POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::ReallocateEx@POINTER@uintptr_t size>
   \ \                                                        */
#ifdef FIX_RELEASE_COM_COLLISION
#else
#define Reallocate(p,sz) ReallocateEx( (p),(sz) DBG_SRC )
#endif
/* This can be used to add additional space before the beginning
   of a memory block.
   Parameters
   pHeap :   If NULL or not specified, uses the common memory heap.
   source :  pointer to the block to pre\-allocate. If NULL, a new
             memory block will be allocated that is filled with 0.
   size :    the new size of the block.
   Returns
   A pointer to a new block of memory that is the new size.
   Remarks
   If the size specified for the new block is larger than the
   previous size of the block, the content data is copied to the
   end of the new block, and the memory leading up to the block
   is cleared to 0.
   If the size specified for the new block is smaller than the
   previous size, the end of the original block is not copied to
   the new block.
   If NULL is passed as the source block, then a new block
   filled with 0 is created.                                        */
MEM_PROC  POINTER MEM_API  HeapPreallocateEx ( PMEM pHeap, POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::HeapPreallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                  */
#define HeapPreallocate(heap,p,sz) HeapPreallocateEx( (heap),(p),(sz) DBG_SRC )
/* <combine sack::memory::HeapPreallocateEx@PMEM@POINTER@uintptr_t size>
   \ \                                                                  */
MEM_PROC  POINTER MEM_API  PreallocateAlignedEx ( POINTER source, uintptr_t size, uint16_t alignment DBG_PASS );
MEM_PROC  POINTER MEM_API  PreallocateEx ( POINTER source, uintptr_t size DBG_PASS );
/* <combine sack::memory::PreallocateEx@POINTER@uintptr_t size>
   \ \                                                         */
#define PreallocateAligned(p,sz,al) PreallocateAlignedEx( (p),(sz),(al) DBG_SRC )
#define Preallocate(p,sz) PreallocateEx( (p),(sz) DBG_SRC )
/* Moves a block of memory from one heap to another.
   Parameters
   pNewHeap :  heap target to move the block to.
   source :    source block to move \- pointer to the data in the
               block.
   Remarks
   Since each block remembers its own size, it is possible to
   move a block from one heap to another. A heap might be a
   memory mapped file at a specific address for instance.         */
MEM_PROC  POINTER MEM_API  HeapMoveEx ( PMEM pNewHeap, POINTER source DBG_PASS );
/* <combine sack::memory::HeapMoveEx@PMEM@POINTER source>
   \ \                                                    */
#define HeapMove(h,s) HeapMoveEx( (h), (s) DBG_SRC )
/* \returns the size of a memory block which was Allocate()'d.
   Parameters
   pData :  pointer to a allocated memory block.
   Returns
   The size of the block that was specified by the Allocate(). */
MEM_PROC uintptr_t MEM_API  SizeOfMemBlock ( CPOINTER pData );
/* \returns the allocation alignment of a memory block which was Allocate()'d.
Parameters
pData :  pointer to a allocated memory block.
Returns
The alignment of the block that was specified from Allocate(). */
MEM_PROC uint16_t  AlignOfMemBlock( CPOINTER pData );
/* not so much of a fragment as a consolidation. Finds a free
   spot earlier in the heap and attempts to move the block
   there. This can help alleviate heap fragmentation.
   Parameters
   ppMemory :  pointer to a pointer to memory which might move */
MEM_PROC  LOGICAL MEM_API  Defragment ( POINTER *ppMemory );
/* \ \
   Parameters
   pHeap :        pointer to a heap
   pFree :        pointer to a 32 bit value to receive the size
                  of free space
   pUsed :        pointer to a 32 bit value to receive the size
                  of used space
   pChunks :      pointer to a 32 bit value to receive the total
                  count of chunks.
   pFreeChunks :  pointer to a 32 bit value to receive the total
                  count of free chunks.
   Remarks
   It looks like DBG_PASS parameter isn't used... not sure why
   it would here, there is no allocate or delete.
   The count of allocated chunks can be gotten by subtracting
   FreeChunks from Chunks.
   Example
   <code lang="c++">
   uint32_t free;
   uint32_t used;
   uint32_t chunks;
   uint32_t free_chunks;
   GetHeapMemStatsEx( NULL, &amp;free, &amp;used, &amp;chunks, &amp;free_chunks );
   </code>                                                                         */
MEM_PROC  void MEM_API  GetHeapMemStatsEx ( PMEM pHeap, uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks DBG_PASS );
/* <combine sack::memory::GetHeapMemStatsEx@PMEM@uint32_t *@uint32_t *@uint32_t *@uint32_t *pFreeChunks>
   \ \                                                                               */
#define GetHeapMemStats(h,f,u,c,fc) GetHeapMemStatsEx( h,f,u,c,fc DBG_SRC )
//MEM_PROC  void MEM_API  GetHeapMemStats ( PMEM pHeap, uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks );
MEM_PROC  void MEM_API  GetMemStats ( uint32_t *pFree, uint32_t *pUsed, uint32_t *pChunks, uint32_t *pFreeChunks );
/* Sets whether to log allocations or not.
   \returns the prior state of logging...
   Parameters
   bTrueFalse :  if TRUE, allocation logging is turned on. Enables
                 logging when each block is Allocated, Released,
                 or Held.                                          */
MEM_PROC  int MEM_API  SetAllocateLogging ( LOGICAL bTrueFalse );
/* disables storing file/line, also disables auto GetMemStats
   checking
   Parameters
   bDisable :  set to TRUE to disable allocate debug logging. */
MEM_PROC  int MEM_API  SetAllocateDebug ( LOGICAL bDisable );
/* disables auto GemMemStats on every allocate/release/Hold
   GetMemStats will evaluate each and every block allocated in
   memory and inspect it for corruption.
   Parameters
   bDisable :  set to TRUE to disable auto mem check.          */
MEM_PROC  int MEM_API  SetManualAllocateCheck ( LOGICAL bDisable );
/* Sets whether to log critical sections or not.
   \returns the prior state of logging...
   Parameters
   bTrueFalse :  if TRUE, critical section logging is turned on. Logs
                 when each thread enters or leaves a
                 CRITICIALSECTION.                                    */
MEM_PROC  int MEM_API  SetCriticalLogging ( LOGICAL bTrueFalse );
/* Sets the minimum size to allocate. If a block size less than
   this is allocated, then this much is actually allocated.
   Parameters
   nSize :  Specify the minimum allocation size                 */
MEM_PROC  void MEM_API  SetMinAllocate ( size_t nSize );
/* Sets how much a heap is expanded by when it is out of space. Default
   is like 512k.
   Parameters
   dwSize :  the new size to expand heaps by.
   Remarks
   Probably internally, this is rounded up to the next 4k
   boundary.                                                            */
MEM_PROC  void MEM_API  SetHeapUnit ( size_t dwSize );
/* Multi-processor safe exchange operation. Returns the prior
   value at the pointer.
   Parameters
   p :    pointer to a volatile 64 bit value.
   val :  a new 64 bit value to put at (*p)
   Example
   <code lang="c#">
   uint64_t value = 13;
   uint64_t oldvalue = LockedExchange64( &amp;value, 15 );
   // old value will be 13
   // value will be 15
   </code>                                                    */
MEM_PROC  uint64_t MEM_API  LockedExchange64 ( volatile uint64_t* p, uint64_t val );
/* A multi-processor safe increment of a variable.
   Parameters
   p :  pointer to a 32 bit value to increment.    */
MEM_PROC  uint32_t MEM_API  LockedIncrement ( uint32_t* p );
/* Does a multi-processor safe decrement on a variable.
   Parameters
   p :  pointer to a 32 bit value to decrement.         */
MEM_PROC  uint32_t MEM_API  LockedDecrement ( uint32_t* p );
#ifdef __cplusplus
// like also __if_assembly__
//extern "C" {
#endif
#ifdef __64__
#define LockedExchangePtrSzVal(a,b) LockedExchange64((volatile uint64_t*)(a),b)
#else
#define LockedExchangePtrSzVal(a,b) LockedExchange((volatile uint32_t*)(a),b)
#endif
/* Multiprocessor safe swap of the contents of a variable with a
   new value, and result with the old variable.
   Parameters
   p :    pointer to a 32 bit value to exchange
   val :  value to set into the variable
   Returns
   The prior value in p.
   Example
   <code>
   uint32_t variable = 0;
   uint32_t oldvalue = LockedExchange( &amp;variable, 1 );
   </code>                                                       */
MEM_PROC  uint32_t MEM_API  LockedExchange ( volatile uint32_t* p, uint32_t val );
/* Sets a 32 bit value into memory. If the length to set is not
   a whole number of 32 bit words, the last bytes may contain
   the low 16 bits of the value and the low 8 bits.
   Parameters
   p :   pointer to memory to set
   n :   32 bit value to set memory with
   sz :  length to set
   Remarks
   Writes as many 32 it values as will fit in sz.
   If (sz &amp; 2), the low 16 bits of n are written at the end.
   then if ( sz &amp; 1 ) the low 8 bits of n are written at the
   end.                                                          */
MEM_PROC  void MEM_API  MemSet ( POINTER p, uintptr_t n, size_t sz );
//#define _memset_ MemSet
/* memory copy operation. not safe when buffers overlap. Performs
   platform-native memory stream operation to copy from one
   place in memory to another. (32 or 64 bit operations as
   possible).
   Parameters
   pTo :    Memory to copy to
   pFrom :  memory to copy from
   sz :     size of block of memory to copy                       */
MEM_PROC  void MEM_API  MemCpy ( POINTER pTo, CPOINTER pFrom, size_t sz );
//#define _memcpy_ MemCpy
/* Binary byte comparison of one block of memory to another. Results
   \-1 if less, 1 if more and 0 if equal.
   Parameters
   pOne :  pointer to memory one
   pTwo :  pointer to some other memory
   sz :    count of bytes to compare
   Returns
   0 if equal
   \-1 if the first different byte in pOne is less than pTwo.
   1 if the first different byte in pOne is more than pTwo.          */
MEM_PROC  int MEM_API  MemCmp ( CPOINTER pOne, CPOINTER pTwo, size_t sz );
	/* nothing.
   does nothing, returns nothing. */
//#define memnop(mem,sz,comment)
#ifdef __cplusplus
//};
#endif
/* Compares two strings. Must match exactly.
   Parameters
   s1 :  string to compare
   s2 :  string to compare
   Returns
   0 if equal.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
	if s1 and s2 are NULL return is 0.              */
#ifdef StrCmp
#undef StrCmp
 // StrCmp
#endif
MEM_PROC  int MEM_API  StrCmp ( CTEXTSTR pOne, CTEXTSTR pTwo );
/* Compares two strings, case insensitively.
   Parameters
   s1 :  string to compare
   s2 :  string to compare
   Returns
   0 if equal.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
   if s1 and s2 are NULL return is 0.              */
MEM_PROC  int MEM_API  StrCaseCmp ( CTEXTSTR s1, CTEXTSTR s2 );
/* String insensitive case comparison with maximum length
   specified.
   Parameters
   s1 :      string to compare
   s2 :      string to compare
   maxlen :  maximum character required to match
   Returns
   0 if equal up to the number of characters.
   1 if (s1 \>s2)
   \-1 if (s1 \< s2)
   if s1 is NULL and s2 is not NULL, return is -1.
   if s2 is NULL and s1 is not NULL, return is 1.
   if s1 and s2 are NULL return is 0.                     */
MEM_PROC  int MEM_API  StrCaseCmpEx ( CTEXTSTR s1, CTEXTSTR s2, size_t maxlen );
/* This searches a string for the first character that matches
   some specified character.
   A custom strchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This flavor is the only one on C where operator overloading
   cannot switch between CTEXTSTR and TEXTSTR parameters, to
   \result with the correct type. If a CTEXTSTR is passed to
   this it should result with a CTEXTSTR, but if that's the only
   choice, then the result of this is never modifiable, even if
	it is a pointer to a non-const TEXTSTR.                       */
MEM_PROC  CTEXTSTR MEM_API  StrChr ( CTEXTSTR s1, TEXTCHAR c );
/* copy S2 to S1, with a maximum of N characters.
   The last byte of S1 will always be a 'nul'. If S2 was longer
   than S1, then it will be truncated to fit within S1. Perferred
   method over this is SaveText or StrDup.
   Parameters
   s1 :      desitnation TEXTCHAR buffer
   s2 :      source string
   length :  the maximum number of characters that S1 can hold. (this
             is not a size, but is a character count)                 */
MEM_PROC  TEXTSTR MEM_API  StrCpyEx ( TEXTSTR s1, CTEXTSTR s2, size_t n );
/* copy S2 to S1. This is 'unsafe', since neither paramter's
   size is known. Prefer StrCpyEx which passes the maximum
   length for S1.
   Parameters
   s1 :  desitnation TEXTCHAR buffer
   s2 :  source string                                       */
MEM_PROC  TEXTSTR MEM_API  StrCpy ( TEXTSTR s1, CTEXTSTR s2 );
/* \Returns the count of characters in a string.
   Parameters
   s :  string to measure
   Returns
   length of string.                             */
MEM_PROC  size_t MEM_API  StrLen ( CTEXTSTR s );
/* Get the length of a string in C chars.
   Parameters
   s :  char * to count.
   Returns
   the length of s. If s is NULL, return 0. */
MEM_PROC  size_t MEM_API  CStrLen ( char const*s );
/* Finds the last instance of a character in a string.
   Parameters
   s1 :  String to search in
   c :   character to find
   Returns
   NULL if character is not in the string.
   a pointer to the last character in s1 that matches c. */
MEM_PROC  CTEXTSTR MEM_API  StrRChr ( CTEXTSTR s1, TEXTCHAR c );
#ifdef __cplusplus
/* This searches a string for the first character that matches
   some specified character.
   A custom strchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This second flavor is only available on C++ where operator
   overloading will switch between CTEXTSTR and TEXTSTR
   \parameters, to result with the correct type. If a CTEXTSTR
   is passed to this it should result with a CTEXTSTR, but if
   that's the only choice, then the result of this is never
   modifiable, even if it is a pointer to a non-const TEXTSTR.  */
MEM_PROC  TEXTSTR MEM_API  StrChr ( TEXTSTR s1, TEXTCHAR c );
/* This searches a string for the last character that matches
   some specified character.
   A custom strrchr function, since microsoft is saying this is
   an unsafe function. This Compiles to compare native strings,
   if UNICODE uses unicode, otherwise uses 8 bit characters.
   Parameters
   s1 :  String to search
   c :   Character to find
   Returns
   pointer in string to search that is the first character that
   matches. NULL if no character matches.
   Note
   This second flavor is only available on C++ where operator
   overloading will switch between CTEXTSTR and TEXTSTR
   \parameters, to result with the correct type. If a CTEXTSTR
   is passed to this it should result with a CTEXTSTR, but if
   that's the only choice, then the result of this is never
   modifiable, even if it is a pointer to a non-const TEXTSTR.  */
MEM_PROC  TEXTSTR MEM_API  StrRChr ( TEXTSTR s1, TEXTCHAR c );
/* <combine sack::memory::StrCmp@CTEXTSTR@CTEXTSTR>
   \ \                                              */
MEM_PROC  int MEM_API  StrCmp ( const char * s1, CTEXTSTR s2 );
#endif
/* <combine sack::memory::StrCmp@char *@CTEXTSTR>
   \ \                                            */
MEM_PROC  int MEM_API  StrCmpEx ( CTEXTSTR s1, CTEXTSTR s2, INDEX maxlen );
/* Finds an instance of a string in another string.
   Custom implementation because strstr is declared unsafe, and
   to handle switching between unicode and char.
   Parameters
   s1 :  the string to search in
   s2 :  the string to locate
   Returns
   NULL if s2 is not in s1.
   The beginning of the string in s1 that matches s2.
   Example
   <code lang="c++">
   TEXTCHAR const *found = StrStr( WIDE( "look in this string" ), WIDE( "in" ) );
                                               ^returns a pointer to here.
   </code>                                                                        */
MEM_PROC  CTEXTSTR MEM_API  StrStr ( CTEXTSTR s1, CTEXTSTR s2 );
#ifdef __cplusplus
/* Finds an instance of a string in another string.
   Custom implementation because strstr is declared unsafe, and
   to handle switching between unicode and char.
   Parameters
   s1 :  the string to search in
   s2 :  the string to locate
   Returns
   NULL if s2 is not in s1.
   The beginning of the string in s1 that matches s2.
   Example
   <code>
   TEXTCHAR *writable_string = StrDup( WIDE( "look in this string" ) );
   TEXTCHAR *found = StrStr( writable_string, WIDE( "in" ) );
   // returns a pointer to 'in' in the writable string, which can then be modified.
   </code>                                                                          */
MEM_PROC  TEXTSTR MEM_API  StrStr ( TEXTSTR s1, CTEXTSTR s2 );
#endif
/* Searches for one string in another. Compares case
   insensitively.
   Parameters
   s1 :  string to search in
   s2 :  string to locate
   See Also
   <link sack::memory::StrStr@CTEXTSTR@CTEXTSTR, StrStr> */
MEM_PROC  CTEXTSTR MEM_API  StrCaseStr ( CTEXTSTR s1, CTEXTSTR s2 );
/* This duplicates a block of memory.
   Parameters
   p :  pointer to a block of memory that was allocated.
   Returns
   a pointer to a new block of memory that has the same content
   as the original.                                             */
MEM_PROC  POINTER MEM_API  MemDupEx ( CPOINTER thing DBG_PASS );
/* <combine sack::memory::MemDupEx@CPOINTER thing>
   \ \                                             */
#define MemDup(thing) MemDupEx(thing DBG_SRC )
/* Duplicates a string, and returns a pointer to the copy.
   Parameters
   original :  string to duplicate                         */
MEM_PROC  TEXTSTR MEM_API  StrDupEx ( CTEXTSTR original DBG_PASS );
/* Translates from a TEXTCHAR string to a char string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  char *  MEM_API  CStrDupEx ( CTEXTSTR original DBG_PASS );
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  wchar_t *  MEM_API  DupTextToWideEx( CTEXTSTR original DBG_PASS );
#define DupTextToWide(s) DupTextToWideEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC  char *     MEM_API  DupTextToCharEx( CTEXTSTR original DBG_PASS );
#define DupTextToChar(s) DupTextToCharEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC TEXTSTR     MEM_API  DupWideToTextEx( const wchar_t *original DBG_PASS );
#define DupWideToText(s) DupWideToTextEx( s DBG_SRC )
/* Translates from a TEXTCHAR string to a wchar_t string. Probably
   only for UNICODE to non wide translation points.
   Parameters
   original :  string to duplicate                              */
MEM_PROC TEXTSTR     MEM_API  DupCharToTextEx( const char *original DBG_PASS );
#define DupCharToText(s) DupCharToTextEx( s DBG_SRC )
/* Converts from 8 bit char to 16 bit wchar (or no-op if not
   UNICODE compiled)
   Parameters
   original :  original string of C char.
   Returns
   a pointer to a wide character string.                     */
MEM_PROC  TEXTSTR MEM_API  DupCStrEx ( const char * original DBG_PASS );
/* Converts from 8 bit char to 16 bit wchar (or no-op if not
UNICODE compiled)
Parameters
original :  original string of C char.
Returns
a pointer to a wide character string.                     */
MEM_PROC  TEXTSTR MEM_API  DupCStrLenEx( const char * original, size_t chars DBG_PASS );
/* <combine sack::memory::StrDupEx@CTEXTSTR original>
   \ \                                                */
#define StrDup(o) StrDupEx( (o) DBG_SRC )
/* <combine sack::memory::CStrDupEx@CTEXTSTR original>
   \ \                                                 */
#define CStrDup(o) CStrDupEx( (o) DBG_SRC )
/* <combine sack::memory::DupCStrEx@char * original>
   \ \                                               */
#define DupCStr(o) DupCStrEx( (o) DBG_SRC )
/* <combine sack::memory::DupCStrLenEx@char * original@size_t chars>
   \ \                                               */
#define DupCStrLen(o,l) DupCStrLenEx( (o),(l) DBG_SRC )
//------------------------------------------------------------------------
#if 0
// this code was going to provide network oriented shared memory.
#ifndef TRANSPORT_STRUCTURE_DEFINED
typedef uintptr_t PTRANSPORT_QUEUE;
struct transport_queue_tag { uint8_t private_data_here; };
#endif
MEM_PROC  struct transport_queue_tag * MEM_API  CreateQueue ( int size );
MEM_PROC  int MEM_API  EnqueMessage ( struct transport_queue_tag *queue, POINTER msg, int size );
MEM_PROC  int MEM_API  DequeMessage ( struct transport_queue_tag *queue, POINTER msg, int *size );
MEM_PROC  int MEM_API  PequeMessage ( struct transport_queue_tag *queue, POINTER *msg, int *size );
#endif
//------------------------------------------------------------------------
#ifdef __cplusplus
 // namespace memory
};
 // namespace sack
};
using namespace sack::memory;
#if defined( _DEBUG ) || defined( _DEBUG_INFO )
/*
inline void operator delete( void * p )
{ Release( p ); }
#ifdef DELETE_HANDLES_OPTIONAL_ARGS
inline void operator delete (void * p DBG_PASS )
{ ReleaseEx( p DBG_RELAY ); }
#define delete delete( DBG_VOIDSRC )
#endif
//#define deleteEx(file,line) delete(file,line)
#ifdef USE_SACK_ALLOCER
inline void * operator new( size_t size DBG_PASS )
{ return AllocateEx( (uintptr_t)size DBG_RELAY ); }
static void * operator new[]( size_t size DBG_PASS )
{ return AllocateEx( (uintptr_t)size DBG_RELAY ); }
#define new new( DBG_VOIDSRC )
#define newEx(file,line) new(file,line)
#endif
*/
// common names - sometimes in conflict when declaring
// other functions... AND - release is a common
// component of iComObject
//#undef Allocate
//#undef Release
// Hmm wonder where this conflicted....
//#undef LineDuplicate
#else
#ifdef USE_SACK_ALLOCER
inline void * operator new(size_t size)
{ return AllocateEx( size ); }
inline void operator delete (void * p)
{ ReleaseEx( p ); }
#endif
#endif
#endif
#endif
#ifndef _TIMER_NAMESPACE
#ifdef __cplusplus
#define _TIMER_NAMESPACE namespace timers {
/* define a timer library namespace in C++. */
#define TIMER_NAMESPACE SACK_NAMESPACE namespace timers {
/* define a timer library namespace in C++ end. */
#define TIMER_NAMESPACE_END } SACK_NAMESPACE_END
#else
#define _TIMER_NAMESPACE
#define TIMER_NAMESPACE
#define TIMER_NAMESPACE_END
#endif
#endif
// this is a method replacement to use PIPEs instead of SEMAPHORES
// replacement code only affects linux.
#if defined( __QNX__ ) || defined( __MAC__) || defined( __LINUX__ ) || defined( __ANDROID__ )
#  define USE_PIPE_SEMS
// no semtimedop; no semctl, etc
//#include <sys/sem.h>
#endif
#ifdef USE_PIPE_SEMS
#  define _NO_SEMTIMEDOP_
#endif
SACK_NAMESPACE
/* This namespace contains methods for working with timers and
   threads. Since timers are implemented in an asynchronous
   thread, the thread creation and control can be exposed here
   also.
   ThreadTo
   WakeThread
   WakeableSleep [Example]
   AddTimer
   RemoveTimer
   RescheduleTimer
   EnterCriticalSec see Also
 EnterCriticalSecNoWait
   LeaveCriticalSec                                            */
_TIMER_NAMESPACE
#ifdef TIMER_SOURCE
#define TIMER_PROC(type,name) EXPORT_METHOD type CPROC name
#else
/* Defines import export and call method for timers. Looks like
   timers are native calltype by default instead of CPROC.      */
#define TIMER_PROC(type,name) IMPORT_METHOD type CPROC name
#endif
#if defined( __LINUX__ ) || defined( __ANDROID__ )
TIMER_PROC( uint32_t, timeGetTime )( void );
TIMER_PROC( uint32_t, GetTickCount )( void );
TIMER_PROC( void, Sleep )( uint32_t ms );
#endif
/* Function signature for user callbacks passed to AddTimer. */
typedef void (CPROC *TimerCallbackProc)( uintptr_t psv );
/* Adds a new periodic timer. From now, until the timer is
   removed with RemoveTimer, it will call the timer procedure at
   the specified frequency of milliseconds. The delay until the
   first time the timer fires can be specified independant of
   frequency. If it is not specified, the first time the timer
   will get invoked is at +1 frequency from now.
   Parameters
   start :      how long in milliseconds until the timer starts. Can
                be 0 and timer will fire at the next opportunity.
   frequency :  how long the delay is between event invocations,
                in milliseconds.
   callback :   user routine to call when the timer's delay
                expires.
   user :       user data to pass to the callback when it is
                invoked.
   Returns
   a 32 bit ID that identifies the timer for this application.
   Example
   First some setup valid for all timer creations...
   <code lang="c++">
   void CPROC TimerProc( uintptr_t user_data )
   {
       // user_data of the timer is the 'user' parameter passed to AddTimer(Exx)
   }
   </code>
   you might want to save this for something like
   RescheduleTimer
   <code>
   uint32_t timer_id;
   </code>
   Create a simple timer, it will fire at 250 milliseconds from
   now, and again every 250 milliseconds from the time it
   starts.
   <code lang="c++">
   timer_id = AddTimer( 250, TimerProc, 0 );
   </code>
   Create a timer that fires immediately, and 732 milliseconds
   after, passing some value 1234 as user data...
   <code lang="c++">
   timer_id = AddTimerEx( 0, 732, TimerProc, 1234 );
	</code>
	Remarks
	if a timer is dispatched and needs to wait - please link with idlelib, and call Idle.
	this will allow other timers to fire on schedule.  The timer that is waiting is not
	in the list of timers to process.
	*/
TIMER_PROC( uint32_t, AddTimerExx )( uint32_t start, uint32_t frequency
					, TimerCallbackProc callback
					, uintptr_t user DBG_PASS);
/* <combine sack::timers::AddTimerExx@uint32_t@uint32_t@TimerCallbackProc@uintptr_t user>
   \ \                                                                         */
#define AddTimerEx( s,f,c,u ) AddTimerExx( (s),(f),(c),(u) DBG_SRC )
/* <combine sack::timers::AddTimerExx@uint32_t@uint32_t@TimerCallbackProc@uintptr_t user>
   \ \                                                                         */
#define AddTimer( f, c, u ) AddTimerExx( (f), (f), (c), (u) DBG_SRC)
/* Stops a timer. The next time this timer would run, it will be
   removed. If it is currently dispatched, it is safe to remove
   from within the timer itself.
   Parameters
   timer :  32 bit timer ID from AddTimer.                       */
TIMER_PROC( void, RemoveTimer )( uint32_t timer );
/* Reschedule when a timer can fire. The delay can be 0 to make
   wake the timer.
   Parameters
   timer :  32 bit timer identifier from AddTimer.
   delay :  How long before the timer should run now.<p />If 0,
            will issue timer immediately.<p />If not specified,
            using the macro, the default delay is the timer's
            frequency. (can prevent the timer from firing until
            it's frequency from now.)                           */
TIMER_PROC( void, RescheduleTimerEx )( uint32_t timer, uint32_t delay );
/* <combine sack::timers::RescheduleTimerEx@uint32_t@uint32_t>
   \ \                                               */
TIMER_PROC( void, RescheduleTimer )( uint32_t timer );
/* Changes the frequency of a timer. Reschedule timer only
   changes the next time it fires, this can adjust the
   frequency. The simple ChangeTimer macro is sufficient.
   Parameters
   ID :         32 bit ID of the time created by AddTimer.
   initial :    initial delay of the timer. (Might matter if the
                timer hasn't fired the first time)
   frequency :  new delay between timer callback invokations.    */
TIMER_PROC( void, ChangeTimerEx )( uint32_t ID, uint32_t initial, uint32_t frequency );
/* <combine sack::timers::ChangeTimerEx@uint32_t@uint32_t@uint32_t>
   \ \                                               */
#define ChangeTimer( ID, Freq ) ChangeTimerEx( ID, Freq, Freq )
/* This is the type returned by MakeThread, and passed to
   ThreadTo. This is a private structure, and no definition is
   publicly available, this should be treated like a handle.   */
typedef struct threads_tag *PTHREAD;
/* Function signature for a thread entry point passed to
   ThreadTo.                                             */
typedef uintptr_t (CPROC*ThreadStartProc)( PTHREAD );
/* Function signature for a thread entry point passed to
   ThreadToSimple.                                             */
typedef uintptr_t (*ThreadSimpleStartProc)( POINTER );
/* Create a separate thread that starts in the routine
   specified. The uintptr_t value (something that might be a
   pointer), is passed in the PTHREAD structure. (See
   GetThreadParam)
   Parameters
   proc :       starting routine for the thread
   user_data :  some value that can be stored in the number of
                bits that a pointer is. This is passed to the
                proc when the thread starts.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( PTHREAD, ThreadToEx )( ThreadStartProc proc, uintptr_t param DBG_PASS );
/* <combine sack::timers::ThreadToEx@ThreadStartProc@uintptr_t param>
   \ \                                                               */
#define ThreadTo(proc,param) ThreadToEx( proc,param DBG_SRC )
/* Create a separate thread that starts in the routine
   specified. The uintptr_t value (something that might be a
   pointer), is passed in the PTHREAD structure. (See
   GetThreadParam)
   Parameters
   proc :       starting routine for the thread
   user_data :  some value that can be stored in the number of
                bits that a pointer is. This is passed to the
                proc when the thread starts.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( PTHREAD, ThreadToSimpleEx )( ThreadSimpleStartProc proc, POINTER param DBG_PASS );
/* <combine sack::timers::ThreadToEx@ThreadStartProc@uintptr_t param>
   \ \                                                               */
#define ThreadToSimple(proc,param) ThreadToSimpleEx( proc,param DBG_SRC )
/* \Returns a PTHREAD that represents the current thread. This
   can be used to create a PTHREAD identifier for the main
   thread.
   Parameters
   None.
   Returns
   a pointer to a thread structure that identifies the current
   thread. If this thread already has this structure created,
   the same one results on subsequent MakeThread calls.        */
TIMER_PROC( PTHREAD, MakeThread )( void );
/* Releases resources associated with a PTHREAD. For purposes of
   waking a thread, and providing a wakeable point for the
   thread, a system blocking event object is allocated, named
   with the THREAD_ID so it can be referenced by other
   processes. This is only allowed to be done by the thread
   itself.
   Parameters
   Param1 :  \Description
   Param2 :  \Description
   Example
   <code lang="c++">
   int main( void )
   {
       PTHREAD myself = MakeThread();
       // create threads, do stuff...
       UnmakeThread();
       At this point the pointer in 'myself' is invalid, and should be cleared.
       myself = NULL;
   }
   </code>                                                                      */
TIMER_PROC( void, UnmakeThread )( void );
/* This returns the parameter passed as user data to ThreadTo.
   Parameters
   thread :  thread to get the parameter from.
   Example
   See WakeableSleepEx.                                        */
TIMER_PROC( uintptr_t, GetThreadParam )( PTHREAD thread );
/* \returns the numeric THREAD_ID from a PTHREAD.
   Parameters
   thread :  thread to get the system wide unique ID of. */
TIMER_PROC( THREAD_ID, GetThreadID )( PTHREAD thread );
/* \returns the numeric THREAD_ID from a PTHREAD.
   Parameters
   thread :  thread to get the system wide unique ID of. */
TIMER_PROC( THREAD_ID, GetThisThreadID )( void );
/* Symbol defined to pass to Wakeable_Sleep to sleep until
   someone calls WakeThread.                               */
#define SLEEP_FOREVER 0xFFFFFFFF
/* Sleeps a number of milliseconds or until the thread is passed
   to WakeThread.
   Parameters
   dwMilliseconds :  How long to sleep. Can be indefinite if
                     value is SLEEP_FOREVER.
   Example
   <code lang="c++">
   PTHREAD main_thread;
   uintptr_t CPROC WakeMeThread( PTHREAD thread )
   {
      // get the value passed to ThreadTo as user_data.
      uintptr_t user_data = GetThreadParam( thread );
      // let the main thread sleep a little wile
       WakeableSleep( 250 );
      // then wake it up
       WakeThread( main_thread );
       return 0;
   }
   int main( void )
   {
       // save my PTHREAD globally.
       main_thread = MakeThread();
       // create a thread that can wake us
       ThreadTo( WakeMeThread, 0 );
       // demonstrate sleeping
       WakableSleep( SLEEP_FOREVER );
       return 0;
   }
   </code>                                                       */
TIMER_PROC( void, WakeableSleepEx )( uint32_t milliseconds DBG_PASS );
TIMER_PROC( void, WakeableSleep )( uint32_t milliseconds );
TIMER_PROC( void, WakeableNamedSleepEx )( CTEXTSTR name, uint32_t n DBG_PASS );
#define WakeableNamedSleep( name, n )   WakeableNamedSleepEx( name, n DBG_SRC )
TIMER_PROC( void, WakeNamedSleeperEx )( CTEXTSTR name DBG_PASS );
#define WakeNamedSleeper( name )   WakeNamedSleeperEx( name DBG_SRC )
TIMER_PROC( void, WakeableNamedThreadSleepEx )( CTEXTSTR name, uint32_t n DBG_PASS );
#define WakeableNamedThreadSleep( name, n )   WakeableNamedThreadSleepEx( name, n DBG_SRC )
TIMER_PROC( void, WakeNamedThreadSleeperEx )( CTEXTSTR name, THREAD_ID therad DBG_PASS );
#define WakeNamedThreadSleeper( name, thread )   WakeNamedThreadSleeperEx( name, thread DBG_SRC )
#ifdef USE_PIPE_SEMS
TIMER_PROC( int, GetThreadSleeper )( PTHREAD thread );
#endif
/* <combine sack::timers::WakeableSleepEx@uint32_t milliseconds>
   \ \                                                      */
#define WakeableSleep(n) WakeableSleepEx(n DBG_SRC )
/* Wake a thread by ID, if the pThread is not available. Can be
   used cross-process for instance. Although someone could add a
   method to provide a PTHREAD wrapper around THREAD_ID for
   threads in remote processes, this may not be a best practice.
   Parameters
   thread_id :  THREAD_ID from GetMyThreadID, which is a macro
                appropriate for a platform.                      */
TIMER_PROC( void, WakeThreadIDEx )( THREAD_ID thread DBG_PASS );
/* Wake a thread.
   Example
   See WakeableSleepEx.
   Parameters
   pThread :  thread to wake up from a WakeableSleep. */
TIMER_PROC( void, WakeThreadEx )( PTHREAD thread DBG_PASS );
/* <combine sack::timers::WakeThreadIDEx@THREAD_ID thread>
   \ \                                                     */
#define WakeThreadID(thread) WakeThreadIDEx( thread DBG_SRC )
/* <combine sack::timers::WakeThreadEx@PTHREAD thread>
   \ \                                                 */
#define WakeThread(t) WakeThreadEx(t DBG_SRC )
/* This can be checked to see if the THREAD_ID to wake still has
   an event. Sometimes threads end.
   Parameters
   thread :  thread identifier to check to see if it exists/can be
             woken.
   Returns
   TRUE if the thread can be signaled to wake up.
   FALSE if the thread cannot be found or cannot be woken up.      */
TIMER_PROC( int, TestWakeThreadID )( THREAD_ID thread );
/* This can be checked to see if the PTHREAD to wake still has
   an event. Sometimes threads call UnmakeThread(). This is a
   more practical test using a THREAD_ID instead. See
   TestWakeThreadID.
   Returns
   TRUE if the thread can be signaled to wake up.
   FALSE if the thread cannot be found or cannot be woken up.  */
TIMER_PROC( int, TestWakeThread )( PTHREAD thread );
//TIMER_PROC( void, WakeThread )( PTHREAD thread );
TIMER_PROC( void, EndThread )( PTHREAD thread );
/* This tests to see if a pointer to a thread references the
   current thread.
   Parameters
   thread :  thread to check to see if it is the current thread.
   Returns
   TRUE if this thread is the same as the PTHREAD passed.
   otherwise FALSE.
   Example
   <code lang="c++">
   PTHREAD main_thread;
   LOGICAL thread_finished_check;
   uintptr_t CPROC ThreadProc( PTHREAD thread )
   {
       if( IsThisThread( main_thread ) )
            printf( "This thread is not the main thread.\\n" );
       else
            printf( "This is the main thread - cannot happen :)\\n" );
   </code>
   <code>
       // mark that this thread is complete
       thread_finished_check = TRUE;
   </code>
   <code lang="c++">
       // hmm - for some reason, just pass the uintptr_t that was passed to ThreadTo as the result.
       return GetThreadParam( thread );
   }
   int main( void )
   {
        main_thread = MakeThread();
        ThreadTo( ThreadProc, 0 );
        // wait for the thread to finish its thread identity check.
        while( !thread_finished_check )
            Relinquish();
        return 0;
   }
   </code>                                                                                         */
TIMER_PROC( int, IsThisThreadEx )( PTHREAD pThreadTest DBG_PASS );
/* <combine sack::timers::IsThisThreadEx@PTHREAD pThreadTest>
   \ \                                                        */
#define IsThisThread(thread) IsThisThreadEx(thread DBG_SRC)
/* Enter a critical section. Only a single thread may be in a
   critical section, if a second thread attempts to enter the
   section while another thread is in it will block until the
   original thread leaves the section. The same thread may enter
   a critical section multiple times. For each time a critical
   section is entered, the thread must also leave the critical
   section (See LeaveCriticalSection).
   Parameters
   pcs :  pointer to a critical section to enter                 */
TIMER_PROC( LOGICAL, EnterCriticalSecEx )( PCRITICALSECTION pcs DBG_PASS );
/* Leaves a critical section. See EnterCriticalSecEx.
   Parameters
   pcs :  pointer to a critical section.              */
TIMER_PROC( LOGICAL, LeaveCriticalSecEx )( PCRITICALSECTION pcs DBG_PASS );
/* Does nothing. There are no extra resources required for
   critical sections, and the memory is allocated by the
   application.
   Parameters
   pcs :  pointer to critical section to do nothing with.  */
TIMER_PROC( void, DeleteCriticalSec )( PCRITICALSECTION pcs );
#ifdef _WIN32
	TIMER_PROC( HANDLE, GetWakeEvent )( void );
	TIMER_PROC( HANDLE, GetThreadHandle )( PTHREAD thread );
#endif
#ifdef __LINUX__
	TIMER_PROC( pthread_t, GetThreadHandle )(PTHREAD thread);
#endif
#ifdef USE_NATIVE_CRITICAL_SECTION
#define EnterCriticalSec(pcs) EnterCriticalSection( pcs )
#define LeaveCriticalSec(pcs) LeaveCriticalSection( pcs )
#else
/* <combine sack::timers::EnterCriticalSecEx@PCRITICALSECTION pcs>
   \ \                                                             */
#define EnterCriticalSec( pcs ) EnterCriticalSecEx( (pcs) DBG_SRC )
/* <combine sack::timers::LeaveCriticalSecEx@PCRITICALSECTION pcs>
   \ \                                                             */
#define LeaveCriticalSec( pcs ) LeaveCriticalSecEx( (pcs) DBG_SRC )
#endif
TIMER_NAMESPACE_END
#ifdef __cplusplus
using namespace sack::timers;
#endif
#endif
// $Log: timers.h,v $
// Revision 1.37  2005/05/16 19:06:58  jim
// Extend wakeable sleep to know the originator of the sleep.
//
// Revision 1.36  2004/09/29 16:42:51  d3x0r
// fixed queues a bit - added a test wait function for timers/threads
//
// Revision 1.35  2004/07/07 15:33:54  d3x0r
// Cleaned c++ warnings, bad headers, fixed make system, fixed reallocate...
//
// Revision 1.34  2004/05/02 02:04:16  d3x0r
// Begin border exclusive option, define PushMethod explicitly, fix LaunchProgram in timers.h
//
// Revision 1.33  2003/12/10 15:38:25  panther
// Move Sleep and GetTickCount to real code
//
// Revision 1.32  2003/11/02 00:31:47  panther
// Added debuginfo pass to wakethread
//
// Revision 1.31  2003/10/24 14:59:21  panther
// Added Load/Unload Function for system shared library abstraction
//
// Revision 1.30  2003/10/17 00:56:04  panther
// Rework critical sections.
// Moved most of heart of these sections to timers.
// When waiting, sleep forever is used, waking only when
// released... This is preferred rather than continuous
// polling of section with a Relinquish.
// Things to test, event wakeup order uner linxu and windows.
// Even see if the wake ever happens.
// Wake should be able to occur across processes.
// Also begin implmeenting MessageQueue in containers....
// These work out of a common shared memory so multiple
// processes have access to this region.
//
// Revision 1.29  2003/09/21 04:03:30  panther
// Build thread ID with pthread_self and getgid
//
// Revision 1.28  2003/07/29 10:41:25  panther
// Predefine struct threads_tag to avoid warning
//
// Revision 1.27  2003/07/24 22:49:20  panther
// Define callback procs as CDECL
//
// Revision 1.26  2003/07/24 16:56:41  panther
// Updates to expliclity define C procedure model for callbacks and assembly modules - incomplete
//
// Revision 1.25  2003/07/22 15:33:19  panther
// Added comment about idle()
//
// Revision 1.24  2003/04/03 10:10:20  panther
// Add file/line debugging to addtimer
//
// Revision 1.23  2003/03/27 13:47:14  panther
// Immplement a EndThread
//
// Revision 1.22  2003/03/25 08:38:11  panther
// Add logging
//
#ifndef MAXPATH
// windef.h has MAX_PATH
#  define MAXPATH MAX_PATH
#  if (!MAXPATH)
#    undef MAXPATH
#    define MAXPATH 256
#  endif
#endif
#ifndef PATH_MAX
// sometimes PATH_MAX is what's used, well it's should be MAXPATH which is MAX_PATH
# define PATH_MAX MAXPATH
#endif
#ifdef _UNICODE
#  ifdef _WIN32
#    ifdef CONSOLE_SHELL
    // in order to get wide characters from the commandline we have to use the GetCommandLineW function, convert it to utf8 for internal usage.
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { char *tmp; TEXTCHAR **b; ParseIntoArgs( GetCommandLineW(), &a, &b ); Deallocate( char*, tmp ); {
	//int n; TEXTCHAR **b; b = NewArray( TEXTSTR, a + 1 ); for( n = 0; n < a; n++ ) b[n] = DupCharToText( argv_real[n] ); b[n] = NULL; {
#      define EndSaneWinMain() } }
#    else
#      define SaneWinMain(a,b) int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow ) { char *tmp; int a; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); Deallocate( char*, tmp ); {
#      define EndSaneWinMain() } }
#    endif
#  else
#    if defined( __ANDROID__ ) && !defined( ANDROID_CONSOLE_UTIL )
#      define SaneWinMain(a,b) int SACK_Main( int a, char **b )
#      define EndSaneWinMain()
#    else
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { int n; TEXTCHAR **b; b = NewArray( TEXTSTR, a + 1 ); for( n = 0; n < a; n++ ) b[n] = DupCharToText( argv_real[n] ); b[n] = NULL; {
#      define EndSaneWinMain() } }
#    endif
#  endif
#else
#  ifdef _WIN32
#    ifdef CONSOLE_SHELL
// in order to get wide characters from the commandline we have to use the GetCommandLineW function, convert it to utf8 for internal usage.
#      define SaneWinMain(a,b) int main( int a, char **argv_real ) { char *tmp; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); Deallocate( char*, tmp ); {
#      define EndSaneWinMain() } }
#    else
#      define SaneWinMain(a,b) int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow ) { int a; char *tmp; TEXTCHAR **b; ParseIntoArgs( tmp = WcharConvert( GetCommandLineW() ), &a, &b ); {
#      define EndSaneWinMain() } }
#    endif
#  else
#    if defined( __ANDROID__ ) && !defined( ANDROID_CONSOLE_UTIL )
#      define SaneWinMain(a,b) int SACK_Main( int a, char **b )
#      define EndSaneWinMain()
#    else
#      define SaneWinMain(a,b) int main( int a, char **b ) { char **argv_real = b; {
#      define EndSaneWinMain() } }
#    endif
#  endif
#endif
//  these are rude defines overloading otherwise very practical types
// but - they have to be dispatched after all standard headers.
#ifndef FINAL_TYPES
#define FINAL_TYPES
#  ifdef __WATCOMC__
 //__WATCOMC__
#  endif
#  ifdef _WIN32
#    include <basetsd.h>
  // this redefines lprintf sprintf etc... and strsafe is preferred
 // more things that need override by strsafe.h
#    include <tchar.h>
 // added for mingw64 actually
#    ifdef __GNUC__
#      undef __CRT__NO_INLINE
#    endif
#    ifndef MINGW_SUX
#      include <strsafe.h>
#    else
#      define STRSAFE_E_INSUFFICIENT_BUFFER  0x8007007AL
#    endif
#  else
#  endif
// may consider changing this to uint16_t* for unicode...
#ifdef UNICODE
#  ifndef NO_UNICODE_C
#    define strrchr          wcsrchr
#    define strchr           wcschr
#    define strncpy          wcsncpy
#    ifdef strcpy
#      undef strcpy
#    endif
#    define strcpy           wcscpy
#    define strcmp           wcscmp
#    ifndef __LINUX__
// linux also translates 'i' to 'case' in sack_typelib.h
#      define stricmp          wcsicmp
#      define strnicmp         wcsnicmp
//#  define strlen           mbrlen
#    endif
#    define strlen           wcslen
#    ifdef WIN32
#      define stat(a,b)        _wstat(a,b)
#    else
#    endif
#    define printf           wprintf
#    define fprintf          fwprintf
#    define fputs            fputws
#    define fgets            fgetws
#    define atoi             _wtoi
#    ifdef __WATCOMC__
#      undef atof
#    endif
//#    define atof             _wtof
#    ifdef _MSC_VER
#      ifndef __cplusplus_cli
#        define fprintf   fwprintf
#        define atoi      _wtoi
// define sprintf here.
#      endif
#    endif
#    if defined( _ARM_ ) && defined( WIN32 )
// len should be passed as character count. this was the wrongw ay to default this.
#      define snprintf StringCbPrintf
//#define snprintf StringCbPrintf
#    endif
#  else
//#    define atoi             wtoi
#  endif
 // not unicode...
#else
#endif
#  ifdef _MSC_VER
#    define SUFFER_WITH_NO_SNPRINTF
#    ifndef SUFFER_WITH_NO_SNPRINTF
#      define vnsprintf protable_vsnprintf
//   this one gives deprication warnings
//   #    define vsnprintf _vsnprintf
//   this one doesn't work to measure strings
//   #    define vsnprintf(buf,len,format,args) _vsnprintf_s(buf,len,(len)/sizeof(TEXTCHAR),format,args)
//   this one doesn't macro well, and doesnt' measure strings
//  (SUCCEEDED(StringCbVPrintf( buf, len, format, args ))?StrLen(buf):-1)
#      define snprintf portable_snprintf
//   this one gives deprication warnings
//   #    define snprintf _snprintf
//   this one doesn't work to measure strings
//   #    define snprintf(buf,len,format,...) _snprintf_s(buf,len,(len)/sizeof(TEXTCHAR),format,##__VA_ARGS__)
//   this one doesn't macro well, and doesnt' measure strings
//   (SUCCEEDED(StringCbPrintf( buf, len, format,##__VA_ARGS__ ))?StrLen(buf):-1)
// make sure this is off, cause we really don't, and have to include the following
#      undef HAVE_SNPRINTF
 // define this anyhow so we can avoid name collisions
#      define PREFER_PORTABLE_SNPRINTF
#      ifdef SACK_CORE_BUILD
#        include <../src/snprintf_2.2/snprintf.h>
#      else
#        include <snprintf-2.2/snprintf.h>
 // SACK_CORE_BUILD
#      endif
 // SUFFER_WITH_WARNININGS
#    else
#      define snprintf _snprintf
#      define vsnprintf _vsnprintf
#      if defined( _UNICODE )
#        define tnprintf _snwprintf
#        define vtnprintf _vsnwprintf
#      else
#        define tnprintf _snprintf
#        define vtnprintf _vsnprintf
#      endif
#    define snwprintf _snwprintf
// suffer_with_warnings
#    endif
#    if defined( _UNICODE ) && !defined( NO_UNICODE_C )
#    define tscanf swscanf_s
#    else
#    define tscanf sscanf_s
#    endif
#    define scanf sscanf_s
#    define swcanf swscanf_s
 // _MSC_VER
#  endif
#  ifdef  __GNUC__
#      if defined( _UNICODE )
#        define VSNPRINTF_FAILS_RETURN_SIZE
#        define tnprintf  swprintf
#        define vtnprintf vswprintf
#        if !defined( NO_UNICODE_C )
#           define snprintf   swprintf
#           define vsnprintf  vswprintf
//#           define sscanf     swscanf
#        else
#        endif
#      else
#        define tnprintf snprintf
#        define vtnprintf vsnprintf
//#        define snprintf snprintf
//#        define vsnprintf vsnprintf
#    if defined( _UNICODE ) && !defined( NO_UNICODE_C )
#    define tscanf swscanf
#    else
#    define tscanf sscanf
#    endif
#      endif
 // __GNUC__
#  endif
#  ifdef __WATCOMC__
#      if defined( _UNICODE )
#        define tnprintf  _snwprintf
#        define vtnprintf _vsnwprintf
#        if !defined( NO_UNICODE_C )
#           define snprintf  _snwprintf
#           define vsnprintf _vsnwprintf
#           define sscanf     swscanf
#        else
#        endif
#      else
#         define tnprintf  snprintf
#         define vtnprintf vsnprintf
//#        define snprintf snprintf
//#        define vsnprintf vsnprintf
#      endif
#        define snwprintf  _snwprintf
 // __WATCOMC__
#  endif
#endif
#endif
#ifdef __cplusplus
SACK_NAMESPACE namespace network {
	namespace jsox {
#endif
#ifdef JSOX_PARSER_SOURCE
#  define JSOX_PARSER_PROC(type,name) EXPORT_METHOD type name
#else
#  define JSOX_PARSER_PROC(type,name) IMPORT_METHOD type name
#endif
enum jsox_value_types {
	JSOX_VALUE_UNDEFINED = -1
	, JSOX_VALUE_UNSET = 0
 //= 1 no data
	, JSOX_VALUE_NULL
 //= 2 no data
	, JSOX_VALUE_TRUE
 //= 3 no data
	, JSOX_VALUE_FALSE
 //= 4 string
	, JSOX_VALUE_STRING
 //= 5 string + result_d | result_n
	, JSOX_VALUE_NUMBER
 //= 6 contains
	, JSOX_VALUE_OBJECT
 //= 7 contains
	, JSOX_VALUE_ARRAY
	// up to here is supported in JSON
 //= 8 no data
	, JSOX_VALUE_NEG_NAN
 //= 9 no data
	, JSOX_VALUE_NAN
 //= 10 no data
	, JSOX_VALUE_NEG_INFINITY
 //= 11 no data
	, JSOX_VALUE_INFINITY
  // = 12 comes in as a number, string is data.
	, JSOX_VALUE_DATE
 // = 13 string data, needs bigint library to process...
	, JSOX_VALUE_BIGINT
 // = 14 no data; used in [,,,] as place holder of empty
	, JSOX_VALUE_EMPTY
  // = 15 string is base64 encoding of bytes.
	, JSOX_VALUE_TYPED_ARRAY
  // = 14 string is base64 encoding of bytes.
	, JSOX_VALUE_TYPED_ARRAY_MAX = JSOX_VALUE_TYPED_ARRAY +12
};
struct jsox_value_container {
  // name of this value (if it's contained in an object)
	char * name;
	size_t nameLen;
 // value from above indiciating the type of this value
	enum jsox_value_types value_type;
   // the string value of this value (strings and number types only)
	char *string;
	size_t stringLen;
  // boolean whether to use result_n or result_d
	int float_result;
	union {
		double result_d;
		int64_t result_n;
		//struct json_value_container *nextToken;
	};
  // list of struct json_value_container that this contains.
	PDATALIST contains;
  // acutal source datalist(?)
	PDATALIST *_contains;
  // if VALUE_OBJECT or VALUE_TYPED_ARRAY; this may be non NULL indicating what the class name is.
	char *className;
};
// allocates a JSOX parsing context and is prepared to begin parsing data.
JSOX_PARSER_PROC( struct jsox_parse_state *, jsox_begin_parse )(void);
// clear state; after an error state, this can allow reusing a state.
JSOX_PARSER_PROC( void, jsox_parse_clear_state )( struct jsox_parse_state *state );
// destroy current parse state.
JSOX_PARSER_PROC( void, jsox_parse_dispose_state )(struct jsox_parse_state **ppState);
// return >0 when a completed value/object is available.
// after returning >0, call json_parse_get_data.  It is possible that there is
// still unconsumed data that can begin a new object.  Call this with NULL, 0 for data
// to consume this internal data.  if this returns 0, then ther is no further object
// to retrieve.  If this return -1 there was an error, and use jsox_parse_get_error() to
// retrieve the error text.
JSOX_PARSER_PROC( int, jsox_parse_add_data )(struct jsox_parse_state *context
	, const char * msg
	, size_t msglen
	);
JSOX_PARSER_PROC( PTEXT, jsox_parse_get_error )(struct jsox_parse_state *state);
JSOX_PARSER_PROC( PDATALIST, jsox_parse_get_data )(struct jsox_parse_state *context);
// single all-in-one parsing of an input buffer.
JSOX_PARSER_PROC( LOGICAL, jsox_parse_message )(const char * msg
	, size_t msglen
	, PDATALIST *msg_data_out
	);
// release all resources of a message from jsox_parse_message or jsox_parse_get_data
JSOX_PARSER_PROC( void, jsox_dispose_message )(PDATALIST *msg_data);
JSOX_PARSER_PROC( char *, jsox_escape_string_length )(const char *string, size_t len, size_t *outlen);
JSOX_PARSER_PROC( char *, jsox_escape_string )(const char *string);
#ifdef __cplusplus
} } SACK_NAMESPACE_END
using namespace sack::network::jsox;
#endif
#endif
