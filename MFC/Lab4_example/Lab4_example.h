
// Lab4_example.h : Lab4_example ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLab4_exampleApp:
// �� Ŭ������ ������ ���ؼ��� Lab4_example.cpp�� �����Ͻʽÿ�.
//

class CLab4_exampleApp : public CWinApp
{
public:
	CLab4_exampleApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab4_exampleApp theApp;
