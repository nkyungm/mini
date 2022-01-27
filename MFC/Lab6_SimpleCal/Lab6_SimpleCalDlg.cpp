
// Lab6_SimpleCalDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Lab6_SimpleCal.h"
#include "Lab6_SimpleCalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CLab6_SimpleCalDlg 대화 상자



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


// CLab6_SimpleCalDlg 메시지 처리기

BOOL CLab6_SimpleCalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_combo.InsertString(0, _T("+"));  // combo box에 + 추가
	m_combo.InsertString(1, _T("-"));  // combo box에 - 추가
	m_combo.InsertString(2, _T("*")); // combo box에 * 추가
	m_combo.InsertString(3, _T("/"));  // combo box에 / 추가

	m_combo.SetCurSel(0); // combo box 시작을 +부터 시작함

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CLab6_SimpleCalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLab6_SimpleCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab6_SimpleCalDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLab6_SimpleCalDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index;
	CString str;

	GetDlgItemText(IDC_EDIT1, str);// IDC_EDIT1 의 값을 str에 저장
	m_num1 = _wtof(str);

	GetDlgItemText(IDC_EDIT2, str);// IDC_EDIT2 의 값을 str에 저장   
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
			MessageBox(_T("Error!!! (0으로 나눌 수 없음)"));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetDlgItemText(IDC_EDIT1, _T("")); // 초기화
	SetDlgItemText(IDC_EDIT2, _T(""));
	SetDlgItemText(IDC_EDIT3, _T(""));
}
