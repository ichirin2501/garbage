
import itertools

def fib():
    a, b = 1, 2
    while True:
        if a%2==0 :
            yield a
        a, b = b, a+b

N = 4000000

print sum(itertools.takewhile(lambda x: x<=N, fib()))

