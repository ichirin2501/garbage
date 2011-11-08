
lucky = []
def make_lucky(k):
    if k > 0:
        lucky.append(k)
    if k <= 1000:
        make_lucky(10*k + 4)
        make_lucky(10*k + 7)

make_lucky(0)

n = int(raw_input())
ok = False
for x in lucky:
    if n % x == 0:
        ok = True
        break

if ok :
    print "YES"
else :
    print "NO"
