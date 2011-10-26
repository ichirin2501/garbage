
import itertools

def factor(n):
    i = 2
    while i*i<=n:
        while n%i==0:
            yield i
            n /= i
        i = i + 1
    if n>1:
        yield n


print max(factor(600851475143))
