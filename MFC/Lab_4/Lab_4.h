
// Lab_4.h : Lab_4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLab_4App:
// �� Ŭ������ ������ ���ؼ��� Lab_4.cpp�� �����Ͻʽÿ�.
//

class CLab_4App : public CWinApp
{
public:
	CLab_4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab_4App theApp;
