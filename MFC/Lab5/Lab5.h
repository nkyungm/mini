
// Lab5.h : Lab5 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLab5App:
// �� Ŭ������ ������ ���ؼ��� Lab5.cpp�� �����Ͻʽÿ�.
//

class CLab5App : public CWinApp
{
public:
	CLab5App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab5App theApp;
