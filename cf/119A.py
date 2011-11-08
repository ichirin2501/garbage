
from fractions import gcd


a, b, n = map(int, raw_input().split())

while True:
    k = gcd(a,n)
    if k > n:
        print "1"
        break
    n -= k
    k = gcd(b,n)
    if k > n:
        print "0"
        break
    n -= k

