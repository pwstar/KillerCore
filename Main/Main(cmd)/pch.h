#pragma once

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#pragma comment(lib, "jykCore.lib")

extern "C" __declspec(dllexport) void __stdcall  test(LPCSTR math); 

extern "C" __declspec(dllexport) void __stdcall  Kill(LPCSTR name);       // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用
