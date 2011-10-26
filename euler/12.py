# project euler 12

def divisor_count(n):
    ret = 1
    i = 2
    while i*i<=n:
        cnt = 0
        while n%i==0:
            cnt = cnt + 1
            n /= i
        ret *= (cnt + 1)
        i = i + 1

    if n > 1 :
        ret *= 2
    return ret


def triangular_number():
    i = 1
    while True:
        yield i*(i+1)/2
        i = i + 1

N = 501
for x in triangular_number():
    if divisor_count(x) >= N :
        print x
        break

