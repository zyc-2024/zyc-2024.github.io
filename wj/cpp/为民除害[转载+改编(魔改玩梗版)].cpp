#include<bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
int hh = 0;
long long jx = 15 , fx = 8, hpx = 30 , jy = 0, gold = 0 , lv = 1 , b ,lvd,yyi,yer,ysan,ysi,hhx,dhhx;
int jpn,zt = 0 , dzt = 0 , ztx , dztx ;
string cinmmz , cinboss;
long long j = jx , f = fx, hp = hpx;
bool dhpx = false,er=false;
string name;
bool z1,z2,z3,z4,z5,z6,z7;
int slowout(char *p) {
	while(1) {
		if(*p!=0)
			printf("%c",*p++);
		else
			break;
		Sleep(70);
	}
}
int so(char *o) {
	while(1) {
		if(*o!=0)
			printf("%c",*o++);
		else
			break;
		Sleep(10);
	}
}
void wap(int gongji , int fangyu ,int xueliang,string boss,int jingyan , int jinbi) {
	Sleep(900);
	slowout("\n是否攻击/逃跑？(1/else)");
	cin >> ysi;

	zt = 0;
	dzt = 0;
	while(hp > 0 && xueliang > 0 && ysi == 1) {
		j = jx;
		f = fx;
		if(jpn == 1) {
			system("cls");
			cout << "\n"<<name<<"使用了---飞坤在天！\n";
			j += 300;
			system("pause");
		}
		dztx = 0;
		ztx = 0;
		system("cls");
		dhpx = false;
		cout << boss;
		printf("剩余血量%d\n",xueliang);
		Sleep(800);
		cout << name;
		printf("剩余血量%d\n",hp);
		Sleep(800);
		srand(time(0));
		ztx = rand() % 3 + 1;
		if(ztx != 1)zt ++;
		if(zt == 1) {
			cout << name << "精神振作了一点，状态增加一级!\n";
			j += 2;
		}
		if(zt == 2) {
			cout << name << "燃起斗志了，状态增加二级!\n";
			j += 3;
		}
		if(zt == 3) {
			if(hhx > 1) {
				srand(time(0));
				ztx = rand()%3+1;
				if(ztx == 1) {
					cout << name << "恢复正常了，状态增加零!\n";
					j = jx;
					hhx = 0;
				}
			} else {
				cout << name << "进入暴走状态，火力全开！！！\n";
				j += 4;
				hhx ++;
			}
		}
		cout << name << "向" << boss << "攻击!\n";
		if(j>=fangyu) {
			xueliang -= j - fangyu;
			cout<<boss;
			printf("扣了%d滴血\n",j-fangyu);
		} else {
			xueliang-=0;
			cout<<boss;
			printf("扣了0滴血");
		}

		if(xueliang <= 0) {
			printf("你打败了");
			cout << boss;
			printf("!\n");
			jy += jingyan;
			gold += jinbi;
			dhpx = true;
			system("pause");
		} else {
			srand(time(0));
			dztx = rand() % 3 + 1;
			if(dztx != 1)dzt ++;
			if(dzt == 1) {
				cout << boss << "精神振作了一点，状态增加一级!\n";
				gongji += 2;
			}
			if(dzt == 2) {
				cout << boss << "燃起斗志了，状态增加二级!\n";
				gongji += 3;
			}
			if(dzt == 3) {
				if(dhhx > 1) {
					srand(time(0));
					dztx = rand()%3+1;
					if(dztx == 1) {
						cout << boss << "恢复正常了，状态增加零!\n";
						gongji = jx;
						dhhx = 0;
					}
				} else {
					cout << boss << "进入暴走状态，火力全开！！！\n";
					gongji += 4;
					dhhx ++;
				}
			}
			cout << boss;
			printf("向你的");
			cout << name << "扑来！\n";
			hp -= gongji - f;
			cout << "你的" << name;
			printf("扣了%d滴血\n",gongji-f);
			system("pause");
			if(hp <= 0) {
				slowout("凉凉...\n");
				hp = hpx;
				system("pause");
				return;
			}
		}
	}
}
void gameover() {
	slowout("你打败了蔡徐坤，成为了只因国的英雄。");
	slowout("你的事迹也成为了一代传奇...\n");
}
/*void senlinchuanshuo()
{
system("cls");
system("color 79");
cout<<"你要查看什么?\n";
cout<<"1.茶杯犬 2.小金毛 3.大金毛 4.藏獒 5.老虎 6.小象\n7.大象 8.会唱跳rap的坤 9.开朗网友 10.霸王龙 11.灭霸\n";
int shuru;
cin>>shuru;
switch(shuru)
{
case 1:
}
}*/
int main() {
	system("color 07");
	bool kg = false;
shurumokuai:
	int huida=MessageBox(NULL,"请不要尝试输入任何乱码，否则将导致游戏崩溃！","提示",MB_YESNO);
	if(huida==IDYES)
		MessageBox(NULL,"谢谢配合！","提示",MB_OK);
	else
		goto shurumokuai;
	so("\n\n\n\n\n\n\n--------------------------------------------------------为民除害-------------------------------------------------------\n-----------------------------------------------------(魔改玩梗版本)----------------------------------------------------\n\n\n\n\n\n");
	slowout("浏阳艺校1802张浩天制作\n雁江一小5632钟子宇改编\n\n\n\n");
	for(int i = 1; i <= 10; i++) {
		system("color 4F");
		system("color 5B");
		system("color 6C");
		system("color 3D");
		system("color 66");
	}
	system("cls");
xuanzemokuai:
	slowout("你正走着，看见了一只流浪只因，是否捡起？\n");
	huida=MessageBox(NULL,"是否捡起","请选择",MB_YESNO);
	if(huida==IDYES)
		MessageBox(NULL,"你是个善良的人！","提示",MB_OK);
	else {
		slowout("你没有捡起它，而是向一旁走去...\n");
		goto xuanzemokuai;
	}
	slowout("给它取个名字：");
	getline(cin,name);
	if(hh != 0)goto a;
	else if(hh==0) {
		cout<<"游戏开始了!";
		Sleep(2000);
		system("color 8F");
		system("cls");
		slowout("只因国有一位杀人无数的罪犯——蔡徐坤\n");
		slowout("传说他杀人不眨眼，最爱收集血液\n");
		slowout("知道了这些，你决定为民除害！！！\n");
		system("pause");
		system("cls");
		cout<<"提示:\n";
		if(lv == 1)slowout("在你达到三级之前在梗林里攻击小孩哥和玛卡巴卡，千万不要攻击其他!\n");
		if(hp < 10000)slowout("千万别攻击电摇小子!\n");
		if(hp < 40000)slowout("你打不过牢大!\n");
		slowout("蔡徐坤住在只因之堡中\n");
		system("pause");
		goto a;
	}
a3:
	cout<<"你想要";
	cout<<"改成什么名字？\n";
	cin >> name;
	slowout("改名成功！");
r:
	hh++;
	system("cls");
	system("cls");
	cout <<name<< "\n技能伤害:" << j << "\n防御:" << f << "\n最大生命值:" << hp << "\n等级:" << lv << " 还差" << lv * 50 - jy << "经验升级" << "\n￥:" << gold << endl;
	/*
	技能伤害 j
	防御 f
	最大生命值 hp
	等级 lv
	经验 jy
	钱 gold
	*/
	system("pause");
gameover2:
	if(kg==true) {
		cout<<"你竟然修炼了外挂神技！！！"<<endl;
		slowout("蔡徐坤服下金坷垃状态大增") ;
		wap(40000,6000,100000,"蔡徐坤",100000000,100000000);
	}
	printf("蔡徐坤向你的");
	cout << name;
	printf("扑来!\n");
	Sleep(800);
	if(hp<=1000) {
		cout << "你的" << name << "还剩1丝血\n";
		slowout("突然，你的宠物感觉到一股力量由你传来\n");
		Sleep(800);
		slowout("它进化成了篮球明星菜鸡！\n");
		j += 10000;
		jx=j;
		f += 10000;
		fx=f;
		hp += 10000;
		wap(10000,6000,100000,"蔡徐坤",100000000,100000000);
	}
	if(dhpx == false || ysi != 1) goto a;
	else gameover();
b:
	int pp;
	srand((unsigned)time(NULL));
	if(j>=150)
		pp=5+rand()%13;
	else if(j<=150)
		pp = 1+rand()%5;
	if(pp == 1) {
		cout << "你遇到了小孩哥!(危险度:0级)";
		wap(10,5,20,"小孩哥",100,20);
		goto a;
	}
	if(pp == 2) {
		cout << "你遇到了一只玛卡巴卡!(危险度:0.5级)";
		wap(20,15,40,"玛卡巴卡",150,35);
		goto a;
	}
	if(pp == 3) {
		cout << "你遇到了一只男神GG爆!(危险度:1级)";
		wap(40,20,100,"男神GG爆",350,80);
		goto a;
	}
	if(pp == 4) {
		cout << "你遇到了五星上将麦克阿瑟!(危险度:2级)";
		wap(70,50,250,"五星上将麦克阿瑟",700,100);
		goto a;
	}
	if(pp == 5) {
		cout << "你遇到了一只大香蕉!(危险度:3级!)";
		wap(150,200,500,"大香蕉",1000,120);
		goto a;
	}
	if(pp==6) {
		cout << "你遇到了一只老六!(危险度:2.5级)";
		wap(100,180,300,"老六",1500,150);
		goto a;
	}
	if(pp==7) {
		cout << "你遇到了一只会唱跳rap的坤!(危险度:5级)";
		wap(500,600,5000,"会唱跳rap的坤",2300,230);
		goto a;
	}
	if(pp == 10) {
		cout << "你遇到了端着鸡汤的穿山甲!(危险度:4级!!)";
		wap(200,190,1000,"端着鸡汤的穿山甲",2000,200);
		goto a;
	}
	if(pp==9) {
		cout << "你遇到了一只开朗网友!(危险度:5.5级!)";
		wap(1000,1300,8000,"开朗网友",2800,280);
		goto a;
	}
	if(pp == 11) {
		cout << "你遇到了一只电摇小子!(危险度:6级!!!)";
		wap(2000,2000,10000,"电摇小子",3000,300);
		goto a;
	}
	if(pp == 12) {
		cout << "你遇到了一只牢大!(危险度:无法测量!!!!!!!!!)";
		wap(10000,15000,40000,"牢大",4000,900);
		goto a;
	}
x:
	slowout("输入错误!");
	Sleep(500);
	goto a;
BOSS:
	slowout("确定吗?(1/2)");
	cin >> ysan;
	if(ysan == 2) goto a;
	if(ysan != 2 && ysan != 1) goto x;
	system("cls");
	slowout("你进入了只因之堡。突然，你身后大门竟然自己关上了\n");
	slowout("周围一片阴森，四处布满危机，你听到有人来了！！！\n");
	Sleep(500);
	slowout("小黑子守卫向你扑来!\n");
	wap(2000,1000,10000,"小黑子守卫",1000,2000);
	if(dhpx == false || ysi != 1)goto a;
	slowout("你打败了小黑子守卫，继续前进。\n");
	slowout("虽然首战告捷，但是你知道，真正的敌人远远不止如此，你更加警惕了！！！\n");
	Sleep(500);
	slowout("爱坤巡警向你扑来!\n");
	wap(2500,2000,10000,"爱坤巡警",2000,4000);
	if(dhpx == false || ysi != 1)goto a;
	slowout("你打败了爱坤巡警，继续往前探索。\n");
	slowout ("你来到了只因之堡的顶层，如果线索正确的话，蔡徐坤应该就在里面！！！\n");
	Sleep(500);
	slowout("蔡徐坤的贴身保镖向你扑来!\n");
	wap(4000,3000,20000,"蔡徐坤的贴身保镖",3000,7000);
	if(dhpx == false || ysi != 1)goto a;
	slowout("你打败了蔡徐坤的贴身保镖，来到了只因之堡的最深处\n");
	Sleep(500);
c:
	system("cls");
	Sleep(800);
	slowout("你要买什么？\n");
	cout <<"1.皮质篮球(攻击+4)20￥\n\n2.铁质篮球(攻击+5)30￥\n\n3.金质篮球(攻击+6)40￥\n\n4.钛合金篮球(攻击+7)50￥\n\n5.钻石篮球(攻击+8)60￥\n\n6.技能 --- 飞坤在天150￥ \n\n7.40米大篮球(攻击加500)300￥\n\n0.退出\n\n";
	cout<<"你有"<<gold<<"元钱";
	cin >> b;
	if(b == 1) {
		if(gold < 20)
			slowout("买不起!\n");
		if(z1) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 20;
			jx += 4 ;
			j=jx;
			z1=true;
		}
		system("pause");
		goto c;
	}
	if(b == 2) {
		if(gold < 30)
			slowout("买不起!\n");
		if(z2) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 30;
			jx += 5 ;
			j=jx;
			z2=true;
		}
		system("pause");
		goto c;
	}
	if(b == 3) {
		if(gold < 40)
			slowout("买不起!\n");
		if(z3) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 40;
			jx += 6 ;
			j=jx;
			z3=true;
		}
		system("pause");
		goto c;
	}
	if(b == 4) {
		if(gold < 50)
			slowout("买不起!\n");
		if(z4) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 50;
			jx += 4 ;
			j=jx;
			z4=true;
		}
		system("pause");
		goto c;
	}
	if(b == 5) {
		if(gold < 60)
			slowout("买不起!\n");
		if(z5) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 60;
			jx += 7;
			j=jx;
			z5=true;
		}
		system("pause");
		goto c;
	}
	if(b == 6) {
		if(gold < 150)
			slowout("买不起!\n");
		if(z6) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 150;
			jpn =1;
			z6=true;
		}
		system("pause");
		goto c;
	}
	if(b==7) {
		if(gold<300)
			slowout("买不起\n");
		if(z7) {
			slowout("你买过了");
			cout<<endl;
		} else {
			slowout("购买成功!\n");
			gold -= 300;
			jx+=500;
			j=jx;
			z7=true;
		}
		system("pause");
		goto c;
	}
	if(b == 0)
		goto a;
	if(b != 0&&b != 1&&b != 2&&b != 3&&b != 4&&b != 5&&b != 6&&b!=7)
		goto x;
