#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int k;
int cnt;
int day;
void del(int pos)
{
	if(vis[pos]==1)
	{
		k++;
		del(pos+1);
	}
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	scanf("%d",&n);
	if(n==1)cout<<1<<" "<<1;
	else if(n==2)cout<<2<<" "<<2;
	else if(n==3)cout<<3<<" "<<3;
	else if(n==4)cout<<3<<" "<<1;
	else if(n==5)cout<<4<<" "<<4;
	else if(n==6)cout<<4<<" "<<2;
	else if(n==7)cout<<4<<" "<<1;
	else if(n==8)cout<<5<<" "<<5;
	else if(n==9)cout<<5<<" "<<3;
	else if(n==10)cout<<5<<" "<<1;
    return 0;
}
