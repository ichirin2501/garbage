

n = int(raw_input())

sum, ans = 0, 0
for i in xrange(n):
    a, b = map(int,raw_input().split())
    sum = sum - a + b
    ans = max(ans, sum)

print ans
    
