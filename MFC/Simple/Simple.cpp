
// Simple.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Simple.h"
#include "MainFrm.h"
//추가
#include <fstream>
#include <iostream>
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std; //추가

// CSimpleApp

BEGIN_MESSAGE_MAP(CSimpleApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CSimpleApp::OnAppAbout)
END_MESSAGE_MAP()


// CSimpleApp 생성

CSimpleApp::CSimpleApp()
{
	// TODO: 아래 응용 프로그램 ID 문자열을 고유 ID 문자열로 바꾸십시오(권장).
	// 문자열에 대한 서식: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Simple.AppID.NoVersion"));

	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 유일한 CSimpleApp 개체입니다.

CSimpleApp theApp;


// CSimpleApp 초기화

BOOL CSimpleApp::InitInstance()
{
	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// RichEdit 컨트롤을 사용하려면  AfxInitRichEdit2()가 있어야 합니다.	
	// AfxInitRichEdit2();

	// 표준 초기화
	// 이들 기능을 사용하지 않고 최종 실행 파일의 크기를 줄이려면
	// 아래에서 필요 없는 특정 초기화
	// 루틴을 제거해야 합니다.
	// 해당 설정이 저장된 레지스트리 키를 변경하십시오.
	// TODO: 이 문자열을 회사 또는 조직의 이름과 같은
	// 적절한 내용으로 수정해야 합니다.
	SetRegistryKey(_T("로컬 응용 프로그램 마법사에서 생성된 응용 프로그램"));

	/*C++ 함수 사용*/
	/* 
	string str;
	ifstream fin;
	fin.open("sample.txt"); //파일열기
	
	if (fin.is_open()) //파일이 열렸는지 확인
	{
		while (!fin.eof()) //파일 끝까지 읽었는지 확인
		{
			getline(fin, str); //파일 읽어 문자열 str에 저장
		}
	}
	
	text= str.c_str(); //파일 내 문자열을 CString 클래스 객체로 보관

	fin.close(); //파일 닫기
	*/

	/*C언어 함수 사용*/
	char str[100];
	FILE* fp;
	fopen_s(&fp,"sample.txt", "r"); //파일열기

	if (fp == NULL) //파일이 열렸는지 확인
	{
		printf("실패\n");
		return -1;
	}
	
	while (!feof(fp)) //파일 끝까지 읽었는지 확인
	{
		fgets(str, 100, fp); //파일 읽어 문자열 str에 저장
	}

	text = str; //파일 내 문자열을 CString 클래스 객체로 보관

	fclose(fp); //파일 닫기


	// 주 창을 만들기 위해 이 코드에서는 새 프레임 창 개체를
	// 만든 다음 이를 응용 프로그램의 주 창 개체로 설정합니다.
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 프레임을 만들어 리소스와 함께 로드합니다.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);





	// 창 하나만 초기화되었으므로 이를 표시하고 업데이트합니다.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CSimpleApp::ExitInstance()
{
	//TODO: 추가한 추가 리소스를 처리합니다.
	return CWinApp::ExitInstance();
}

// CSimpleApp 메시지 처리기


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

// 대화 상자를 실행하기 위한 응용 프로그램 명령입니다.
void CSimpleApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CSimpleApp 메시지 처리기



