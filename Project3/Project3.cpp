#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include <windows.h>

POINT startPoint = { 0 };        // 사각형 그리기 시작점 좌표
POINT endPoint = { 0 };          // 사각형 그리기 종료점 좌표
int isMouseLButtonPressed = 0;   // 마우스 왼쪽 버튼이 눌렸는지 여부를 나타내는 플래그
RECT previousRect = { 0 };       // 이전에 그려진 사각형의 좌표를 저장하는 변수

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_LBUTTONDOWN:
    {
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
        isMouseLButtonPressed = 1;
    }
    break;

    case WM_LBUTTONUP:
    {
        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);

        if (isMouseLButtonPressed)
        {
            isMouseLButtonPressed = 0;

            // 시작점과 종료점을 이용하여 새로운 사각형의 좌표 계산
            int left = min(startPoint.x, endPoint.x);
            int top = min(startPoint.y, endPoint.y);
            int right = max(startPoint.x, endPoint.x);
            int bottom = max(startPoint.y, endPoint.y);

            // 화면에 사각형 그리기
            HDC hdc = GetDC(hwnd);
            RECT rect = { left, top, right, bottom };
            HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성

            if (hBrush == NULL)
            {
                MessageBox(NULL, L"CreateSolidBrush failed!", L"Error", MB_ICONERROR);
                exit(-1); // 예외
            }

            FillRect(hdc, &rect, hBrush); // 사각형을 핑크색으로 채우기
            ReleaseDC(hwnd, hdc);
            DeleteObject(hBrush);

            // 현재 그려진 사각형의 좌표를 이전 좌표로 저장
            previousRect = rect;
        }
    }
    break;

    case WM_RBUTTONDOWN:
    {
        startPoint.x = LOWORD(lParam);
        startPoint.y = HIWORD(lParam);
    }
    break;

    case WM_RBUTTONUP:
    {
        endPoint.x = LOWORD(lParam);
        endPoint.y = HIWORD(lParam);

        int deltaX = endPoint.x - startPoint.x;
        int deltaY = endPoint.y - startPoint.y;

        // 이전에 그린 네모를 지우기
        HDC hdc = GetDC(hwnd);
        FillRect(hdc, &previousRect, (HBRUSH)(COLOR_WINDOW + 1));
        ReleaseDC(hwnd, hdc);

        // 새로운 위치에 네모 그리기
        previousRect.left += deltaX;
        previousRect.right += deltaX;
        previousRect.top += deltaY;
        previousRect.bottom += deltaY;

        hdc = GetDC(hwnd);
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성

        if (hBrush == NULL)
        {
            MessageBox(NULL, L"CreateSolidBrush failed!", L"Error", MB_ICONERROR);
            exit(-1); // 예외
        }

        FillRect(hdc, &previousRect, hBrush); // 이동한 위치에 네모 그리기
        ReleaseDC(hwnd, hdc);
        DeleteObject(hBrush);
    }
    break;

    case WM_MOUSEMOVE:
    {
        // 마우스 이동 중
        if (isMouseLButtonPressed)
        {
            // 아무 작업도 수행하지 않음.
        }
    }
    break;

    case WM_PAINT:
    {
        HDC hdc = GetDC(hwnd);

        if (isMouseLButtonPressed)
        {
            RECT rect;
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
        }

        ReleaseDC(hwnd, hdc);
        /** 사각형 그리기
        */
        //HDC hdc = GetDC(hwnd);
        //RECT rect = { 50, 50, 150, 150 }; // 왼쪽 상단 좌표 (50, 50)에서 오른쪽 하단 좌표 (150, 150)까지의 사각형
        //HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성


        //// 그리기
        //FillRect(hdc, &rect, hBrush); // 사각형을 빨간색으로 채우기
        //ReleaseDC(hwnd, hdc);


        /** 타원 그리기
        */
        //HDC hdc = GetDC(hwnd); // 디바이스 컨텍스트 얻기
        //
        //HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // 핑크 브러시 생성
        //SelectObject(hdc, hBrush);

        //// 타원 그리기
        //Ellipse(hdc, 50, 50, 200, 150); // 왼쪽 상단 좌표 (50, 50)에서 오른쪽 하단 좌표 (200, 150)까지의 타원

        //DeleteObject(hBrush);

        //ReleaseDC(hwnd, hdc); // 디바이스 컨텍스트 해제

    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return S_OK;
}

#ifdef UNICODE
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
#else
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR pCmdLine, _In_ int nCmdShow)
#endif
{
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(wc));

    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("Computer Software");
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;

    if (RegisterClass(&wc) == 0)
    {
        MessageBox(NULL, L"RegisterClass failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    RECT rect = { 150, 100, 800, 600 };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;

    HWND hwnd = CreateWindow(
        wc.lpszClassName,
        TEXT("202217051 박영혜"),
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME,
        0, 0,
        width, height,
        NULL, NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        MessageBox(NULL, L"CreateWindow failed!", L"Error", MB_ICONERROR);
        exit(-1);
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));

    while (msg.message != WM_QUIT)
    {
        if (GetMessage(&msg, hwnd, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}
