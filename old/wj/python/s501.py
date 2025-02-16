note='''\
Note:
s5_chess is a singleplayer game developed by outryx.
Rule of game: The player can switch between operating the Cyan piece and the Purple piece and the player can move his piece by a distance of sqrt(5). The goal is to gather all the pieces of the same color together. (the rule can be changed if needed)
The code of this program can be freely copied for entertainment use.
Email: pscco_official@163.com
Luogu: a97_QwQ
'''
print(note)
import turtle as t,random as r,time as tm
mp=[]
cl=[]
clr=[1,0,0,1,0,1]
clg=[0,1,0,1,1,0]
clb=[0,0,1,0,1,1]
plr=['Cyan  ','Purple']
inbound=lambda x,y: x>=0 and y>=0 and x<6 and y<6
now=0
stretch0=2.4
dt=0.16
dx=[-1,1,2, 2, 1,-1,-2,-2]
dy=[ 2,2,1,-1,-2,-2,-1, 1]
ops=['2','3','e','d','x','z','a','q','s']
left=list(range(4))*9
spaces=[[0,0],[5,5]]
spaces0=[[0,0],[5,5]]
def color(i,j):
 if cl[i][j]>-1:
  mp[i][j].color(clr[cl[i][j]],clg[cl[i][j]],clb[cl[i][j]])
 else:
  c=spaces0[spaces.index([i,j])][0]
  q=4+int(c>4)
  mp[i][j].color(clr[q],clg[q],clb[q])
def detect():
 for i in range(6):
  for j in range(6):
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
t.title('s5_chess turtle board')
t.bgcolor(0.92,0.88,0.82)
for i in range(6):
 cl.append([])
 for j in range(6):
  if (i==0 or j==5) and (i==5 or j==0):
   cl[i].append(-1)
  else:
   cl[i].append(left.pop(left.index(r.choice(left))))
for i in range(6):
 mp.append([])
 for j in range(6):
  mp[i].append(0)
  mp[i][j]=t.Turtle()
  mp[i][j].up()
  stretch=stretch0
  mp[i][j].goto((i-2.5)*(20*stretch+2),(j-2.5)*(20*stretch+2))
  if cl[i][j]>-1:
   mp[i][j].shape('square')
  else:
   mp[i][j].shape('circle')
  mp[i][j].color(0.5,0.5,0.5)
detect()
while 1:
 print('- '*22)
 s=str(plr[now])+'\'s operation(23edxzaq or s for swap): '
 op=input(s)
 while not op in ops:
  op=input('Please input using the correct format: ')
 if op=='s':
  now=(now+1)%2
  continue
 ux=spaces[now][0]
 uy=spaces[now][1]
 vx=ux+dx[ops.index(op)]
 vy=uy+dy[ops.index(op)]
 if inbound(vx,vy):
  spaces[now]=[vx,vy]
  for i in range(2):
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
  color(ux,uy)
  detect()
  mp[vx][vy].ht()
  tm.sleep(dt)
  mp[vx][vy].st()
  tm.sleep(dt)
  mp[vx][vy].ht()
  tm.sleep(dt)
  mp[vx][vy].st()