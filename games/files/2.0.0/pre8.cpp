#include<bits/stdc++.h>
//include from dgncx-snakev1.3.1.cpp
#include <iostream>
#include <deque>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;




//decleartion before everything、
//dgncx 
void cl();
void color(const int);
void SetPos(COORD);
void SetPos(int,int);
void clear(int,int);
void print(int,int,const int);
void print(const pair<int,int>,const int);
//dgncx
//global
int ri(int,int);
char home();
//g
void f1_1();
void f1_1_1();
void f1_2();
void f1_1_3();
void f1_1_2();
void f1_2_1();
void f1_2_2();
void f1_ADVANCEMENT(int);
void f1();
void fi();
void fc();
int f1_EET();
int f1_ENDT();
void f1_ENDING(int);
void f1_EGGCHECK(int);
void f1_DEBUG();
void f2();
char f2_HOME();
void f2_1();
void f2_2();
void f2_3();
void f2_4();
void f2_PLAY();
void f2_GENERATE_MAPS(int,int,int);
//end



int nowee[5]={0,0,0,0,0},
    end[5]  ={0,0,0,0,0};
string infoee[5]={
	"N坏了?!那就按Na2S2O3吧！",
	"豪臭！",
	"Ele!",
	"Geek!",
	"" },
endinfo[5]={
	"Happy Ending",
	"Sad Ending",
	"Na2S2O3 Ending",
	"Protection Ending",
	"Sublimation Ending"};
bool endgame=false;int eastereggt=5;
void cl(){system("cls");}



//dgncx function
void color(const int a) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a); }
void SetPos(COORD a) { HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleCursorPosition(out, a); }
void SetPos(int i, int j) { COORD pos = { (SHORT)i, (SHORT)j }; SetPos(pos); }
void clear(int x, int y) {
	swap(x, y);
	SetPos(x+1, y + 1);
	putchar(' ');
}
void clear(const pair<int, int> p) { clear(p.first, p.second); }
void print(int x, int y, const int col = 2) {
	swap(x, y);
	SetPos(x + 1, y + 1);
	color(col);
	putchar('#');
	color(15);
}
void print(const pair<int, int> p, const int col = 2) { print(p.first, p.second, col); }
//dgncx part ends



//cmd.exe color [attr]
//设置默认的控制台前景和背景颜色。
//
//COLOR [attr]
//
//  attr        指定控制台输出的颜色属性。
//
//颜色属性由两个十六进制数字指定 -- 第一个
//对应于背景，第二个对应于前景。每个数字
//可以为以下任何值:
//
//    0 = 黑色       8 = 灰色
//    1 = 蓝色       9 = 淡蓝色
//    2 = 绿色       A = 淡绿色
//    3 = 浅绿色     B = 淡浅绿色
//    4 = 红色       C = 淡红色
//    5 = 紫色       D = 淡紫色
//    6 = 黄色       E = 淡黄色
//    7 = 白色       F = 亮白色
//
//如果没有给定任何参数，此命令会将颜色还原到 CMD.EXE 启动时
//的颜色。这个值来自当前控制台
//窗口、/T 命令行开关或 DefaultColor 注册表
//值。
//
//如果尝试使用相同的
//前景和背景颜色来执行
// COLOR 命令，COLOR 命令会将 ERRORLEVEL 设置为 1。
//
//示例: "COLOR fc" 在亮白色上产生淡红色
//color():base16->10
//┍─┓
//├┯┥
//┃┽┃
//└┷┚



