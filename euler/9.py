

N = 1000


for a in range(1,N/3):
    for b in range(a+1,N):
        c = N - a - b
        if c < b :
            break

        if a**2 + b**2 == c**2:
            if a+b+c == N:
                print "(%d,%d,%d) = %d" % (a,b,c,a*b*c)
