# project euler 26


def repeating_decimal_len(n):
    m = 1
    cnt = 0
    d = {}

    while not d.has_key(m):
        d[m] = cnt
        m = m * 10 % n
        cnt = cnt + 1
    return cnt - d[m]

print max([(repeating_decimal_len(n),n) for n in xrange(2,1000)])[1]

    
