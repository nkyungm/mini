
// Lab6_SimpleCal.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLab6_SimpleCalApp:
// �� Ŭ������ ������ ���ؼ��� Lab6_SimpleCal.cpp�� �����Ͻʽÿ�.
//

class CLab6_SimpleCalApp : public CWinApp
{
public:
	CLab6_SimpleCalApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLab6_SimpleCalApp theApp;