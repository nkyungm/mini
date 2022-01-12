// 데통_실습2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "데통_실습2.h"
#include<string>

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
            wprintf(L"심각한 오류: MFC를 초기화하지 못했습니다.\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.

			std::string str1;
			CString s1, s2;
			CString op("+-*/");
			int op_position;
			CString x, y;

			_tsetlocale(LC_ALL, _T("")); //한글 출력

			_tprintf(_T("사칙연산 수식을 입력하시오:"));
			_tprintf(_T("\n"));
			getline(cin, str1); //사용자로부터 문자열 입력받기

			CString str2;
			str2 = str1.c_str(); //std::string -> CString

			str2.Replace(_T(" "), NULL); //모든 공백 없애기

			op_position = str2.FindOneOf(op); //연산자 op의 위치 찾아서 위치값 반환
			x = str2.Left(op_position); //왼쪽을 기준으로 문자열 추출
			y = str2.Right(op_position); //오른쪽을 기준으로 문자열 추출

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
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
