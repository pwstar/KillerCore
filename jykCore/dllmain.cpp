// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <TlHelp32.h>

//include部分结束



//dll定义部分

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

typedef struct ST_WNDINFO
{
    HWND    hWnd;
    DWORD   dwProcessId;
}WNDINFO, * LPWNDINFO;

//dll定义部分结束

//测试

void __stdcall test(LPCSTR math) {
	std::cout << math;
	while (1);
}

//测试结束

//获取句柄 函数方法GetProcessIDFromName（name）

HWND GetProcessMainWnd(const DWORD dwProcessId)
{
	WNDINFO wndInfo;
	wndInfo.hWnd = nullptr;
	wndInfo.dwProcessId = dwProcessId;
	::EnumWindows([](HWND hWnd, LPARAM lParam) -> BOOL
		{
			DWORD dwProcessId = 0;
			::GetWindowThreadProcessId(hWnd, &dwProcessId);
			const auto pInfo = reinterpret_cast<LPWNDINFO>(lParam);
			if (dwProcessId == pInfo->dwProcessId)
			{
				pInfo->hWnd = hWnd;
				return FALSE;
			}
			return TRUE;
		}, reinterpret_cast<LPARAM>(&wndInfo));

	return wndInfo.hWnd;
}

DWORD GetProcessIDFromName(LPCSTR szName) {
	DWORD id = 0;       // 进程ID
	PROCESSENTRY32 pe;  // 进程信息
	pe.dwSize = sizeof(PROCESSENTRY32);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // 获取系统进程列表
	if (Process32First(hSnapshot, &pe)) {   // 返回系统中第一个进程的信息
		do {
			if (0 == _stricmp(pe.szExeFile, szName)) { // 不区分大小写比较
				id = pe.th32ProcessID;
				break;
			}
		} while (Process32Next(hSnapshot, &pe));     // 下一个进程
	}
	CloseHandle(hSnapshot);     // 删除快照
	return id;
}
//获取句柄结束

//杀进程部分 函数方法 Kill(LPCSTR name)
#define KILL_FORCE 1
#define KILL_DEFAULT 2

//用杀掉每个线程的方法解决某些进程hook住了TerminateProcess()的问题
bool KillProcess(DWORD dwProcessID, int way) {
	if (way == KILL_FORCE) {
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, dwProcessID);

		if (hSnapshot != INVALID_HANDLE_VALUE) {
			bool rtn = false;
			THREADENTRY32 te = { sizeof(te) };
			BOOL fOk = Thread32First(hSnapshot, &te);
			for (; fOk; fOk = Thread32Next(hSnapshot, &te)) {
				if (te.th32OwnerProcessID == dwProcessID) {
					HANDLE hThread = OpenThread(THREAD_TERMINATE, FALSE, te.th32ThreadID);
					if (TerminateThread(hThread, 0)) rtn = true;
					CloseHandle(hThread);
				}
			}
			CloseHandle(hSnapshot);
			return rtn;
		}
		return false;
	}
	else if (way == KILL_DEFAULT) {
		//默认方法，稳定安全
		HANDLE handle = OpenProcess(PROCESS_TERMINATE, FALSE, dwProcessID);
		BOOL sta = TerminateProcess(handle, 0);
		CloseHandle(handle);
		return sta;
	}
	return false;
}
void __stdcall Kill(LPCSTR name) {
	KillProcess(GetProcessIDFromName(name), KILL_FORCE);
}


//杀进程部分结束


//挂起进程部分

/*
函数功能:挂起进程中的所有线程
参数1:进程ID
参数2:若为TRUE时对进程中的所有线程调用SuspendThread,挂起线程
	  若为FALSE时对进程中的所有线程调用ResumeThread,恢复线程
*/

VOID SuspendProcess(DWORD dwProcessID, BOOL fSuspend) {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(
		TH32CS_SNAPTHREAD, dwProcessID);

	if (hSnapshot != INVALID_HANDLE_VALUE) {

		THREADENTRY32 te = { sizeof(te) };
		BOOL fOk = Thread32First(hSnapshot, &te);
		for (; fOk; fOk = Thread32Next(hSnapshot, &te)) {
			if (te.th32OwnerProcessID == dwProcessID) {
				HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);

				if (hThread != NULL) {
					if (fSuspend) {
						SuspendThread(hThread);
					}
					else {
						ResumeThread(hThread);
					}
				}
				CloseHandle(hThread);
			}
		}
		CloseHandle(hSnapshot);
	}
}
VOID __stdcall OnProcess(LPCSTR name) {
	SuspendProcess(GetProcessIDFromName(name), true);
}

VOID __stdcall DownProcess(LPCSTR name) {
	SuspendProcess(GetProcessIDFromName(name), false);
}


//挂起进程部分

