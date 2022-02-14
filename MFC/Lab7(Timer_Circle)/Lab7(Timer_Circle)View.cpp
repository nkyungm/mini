
// Lab7(Timer_Circle)View.cpp : CLab7Timer_CircleView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CLab7Timer_CircleView 생성/소멸

CLab7Timer_CircleView::CLab7Timer_CircleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLab7Timer_CircleView::~CLab7Timer_CircleView()
{
}

BOOL CLab7Timer_CircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CLab7Timer_CircleView 그리기

void CLab7Timer_CircleView::OnDraw(CDC* /*pDC*/)
{
	CLab7Timer_CircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CLab7Timer_CircleView 인쇄

BOOL CLab7Timer_CircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CLab7Timer_CircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CLab7Timer_CircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CLab7Timer_CircleView 진단

#ifdef _DEBUG
void CLab7Timer_CircleView::AssertValid() const
{
	CView::AssertValid();
}

void CLab7Timer_CircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab7Timer_CircleDoc* CLab7Timer_CircleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab7Timer_CircleDoc)));
	return (CLab7Timer_CircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CLab7Timer_CircleView 메시지 처리기
