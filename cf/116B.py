
n, m = map(int, raw_input().split())
grid = [list('.' * (m+2))]
grid += [list('.' + raw_input() + '.') for x in xrange(n)]
grid += [list('.' * (m+2))]

dx = [0,0,1,-1]
dy = [1,-1,0,0]    
ans = 0
           

for i in xrange(1,n+2):
    for j in xrange(1,m+2):
        if grid[i][j] == 'P' :
            for k in xrange(4):
                tx = j + dx[k]
                ty = i + dy[k]
                if grid[ty][tx] == 'W':
                    ans += 1
                    grid[ty][tx] = '.'

print ans
    
