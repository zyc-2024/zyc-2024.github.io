#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[]){
    if(argc<2){return 0;}
    string gcc="D:\\MinGW\\bin\\g++.exe ";
    gcc+="\"";
    gcc+=argv[1];
    gcc+="\"";
    gcc+=" -o ";
    gcc+="\"";
    gcc+=argv[1];
    gcc+=".exe\" -O2 -std=c++14 -Wall";
    string gccc="\"";
    gccc+=argv[1];
    gccc+=".exe\"";
    system("@echo off");
    system(gcc.c_str());
    system(gccc.c_str());
}