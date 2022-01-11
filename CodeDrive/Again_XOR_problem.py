for q in range(int(input())):
    n, k  = map(int,input().split())
    s = input()
    xor = s[:k]
    for i in range(1,n-k+1):
        new = xor[1:]+s[i+k-1];
        print(xor,new)
        # xor = int(s[i:i+k])^xor
    print(str(xor).count("1"))