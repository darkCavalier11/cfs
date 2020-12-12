n, x = [int(p) for p in input().split()]
arr = [int(p) for p in input().split()]
dp = []
for i in range(n+1):
	dp.append([float('inf')]*(x+1))
for i in range(n+1):
	dp[i][0]=0
for i in range(1, n+1):
	for j in range(1, x+1):
		if j-arr[i-1] < 0:
			dp[i][j] = dp[i-1][j]
		else:
			dp[i][j] = min(dp[i-1][j], 1+dp[i][j-arr[i-1]])
if dp[n][x] == float('inf'):
	print(-1)
else:
	print(dp[n][x])