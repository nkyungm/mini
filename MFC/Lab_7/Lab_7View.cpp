
// Lab_7View.cpp : CLab_7View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Lab_7.h"
#endif

#include "Lab_7Doc.h"
#include "Lab_7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab_7View

IMPLEMENT_DYNCREATE(CLab_7View, CView)

BEGIN_MESSAGE_MAP(CLab_7View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CLab_7View ����/�Ҹ�

CLab_7View::CLab_7View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLab_7View::~CLab_7View()
{
}

BOOL CLab_7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLab_7View �׸���

void CLab_7View::OnDraw(CDC* /*pDC*/)
{
	CLab_7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CLab_7View �μ�

BOOL CLab_7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CLab_7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CLab_7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CLab_7View ����

#ifdef _DEBUG
void CLab_7View::AssertValid() const
{
	CView::AssertValid();
}

void CLab_7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab_7Doc* CLab_7View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab_7Doc)));
	return (CLab_7Doc*)m_pDocument;
}

#define LOOPCNT (200000)
#define DIVCNT (LOOPCNT/500)

UINT MyDraw(LPVOID arg)
{
	ThreadArg *pArg = (ThreadArg *)arg;
	CClientDC dc(pArg->pWnd);
	int x, y, i;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(0, 0, 255));

	//���� �ٸ� ��ġ�� ���� �ӵ��� ���븦 ����Ѵ�
	switch (pArg->pos) {
	case1:
		dc.SelectObject(&brush1);
		x = 50; y = 50;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	case2:
		dc.SelectObject(&brush2);
		x = 50; y = 100;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}
	return 0;
}

// CLab_7View �޽��� ó����



void CLab_7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//ȭ���� �����
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	//ù ��° �����带 ���� ���·� �����Ѵ�
	arg1.pWnd = this; //�� ��ü�� �ּ�
	arg1.pos = 1;
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);


	//�� ��° �����带 ���� ���·� �����Ѵ�
	arg2.pWnd = this; //�� ��ü�� �ּ�
	arg2.pos = 2;
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	//�� ��° �������� �켱���� ������ �����Ѵ�
	pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);

	//�� �������� ������ �簳�Ѵ�
	pThread1->ResumeThread();
	pThread2->ResumeThread();
}
#endif //_DEBUG
