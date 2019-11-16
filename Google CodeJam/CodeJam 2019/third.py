import math
def binary_search(a, x):
    lo = 0
    hi = len(a)-1
    while lo <= hi:
        mid = (lo+hi)//2
        midval = a[mid]
        if midval < x:
            lo = mid+1
        elif midval > x: 
            hi = mid-1
        else:
            return mid
    return -1

test = int(input())
for t in range(1, test+1):
    arr = []
    comm = 1
    [n,l] = list(map(int, input().split()))
    li = list(map(int, input().split()))
    st = 0

    while(li[st] == li[st+1]):
        st = st+1
    comm = math.gcd(li[st], li[st+1])
    fincomm = comm
    arr.append(comm)
    for i in range(st, -1, -1):
        arr.append(int(li[i]/comm))
        comm = li[i]/comm
    arr.reverse()
    comm = fincomm
    st = st+1
    
    for i in range(st, l):
        arr.append(int(li[i]/comm))
        comm = li[i]/comm
    # print(arr)

    ls = sorted(list(set(arr)))

    stri = ""
    for num in arr:
        ind = binary_search(ls,num)
        stri += chr(65 + ind)
    print("Case #" + str(t) + ": " + str(stri))
