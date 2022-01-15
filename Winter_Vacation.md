# 📌[PYTHON]

<details>

<summary> 2022.1.11(TUE)</summary>
<div markdown="1">
 
## 📝 변수, 표현식 및 코드 + 실습
 
### 1. 변수
 - 변수는 이름이 주어진 메모리로 변수 이름을 통해 데이터를 저장하고 검색 가능
 - 프로그래머가 변수 이름을 지정
 - 대입문을 통해 변수값을 변경 가능 
 
### 2. 상수
 - 값이 변하지 않아서 숫자, 글자, 문자열과 같은 고정 값을 "상수"라고 함
 - 숫자 상수
 - 문자열 상수는 작은따옴표나 (') 큰따옴표(") 표시
 
### 3. 자료형 
 - 파이썬에서 변수, 문자, 상수라는 "자료형"이 있음
 - 파이썬은 정수와 문자열의 차이를 앎
 - 예를 들어 "+"는 숫자를 "덧셈"하고 문자열을 "연결"
 
 - 파이썬은 "자료형"을 구분
 - 어떤 연산은 금지되어 있음
 - 예를 들어 문자열에 1을 더할 수 없음
 - type() 함수를 써서 자료형을 알 수 있음
 
 - 자료형 변환  
 1. int()
 2. float()

 ### 4. 사용자 입력
 - input() 함수로 멈추고 사용자의 입력값을 받을 수 있음
 - input() 함수는 문자열을 반환
 
 ![image](https://user-images.githubusercontent.com/97418768/148961698-508721bd-690b-44d4-8e1c-c831df9af5e5.png)

 
### 5. 숫자 표현식

| 연산자 | 연산 |  
| :---: | :----: |
| + | 더하기 |    
| - | 빼기 |    
| * | 곱하기 |
| / | 나누기 |
| ** | 거듭제곱 |
| % | 나머지 |

### 6. 실습 
 ![image](https://user-images.githubusercontent.com/97418768/149092415-c7fb3715-5926-49dc-92e1-9b71bc20b130.png)
 ``` PYTHON
 hours=int(input('Enter Hours: '))
 rate=float(input('Enter Rate: '))
 pay=(hours)*(rate)
 print('Pay:',pay)
 ```
</div>
</details>

 
<details>
<summary> 2022.1.12(WED)</summary>
<div markdown="1">

## 📝조건문 실행, 함수 + 실습
 
### 1. 조건문 실행
##### <h4> 1-1 조건문(if else)
 - 비교 연산자
 
| 연산자 | 의미 |    
| :---: | :----: |    
| > | x가 y보다 클 때 True, 그 외에는 False |    
| < | x가 y보다 작을 때 True, 그 외에는 False |
| >= | x가 y보다 크거나 같을 때 True, 그 외에는 False |
| <= | x가 y보다 작거나 같을 때 True, 그 외에는 False |
| == | x와 y가 같을 때 True, 그 외에는 False |
| != | x와 y가 다를 때 True, 그 외에는 False |

- 단일 if문
``` PYTHON
x=5
if x<10:
    print("Smaller")
 ```
 - if else문
``` PYTHON
x=11
if x<10:
   print("Smaller")
else:
   print("Bigger")
 ```
##### <h4> 1-2 조건문(elif)과 예외처리(try,except)
 - 다중 분기(if-elif-else)
 ``` PYTHON
x=21
if x<2:
    print("Small")
elif x<10:
    print("Medium")
else:
    print("Big")
 ```
 - try / except
``` PYTHON
astr='Hello Bob'
try:
    istr=int(astr)
except:
    istr= -1
print('First',istr)

astr='123'
try:
    istr=int(astr)
except:
    istr= -1
print('Second',istr)
 ```
 
##### <h4> 1-3 조건문 실행 실습           
 - 실습1
           
![image](https://user-images.githubusercontent.com/97418768/149092326-c2aba6d3-2520-4049-9ddd-4d4f0b971298.png)
``` PYTHON
hours=input("Enter Hours: ")
rate=input("Enter Rate: ")
if(int(hours)>40):
    pay=40*float(rate)+(float(hours)-40)*15
else:
    pay=float(hours)*float(rate)
print("Pay: ",pay)
 ```
 
 - 실습2
 
 ![image](https://user-images.githubusercontent.com/97418768/149092345-b7e60e42-321f-4a32-92c2-33b0e6f1ab74.png)
``` PYTHON
hours=input("Enter Hours: ")
rate=input("Enter Rate: ")
try:
    hours_f=float(hours)
    rate_f=float(rate)
except:
    print('Error, please enter numeric input')
    quit()

if(hours_f>40):
    pay=40*rate_f+(hours_f-40)*15
else:
    pay=hours_f*rate_f
print("Pay: ",pay)
 ```
### 2. 함수
 - 함수는 반복적으로 호출해야하는 코드의 묶음을 하나의 블럭으로 만들어 이름을 붙여 재사용률을 높인 "코드의 묶음"
##### <h4> 2-1 내장함수
 ex) print(), input(), type(), float(), int()...
 
##### <h4> 2-2 사용자 정의함수
 - 인자를 입력 받고, 계산을 하고, 결과를 반환하는 재사용 가능한 코드
 - 함수를 정의할 때 def 예약어 이용
 - 함수 이름, 괄호 그리고 인자를 이용해 함수 호출
1. 인자(Argument)
 - 인자란 함수를 호출할 때 전달하는 값
2. 매개변수(Parameters)
 - 함수가 정의된 곳에서 변수처럼 사용
``` PYTHON
def greeting(lang):
    print(lang)
greeting("Hello Word")
 ```
3. 반환값(Return Value)
``` PYTHON
def greeting():
    return "Hello"
print(greeting(),"Connect")
print(greeting(),"Python")
 ```
4. Multiple 매개변수 / 인자
``` PYTHON
def add(left,right):
    return left+right
 
print(add(1,2))
 ```
##### <h4> 2-3 함수 실습
![image](https://user-images.githubusercontent.com/97418768/149092101-fb90dd42-34d0-4d60-887f-67dc10f56e8b.png)
``` PYTHON
def computepay(h,r):
    if(h>40):
        return 40*r+(h-40)*15
    else:
        return h*r

hours=input('Enter Hour:')
rate=input('Enter Rate:')

hour_f=float(hours)
rate_f=float(rate)

print("Pay: ",computepay(hour_f,rate_f))
 ```
</div>
</details>

<details>
<summary> 2022.1.13(THU)</summary>
<div markdown="1">    

 
## 📝 백준문제 풀이    
 ### 1. 백준 입출력과 사칙연산 문제풀이
![image](https://user-images.githubusercontent.com/97418768/149474411-4ef612ef-9e11-41c5-b921-3be55f2b8b5e.png)

 ### 2. 백준 if문 문제풀이
![image](https://user-images.githubusercontent.com/97418768/149474518-957c5a08-cb76-4ffb-acdf-c2fad77d6ff1.png)

</div>
</details>
 
 
<details>
<summary> 2022.1.14(FRI)</summary>
<div markdown="1">  
 
 ## 📝 루프와 반복문 + 실습
 ### 1. while 루프
 - 루프(반복 단계)는 각 루프마다 변하는 반복 변수를 가지고 있음
 - 종종 반복 변수는 연속된 숫자를 차례대로 받음
 
 ### 2. for 루프

 ### 3. 반복문
 
 ### 4. 반복문 응용
 
 ### 5. 실습
 
 ![백준_for문](https://user-images.githubusercontent.com/42793489/148317500-8c39860d-2a55-4042-85b5-ea51ab1856c5.PNG)

 </div>
</details>
 
<details>
<summary> 2022.1.15(SAT)</summary>
<div markdown="1">  
 
 ## 📝객체지향 프로그래밍, 클래스와 인스턴스 개념 알아보고 실습하기
 ### 1. 객체지향 프로그래밍 
 - C언어처럼 실행하고자 하는 절차를 정하고, 절차대로 프로그래밍 하는 방법을 절차지향 프로그래밍이라고 한다. 그러나. 현실에서는 단순히 일련의 행위가 아니라 각 물체 간의 관계, 상호작용 등 훨씬 복잡하게 구성되어 있다.
 - 객체 지향 프로그래밍은 절차 지향 프로그래밍의 이러한 단점을 극복하고 물체를 객체로 표현하고, 관계, 상호 작용을 프로그램으로 나타낸다.
 - 자판기를 객체 지향 프로그램으로 구현하면, 관련 물체들을 객체로 추출하고, 이들의 상호작용에 필요한 함수(메소드)와 변수(필드)를 설계를 및 구현한다.
 
 ### 2. 클래스와 인스턴스
 - 클래스는 객체를 만들어 내기 위한 설계 혹은 틀이다.
 - 클래스에 선언된 모양 그대로 생성된 실체가 객체이다. 이러한 연유로 객체를 클래스의 인스턴스라고도 부른다.
 - 하나의 클래스에 여러개의 객체들이 생성될수 있다. 각 객체들은 동일한 속성을 가지고 있지만, 자신만의 고유한 값을 가짐으로 구분된다. 
 
 ### 3. 실습
 
 <details>

<summary> 백준문제 1712번 손익분기점 계산 문제 class 를 이용해서 풀이</summary>
<div markdown="2">
 
 - 소스코드
 
 ![백준_손익분기점_클래스사용_code](https://user-images.githubusercontent.com/42793489/148509965-4e62239e-30f5-4e68-a779-d803c1ef13a8.PNG)

 - 문제풀이 결과 
 
 ![백준_손익분기점_클래스사용](https://user-images.githubusercontent.com/42793489/148510001-6c265268-b73e-44ee-b1d1-a96346804a60.PNG)
 </div>
</details>
 
 <details>

<summary> 백준문제 2292번 벌집 문제 class 를 이용해서 풀이</summary>
<div markdown="2">
 
 - 소스코드
 
![백준_벌집_code](https://user-images.githubusercontent.com/42793489/148516881-8c9ee82a-d531-47c7-8a88-56766f85672b.PNG)


 - 문제풀이 결과 
 
 ![백준_벌집](https://user-images.githubusercontent.com/42793489/148516904-5ace6ae7-b6e2-4b3c-b5f2-a2c7682bc602.PNG)


 </div>
</details>

 </div>
</details>
 
 
  
<details>

<summary> 2022.1.16(SUN) </summary>
<div markdown="1">
 
 ## 📝 상속 / 캡슐화 / 다형성
 
 ### 1. 상속
 - 자식 클래스가 부모 클래스의 기능을 그대로 물려 받을 수 있는 것이 상속이다.
 - 부모 클래스의 private 접근 제한을 갖는 필드 및 메소드는 자식이 물려받을수 없다.
 - 상속 받고자 하는 자식 클래스 옆에 extends 키워드를 붙이고, 상속할 부모 클래스를 작성한다.
 ``` JAVA
 public class parent {};
 public class Child extends parent {}:
 ```
 
 - 상속할 부모는 오직 1명 뿐이다. 다음은 동작하지 않는 코드이다.
 ``` JAVA
 public class parent {};
 public class parent2 {};
 public class Child extends parent, parent2 {}:
 ```
 
 ### 2. 캡슐화
 - 변수와 함수를 하나의 클래스로 묶고 외부에서 쉽게 접근하지 못하도록 하는것 은닉화가 핵심이다. 
 - 외부에서 객체 접근하는데 있어서 정보를 숨기고 객체의 연산을 통해서만 접근가능하게 하는것이다. 
 - 외부에서 특정 객체의 데이터 및 함수를 직접 접근을 막음으로써 변경을 못하게 하고 시스템 확장시 오류를 최소화 할 수 있다는 점에서 은닉화는 장점이 된다. 
 - 캡슐화를 위한 접근 제어자
  ``` JAVA
 public class parent1 {
     private int val1; // 동일한 클래스안에서만 접근이 가능하고, 외부에서는 접근이 불가능하다.
 }; // 다른패키지에서 인스턴스(객체) 생성가능하다.
 private class parent2 {}; //동일한 클래스안에서만 접근이 가능하고,  상속은 안된다.
 protected class parent3 {}; //동일한 패키지 안에서 사용가능하고, 다른 외부 패키지라도 상속받은 클래스에는 접근 가능 
 ```
 ### 3. 다형성 
 - 하나의 객체가 여러 타입을 가질수있는 특징을 다형성이라고한다.
 - JAVA 에서 다형성은 부모 클래스 타입의 참조 변수로 자식 클래스 타입의 인스턴스를 참조할 수 있도록 구현되고 있다.
 - JAVA 에서 부모클래스는 다중상속을 지원하지 않지만, 인터페이스는 더 추상적이기때문에 여러 인터페이스를 상속받는 다중 상속을 지원한다.
 ``` JAVA
 public class child {};
 public class parent {};
 public class child extends parent implements parents1, parents2 {}: // child 객체는 parents 클래스의 객체이면서, parents1, parents2 인터페이스의 객체이기도 하다. 
 ```
</div>
</details>

 </div>
</details>
 
 # 📌[MFC]

 # 📌[BlockChain]
 
 # 📌[Information Security & Web Hacking]
 <details>

<summary> 0강 - 실습을 위한 환경 구축, 웹 해킹 입문 전 기본적인 지식 </summary>
<div markdown="1">
 
## 📝 실습을 위한 환경 구축, 웹 해킹 입문 전 기본적인 지식
 
### 1. 설치
 https://tomatohj.tistory.com/12?category=873511
 
### 2. 기본적인 지식
##### <h4> 2-1 보안
 - 안전을 유지함
 - 사회의 안녕과 질서를 유지함
1. 관리적 방안
 - 개인정보보호법, 정보통신망법, 전자금융감독규정 등 보안 관련 법령에 대한 준수
 - 사내 보안 정책 수립 및 관리
 - 신입 사원 보안 교육
 - ISMS-P, iso27001 등 보안 인증 취득
2. 물리적 방안
 - CCTV 설치 및 운영
 - 출입통제시스템 설치 및 운영
 - 금속탐지기 설치 및 운영
 - 출력물 보안솔루션 도입 및 운영
 - 시건장치 사용
3. 기술적 방안
 - 보안장비를 통한 유해사이트 접근 차단
 - 백신, NAC, EDR 등의 보안 솔루션 도입
 - 시스템 보안 패치 관리
 - 취약점 진단 / 모의해킹
 
##### <h4> 2-2 해킹
 - 컴퓨터 네트워크의 취약한 보안망에 불법적으로 접근하거나 정보 시스템에 유해한 영향을 끼치는 행위
 1. 종류
 - 화이트 햇(white hat) : 악의가 없는 해킹
 - 블랙 햇(black hat) : 타인에게 피해를 주는 불법적인 해킹
 - 그레이 햇(gray hat) : 화이트햇과 블랙햇의 중간
 2. 시스템 해킹
 - 시스템을 대상으로 하는 공격
 - 공격 결과가 시스템의 정상적인 흐름에 영향 미침
 - 시스템의 잘못된 설정, 프로그램의 취약점 등을 이용하여 주어진 권한을 벗어나 관리자로 권한을 상승하는 등 해커가 원하는 방향으로 시스템 공격
 - ex) Buffer Overflow, Use after free etc...
 3. 네트워크 해킹
 - 인터넷 통신구간을 대상으로 하는 공격
 - 공격 결과가 인터넷 통신상에 문제를 일으킴
 - 서비스를 운영하는 시스템에 대하여 수많은 통신을 일으켜 장애를 야기하거나 같은 인터넷 통신구간에서 다른 사람의 통신 내용을 훔쳐보는 등 인터넷 통신 구간에서 문제 일으킴
 - ex) Spoofing, Sniffing, DoS, Flooding etc...
 4. 웹 해킹
 - 웹 서비스를 대상으로 하는 공격
 - 공격 결과 웹 서비스의 기밀성, 무결성, 가용성 침해
 - 회원 가입된 사용자의 정보 유출, 웹 사이트를 통한 악성코드 유포, 사용할 수 없는 가능을 사용하는 등 해커가 웹 서비스의 기밀성, 무결성, 가용성을 침해
 - ex) SQL Injection, XSS, CSRF etc...

</div>
</details>

<details>

<summary> 1강 - 웹 해킹 입문 전 기본적인 지식 </summary>
<div markdown="1">
 
## 📝 웹 해킹 입문 전 기본적인 지식
 
### 1. OS와 네트워크란?
 - 소프트웨어 : 컴퓨터 프로그램 및 그와 관련된 문서들을 통틀어 이르는 말
 - 하드웨어 : 컴퓨터를 구성하는 기계 장치의 몸체를 통틀어 이르는 말
##### <h4> 1-1 OS
 - Operating System의 줄임말, 운영체제
 - 컴퓨터를 사용하기 위한 가장 기본적인 소프트웨어
 
 ![image](https://user-images.githubusercontent.com/97418768/149619675-65e3fcf3-c770-4c66-be7d-095a4d597981.png)
1. OS의 역할
 - 키보드, 마우스, 모니터, 프린터와 같은 입력/출력을 위한 기기 관리
 - 컴퓨터에 생성, 삭제, 변경되는 파일들에 대해 관리
 - 여러 프로그램을 실행하고 관리

##### <h4> 1-2 네트워크
- 어떠한 일이나 문제점을 처리하는 데 각 기관 따위가 긴밀하게 연결되어 조직적이고 효율적으로 움직일 수 있도록 만든 체계
 - Net(그물)처럼 서로서로 연걸된 것
 - ex) 휴먼 네트워크, 컴퓨터 네트워크
 1. 컴퓨터 네트워크
 - 컴퓨터들이 그물처럼 서로서로 연걸된 것
 - 즉, 위치에 상관없이 서로 통신이 가능하다.
 
 2. 컴퓨터 네트워크의 종류
 - LAN(Local Area Network) : 근거리 영역 네트워크
 - MAN(Metropolitan Area Network) : 대도시 영역 네트워크
 - WAN(Wide Area Network) : 광대역 네트워크

 3. 네트워크의 통신 방식
 - 회선 교환 방식 : 발신 장치로부터의 접속 정보에 따라, 스위치 회로망의 입선 단자와 출선 단자 간의 직접적으로 정보가 전달되는 접속 경로를 설정하여 통신 정보를 송수신하는 방식

 ![image](https://user-images.githubusercontent.com/97418768/149619910-cbf80b8e-e4f5-4c2a-b385-759715e25d2c.png)
 - 패킷 교환 방식 : 축적 교환 방식의 일종, 메시지 교환 방식이 전문을 완전히 축출한 다음 송출하는 데 반하여 이 방식은 모든 전문을 패킷 단위로 분할하여 단위마다 수신인의 주소나 그 밖의 정보를 부가하여 전송하는 방식
 
 ![image](https://user-images.githubusercontent.com/97418768/149619957-150171c4-a699-4d6d-92ea-91a0aaf1b466.png)

### 2. IP주소와 도메인
##### <h4> 2-1 IP주소
 - tcp/ip 프로토콜을 사용하여 통신을 할 때, 송신자와 수신자를 구별하기 위한 고유의 주소
 - 컴퓨터의 집 주소 = IP 주소 (Internet Protocol Address)
 - 인터넷에서 사용하는 숫자로 이루어진 컴퓨터의 주소 
 - ex) 192.168.1.2, 172.16.2.160
1. 공인 IP주소
 - 집주소

 ![image](https://user-images.githubusercontent.com/97418768/149620154-710b543b-9e24-4b52-9343-3e2f3a60034c.png)
 
2. 사설 IP주소 (가상 IP주소)
 - 우리집
 
 ![image](https://user-images.githubusercontent.com/97418768/149620162-ffa5c5ae-ad7c-4a1d-9655-e53f3f17d3dd.png)
 
3. 사설 IP주소가 필요한 이유
 - IP주소는 12자리의 숫자로 이루어져 있다 -> 생성할 수 있는 공인 IP주소에 한계가 있다
 - 공인 IP주소는 누구나 접근할 수 있다 -> 누구나 내 컴퓨터에 접근할 수 있다, 누구나 내 컴퓨터를 공격할 수 있다
 
4. 사설 IP주소 확인하는 방법
 - Windows : 윈도우키 + r -> cmd 입력 후 Enter -> ipconfig명령어 입력
 - MAC : Launchpad -> 터미널 검색 후 실행 -> ifconfig명령어 입력
 - Linux : 터미널 실행 -> ifconfig명령어 입력

 ##### <h4> 2-2 도메인
 - 숫자로 이루어진 인터넷상의 컴퓨터 주소를 영문으로 표현한 것
 - 숫자로 된 IP주소는 기억하기 어려움
 - IP주소(숫자 형태의 주소) -> 도메인(영문자 형태의 주소)
 
### 3. 웹
 - WWW(World Wide Web)
 - 제공하는 정보 검색 서비스로 텍스트만 제공했던 기존의 정보 서비스와는 달리 그림, 동화상, 소리 등도 모두 지원
 - 하이퍼텍스트 개념을 도입하여 쉽게 원하는 정보와 관련된 정보를 찾아볼 수 있는 특징이 있음
 - 다른 사이트와의 관계가 거미줄처럼 복잡하게 얽혀 있다 ex) Naver -> Facebook -> Google
##### <h4> 3-1 브라우저
 - 웹 정보를 화면에 표시하는 소프트웨어
 - 종류 : Internet Explorer, Safari, Chrome, Firefox 등
##### <h4> 3-2 웹 캐시
 - 서버 지연을 줄이기 위해 웹페이지, 이미지, 기타 유형의 웹 멀티미디어 등의 웹 문서들을 임시 저장하기 위한 정보기술
 - 방문한 적이 있는 사이트의 그림, 동영상, 내용 등을 저장하는 기술 -> 재방문 시, 저장된 파일을 그대로 불러와, 속도가 빨라짐
##### <h4> 3-3 쿠키
 - 인터넷 웹사이트의 방문기록을 남겨 사용자와 웹사이트 사이를 매개해 주는 정보
 - 사용자와 웹 서비스 간에 필요한 정보
 - ex) 사용자 로그인 구분자(중요)
 
 ![image](https://user-images.githubusercontent.com/97418768/149620494-ae648e3b-935d-462a-880d-9d0367fccbe7.png)

 ### 4. 클라이언트, 서버
 - 클라이언트 : 서버 시스템과 연결하여 주된 작업이나 정보를 서버에게 요청하고 그 결과를 돌려받는 컴퓨터 시스템
 - 서버 : 주된 정보의 제공이나 작업을 수행하는 컴퓨터 시스템, 서버는 클라이언트 시스템이 요청한 작업이나 정보의 수행 결과를 돌려줌
 ##### <h4> 4-1 프론트 엔드, 백엔드
 - 로그인 예시 : 프론트 엔드(로그인을 위한 화면) + 백엔드(ID/PW)가 맞는지 확인하는 기능

 ![image](https://user-images.githubusercontent.com/97418768/149620590-7b8898c8-31a6-4558-87f1-81b06a1b7f24.png)

 ##### <h4> 4-2웹 서핑을 하기 위한 절차
 1. 컴퓨터 조립/구매 -> 하드웨어
 2. 컴퓨터에 Windows 설치 -> 운영체제
 3. 인터넷 익스플로러 실행 -> 브라우저
 4. 사이트 접속 -> 웹
 
 ![image](https://user-images.githubusercontent.com/97418768/149620608-e9c73cfe-bf25-4700-a2da-0c694d2bddcc.png)

 ##### <h4> 4-3 DNS(Domain Name Server)
 - 'sis.snu.ac.kr'와 같이 문자로 구성
 
 ### 5. 웹 서비스 구성 요소
 ##### <h4> 5-1 프론트엔드
 1. 홈페이지 구조 설계 -> HTML
 2. 홈페이지 디자인 -> CSS
 3. 동적인 움직임 개발 -> Javascript
 - 클라이언트 사이드 언어로 개발
 
  ##### <h4> 5-2 백엔드
 1. 사용자의 요청을 받고 응답 -> Web Server 설치
 2. 상황에 맞는 기능 개발 -> PHP, JSP 등 개발
 3. 개발한 기능 해석 -> 해석기 설치 OR WAS 설치
 4. 데이터 저장 -> Database 구축
 - 필요한 소프트웨어 설치, 서버사이드 언어로 개발
 
 ##### <h4> 5-3
 1. Web Server : 사용자의 요청을 받고, 응답해주는 역할 ex) Apache, Nginx 
 2. 서버사이드 언어 : 실질적인 기능을 수행하는 언어 ex) PHP, JSP, ASP 등
 3. 서버사이드 언어 해석기 : 서버사이드 언어를 해석하여 실행함
 - Web Server에 모듈 형태로 설치 ex)PHP
 - 전용 WAS 설치 ex)JSP
 4. WAS(Web Application Server) : 기존 Web Server의 기능에 서버사이드 언어에 대한 해석 기능이 추가된 소프트 웨어
 - ex) Tomcat, JBoss Jeus 등
 5. DataBase : 저장된 데이터의 집합체, DBMS라는 소프트웨어를 통해 데이터를 추가, 삭제, 수정하며 관리함
 6. DBMS(DataBase Management System) : DataBase를 관리하는 소프트웨어
 - ex) MySQL, Oracle, MSSQL 등
 
 ##### <h4> 5-4 웹 서비스를 위해 필요한 것
 1. 클라이언트 사이드 언어로 개발/프로그래밍
 2. Web Server 설치
 3. 서버 사이드 언어로 개발/프로그래밍
 4. 모듈 형태의 해석기 또는 WAS 설치
 5. DBMS 설치
 
 </div>
</details>
