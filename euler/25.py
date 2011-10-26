
def fib():
    a, b = 1, 1
    yield a
    yield b
    while True:
        yield a + b
        a, b = b, a+b


for i,f in enumerate(fib()):
    if len(str(f)) == 1000 :
        print i + 1
        break

