"""
1.2 표준입력장치 (키보드)로부터 원의 반지름(radius)을 입력 받고, 그 원의 넓이(area)와 원둘레
(circumference)를 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라. 
Project : SmartMobility_HW1.2
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
r=int(input('radius = '))
PI=3.141592
print('Circle of radius ({}) : area ({}), circumference({})'.format(r,r**2*PI,r*2*PI))