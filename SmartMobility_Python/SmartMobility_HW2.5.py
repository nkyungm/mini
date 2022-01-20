"""
2.5 다각형 꼭지점 개수 n과 한 변의 길이 (length), 그 다각형의 중심 좌표 x0, y0를 한 줄로 입
력 받고, 지정된 위치 (x0, y0)를 중심으로 다각형을 그리는 파이썬 프로그램을 작성하라. 다
각형의 좌측 하단 꼭지점의 좌표를 정확하게 계산하여 출력하며, 터틀 그래픽의 중앙과 다각
형의 각 꼭지점 좌표를 터틀 객체의 write() 함수를 사용하여 출력할 것.
Project : SmartMobility_HW2.5
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
import turtle as t
import math

t.shape("turtle")
t.color("blue")
t.pencolor("blue")
t.pensize(3)

polygon,side_length,x0,y0=map(int,input("Input number of vertices polygon, side_length, center position x0 and y0 in one\n line (e.g., 7 100 100 100) = ").split())

t.up()
t.goto(x0,y0)
t.dot(5)
t.write(t.pos())
t.down

t.up()
dx=side_length/2
theta=180-((360/polygon)/2+90)
radius = math.radians(theta) #주의!!
dy=side_length*(math.tan(radius)/2)
t.goto(x0-dx,y0-dy)
t.down()

t.pencolor("red")
for i in range(polygon):
    t.dot(5)
    t.write(t.pos())
    t.forward(side_length)
    t.left(360/polygon)
input('Press any key to exit...')