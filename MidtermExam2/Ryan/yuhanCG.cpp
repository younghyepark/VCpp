#include "yuhanCG.h"

void DrawRect(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255)); // ��ũ �귯�� ����
    RECT rect = { left, top, right, bottom }; // RECT Ÿ���� ������ �����ϰ� ���� ����
    FillRect(hdc, &rect, hBrush); // ��ũ�� �簢�� �׸���
    DeleteObject(hBrush); // �귯�� ����
}

void DrawCircle(HWND hWnd, HDC hdc, int radius, POINT center)
{
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
    Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
    SelectObject(hdc, hBrush);

    DeleteObject(hBrush); // �귯�� ����
}

void DrawBonobono(HWND hwnd, HDC hdc, int blink)
{
    RECT rc;
    // ����� �׸��ϴ�.
    if (blink)
    {
        HBRUSH bBrush = CreateSolidBrush(RGB(0, 0, 0)); // ���� ����
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 240, 200)); // ���� ����
        FillRect(hdc, &rc, hBrush);
        DeleteObject(hBrush);
        HBRUSH hEllipseBrush = CreateSolidBrush(RGB(127, 200, 255));
        HBRUSH ddllipseBrush = CreateSolidBrush(RGB(255, 150, 255));//��ȫ��
        HBRUSH xxllipseBrush = CreateSolidBrush(RGB(255, 255, 255));//�Ͼ��
        SelectObject(hdc, hEllipseBrush); // �Ķ��� �귯�� ����
        Ellipse(hdc, 250, 100, 550, 400);// ��
        SelectObject(hdc, ddllipseBrush); // �Ķ��� �귯�� ����
        Ellipse(hdc, 377, 244, 424, 322);
        SelectObject(hdc, xxllipseBrush); // ��� �귯�� ����
        Ellipse(hdc, 353, 245, 400, 292); //���� �԰�
        Ellipse(hdc, 400, 245, 447, 292);
        SelectObject(hdc, bBrush);
        Ellipse(hdc, 275, 225, 284, 242); //��
        Ellipse(hdc, 525, 225, 534, 242);
        SelectObject(hdc, xxllipseBrush);
        Ellipse(hdc, 278, 228, 281, 236); //���� �ȴ�
        Ellipse(hdc, 528, 227, 531, 236); //������ �� ��
        SelectObject(hdc, bBrush);
        Ellipse(hdc, 383, 234, 417, 272); //��
        MoveToEx(hdc, 340, 285, NULL);
        LineTo(hdc, 368, 272);
        MoveToEx(hdc, 340, 255, NULL);
        LineTo(hdc, 380, 262);
        MoveToEx(hdc, 430, 275, NULL);
        LineTo(hdc, 468, 282); //�����ʾƷ� ����
        MoveToEx(hdc, 470, 255, NULL);
        LineTo(hdc, 420, 272);
    }
    else
    {
        HDC hdc = GetDC(hwnd);
        RECT rect;
        GetClientRect(hwnd, &rect);
        HBRUSH bBrush = CreateSolidBrush(RGB(0, 0, 0)); // ���� ����
        HBRUSH hEllipseBrush = CreateSolidBrush(RGB(127, 200, 255));
        HBRUSH ddllipseBrush = CreateSolidBrush(RGB(255, 150, 255));//��ȫ��
        HBRUSH xxllipseBrush = CreateSolidBrush(RGB(255, 255, 255));//�Ͼ��
        SelectObject(hdc, hEllipseBrush); // �Ķ��� �귯�� ����
        Ellipse(hdc, 250, 100, 550, 400);// ��
        SelectObject(hdc, ddllipseBrush); // �Ķ��� �귯�� ����
        Ellipse(hdc, 377, 244, 424, 322);
        SelectObject(hdc, xxllipseBrush); // ��� �귯�� ����
        Ellipse(hdc, 353, 245, 400, 292); //���� �԰�
        Ellipse(hdc, 400, 245, 447, 292);
        MoveToEx(hdc, 275, 225, NULL);
        LineTo(hdc, 290, 245); //��
        MoveToEx(hdc, 514, 245, NULL);
        LineTo(hdc, 529, 225);
        MoveToEx(hdc, 290, 245, NULL);
        LineTo(hdc, 275, 265); //��
        MoveToEx(hdc, 514, 245, NULL);
        LineTo(hdc, 529, 265);
        SelectObject(hdc, bBrush);
        Ellipse(hdc, 383, 234, 417, 272); //��
        MoveToEx(hdc, 340, 285, NULL);
        LineTo(hdc, 368, 272);
        MoveToEx(hdc, 340, 255, NULL);
        LineTo(hdc, 380, 262);
        MoveToEx(hdc, 430, 275, NULL);
        LineTo(hdc, 468, 282); //�����ʾƷ� ����
        MoveToEx(hdc, 470, 255, NULL);
        LineTo(hdc, 420, 272);

        ReleaseDC(hwnd, hdc);
    }
}

