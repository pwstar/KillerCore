// Main(GUI).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

using namespace std;

#pragma comment(lib, "jykCore.lib")
extern "C" __declspec(dllexport) void __stdcall  test(LPCSTR math);      // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  test(LPCSTR math);

extern "C" __declspec(dllexport) void __stdcall  kill(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  kill(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

extern "C" __declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  OnProcess(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

extern "C" __declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);      // __declspec(dllexport)声明导出该函数供外部调用

extern "C" __declspec(dllexport) void __stdcall  DownProcess(LPCSTR name);  // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

void window() {
    initgraph(600, 500);
    setbkcolor(WHITE);//--------------------------------背景白色
    cleardevice();//------------------------------------刷新背景色
}

void hello() {
    settextcolor(RGB(254,1,1));
    settextstyle(20, 0, L"仿宋GB2312");
    string hello = "Make by a member in C2G6";
    outtextxy(177, 0, L"Make by a member in C2G6");
}

void killing() {
    settextcolor(RGB(254, 1, 1));
    settextstyle(40, 0, L"仿宋GB2312");
    outtextxy(220, 120, L"Killing");
}

int main()
{
    window();
    hello();
    killing();
    while (1);
    return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
