
// Lab6_SimpleCalDlg.h : ��� ����
//

#pragma once


// CLab6_SimpleCalDlg ��ȭ ����
class CLab6_SimpleCalDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CLab6_SimpleCalDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB6_SIMPLECAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
