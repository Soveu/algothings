def is_nondec(s):
    for i in range(1, len(s)):
        if ord(s[i-1]) > ord(s[i]):
            return False

    return True

def are_adj(s):
    for i in range(1, len(s)):
        if s[i-1] == s[i]:
            return True

    return False

counter = 0
for x in range(37253, 892942+1):
    s = str(x)
    if are_adj(s) and is_nondec(s):
        counter += 1

print(counter)
