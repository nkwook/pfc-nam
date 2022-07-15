def solution(l):
    if len(l) < 2:
        return l

    mid = len(l) // 2
    low_arr = solution(l[:mid])
    high_arr = solution(l[mid:])

    merged_arr = []
    l = h = 0
    while l < len(low_arr) and h < len(high_arr):
        if cmp(low_arr[l], high_arr[h]):
            merged_arr.append(low_arr[l])
            l += 1
        else:
            merged_arr.append(high_arr[h])
            h += 1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr

    
def cmp(a, b):
    al=a.split('.')
    bl=b.split('.')
    for i in range(3):
        if int(al[i]) > int(bl[i]):
            return False
        elif int(al[i]) < int(bl[i]):
            return True
        else :
            if len(al)==i+1:
                return True
            elif len(bl)==i+1:
                return False
  

print(solution(["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"]))
