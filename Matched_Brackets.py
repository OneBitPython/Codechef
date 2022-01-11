from sys import stdin,stdout
from sys import setrecursionlimit
from sys import exit as quit
#setrecursionlimit(1000000)
'''r = [0 for i in range(3000)]
c = [0 for i in range(3000)]
t = [0 for i in range(3000)]
f = [0 for i in range(3000)]'''
#v = [[0 for i in range(3000)] for j in range(3000)]

n = int(stdin.readline().strip())
a = list(map(int,stdin.readline().strip().split()))

st = []
dep = 0;
cnt = 0;
maxdep = 0;
maxcnt = 0;
for i in range(n):
    if not dep:
        cnt = 0;
        bsi = i+1;
    cnt+=1;
    if a[i]==1:
        dep+=1;
    else:
        dep-=1;
    if dep>maxdep:
        deploc = i+1;
        maxdep = dep;
    if cnt>maxcnt:
        cntloc = bsi;
        maxcnt = cnt
print(maxdep,deploc,maxcnt,cntloc)
