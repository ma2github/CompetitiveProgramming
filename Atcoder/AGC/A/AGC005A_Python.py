s=input()
stack=[]
for c in s:
    stack.append(c)
    if stack[-2:]==['S','T']:
        del stack[-2:]
print(len(stack))
