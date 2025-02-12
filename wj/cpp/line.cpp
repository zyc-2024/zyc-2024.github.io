#include<windows.h>
#include<bits/stdc++.h>
#include<winuser.h>
using namespace std;


void DrawLine(HDC hDC, int x0, int y0, int x1, int y1, int style, int width, COLORREF color) {
	HPEN hPen = CreatePen(style, width, color);
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	MoveToEx(hDC, x0, y0, NULL);
	LineTo(hDC, x1, y1);
	SelectObject(hDC, hOldPen);
	DeleteObject(hPen);
}
int main(){
    HDC hdc;
    DrawLine(hdc,100,100,200,200,0,20,0);
}