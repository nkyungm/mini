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
 ![image](https://user-images.githubusercontent.com/97418768/148963128-0dbfc46c-7390-44a3-a1e6-d29ccc3042e1.png)
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
           
![image](https://user-images.githubusercontent.com/97418768/149085926-c3f0e237-fe93-42aa-8cbb-544f006332e8.png)
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
 
 ![image](https://user-images.githubusercontent.com/97418768/149086036-d0c86b2e-04f2-4512-bf7a-9cb5f808c289.png)
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

### 2. 조건문(elif)과 예외처리(try,except)
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
</div>
</details>

<details>
<summary> 2022.1.13(THU)</summary>
<div markdown="1">    

 
## 📝연산자/조건문/반복문1 + 백준문제 풀이    
 ### 1. 연산자
 - 연산식은 연산자를 통해 하나의 값을 산출한다.
 - 피 연산자의 수의 따라 단항 연산자, 이항연산자, 삼항 연산자로 구분되어진다.
 - 연산자 종류1
 
 | 연산자 종류 | 연산자 | 피연산자수 | 설명 |   
 | :---: | :----: | :----: | :----: |  
 | 산술연산 | +,-,*,/,% | 이항 | 사칙연산 및 계산 |
 | 부호 | +,- | 단항 | 정수, 실수 타입에 부호 |
 | 문자열 | + | 이항 | 문자형 변수 2개를 연결시킴 |
 | 대입 연산 | =,+= ,-=, *=, <<= ...etc | 이항 | 우변의 값을 좌변 변수에 대입 |
 | 증감 연산 | ++, -- | 단항 | 1만큼 증가/ 감소 |
 | 비교 연산 | ==, !=, <, >, <= ..etc | 이항 | 좌 우변 값 비교 |
 | 논리 연산 | !, &, ||, &&| 이항,단항 | 논리적 NOT, AND, OR 연산 |
 | 조건 연산 | (조건식)? A : B | 삼항 | 조건식에 따라 참일경우 A, 거짓이면 B |
 | 비트 | ~,&,^ | 단항, 이항 | 비트식 NOT, AND, OR 연산 |
 | 비트 쉬프트 | >>,<<,>>> | 이항 | 비트를 좌 or 우측으로 이동 |
 
 - 연산 우선순위  
 1. 단항 - 이항 - 삼항 순으로 우선운위 갖는다.
 2. 산술 - 비교, 논리 - 대입 연산자 순으로 우선순위 갖는다.
 ### 2. 조건문
 - 프로그래밍할 때 일어 날 수 있는 상황조건을 판단해서 그 상황에 맞게 처리하는것이 조건문이다. 
 
 ##### <h4> 2-1 if문
 - if(조건문)에 사용한 조건문으로 참과 거짓을 판단한다.
 - else if 를 사용하여 다중조건 판단을 가능하게 한다. 
 - if 와 else if 조건을 충족 못하는 조건들은 else 문장으로 수행된다.
 
 
 ##### <h4> 2-2 switch/case문
 - 입력변수의 값과 일치하는 case 입력값에 따라 해당 case 문에 속한 문장이 실행된다. case 문장안에 break 문장을 통해 case 문장 실행 뒤 switch 문을 빠져 나간다.
 - 입력값이 정형화 되어있는 경우에는 switch/case 문장을 사용하는것이 편리하다. 
 
 ### 3. 백준문제 풀이
 - if 문 백준 5문제
 
 ![백준_if문](https://user-images.githubusercontent.com/42793489/148174171-5dd8016e-bf28-4cda-a71d-c2da6c8118f7.PNG)

 
 - while 문 백준 3문제
 
 ![백준_while문](https://user-images.githubusercontent.com/42793489/148174178-8cbb3950-6702-42c3-bbcb-43e578a23643.PNG)

</div>
</details>
 
 
<details>
<summary> 2022.1.14(FRI)</summary>
<div markdown="1">  
 
 ## 📝연산자/조건문/반복문2 + 백준문제 풀이 
 ### 1. 반복문
 ##### <h4> 1-1 while 문
 - 조건이 참인 동안 while문 아래의 문장을 반복하여 수행한다. 
 - while문 강제로 멈춰야 하는경우 break 호출하여 while 문 빠져 나가게 한다.
 - while 문 조건문으로 돌아가기 위해 continue 를 호출하여 다시 while문으로 돌아간다.
 
 ##### <h4> 1-2 for 문
 - 세미콜론(;)으로 구분을 한다. 
 - while문과 동일하게 continue를 사용해서 for 문 처음으로 돌아가서 사용이 가능하다. 
 
  ### 2. 백준 for문 문제풀이
 
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
