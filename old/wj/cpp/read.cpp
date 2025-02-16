#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;

int main(){
    ifstream p1("part1.dat",ios::in | ios::binary);
    ofstream out("input.zip",ios::out | ios::binary);
    char c;
    while(p1.read(&c,1)) out.write(&c,1);
    p1.close();
    ifstream p2("part2.dat",ios::in | ios::binary);
    while(p2.read(&c,1)) out.write(&c,1);
    p2.close();
    ifstream p3("part3.dat",ios::in | ios::binary);
    while(p3.read(&c,1)) out.write(&c,1);
    p3.close();
    out.close();
    return 0;
}
