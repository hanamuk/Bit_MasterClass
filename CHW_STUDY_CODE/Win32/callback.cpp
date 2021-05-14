//void (*pFunc)(HWND ,UINT ,UINT_PTR ,DWORD );

////OS내의 함수를 내가 짜보자
//void SetTimer(HWND hWnd, int nTimerID, int nSecond, void (*pFunc)(HWND, UINT, UINT_PTR, DWORD))
//{
//    Sleep(nSecond);
//    if (pFunc == NULL)
//    {
//        SendMessage(hWnd, WM_TIMER, nTimerID, NULL);
//    }
//    else
//    {
//        pFunc(hWnd, nTimerID, 0, 0);
//    }
//    
//}