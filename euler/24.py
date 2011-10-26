
from itertools import permutations

for i,perm in enumerate(permutations('0123456789')):
    if i+1 == 1000000 :
        print ''.join(perm)
        break
