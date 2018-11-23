#!/usr/bin/env python
# -*- coding_ utf-8 -*-

## we want to apply a discrete integral
"""
Based on the Trapezoid method to integrate defined functions:
    https://www.geeksforgeeks.org/trapezoidal-rule-for-approximate-value-of-definite-integral/
"""

# area down this function
def main_function(x):
    #f_de_x = (1.0 / (1.0 + x * x))
    f_de_x = (9.0 * x) - 6
    return f_de_x

# sumation in the second component of the trapezoid method
def sumation(n, a, h):
    result = 0.0
    i = 1
    while i <= n-1:
        #print("i: {}".format(i))
        result += main_function(a + (i * h))
        #print(result)
        i += 1
    #print(result)
    return result

# main logic to integrate all the function over a and b in n slices
def integral_trapezoide(a, b, n):
    # grid spacing
    h = (b - a) /float(n)
    #print("h: {}".format(h))

    # calculating the integral
    first_component = (b - a) / (2 * float(n))

    f_de_a = main_function(a)
    f_de_b = main_function(b)

    intermediate_component = 2* sumation(n, a, h)

    result = first_component*(f_de_a + intermediate_component + f_de_b)

    return result
    
if __name__ == "__main__":
    n = 6
    a = 1
    b = 3
    r = integral_trapezoide(a,b,n)
    print(r)
