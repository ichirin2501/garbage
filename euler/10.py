
import itertools

def prime(N=2000000):
    li = [True] * (N+1)
    li[0] = li[1] = False
    i = 2
    while i*i <= N:
        j = i * 2
        while j <= N:
            li[j] = False
            j += i
        i = i + 1

    i = 0
    while i <= N:
        if li[i]:
            yield i
        i = i + 1


print sum(prime())



