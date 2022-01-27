
// Lab6_SimpleCalDlg.h : 헤더 파일
//

#pragma once


// CLab6_SimpleCalDlg 대화 상자
class CLab6_SimpleCalDlg : public CDialogEx
{
// 생성입니다.
public:
	CLab6_SimpleCalDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB6_SIMPLECAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	double m_num1;
	double m_num2;
	double m_num3;
	CComboBox m_combo;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedClear();
};
