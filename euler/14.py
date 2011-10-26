# project euler 14

N = 1000000
memo = [0] * N

def Collatz_seq_count(n):
    M = n
    ret = 1
    while n>1:
        if n < N and memo[n] != 0 :
            memo[M] = ret + memo[n] - 1
            return memo[M]

        if n%2 == 0:
            n /= 2
        else:
            n = 3*n + 1
        ret = ret + 1
        
    memo[M] = ret
    return ret

def gen():
    for i in xrange(1,N):
        yield (Collatz_seq_count(i), i)

def compare(c1, c2):
    if c1[0] > c2[0] :
        return c1
    return c2

print reduce(compare, gen())
#print max([ (Collatz_seq_count(x),x) for x in xrange(1,N) ])[1]




        
        
