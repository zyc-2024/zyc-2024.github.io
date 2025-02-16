note='''\
Note:
4c_chess is a multiplayer game developed by outryx.
Rule of game: 4 players take turns to operate their pieces to move by a distance of 1. The first one to gather all 5 pieces of one of his/hers colors together wins. (the rule can be changed if needed)
The code of this program can be freely copied for entertainment use.
Email: pscco_official@163.com
Luogu: a97_QwQ
'''
print(note)
import turtle as t,random as r,time as tm
mp=[]
cl=[]
clr=[0.3, 0.6, 1,   0,   0.1, 0.3, 0.1, 0.1, 0.4, 0.4, 0.7, 0.9]
clg=[0,   0.1, 0.4, 0.3, 0.6, 1,   0.1, 0.1, 0.4, 0.4, 0.7, 0.9]
clb=[0,   0.1, 0.4, 0,   0.1, 0.3, 0.3, 0.7, 1  , 0.1, 0.2, 0.3]
plr=['Red   ','Green ','Blue  ','Yellow']
inbound=lambda x,y: x>=0 and y>=0 and x<8 and y<8
now=0
stretch0=2.4
dt=0.16
dx=[0,-1,0,1]
dy=[1,0,-1,0]
ops=['w','a','s','d','p']
left=list(range(12))*5
spaces=[[0,0],[0,7],[7,0],[7,7]]
spaces0=[[0,0],[0,7],[7,0],[7,7]]
def color(i,j):
 if cl[i][j]>-1:
  mp[i][j].color(clr[cl[i][j]],clg[cl[i][j]],clb[cl[i][j]])
 else:
  c,d=spaces0[spaces.index([i,j])][0],spaces0[spaces.index([i,j])][1]
  q=1+int(c>6)*6+int(d>6)*3
  mp[i][j].color(clr[q],clg[q],clb[q])
def detect():
 for i in range(8):
  for j in range(8):
   stretch=stretch0
   if cl[i][j]==-1:
    stretch=stretch0-0.2
   mp[i][j].shapesize(stretch,stretch)
   do=0
   for x,y in spaces:
    if abs(x-i)<2 and abs(y-j)<2:
      do=1
   if do:
    color(i,j)
r.seed(input('Seed of game:'))
t.delay(0)
t.resizemode('user')
t.title('4c_chess turtle board')
t.bgcolor(0.92,0.88,0.82)
for i in range(8):
 cl.append([])
 for j in range(8):
  if (i==0 or i==7) and (j==0 or j==7):
   cl[i].append(-1)
  else:
   cl[i].append(left.pop(left.index(r.choice(left))))
for i in range(8):
 mp.append([])
 for j in range(8):
  mp[i].append(0)
  mp[i][j]=t.Turtle()
  mp[i][j].up()
  stretch=stretch0
  mp[i][j].goto((i-3.5)*(20*stretch+2),(j-3.5)*(20*stretch+2))
  if cl[i][j]>-1:
   mp[i][j].shape('square')
  else:
   mp[i][j].shape('circle')
  mp[i][j].color(0.5,0.5,0.5)
detect()
while 1:
 print('- '*20)
 s=str(plr[now])+'\'s operation(wasd or p for pass): '
 op=input(s)
 while not op in ops:
  op=input('Please input using the correct format: ')
 if op=='p':
  now=(now+1)%4
  continue
 ux=spaces[now][0]
 uy=spaces[now][1]
 vx=ux+dx[ops.index(op)]
 vy=uy+dy[ops.index(op)]
 if inbound(vx,vy):
  spaces[now]=[vx,vy]
  for i in range(4):
   if i==now:
    continue
   if spaces[i]==[vx,vy]:
    spaces[i]=[ux,uy]
  cl[ux][uy],cl[vx][vy]=cl[vx][vy],cl[ux][uy]
  ushape=mp[ux][uy].shape()
  vshape=mp[vx][vy].shape()
  mp[ux][uy].shape(vshape)
  mp[vx][vy].shape(ushape)
  ucol=mp[ux][uy].color()[0]
  vcol=mp[vx][vy].color()[0]
  mp[ux][uy].color(vcol)
  mp[vx][vy].color(ucol)
  detect()
  mp[vx][vy].ht()
  tm.sleep(dt)
  mp[vx][vy].st()
  tm.sleep(dt)
  mp[vx][vy].ht()
  tm.sleep(dt)
  mp[vx][vy].st()
 now=(now+1)%4