
// Lab5View.cpp : CLab5View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CLab5View ����/�Ҹ�

CLab5View::CLab5View()
	: CFormView(IDD_LAB5_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CLab5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_edit.SetLimitText(30);
}


// CLab5View ����

#ifdef _DEBUG
void CLab5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CLab5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLab5Doc* CLab5View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab5Doc)));
	return (CLab5Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab5View �޽��� ó����


void CLab5View::OnEnChangeMyedit()
{
	m_edit.GetWindowText(str);
	//m_static.SetWindowText(str);

	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CLab5View::OnEnMaxtextMyedit()
{
	MessageBox(_T("�ִ� ���� ����!"), _T("����"), MB_ICONERROR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CLab5View::OnBnClickedMybutton()
{
	CString space(""); 
	list_box.AddString(str); //�Է��� ������ �Ʒ��� ���� ��Ʈ���� ǥ���� �� �ִ� ���� ���ڸ� �Ѵ� ��� �ڵ� ��ũ��
	m_edit.SetWindowText(space);   //�Է��� �޼���ĭ ���� ���
	list_box.SetCurSel(list_box.GetCount() - 1); //���� �������� �Է��� ������ ȭ�鿡 ��Ÿ��
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CLab5View::OnLbnSelchangeList1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
