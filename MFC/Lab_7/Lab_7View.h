
// Lab_7View.h : CLab_7View 클래스의 인터페이스
//

#pragma once
struct ThreadArg
{
	CWnd *pWnd; //출력할 대상 윈도우 객체의 주소
	int pos; //1이면 위쪽에, 2면 아래쪽에 출력
};

class CLab_7View : public CView
{
protected: // serialization에서만 만들어집니다.
	CLab_7View();
	DECLARE_DYNCREATE(CLab_7View)

// 특성입니다.
public:
	CLab_7Doc* GetDocument() const;
	CWinThread *pThread1, *pThread2; //스레드 객체 주소
	ThreadArg arg1, arg2; //스레드 전달 인자

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CLab_7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Lab_7View.cpp의 디버그 버전
inline CLab_7Doc* CLab_7View::GetDocument() const
   { return reinterpret_cast<CLab_7Doc*>(m_pDocument); }
#endif

