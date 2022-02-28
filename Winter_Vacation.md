# 📌[PYTHON]

<details>

<summary> 2022.1.11(TUE)</summary>
<div markdown="1">
 
## 📝 변수, 표현식 및 코드 + 실습
 
### 1. 변수
 - 변수는 이름이 주어진 메모리로 변수 이름을 통해 데이터를 저장하고 검색 가능
 - 프로그래머가 변수 이름을 지정
 - 대입문을 통해 변수값을 변경이 가능
 
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
 

 </div>
</details>
 
<details>
<summary> 2022.1.16(SUN) </summary>
<div markdown="1">
 
 ## 📝 백준문제 풀이    
 ### 1. 백준 for문 문제풀이
![image](https://user-images.githubusercontent.com/97418768/149661370-932a61a2-01cf-4eba-846e-eb52aaee835b.png)

</div>
</details>

 </div>
</details>
 
 <details>
<summary> 2022.1.17(MON) </summary>
<div markdown="1">
 
 ## 📝 백준문제 풀이    
 ### 1. 백준 while문 문제풀이
![image](https://user-images.githubusercontent.com/97418768/149787887-247966ec-0bbc-431a-8127-bbb2d9c0afc3.png)
 
 ### 1. 백준 1차원배열 문제풀이
![image](https://user-images.githubusercontent.com/97418768/149787987-a0fb3748-6b6a-455d-bcf2-145d85b57e29.png)

</div>
</details>

 </div>
</details>
  <details>
<summary> 2022.1.18(TUE) </summary>
<div markdown="1">
 
 ## 📝 Coding Test 파이썬 문제풀이(1~30)   
![image](https://user-images.githubusercontent.com/97418768/150154390-0aa50962-ae3d-4416-bb2a-6b00fdf17804.png)
![image](https://user-images.githubusercontent.com/97418768/150154496-5fe644b8-f119-421d-8536-35c3539d59da.png)

</div>
</details>

 </div>
</details>
<details>
<summary> 2022.1.19(WED) </summary>
<div markdown="1">
 
 ## 📝 Coding Test 파이썬 문제풀이(31~60)   
![image](https://user-images.githubusercontent.com/97418768/150154798-12c9890c-66ab-4d8e-995b-1b4d08b54f70.png)
![image](https://user-images.githubusercontent.com/97418768/150154862-bda414c1-2b7d-445b-b1d1-7df58efd2b2d.png)

</div>
</details>

 </div>
</details>
 
 <details>
<summary> 2022.1.20(THU) </summary>
<div markdown="1">
 
 ## 📝 Smart Mobility Programming Camp HW1,2   
 1. HW1
 
 - HW1.2  표준입력장치 (키보드)로부터 원의 반지름(radius)을 입력 받고, 그 원의 넓이(area)와 원둘레 (circumference)를 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.  
 - HW1.3  직사각형의 가로 (width)와 세로 (length)를 입력 받아 넓이(area)와 둘레(perimeter)를 계산하여 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
 - HW1.4 표준입력장치 (키보드)로부터 직사각형의 가로 (width) 및 세로 (length) 크기를 각각 입력 받고, 터틀그래픽을 사용하여 지정된 크기의 사각형을 (0, 0) 좌표가 중심이 되도록 그리는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
 - HW1.5 임의의 실수 (float) 데이터를 한 줄에 차례로 입력받고, 입력된 데이터의 최댓값, 최솟값, 평균값를 계산하여 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
 
 2. HW2
 
 - HW2.1 0 ~ 255의 값을 10진수, 2진수, 8진수, 16진수로 각각 출력하는 파이썬 프로그램을 작성하고, 실행결과를 제출하라. 2진수는 총 8자리, 8진수는 접두어를 포함하여 5자리, 16진수는 접두어를 포함하여 4자리로 출력하며, 앞부분에 빈자리가 있는 경우 0으로 채울 것.
 - HW2.2 10개의 실수 (float) 데이터를 한 줄에 입력 받아 리스트에 저장하고, 이 리스트에 포함된 데이터 중 최솟값, 최댓값, 평균값을 계산하여 출력하라. 평균값은 소수점 이하 2자리까지 출력
 - HW2.3  3개의 16진수 x, y, z를 각각 입력 받고, 이 16진수 x와 y의 bit-wise and, bit-wise or, bit-wise exclusive or 값을 각각 계산하여 2진수 및 16진수로 출력하며, x의 bit-wise not과 bit-wise left shift 2, y와 z의 bitwise right shift 2를 각각 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라. 각 출력 항목들은 오른쪽으로 줄 맞춤 할 것.
- HW2.4 복소수 (complex number) c1을 입력 받고, 이 c1의 켤레 복소수 c2를 계산하여 출력하라. c1과 c2의 덧셈, 뺄셈, 곱셈, 나눗셈을 계산하여 결과를 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
 -HW2.5  다각형 꼭지점 개수 n과 한 변의 길이 (length), 그 다각형의 중심 좌표 x0, y0를 한 줄로 입력 받고, 지정된 위치 (x0, y0)를 중심으로 다각형을 그리는 파이썬 프로그램을 작성하라. 다각형의 좌측 하단 꼭지점의 좌표를 정확하게 계산하여 출력하며, 터틀 그래픽의 중앙과 다각형의 각 꼭지점 좌표를 터틀 객체의 write() 함수를 사용하여 출력할 것. 
 
</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.21(FRI) </summary>
<div markdown="1">
 
 ## 📝 Coding Test 파이썬 문제풀이(61~80)   
 ![image](https://user-images.githubusercontent.com/97418768/151354024-8c16462f-4608-4c48-bc6d-91fbf5045fb8.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.24(MON) </summary>
<div markdown="1">
 
 ## 📝 Coding Test 파이썬 문제풀이(81~98)   
 ![image](https://user-images.githubusercontent.com/97418768/151354216-4fb77110-f5e5-435a-abcd-1555101911c9.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.25(TUE) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 함수 문제풀이
![image](https://user-images.githubusercontent.com/97418768/151354704-9e2d1d75-ee96-4c5c-9dd7-e49f4ca261ae.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.26(WED) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 문자열 문제풀이(1~5)
![image](https://user-images.githubusercontent.com/97418768/151354862-ad2a1d05-b248-49ec-b8d6-6e264944d6fc.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.27(THU) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 문자열 문제풀이(6~10)
![image](https://user-images.githubusercontent.com/97418768/151354983-50339cd8-c404-4ff8-a445-40bfdcf0b7aa.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.28(FRI) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 기본 수학 1 문제풀이(1~4)
![image](https://user-images.githubusercontent.com/97418768/151533199-bcd4e5cc-9522-40e4-81d2-09ac889ca264.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.1.31(MON) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 기본 수학 1 문제풀이(5)
![image](https://user-images.githubusercontent.com/97418768/152357667-c8e8451a-22db-4c30-be2c-3e6b8ffbbb47.png)

 ### 2. 백준 재귀 문제풀이(1,2)
![image](https://user-images.githubusercontent.com/97418768/152357776-328d3005-8a5f-4f1c-aa49-7b0ca60d9763.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.2.1(TUE) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 기본 수학 2 문제풀이(1~3)
![image](https://user-images.githubusercontent.com/97418768/152357991-361c04e2-179a-4e11-b5d4-74b917131273.png)

</div>
</details>

 </div>
</details>

<details>
<summary> 2022.2.2(WED) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 기본 수학 2 문제풀이(4~5,7)
![image](https://user-images.githubusercontent.com/97418768/152358086-525cd563-4be8-4c4f-9985-547ef2db081c.png)
![image](https://user-images.githubusercontent.com/97418768/152358128-95587ea3-a8df-4ddf-b838-6a798b97bf70.png)
</div>
</details>

 </div>
</details>

<details>
<summary> 2022.2.3(THU) </summary>
<div markdown="1">
 
## 📝 백준문제 풀이    
 ### 1. 백준 기본 수학 2 문제풀이(8~10)
![image](https://user-images.githubusercontent.com/97418768/152358239-8e8003f0-0a70-4b73-9be2-97e052af8be7.png)
</div>
</details>

 </div>
</details>

 # 📌[BlockChain]
 
 <details>

<summary>Beginning Ethereum Smart Contracts Programming
- With Examples in Python, Solidity, and JavaScript</summary>
<div markdown="1">
 
## 📝 Connecting to the Ethereum Blockchain, Creating Your Own Private Ethereum Test Network
### 1. node1 geth실행 : geth --datadir C:\Users\NGM\MyTestNet\node1 console --networkid 4649 --nodiscover --maxpeers 0 (or) geth --datadir C:\Users\NGM\MyTestNet\node1 console 2>console1.log
### 2. 외부 계정주소 생성 : personal.newAccount() (비밀번호 : pass0)
### 3. 외부 계정주소 확인 : eth.accounts
### 4. 코인베이스계정주소확인 : eth.coinbase
### 5. 코인베이스 잔액 조회 : eth.getBalance(eth.accounts[0])
### 6. 단위 변경(wei -> ether) : web3.fromWei(eth.getBalance(eth.accounts[0]),"ether") => 채굴 보상 = 생성 블록 수 * 5 ETH
### 7. 종료 : exit
### 8. node2 geth실행 : geth --datadir C:\Users\NGM\MyTestNet\node2 console --networkid 4649 --nodiscover --maxpeers 0 (or) geth --datadir C:\Users\NGM\MyTestNet\node2 --port 30304 --nodiscover --networkid 2345 console 2>console2.log => geth --networkid 2345 --datadir C:\Users\NGM\MyTestNet\node2 --port 30304 console 2>> C:\Users\NGM\MyTestNet\node2\geth.log 이거로 geth 들어가야함

### 9. node1 geth 실행(node2와 동시 접속) : geth --datadir C:\Users\NGM\MyTestNet\node1 --networkid 2345 --ipcdisable console 2>console1.log
### 10. admin.nodeInfo
### 11. enode 명령어 : admin.nodeInfo.enode
### 12. node1의 enode : "enode://26c316e90df9254a5da1dc934df9e860c959c89f0176cfd2a88940eeceae5e6d0e3ebaec2ca67bb325aeb6133ecbf82dab3b0a2125da6662d86f3e894f76512e@165.229.125.27:30303", node2의 enode : "enode://d2facada76b143b2eda531fc0e08a104d71284f70ddc8c28cacade3d06516265f7f33874d67706d47e77ba2fec5e70eb9285abcea0303041cbe23f064cf42eda@165.229.125.27:30304"
### 13. Paring the Nodes(node1에 node2 enode 연결) : admin.addPeer("enode://d2facada76b143b2eda531fc0e08a104d71284f70ddc8c28cacade3d06516265f7f33874d67706d47e77ba2fec5e70eb9285abcea0303041cbe23f064cf42eda@165.229.125.27:30304")
### 14. Paring the Nodes(node2에 node1 enode 연결) : admin.addPeer("enode://26c316e90df9254a5da1dc934df9e860c959c89f0176cfd2a88940eeceae5e6d0e3ebaec2ca67bb325aeb6133ecbf82dab3b0a2125da6662d86f3e894f76512e@165.229.125.27:30303")
### 15. node 연결 확인 : admin.peers

## <port 번호 새로 생성해서 geth 들어감> -> 실패
### 16. geth --networkid 2345 --datadir C:\Users\NGM\MyTestNet\node1 --port 9991 console 2>> C:\Users\NGM\MyTestNet\node1\geth.log
### 17. geth --networkid 2345 --datadir C:\Users\NGM\MyTestNet\node2 --port 9992 console 2>> C:\Users\NGM\MyTestNet\node2\geth.log
### 18. "enode://26c316e90df9254a5da1dc934df9e860c959c89f0176cfd2a88940eeceae5e6d0e3ebaec2ca67bb325aeb6133ecbf82dab3b0a2125da6662d86f3e894f76512e@165.229.125.27:9991", "enode://d2facada76b143b2eda531fc0e08a104d71284f70ddc8c28cacade3d06516265f7f33874d67706d47e77ba2fec5e70eb9285abcea0303041cbe23f064cf42eda@165.229.125.27:9992"

## <노트북에 node3 생성>
### 19. 1) 버전 달라서 조금 다르게 해줌
{
"config": {
"chainId": 15,
"homesteadBlock": 0,
"eip150Block": 0,
"eip155Block": 0,
"eip158Block": 0
},

"nonce": "0x0000000000000042",
"timestamp": "0x00",
"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
"extraData": "0x00",
"gasLimit": "0x8000000",
"difficulty": "0x4000",
"mixhash": "0x0000000000000000000000000000000000000000000000000000000000000000",
"coinbase": "0x3333333333333333333333333333333333333333",
"alloc": {}
}
### 20. 2) geth --datadir C:\Users\skaru\MyTestNet\data\node3 init C:\Users\skaru\MyTestNet\data\node3\genesis.json
### 21. 3) geth --datadir C:\Users\skaru\MyTestNet\data\node3 --networkid 2345 console 2>console2.log (or) geth --datadir C:\Users\skaru\MyTestNet\data\node3 console --networkid 2345 --nodiscover --maxpeers 0(채굴 화면에 보임)
 
![화면 캡처 2022-02-19 204840](https://user-images.githubusercontent.com/97418768/154805838-dac06afb-f70e-46b2-bb77-a6a8d8c12bd5.png)

### 22. 4) miner.start(1)
![화면 캡처 2022-02-19 204857](https://user-images.githubusercontent.com/97418768/154805849-8e956999-e178-48d8-92e6-e102463b8942.png)

 
### 23. 5) eth.blockNumber, eth.getBalance(eth.coinbase), web3.fromWei(eth.getBalance(eth.coinbase),"ether")
 ![화면 캡처 2022-02-19 204925](https://user-images.githubusercontent.com/97418768/154805854-b9a72ac8-5143-44a6-881c-a5d1fc1d4d35.png)

### 24. "enode://26c316e90df9254a5da1dc934df9e860c959c89f0176cfd2a88940eeceae5e6d0e3ebaec2ca67bb325aeb6133ecbf82dab3b0a2125da6662d86f3e894f76512e@165.229.125.27:30303","enode://e63df132122045e5c13995fac3315db22cb8b0d4d173c6e4ca66c140576de13589b94caf32961ede60afa1c12e302ed952116aa12f474bfbbdd133245cef3497@127.0.0.1:30303"

## Connecting to the Ethereum Blockchain
### 1. Geth 다운로드 및 설치(Windows용 Geth 설치)
- https://geth.ethereum.org/downloads/
### 2. Geth 시작하기
#### > geth --testnet —datadir ~.testnet
 - --testnet : geth 클라이언트는 Ropsten 테스트 네트워크 (--testnet)에 연걸해 네트워크에서 전체 블록체인 다운로드 시도
 - --datadir : 블록체인, 키 저장소 및 기타 로컬 클라이언트 데이터를 저장하는 데 사용할 로컬 저장소 (홈 디렉토리의 .ethereum-testnet인 숨겨진 폴더에 저장)
 ### [ 이더리움 네트워크 ]
 - 메인 이더리움 네트워크(메인넷) 외에도 개발 목적으로 사용할 수 있는 수많은 테스트 네트워크(테스트넷)가 있음
- 테스트 넷은 네트워크의 이더가 실질적인 금전적 가치 X  ->  이더리움 블록체인을 테스트 및 탐색 가능
- 테스트(및 학습)를 마지막으로 완료한 경우에만 실제 구축을 위해 메인넷에 연결
- 4개의 테스트넷(Ropsten, Kovan, Rinkeby, Goerli)
 ### 3. 다운로드한 데이터 검사
 - Geth가 ~.ethereum-testnet 디렉터리에서 생성한 폴더
  - geth : 다운로드 중인 블록체인
  - keystore : 로컬 이더리움 노드의 계정 세부 정보
 ### 4. JavaScript 콘솔 가져오기
 #### > geth --testnet --datadir ~/.ethereum-testnet console 2>console.log
 #### > personal.newAccount()
 #### Password: pass0
 #### Repeat password: pass0
- Geth 자바스크립트 콘솔 없이 별도의 창에서 Geth를 실행 + Geth와 상호 작용
 #### > geth --testnet --datadir ~/.ethereum-testnet --rpc —rpcport 8545
 - --rpc : HTTP_RPC 서버를 사용 가능으로 설정
 - --rpcport 8545 : HTTP_RPC 서버가 포트 8545에서 수신하여 다른 클라이언트가 연결할 수 있도록 함
 #### > geth attach http://127.0.0.1:8545
 - 다른 터미널 창에서 geth로 url http://127.0.0.1:8545 붙임
 ### 5. 동기화 모드
 #### 1. 전체 노드 모드(빠른 동기화 포함)
 - --syncmode 옵션을 지정하지 않고 Geth 클라이언트를 시작하면 Geth에서 사용하는 기본 모드(--syncmode fast)
- 블록 헤더 다운로드 -> 블록 본문, 영수증 작성해 Geth가 전체 블록체인을 컴퓨터에 다운로드
- 빠른 동기화가 이더리움 네트워크의 마지막 블록에 도달 -> 전체 동기화 모드로 전환, 최신 정보 확인
 #### 2. 전체 노드 모드
 - 제네시스 블록에서 시작 -> 모든 블록 확인 및 모든 트랜잭션 실행하는 전체 노드 동기화
- 빠른 동기화 모드보다 느림, 보안 강화
 #### 3. 라이트 노드 모드
 - 헤더 체인만 다운로드, 네트워크에서 기타 모든 것을 on-demand 방식으로 요청
- 블록 헤더에 있는 상태 루트에 대해 데이터의 유효성 확인
- --syncmode 조명 옵션 사용
 
 ## Creating Your Own Private Ethereum Test Network
 ### 1. Genesis 블록, 노드 데이터 저장 폴더 생성
 - 실제 블록체인에 연결X, 로컬 설정에서 자신만의 사설 테스트 네트워크 생성 가능 -> 쉬운 개발, 실제 이더리움 비용 지불하지 않고도 이더리움 블록체인 탐색 가능
 ### 실습 : 단일 컴퓨터에 노드 1과 노드 2, 세번 째 노드 3으로 구성된 사설 테스트 네트워크를 다른 컴퓨터에 생성
 ### 1. MyTestNet 폴더 생성
 #### > cd ~
#### > mkdir MyTestNet
#### > cd MyTestNet
 ### 2. Genesis 블록 생성
 - Genensis 블록 : 첫 번째 블록이자 선행 블록을 가리키지 않는 유일한 블록인 블록체인의 시작
 - genesis.json 파일을 생성
 
 {
"config": {
"chainId": 15,
"homesteadBlock": 0,
"eip150Block": 0,
"eip155Block": 0,
"eip158Block": 0
},
"nonce": "0x0000000000000042",
"timestamp": "0x00",
"parentHash": "0x0000000000000000000000000000000000000000000000000000000000000000",
"extraData": "0x00",
"gasLimit": "0x8000000",
"difficulty": "0x4000",
"mixhash": "0x0000000000000000000000000000000000000000000000000000000000000000",
"coinbase": "0x3333333333333333333333333333333333333333",
"alloc": {}
}
 ### 3. 노드 데이터 저장 폴더 생성
 #### > cd ~/MyTestNet
#### > mkdir data
 ### 4. 노드 초기화
 - 테스트 네트워크에 노드를 생성하려면 이전에 생성한 Genesis 블록을 사용하여 노드 초기화 과정 필요
 #### > geth --datadir ~/MyTestNet/data/node1 init ~/MyTestNet/genesisblock.json
 #### > tree (node1, node2 구성)
 ### 5. 노드 시작 - node 1
 #### > geth --datadir ~/MyTestNet/data/node1 console 2>console1.log
 - console 2 옵션은 기본적으로 출력을 파일로 다시 보냄 (console1.log) -> Geth가 지속적으로 많은 출력 생성 방지, Geth 자바스크립트 콘솔 사용 가능
 ### 6. 계정 생성 및 잔액 확인
 #### > personal.newAccount()
 Passphrase: pass0
 
Repeat passphrase: pass0
 #### > eth.accounts
 - 노드 계정 목록이 배열로 표시
- 계정 생성 시, ~/MyTestNet/data/node1/keystore 디렉터리의 파일에 저장된 계정 세부 정보 있음
 #### > eth.getBalance(eth.accounts[0])
 -> 0
 - 잔액에 대한 표시 단위 Wei
- 1 Ether = 100000000000000Wei
 - Wei의 잔액 -> Ether
 #### > web3.fromWei(eth.getBalance(eth.accounts[0]), "ether")
 -> 0
 
 ![image](https://user-images.githubusercontent.com/97418768/155154404-f35fa232-5190-4f66-be76-b6469df73379.png)
### 7. 다른 노드 시작 - node 2
 #### > geth --datadir ~\MyTestNet\data\node2 -port 30304 --nodiscover --networkid 2345 --ipcdisable console 2>console2.log
 - --port 30304 설정 : Geth는 기본적으로 30303 사용(node 1), 동일한 컴퓨터에서 실행되는 노드가 여러 개인 경우, 각 노드가 고유한 포트 번호 사용해야 함 -> 충돌 방지
- --nodiscover : 피어가 서로를 자동으로 검색 X , 피어를 수동으로 추가해야 함
- --networkid : 다른 노드가 동일한 네트워크 ID로 네트워크 연결 가능하도록 네트워크 ID 지정
- --ipcdisable : port 접근 허용
 ### - node 1 다시 시작
 #### > geth --datadir ~\MyTestNet\data\node1 --networkid 2345 --ipcdisable console 2>console1.log
 - -- networkid 2345 : 노드 2의 피어로 추가 가능
 
 ![image](https://user-images.githubusercontent.com/97418768/155154585-1e26cb03-b0cf-47dc-9d94-31fa82c45c0c.png)
### 8. 노드 정보 가져오기 (enode : 이더리움 네트워크의 노드를 URI의 형태로 설명)
 #### > admin.nodeInfo (node 1)
 #### > admin.nodeInfo (node 2)
 ### 9. 노드 쌍 구성( 동일 컴퓨터 노드 )
#### >admin.addPeer("enode://2e363f13e5cef58e1ed4b5106ad9328c3df74430e8cb9627ef8f67378dd4780f1190a7e0454fe9c18a0e493e92503229fb5fd8f18f27529c2f8d8e4afcc798f1@211.186.154.15:30303")
 -> true
 - node 2에 node 1의 enode 키 값 입력
 #### > admin.addPeer("enode://1922d09135e6b8f91221575cb0a9a6819d09d8ea56a13788419569abc0de410d94dd974ae7ebf00c9cde904ca9dc09aa5d07f8f774f02fdcffae48400c2fa65a@127.0.0.1:30304?discport=0")
 -> true
 - node 1에 node 2의 enode 키 값 입력
 #### > admin.peers
 - node 1에 Peer 추가
 #### > admin.peers
 - node 2 Peer 추가
 10. 노드 쌍 구성( 다른 컴퓨터 노드 )
 ![image](https://user-images.githubusercontent.com/97418768/156004741-c7b9229a-85cd-404b-8ce7-04065317961d.png)

 ### 12. 노드 간 이더넷 전송
 #### > personal.newAccount()
 Password: pass1
 
Repeat password: pass1
 - node 1에서 다른 계정 생성
 #### > eth.accounts
 #### > eth.getBalance(eth.accounts[0])
 -> 470000000000000000000
 #### > eth.getBalance(eth.accounts[1])
 -> 0
 #### > personal.unlockAccount(eth.accounts[0])
 Password: pass0
 - 한 계정에서 다른 계정으로 일부 Ether를 전송하기 전, 원본 계정 잠금 해제
 #### > eth.sendTransaction({from: eth.accounts[0], to: eth.accounts[1], value: web3.toWei(5,"ether")})
 - 첫 번째 계정의 Ether 5개를 동일한 노드 내의 두 번째 계정으로 이체
 
 #### > miner.start()
 -> null
 -첫 번째 계정 마이닝(거래가 블록체인에 기록될 수 있도록 거래 확인)
 #### > miner.stop()
 -> null
 -마이닝 종료
 #### > eth.getBalance(eth.accounts[1])
 -> 5000000000000000000
 -두 번째 계정에 5개의 Ether 전송됨
 ### 12. 계정 관리 및 제거
 #### {
"address":"acf28077eb41424c70c28c31222b821dde5f686b",
"crypto":{
"cipher":"aes-128-ctr",
"ciphertext":"cb1cb85da255a3cc51444d6b16db17ecbd6095dd61fc5a96d501cb26210e76d7",
"cipherparams":{
"iv":"8e4cdab86e4a2a2592976ce269fd1ef8"
},
"kdf":"scrypt",
"kdfparams":{
"dklen":32,
"n":262144,
"p":1,
"r":8,
"salt":"ad792a4c9f00d10a721eafbff2c6eb17ab39125ad087776ca781d5650abb2d26"
},
"mac":"43668000a8966c501ec861b100040778bce56603b9819220630bc99f1c7c084c"
},
"id":"aab06707-604c-4f42-b7cb-18a34738667f",
"version":3
}
 - UTC 파일 내용 분석
 ### 13. 코인베이스 설정
 #### > eth.coinbase
 - 마이닝 보상이 가는 노드 내의 계정 반환
 #### > miner.setEtherbase(eth.accounts[1])
 -> true
 - 코인베이스를 두 번째 계정으로 변경
 #### > eth.coinbase
 - 코인베이스가 두 번째 계정인지 확인
 
 </div>
</details>
 
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
