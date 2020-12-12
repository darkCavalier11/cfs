from collections import deque
n = int(input())
arr = [int(p) for p in input().split()]
s = set()
ind = {}
for i in range(n):
	if arr[i] not in ind:
		ind[arr[i]] = deque([i])
	else:
		ind[arr[i]].appendleft(i)
cnt = [1]*n; s.add(arr[0])
for i in range(1, n):
	if arr[i] not in s:
		cnt[i] = cnt[i-1] + 1
		s.add(arr[i])
	else:
		cnt[i] = min(cnt[i-1]+1, i-ind[arr[i]].pop())
print(max(cnt))