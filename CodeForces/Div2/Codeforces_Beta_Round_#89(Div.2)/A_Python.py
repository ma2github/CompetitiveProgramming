s=input()
ans=''
ng='AOYEUIaoyeui'
for c in s:
    if c in ng:
        continue
    ans+='.'+c.lower()
print(ans)
