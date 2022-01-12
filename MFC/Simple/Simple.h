
// Simple.h : Simple 응용 프로그램에 대한 주 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CSimpleApp:
// 이 클래스의 구현에 대해서는 Simple.cpp을 참조하십시오.
//

class CSimpleApp : public CWinApp
{
public:
	CSimpleApp();
	CString text; //파일 내 문자열을 CString 클래스 객체로 보관하기위해 헤더파일에 변수 선언

// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimpleApp theApp;
