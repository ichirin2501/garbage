
import itertools



def prime_gen(n):
    def prime():
        yield 2
        m = 3
        while True:
            i = 2
            while i*i<=m:
                if m%i==0 :
                    break
                i = i + 1
            
            if i*i>m:
                yield m
            m = m + 2

    g = prime()
    for i in xrange(n):
        yield g.next()

print max(prime_gen(10001))



