"""
2.1 0 ~ 255의 값을 10진수, 2진수, 8진수, 16진수로 각각 출력하는 파이썬 프로그램을 작성하
고, 실행결과를 제출하라. 2진수는 총 8자리, 8진수는 접두어를 포함하여 5자리, 16진수는 접
두어를 포함하여 4자리로 출력하며, 앞부분에 빈자리가 있는 경우 0으로 채울 것.
Project : SmartMobility_HW2.1
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
print("==================================")
print("Decimal  Bit   Octal  hexadecimal")
print("----------------------------------")
for i in range(256):
    print("{0:6d} {1:08s} {2:05} ".format(i,format(i,'b'),oct(i)),end="")
    print(" 0X%02X"%i)