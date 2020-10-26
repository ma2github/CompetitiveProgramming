s=input()
t=input()
for i in range(len(s)):
    if s[len(s)-i:]+s[:len(s)-i]==t:
        print(i)
        exit(0)
print(-1)