int ri(int start,int end){
	return (rand()%(end-start+1))+start;
} 
int f1_EET(){
	return nowee[0]+nowee[1]+nowee[2]+nowee[3]+nowee[4];
}
int f1_ENDT(){
	return end[0]+end[1]+end[2]+end[3]+end[4];
}
void f1_DEBUG(){
	cl();cout<<"Debug Mode(Type \'f1_DEBUG\' to access)";
	f1();Sleep(1000);fi();Sleep(1000);
	f1_1_1();f1_1_2();f1_1_3();f1_2_1();f1_2_2();
}
char home(){
	cout<<"Welcome to Games By 28AZYC!\n";
	char c;cout<<"====Menu===="<<endl;
	cout<<"1. Na2S2O3"<<endl;
	cout<<"2. Minesweeper"<<endl;
	cout<<"i. Info"<<endl;
	cout<<"c. Changelog"<<endl;
	cout<<"q. Quit"<<endl;
	cout<<"Please Choose:";c=_getch();return tolower(c);
}
void f1_EGGCHECK(int id){
	if(id==0){
		if(_getch()=='a'&&_getch()=='2'&&_getch()=='S'&&_getch()=='2'&&_getch()=='O'&&_getch()=='3'){
			f1_ADVANCEMENT(0);
		}
	}else if(id==1){
		if(_getch()=='o'&&_getch()=='m'&&_getch()=='o'){
			f1_ADVANCEMENT(1);
		}
	}else if(id==2){
		if(_getch()=='l'&&_getch()=='e'&&_getch()=='p'&&_getch()=='h'&&_getch()=='a'&&_getch()=='n'&&_getch()=='t'){
			f1_ADVANCEMENT(2);
		}
	}else if(id==3){
		if(_getch()=='e'&&_getch()=='e'&&_getch()=='k'){
			f1_ADVANCEMENT(3);
		}
	}else if(id==114){
		if(_getch()=='e'&&_getch()=='b'&&_getch()=='u'&&_getch()=='g'){
			f1_DEBUG();
		}
	}
}
void f1_1(){
	int a=ri(1,21);
	if(a==21){
		f1_1_3();
	}else if(a%2==0){
		f1_1_1();
	}else{
		f1_1_2();
	} 
}
void f1_1_1(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃小A忐忑的写了一封信向TA表明自己的心意，期待着收┃"<<endl;
	cout<<"┃到TA的回信。两天后TA主动找到小A，小A怀着激动又 ┃"<<endl;
	cout<<"┃紧张的心情听到TA说：我也喜欢你。此时的小A激动万┃"<<endl;
	cout<<"┃分，他们就这样开始交往了。上课的时候脑海里总是 ┃"<<endl;
	cout<<"┃浮现出彼此的身影，经常想的是周末要一起去哪里   ┃"<<endl;
	cout<<"┃玩……很快要期末考试了，他们俩的心中只有彼此， ┃"<<endl;
	cout<<"┃静不下心来复习。随着相处时间的变长，小A觉得TA身┃"<<endl;
	cout<<"┃上的光环在一点点消失，他们开始出现了一些矛盾和 ┃"<<endl;
	cout<<"┃争吵。而就在此时，他们在一起的事情被老师和家长 ┃"<<endl;
	cout<<"┃知道了......                                   ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃    The end!(Happy Ending)!Congratulations!    ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃           Press     to retry                  ┃"<<endl;
	cout<<"┖───────────────────────────────────────────────┙"<<endl;
	color(6);SetPos(18,15);cout<<"[R]";
	color(15);f1_ENDING(0);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2(){
	int a=ri(1,2);
	if(a%2==0){
		f1_2_1();
	}else{
		f1_2_2();
	} 
}
void f1_1_3(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃小A向TA表白的事情被班里的同学知道了，这条爆炸性┃"<<endl;
	cout<<"┃的新闻迅速在班级内传播、蔓延，同学们议论纷纷， ┃"<<endl;
	cout<<"┃并且传到最后已经变了味道。小A很害怕，不知道怎么┃"<<endl;
	cout<<"┃应对这样的流言蜚语，小A感到无助与卑微，而此时TA┃"<<endl;
	cout<<"┃也被卷入了舆论中心......                       ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃   The end!(Na2S2O3 Ending)!Congratulations!   ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃           Press     to retry                  ┃"<<endl;
	cout<<"┖───────────────────────────────────────────────┙"<<endl;
	color(6);SetPos(18,10);cout<<"[R]";
	color(15);f1_ENDING(2);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_1_2(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃小A鼓足勇气向喜欢的TA表明了自己的心意，结果得到┃"<<endl;
	cout<<"┃了TA的拒绝。接下来的一整天小A都浑浑噩噩的，课上┃"<<endl;
	cout<<"┃也不知道老师都讲了些什么，回到家里自己反复的听 ┃"<<endl;
	cout<<"┃着他们共同喜欢的歌曲，刷着他们的聊天记录，流下 ┃"<<endl;
	cout<<"┃了眼泪。之后的一段时间，小A一直打不起精神，并且┃"<<endl;
	cout<<"┃不知道该怎样与TA相处，好像已经做不回好朋友     ┃"<<endl;
	cout<<"┃了......                                       ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃    The end!(Sad Ending)!Congratulations!      ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃           Press     to retry                  ┃"<<endl;
	cout<<"┖───────────────────────────────────────────────┙"<<endl;
	color(6);SetPos(18,12);cout<<"[R]";
	color(15);f1_ENDING(1);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2_1(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃TA的形象在小A的日记本中逐渐清晰。TA的成绩很棒，┃"<<endl;
	cout<<"┃为人开朗又热情。越是心仪的东西越是不敢靠近，小 ┃"<<endl;
	cout<<"┃A总是装作默然，但心里却溢满惴惴不安。小A觉得只 ┃"<<endl;
	cout<<"┃有优秀的人才可以和TA并肩站在灿烂的阳光下。小A  ┃"<<endl;
	cout<<"┃希望像TA吸引小A一样，有一天小A也能让TA侧目。一 ┃"<<endl;
	cout<<"┃向不太努力的小A把全部精力都投入到了学习中，投  ┃"<<endl;
	cout<<"┃入到了发展自我中......                         ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃ The end!(Sublimation Ending)!Congratulations! ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃           Press     to retry                  ┃"<<endl;
	cout<<"┖───────────────────────────────────────────────┙"<<endl;
	color(6);SetPos(18,12);cout<<"[R]";
	color(15);f1_ENDING(4);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_2_2(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃这份喜欢压在小A心头，小A不确定是否要告诉TA，不 ┃"<<endl;
	cout<<"┃确定告诉TA的结果会是什么？自己能否承担起这份结 ┃"<<endl;
	cout<<"┃果？是否是对彼此最好的选择？思索了一段时间，小 ┃"<<endl;
	cout<<"┃A决定以朋友的身份默默守护。小A在TA需要的时候提 ┃"<<endl;
	cout<<"┃供帮助，两个人互相鼓励，共同成长。小A用自己的力┃"<<endl;
	cout<<"┃量守护着这个秘密，也守护着想要守护的人......   ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃  The end!(Protection Ending)!Congratulations! ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃           Press     to retry                  ┃"<<endl;
	cout<<"┖───────────────────────────────────────────────┙"<<endl;
	color(6);SetPos(18,11);cout<<"[R]";
	color(15);f1_ENDING(3);
	color(15);while(tolower(_getch())!='r'){}
}
void f1_ADVANCEMENT(int id){
	SetPos(80,2);cout<<"┍──────────────────────────────┐";
	SetPos(80,3);cout<<"┃                              ┃";
	SetPos(80,4);cout<<"┃                              ┃";
	SetPos(80,5);cout<<"└──────────────────────────────┚";
	SetPos(81,3);nowee[id]=1;cout<<"已达成彩蛋:"<<f1_EET()<<"/"<<eastereggt;
	SetPos(82,4);cout<<infoee[id];
	Sleep(3000);
}
void f1_ENDING(int id){
	SetPos(80,2);cout<<"┍──────────────────────────────┐";
	SetPos(80,3);cout<<"┃                              ┃";
	SetPos(80,4);cout<<"┃                              ┃";
	SetPos(80,5);cout<<"└──────────────────────────────┚";
	SetPos(81,3);end[id]=1;cout<<"已达成结尾:"<<f1_ENDT()<<"/"<<5;
	SetPos(82,4);cout<<endinfo[id];
	Sleep(3000);
}
void f1(){
	cl();cout<<"剧情"<<endl;
	cout<<"┍───────────────────────────────────────────────┓"<<endl;
	cout<<"┃那次的班级活动中，小A和TA一起准备一个才艺展示，┃"<<endl;
	cout<<"┃在一起准备的这段时间里，小A发现TA非常善解人意，┃"<<endl;
	cout<<"┃总是能照顾到小A的想法，表演起来又是那么自信大方┃"<<endl;
	cout<<"┃，从那个时候开始，小A心里萌生出了一种特别的感觉┃"<<endl;
	cout<<"┃。回到学校后小A总是不经意的望向TA的方向，会制造┃"<<endl;
	cout<<"┃和TA的偶遇。如果哪天TA多跟小A说了几句话，小A的 ┃"<<endl;
	cout<<"┃一整天都会特别开心。如果哪天TA没来学校，小A一天┃"<<endl;
	cout<<"┃都感觉心里空落落的。TA牵动着小A的心，小A意识到 ┃"<<endl;
	cout<<"┃自己好像喜欢上TA了。                           ┃"<<endl;
	cout<<"├───────────────────────────────────────────────┥"<<endl;
	cout<<"┃小A要不要把自己的心意告诉TA?                   ┃"<<endl;
	cout<<"├─────────────────────────┯─────────────────────┥"<<endl;
	cout<<"┃         是(Y)           ┃        否(N)        ┃"<<endl;
	cout<<"┖─────────────────────────┶─────────────────────┙"<<endl;
	char y=_getch();if(y=='Y'||y=='y'){f1_1();}else if(y=='n'){f1_2();}
	if(y=='N'){f1_EGGCHECK(0);f1_2();}
}
void fi(){
	cl();
	cout<<"Games(Na2S2O3+Minesweeper) by 28A_ZYC"<<endl;
	cout<<"Version: 2.0.0 pre-realease 3"<<endl;
	cout<<"Press     to return to the main menu.";
	color(6);SetPos(6,2);cout<<"[R]";
	color(15);while(tolower(_getch())!='r'){}
}
void f2(){
	while(endgame!=1){
		cl();color(15);
		switch(f2_HOME()){
			case '1':f2_1();cl();break;
			case '2':f2_2();cl();break;
			case '3':f2_3();cl();break;
			case '4':f2_4();cl();break;
			case 'q':endgame=1;break;
			
		}
	}
}
char f2_HOME(){
	cout<<"coming soon~"<<endl;
	cout<<"PS:there will be a lot of pre realease versions in 2.0.0\n";
	Sleep(1000);
	cout<<"=====Welcome to minesweeper!=====\n"<<endl;
	cout<<"Version:1.0.0 pre realease 8\n";
	cout<<"===MENU==="<<endl;
	cout<<"1.Small"<<endl;
	cout<<"2.Medium"<<endl;
	cout<<"3.Large"<<endl;
	cout<<"4.Custom"<<endl;
	cout<<"q.Quit"<<endl;
	cout<<"Please Choose:";return tolower(_getch());
}
void f2_1(){
	f2_GENERATE_MAPS(10,10,10);
	f2_PLAY();
}
void f2_2(){
	f2_GENERATE_MAPS(16,16,40);
	f2_PLAY();
}
void f2_3(){
	f2_GENERATE_MAPS(30,16,99);
	f2_PLAY();
}
void f2_4(){
	cout<<"lines:";
	int a,b,c;cin>>a;
	cout<<"rols:";cin>>b;
	cout<<"mines:";cin>>c;
	f2_GENERATE_MAPS(a,b,c);
	f2_PLAY();
}
void f2_GENERATE_MAPS(int l,int r,int m){
	int mines[m][2];
	bool chk[m];
	memset(chk,0,sizeof(chk));
	for(int i=0;i<m;i++){
		mines[i][0]=ri(0,l);
		mines[i][1]=ri(0,r);
	}
}
void f2_DRAWMAP(int l,int r){
	cl();
	//map start
	cout<<"X ┃\n──┷" ;
	//cols
	for(int i=0;i<l;i++){
		SetPos(4,1);
		printf("%-3d",i);
	}
	/*
	X ┃
	──┷
	Num  
	───
	
	Nu┃
 	 m┃
	  ┃
	  
	 ┍─ ┓
	 ┃N┃
	 └─┚
	 
	 (red)
	 ┍─ ┓
	 ┃X┃
	 └─┚
	*/
	Sleep(1000);
}
void f2_PLAY(){
	
}



int main(){
	srand(time(0));
	while(endgame!=1){cl();color(15);
		switch(home()){
			case '1':f1();cl();break;
			case '2':f2();cl();break;
			case 'i':fi();cl();break;
			case 'q':endgame=1;break;
			case 'h':f1_EGGCHECK(1);
			case 'e':f1_EGGCHECK(2);
			case 'g':f1_EGGCHECK(3);
			case 'd':f1_EGGCHECK(114);
			default:break;
		}
	}	
}
