
from math import sqrt

def divisor_sum(n):
    if n == 1: return 1
    M = n
    ret = 1
    i = 2
    while i*i<=n:
        cnt = 0
        while n%i == 0:
            cnt = cnt + 1
            n /= i
        ret *= sum(map(lambda x: i**x, xrange(cnt+1)))
        i = i + 1
    if n > 1:
        ret *= (n + 1)
    return ret - M


N = 28123
ok = [True] * (N+1)

def is_abundant(x):
    return divisor_sum(x) > x


kajou = filter(lambda x: is_abundant(x), xrange(1,N))

m = len(kajou)
for i in xrange(m):
    for j in xrange(i,m):
        if kajou[i] + kajou[j] > N :
            break
        ok[kajou[i] + kajou[j]] = False

print sum(filter(lambda x: ok[x], xrange(N+1)))
        
