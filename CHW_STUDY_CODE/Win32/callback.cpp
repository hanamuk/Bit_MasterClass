//void (*pFunc)(HWND ,UINT ,UINT_PTR ,DWORD );

////OS���� �Լ��� ���� ¥����
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