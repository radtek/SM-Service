// ------------------------------------- //
// 您如果要使用本文件，请不要删除本说明  //
// ------------------------------------- //
//             HOOKAPI v1.0              //
//   Copyright 2002 编程沙龙 Paladin     //
//       www.ProgramSalon.com            //
// ------------------------------------- //

#ifndef __HookAPI_H__
#define __HookAPI_H__

#include <windows.h>
#include "mydll.h"
#include "apiinfo.h"

#define MsgBox(msg) MessageBox(NULL, msg, "9you.com", MB_OK)

//映射到mydll的 MYAPIINFO *GetMyAPIInfo()
typedef MYAPIINFO *(*tagGetMyAPIInfo)();
//设置远程服务器地址，供发送使用
typedef void (*tagSetServerInfo)(char *pdest_ip_addr,int piPort);

#ifdef WIN95
#define HOOKAPI_DLL_NAME	"HookAPI9x.dll"
#define MY_DLL_NAME			"mydll_9x.dll"
#else
#define HOOKAPI_DLL_NAME	"HookAPINT.dll"
#define MY_DLL_NAME			"mydll.dll"
#endif

class CHookAPI  
{
public:
	CHookAPI();
	virtual ~CHookAPI();

	int m_hook_type;			// 0 - hook all, 1 - hook one process
	
	HINSTANCE m_hMyDll;

	int Init();
	int InitPSAPI();
	int FreePSAPI();

	int LoadMyDll();
	void FreeMyDll();
	
	int HookOneAPI(APIINFO *api_info);
	int UnhookOneAPI(APIINFO *api_info);
	
	int UnhookOneProcess(DWORD process_id);
	
	int HookAllAPI();
	void UnhookAllAPI();

	

	static void ProcessCall();
	
	static int RestoreAPICodes(char *my_api_name);
	static int ChangeAPICodes(char *my_api_name);

	static int RemoveProtection(APIINFO *);

#ifdef WINNT
	int InjectDll(char *dll_name);
	int UninjectDll(char *dll_name);
	
	static DWORD WINAPI myCreateProcessW2003(
		LPCWSTR lpApplicationName,
		LPWSTR lpCommandLine, 
		LPSECURITY_ATTRIBUTES lpProcessAttributes,
		LPSECURITY_ATTRIBUTES lpThreadAttributes,
		BOOL bInheritHandles,
		DWORD dwCreationFlags,
		LPVOID lpEnvironment,
		LPCWSTR lpCurrentDirectory,
		LPSTARTUPINFOW lpStartupInfo,
		LPPROCESS_INFORMATION lpProcessInformation);
	static DWORD WINAPI myCreateProcessA2003(
		LPCSTR lpApplicationName,
		LPSTR lpCommandLine, 
		LPSECURITY_ATTRIBUTES lpProcessAttributes,
		LPSECURITY_ATTRIBUTES lpThreadAttributes,
		BOOL bInheritHandles,
		DWORD dwCreationFlags,
		LPVOID lpEnvironment,
		LPCSTR lpCurrentDirectory,
		LPSTARTUPINFO lpStartupInfo,
		LPPROCESS_INFORMATION lpProcessInformation);

#endif
};

#endif