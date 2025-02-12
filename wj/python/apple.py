import random
mp=[['^' for _ in range(8)] for _ in range(8)]
mp[7][0]='i'
apx=[-2,-2,-2,-2,-2]#|
apy=[-2,-2,-2,-2,-2]#-
for i in range(0,8):
  for j in range(0,8):
    print(mp[i][j],end='')
  print()
op='' 
x=0
scr=0
hp=10
dic={'a':-1,'d':1}
while 1:
  scrjd=0
  for i in range(5):
    if apy[i]==-2:
      while 1:
        r=random.randint(0,7)
        if not r in apx:
          break
      apx[i]=r
      apy[i]=-1
      break
  for i in range(5):
    if apy[i]!=-2:
      apy[i]+=1
    if apy[i]==8:
      mp[apy[i]-1][apx[i]]='^'
      while 1:
        r=random.randint(0,7)
        if not r in apx:
          break
      apx[i]=r
      apy[i]=0
  for i in range(5):
    if apy[i]>-1:
      mp[apy[i]-1][apx[i]]='^'
      mp[apy[i]][apx[i]]='@'
  op=input()
  try:
    g=dic[op]
  except:
    g=0
  if g==1 and x==7:
    continue
  if g==-1 and x==0:
    continue
  try:
    mp[7][x],mp[7][x+g]='^','i'
    x+=g
  except:
    pass
  for i in range(5):
    if x==apx[i] and apy[i]==7:
      scrjd=1
  for i in range(8):
    for j in range(8):
      print(mp[i][j],end='')
    print()
  if scrjd:
    randap=random.randint(0,9)
    if (not randap) or (not (randap-1)):
      hp-=3
      print('You hit a bomb! hp-3','now hp:',hp)
      if hp<0:
        print('you died!')
        print('final score: ',scr)
        while 1:
          pass
    elif not (randap-9):
      hp+=3
      scr+=1
      print('your hp+3!','now hp:',hp)
      print('you scored! score:',scr)
    else:
      scr+=1
      print('you scored! score:',scr)
