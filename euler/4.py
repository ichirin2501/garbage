

def func4():
    for i in xrange(100,1000):
        for j in xrange(i,1000):
            k = i * j
            if str(k) == str(k)[::-1] :
                yield k

print max(func4())
        
