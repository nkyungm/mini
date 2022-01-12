// Console.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Console.h"

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
            wprintf(L"�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n"); //wprintf = _tprintf ?
            nRetCode = 1;
        }
        else
        {
            // TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.;
			_tsetlocale(LC_ALL, _T(""));
			/*Console ���� �ڵ�*/
			/*
			CString str; //���ڿ����� ����
			str.LoadStringW(IDS_APP_TITLE); //str�� cpp �̸� load
			_tprintf(_T("Hello from %s!\n"), str); //���
			*/

			/*CString ����1*/
			/*
			CString str1;
			//TCHAR : ������Ʈ�� �������� ������ �����ϰ� ����� �� �ִ� ���� �ڷ���
			//_T : TCHAR������ ������ִ� ��ũ��
			str1 = _T("�ȳ��ϼ���."); //���ڿ��� ���� ����
			CString str2(_T("������")); //���ڿ��� ������ ���ڷ� ����
			CString str3(str2); //CString ��ü�� ������ ���ڷ� ���� 
			//CString ��ü�� ���ڿ��� ����
			CString str4 = str1 + _T(" ") + str2 + _T(" ��ſ� ���Դϴ�. ");
			_tprintf(_T("%s\n"), str1);
			_tprintf(_T("%s\n"), str2);
			_tprintf(_T("%s\n"), str3);
			_tprintf(_T("%s\n"), str4);
			//+= �����ڸ� �̿��Ͽ� ���� ���ڿ��� ���ο� ���ڿ��� �����δ�.
			str4 += _T(" ������");
			_tprintf(_T("%s\n"), str4);
			 */
			
			/*CString ����2 - Format() �Լ�*/
			/*
			CString str;
			str.Format(_T("x=%d, y=%d\n"), 100, 200); //����ȯ
			MessageBox(NULL, str, _T("CString::Format() ����"), MB_OK);
			*/

			/*CString ����3*/
			/*
			CString str;
			str.LoadStringW(IDS_APP_TITLE); //���ڿ� ���ҽ��� �ε�
			str.Insert(0, _T("Hello from ")); //�� �տ� ���ڿ� ����
			str.Append(_T("!")); //�� ���� ���ڿ� ������
			MessageBox(NULL, str, _T("CString::LoadString() ����"), MB_OK);
			*/

			/*��ĳ���� ����*/ 
			/* 
			void SomeFunc(POINT pt); //�Լ� ���� ����, �� �Լ� ¥���ϴ°�?
			POINT pt1 = { 100,200 }; //POINT ����ü ���� ����
			CPoint pt2(300, 400); //CPoint Ŭ���� ��ü ����
			SomeFunc(pt1); //OK! (Ÿ�� ��ġ)
			SomeFunc(pt2); //OK! (��ĳ����)
			*/

			/*CPoint Ŭ���� ����*/
			//CPoint pt1(10, 20); //x,y��ǥ�� ������ ���ڷ� ����
			//POINT pt = { 30,40 };
			//CPoint pt2(pt); //POINT Ÿ�� ������ ������ ���ڷ� ����
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//pt1.Offset(40, 30); //x,y ��ǥ�� ���� 40,30�� ���Ѵ�.
			//pt2.Offset(20, 10); //x,y ��ǥ�� ���� 20,10�� ���Ѵ�.
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//if (pt1 == pt2) //�� ��ü�� ������ ������ Ȯ��
			//	_tprintf(_T("�� ���� ��ǥ�� �����ϴ�.\n"));
			//else
			//	_tprintf(_T("�� ���� ��ǥ�� �ٸ��ϴ�.\n"));

			/*CRect Ŭ���� ����*/
			/* 
			CRect rect1(0, 0, 200, 100); //���簢���� ��ǥ�� �������� ���ڷ� ����
			CRect rect2;
			rect2.SetRect(0, 0, 200, 100); //���簢���� ��ǥ�� ���� �߿� �����Ѵ�.
			if (rect1 == rect2) //�� ��ü�� ������ ������ Ȯ��
				_tprintf(_T("�� ���簢���� ��ǥ�� �����ϴ�.\n "));
			else
				_tprintf(_T("�� ���簢���� ��ǥ�� �ٸ��ϴ�.\n "));
			RECT rect = { 100,100,300,200 };
			CRect rect3(rect); //RECT Ÿ�� ������ ������ ���ڷ� ����
			_tprintf(_T("%d, %d\n"), rect3.Width(),rect3.Height());

			CPoint pt(200, 150);
			if (rect3.PtInRect(pt)) //���� ���簢�� ���ο� �ִ��� �Ǵ�
				_tprintf(_T("���� ���簢�� ���ο� �ֽ��ϴ�.\n "));
			else
				_tprintf(_T("���� ���簢�� �ܺο� �ֽ��ϴ�.\n "));
		    */

			/*CSize Ŭ���� ����*/
			/*
			CSize size1(100, 200); //���� ���̸� ������ ���ڷ� ����
			SIZE size = { 100,200 };
			CSize size2(size); //SIZE Ÿ�� ������ ������ ���ڷ� ����
			_tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
			if (size1 == size2) //�� ��ü�� ������ ������ Ȯ��
				_tprintf(_T("ũ�Ⱑ �����ϴ�.\n"));
			else
				_tprintf(_T("ũ�Ⱑ �ٸ��ϴ�.\n"));
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
