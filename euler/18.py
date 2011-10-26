
li = [ [75],
       [95, 64],
       [17, 47, 82],
       [18, 35, 87, 10],
       [20,  4, 82, 47, 65],
       [19,  1, 23, 75,  3, 34],
       [88,  2, 77, 73,  7, 63, 67],
       [99, 65,  4, 28,  6, 16, 70, 92],
       [41, 41, 26, 56, 83, 40, 80, 70, 33],
       [41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
       [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
       [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
       [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
       [63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
       [ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23] ]



def maxsum(sum, line): # <list>, <list>
    print "sum =",sum
    print "line =", line
    print

    a = map(lambda x: x[0]+x[1], zip(sum, line))
    b = map(lambda x: x[0]+x[1], zip(sum[1:], line))
    return map(max, zip(a,b))

li = [[100],[200,3000]]
print zip(li[0], li[1])
print reduce(maxsum, li[::-1])

quit()

n = len(li)
for i in xrange(1,n):
    for j in xrange(i+1):
        tmp = 0
        if j != 0: # left ?
            tmp = max(tmp, li[i-1][j-1])
        if j != i: # up
            tmp = max(tmp, li[i-1][j])
        li[i][j] += tmp

print max(li[n-1])




        
