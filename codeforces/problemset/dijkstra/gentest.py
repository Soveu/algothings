import random

N = 2900
M = N-1

print(N, M)
for i in range(M):
    print(i+1, i+2, random.randint(500000, 999999))

