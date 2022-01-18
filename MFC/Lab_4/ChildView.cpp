
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Lab_4.h"
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

	/*리스트 맨 앞에서부터 순환하면서 데이터 출력
	윈도우 크기가 바뀔 때마다, 뷰 클래스의 OnPaint() 함수에 다시 그림*/

	CPoint n=NULL; 
	for (int i = 0; i < count; i++)
	{
		if(square[i]!=n) //배열중 값이 NULL이 아니면
			dc.Rectangle(square[i].x - 20, square[i].y - 20, square[i].x + 20, square[i].y + 20);
		    //사각형 출력
	}

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnLButtonDown(nFlags, point); //주석처리
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20); 
	//마우스 왼쪽 버튼 클릭하면 사각형 나타남
	square[count] = point; //배열에 사각형 저장
	count++; //인덱스값 1증가

	//뷰 화면에서 마우스 왼쪽 버튼 클릭하면 사각형이 나타남
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//CWnd::OnRButtonDown(nFlags, point);
	CClientDC dc(this);
	for (int i = 0; i < count; i++)
	{
		//사각형 안을 클릭하면
		if (square[i].x - 20 <= point.x && point.x <= square[i].x + 20 && square[i].y - 20 <= point.y && point.y <= square[i].y + 20) 
			square[i] = NULL; //해당 배열의 인덱스 NULL로 변경
	}

	Invalidate(); //OnDraw()함수를 호출하여 화면을 다시 그리는 역할
	
}
