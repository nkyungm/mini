
// Simple.h : Simple ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSimpleApp:
// �� Ŭ������ ������ ���ؼ��� Simple.cpp�� �����Ͻʽÿ�.
//

class CSimpleApp : public CWinApp
{
public:
	CSimpleApp();
	CString text; //���� �� ���ڿ��� CString Ŭ���� ��ü�� �����ϱ����� ������Ͽ� ���� ����

// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSimpleApp theApp;
