#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Algorithm can be find here:
    http://mathfaculty.fullerton.edu/mathews/n2003/SimpsonsRule2DMod.html
"""
# function we're doing everything over
def main_function(x, y):
    return (3.0 * y)-(2 * (x*x))

# y is c or d 
def sumation1(m, y, a, h):
    i = 1
    result = 0.0
    while i != m-1:
        result += main_function(Xi(a, i, h), y)
        i +=1
    return result 

# x is a or b 
def sumation2(n, x, c, k):
    i = 1
    result = 0.0
    while i != n-1:
        result += main_function(x, Yj(c, i, k))
        i+=1
    return result

def double_sumation(n, m, a, c, h, k):
    sumation = 0.0
    for j in range(1, n):
        #print("i: {}".format(i))
        for i in range(1, m):
            #print("j: {}".format(j))
            sumation += main_function(Xi(a, i, h), Yj(c, j, k))
    return sumation

def Xi(a, i, h):
    return a + (i*h)

def Yj(c, j, k):
    return c + (j*k)

def double_integral_trapezoidal(a, b, c, d, n, m):
    #calculating the grid spacing
    h = (b - a) / float(m) # for y
    k = (d - c) / float(n) # for x
    
    first_component = (1 / 4.0)*h * k

    second_component = main_function(a, c) + main_function(b, c)
    second_component += main_function(a, d) + main_function(b, d)

    third_component = (2.0 * sumation1(m, c, a, h))
    third_component += (2.0 * sumation1(m, d, a, h))
    third_component += (2.0 * sumation2(n, a, c, k))
    third_component += (2.0 * sumation2(n, b, c, k))

    fouth_component = 4 * double_sumation(n, m, a, c, h, k)

    return first_component * (second_component+third_component+fouth_component)

if __name__ == "__main__":
    a = -1
    b = 2
    c = 1
    d = 3
    # these are the number of rectangles to be sliced
    n = 1000
    m = 1000
    r = double_integral_trapezoidal(a, b, c, d, n, m)
    print(r)