a:
	hh++;
	int i;
	for(i = 0; lv * 50 - jy <= 0; i++) {
		lv += 1;
		jx += lv * 8;
		hpx += lv * 10;
		fx += lv * 6;
		gold += lv * 15;
		jy -= lv * 50;
	}
	if(i > 0) {
		cout<<name<<"升了";
		cout << i;
		cout<<"级!";
		Sleep(500);
	}
	j = jx;
	f = fx;
	hp = hpx;
	system("cls");
	cout<<"你要干什么?\n";
	if(kg==false) {
	cout<<"1.去梗林(试炼场) 2.去商店 3.查看属性 4.重命名\n5.修炼开挂神技 6.前往只因之堡 7.查看提示";
    }
	else cout<<"1.去梗林(试炼场) 2.去商店 3.查看属性 4.重命名\n5.修炼开挂神技-二阶 6.前往只因之堡 7.查看提示";
	int a;
	cin >> a;
	if(a == 1) goto b;
	if(a == 2) goto c;
	if(a == 3) goto r;
	if(a == 4) goto a3;
	if(a==6) goto BOSS;
	if(a != 1 && a != 2 && a != 3 && a != 4 && a != 5 && a != 6 && a != 7&&a!=8) goto x;
	if(a == 7) {
		if(lv == 1)slowout("在梗林里攻击小孩哥和玛卡巴卡，千万不要攻击其他!\n");
		if(kg == true)slowout("别以为开挂了就谁都打得过了!\n");
		if(hp < 10000)slowout("千万别攻击电摇小子!\n");
		if(hp < 40000)slowout("你打不过牢大!\n");
		system("pause");
		goto a;
	}
	if(a == 5) {
		if(kg == true) {
			if(er){
			    slowout("您已修炼开挂神技-二阶!\n");
			    goto a;
			}
			slowout("您已修炼开挂神技!\n");
			slowout("修炼开挂神技-二阶特权:\n");
	    	cout << "1.更高伤害\n";
		    cout << "2.更高血量\n";
	    	cout << "3.更高防御\n";
	    	cout << "4.超多经验\n";
	    	system("pause");
		    slowout("请输入密码:");
	    	cin >> cinmmz;
    		if(cinmmz == "禁止开挂") {
	    		hpx += 5000;
			    hp = hpx;
    			jx += 3000;
	    		fx += 2000;
		    	j = jx;
			    f = fx;
    			jy += 30000;
	    		er = true;
			    for(int i = 1; i <= 10; i++) {
				    system("color 18");
    				system("color 29");
	    			system("color 31");
		    		system("color 42");
		            system("color 53");
			    	system("color 64");
    				system("color 7B");
	    			system("color 9E");
		    	}
			    slowout("修炼成功!\n");
    			system("pause");
	    		goto a;
		    } else {
			    slowout("错误!");
    			goto a;
	    	}
	    }
		    }
		slowout("修炼特权:\n");
		cout << "1.高伤害\n";
		cout << "2.高血量\n";
		cout << "3.高防御\n";
		cout << "4.超多金币\n";
		cout << "5.获得技能 ———飞坤在天!\n";
		system("pause");
		slowout("请输入密码:");
		cin >> cinmmz;
		if(cinmmz == "拒绝外挂") {
			hpx = 15000;
			gold += 10000;
			hp = hpx;
			jx += 3000;
			fx += 2000;
			j = jx;
			f = fx;
			jy += 15000;
			kg = true;
			jpn ++;
			for(int i = 1; i <= 10; i++) {
				system("color 18");
				system("color 29");
				system("color 31");
				system("color 42");
				system("color 53");
				system("color 64");
				system("color 7B");
				system("color 9E");
			}
			slowout("修炼成功!\n");
			system("pause");
			goto a;
		} else {
			slowout("错误!");
			goto a;
		}
	}
