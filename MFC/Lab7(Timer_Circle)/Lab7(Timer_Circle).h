
// Lab7(Timer_Circle).h : Lab7(Timer_Circle) ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLab7Timer_CircleApp:
// �� Ŭ������ ������ ���ؼ��� Lab7(Timer_Circle).cpp�� �����Ͻʽÿ�.
//

class CLab7Timer_CircleApp : public CWinApp
{
public:
	CLab7Timer_CircleApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab7Timer_CircleApp theApp;
