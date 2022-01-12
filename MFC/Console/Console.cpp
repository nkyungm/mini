// Console.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Console.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

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
            wprintf(L"심각한 오류: MFC를 초기화하지 못했습니다.\n"); //wprintf = _tprintf ?
            nRetCode = 1;
        }
        else
        {
            // TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.;
			_tsetlocale(LC_ALL, _T(""));
			/*Console 예제 코드*/
			/*
			CString str; //문자열변수 선언
			str.LoadStringW(IDS_APP_TITLE); //str에 cpp 이름 load
			_tprintf(_T("Hello from %s!\n"), str); //출력
			*/

			/*CString 예제1*/
			/*
			CString str1;
			//TCHAR : 프로젝트의 문자집합 설정과 무관하게 사용할 수 있는 문자 자료형
			//_T : TCHAR형으로 만들어주는 매크로
			str1 = _T("안녕하세요."); //문자열에 직접 대입
			CString str2(_T("오늘은")); //문자열을 생성자 인자로 전달
			CString str3(str2); //CString 객체를 생성자 인자로 전달 
			//CString 객체와 문자열을 붙임
			CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다. ");
			_tprintf(_T("%s\n"), str1);
			_tprintf(_T("%s\n"), str2);
			_tprintf(_T("%s\n"), str3);
			_tprintf(_T("%s\n"), str4);
			//+= 연산자를 이용하여 기존 문자열에 새로운 문자열을 덧붙인다.
			str4 += _T(" 하하하");
			_tprintf(_T("%s\n"), str4);
			 */
			
			/*CString 예제2 - Format() 함수*/
			/*
			CString str;
			str.Format(_T("x=%d, y=%d\n"), 100, 200); //형변환
			MessageBox(NULL, str, _T("CString::Format() 연습"), MB_OK);
			*/

			/*CString 예제3*/
			/*
			CString str;
			str.LoadStringW(IDS_APP_TITLE); //문자열 리소스를 로드
			str.Insert(0, _T("Hello from ")); //맨 앞에 문자열 삽입
			str.Append(_T("!")); //맨 끝에 문자열 덧붙임
			MessageBox(NULL, str, _T("CString::LoadString() 연습"), MB_OK);
			*/

			/*업캐스팅 예제*/ 
			/* 
			void SomeFunc(POINT pt); //함수 원형 선언, 이 함수 짜야하는가?
			POINT pt1 = { 100,200 }; //POINT 구조체 변수 정의
			CPoint pt2(300, 400); //CPoint 클래스 객체 정의
			SomeFunc(pt1); //OK! (타입 일치)
			SomeFunc(pt2); //OK! (업캐스팅)
			*/

			/*CPoint 클래스 예제*/
			//CPoint pt1(10, 20); //x,y좌표를 생성자 인자로 전달
			//POINT pt = { 30,40 };
			//CPoint pt2(pt); //POINT 타입 변수를 생성자 인자로 전달
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//pt1.Offset(40, 30); //x,y 좌표에 각각 40,30을 더한다.
			//pt2.Offset(20, 10); //x,y 좌표에 각각 20,10을 더한다.
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//if (pt1 == pt2) //두 객체의 내용이 같은지 확인
			//	_tprintf(_T("두 점의 좌표가 같습니다.\n"));
			//else
			//	_tprintf(_T("두 점의 좌표가 다릅니다.\n"));

			/*CRect 클래스 예제*/
			/* 
			CRect rect1(0, 0, 200, 100); //직사각형의 좌표를 생성자의 인자로 전달
			CRect rect2;
			rect2.SetRect(0, 0, 200, 100); //직사각형의 좌표를 실행 중에 설정한다.
			if (rect1 == rect2) //두 객체의 내용이 같은지 확인
				_tprintf(_T("두 직사각형의 좌표가 같습니다.\n "));
			else
				_tprintf(_T("두 직사각형의 좌표가 다릅니다.\n "));
			RECT rect = { 100,100,300,200 };
			CRect rect3(rect); //RECT 타입 변수를 생성자 인자로 전달
			_tprintf(_T("%d, %d\n"), rect3.Width(),rect3.Height());

			CPoint pt(200, 150);
			if (rect3.PtInRect(pt)) //점이 직사각형 내부에 있는지 판단
				_tprintf(_T("점이 직사각형 내부에 있습니다.\n "));
			else
				_tprintf(_T("점이 직사각형 외부에 있습니다.\n "));
		    */

			/*CSize 클래스 예제*/
			/*
			CSize size1(100, 200); //폭과 높이를 생성자 인자로 전달
			SIZE size = { 100,200 };
			CSize size2(size); //SIZE 타입 변수를 생성자 인자로 전달
			_tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
			if (size1 == size2) //두 객체의 내용이 같은지 확인
				_tprintf(_T("크기가 같습니다.\n"));
			else
				_tprintf(_T("크기가 다릅니다.\n"));
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
