
def islucky(ss):
    for i in ss:
        if not (i == '4' or i == '7'):
            return False
    return True

s = raw_input()
d = dict()


for i in xrange(len(s)):
    for j in xrange(1,len(s)-i+1):
        ss = s[i:i+j]
        if islucky(ss):
            if d.has_key(ss):
                d[ss] = d[ss] - 1
            else:
                d[ss] = -1


li = []
for k,v in d.iteritems():
    li.append((v,k))

if li == [] :
    print -1
else :
    print min(li)[1]
    
        


