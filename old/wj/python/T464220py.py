import re
a=input()
b=input()
aq=True
def fo(text, pattern):
    occurrences = []
    start = 0
    while True:
        index = text.find(pattern, start)
        if index == -1:
            break
        occurrences.append(index)
        start = index + 1
    return occurrences
for i in b:
    if i!="?":
        aq=False
        break
if aq:
    for i in range(1,len(a)-len(b)+1):
        print(i,i+len(b))
else:
    ok=list(range(len(a)-len(b)))
    for i in range(len(b)):
        if b[i]=="?":
            continue
        else:
            ok2=list(set(ok)&set([j-i for j in fo(a,b[i])]))
            ok=ok2
            # print(ok)
    for i in ok:
        print(i+1,i+len(b))
