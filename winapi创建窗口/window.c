#include <windows.h>


LRESULT CALLBACK DealMessage(HWND hwnd,//���ڹ��̺���
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
	)
{
	return 0;
}

//WINAPI:���κ������涨�˺���������ջ�������󣬺���������ϣ��Զ������ջ
//CALLBACK����������ĺ���һ����
int WINAPI WinMain(HINSTANCE hInstance,//Ӧ�ó���ʵ��
	HINSTANCE hPrevInstance,//��һ��Ӧ�ó���ʵ��������
	LPSTR lpCmdLine,//�����в���
	int nCmdShow//������ʾ����ʽ����󻯣���С��
	)
{
	/*
	1��������ں��� WinMain( )
    2������һ������
      A����ƴ����� WNDCLASS������Ա������ֵ��
      B��ע�ᴰ����
      C����ʾ�͸��´���
    3����Ϣѭ��
    4�����ڹ��̺���
	*/


	//��ƴ����� WNDCLASS������Ա��ֵ��
	WNDCLASS wc;
	wc.cbClsExtra = 0;//��ĸ�����Ϣ
	wc.cbWndExtra = 0;//���ڸ�����Ϣ
	                    //��ȡϵͳĬ�ϵİ�ɫ����
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//����ɫ������д
	//wc.hCursor = NULL;//���,ʹ��Ĭ��
	wc.hCursor = LoadCursor(NULL, IDC_HELP);//����ϵͳĬ�Ϲ��
	//wc.hIcon = NULL;//Ĭ��ͼ��
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);//����ϵͳĬ��ͼ��

	wc.hInstance = hInstance;//Ӧ�ó���ʵ��
	wc.lpfnWndProc =DealMessage  ;//���ڹ��̺������֣���Ϣ������

	wc.lpszClassName = TEXT("abc");//�������
	wc.lpszMenuName = NULL;//�˵�����
	wc.style = nCmdShow; //��ʾ���

	//B)ע�ᴰ���࣬����ϵͳ���ڹ��̺�������ڵ�ַ
	RegisterClass(&wc);

	//C)����������
	HWND hWnd = CreateWindow(TEXT("abc"), TEXT("hello,windows"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	//D)��ʾ�͸��´���
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	while (1)
	{

	}
	return 0;
}