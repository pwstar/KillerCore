#pragma once

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#pragma comment(lib, "jykCore.lib")

extern "C" __declspec(dllexport) void __stdcall  test(LPCSTR math); 

extern "C" __declspec(dllexport) void __stdcall  Kill(LPCSTR name);       // __declspec(dllexport)���������ú������ⲿ����

extern "C" __declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);      // __declspec(dllexport)���������ú������ⲿ����

extern "C" __declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);  // __stdcall��Windows APIĬ�ϵĺ�������Э�飬�������ô��ҵ����ѹջ��ʽ���Լ����˳�ʱ��ն�ջ��Ҳ���Բ�ʹ��
