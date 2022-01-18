
// ChildView.cpp : CChildView Ŭ������ ����
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

	/*����Ʈ �� �տ������� ��ȯ�ϸ鼭 ������ ���
	������ ũ�Ⱑ �ٲ� ������, �� Ŭ������ OnPaint() �Լ��� �ٽ� �׸�*/

	CPoint n=NULL; 
	for (int i = 0; i < count; i++)
	{
		if(square[i]!=n) //�迭�� ���� NULL�� �ƴϸ�
			dc.Rectangle(square[i].x - 20, square[i].y - 20, square[i].x + 20, square[i].y + 20);
		    //�簢�� ���
	}

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//CWnd::OnLButtonDown(nFlags, point); //�ּ�ó��
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20); 
	//���콺 ���� ��ư Ŭ���ϸ� �簢�� ��Ÿ��
	square[count] = point; //�迭�� �簢�� ����
	count++; //�ε����� 1����

	//�� ȭ�鿡�� ���콺 ���� ��ư Ŭ���ϸ� �簢���� ��Ÿ��
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//CWnd::OnRButtonDown(nFlags, point);
	CClientDC dc(this);
	for (int i = 0; i < count; i++)
	{
		//�簢�� ���� Ŭ���ϸ�
		if (square[i].x - 20 <= point.x && point.x <= square[i].x + 20 && square[i].y - 20 <= point.y && point.y <= square[i].y + 20) 
			square[i] = NULL; //�ش� �迭�� �ε��� NULL�� ����
	}

	Invalidate(); //OnDraw()�Լ��� ȣ���Ͽ� ȭ���� �ٽ� �׸��� ����
	
}
