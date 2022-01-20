"""
1.4 표준입력장치 (키보드)로부터 직사각형의 가로 (width) 및 세로 (length) 크기를 각각 입력 받고, 터틀
그래픽을 사용하여 지정된 크기의 사각형을 (0, 0) 좌표가 중심이 되도록 그리는 파이썬 프로그램을 작
성하고, 실행 결과를 제출하라.
Project : SmartMobility_HW1.4
Author: Kyung-Min Nam
Date of last update: Jan. 19, 2022
"""
import turtle
width=int(input('width = '))
length=int(input('length = '))
print('Drawing a rectangle of width({}), length({}) ...'.format(width,length))
turtle.setup(500,500)
turtle.title("Drawing a rectangle")
t=turtle.Turtle()
t.shape("turtle")
t.pensize(5)
t.color('blue')
t.pencolor('red')

t.dot(3)
t.up()
t.goto((-width/2),(-length/2))
t.down()

t.forward(width)
t.left(90)
t.forward(length)
t.left(90)
t.forward(width)
t.left(90)
t.forward(length)
t.left(90)
t.up()
t.goto(0,0)
t.down()
input('Press any key to exit...')