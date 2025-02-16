b=[]
while (1):
    a=input()
    if a=="ok":
        break
    if len(a)==8:
        b.append(a)
print("\n".join(b))
