// Console2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Console2.h"

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

			setlocale(LC_ALL, "korean");
			_wsetlocale(LC_ALL, L"korean");

			/*CTime 클래스 예제*/
			/*
			CTime::GetCurrentTime() 함수로 현재 시각 구함
			CTime tm;
			tm = CTime::GetCurrentTime();
			//여러 형식으로 화면에 출력
			CString str = tm.Format(_T("%A, %B %d, %Y"));
			_tprintf(_T("%s\n"), str);
			str.Format(_T("현재 시각은 %d시 %d분 %d초입니다."),
				tm.GetHour(), tm.GetMinute(), tm.GetSecond());
			_tprintf(_T("%s\n"), str);
			*/

			/*CTimeSpan 클래스 예제*/
			/*
			CTime startTime = CTime::GetCurrentTime();
			Sleep(2000); //2000밀리초 지연
			CTime endTime = CTime::GetCurrentTime();
			CTimeSpan elapsedTime = endTime - startTime;
			CString str;
			str.Format(_T("%d초 지남!"), elapsedTime.GetTotalSeconds());
			_tprintf(_T("%s\n"), str);
			*/

			/*배열 클래스 예제1-배열 생성과 초기화*/
			/*
			CUIntArray array; //객체를 생성
			array.SetSize(10); //배열 크기 설정
			for (int i = 0; i < 10; i++)
				array[i] = i * 10; //값 대입
			for (int i = 0; i < 10; i++)
				_tprintf(_T("%d "), array[i]); //값 출력
			_tprintf(_T("\n"));
			*/

			/*배열 클래스 예제2-배열 생성과 초기화*/
			/*
			CStringArray array; //객체 생성
			array.SetSize(5); //배열 크기 설정
			for (int i = 0; i < 5; i++)
			{
				CString string;
				string.Format(_T("%d년이 지났습니다."), (i + 1) * 10);
				array[i] = string; //값 대입
			}
			for (int i = 0; i < 5; i++)
				_tprintf(_T("%s\n"), array[i]); //값 출력
			*/

			/*배열 클래스 예제3-배열 원소 삽입과 삭제*/
			/*
			CUIntArray array;
			array.SetSize(5);
			for (int i = 0; i < 5; i++)
				array[i] = i;

			//배열 원소 삽입
			array.InsertAt(3, 77); //인덱스 3 위치에 원소 삽입
			for (int i = 0; i < array.GetSize(); i++) //변경된 배열의 크기만큼 반복
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));

			//배열 원소 삭제
			array.RemoveAt(4); //인덱스 4 위치의 원소 삭제
			for (int i = 0; i < array.GetSize(); i++)
				_tprintf(_T("%d "), array[i]);
			_tprintf(_T("\n"));
			*/

			/*배열 클래스 예제4-템플릿 배열 클래스*/
			//Point3D 객체를 저장할 수 있는 배열 객체 생성
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

			/*리스트 클래스 예제1-리스트 생성과 초기화*/
			
			//CString 객체는 물론이고 일반 문자열도 리스트에 추가할 수 있음
			/*
			TCHAR *szFruits[] = {
				_T("사과"),_T("딸기"),_T("포도"),_T("오렌지"),_T("자두")
			};
			CStringList list; //리스트 객체 생성
			for (int i = 0; i < 5; i++)
				list.AddTail(szFruits[i]); //리스트 끝에 데이터 추가
			*/
			
			/*리스트 클래스 예제2-리스트 순환(위의 예시 계속)*/
			/*
			//리스트 맨 앞에서부터 순환하면서 데이터 출력
			POSITION pos = list.GetHeadPosition();
			while (pos != NULL) {
				CString str = list.GetNext(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));

			//리스트 맨 뒤에서부터 순환하면서 데이터 출력
			pos = list.GetTailPosition();
			while (pos != NULL) {
				CString str = list.GetPrev(pos);
				_tprintf(_T("%s "), str);
			}
			_tprintf(_T("\n"));
			*/

			/*리스트 클래스 예제3-리스트 항목 삽입과 삭제(위의 예시 계속)*/
           /*
			pos = list.Find(_T("포도")); //데이터의 위치를 얻는다
			list.InsertBefore(pos, _T("살구")); //앞쪽에 데이터 삽입
			list.InsertAfter(pos, _T("바나나")); //뒤쪽에 데이터 삽입
			list.RemoveAt(pos); //데이터 삭제

			//리스트 맨 앞에서부터 순환하면서 데이터 출력
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
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
