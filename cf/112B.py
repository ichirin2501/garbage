
n, x, y = map(int, raw_input().split())

if (n/2 == x or n/2+1 == x) and (n/2 == y or n/2+1 == y) :
    print "NO"
else:
    print "YES"