void DrawRyan(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double xlength = 0, ylength = 0;

    xlength = right - left;
    ylength = bottom - top;

    HBRUSH hLeftEarColor = CreateSolidBrush(RGB(255, 200, 15));  // ����� ��
    SelectObject(hdc, hLeftEarColor);
    Ellipse(hdc, left, top, left + xlength / 3, top + ylength / 3);  // ���� ���� ���̸� ����
    DeleteObject(hLeftEarColor);

    //// ������ �� (�����)
    HBRUSH hRightEarColor = CreateSolidBrush(RGB(255, 200, 15));  // ����� ��
    SelectObject(hdc, hRightEarColor);
    Ellipse(hdc, left + xlength * 2 / 3, top, left + xlength, top + ylength / 3);  // ������ ���� ���̸� ����
    DeleteObject(hRightEarColor);

    //// �� �׸��� (�����)
    HBRUSH hFaceColor = CreateSolidBrush(RGB(255, 200, 15));  // ����� ��
    SelectObject(hdc, hFaceColor);
    Ellipse(hdc, left + xlength / 18, top + ylength / 13, left + xlength / 18 * 17, top + ylength);
    DeleteObject(hFaceColor);

    //// ���� �׸��� (��� ����)
    SelectObject(hdc, GetStockObject(BLACK_PEN));

    // ���� �� ���μ� �׸���
    MoveToEx(hdc, left + xlength * 7 / 27, top + ylength * 40 / 144, NULL);
    LineTo(hdc, left + xlength * 11 / 27, top + ylength * 40 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18, top + ylength * 40 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18, top + ylength * 40 / 144);

    // ���� �� ���μ� �׸���
    MoveToEx(hdc, left + xlength * 7 / 27, top + ylength * 41 / 144, NULL);
    LineTo(hdc, left + xlength * 11 / 27, top + ylength * 41 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18, top + ylength * 41 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18, top + ylength * 41 / 144);

    // ���� �� �� �κ� �׸���
    MoveToEx(hdc, left + xlength * 7 / 27, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 11 / 27, top + ylength * 42 / 144);
    MoveToEx(hdc, left + xlength * 10 / 18, top + ylength * 42 / 144, NULL);
    LineTo(hdc, left + xlength * 13 / 18, top + ylength * 42 / 144);

    // �� �׸��� (������)
    SelectObject(hdc, GetStockObject(BLACK_BRUSH));

    // ���� ��
    Ellipse(hdc, left + xlength * 17 / 54, top + ylength * 27 / 72, left + xlength * 20 / 54, top + ylength * 31 / 72);

    // ������ ��
    Ellipse(hdc, left + xlength * 32 / 54, top + ylength * 27 / 72, left + xlength * 35 / 54, top + ylength * 31 / 72);



    // �� �׸��� (��� ����, ���)
    HBRUSH hMouthColor = CreateSolidBrush(RGB(255, 255, 255));  // ��� ��
    SelectObject(hdc, hMouthColor);
    int mouthLeft = left + xlength * 8 / 20;  // �� ���� �κ�
    int mouthRight = left + xlength / 2;  // �� ������ �κ�
    int mouthTop = top + ylength * 35 / 72;
    int mouthBottom = top + ylength * 42 / 72;
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    mouthLeft = left + xlength / 2;  // �� ��° ���� ���� �κ�
    mouthRight = left + xlength * 12 / 20;  // �� ��° ���� ������ �κ�
    Ellipse(hdc, mouthLeft, mouthTop, mouthRight, mouthBottom);

    DeleteObject(hMouthColor);
}

void DrawCube(HWND hWnd, HDC hdc, int left, int top, int right, int bottom)
{
    double xlength = 0, ylength = 0;

    xlength = right - left;
    ylength = bottom - top;

    MoveToEx(hdc, left + xlength * 5 / 16, top, NULL); //1 ����
    LineTo(hdc, left + xlength, top);

    MoveToEx(hdc, left + xlength * 5 / 16, top, NULL);
    LineTo(hdc, left, top + ylength * 9 / 36);

    MoveToEx(hdc, left + xlength, top, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36);

    MoveToEx(hdc, left, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36); //2

    MoveToEx(hdc, left, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left, top + ylength);

    MoveToEx(hdc, left + xlength * 11 / 16, top + ylength * 9 / 36, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength);

    MoveToEx(hdc, left, top + ylength, NULL);
    LineTo(hdc, left + xlength * 11 / 16, top + ylength); //3

    MoveToEx(hdc, left + xlength, top, NULL);
    LineTo(hdc, left + xlength, top + ylength * 11 / 16);

    MoveToEx(hdc, left + xlength * 11 / 16, top + ylength, NULL);
    LineTo(hdc, left + xlength, top + ylength * 11 / 16);
}