// Lab3_����1.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Lab3_����1.h"

IMPLEMENT_DYNAMIC(CMyClass, CObject);  //���� �ð� Ŭ���� ���� ��� �߰�
IMPLEMENT_DYNCREATE(CMyClass, CObject);//���� ��ü ���� ��� �߰�
IMPLEMENT_SERIAL(CMyClass,CObject,1) //����ȭ ��� �߰�

void CMyClass::Serialize(CArchive&ar)
{
	//CObject�� �����ϴ� ���� �Լ��� Serialize()�� �������Ѵ�.
}

void CMyClass::AssertValid() const
{
	//���̽� Ŭ������ AssertValid() �Լ��� ���� ȣ��
	CObject::AssertValid();

	//��� ���� m_start ���� 0���� ū�� �˻��Ѵ�.
	ASSERT(m_start > 0);

	//��� ���� m_end ���� 100���� ������ �˻��Ѵ�.
	ASSERT(m_end < 100);
}

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
            wprintf(L"�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.

			/*CObject Ŭ���� ����*/
			/*
			//��ü�� �������� ����
			CRuntimeClass* pRuntimeClass = RUNTIME_CLASS(CMyClass);
			CObject* pObject = pRuntimeClass->CreateObject();

			//��ü ���� ���� Ȯ��
			ASSERT(pObject->IsKindOf(RUNTIME_CLASS(CMyClass)));
			*/

        }
    }
    else
    {
        // TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
        wprintf(L"�ɰ��� ����: GetModuleHandle ����\n");
        nRetCode = 1;
    }

    return nRetCode;
}
