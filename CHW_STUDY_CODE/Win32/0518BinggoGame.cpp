// 0518BinggoGame.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//






#include "framework.h"
#include "0518BinggoGame.h"

#define MAX_LOADSTRING 100
#define MAX_SIZE 3
#define WM_CHECKBINGO    WM_USER + 10



// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND g_hMainWnd;
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
LPCTSTR lpszChildClass = TEXT("ChildWnd");


BOOL g_bMyTurn = TRUE;
HWND   arrBinggo[MAX_SIZE][MAX_SIZE];


enum modeBINGO {
    bingoNONE,
    bingoMINE,
    bingoMyBINGO,
    bingoYOURS,
    bingoYourBINGO
};



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
    LoadStringW(hInstance, IDC_MY0518BINGGOGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0518BINGGOGAME));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0518BINGGOGAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0518BINGGOGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    g_hMainWnd = hWnd;
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    if (!hWnd)
    {
        return FALSE;
    }

    return TRUE;
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        for (int x = 0; x < MAX_SIZE; x++)
        {

            for (int y = 0; y < MAX_SIZE; y++)
            {                
                arrBinggo[x][y] = CreateWindow(lpszChildClass, NULL,
                    WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_BORDER,
                    x * 100, y * 100, 100, 100, hWnd, (HMENU)NULL, hInst, NULL);

            }

        }

    }
    case WM_CHECKBINGO:
    {      
        HWND hChild = (HWND) wParam;
        int nChildMode = (int)lParam;

        //해당 차일드 체크===============================
        int x = 0;
        int y = 0;
        for(int i=0; i< MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE; j++)
        {
            if (arrBinggo[i][j] == hChild)
            {
                //hit
                x = i;
                y = j;
                break;                
            }
        }


        int nBingoCount;
        //가로 빙고 , x고정 y로 ..
        nBingoCount = 0;
        for (int i = 0; i < MAX_SIZE; i++)//아래로 내려가는 ..
        {
            int temp = (int)GetProp(arrBinggo[x][i], TEXT("nBingoMode"));
            if(temp == nChildMode || temp== nChildMode+1)
            {
                nBingoCount++;               
            }
        }
        if (nBingoCount == 3)//가로 빙고!!!!!
        {
            for (int i = 0; i < MAX_SIZE; i++)//아래로 내려가는 ..
            {
                SetProp(arrBinggo[x][i], TEXT("nBingoMode"), (HANDLE)(nChildMode + 1));
                InvalidateRect(arrBinggo[x][i], NULL, TRUE);
            }
        }

        nBingoCount = 0;
        for (int i = 0; i < MAX_SIZE; i++)//아래로 내려가는 ..
        {
            int temp = (int)GetProp(arrBinggo[i][y], TEXT("nBingoMode"));
            if (temp == nChildMode || temp == nChildMode + 1)
            {
                nBingoCount++;
            }
        }
        if (nBingoCount == 3)//세로 빙고!!!!!
        {
            for (int i = 0; i < MAX_SIZE; i++)//아래로 내려가는 ..
            {
                SetProp(arrBinggo[i][y], TEXT("nBingoMode"), (HANDLE)(nChildMode + 1));
                InvalidateRect(arrBinggo[i][y], NULL, TRUE);
            }
        }

        break;
    }
 
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;
}

LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{    
    switch (message)
    {
    case WM_CREATE:
    {

        SetProp(hWnd, TEXT("nBingoMode"), (HANDLE)bingoNONE); //얘가 x인지 아닌지 판단
    }
    break;
    case WM_PAINT:
    {        
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        int nBingoMode;
        nBingoMode = (int)GetProp(hWnd, TEXT("nBingoMode")); //한번 클릭된 것이라면 두번 클릭해도 다른사람 꺼로 바뀌지않고 내꺼로 계속 사용하려고 사용

        switch (nBingoMode)
        {
        case bingoNONE: 
            Rectangle(hdc, 10, 10, 90, 90);
            break;
        case bingoMINE: 
            Ellipse(hdc, 10, 10, 90, 90);
            break;
        case bingoMyBINGO: 
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 10, 10, _T("나의빙고"), 4);
            break;
        case bingoYOURS: 
            MoveToEx(hdc, 10, 10, NULL); LineTo(hdc, 90, 90);
            MoveToEx(hdc, 10, 90, NULL); LineTo(hdc, 90, 10);
            break;
        case bingoYourBINGO: 
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 10, 10, _T("너의빙고"), 4);
            break;
        }
        EndPaint(hWnd, &ps);
    }
    break;

    case WM_LBUTTONDOWN:
    {
        
        int nBingoMode;
        nBingoMode = (int)GetProp(hWnd, TEXT("nBingoMode"));
        g_bMyTurn = !g_bMyTurn;

        if (nBingoMode==bingoNONE)
        {
            int nCurMode;
            if (g_bMyTurn == TRUE)
            {
                nCurMode = bingoMINE;

            }
            else                 
            {
                nCurMode = bingoYOURS;
            }
            SetProp(hWnd, TEXT("nBingoMode"), (HANDLE)nCurMode);
            SendMessage(g_hMainWnd, WM_CHECKBINGO, (WPARAM)hWnd, nCurMode);
        }
        InvalidateRect(hWnd, NULL, TRUE);     
    }
    break;

    case WM_DESTROY:
   
        RemoveProp(hWnd, TEXT("nBingoMode"));
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);    //Windows라면 당연히 되는 부분 굳이 짤 필요가 없음(move, 최대화, 최소화)
    }
    return 0;

}