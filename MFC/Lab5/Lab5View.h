
// Lab5View.h : CLab5View Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"


class CLab5View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CLab5View();
	DECLARE_DYNCREATE(CLab5View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_LAB5_FORM };
#endif

// Ư���Դϴ�.
public:
	CLab5Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CLab5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CString str;
	CString temp;
	afx_msg void OnEnChangeMyedit();
	afx_msg void OnEnMaxtextMyedit();
	CStatic m_static;
	afx_msg void OnBnClickedMybutton();
	afx_msg void OnLbnSelchangeList1();
	CListBox list_box;
};

#ifndef _DEBUG  // Lab5View.cpp�� ����� ����
inline CLab5Doc* CLab5View::GetDocument() const
   { return reinterpret_cast<CLab5Doc*>(m_pDocument); }
#endif

