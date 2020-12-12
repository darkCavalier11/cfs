import time
n = int(input())
ans = 0
s = time.time()
def find(mat, i, j, temp):
	global match, ans
	if not ((0 <= i <= n-1) and (0 <= j <= n-1)):
		return
	if mat[i][j]:
		return
	if i == n-1 and j == 0:
		if len(temp) == n**2-1:
			ans += 1
		return
	if mat[n-1][0]:return
	if i == 0 and 0 < j < n-1:
		if mat[i+1][j] and mat[i][j-1] and mat[j+1][i]:
			return
	mat[i][j] = 1
	temp.append('U')
	find(mat, i-1, j, temp)
	temp.pop()
	temp.append('D')
	find(mat, i+1, j, temp)
	temp.pop()
	temp.append('L')
	find(mat, i, j-1, temp)
	temp.pop()
	temp.append('R')
	find(mat, i, j+1, temp)
	temp.pop()
	mat[i][j] = 0
grid = []
for i in range(n):
	grid.append([0]*n)
find(grid, 0, 0, [])
print(ans)
e = time.time()
print(e-s)