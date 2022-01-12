// Lab3_예제1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Lab3_예제1.h"

IMPLEMENT_DYNAMIC(CMyClass, CObject);  //실행 시간 클래스 정보 기능 추가
IMPLEMENT_DYNCREATE(CMyClass, CObject);//동적 객체 생성 기능 추가
IMPLEMENT_SERIAL(CMyClass,CObject,1) //직렬화 기능 추가

void CMyClass::Serialize(CArchive&ar)
{
	//CObject가 제공하는 가상 함수인 Serialize()를 재정의한다.
}

void CMyClass::AssertValid() const
{
	//베이스 클래스의 AssertValid() 함수를 먼저 호출
	CObject::AssertValid();

	//멤버 변수 m_start 값이 0보다 큰지 검사한다.
	ASSERT(m_start > 0);

	//멤버 변수 m_end 값이 100보다 작은지 검사한다.
	ASSERT(m_end < 100);
}

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

			/*CObject 클래스 예제*/
			/*
			//객체를 동적으로 생성
			CRuntimeClass* pRuntimeClass = RUNTIME_CLASS(CMyClass);
			CObject* pObject = pRuntimeClass->CreateObject();

			//객체 생성 여부 확인
			ASSERT(pObject->IsKindOf(RUNTIME_CLASS(CMyClass)));
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
