columns = [0]*8
diag1 = [0]*15
diag2 = [0]*15
cnt = 0
mat = []
for i in range(8):
	mat.append(list(input()))
def queen(y):
	global columns, diag1, diag2, cnt, mat
	if y == 8:
		cnt += 1
		return
	for i in range(8):
		if columns[i] or diag1[i+y] or diag2[i-y+7] or mat[y][i] == '*':
			continue
		columns[i] = diag1[i+y] = diag2[i-y+7] = 1
		queen(y+1)
		columns[i] = diag1[i+y] = diag2[i-y+7] = 0
queen(0)
print(cnt)
