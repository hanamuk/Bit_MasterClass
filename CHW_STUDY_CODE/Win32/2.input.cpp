// WindowsProject_0513.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//
//#define ON_MAIN
#ifdef ON_MAIN

#include "framework.h"
#include "WindowsProject_0513.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT0513, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT0513));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;  //�����̸�. ó������ �ٲܼ��ִ�.
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT0513));
    wcex.hCursor = LoadCursor(nullptr, IDC_HAND);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    //wcex.hbrBackground  = (HBRUSH)GetStockObject(GRAY_BRUSH);

    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT0513);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   �뵵: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   �ּ�:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR* mem;
    static TCHAR str[256] = { 0 }; //static�� �ϸ� �ѹ� ���ڰ� ���ͼ� ����Ǿ��ٰ� WndProc�� ������ ������ �����Ǿ��ٰ� �ٽ� �����Ǽ� �ʱ�ȭ�Ǵ°�.
    int len;
  
    static int x1 = 100;
    static int y1 = 100;
    static int x2 = 200;
    static int y2 = 200;

    switch (message)
    {
    case WM_CHAR:   //Ű���忡�� ����Ű�� ������.
    {
        if ((TCHAR)wParam == ' ')
        {
            str[0] = 0;//0=='\0'
        }
        else
        {
            len = lstrlen(str); //ó������ str =0 , why? str�ȿ� ���� ���� ���� �ʾұ� ������.
            str[len] = (TCHAR)wParam;
            str[len + 1] = 0;

        }

        InvalidateRect(hWnd, NULL, TRUE); //WM_PAINT �߻�, �� ������ �ѱ��� �߰��ɶ����� PINT�ΰ��� ���ڸ� �׷���. ������ ���ΰ�ħ �������?,�׸� ��ü �ٽñ׷�
                                            //�ٵ� �ٷ� ó���Ǵ°� �ƴϰ� �տ� �޽����� ó���ǰ� ó����.
                                            //���������ڸ� true�� �ָ� �������� �������°� �̴�.

    }
    break;
    case WM_KEYDOWN: //Ű���忡�� Ű�� ����
    {
        switch (wParam)
        {
        case VK_LEFT:
            x1 -= 8;
            break;
        case VK_RIGHT:
            x1 += 8;
            break;
        case VK_UP:
            y1 -= 8;
            break;
        case VK_DOWN:
            y1 += 8;
            break;
        }
        InvalidateRect(hWnd, NULL, FALSE);
    }
    break;

   case WM_LBUTTONDOWN:
    {
        x2 = LOWORD(lParam);
        y2 = HIWORD(lParam);
        InvalidateRect(hWnd, NULL, TRUE);

    }
   break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...

        TextOut(hdc, x1, y1, _T("O"), 1);
        TextOut(hdc, x2, y2, _T("�ȳ��ϼ���. �ݰ�����"), 15);
        TextOut(hdc, 100, 100, str, lstrlen(str));

        return 0;

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_CREATE: //�����찡 ������
        mem = (TCHAR*)malloc(1212);
        break;
    case WM_DESTROY://�����찡 �ı���
        free(mem);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#endif