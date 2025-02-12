/*
    TODO1 im:** difficulty:**** bizzard and Z(jin_shu_dao_dian)
*/

#include <bits/stdc++.h>
#include <unistd.h>
#include <windows.h>
#include <random>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>

#define O cout
#define I cin

using namespace std;

void printt(int wei, int hei);
void gameorplotorpic();
void plot();
void cdstory();
void cluestory();
void smallgame();
void qkhcq();
void link();

int coin1, coin2, coin3;
int wei=0;
int hei=0;
int getcoin;
int getz;
int coincnt = 0;
int zcnt=0;
int coinxy[1000];
int gamecnt = 0;
unsigned int cccoin;

bool clickflag = 0;
bool coincolor = false;
bool juqingcd1 = 0, juqingcd2 = 0, juqingcd3 = 0, juqingcd4 = 0;
bool picflag[1000][1000] = {0};
bool gameone = 0;
bool pdwin(int wei, int hei);

char role = '$';
char clouds = '$';
char pic[1000][1000];
char readd;

string s = "";

void SetColorAndBackground(int ForgC, int BackC){
	WORD wColor = ((BackC&0x0f) << 4) + (ForgC&0x0f);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void rgb_init(){
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);
	GetConsoleMode(hOut, &dwOutMode);
	dwInMode |= 0x0200;
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);
	SetConsoleMode(hOut, dwOutMode);
}

void rgb_set(int wr, int wg, int wb, int br, int bg, int bb){
	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg, bb);
}

void slowprint(string slow){
	for(int i = 0; i < slow.length(); i++){
		O << slow[i];
		Sleep(85);
	}
}

void readin(){
	system("cls");
	O << "Read your archive or not?(y or n)     ";
	char readchoice;
	cin_readchoice:
	I >> readchoice;
	switch (readchoice){
		case ('y'):
			break;
		case ('n'):
			O << "ok.";
			sleep(1);
			return;
			break;
		default:
			O << "wrong input!\n\n";
			qkhcq();
			goto cin_readchoice;
	}
	ifstream in("l_b_z.dat");
	in >> gamecnt >> gameone >> juqingcd1 >> juqingcd2 >> juqingcd3 >> juqingcd4;
    in.close();
}

void saveout(){
	system("cls");
	O << "Save your archive or not?(y or n)     ";
	char savechoice;
	cin_savechoice:
	qkhcq();
	I >> savechoice;
	switch (savechoice){
		case ('y'):
			break;
		case ('n'):
			O << "ok.";
			sleep(1);
			return;
			break;
		default:
			O << "wrong input!\n\n";
			goto cin_savechoice;
	}
    ofstream out("l_b_z.dat");
    out << gamecnt << " " << gameone << " " << juqingcd1 << " " << juqingcd2 << " " << juqingcd3 << " " << juqingcd4;
    out.close();
}

void yan_hua(int n){
	rgb_init();
	srand((unsigned) time(NULL));
	int cd4_rd1;
	int cd4_rd2;
	int cd4_rd3;
	for (int k = 0; k < n; k++){
		system("cls");
		for (int i = 0; i < 29; i++){
			for (int j = 0; j < 60; j++){
				cd4_rd1 = rand() % 256;
				cd4_rd2 = rand() % 256;
				cd4_rd3 = rand() % 256;
				rgb_set(255, 255, 255, cd4_rd1, cd4_rd2, cd4_rd3);
				O << "  ";	
			}
			O << "\n";
		}
		Sleep(50);
	}
	rgb_set(255, 255, 255, 0, 0, 0);
}

bool drawcoin_pd(int a){
	for (int i = 1; i <= cccoin; i++){
		if (a == coinxy[i]) return true;
	}
	return false;
}

bool rdcoin_pd(int a){
	for (int i = 1; i < a; i++){
		if (coinxy[i] == coinxy[a]) return true;
	}
	return false;
}

bool drawz_pd(){
	
}

void rdcoin(int cccoin, int wei, int hei){
	srand((unsigned) time(NULL));
	for(int i = 1; i <= cccoin; i++){
		rdcoina:
		coinxy[i] = 1 + rand() % (wei * hei);
		if ((coinxy[i] == 1)||(rdcoin_pd(i))) goto rdcoina;
	}
}

void rdz(){
	
}

void atakz(){
	
}

void qkhcq(){
	cin.clear(); 
}

