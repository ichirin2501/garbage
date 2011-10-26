
def fact(n):
    if n <= 1:
        return 1
    else :
        return n * fact(n-1)


print sum(map(int, str(fact(100))))
