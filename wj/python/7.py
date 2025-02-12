def qh(n):
    n=n/2
    n=n*n
    return n
def main():
    a=list(map(int,input().split()))
    i=0
    while 1:
        if 2**(a[1])<=a[0]:
            print(i)
            return 0
        a[0]=a[0]**2
        i+=1
        if 2**(a[1])<=a[0]:
            print(i)
            return 0
        a[0]=qh(a[0])
        #print(a[0])
        i+=1
        if i>100000:
            print("inf")
            return 0

main()
