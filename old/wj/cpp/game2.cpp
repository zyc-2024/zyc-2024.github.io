#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
struct ConsoleColor {
    WORD Value;
    ConsoleColor(WORD value) { Value = value; }
    ConsoleColor operator|(const ConsoleColor &Other) const {
        ConsoleColor result = Value;
        result.Value |= Other.Value;
        return result;
    }
    ConsoleColor operator|(const WORD &Other) const {
        ConsoleColor result = Value;
        result.Value |= Other;
        return result;
    }
};

// 支持设置的颜色（目前只有这几种，够用了）
namespace Color {
const ConsoleColor Red = FOREGROUND_RED;               // 红色
const ConsoleColor Green = FOREGROUND_GREEN;           // 绿色
const ConsoleColor Blue = FOREGROUND_BLUE;             // 蓝色
const ConsoleColor Gray = FOREGROUND_INTENSITY;        // 灰色
const ConsoleColor Yellow = Red | Green;               // 黄色
const ConsoleColor Purple = Red | Blue;                // 紫色
const ConsoleColor Aqua = Green | Blue;                // 浅蓝色
const ConsoleColor DefaultColor = Red | Green | Blue;  // 默认颜色（白色）
}  // namespace Color

// 设置颜色
// 用法1：SetColor(Color::Aqua); 这个将颜色设置为了浅蓝色，设置后打印的内容可以变色
// 用法2：cout << SetColor(Color::Green) << 内容; 同“用法1”效果但是更简便
string SetColor(const ConsoleColor &Color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color.Value);
    return "";
}
long long num=164212414;
int thing[114],has;
int tim,level,cs,danger,bs=1,amlhas; 
void CoutStr(const char *p){
	while(1){
		if(*p!=0){
			printf("%c",*p++);
		}
		else{
			break;
		}
		Sleep(100/bs);
	}
	printf("\n");
	Sleep(500); 
	return ;
}
void inal(){
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	system("pause");
	system("cls");
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
}
void start(){
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	system("cls");
}
void end(){
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
}
void Tip(){
//	mciSendString("play 打字.mp3 repeat",NULL,0,NULL);
	CoutStr("提示：请在选择时使用大写，不要多次按键，不要在选项未输出完时按键。 ");
	CoutStr("请选择输出速度倍率（初始200ms/字，输入0至9,0表示无间隔） "); 
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch>='1'&&ch<='9'){
				bs=ch-'0';
				break;
			}
			else if(ch=='0'){
				bs=200;
				break;
			}
		}
	}
	CoutStr("设置完成。"); 
	system("pause");
} 
void chapter1();
void chapter0(){
	Tip();
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	system("cls");
	CoutStr("序章 误入歧途");
	inal();
	CoutStr("你正在路上走着，一辆车飞驰而来，你妄图躲避，却还是被车一头创上。");
	inal();
	CoutStr("你听着耳边嘈杂的人声，一生的画面如同走马灯般掠过。");
	CoutStr("难道，我就这样死了吗？你想。");
	CoutStr("你逐渐失去了意识。");
	inal();
	CoutStr("等你再睁开眼时，你已经来到了一个陌生的地方。");
	inal();
	CoutStr("一个声音告诉你，只要能通过它给出的所有“关卡”，便能重获生命，回到社会。");
	CoutStr("而且，还能向它许下一个愿望，只要在它的能力范围之内，都可以实现。 ");
	CoutStr("你虽不情不愿，死了都要被人拉来做这种事，但是“复活”与“愿望”吸引了你。");
	CoutStr("“反正都死了，试一试也未必不可。” ");
	inal();
	CoutStr("那就开始吧，如果我没记错的话，这应该是第......");
	cout<<"             "<<num<<endl;
	Sleep(1000);
	CoutStr("   次了吧。");
	CoutStr("未待你仔细思考这句话，那个声音便消失了。");
	CoutStr("等你再抬头时，眼前出现了一个建筑物，看起来似乎是一个巨大的商场。");
	CoutStr("你意识到你可以移动了。 ");
	system("cls");
	chapter1();
	return ;
}
void end1(){
	system("cls"); 
	CoutStr("你越撕，身体越痛，当你将规则完全撕下时，你的身体裂成了两半。");
	CoutStr("END 1:不要破坏公物。");
	CoutStr("A.重新开始。");
	CoutStr("B.退出游戏。");
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				num++;
				chapter0();
				break;
			}
			else if(ch=='B'){
				exit(0);
			}
		}
	}
}
void end2(){
	system("cls"); 
	CoutStr("你带走了食物，可是，过了一会，你身上有食物中毒的症状传来，你死了。");
	CoutStr("END 2:是食物有问题吗？还是......没遵守规则呢？");
	CoutStr("A.重新开始。");
	CoutStr("B.退出游戏。");
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				num++;
				chapter0();
				break;
			}
			else if(ch=='B'){
				exit(0);
			}
		}
	}
}
void end3(){
	system("cls"); 
	CoutStr("你死了。走得很安详。");
	CoutStr("END 3:美好的死亡......吗？");
	CoutStr("A.重新开始。");
	CoutStr("B.退出游戏。");
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				num++;
				chapter0();
				break;
			}
			else if(ch=='B'){
				exit(0);
			}
		}
	}
}
void Get_Time(){
	cout<<"当前时间："<<tim/100<<"时"<<tim%100<<"分。";
	if(thing[2]!=-1){
		thing[2]++;
	}
	inal(); 
}
void Get_Level(){
	cout<<"当前楼层："<<level<<"层。";
	Sleep(500);
	if(thing[1]!=level){
		CoutStr("你意识到这里的空间有些问题。");
		thing[1]=-1;
	}
	else{
		thing[1]=level;
	}
	inal();
}
void chos3(){
	int number=rand()%10;
	if(number<=7){
		CoutStr("什么都没有。");
		inal();
	}
	if(number==8||number==9){
		CoutStr("你找到了一些食物。");
		inal(); 
	}
	if(number==10){
		CoutStr("你找到了一个钟，上面显示时间为11:45分。");
		if(thing[2]){
			CoutStr("你意识到这里的时间有些问题。");
			thing[2]=-1;
		}
		inal(); 
	}
}
void question1(int lx){
	if(lx==1){
		mciSendString("resume 打字.mp3",NULL,0,NULL);
		CoutStr("他四处看看，确定没人后告诉你：");
		CoutStr("不该问的事少问！");
		danger++;
		inal(); 
	}
	else if(lx==2){
		if(cs){
			CoutStr("这个吗......虽然不想告诉你，但是确实有问题。");
			cs--;
		}
		else{
			CoutStr("没有回答。");
			danger+=2;
		}
	}
	else if(lx==3){
		if(thing[3]==-1&&thing[4]){
			CoutStr("是我搞的，为了防止有人能够逃出去，很惊讶是吧，如果想出去，就去T6吧。");
			thing[4]--; 
		}
		else{
			CoutStr("没有回答。");
			danger+=5; 
		}
	}
	else{
		CoutStr("没有回答。");
		danger+=5; 
	}
}
void ask(int lx){
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	CoutStr("你决定向他询问：");
	CoutStr("A.对不起打扰了。");
	if(thing[1]==-1){
		CoutStr("B.这里的空间是有问题吗？");
	}
	if(thing[2]==-1){
		CoutStr("C.这里的时间是有问题吗？");
	}
	if(lx==4){
		CoutStr("D.你是谁？");
	}
//	mciSendString("pause 打字.mp3",NULL,0,NULL)/;
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				return ;
			}
			else if(ch=='B'&&thing[1]==-1){
				question1(lx);
				break;
			}
			else if(ch=='C'&&thing[2]==-1){
				question1(lx);
				break;
			}
			else if(ch=='D'&&lx==4){
				if(thing[5]==-1){
					CoutStr("我是B，就是入口的第二个红色字迹，这里有问题，快去T5!来不及了!");
					CoutStr("你身上“那个人”给的信物消失了。");
					thing[5]=0;
				}
				else{
					CoutStr("没有回答。");
					danger+=5;
				}
				break;
			}
		}
	}
}
void Level1();
void Level2();
void Level3();
void help(int lev){
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	int num=rand()%100,lx=0;
	if(num<=40){
		CoutStr("可是并没有人。");
		inal(); 
		return ;
	}
	if(num<=60){
		lx=1;
		CoutStr("你遇到了一名蓝衣IOI工作人员。");
		inal(); 
		CoutStr("他向你询问：请问您需要帮助吗？");
		inal(); 
	}
	else if(num<=70){
		lx=2;
		CoutStr("你遇到了一名蓝衣IOI委员会主席。");
		inal(); 
	}
	else if(num<=80){
		lx=3;
		CoutStr("你遇到了一名红衣IOI委员会会长。");
		inal(); 
	}
	else if(num<=85){
		CoutStr("你遇到了一名蓝衣IOI委员会会长。");
		inal(); 
	}
	else if(num<=90){
		CoutStr("你遇到了一名红衣IOI工作人员。");
		inal();
		CoutStr("他向你询问：请问您需要帮助吗？"); 
		inal(); 
	}
	else if(num<=95){
		CoutStr("你遇到了一名红衣IOI委员会主席。");
		inal(); 
	}
	else if(num<=100){
		lx=4;
		CoutStr("你遇到了？？？");
		inal(); 
	}
	ask(lx);
	if(lev==2){
		Level2();
	}
}
void Level1();
void Level0(){
	start();
	CoutStr("暂未施工！");
	CoutStr("回到T1。");
	end();
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				Level1();
			}
		}
	}
}
void Level1(){
	level=1;
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	system("cls");
	CoutStr("你决定：");
	CoutStr("A.搜寻附近。");
	CoutStr("B.看看这是几楼。");
	CoutStr("C.前往楼下。");
	CoutStr("D.前往楼上。");
	CoutStr("E.看看时间。");
	CoutStr("F.寻求帮助。");
	tim+=30;
	if(tim%100>=60){
		tim+=40;
	}
	if(danger>=3){
		CoutStr("一些烦躁的情绪出现在你心里。");
	}
	if(danger>=7){
		int animal=rand()%max((100-danger*5),1);
		if(animal<=5){
			CoutStr("你看见了兔子。");
			amlhas=1; 
		}
	}
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos3();
				Level1();
			}
			else if(ch=='B'){
				Get_Level();
				Level1();
			}
			else if(ch=='C'){
				Level2();
				break;
			}
			else if(ch=='D'){
				Level0();
				break;
			}
			else if(ch=='E'){
				Get_Time();
				Level2();
			}
			else if(ch=='F'){
				help(1);
			} 
		}
	}
}
void Level2(){
	level=2;
	start();
	CoutStr("你决定：");
	CoutStr("A.搜寻附近。");
	CoutStr("B.看看这是几楼。");
	CoutStr("C.前往楼下。");
	CoutStr("D.前往楼上。");
	CoutStr("E.看看时间。");
	CoutStr("F.寻求帮助。");
	tim+=30;
	if(tim%100>=60){
		danger--;
		if(danger==2){
			CoutStr("你不在烦躁了。");
		}
		if(danger==6){
			CoutStr("兔子消失了，就像他从没来过。");
		}
		tim+=40;
	}
	if(danger>=3){
		CoutStr("一些烦躁的情绪出现在你心里。");
	}
	if(danger>=7){
		int animal=rand()%max((100-danger*5),1);
		if(animal<=5){
			CoutStr("你看见了兔子。");
			amlhas=1; 
		}
	} 
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos3();
				Level2();
			}
			else if(ch=='B'){
				Get_Level();
				Level2();
			}
			else if(ch=='C'){
				Level3();
				break;
			}
			else if(ch=='D'){
				Level1();
				break;
			}
			else if(ch=='E'){
				Get_Time();
				Level2();
			}
			else if(ch=='F'){
				help(2);
			} 
		}
	}
}
void chos6();
void paper1(){
	start(); 
	CoutStr("某人的“信物”");
	CoutStr("听好了，不知何处的OIER，我不知你是怎么来到的IOI，但是，我将向你说一些内容，你可能无法理解或者怀疑，但是我希望你相信。");
	CoutStr("先自我介绍一下，我叫本杰明，他们都叫我“B”，这个地方的“管理者”是一个仿照“C”制作的机器人，名叫“Angela”。");
	CoutStr("这里的所有人都被Angela控制了，所以以后出现的“我”都是被他控制的。");
	CoutStr("红色的规则，呃，不如说是血色的规则是我写的，当然，也有可能是Angela用我的血写的，只有我的血有这个能力......");
	CoutStr("真正的出口在T6，希望你能相信我。");
	CoutStr("注意你的“危险值”，他不会显示，但当你做出错误的选择时，他会累加，你可以到Leavl2消除。");
	CoutStr("最后，希望你能找到Angela，这里，是逃不出去的......");
	CoutStr("A.收起来。");
	end();
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos6();
			}
		}
	}
}
void chos4();
void chos7();
void chos8(){
	start();
	thing[5]=-1; 
	CoutStr("你翻出了一张纸条，纸条埋的很深，使你找了很久。");
	CoutStr("纸条看起来有些陈旧，你决定：");
	CoutStr("A.读读看。");
	CoutStr("B.收起来。");
	CoutStr("C.丢了。");
	end();
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				paper1();
			}
			else if(ch=='B'){
				chos6();
			}
			else if(ch=='C'){
				thing[5]=0;
				chos6();
			}
		}
	}
}
void chos6(){
	start();
	if(thing[6]==-1){
		CoutStr("你遇见了你的亲人。");
		CoutStr("这是如此巧合，使你信不了一点。"); 
		CoutStr("他们呼唤着你：快走，孩子，我知道这个啥啥商场给了一堆规则，可这都是迷信啊！");
		CoutStr("我们找到出口了，你想在里面过夜吗？"); 
	}
	CoutStr("你翻找着一家店铺里的东西，可是什么都没有。");
	if(thing[6]==-1){
		CoutStr("亲人的喊声使你心烦意乱。");
	}
	CoutStr("你决定："); 
	CoutStr("A.回去。");
	CoutStr("B.继续找。");
	if(thing[6]==-1){
		CoutStr("C.跟着家人去寻找出口。");
	}
	end();
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				if(thing[6]==-1){
					thing[6]=0;
				} 
				chos4();
			}
			else if(ch=='B'){
				if(thing[6]==-1){
					thing[6]=0;
				}
				chos8();
			}
			else if(ch=='C'&&thing[6]==-1){
				danger+=4;
				chos7();
			}
		}
	}
} 
void chos7(){
	if(danger>=5){
		start();
		CoutStr("啊！瞧瞧我看见了什么！出口！我来了！你决定：");
		CoutStr("A.出去！");
		CoutStr("B.出去！");
		CoutStr("C.出去！");
		CoutStr("作者提示：玩过脑叶公司吗？经典3选1，你说结局是啥？");
		end();
		while(1){
			if(_kbhit()){
				char ch=_getch();
				if(ch=='A'||ch=='B'||ch=='C'){
					end3();
				}
			}
		}
	}
	else{
		start();
		CoutStr("前方是一个巨物的嘴，你光看了一眼，便冷汗直流。你决定：");
		danger+=4;
		CoutStr("A.快跑！");
		CoutStr("B.快跑！");
		CoutStr("C.快跑！");
		end();
		while(1){
			if(_kbhit()){
				char ch=_getch();
				if(ch=='A'||ch=='B'||ch=='C'){
					CoutStr("你一口气跑回了T3。");
					Level3();
				}
			}
		}
		
	} 
} 
void chos5(){
	CoutStr("你愈发深入了T3。");
	if(danger>=5){
		CoutStr("你觉得前方愈发光明。");
	}
	else{
		CoutStr("你觉得前方愈发黑暗。");
	}
	CoutStr("你决定：");
	CoutStr("A.继续向前");
	CoutStr("B.回去");
	if(danger<=1){
		CoutStr("C.搜索一下");
	}
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos6();
			}
			else if(ch=='B'){
				chos4();
			}
			else if(ch=='C'&&danger<=1){
				chos7();
			}
		}
	}
}
void Level4();
void chos4(){
	start();
	CoutStr("你深入了T3。");
	CoutStr("两旁有很多食品店，大多都是罐头食品，你决定：");
	CoutStr("A.带一点走");
	CoutStr("B.回去");
	CoutStr("C.继续向前");
	end(); 
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				end2();
				Level3();
			}
			else if(ch=='B'){
				chos5();
				chos4();
			}
			else if(ch=='C'){
				Level4();
				break;
			}
		}
	}
}
void Level3(); 
void Level4(){
	CoutStr("暂未施工！");
	CoutStr("A.回到T3。");
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				Level3();
			}
		}
	}
} 
void Level3(){
	level=3;
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	system("cls");
	CoutStr("你来到了T3。");
	CoutStr("这里不同于一二楼，看上去像一个......美食街？你知道这样形容并不恰当，可你看见了两旁一大堆食品店......");
	CoutStr("你决定：");
	CoutStr("A.搜寻附近。");
	CoutStr("B.看看这是几楼。");
	CoutStr("C.前往楼下。");
	CoutStr("D.前往楼上。");
	CoutStr("E.看看时间。");
	CoutStr("F.寻求帮助。");
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	tim+=30;
	if(tim%100>=60){
		tim+=40;
	} 
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos4();
				Level3();
			}
			else if(ch=='B'){
				Get_Level();
				Level3();
			}
			else if(ch=='C'){
				Level4();
				break;
			}
			else if(ch=='D'){
				Level2();
				break;
			}
			else if(ch=='E'){
				Get_Time();
				Level3();
			}
			else if(ch=='F'){
				help(1);
			} 
		}
	}
}
void chos2(){
//	mciSendString("resume 打字.mp3",NULL,0,NULL);
	system("cls");
	CoutStr("纸条上写了一些东西。");
	CoutStr("欢迎游客来到IOI商场，为了您的购物体验，请遵守以下规则。");
	SetColor(Color::Red);
	CoutStr("1.请不要尝试离开商场，商场是安全的。");//√ x
	SetColor(Color::DefaultColor);
	CoutStr("2.商场内仅有6层，且分别为T1,T2,T3,T4,T5,T6，不 存 在 T 0！ ");//√ 
	CoutStr("3.商场内可能会出现一些奇怪的现象，这种现象通常从T1至T6变多，若你感到心态崩溃，请寻找我们的工作人员帮助。"); //√ 
	CoutStr("4.我们的工作人员分为3种：1.蓝衣IOI工作人员，你可以找他解决普通的问题。") ;//√ 
	CoutStr("5.我们的工作人员分为3种：2.蓝衣IOI委员会主席，你可以找他解决大部分问题，但他不喜欢被打扰，你只有2次机会。"); //√ 
	CoutStr("6.我们的工作人员分为3种：3.红衣IOI委员会会长，你可以找他解决所有问题，但他不喜欢被打扰，你只有AK IOI(AKIOI,指去过所有楼层)才有可能获得他的帮助。");//x
	CoutStr("7.通常，工作人员的身份牌佩戴在胸前。若某工作人员“信息不完善”或衣服颜色不对，请勿寻求帮助。");//√ 
	CoutStr("8.商场内没有动物，若你看见了，一定是看错了，请尽快回到T2。");//√ 
	CoutStr("9.商场的食物区位于T3。");//x
	CoutStr("10.T1是绝对安全的。");//x 
	CoutStr("11.商场的威胁无处不在，当然，食物也无处不在。");//√ 
	CoutStr("12.小心你的家人。");//√ 
	CoutStr("13.商场除你以外没有人。");//√ 
	CoutStr("14.T4有一些“有趣的东西”，如果找到并带给IOI委员会会长，可能有一些奖励。");//√ 
	SetColor(Color::Red);
	CoutStr("15.想办法，这些都是...!(好像被人涂掉了)  ");//√ 
	SetColor(Color::DefaultColor);
	CoutStr("15.可以破坏公物，但要照价赔偿。");//x 
	CoutStr("纸条看完了，你注意到了纸条下渗出了一些东西，你决定：");
	CoutStr("A.撕下来。");
	CoutStr("B.进入商场。");
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				end1();
				break;
			}
			else if(ch=='B'){
				CoutStr("你进入了商场。");
				system("pause"); 
				Level2();
				break;
			}
		}
	} 
}
void chos1(){
	CoutStr("A.看看吧。");
	CoutStr("B.进入商场。");
//	mciSendString("pause 打字.mp3",NULL,0,NULL);
	while(1){
		if(_kbhit()){
			char ch=_getch();
			if(ch=='A'){
				chos2();
				break;
			}
			else if(ch=='B'){
				Level2();
				break;
			}
		}
	} 
}
void chapter1(){
	CoutStr("第一章 商场怪谈");
	cs=2;
	danger=0;
	amlhas=0;
	tim=800;
	memset(thing,0,sizeof(thing));
	inal();
	CoutStr("商场门口贴着一张纸条。");
	CoutStr("你意识到你需要做些什么。");
	chos1(); 
	return ;
}
int main(void){
	chapter0();
	return 0;
}
//resume
