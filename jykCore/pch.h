// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
#include "framework.h"
#include <iostream>

#ifdef __cplusplus         // 一般用于将C++代码以标准C形式输出（即以C的形式被调用）
extern"C" {                 // 告诉编译器下面大括号括起来的函数是c语言函数（因为c++和c语言对函数的编译转换不一样，主要是c++中存在重载）
#endif

	__declspec(dllexport) void __stdcall  test(LPCSTR math);      // __declspec(dllexport)声明导出该函数供外部调用

	__declspec(dllexport) void __stdcall  test(LPCSTR math);

	__declspec(dllexport) void __stdcall  Kill(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

	__declspec(dllexport) void __stdcall  Kill(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

	__declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

	__declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

	__declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

	__declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

#ifdef __cplusplus
}
#endif

#endif //PCH_H
