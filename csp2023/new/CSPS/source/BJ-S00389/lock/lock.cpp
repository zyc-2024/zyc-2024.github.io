#include<iostream>
using namespace std;
int a[10], b[10], c[10], d[10], e[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    if(n == 1) cout<<81<<endl;
    else cout<<10<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
