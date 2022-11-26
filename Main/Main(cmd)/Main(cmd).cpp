#include "pch.h"

using namespace std;

//load jykCore.dll(from jykCore.lib)



int main()
{
	int how;
	LPCSTR mythwarename = "StudentMain.exe";
	cout << "Welcome to use Mythware Killer. \nPlease press:\nPress 1 means kill Mythware \nPress 2 means hang-up Mythware \nPress 3 means hang-down Mythware \n";
	cin >> how;
	switch (how)
	{
	case 1:
		Kill(mythwarename);
		cout << "Finish\n";
		main();
	case 2:
		OnProcess(mythwarename);
		cout << "Finish\n";
		main();
	case 3:
		DownProcess(mythwarename);
		cout << "Finish\n";
		main();
	default:
		cout << "Error \n";
		main();
	}
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