void printt(int wei,int hei){
	int printcnt = 0;
	SetColorAndBackground(15, 0);//6,0->deep yellow  14,0->not deep yellow(coins' color) 
	system("cls");
	for (int i = 0; i <= hei + 1; i++){
		for (int j = 0; j <= wei + 3; j++){
			if (pic[i][j] == '$'){
				if (coincolor){
					SetColorAndBackground(6, 0);
					coincolor = false;
				} else {
				SetColorAndBackground(14, 0);
				coincolor = true;
				}
				O << '$';
				SetColorAndBackground(15, 0);
				continue;
			}
			O << pic[i][j];
		}
		if (i == 1 && getcoin == 1){
			SetColorAndBackground(6, 0);
			O << "        you get a coin!";
			SetColorAndBackground(15, 0);
		}
		if (i == 2 && getcoin == 1){
			O << "        you still need to get " << cccoin - coincnt << " coin";
			if (cccoin - coincnt > 1) O << 's';
		}
		O << '\n';
	}
	O << "\nyou are " << role << "\n" << clouds << "s are the cells that you haven't been there yet\n'$' are coins\nyou need to control " << role << " by wsad\nyour goal is to collect all the coins as fast as possible\nand then clear all the clouds,the fewer steps the better\n";
}

bool pdwin(int wei,int hei){
	int cntflag = 0;
	for (int i = 1; i < hei + 1; i++){
		for (int j = 1; j < wei + 1; j++){
			if (picflag[i][j]) cntflag++;
		}
	} 
	if (cntflag == hei * wei){
		system("cls");
		O << "you win!!!\n";
		return 1;	
	}
	return 0;
}

void welcome(){
	system("cls");                   
	O << "\
	\n\
###  #######  ###          #########            ###   \n\
###  ### ###  ###          ###                  ###   \n\
###  ### ###  ###          #########            ###   \n\
### ###   ### ###          #########            ###   \n\
### ###   ### ###          ###                  ###   \n\
 #####     #####           ###                  #########\n\
  ###       ###            #########            #########\n\n\n\n\
";
	O << "\
    #####                   #####                  ###        ###             ###########\n\
  #########               #########               #####      #####            ###########\n\
##############          ##############           ### ###    ### ###           ###\n\
###        ###          ###        ###          ###   ###  ###   ###          ###\n\
###        ##           ###        ###         ###    ###  ###    ###         ###########\n\
###                     ###        ###         ###    ###  ###    ###         ###########\n\
###        ##           ###        ###         ###     ######     ###         ###\n\
###        ###          ###        ###         ###       ##       ###         ###\n\
##############          ##############         ###                ###         ###\n\
  #########               #########            ###                ###         ###########\n\
    #####                   #####              ###                ###         ###########\n\
	";
	sleep(1);
	system("cls");
	O << "\
	\n\
##############                ######    \n\
##############              ##########  \n\
     ####                 ##############\n\
     ####                 ###        ###\n\
     ####                 ###        ###\n\
     ####                 ###        ###\n\
     ####                 ##############\n\
     ####                   ##########  \n\
     ####                     ######    \n\
	";
	sleep(1);
	system("cls");
	O << "\
__      _                      _      ____ _                      __\n\
| |    (_)                    | |    |  _ \ (_)                    | |\n\
| |     _ __________ _ _ __ __| |    | |_) |_ __________ _ _ __ __| |\n\
| |    | |_  /_  / _` | '__/ _` |    |  _ <| |_  /_  / _` | '__/ _` |\n\
| |____| |/ / / / (_| | | | (_| |    | |_) | |/ / / / (_| | | | (_| |\n\
|______|_/___/___\__,__|_|  \__,__|    |____/|_/___/___\_,___|_|  \__,__|\n\n\n\
";
	O << "\
                 ###\n\
                ###\n\
               ###\n\
              ###\n\
             ###\n\
            ##############\n\
            ##############\n\
                      ###\n\
                     ###\n\
                    ###\n\
                   ###\n\
                  ###\n\
	";
	sleep(1);
	system("cls");
	return; 
}

void original_story(int inplace){
	system("cls");
	string storyin = "More than a hundred years ago, \n\
a group of exquisite and lovely lizards lived on the miraculous land of Kashata. \n\
You are one of them. \n\
You have been living here safely for years. \n\
No one is bothering you. \n\
But suddenly one day, \n\
a dazzling yellow light came down from the air. \n\
After the yellow light goes out, \n\
you find yourself trapped in a small room. \n\
It's written on the wall: \n\
    p..play the game...me an..and f...fi..nd..d all th..the clues..s \n\
    t..to escap..ppe heee..re bit... by b..bit.";
	slowprint(storyin);
	O<<"\npress any key to continue...";
	readd = getch();
	system("cls");
	if (inplace == 2){
		plot();
	} else {
		return;
	}
}

