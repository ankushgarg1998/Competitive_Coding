T = input()
for test in range(1,T+1):
    [N,K] = map(int,raw_input().split())
    array = {N:1}
    ans = []
    count = 0
    while True:
        m = max(array.iterkeys())
        if m%2==0:
            first = m/2
            second = first - 1
            if not first in array:
                array[first] = array[m]
            else:
                array[first] += array[m]
            if not second in array:
                array[second] = array[m]
            else:
                array[second] += array[m]
            count+=array[m]
            del array[m]
            ans = [first,second]
        else:
            first = m/2
            if not first in array:
                array[first] = (2*array[m])
            else:
                array[first] += (2*array[m])
            count += array[m]
            del array[m]
            ans = [first,first]
        if count>=K:
            break
    print (str(ans[0])+' '+str(ans[1]))
