
// Lab6.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CLab6App:
// �� Ŭ������ ������ ���ؼ��� Lab6.cpp�� �����Ͻʽÿ�.
//

class CLab6App : public CWinApp
{
public:
	CLab6App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CLab6App theApp;