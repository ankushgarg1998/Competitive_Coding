for _ in range(int(input())):
  n,sig = tuple(map(int,input().split()))
  ans = (((sig**2)*n)/2)**0.5
  print (str(ans) + " -" + str(ans) + (" 0"*(n-2)))
