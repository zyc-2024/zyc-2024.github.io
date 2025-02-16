#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
const int totw=110;
const int totp=7;
string words[1010]={
"朱砂","天下","杀伐","人家","韶华","风华","繁华","血染","墨染","白衣","素衣","嫁衣","倾城","孤城","空城","旧城","旧人","伊人","心疼","春风","古琴","无情","迷离","奈何","断弦","焚尽","散乱","陌路","乱世","笑靥","浅笑","明眸","轻叹","烟火","一生","三生","浮生","桃花","梨花","落花","烟花","离殇","情殇","爱殇","剑殇","灼伤","仓皇","匆忙","陌上","清商","焚香","墨香","微凉","断肠","痴狂","凄凉","黄梁","未央","成双","无恙","虚妄","凝霜","洛阳","长安","江南","忘川","千年","纸伞","烟雨","回眸","公子","红尘","红颜","红衣","红豆","红线","青丝","青史","青冢","白发","白首","白骨","黄土","黄泉","碧落","紫陌情深缘浅","情深不寿","莫失莫忘","阴阳相隔","如花美眷","似水流年","眉目如画","曲终人散","繁华落尽","不诉离殇","一世长安","辗转轮回","幻梦一场","孑然一身","蓦然回首","颠倒荣华","思念成河","寂寞如烟","独坐如莲","孑然凭栏","熏风满帘","望断秋水","柒指流年","过眼云烟","半世烟尘"};
string patterns[101][101]={
{"xx","，","xx","，","xx","了","xx","。"},{"xxxx","，","xxxx","，","不过是一场","xxxx","。"},
{"你说","xxxx","，","我说","xxxx","，","最后不过","xxxx","。"},{"xx","，","xx","，","许我一场","xxxx","。"},
{"一","x","一","x","一","xx","，半","x","半","x","半","xx","。"},{"你说","xxxx","，后来","xxxx","。"}
,{"xxxx","，","xxxx","，","终不敌","xxxx","。"}};
int pos,t;
int main()
{
	cout<<"请输入需要的恶俗句子数量,输入0将无限生成:"<<endl;
	srand(time(NULL));
	cin>>t;
	int fl=0;
	if(t==0)fl=1;
while(t--||fl)
{
	pos=rand()%totp;
	for(int i=0;patterns[pos][i][0];++i)
	{
		if(patterns[pos][i][0]!='x')
		{
			cout<<patterns[pos][i];
			continue;
		}
		int siz=patterns[pos][i].size();
		if(siz<=2)
		{
			int w=rand()%totw;
			while(words[w].size()>10||!words[w][0])w=rand()%totw;
			cout<<words[w];
		}
		else
		{
			int w=rand()%totw;
			while(!words[w][0])w=rand()%totw;
			if(words[w].size()<10)
			{
				cout<<words[w];
				w=rand()%totw;
				while(!words[w][0]||words[w].size()>10)w=rand()%totw;
			}
			cout<<words[w];
		}
	}
	sleep(2);
	puts("");
}
	return 0;
}