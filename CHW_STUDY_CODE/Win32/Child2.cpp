// GUI_resource.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

#include "framework.h"
#include "GUI_resource.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND h;
// �� �ڵ� ��⿡ ���Ե� �Լ��� ������ �����մϴ�:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszChildClass = TEXT("ChildWnd");


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GUIRESOURCE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GUIRESOURCE));

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
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GUIRESOURCE));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GUIRESOURCE);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    //���ϵ� ������ ���
    static HBRUSH hRed = CreateSolidBrush(RGB(255, 0, 0));

    wcex.hbrBackground = hRed;
    wcex.lpfnWndProc = ChildProc;
    wcex.lpszClassName = lpszChildClass;
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);

    RegisterClassExW(&wcex);

    return 0;


  

}

//   �Լ�: InitInstance(HINSTANCE, int)


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ ����

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    if (!hWnd)
    {
        return FALSE;
    }

    return TRUE;
}

//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  �뵵: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���ø����̼� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.

// ����
// ����� ������ case �߰��ؼ� ��� -> ���콺 �Ƿη�
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                CreateWindow(lpszChildClass, NULL,
                    WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_BORDER,
                    x*100,y*100, 100, 100, hWnd, (HMENU)NULL, hInst, NULL);

            }

        }
    

        /*
        //���ϵ� ������
         h=CreateWindow(lpszChildClass, NULL,
            WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN|WS_BORDER,
            100, 100, 100, 100, hWnd, (HMENU)0, hInst, NULL);
         */


         /*
         //�˾� ������ 
         
         CreateWindow(lpszChildClass, _T("Hi POPUP"),
             WS_POPUP | WS_VISIBLE | WS_CLIPCHILDREN | WS_CAPTION|WS_SYSMENU,
             100, 100, 500, 500, hWnd, (HMENU)0, hInst, NULL);
         */
        
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows��� �翬�� �Ǵ� �κ� ���� © �ʿ䰡 ����(move, �ִ�ȭ, �ּ�ȭ)
    }
    return 0;
}

BOOL bEllipse = TRUE;
LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    BOOL bProp;

    switch (message)
    {
    case WM_CREATE:
    {
        SetProp(hWnd, TEXT("bEllipse"), (HANDLE)TRUE); //bEllipse��� �Ӽ��� �ֱ����� �ڵ� , HANDLE���� ����ȯ�� ������ ���� ���� ����������..
        SetProp(hWnd, TEXT("nCount"), (HANDLE)3);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);    
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        SetBkMode(hdc, TRANSPARENT);

        //if (bEllipse == TRUE)
        bProp = (BOOL)GetProp(hWnd, TEXT("bEllipse"));//bEllipse �Ӽ����� �޾ƿ´�
        if(bProp)
        {
            Ellipse(hdc, 10, 10, 90,  90);

        }
        else
        {
            MoveToEx(hdc, 10, 10, NULL); LineTo(hdc, 90, 90);
            MoveToEx(hdc, 10, 90, NULL); LineTo(hdc, 90, 10);

        }
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        bProp = (BOOL)GetProp(hWnd, TEXT("bEllipse"));
        SetProp(hWnd, TEXT("bEllipse"), (HANDLE)!bProp);
        InvalidateRect(hWnd, NULL, TRUE);

    }    
    break;
    case WM_DESTROY:
        RemoveProp(hWnd, TEXT("bEllipse"));
        RemoveProp(hWnd, TEXT("nCount"));
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows��� �翬�� �Ǵ� �κ� ���� © �ʿ䰡 ����(move, �ִ�ȭ, �ּ�ȭ)
    }
    return 0;

}