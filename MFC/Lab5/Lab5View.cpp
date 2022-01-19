
// Lab5View.cpp : CLab5View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Lab5.h"
#endif

#include "Lab5Doc.h"
#include "Lab5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab5View

IMPLEMENT_DYNCREATE(CLab5View, CFormView)

BEGIN_MESSAGE_MAP(CLab5View, CFormView)
	ON_EN_CHANGE(IDC_MYEDIT, &CLab5View::OnEnChangeMyedit)
	ON_EN_MAXTEXT(IDC_MYEDIT, &CLab5View::OnEnMaxtextMyedit)
	ON_BN_CLICKED(IDC_MYBUTTON, &CLab5View::OnBnClickedMybutton)
	
	ON_LBN_SELCHANGE(IDC_LIST1, &CLab5View::OnLbnSelchangeList1)
END_MESSAGE_MAP()

// CLab5View 생성/소멸

CLab5View::CLab5View()
	: CFormView(IDD_LAB5_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CLab5View::~CLab5View()
{
}

void CLab5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYEDIT, m_edit);
	DDX_Control(pDX, IDC_LIST1, list_box);
}

BOOL CLab5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CLab5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_edit.SetLimitText(30);
}


// CLab5View 진단

#ifdef _DEBUG
void CLab5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLab5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLab5Doc* CLab5View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab5Doc)));
	return (CLab5Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab5View 메시지 처리기


void CLab5View::OnEnChangeMyedit()
{
	m_edit.GetWindowText(str);
	//m_static.SetWindowText(str);

	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab5View::OnEnMaxtextMyedit()
{
	MessageBox(_T("최대 길이 도달!"), _T("오류"), MB_ICONERROR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CLab5View::OnBnClickedMybutton()
{
	CString space(""); 
	list_box.AddString(str); //입력한 내용이 아래쪽 편집 컨트롤이 표시할 수 있는 줄의 숫자를 넘는 경우 자동 스크롤
	m_edit.SetWindowText(space);   //입력한 메세지칸 공백 출력
	list_box.SetCurSel(list_box.GetCount() - 1); //가장 마지막에 입력한 내용이 화면에 나타남
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CLab5View::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
