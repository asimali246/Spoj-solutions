while(1):
	(n, d)=raw_input().split(' ')
	n=int(n)
	d=int(d)
	if(n==0 and d==0):
		break
	print n**d
