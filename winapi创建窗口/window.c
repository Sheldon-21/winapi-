#include <windows.h>


LRESULT CALLBACK DealMessage(HWND hwnd,//窗口过程函数
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
	)
{
	return 0;
}

//WINAPI:修饰函数，规定了函数参数入栈从右往左，函数调用完毕，自动清理堆栈
//CALLBACK：（和上面的含义一样）
int WINAPI WinMain(HINSTANCE hInstance,//应用程序实例
	HINSTANCE hPrevInstance,//上一个应用程序实例，不用
	LPSTR lpCmdLine,//命令行参数
	int nCmdShow//窗口显示的样式，最大化，最小化
	)
{
	/*
	1，定义入口函数 WinMain( )
    2，创建一个窗口
      A）设计窗口类 WNDCLASS（给成员变量赋值）
      B）注册窗口类
      C）显示和更新窗口
    3，消息循环
    4，窗口过程函数
	*/


	//设计窗口类 WNDCLASS（给成员赋值）
	WNDCLASS wc;
	wc.cbClsExtra = 0;//类的附加信息
	wc.cbWndExtra = 0;//窗口附加信息
	                    //获取系统默认的白色画板
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景色，必须写
	//wc.hCursor = NULL;//光标,使用默认
	wc.hCursor = LoadCursor(NULL, IDC_HELP);//加载系统默认光标
	//wc.hIcon = NULL;//默认图标
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);//加载系统默认图标

	wc.hInstance = hInstance;//应用程序实例
	wc.lpfnWndProc =DealMessage  ;//窗口过程函数名字，消息处理函数

	wc.lpszClassName = TEXT("abc");//类的名字
	wc.lpszMenuName = NULL;//菜单名字
	wc.style = nCmdShow; //显示风格

	//B)注册窗口类，告诉系统窗口过程函数的入口地址
	RegisterClass(&wc);

	//C)创建窗口类
	HWND hWnd = CreateWindow(TEXT("abc"), TEXT("hello,windows"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	//D)显示和更新窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	while (1)
	{

	}
	return 0;
}