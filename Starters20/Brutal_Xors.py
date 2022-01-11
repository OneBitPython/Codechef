for q in range(int(input())):
    n = int(input())
    s= set()
    for i in range(n):
        for q in range(i, n):
            s.add(i^q)
    print(len(s))