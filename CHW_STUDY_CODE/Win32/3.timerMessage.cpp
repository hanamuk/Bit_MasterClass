// WindowsProject_0513.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

#define ON_MAIN
#ifdef ON_MAIN

// WindowsProject_0513.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

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
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
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
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT0513));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
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

void CALLBACK MyTimerproc( HWND hWnd,UINT_PTR unnamedParam3,DWORD unnamedParam4) // �ݹ����� ����Ϸ��� CALLBACK Ű���� ���
{
    HDC hdc = GetDC(hWnd);
    for (int i = 0; i < 1000; i++)
    {
        SetPixel(hdc, rand() %500, rand() % 500, RGB(rand() % 256, rand() % 256, rand() % 256));
    }
    ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR sTime[128];
    switch (message)
    {
    case WM_CREATE:
    {
        //SetTimer(hWnd, 1, 1000, NULL);//Ÿ�̸Ӹ� ������ּ���, 1���˶����� ����, 1��(1000)���� ���.
       // SetTimer(hWnd, 2, 5000, NULL);
        SetTimer(hWnd, 3, 100, MyTimerproc);//���������ڰ� NULL�̸� WM_TIMER�ΰ��� , �Լ��̸��� �ָ� �Լ��� ����ȴ�. �� �̰� MyTimerproc�� ����.

    }
    break;
    case WM_TIMER: 
    {
        switch (wParam) //wParam == Ÿ�̸Ӿ��̵�
        {
        case 1: //����ð��� ���ؼ� ȭ�鿡 ǥ���Ѵ�.
            SYSTEMTIME st;
            GetLocalTime(&st);//����ð��� �����ִ� �Լ�
            wsprintf(sTime, TEXT("������ �ð��� %d :%d: %d�Դϴ�"), st.wHour, st.wMinute, st.wSecond); //ȭ������� �ƴϰ� sTime���ۿ� ���ڸ� �־��ִ� �ڵ�.
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case 2: //���� ��ȭ���ڸ� ����Ѵ�.
            int a =MessageBox(hWnd, _T("���½ð��Դϴ�"), _T("�߿�˸�"), MB_YESNO);
            if(a==7)
                MessageBox(hWnd, _T("�ƴϿ��� ��������"), _T("���ð�����"), MB_YESNO);
            break;
        }
    }
    break;
    case WM_LBUTTONDOWN:
    {

        //KillTimer(hWnd, 2);//2��Ÿ�̸Ӹ� �׿���
        HDC hdc = GetDC(hWnd);
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        Ellipse(hdc, x - 10, y - 10, x + 10, y + 10);

        ReleaseDC(hWnd, hdc);
    
    }
     break;

    case WM_RBUTTONDOWN:
        //SetTimer(hWnd, 1, 1000, NULL);
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        TextOut(hdc, 100, 100, sTime, lstrlen(sTime));
       
        EndPaint(hWnd, &ps);
    }
    break;
 
    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, 1);//1��Ÿ�̸Ӹ� �׿���
        KillTimer(hWnd, 2);//2��Ÿ�̸Ӹ� �׿���

        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#endif 
