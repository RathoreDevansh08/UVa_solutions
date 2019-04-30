import numpy as np

def check(C):
	s=C[0][0]+C[0][1]+C[0][2]+C[1][0]+C[1][1]+C[1][2]+C[2][0]+C[2][1]+C[2][2]
	if(s==0):
		return False
	else:
		return True

t=int(input())
A=np.zeros((3,3), dtype=int)
while(t):
	t-=1
	c=input()
	for i in range(3):	
		m=int(input())
		A[i][2]=int(m%10)
		m=m/10
		A[i][1]=int(m%10)
		m=m/10
		A[i][0]=int(m%10)
	
	if(check(A)):
		k=-1
		L=[]
	else:
		print(-1)
		continue
		
	while(True):
		k+=1
		L.append(A)
		B=np.zeros((3,3), dtype=int)
		B[0][0]=(A[0][1]+A[1][0])%2
		B[0][1]=(A[0][0]+A[0][2]+A[1][1])%2
		B[0][2]=(A[0][1]+A[1][2])%2
		B[1][0]=(A[0][0]+A[1][1]+A[2][0])%2
		B[1][1]=(A[0][1]+A[1][0]+A[1][2]+A[2][1])%2
		B[1][2]=(A[0][2]+A[1][1]+A[2][2])%2
		B[2][0]=(A[1][0]+A[2][1])%2
		B[2][1]=(A[2][0]+A[1][1]+A[2][2])%2
		B[2][2]=(A[1][2]+A[2][1])%2
		
		#print(B)
		#print("---------")
		if(check(B)):
			A=B
		else:
			break
		
	print(k)
