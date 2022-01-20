"""
1.5 임의의 실수 (float) 데이터를 한 줄에 차례로 입력받고, 입력된 데이터의 최댓값, 최솟값, 평균값를 계
산하여 출력하는 파이썬 프로그램을 작성하고, 실행 결과를 제출하라.
Project : SmartMobility_HW1.5
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
L=list(map(float,input('input data in one line = ').split()))
count=len(L)
print('Input data (num_data = {}) = {}'.format(count,L))
min=max=sum=L[0]
for i in range(1,count):
    if(min>L[i]):
        min=L[i]
    if(max<L[i]):
        max=L[i]
    sum+=L[i]
print('min = {}, max = {}, avg = {}'.format(min,max,sum/count))