#!/usr/bin/python
"""
Algorithm can be find here:
    http://mathfaculty.fullerton.edu/mathews/n2003/SimpsonsRule2DMod.html
"""
def main_function(x, y):
    return (3 * y)-(2 * (x*x))

def sumation1(interval, y):
    i = 1
    result = 0.0
    while i != interval-1:
        result += main_function(i, y)
        i +=1
    return result 

def sumation2(interval, x):
    i = 1
    result = 0.0
    while i != interval-1:
        result += main_function(x, i)
    
def double_integral_trapezoidal():
    #calculating the grid spacing
    h = (b - a) / float(m) # for y
    k = (d - c) / float(n) # for x
    
    first_component = (1 / 4.0)*h * k
    second_component = main_function(a, c) + main_function(b, c)
    second_component += main_function(a, d) + main_function(b, d)

    thirdComponent = 2 * sumation1(m, c)
    thirdComponent += 2 * sumation1(m, d)
    thirdComponent += 2 * sumation2(n, a)
    thirdComponent += 2 * sumation2(n, b)

if __name__ == "__main__":
    a = 0
    b = 1
    c = 0
    d = 2
    # these are the number of rectangles to be sliced
    n = 6
    m = 6
    r = double_integral_trapezoidal(a, b, c, d, n, m)
    print(r)