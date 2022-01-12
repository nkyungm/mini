// Console3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Console3.h"

#include "locale.h"
#include "afxtempl.h"
#include "afxcoll.h"
#include <afxtempl.h> //템플릿 클래스 정의를 담고 있다.

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

//3차원 좌표를 저장할 수 있는 클래스
//모든 멤버가 public일 때는 class 대신 struct를 사용하면 좀더 편리
struct Point3D {
	int x, y, z;
	Point3D() {}
	//템플릿 클래스에 사용할 때는 반드시 기본 생성자 필요
	Point3D(int x0, int y0, int z0) { x = x0; y = y0; z = z0; }
};

//CString 타입에 해당하는 해시 함수가 없으므로 정의한다.
template<> UINT AFXAPI HashKey(CString& str)
{
	LPCTSTR key = (LPCTSTR)str;
	return HashKey(key); //LPCTSTR 타입의 해시 함수를 재호출
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 오류 코드를 필요에 따라 수정합니다.
            wprintf(L"심각한 오류: MFC를 초기화하지 못했습니다.\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.

			//한글 출력하기위한 코드들
			//setlocale(LC_ALL, "korean");
			//_wsetlocale(LC_ALL, L"korean");

			/*리스트 클래스 예제4-템플릿 리스트 클래스*/
			/*
			CList<Point3D, Point3D&>list;
			//Point3D 객체를 저장할 수 있는 리스트 객체 생성
			for (int i = 0; i < 5; i++) //리스트 끝에 데이터 추가
				list.AddTail(Point3D(i, i * 10, i * 100));
			//리스트 맨 앞에서부터 순환하면서 데이터 출력
			POSITION pos = list.GetHeadPosition();
			while (pos != NULL) {
				Point3D pt = list.GetNext(pos);
				_tprintf(_T("%d %d %d\n"), pt.x, pt.y, pt.z);
			}
			*/

			/*맵 클래스 예제1-맵 생성과 초기화 및 검색*/
			/*
			//맵 객체를 생성, 초기화
			CMapStringToString map;
			map[_T("사과")] = _T("Apple");
			map[_T("딸기")]= _T("Strawberry");
			map[_T("포도")] = _T("Grape");
			map[_T("우유")] = _T("Milk");

			_tprintf(_T("%d %d %d %d\n"), "사과","딸기","포도","우유"); //map의 순서??

			//특정 키값을 가진 데이터 검색
			CString str;
			if (map.Lookup(_T("딸기"), str))
				_tprintf(_T("딸기 -> %s\n"), str);
			*/

			/*맵 클래스 예제2-맵 순환(앞에 예제 계속)*/
			/*
			//이거 왜 순서 우유 -> 딸기 -> 포도 -> 사과 인가??
			_tprintf(_T("\n"));
			//맵 순환하면서 모든 키와 데이터값 출력
			POSITION pos = map.GetStartPosition();
			while (pos != NULL) {
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			*/

			/*맵 클래스 예제3-맵 데이터 삽입과 삭제(앞에 예제 계속)*/
			/*
			_tprintf(_T("\n"));
			map.RemoveKey(_T("우유")); //키값 "우유"에 해당하는 데이터 삭제
			map[_T("수박")] = _T("Watermelon"); //map.SetAt(_T("수박"),_T("Watermelon"));
			//맵을 순환하면서 모든 키와 데이터 값 출력
			pos = map.GetStartPosition();
			while (pos != NULL) {
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}
			*/

			/*맵 클래스 예제4-맵 최적화*/
			/*
			CMapStringToString map; //맵 객체 생성
			map.InitHashTable(12007); //해시 테이블 크기 12007로 바꾼다.
			*/
			
			/*맵 클래스 예제5-템플릿 맵 클래스*/
			/*
			//콘솔에서 한글(유니코드)을 출력하려면 필요
			_tsetlocale(LC_ALL, _T(""));

			//맵(CString->UINT) 객체를 생성하고 초기화
			CMap<CString, CString&, UINT, UINT&> map;
			map[CString(_T("사과"))] = 10;
			map[CString(_T("딸기"))] = 25;
			map[CString(_T("포도"))] = 40;
			map[CString(_T("수박"))] = 15;

			//특정 키값을 가진 데이터 검색
			UINT  nCount;
			if (map.Lookup(CString(_T("수박")), nCount))
				_tprintf(_T("수박 %d상자가 남아 있습니다.\n"), nCount);
			*/
			//남경민
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
