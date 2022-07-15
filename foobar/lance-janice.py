def solution(x):
    l=list(x)
    for i in range(len(l)):
        if 'a' <= l[i] and l[i]<='z': 
            cnt=ord('z')-ord(l[i])
            l[i]=chr(ord('a')+cnt)
        # print(c)

    return "".join(l)



