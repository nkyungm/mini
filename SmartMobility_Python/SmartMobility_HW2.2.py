"""
2.2 10개의 실수 (float) 데이터를 한 줄에 입력 받아 리스트에 저장하고, 이 리스트에 포함된 데
이터 중 최솟값, 최댓값, 평균값을 계산하여 출력하라. 평균값은 소수점 이하 2자리까지 출력
할 것.
Project : SmartMobility_HW2.2
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
L=list(input('input 10 float data in one line (separated in space) = ').split())

print('float_strings = {}'.format(L))
L=list(map(float,L))
print('L_float_data = {}'.format(L))
min=max=sum=L[0]
for i in range(1,10):
    if(min>L[i]):
        min=L[i]
    if(max<L[i]):
        max=L[i]
    sum+=L[i]
print('L_max = ({0:}), L_min = ({1:}), L_avg = ({2:.2f})'.format(max,min,sum/10))