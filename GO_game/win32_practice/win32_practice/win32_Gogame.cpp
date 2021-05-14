// win32_practice.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//


// size 500 * 500
#define WSIZE 530
// backgroundColor:   wcex.hbrBackground  = (HBRUSH)CreateSolidBrush(RGB(232,203,97 ));


#include "framework.h"
#include "win32_practice.h"

#define MAX_LOADSTRING 100
#define INTERVAL 30
void Area(HDC hdc, int nInx, int nIny, int bw);

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
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

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PRACTICE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PRACTICE));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PRACTICE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)CreateSolidBrush(RGB(232,203,97 ));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PRACTICE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WSIZE-13, WSIZE+30, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  

    switch (message)
    {
    case WM_CREATE:
    {


     /*   for (int ix = 0; ix < 18; ix++)
        {
           
            for (int iy = 0; iy < 18; iy++)
            {

            }

        }*/

    }
    case WM_LBUTTONDOWN:
    {
        HDC hdc = GetDC(hWnd);

        int nInx = LOWORD(lParam);//실제 입력좌표
        int nIny = HIWORD(lParam);

        Area(hdc,nInx, nIny, 1);
        

        ReleaseDC(hWnd, hdc);
    }
        break;
    case WM_RBUTTONDOWN:
    {
        HDC hdc = GetDC(hWnd);

        int nInx = LOWORD(lParam);//실제 입력좌표
        int nIny = HIWORD(lParam);

        Area(hdc, nInx, nIny, 0);
        ReleaseDC(hWnd, hdc);
    }  
    break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            //바둑판 그리기..
            //x축 그리기
            for (int y = 0; y <= 20; y ++ )
            {
                MoveToEx(hdc, 0, y*30, NULL);
                LineTo(hdc, 500, y*30);
            }

            //y축 그리기
            for (int x = 0; x <= 20; x ++)
            {
                MoveToEx(hdc, x*30, 0, NULL);
                LineTo(hdc, x*30, 500);
            }
           

            EndPaint(hWnd, &ps);
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


void Area(HDC hdc,int nInx, int nIny, int bw)
{
    //0 ==하얀색

    int RX = nInx % INTERVAL;//나머지연산한 값.
    int RY = nIny % INTERVAL;

    int DX = nInx / INTERVAL;//나누기 값.  이거+1한 값을 나머지 if문에서 끝나서 나온 RX에 곱해주면 해당 좌표로 옮겨간다.
    int DY = nIny / INTERVAL;

    int nDrawX = 0;
    int nDrawY = 0;


    if (0 < RX && RX <= INTERVAL / 2)
    {
        RX = 0;
    }
    else if (INTERVAL / 2 < RX && RX <= INTERVAL)
    {
        RX = INTERVAL;
    }


    if (0 < RY && RY <= INTERVAL / 2)
    {
        RY = 0;
    }
    else if (INTERVAL / 2 < RY && RY <= INTERVAL)
    {
        RY = INTERVAL;
    }

    nDrawX = RX + DX * 30;
    nDrawY = RY + DY * 30;

    if (bw == 1)
    {
        HBRUSH myBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, myBrush);

        Ellipse(hdc, nDrawX - 10, nDrawY - 10, nDrawX + 15, nDrawY + 15);

        SelectObject(hdc, oldBrush);
        DeleteObject(myBrush);
    }
    else
    {
        Ellipse(hdc, nDrawX - 10, nDrawY - 10, nDrawX + 15, nDrawY + 15);

    }
   

}