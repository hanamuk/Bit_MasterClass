// GUI_resource.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "GUI_resource.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND h;
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GUIRESOURCE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GUIRESOURCE));

    MSG msg;

    // 기본 메시지 루프입니다:
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
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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

    //차일드 윈도우 등록
    static HBRUSH hRed = CreateSolidBrush(RGB(255, 0, 0));

    wcex.hbrBackground = hRed;
    wcex.lpfnWndProc = ChildProc;
    wcex.lpszClassName = lpszChildClass;
    wcex.hCursor = LoadCursor(NULL, IDC_CROSS);

    RegisterClassExW(&wcex);

    return 0;


  

}

//   함수: InitInstance(HINSTANCE, int)


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장

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

//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.

// 포수
// 만들고 싶으면 case 추가해서 사용 -> 마우스 또로롱
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
        //차일드 윈도우
         h=CreateWindow(lpszChildClass, NULL,
            WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN|WS_BORDER,
            100, 100, 100, 100, hWnd, (HMENU)0, hInst, NULL);
         */


         /*
         //팝업 윈도우 
         
         CreateWindow(lpszChildClass, _T("Hi POPUP"),
             WS_POPUP | WS_VISIBLE | WS_CLIPCHILDREN | WS_CAPTION|WS_SYSMENU,
             100, 100, 500, 500, hWnd, (HMENU)0, hInst, NULL);
         */
        
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
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
        SetProp(hWnd, TEXT("bEllipse"), (HANDLE)TRUE); //bEllipse라는 속성을 주기위한 코드 , HANDLE으로 형변환한 이유는 무슨 형이 들어올지몰라서..
        SetProp(hWnd, TEXT("nCount"), (HANDLE)3);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);    
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        SetBkMode(hdc, TRANSPARENT);

        //if (bEllipse == TRUE)
        bProp = (BOOL)GetProp(hWnd, TEXT("bEllipse"));//bEllipse 속성값을 받아온다
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
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;

}