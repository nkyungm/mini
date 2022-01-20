"""
2.3 3개의 16진수 x, y, z를 각각 입력 받고, 이 16진수 x와 y의 bit-wise and, bit-wise or, bit-wise 
exclusive or 값을 각각 계산하여 2진수 및 16진수로 출력하며, x의 bit-wise not과 bit-wise left 
shift 2, y와 z의 bitwise right shift 2를 각각 출력하는 파이썬 프로그램을 작성하고, 실행 결과
를 제출하라. 각 출력 항목들은 오른쪽으로 줄 맞춤 할 것.
Project : SmartMobility_HW2.3
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
x=(input("hexadecimal x = "))
y=(input("hexadecimal y = "))
z=(input("hexadecimal z = "))
c_x=int(x,16)
c_y=int(y,16)
c_z=int(z,16)
d_x=bin(c_x)
d_y=bin(c_y)
d_z=bin(c_z)
print('x= {:>3} in decimal, {:>15} in bits'.format(c_x,d_x))
print('x= {:>3} in decimal, {:>15} in bits'.format(c_y,d_y))
print('x= {:>3} in decimal, {:>15} in bits'.format(c_z,d_z))
print("x & y  = in hex({:>10}), in bin ({:>15})".format(hex(c_x&c_y),bin(c_x&c_y)))
print("x | y  = in hex({:>10}), in bin ({:>15})".format(hex(c_x|c_y),bin(c_x|c_y)))
print("x ^ y  = in hex({:>10}), in bin ({:>15})".format(hex(c_x^c_y),bin(c_x^c_y)))
print("~x     = in hex({:>10}), in bin ({:>15})".format(hex(~c_x),bin(~c_x)))
print("x << 2 = in hex({:>10}), in bin ({:>15})".format(hex(c_x<<2),bin(c_x<<2)))
print("y >> 2 = in hex({:>10}), in bin ({:>15})".format(hex(c_y>>2),bin(c_y>>2)))
print("z >> 2 = in hex({:>10}), in bin ({:>15})".format(hex(c_z>>2),bin(c_z>>2)))