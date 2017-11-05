n,u = tuple(map(int,input().split()))
arr = {i:0 for i in range(n)}
for i in range(u):
    a,b = tuple(map(int,input().split()))
    j=0
    b = b
    x = b-1
    while True:
        if  x<n:
            arr[x]+=1
            j+=1
            x+=a
        else:break
print(*arr.values())
