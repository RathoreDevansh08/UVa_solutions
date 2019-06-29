while(True):
	s=input()
	x=int(s)
	if(x==0):
		break
	f=1
	for i in range(x+2,2*x+1):
		f=f*i
	print(f)
