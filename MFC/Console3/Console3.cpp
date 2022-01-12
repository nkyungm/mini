// Console3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Console3.h"

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

//CString Ÿ�Կ� �ش��ϴ� �ؽ� �Լ��� �����Ƿ� �����Ѵ�.
template<> UINT AFXAPI HashKey(CString& str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key); //LPCTSTR Ÿ���� �ؽ� �Լ��� ��ȣ��
}

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

			//�ѱ� ����ϱ����� �ڵ��
			//setlocale(LC_ALL, "korean");
			//_wsetlocale(LC_ALL, L"korean");

			/*����Ʈ Ŭ���� ����4-���ø� ����Ʈ Ŭ����*/
			/*
			CList<Point3D, Point3D&>list;
			//Point3D ��ü�� ������ �� �ִ� ����Ʈ ��ü ����
			for (int i = 0; i < 5; i++) //����Ʈ ���� ������ �߰�
				list.AddTail(Point3D(i, i * 10, i * 100));
			//����Ʈ �� �տ������� ��ȯ�ϸ鼭 ������ ���
			POSITION pos = list.GetHeadPosition();
			while (pos != NULL) {
				Point3D pt = list.GetNext(pos);
				_tprintf(_T("%d %d %d\n"), pt.x, pt.y, pt.z);
			}
			*/

			/*�� Ŭ���� ����1-�� ������ �ʱ�ȭ �� �˻�*/
			/*
			//�� ��ü�� ����, �ʱ�ȭ
			CMapStringToString map;
			map[_T("���")] = _T("Apple");
			map[_T("����")]= _T("Strawberry");
			map[_T("����")] = _T("Grape");
			map[_T("����")] = _T("Milk");

			_tprintf(_T("%d %d %d %d\n"), "���","����","����","����"); //map�� ����??

			//Ư�� Ű���� ���� ������ �˻�
			CString str;
			if (map.Lookup(_T("����"), str))
				_tprintf(_T("���� -> %s\n"), str);
			*/

			/*�� Ŭ���� ����2-�� ��ȯ(�տ� ���� ���)*/
			/*
			//�̰� �� ���� ���� -> ���� -> ���� -> ��� �ΰ�??
			_tprintf(_T("\n"));
			//�� ��ȯ�ϸ鼭 ��� Ű�� �����Ͱ� ���
			POSITION pos = map.GetStartPosition();
			while (pos != NULL) {
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			*/

			/*�� Ŭ���� ����3-�� ������ ���԰� ����(�տ� ���� ���)*/
			/*
			_tprintf(_T("\n"));
			map.RemoveKey(_T("����")); //Ű�� "����"�� �ش��ϴ� ������ ����
			map[_T("����")] = _T("Watermelon"); //map.SetAt(_T("����"),_T("Watermelon"));
			//���� ��ȯ�ϸ鼭 ��� Ű�� ������ �� ���
			pos = map.GetStartPosition();
			while (pos != NULL) {
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			*/

			/*�� Ŭ���� ����4-�� ����ȭ*/
			/*
			CMapStringToString map; //�� ��ü ����
			map.InitHashTable(12007); //�ؽ� ���̺� ũ�� 12007�� �ٲ۴�.
			*/
			
			/*�� Ŭ���� ����5-���ø� �� Ŭ����*/
			/*
			//�ֿܼ��� �ѱ�(�����ڵ�)�� ����Ϸ��� �ʿ�
			_tsetlocale(LC_ALL, _T(""));

			//��(CString->UINT) ��ü�� �����ϰ� �ʱ�ȭ
			CMap<CString, CString&, UINT, UINT&> map;
			map[CString(_T("���"))] = 10;
			map[CString(_T("����"))] = 25;
			map[CString(_T("����"))] = 40;
			map[CString(_T("����"))] = 15;

			//Ư�� Ű���� ���� ������ �˻�
			UINT  nCount;
			if (map.Lookup(CString(_T("����")), nCount))
				_tprintf(_T("���� %d���ڰ� ���� �ֽ��ϴ�.\n"), nCount);
			*/
			//�����
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
