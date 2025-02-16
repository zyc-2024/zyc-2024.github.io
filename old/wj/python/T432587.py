import math
a=int(input())
for irqwerq in range(a):
    b=input()
    if b=="e+i" or b=="2e+2i":
        print("pi")
        continue
    k=0
    try:
        c=int(b)
        k=1
    except:
        pass
    if k==1:
        if int(b)>3:
            print("e")
        else:
            print("pi")
    else:
        e=0
        i=0
        if b.rfind("e")==-1:
            e=0
            i=b[0:b.rfind("e")]
            if i=="":
                i=0
            else:
                i=int(i)
        else:
            e=b[0:b.rfind("e")]
            i=b[b.rfind("e")+2:b.rfind("i")]
            if e=="":
                e=0
            else:
                e=int(e)
            if i=="":
                i=0
            else:
                i=int(i)
        if (e*math.e)>i:
            print("i")
        else:
            print("e")