void storychoice(){
	system("cls");
	O << "Read the original story or not?(y or n)\n";
	char story_choice;
	cin_story_choice:
	qkhcq();
	I >> story_choice;
	if (story_choice == 'y'){
		original_story(1);
	} else if (story_choice == 'n'){
		O << "OK.\n\n";
	} else {
		O << "wrong input!!!\n\n";
		qkhcq();
		goto cin_story_choice;
	}
}

void game(){
	system("cls");
	for(int i=0;i<1000;i++){
		for(int j=0;j<1000;j++){
			pic[i][j]='\0';
		}
	}
	role = '$';
	clouds = '$';
	int wronglettercnt = 0;
	clock_t start, end;
	clock_t start2, end2;
	start2 = clock();
	char tmp;
	int x = 1, y = 1;
	int clickcnt = 0; 
	cin_wh:
	wei=0;
	hei=0;
	cccoin=0;
	O << "height?	";
	I >> hei;//1
	O << "width?	";
	I >> wei;//2
	O<<"how many coins?	";
	I >> cccoin;//1
	if (cccoin > hei * wei - 1){
		O << "impossible!!!\n";
		goto cin_wh;
	}
	zcnt=(ceil(hei*wei*0.025))+(rand()%2);
	system("cls");
	rdcoin(cccoin, wei, hei);
	rdz(/*zcnt,wei,hei*/);
	for (int i = 1; i <= hei; i++){//all space
		for (int j = 1; j <= wei; j++){
			pic[i][j] = ' ';
		}
	}
	for (int i = 0; i <= wei + 1; i += (wei + 1)){
		for (int j = 0;j <= hei + 1; j++){//y
			pic[j][i] = '|';
		}
	}
	int cnt=0;
	for (int i = 0;i <= hei + 1; i += (hei + 1)){//square frame
		for (int j = 1; j <= wei; j++){
			pic[i][j] = '-';//x 
		}
	}
	int drawcoincnt = 0;
	int drawzcnt=0;
	int cdcnt1 = 0;
	while ((clouds == role) || (clouds == '$') || (role == '$')||(clouds == 'Z')||(role == 'Z')){
		O << "select a role(not'$'or'Z'):";
		I >> role;
		qkhcq();
		O << "select a symbol for clouds(not'$'or'Z'):";
		clouds = getch();
		qkhcq();
		system("cls");
		cdcnt1++;
	}
	for (int i = 1; i <= hei; i++){
		for (int j = 1; j <= wei; j++){
			drawcoincnt++;
			drawzcnt++;
			if (drawcoin_pd(drawcoincnt)){
				pic[i][j] = '$';
				continue;
			}
			if (drawz_pd(/*drawzcnt*/)){
				pic[i][j] = 'Z';
				continue;
			}
			pic[i][j] = clouds;//cloud 
		}
	}
	pic[1][1] = role;
	printt(wei, hei);
	start = clock();
	for(int i=1;i<1000;i++){
		for(int j=1;j<1000;j++){
			picflag[i][j]=0;
		}
	}
	picflag[1][1] = 1;
	while (1){
		getcoin = 0;
		getz=0;
		char cinn = getch();
		if (clickflag) {
			clickcnt++;
		}
		if (cinn == 'w' && x != 1){
			qkhcq();
			if (!picflag[x - 1][y]){//up
				if (pic[x - 1][y] == '$'){
					getcoin = 1;
					coincnt++;
					if (coincnt == cccoin){
						clickflag = 1;
						end = clock();
					}
				}
				if(pic[x-1][y]=='Z'){
					getz=1;
					atakz();
				}
				picflag[x - 1][y] = 1; 
				pic[x - 1][y] = ' ';
				if (pdwin(wei, hei)){
					goto winn; 
				}
			}
			tmp = pic[x][y];
			pic[x][y] = pic[x - 1][y];
			pic[x - 1][y] = tmp;
			x--;
		} else if (cinn == 'a' && y != 1){
			qkhcq();
			if (!picflag[x][y - 1]){//left
				if (pic[x][y - 1] == '$'){
					getcoin = 1;
					coincnt++;
					if (coincnt == 3){
						clickflag = 1;
						end = clock();
					}
				}
				if(pic[x][y-1]=='Z'){
					getz=1;
					atakz();
				}
				picflag[x][y - 1] = 1;
				pic[x][y - 1] = ' ';
				if (pdwin(wei, hei)){
					goto winn; 
				}
			}
			tmp = pic[x][y];
			pic[x][y] = pic[x][y - 1];
			pic[x][y - 1] = tmp;
			y--;
		} else if (cinn == 's' && x != hei){
			qkhcq();
			if (!picflag[x + 1][y]){
				if (pic[x + 1][y] == '$'){
					getcoin = 1;
					coincnt++;
					if (coincnt == 3){
						clickflag = 1;
						end = clock();
					}
				}
				if(pic[x+1][y]=='Z'){
					getz=1;
					atakz();
				}
				picflag[x + 1][y] = 1;
				pic[x + 1][y] = ' ';//down
				if (pdwin(wei,hei)){
					goto winn; 
				}
			}
			tmp = pic[x][y];
			pic[x][y] = pic[x + 1][y];
			pic[x + 1][y] = tmp;
			x++;
		} else if (cinn == 'd' && y != wei){
			qkhcq();
			if (!picflag[x][y + 1]){
				if (pic[x][y + 1] == '$'){
					getcoin = 1;
					coincnt++;
					if (coincnt == 3){
						clickflag = 1;
						end = clock();
					}
				}
				if(pic[x][y+1]=='Z'){
					getz=1;
					atakz();
				}
				picflag[x][y + 1] = 1;
				pic[x][y + 1] = ' ';//right
				if (pdwin(wei,hei)){
					goto winn;
				}
			}
			tmp = pic[x][y];
			pic[x][y] = pic[x][y + 1];
			pic[x][y + 1] = tmp;
			y++;
		} else {
			wronglettercnt++;
		}
		printt(wei, hei);
	}
	winn:
	gamecnt += wei * hei;
	if ((clickcnt / 3 + (end - start) / CLK_TCK / 2) > 35) O << "you got 100 score!!!\n";
	else if ((clickcnt / 3 + (end - start) / CLK_TCK / 2 ) >= 135) O << "you got no score!!!\n";
	else O << "you got " << 135 - (clickcnt / 3 + (end - start) / CLK_TCK / 2) << " score!!!\n";
	if(!gameone) gameone = 1;
	sleep(2);
	if (cdcnt1 > 10){
		system("cls");
		sleep(1);
		O << "you get the colorful egg nub1!\n";
		juqingcd1 = true;
	}
	if (clouds == ' '){
		sleep(2);
		O << "you get the colorful egg nub2!!\n";
		sleep(2);
		juqingcd2 = true;
	}
	if (wronglettercnt >= 100){
		sleep(3);
		O << "you get the colorful egg nub3!!!\n";
		juqingcd3 = true;
		qkhcq();
		I >> s;	
	}
	if (s == "!!!!"){
		char cd4hint[100]="but there is something different...\nthe game isn't over yet...*\n";
		end2 = clock();
		O << "--------------------------------\nProcess exited after " << fixed << setprecision(2) << (double)(end2 - start2) / CLK_TCK << " seconds with return value 0\n请按任意键继续. . .\n";
		sleep(1);
		for (int i = 0; i < 100; i++){
			if (cd4hint[i] != '*'){
				O << cd4hint[i];
				Sleep(100);
			} else {
				break;
			}
		}
		sleep(4);
		system("cls");
		SetColorAndBackground(2, 14);
		O << "\nWOW!!!!YOU GET THE COLORFUL EGG NUB4!!!!\n";
		juqingcd4 = true;
		Sleep(2000);
		yan_hua(20);
	}
	saveout();
	gameorplotorpic();
}

