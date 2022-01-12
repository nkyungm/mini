#pragma once

#include "resource.h"

class CMyClass : public CObject
{
	DECLARE_DYNAMIC(CMyClass)  //실행 시간 클래스 정보 기능 추가
	DECLARE_DYNCREATE(CMyClass) //동적 객체 생성 기능 추가
	DECLARE_SERIAL(CMyClass) //직렬화 기능 추가

	int m_start, m_end;
public:
	CMyClass(); //기본 생성자가 반드시 있어야 한다.
	virtual void Serialize(CArchive&ar); //가상 함수 재정의
	virtual void AssertValid() const; //가상 함수 재정의
};