// ����_�ǽ�2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "����_�ǽ�2.h"
#include<string>

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

			std::string str1;
			CString s1, s2;
			CString op("+-*/");
			int op_position;
			CString x, y;

			_tsetlocale(LC_ALL, _T("")); //�ѱ� ���

			_tprintf(_T("��Ģ���� ������ �Է��Ͻÿ�:"));
			_tprintf(_T("\n"));
			getline(cin, str1); //����ڷκ��� ���ڿ� �Է¹ޱ�

			CString str2;
			str2 = str1.c_str(); //std::string -> CString

			str2.Replace(_T(" "), NULL); //��� ���� ���ֱ�

			op_position = str2.FindOneOf(op); //������ op�� ��ġ ã�Ƽ� ��ġ�� ��ȯ
			x = str2.Left(op_position); //������ �������� ���ڿ� ����
			y = str2.Right(op_position); //�������� �������� ���ڿ� ����

			double d_x = _wtof(x); //CString -> double
			double d_y = _wtof(y); //CString -> double

			if (str2[op_position] == '+')
				_tprintf(_T("%.6lf"), d_x + d_y);

			else if(str2[op_position] == '-')
				_tprintf(_T("%.6lf"), d_x - d_y);

			else if (str2[op_position] == '*')
				_tprintf(_T("%.6lf"), d_x * d_y);

			else if (str2[op_position] == '/')
				_tprintf(_T("%.6lf"), d_x / d_y);

			_tprintf(_T("\n"));
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
