#pragma once

#include "resource.h"

class CMyClass : public CObject
{
	DECLARE_DYNAMIC(CMyClass)  //���� �ð� Ŭ���� ���� ��� �߰�
	DECLARE_DYNCREATE(CMyClass) //���� ��ü ���� ��� �߰�
	DECLARE_SERIAL(CMyClass) //����ȭ ��� �߰�

	int m_start, m_end;
public:
	CMyClass(); //�⺻ �����ڰ� �ݵ�� �־�� �Ѵ�.
	virtual void Serialize(CArchive&ar); //���� �Լ� ������
	virtual void AssertValid() const; //���� �Լ� ������
};