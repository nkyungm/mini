
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	/*CPaintDC Ŭ���� ����*/
	/*
	dc.Rectangle(0, 0, 200, 100);
	dc.Ellipse(200, 100, 500, 200);
	*/

	/*�� ���� ���*/
	/*
	CPen pen(PS_SOLID, 2, RGB(255, 0, 0)); //���� 2�� ������ ��(���1)

	CPen pen;
	pen.CreatePen(PS_SOLID,2, RGB(255, 0, 0)); //���� 2�� ������ ��(���2)
	*/

	/*�� ��� ��1*/
	/*
	CPen pen(PS_SOLID, 1, RGB(0, 0, 255)); //�� ��ü�� �����.
	CPen *pOldPen = dc.SelectObject(&pen); //���ο� �� ����, ���� �� ����
	dc.Rectangle(100, 100, 200, 200); //���簢���� �׸���.
	dc.SelectObject(pOldPen); //���� �� ����, ����ϴ� �� ���� ����
	*/

	/*�� ��� ��2*/
	/*
	CPen pen(PS_SOLID,1, RGB(0, 0, 255)); //�� ��ü�� �����.
	dc.SelectObject(&pen); //���ο� ���� �����Ѵ�.
	dc.Rectangle(100, 100, 200, 200); //���簢���� �׸���.
	*/

	/*�귯�� ��� ��1*/
	/*
	CBrush brush(RGB(255, 0, 0)); //�귯�� ��ü�� �����.
	CBrush *pOldBrush = dc.SelectObject(&brush); //���ο� �귯�� ����, ���� �귯�� ����
	dc.Ellipse(100, 100, 200, 200); //���� �׸���.
	dc.SelectObject(pOldBrush); //���� �귯�� ����, ����ϴ� �귯�� ���� ����
	*/
	
	/*�귯�� ��� ��1*/
	/*
	CBrush brush(RGB(255, 0, 0)); //�귯�� ��ü�� �����.
	dc.SelectObject(&brush); //���ο� �귯�ø� �����Ѵ�.
	dc.Ellipse(100, 100, 200, 200); //���� �׸���.
	*/



	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//CWnd::OnLButtonDown(nFlags, point); //�ּ�ó��
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//CWnd::OnRButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}
