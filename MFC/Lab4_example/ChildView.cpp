
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Lab4_example.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	/*CPaintDC 클래스 예제*/
	/*
	dc.Rectangle(0, 0, 200, 100);
	dc.Ellipse(200, 100, 500, 200);
	*/

	/*펜 생성 방법*/
	/*
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0)); //폭이 2인 빨간색 펜(방법1)

	CPen pen;
	pen.CreatePen(PS_SOLID,2, RGB(255, 0, 0)); //폭이 2인 빨간색 펜(방법2)
	*/

	/*펜 사용 예1*/
	/*
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255)); //펜 객체를 만든다.
	CPen *pOldPen = dc.SelectObject(&pen); //새로운 펜 선택, 이전 펜 저장
	dc.Rectangle(100, 100, 200, 200); //직사각형을 그린다.
	dc.SelectObject(pOldPen); //이전 펜 복원, 사용하던 펜 선택 해제
	*/

	/*펜 사용 예2*/
	/*
	CPen pen(PS_SOLID,1, RGB(0, 0, 255)); //펜 객체를 만든다.
	dc.SelectObject(&pen); //새로운 펜을 선택한다.
	dc.Rectangle(100, 100, 200, 200); //직사각형을 그린다.
	*/

	/*브러시 사용 예1*/
	/*
	CBrush brush(RGB(255, 0, 0)); //브러시 객체를 만든다.
	CBrush *pOldBrush = dc.SelectObject(&brush); //새로운 브러쉬 선택, 이전 브러쉬 저장
	dc.Ellipse(100, 100, 200, 200); //원을 그린다.
	dc.SelectObject(pOldBrush); //이전 브러쉬 복원, 사용하던 브러시 선택 해제
	*/
	
	/*브러시 사용 예1*/
	/*
	CBrush brush(RGB(255, 0, 0)); //브러시 객체를 만든다.
	dc.SelectObject(&brush); //새로운 브러시를 선택한다.
	dc.Ellipse(100, 100, 200, 200); //원을 그린다.
	*/



	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnLButtonDown(nFlags, point); //주석처리
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnRButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}
