
// Lab7(Timer_Circle)View.cpp : CLab7Timer_CircleView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Lab7(Timer_Circle).h"
#endif

#include "Lab7(Timer_Circle)Doc.h"
#include "Lab7(Timer_Circle)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab7Timer_CircleView

IMPLEMENT_DYNCREATE(CLab7Timer_CircleView, CView)

BEGIN_MESSAGE_MAP(CLab7Timer_CircleView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab7Timer_CircleView ����/�Ҹ�

CLab7Timer_CircleView::CLab7Timer_CircleView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLab7Timer_CircleView::~CLab7Timer_CircleView()
{
}

BOOL CLab7Timer_CircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CLab7Timer_CircleView �׸���

void CLab7Timer_CircleView::OnDraw(CDC* /*pDC*/)
{
	CLab7Timer_CircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CLab7Timer_CircleView �μ�

BOOL CLab7Timer_CircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CLab7Timer_CircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CLab7Timer_CircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CLab7Timer_CircleView ����

#ifdef _DEBUG
void CLab7Timer_CircleView::AssertValid() const
{
	CView::AssertValid();
}

void CLab7Timer_CircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab7Timer_CircleDoc* CLab7Timer_CircleView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab7Timer_CircleDoc)));
	return (CLab7Timer_CircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab7Timer_CircleView �޽��� ó����
