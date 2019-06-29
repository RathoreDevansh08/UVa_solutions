from sys import stdin

f=[]
f.append(1)
f.append(2)
for i in range(2,1003):
	f.append(f[i-1]+f[i-2])

for line in stdin:
	words=line.split()
	for x in words:
		print(f[int(x)])	
