
from itertools import permutations

n, k = map(int, raw_input().split())
number = []
for x in xrange(n):
    number.append(raw_input())


ans = 99999999999
for x in permutations(range(k)):
    tmp = []
    for i in xrange(n):
        tmp.append( int(''.join([number[i][j] for j in x])) )
    ans = min(ans, max(tmp) - min(tmp))

print ans
