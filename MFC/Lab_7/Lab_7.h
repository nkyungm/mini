
// Lab_7.h : Lab_7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLab_7App:
// �� Ŭ������ ������ ���ؼ��� Lab_7.cpp�� �����Ͻʽÿ�.
//

class CLab_7App : public CWinApp
{
public:
	CLab_7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab_7App theApp;
