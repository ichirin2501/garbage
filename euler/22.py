
import sys

line = [s.strip('"') for s in sys.stdin.readline().split(',')]
line.sort()


ans = 0
for i,j in enumerate(line):
    ans += (i+1) * sum(map(lambda c: ord(c)-ord('A')+1, j))

print ans
    



