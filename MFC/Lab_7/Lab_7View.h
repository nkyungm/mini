
// Lab_7View.h : CLab_7View Ŭ������ �������̽�
//

#pragma once
struct ThreadArg
{
	CWnd *pWnd; //����� ��� ������ ��ü�� �ּ�
	int pos; //1�̸� ���ʿ�, 2�� �Ʒ��ʿ� ���
};

class CLab_7View : public CView
{
protected: // serialization������ ��������ϴ�.
	CLab_7View();
	DECLARE_DYNCREATE(CLab_7View)

// Ư���Դϴ�.
public:
	CLab_7Doc* GetDocument() const;
	CWinThread *pThread1, *pThread2; //������ ��ü �ּ�
	ThreadArg arg1, arg2; //������ ���� ����

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CLab_7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Lab_7View.cpp�� ����� ����
inline CLab_7Doc* CLab_7View::GetDocument() const
   { return reinterpret_cast<CLab_7Doc*>(m_pDocument); }
#endif

