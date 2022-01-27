
// Lab6_SimpleCalDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Lab6_SimpleCal.h"
#include "Lab6_SimpleCalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLab6_SimpleCalDlg ��ȭ ����



CLab6_SimpleCalDlg::CLab6_SimpleCalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LAB6_SIMPLECAL_DIALOG, pParent),
	m_num1(0)
	,m_num2(0)
	,m_num3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab6_SimpleCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDV_MinMaxDouble(pDX, m_num1, 1, 99);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDV_MinMaxDouble(pDX, m_num2, 1, 99);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDV_MinMaxDouble(pDX, m_num3, 1, 99);
}

BEGIN_MESSAGE_MAP(CLab6_SimpleCalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CLab6_SimpleCalDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CLab6_SimpleCalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CLEAR, &CLab6_SimpleCalDlg::OnBnClickedClear)
END_MESSAGE_MAP()


// CLab6_SimpleCalDlg �޽��� ó����

BOOL CLab6_SimpleCalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_combo.InsertString(0, _T("+"));  // combo box�� + �߰�
	m_combo.InsertString(1, _T("-"));  // combo box�� - �߰�
	m_combo.InsertString(2, _T("*")); // combo box�� * �߰�
	m_combo.InsertString(3, _T("/"));  // combo box�� / �߰�

	m_combo.SetCurSel(0); // combo box ������ +���� ������

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CLab6_SimpleCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLab6_SimpleCalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLab6_SimpleCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab6_SimpleCalDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CLab6_SimpleCalDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int index;
	CString str;

	GetDlgItemText(IDC_EDIT1, str);// IDC_EDIT1 �� ���� str�� ����
	m_num1 = _wtof(str);

	GetDlgItemText(IDC_EDIT2, str);// IDC_EDIT2 �� ���� str�� ����   
	m_num2 = _wtof(str);

	m_combo.GetLBText(m_combo.GetCurSel(), str);

	if (str == '+')
	{
		m_num3 = m_num1 + m_num2;
	}
	else if (str == '-')
	{
		m_num3 = m_num1 - m_num2;
	}
	else if (str == '*')
	{
		m_num3 = m_num1 *m_num2;
	}
	else if (str == '/')
	{
		if (m_num2 == 0)
		{
			MessageBox(_T("Error!!! (0���� ���� �� ����)"));
			return;
		}
		else
		{
			m_num3 = m_num1 / m_num2;
		}

	}
	str.Format(_T("%.3f"), m_num3);
	SetDlgItemText(IDC_EDIT3, str);
}


void CLab6_SimpleCalDlg::OnBnClickedClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	SetDlgItemText(IDC_EDIT1, _T("")); // �ʱ�ȭ
	SetDlgItemText(IDC_EDIT2, _T(""));
	SetDlgItemText(IDC_EDIT3, _T(""));
}
