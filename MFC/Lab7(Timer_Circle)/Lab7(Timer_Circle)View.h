
// Lab7(Timer_Circle)View.h : CLab7Timer_CircleView Ŭ������ �������̽�
//

#pragma once


class CLab7Timer_CircleView : public CView
{
protected: // serialization������ ��������ϴ�.
	CLab7Timer_CircleView();
	DECLARE_DYNCREATE(CLab7Timer_CircleView)

// Ư���Դϴ�.
public:
	CLab7Timer_CircleDoc* GetDocument() const;

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
	virtual ~CLab7Timer_CircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Lab7(Timer_Circle)View.cpp�� ����� ����
inline CLab7Timer_CircleDoc* CLab7Timer_CircleView::GetDocument() const
   { return reinterpret_cast<CLab7Timer_CircleDoc*>(m_pDocument); }
#endif

