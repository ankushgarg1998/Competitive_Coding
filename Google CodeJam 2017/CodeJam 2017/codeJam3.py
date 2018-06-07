T = input()
for test in range(1,T+1):
    [N,K] = map(int,raw_input().split())
    array = []
    ans = []
    count = 0
    array.append(N)
    while True:
        m = max(array)
        while True:
            try:
                i = array.index(m)
                if m%2==0:
                    first = m/2
                    second = first - 1
                    array[i:i+1] = second, first
                    count+=1
                else:
                    first = second = m/2
                    array[i:i+1] = first, first
                    count += 1
            except ValueError:
                break
        array = list(set(array))
        print array
        if count>=K:
            ans = [first, second]
            break
    print ('Case #'+str(test)+': '+str(ans[0])+' '+str(ans[1]))

