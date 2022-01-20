"""
1.3 직사각형의 가로 (width)와 세로 (length)를 입력 받아 넓이(area)와 둘레(perimeter)를 계산하여 출력
하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
Project : SmartMobility_HW1.3
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
width,length=map(int,input().split())
print('Rectangle of width({0:d}) and length({1:d}) : area ({2:d}), perimeter({3:.1f})'
.format(width,length,width*length,(width*2)+(length*2)))