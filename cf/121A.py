# coding: utf-8

#input
l, r = map(int, raw_input().split())

def lucky_number(n, li):
    if n > 1:
        li.append(n)
    if n <= 1000000000:
        lucky_number( 10*n + 4, li )
        lucky_number( 10*n + 7, li )

li = []
lucky_number(0, li)
n = len(li)
li.sort()

# startを調べる
start = -1
for k in xrange(n):
    if l <= li[k] :
        start = k
        break

res = 0
prev = l - 1

for k in xrange(start, n):
    if li[k] >= r :
        res += li[k] * (r - prev)
        break
    res += li[k] * (li[k] - prev)
    prev = li[k]

print res
