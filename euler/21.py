
def divisor_sum(n):
    if n == 1: return 1
    M = n
    ret = 1
    i = 2
    while i*i <= n:
        cnt = 0
        while n%i == 0:
            cnt = cnt + 1
            n /= i
        ret *= sum(map(lambda x: i**x, xrange(cnt+1)))
        i = i + 1

    if n > 1:
        ret *= (n + 1)

    return ret - M


def is_amicable_numbers(a):
    b = divisor_sum(a)
    return a == divisor_sum(b) and a != b

print sum(filter(lambda a: is_amicable_numbers(a), xrange(1,10000)))
