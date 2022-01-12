// Console2.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Console2.h"

#include "locale.h"
#include "afxtempl.h"
#include "afxcoll.h"
#include <afxtempl.h> //���ø� Ŭ���� ���Ǹ� ��� �ִ�.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

//3���� ��ǥ�� ������ �� �ִ� Ŭ����
//��� ����� public�� ���� class ��� struct�� ����ϸ� ���� ��
struct Point3D {
	int x, y, z;
	Point3D() {}
	//���ø� Ŭ������ ����� ���� �ݵ�� �⺻ ������ �ʿ�
	Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

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

			setlocale(LC_ALL, "korean");
			_wsetlocale(LC_ALL, L"korean");

			/*CTime Ŭ���� ����*/
			/*
			CTime::GetCurrentTime() �Լ��� ���� �ð� ����
			CTime tm;
			tm = CTime::GetCurrentTime();
			//���� �������� ȭ�鿡 ���
			CString str = tm.Format(_T("%A, %B %d, %Y"));
			_tprintf(_T("%s\n"), str);
			str.Format(_T("���� �ð��� %d�� %d�� %d���Դϴ�."),
				tm.GetHour(), tm.GetMinute(), tm.GetSecond());
			_tprintf(_T("%s\n"), str);
			*/

			/*CTimeSpan Ŭ���� ����*/
			/*
			CTime startTime = CTime::GetCurrentTime();
			Sleep(2000); //2000�и��� ����
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str;
			str.Format(_T("%d�� ����!"), elapsedTime.GetTotalSeconds());
			_tprintf(_T("%s\n"), str);
			*/

			/*�迭 Ŭ���� ����1-�迭 ������ �ʱ�ȭ*/
			/*
			CUIntArray array; //��ü�� ����
			array.SetSize(10); //�迭 ũ�� ����
			for (int i = 0; i < 10; i++)
				array[i] = i * 10; //�� ����
			for (int i = 0; i < 10; i++)
				_tprintf(_T("%d "), array[i]); //�� ���
			_tprintf(_T("\n"));
			*/

			/*�迭 Ŭ���� ����2-�迭 ������ �ʱ�ȭ*/
			/*
			CStringArray array; //��ü ����
			array.SetSize(5); //�迭 ũ�� ����
			for (int i = 0; i < 5; i++)
			{
				CString string;
				string.Format(_T("%d���� �������ϴ�."), (i + 1) * 10);
				array[i] = string; //�� ����
			}
			for (int i = 0; i < 5; i++)
				_tprintf(_T("%s\n"), array[i]); //�� ���
			*/

			/*�迭 Ŭ���� ����3-�迭 ���� ���԰� ����*/
			/*
			CUIntArray array;
			array.SetSize(5);
			for (int i = 0; i < 5; i++)
				array[i] = i;

			//�迭 ���� ����
			array.InsertAt(3, 77); //�ε��� 3 ��ġ�� ���� ����
			for (int i = 0; i < array.GetSize(); i++) //����� �迭�� ũ�⸸ŭ �ݺ�
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));

			//�迭 ���� ����
			array.RemoveAt(4); //�ε��� 4 ��ġ�� ���� ����
			for (int i = 0; i < array.GetSize(); i++)
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
			*/

			/*�迭 Ŭ���� ����4-���ø� �迭 Ŭ����*/
			//Point3D ��ü�� ������ �� �ִ� �迭 ��ü ����
			/*
			CArray<Point3D, Point3D&> array;
			array.SetSize(5);
			for (int i = 0; i < 5; i++) {
				Point3D pt(i, i * 10, i * 100);
				array[i] = pt;
			}
			for (int i = 0; i < 5; i++) {
				Point3D pt = array[i];
				_tprintf(_T("%d, %d, %d\n"), pt.x, pt.y, pt.z);
			}
			*/

			/*����Ʈ Ŭ���� ����1-����Ʈ ������ �ʱ�ȭ*/
			
			//CString ��ü�� �����̰� �Ϲ� ���ڿ��� ����Ʈ�� �߰��� �� ����
			/*
			TCHAR *szFruits[] = {
				_T("���"),_T("����"),_T("����"),_T("������"),_T("�ڵ�")
			};
			CStringList list; //����Ʈ ��ü ����
			for (int i = 0; i < 5; i++)
				list.AddTail(szFruits[i]); //����Ʈ ���� ������ �߰�
			*/
			
			/*����Ʈ Ŭ���� ����2-����Ʈ ��ȯ(���� ���� ���)*/
			/*
			//����Ʈ �� �տ������� ��ȯ�ϸ鼭 ������ ���
			POSITION pos = list.GetHeadPosition();
			while (pos != NULL) {
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			//����Ʈ �� �ڿ������� ��ȯ�ϸ鼭 ������ ���
			pos = list.GetTailPosition();
			while (pos != NULL) {
				CString str = list.GetPrev(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
			*/

			/*����Ʈ Ŭ���� ����3-����Ʈ �׸� ���԰� ����(���� ���� ���)*/
           /*
			pos = list.Find(_T("����")); //�������� ��ġ�� ��´�
			list.InsertBefore(pos, _T("�챸")); //���ʿ� ������ ����
			list.InsertAfter(pos, _T("�ٳ���")); //���ʿ� ������ ����
			list.RemoveAt(pos); //������ ����

			//����Ʈ �� �տ������� ��ȯ�ϸ鼭 ������ ���
			pos = list.GetHeadPosition();
			while (pos != NULL) {
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
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
