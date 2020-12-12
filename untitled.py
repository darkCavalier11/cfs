n = int(input())
arr = []
for i in range(n):
	arr.append(input())
visited = [0]*26
curr = 0
for i in range(n):
	p = arr[i]
	temp = float('inf')
	for j in p:
		if visited[ord(j)-97] != 0:
			temp = min(temp, visited[ord(j)-97])
	if temp == float('inf'):
		curr += 1
		for j in p:
			visited[ord(j)-97] = curr
	else:
		for j in p:
			visited[ord(j)-97] = temp
	curr = max(visited)

for i in range(n):
	p = arr[i]
	temp = float('inf')
	for j in p:
		temp = min(temp, visited[ord(j)-97])
	for j in p:
		visited[ord(j)-97] = temp
print(max(visited))

	