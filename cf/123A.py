# coding: utf-8

def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n%2 == 0:
        return False
    i = 3
    while i*i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

def make_prime(s):
    for i in xrange(2,1000):
        if is_prime(i):
            s.append(i)


def houjo(primes, index, sign, num, n):
    res = 0
    if num > 1:
        res = int(n / num) * sign
    
    for next in xrange(index, len(primes)):
        if primes[next] > n/2 or num*primes[next] > n:
            break
        res += houjo(primes, next+1, -sign, num*primes[next], n)

    return res

primes = []
make_prime(primes)
s = raw_input()

d = dict()
for x in s:
    if d.has_key(x) == False:
        d[x] = 1
    else :
        d[x] += 1


data = [[v,k] for k,v in d.iteritems()]
data.sort(reverse=True)

n = len(s)
y = houjo(primes, 0, -1, 1, n)

if data[0][0] >= y:
    print "YES"
    if y == 0:
        print s
    else:
        alpha = data[0][1]
        ans = ['.'] * n
        for p in primes:
            if p > n/2 :
                break
            for i in xrange(1,n):
                if p*i > n:
                    break
                ans[p*i - 1] = alpha

        #print ans
        data[0][0] -= ans.count(alpha)
        tmp = ''.join([x[1]*x[0] for x in data])
        k = 0
        for i in xrange(n):
            if ans[i] == '.' :
                ans[i] = tmp[k]
                k += 1
        print ''.join(ans)
else:
    print "NO"
        
