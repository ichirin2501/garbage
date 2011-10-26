
import fractions

N = 20
n = 1
for i in range(2, N+1):
    n *= i / fractions.gcd(i,n)

print n
