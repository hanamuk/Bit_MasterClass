// GUI_resource.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
//

#include "framework.h"
#include "GUI_resource.h"

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
    switch (message)
    {
    case WM_COMMAND:
    {
  
    }
    break;
    case WM_PAINT:
    if(0)//StockObject ���
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        HBRUSH Mybr = (HBRUSH)GetStockObject(BLACK_BRUSH);//StockObject �̸������� �귯��,��, ��Ʈ �� ����.. ���°ſ� ���� ����ȯ ������Ѵ�.
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, Mybr);//SelectObject�� ���� �귯����Mybr ������ ��ȯ�Ǵµ� �׷��� �⺻ ���� Oldbr(�Ͼ����)�� ������µ� �����쿡���� 
                                                       //����� ������ �ٽ� ���� ������ �ٲ�����ϱ⶧���� oldr�� �����س��� �پ����� �ٽ� �ٲ�����Ѵ�.
        Rectangle(hdc, 50, 50, 250, 250);
        HBRUSH Mybr2 = (HBRUSH)GetStockObject(GRAY_BRUSH);//StockObject �̸������� �귯��,��, ��Ʈ �� ����.. ���°ſ� ���� ����ȯ ������Ѵ�.
        SelectObject(hdc, Mybr2);
        Rectangle(hdc, 100, 100, 450, 450);

        SelectObject(hdc, Oldbr);//�귯���� ����Ʈ������ �ϴ� �ڵ�
        Rectangle(hdc, 400, 300, 600, 600);
        EndPaint(hWnd, &ps);
    }
    if (1)//������ �귯�� ���
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        //HBRUSH Mybr = CreateSolidBrush(RGB(255,5,94));
        HBRUSH Mybr = CreateHatchBrush(HS_CROSS,RGB(255, 5, 94));//��, �ٵ���ó�� �׷���.
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, Mybr);
        Rectangle(hdc, 100, 100, 250, 250);
        SelectObject(hdc, Oldbr);
        Rectangle(hdc, 300, 300, 600, 600);

        EndPaint(hWnd, &ps);
    }
    if (0)//������ �� ���
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        HPEN MyPen = CreatePen(PS_DASH,1,RGB(158, 100, 213));//����, ����, ���� //ù���� ���ڰ� solid���ƴϸ� ���Ⱑ 1�ƴϸ� �Ȼ���.
        HPEN OlPen = (HPEN)SelectObject(hdc, MyPen);
        Rectangle(hdc, 100, 100, 250, 250);
        SelectObject(hdc, OlPen);
        Rectangle(hdc, 300, 300, 600, 600);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_MOUSEMOVE:
    {
        int x, y, r;
        x = rand() % 640;
        y = rand() % 480;
        r = rand() % 10+10;
        HDC hdc = GetDC(hWnd);
        HBRUSH Mybr = CreateSolidBrush(RGB(rand()%256, rand() % 256, rand() % 256));
        HBRUSH Oldbr = (HBRUSH)SelectObject(hdc, Mybr);
        Ellipse(hdc, x - r, y - r, x + r, y + r);
        SelectObject(hdc, Oldbr);
        ReleaseDC(hWnd,hdc);
    }
    break;

    case WM_LBUTTONDOWN:
    {
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


