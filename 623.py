import sys

mx=0
li=[]
for line in sys.stdin:
	words=line.split()
	for word in words:
		x=int(word)
		li.append(x)
		if(x>mx):
			mx=x

fact=[]
fact.append(1);
for i in range(1,mx+1):
	x=fact[i-1]*i;
	fact.append(x)
	
for i in li:
	print(str(i)+"!")
	print(fact[i])
