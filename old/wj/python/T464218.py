import math
ss=0
for i in range(12):
    a=int(input())
    if ss<=310 and ss+a<=310:
        s=a*3.0
        ss+=a
        print("%.1f"%s)
    elif ss<=310 and ss+a>310 and ss+a<=520:
        s=(310-ss)*3+(ss+a-310)*3.3
        ss+=a
        print("%.1f"%s)
    elif ss<=310 and ss+a>520:
        s=(310-ss)*3+(520-310)*3.3+(ss+a-520)*4.2
        ss+=a
        print("%.1f"%s)
    elif ss>310 and ss+a<=520: 
        s=(a)*3.3
        ss+=a
        print("%.1f"%s)
    elif ss>310 and ss+a>520 and ss<=520: 
        s=(520-ss)*3.3+(ss+a-520)*4.2
        ss+=a
        print("%.1f"%s)
    elif ss>520: 
        s=a*4.2
        ss+=a
        print("%.1f"%s)