void allstory(){
	system("cls");
	original_story(1);
	cluestory();
	cdstory();
	O<<"\npress any key to continue...";
	readd = getch();
	plot();
}

void cdstory(){
	string storycd1 = "thousands of years ago, \n\
there was a big nuclear explosion occur on Kashata. \n\
all the animals and plants mutate a little. \n\
some died and some become huge or tiny,etc. \n\
all the lizards included your ancestors became very cute. \n\
but, one plant became extremely dangerous...";

	string storycd2 = "there was a person called Medozig,\n\
he was the king of the Kashata before the big nuclear explosion.\n\
but after the explotion,\n\
everything mutated and he wasn't the king at all.\n\
no one listened to him.\n\
but he still wanted everyone listen to him,\n\
so, he...\n";

	string storycd3 = "Medozig found that everyone are now listen to a plant,\n\
because it's dangerous.\n\
it can kill anyone who doesn't listen to it.\n\
Medozig doesn't believe that a plant can be so powerful,\n\
so he decide to eliminate that plant.\n\
first, he asked others and knew that the plant was a Aesculus called Aquamerald.\n\
After mutated it became magical.\n\
it can throw leaves,  Aquamarine and Emerald \n\
that can make you be injured, sick and be poisoning(and listen to it).\n\
because of this, many animals and plants listen to it,\n\
and Medozig was going to destroy it...";

	string storycd4 = "Medozig found the Aesculus Aquamerald to destroy it.\n\
they fought with each other over several days and nights.\n\
finally in one day,\n\
Medozig had obvious advantages.\n\
he was thinking he was going to win,\n\
when Aquamerald suddenly said,\n\
if I can't defeat you,\n\
I'll blew myself up.\n\
then with a piercing explosion,\n\
Aquamerald exploded...";

	string storycd5 = "everyone in the Kashata land all affected by the explosion,\n\
some got sick and some even dead.\n\
but the lizards were very lucky.\n\
after all species sicked or bacome extinct,\n\
they were still alive.\n\
but, the explosion had a great impact on Kashata,\n\
and the dazzling yellow light would light up every other year...";
	if (juqingcd1){
		slowprint(storycd1);
		O << "\n";
		O << "\n";
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	sleep(1);
	if (juqingcd2){
		slowprint(storycd2);
		O << "\n";
		O << "\n";
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	sleep(1);
	if (juqingcd3){
		slowprint(storycd3);
		O << "\n";
		O << "\n";
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	sleep(1);
	if (juqingcd4){
		slowprint(storycd4);
		O << "\n";
		O << "\n";
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	sleep(1);
	if ((juqingcd1) && (juqingcd2) && (juqingcd3) && (juqingcd4)){
		slowprint(storycd5);
		O << "\n";
		O << "\n";
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	O<<"\npress any key to continue...";
	readd = getch();
	plot();
}

void cluestory(){
	string cluestory1 = "a hint:\n\
	play more games to get more plots.\n\
";
	string cluestory2 = "you need to find a way to kill 'Medozig',\n\
so that 'Aquamerald' could calm down.\n\
";
	string cluestory3 = "but, you can't kill Medozig,\n\
because he was too powerful.\n\
";
	string cluestory4 = "so,you need to make Aquamerald believe\n\
that Medozig was die...\n\
";
	if (gamecnt > 0){
		slowprint(cluestory1);
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	if (gamecnt > 100){
		slowprint(cluestory2);
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	if (gamecnt > 1000){
		slowprint(cluestory3);
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	if (gamecnt > 1e7){
		slowprint(cluestory4);
	} else {
		O << "\n\n      ?      ?      ?      \n\n";
	}
	O<<"\npress any key to continue...";
	readd = getch();
	plot();
}

void plot(){
	cin_plotchoi:
	system("cls");
	O << "1. oringinal story\n2. story clues\n3. bonus story\n4. all the story\n5. quit\n\n";
	int plotchoi;
	string plot3pw;
	string plot4pw;
	I >> plotchoi;
	switch (plotchoi) {
		case (1):
			original_story(2);
			break;
		case (2):
			if (gameone){
				O << "bonus story's read password is Erybcae";
				sleep(1);
				system("cls");
				cluestory();
			} else {
				O << "please play a game first!";
				O<<"\npress any key to continue...";
				readd = getch();
				goto cin_plotchoi;
			}
			break;
		case (3):
			O << "read password?\n";
			I >> plot3pw;
			if (plot3pw == "Erybcae"){
				O << "all story's read password is dbGirehjBV";
				sleep(1);
				system("cls");
				cdstory();
			} else {
				O << "wrong password!";
				sleep(1);
				goto cin_plotchoi;
			}
			break;
		case (4):
			O << "read password?\n";	
			I >> plot4pw;
			if (plot4pw == "dbGirehjBV"){
				allstory();
			} else {
				O << "wrong password!";
				sleep(1);
				goto cin_plotchoi;
			}
			break;
		case (5):
			gameorplotorpic();
			break;
		default:
			O << "wrong input!\n\n";
			qkhcq();
			goto cin_plotchoi;
	}
}
void lizpic(){
	system("cls");
	picstart:
	O << "i have 4 pictures,\nplease choose one(nub1~4)(quit -> 5):\n";
	int picchoose;
	cinpicchoose:
	I >> picchoose;
	O << "please wait for a minute.\n";
	sleep(1);
	switch (picchoose){
		case (1):
			system("start https://ts1.cn.mm.bing.net/th/id/R-C.cd9fe0f9de158cc712b249cf6045241d?rik=vjELD9Bk9T%2fLFg&riu=http%3a%2f%2fdpic.tiankong.com%2flh%2fdz%2fQJ6645258546.jpg&ehk=ag2yS04w2iPaL6OhOALnjLoT%2b1UbcNHio5fTRq8%2bZY4%3d&risl=&pid=ImgRaw&r=0");
			system("cls");
			O<<"\npress any key to continue...\n";
			readd = getch();
			break;
		case (2):
			system("start https://ts1.cn.mm.bing.net/th/id/R-C.b12049e51ed103f4631616726f8faa49?rik=wbttnezQBFdJVA&riu=http%3a%2f%2fdpic.tiankong.com%2fxv%2f0i%2fQJ8487519038.jpg&ehk=EHAJuNXRbwgOQOOKsqoJO7M%2bYVAa9TLhTSd59Y5eOUY%3d&risl=&pid=ImgRaw&r=0/");
			system("cls");
			O<<"\npress any key to continue...\n";
			readd = getch();
			break;
		case (3):
			system("start https://ts1.cn.mm.bing.net/th/id/R-C.3c5f87b476ea0d0805e2e0468be7b58e?rik=oaDdS1W4H2M%2bBQ&riu=http%3a%2f%2fpic2.58.com%2fzp_images%2fallimg%2f121016%2f5_121016152703_1.png&ehk=uq6tskorR1kcuGr%2fHWqHsHUa%2bb%2b3D20mtpqRN7jW83E%3d&risl=&pid=ImgRaw&r=0&sres=1&sresct=1/");
			system("cls");
			O<<"\npress any key to continue...\n";
			readd = getch();
			break;
		case (4):
			system("start https://www.thesprucepets.com/thmb/8fnUGp4ir4vRH2TXqBJqEKgPWtU=/2125x1411/filters:fill(auto,1)/Pet-iguana-GettyImages-175673540-58b1ddee5f9b5860463c2188.jpg");
			system("cls");
			O<<"\npress any key to continue...\n";
			readd = getch();
			break;
		case (5):
			O << "ok.";
			gameorplotorpic();
		default:
			O << "wrong input!!!\n\n";
			qkhcq();
			goto cinpicchoose;
	}
	goto picstart;
}
void smallgame1(){
	system("cls");
	int minx, maxx;
	cin_min_max:
	O << "the smaller number?\n";
	I >> minx;
	O << "the bigger number?\n";
	I >> maxx;
	if (minx >= maxx){
		O << "the smaller number should < the bigger number!\n";
		goto cin_min_max;
	}
	int chance_cnt;
	O << "how many chances?\n";
	cin_chance_cnt:
	I >> chance_cnt;
	if (chance_cnt <= 0){
		O << "wrong input!!!\n\n";
		qkhcq();
		goto cin_chance_cnt;
	}
	O << "OK. start!\n";
	sleep(1);
	system("cls");
	int guessnum;
	int realnum = (rand()) % (maxx - minx + 1) + minx;	
	for (; chance_cnt > 0; chance_cnt--){
		O << "please input a number:    ";
		I >> guessnum;
		if (guessnum > realnum){
			O << "TOO BIG!!!      remain time(s):" << chance_cnt - 1 << " time(s)\n\n";
		}
		if (guessnum < realnum){
			O << "TOO SMALL!!!      remain time(s):" << chance_cnt - 1 << " time(s)\n\n";
		}
		if (guessnum == realnum){
			O << "YOU GOT IT!!!";
			O<<"\npress any key to continue...";
			readd = getch();
			smallgame();
		}
	}
	O << "SORRY,YOU LOST!\n";
	O << "the real number is " << realnum;
	O<<"\npress any key to continue...";
	readd = getch();
	smallgame();
}
void smallgame2(){
	srand((unsigned) time(NULL));
	system("cls");
	char guess[6];
	char realnumber[6];
	for(int i=1;i<=5;i++){
		realnumber[i] = (rand() % 10)+'0';
	}
	O << "please input your first guess:";
	for(int i=0;i<5;i++){
		O<<"\n";
		for(int i=1;i<=5;i++){
			guess[i]=getch();
			O<<guess[i]<<" ";
		}
		O<<"\n\n";
		int corectword=0;
		for(int i=1;i<=5;i++){
			if(realnumber[i]==guess[i]){
				SetColorAndBackground(7,2);
				O<<guess[i]<<" ";
				corectword++;
				SetColorAndBackground(7,0);
				if(corectword==5){
					O<<"you win!!!";
					sleep(1);
					yan_hua(10);
					smallgame();
				}
			}else if(guess[i]==realnumber[1] || guess[i]==realnumber[2] || guess[i]==realnumber[3] || guess[i]==realnumber[4] || guess[i]==realnumber[5]){
				SetColorAndBackground(7,6);
				O<<guess[i]<<" ";
				SetColorAndBackground(7,0);
			}else{
				SetColorAndBackground(7,8);
				O<<guess[i]<<" ";
				SetColorAndBackground(7,0);
			}
		}
	}
	O<<"\nyou lost!\nthe real number is: ";
	for(int i=1;i<=5;i++){
		O<<realnumber[i];
	}
	O<<"\npress any key to continue...";
	readd=getch();
	smallgame();
}
void smallgame3(){
	rgb_init();
	srand((unsigned) time(NULL));
	int sm3rd1;
	int sm3rd2;
	int sm3rd3;
	cout<<"difficulty?(1~10)";
	int diff;
	cin>>diff;
	for(int i=1;i<2;i++){
		sm3rd1 = rand() % 256;
		sm3rd2 = rand() % 256;
		sm3rd3 = rand() % 256;
		int f=1;
		int r=(rand()%80)+1;
		for(int a=0;a<9;a++){
			rgb_set(255, 255, 255, sm3rd1, sm3rd2, sm3rd3);
			for(int a1=0;a1<9;a1++){
				if(f==r) rgb_set(255, 255, 255, sm3rd1+11-diff, sm3rd2+11-diff, sm3rd3+11-diff);
				cout<<"  ";
				f++;
				if((f-1)==r) rgb_set(255, 255, 255, sm3rd1, sm3rd2, sm3rd3);
			}
			rgb_set(255, 255, 255, 0, 0, 0);
			cout<<"\n";
		
		}
		cout<<"press any keys to continue...";
		readd=getch();
		smallgame();
	}
}
void smallgame(){
	system("cls");
	O << "1. guess a number\n2. number wordle\n3. color difference\n4. quit\n";
	int smallgamechoice;
	cinsmallgamechoice:
	I >> smallgamechoice;
	switch (smallgamechoice){
		case (1):
			smallgame1();
			break;
		case (2):
			smallgame2();
			break;
		case(3):
			smallgame3();
			break;
		case (4):
			gameorplotorpic();
		default:
			O << "wrong input!!!\n\n";
			qkhcq();
			goto cinsmallgamechoice;
	}
}

void luogulink(){
	system("cls");
	O<<"which link do you want to go to?\n";
	Sleep(500);
	O<<"1. this dgncx's coder\n2. PSCCO's leader\n3. friend1\n4. friend2\n5. friend3\n6. friend4\n7. more\n8. quit\n";
	int luogulinkchoice;
	cinluogulinkchoice:
	I >> luogulinkchoice;
	switch(luogulinkchoice){
		case(1):
			system("start https://www.luogu.com.cn/user/695169");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(2):
			system("start https://www.luogu.com.cn/user/542117");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(3):
			system("start https://www.luogu.com.cn/user/700480");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(4):
			system("start https://www.luogu.com.cn/user/695993");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(5):
			system("start https://www.luogu.com.cn/user/661090");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(6):
			system("start https://www.luogu.com.cn/user/688991");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(7):
			system("start https://www.luogu.com.cn/user/695169#following");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			luogulink();
			break;
		case(8):
			link();
		default:
			O<<"wrong input!!!\n";
			goto cinluogulinkchoice;
	}
}

void mineswlink(){
	system("cls");
	O<<"which link do you want to go to?\n";
	Sleep(500);
	O<<"1. this dgncx's coder\n2. friend 1\n3. friend 2\n4. friend from Ukraine\n5. hostile player1\n6. hostile player2\n7. quit\n";
	int mschoice;
	cinmineswlink:
	I >> mschoice;
	switch(mschoice){
		case(1):
			system("start https://minesweeper.online/player/7998443");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(2):
			system("start https://minesweeper.online/player/7457022");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(3):
			system("start https://minesweeper.online/player/4477997");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(4):
			system("start https://minesweeper.online/player/2966478");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(5):
			system("start https://minesweeper.online/player/3544203");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(6):
			system("start https://minesweeper.online/player/2853300");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			mineswlink();
			break;
		case(7):
			link();
			break;
		default:
			O<<"wrong input!!!";
			qkhcq();
			goto cinmineswlink;
			break;
	}
}

void otherlink(){
	system("cls");
	O<<"which link do you want to go to?\n";
	Sleep(500);
	O<<"1. wtlocker\n2. minesweeper island\n3. pscco website\n4. quit";
	int othchoice;
	cinothlink:
	I >> othchoice;
	switch(othchoice){
		case(1):
			system("start https://wtlocker.eu.org/home");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			otherlink();
			break;
		case(2):
			system("start https://box3.codemao.cn/p/minesweeper-online");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			otherlink();
			break;
		case(3):
			system("start https://g9mee.csb.app/");
			system("cls");
			O<<"press any key to continue...";
			readd=getch();
			otherlink();
			break;
		case(4):
			link();
			break;
		default:
			O<<"wrong input!!!";
			qkhcq();
			goto cinothlink;
			break;
	}
}

void link(){
	system("cls");
	O<<"which kind of links?\n\
1. about luogu\n\
2. about minesweeper\n\
3. others\n\
4. quit\n";
	int linkchoice;
	cinlink:
	qkhcq();
	I >> linkchoice;
	switch(linkchoice){
		case(1):
			luogulink();
			break; 
		case(2):
			mineswlink();
			break;
		case(3):
			otherlink();
			break;
		case(4):
			gameorplotorpic();
			break;
		default:
			O<<"wrong input!!!";
			goto cinlink;
	}
}

void feedback(){
	system("cls");
	O<<"if you find any bugs in this dgncx,\n\
please contact me by rockies_qiqi@163.com.\n\
i'll fix it in about 2 weeks.";
	O<<"\npress any key to continue...";
	readd=getch();
	gameorplotorpic();
}
void gameorplotorpic(){
	system("cls");
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	SetColorAndBackground(15, 0);
	for (int i=1;i<=15;i++){
		O<<"*^";
	} 
	O<<"*\n";
	cout<<"< ";
	switch(sys.wDayOfWeek){
		case(1):
			O<<"Mon";
			break;
		case(2):
			O<<"Tue";
			break;
		case(3):
			O<<"Wed";
			break;
		case(4):
			O<<"Thur";
			break;
		case(5):
			O<<"Fri";
			break;
		case(6):
			O<<"Sat";
			break;
		case(0):
			O<<"Sun";
			break;
	}
	O<<" ";
	switch(sys.wMonth){
		case(1):
			O<<"Jan";
			break;
		case(2):
			O<<"Feb";
			break;
		case(3):
			O<<"Mar";
			break;
		case(4):
			O<<"Apr";
			break;
		case(5):
			O<<"May";
			break;
		case(6):
			O<<"Jun";
			break;
		case(7):
			O<<"Jul";
			break;
		case(8):
			O<<"Aug";
			break;
		case(9):
			O<<"Sep";
			break;
		case(10):
			O<<"Oct";
			break;
		case(11):
			O<<"Nov";
			break;
		case(12):
			O<<"Dec";
			break;
		
	}
	O<<"  ";
	O<<sys.wDay;
	O<<" ";
	O<<sys.wHour;
	O<<":";
	O<<sys.wMinute;
	O<<":";
	O<<sys.wSecond;
	O<<" ";
	O<<sys.wYear;
	O<<" >\n";
	O<<"welcome to c++bizzard    press ctrl+c to exit.\n";
	time_t now1970sec=time(0);
	cout<<"Countdown to the first anniversary of c++bizzard: "<<1687335840-now1970sec<<"\n";
	O << "\n\
1. play the game\n\
2. check the plot\n\
3. see some pictures\n\
4. play some small games\n\
5. some links\n\
6. feedback\n";
	int g_or_p_choi;
	cin_g_or_p_choi:
	qkhcq();
	I >> g_or_p_choi;
	switch (g_or_p_choi){
		case (1):
			game();
			break;
		case (2):
			plot();
			break;
		case (3):
			lizpic();
			break; 
		case (4):
			smallgame();
			break;
		case (5):
			link();
			break;
		case (6):
			feedback();
			break;
		default:
			O << "wrong input!!!\n\n";
			qkhcq();
			goto cin_g_or_p_choi;
	}
}

int main(){
	system("mode con cols=240 lines=80");
	system("cls");
	welcome(); 
	readin();
	storychoice();
	gameorplotorpic();
	return 0;
}
