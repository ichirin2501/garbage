
from itertools import permutations

n, k = map(int, raw_input().split())
number = []
for x in xrange(n):
    number.append(raw_input())



ans = 99999999999
for x in permutations(range(k)):
    tmp = [ [number[i][j] for j in x] for i in xrange(n) ]
    #for i in xrange(n):
    #    tmp.append( [number[i][j] for j in x] )
    tmp.sort()
    t1 = int(''.join(tmp[-1]))
    t2 = int(''.join(tmp[0]))
    #t1 = int(''.join(max(tmp)))
    #t2 = int(''.join(min(tmp)))
    if ans > t1 - t2:
        ans = t1 - t2
    #ans = min(ans, t1 - t2)

print ans
