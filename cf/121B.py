
n, k = map(int, raw_input().split())
line = list(raw_input())

i = 0
while True:
    if i >= n-1 or k <= 0 :
        break
    if line[i] == '4' and line[i+1] == '7':
        if (i+1)%2 == 0 :  #even
            if i > 0 and line[i-1] == '4' : # loop
                if k%2 == 1:
                    line[i] = '7'
                break
            line[i] = '7'
        else:
            if i+2 < n and line[i+2] == '7' : # loop
                if k%2 == 1:
                    line[i+1] = '4'
                break
            line[i+1] = '4'
        i -= 1
        k -= 1
    else:
        i += 1

print ''.join(line)
