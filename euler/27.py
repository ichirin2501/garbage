# project euler 27

def is_prime(n):
    if n <=1 :
        return False
    i = 2
    while i*i <= n:
        if n%i == 0 :
            return False
        i = i + 1
    return True


N = 1000
ans, ret = 0, -1
for a in xrange(-N+1, N):
    for b in xrange(-N+1, N):
        n = 0
        while is_prime(n**2 + a*n + b):
            n = n + 1
        if ans < n :
            ans = n
            ret = a * b

print ret
        
        
        
