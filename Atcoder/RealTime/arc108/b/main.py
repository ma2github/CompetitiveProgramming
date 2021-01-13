n=int(input())
s=input()
stack=[]
for c in s:
    stack.append(c)
    while stack[-3:]==['f','o','x']:
        del stack[-3:]
print(len(stack))
