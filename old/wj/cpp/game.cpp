/**************************
 * Includes
 *
 **************************/

#include <windows.h>
#include <gl/gl.h>


#include <gl/glu.h>
#include <Mmsystem.h> 
#pragma comment(lib,"WinMM.lib")
#include <time.h>

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define HALF_WIDTH (WINDOW_WIDTH/2)
#define HALF_HEIGHT (WINDOW_HEIGHT/2)

#define DEF_TEXT(id, txt) char text##id[] = txt;int text##id##Len = sizeof text##id
#define DEF_OPTION(id, txt) char option##id[] = txt;int option##id##Len = sizeof option##id


/**************************
 * Function Declarations
 *
 **************************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

const double pi = 3.1415926f;

unsigned char img2[58*56*3];
unsigned char thImg1[256*256*3];
unsigned char thImg2[512*512*3];

DEF_TEXT(1, "在遥远的古代，有一个神秘的世界，名为洛谷。");
DEF_TEXT(2, "这里既是人间智慧的试炼场，也是神魔交汇的奇异之地。");
DEF_TEXT(3, "洛谷的创始人，一位被后世尊称为“kkksc03”的智者，他创造了一个充满挑战的在线编程世界，用来选拔和培养那些能够驾驭代码之力的英雄。");
DEF_TEXT(4, "洛谷的世界分为人、神、魔三界。");
DEF_TEXT(5, "在人界是普通编程爱好者的居所，他们在这里学习、交流、挑战难题，努力提升自己的编程技艺。");
DEF_TEXT(6, "在人界中，有几位杰出的英雄人物：");
DEF_TEXT(7, "陈哲：一位天赋异禀的编程天才，被誉为“编程界的璀璨新星”。他渴望挑战更高的境界，进入神界与那些传说中的英雄们并肩作战。");
DEF_TEXT(8, "lin_toto：洛谷开发组，同样是一位编程高手。");
DEF_TEXT(9, "lzn：。");
DEF_TEXT(10, "神界则是那些已经登上编程巅峰，拥有超凡智慧与能力的英雄们的领域。他们被尊称为“算法之神”：");
DEF_TEXT(11, "kkksc03：神界的领袖，一位传奇的编程大师。他的代码精妙绝伦，能够解决任何复杂的问题。他对陈哲寄予厚望，希望他能够成为神界的未来之星。");
DEF_TEXT(12, "yummy：一位美丽聪慧的女神，她的存在为神界增添了一抹亮丽的色彩。");
DEF_TEXT(13, "小粉兔：拜月教的前任守护者，高冷，但法力强大。");
DEF_TEXT(14, "魔界则是那些被编程难题所困扰，心怀怨念与不甘的失败者的归宿。他们被称为“代码魔”：");
DEF_TEXT(15, "暗夜魔君：魔界的统治者，他因为无法突破编程的瓶颈而心生怨念，将怒火发泄在魔界生物身上。他嫉妒神界的英雄们，渴望有一天能够挑战他们。");
DEF_TEXT(16, "罗刹魔君：暗夜魔君的弟弟，魔力未知。");
DEF_TEXT(17, "你来到洛谷，决心要在这里闯出一片天地。");
DEF_TEXT(18, "经过一段繁琐的流程，你终于来到了试炼关卡：P1000。你决定");
DEF_TEXT(19, "终于，你模完了这道题！");
DEF_TEXT(20, "你颓了一下，但还是没有思路……");
DEF_TEXT(21, "你决定");
DEF_TEXT(22, "终于，你做完了这道题！");
DEF_TEXT(23, "你做完了这道题！");
DEF_TEXT(24, "你的rp++了！");
DEF_TEXT(25, "接着，你来到了试炼关卡：P1001。你决定");
DEF_TEXT(26, "经过试炼，你变强了不少");
DEF_TEXT(27, "然而，随着时间的推移，你渐渐感到力不从心。");
DEF_TEXT(28, "你的耳边传来了一道神秘的声音：“年轻人，你是否已经放弃？”");
DEF_TEXT(29, "你抬头望去，只见一位身披长袍、手持法杖的老者kkksc03出现在你的面前。");
DEF_TEXT(30, "kkksc03微笑着看着你，眼中闪烁着智慧的光芒。");
DEF_TEXT(31, "“前辈，我……”你支支吾吾地说不出话来。");
DEF_TEXT(32, "“年轻人，不要灰心。”kkksc03打断了他的话，“这场试炼不仅仅是对你编程技艺的考验，更是对你内心世界的磨炼。当你面临绝境时，是否能够坚守信念、勇往直前？”");
DEF_TEXT(33, "听后恍然大悟。你深吸一口气，重新振作起来。");
DEF_TEXT(34, "kkksc03微笑着看着你。");
DEF_TEXT(35, "他问道：“年轻人，你坚守信念了吗？");
DEF_TEXT(36, "………………");
DEF_TEXT(37, "kkksc03长叹一声。");
DEF_TEXT(38, "“你,失败了……”");
DEF_TEXT(39, "你,失败了……");
DEF_TEXT(40, "此时，kkksc03再次出现在你的面前：“恭喜你年轻人，你已经通过了试炼，成为了真正的英雄。现在你可以进入神界与那些英雄们并肩作战了。”");
DEF_TEXT(41, "你激动地跪在kkksc03面前：“多谢前辈指点迷津！”");
DEF_TEXT(42, "从此以后，你在神界中崭露头角，成为了一位备受尊敬的英雄。");
DEF_TEXT(43, "你用自己的智慧和勇气帮助神界解决了许多难题，赢得了众人的赞誉和尊敬。");
DEF_TEXT(44, "而那些曾经嫉妒和仇恨你的魔界生物也在你的影响下逐渐改变了自己的心态，开始追求更高的境界和更美好的未来。");
DEF_TEXT(45, "而洛谷这个神秘的世界却受到了到lin_toto的打击，下沉至了人间。");
DEF_TEXT(46, "在神界的日子里，你的名声越来越响亮。你的智慧、勇气和无私帮助他人的精神赢得了众人的敬仰。");
DEF_TEXT(47, "然而，就在这个时候，洛谷世界却突然陷入了动荡。");
DEF_TEXT(48, "原来，lin_toto，这位洛谷开发组的成员，起了谋权篡位的心思，决定以自己的方式改变这个世界。");
DEF_TEXT(49, "于是，神界的英雄们纷纷出动，寻找阻止lin_toto的方法。");
DEF_TEXT(50, "你颓了一下");
DEF_TEXT(51, "在寻找线索的过程中，你逐渐发现了lin_toto的阴谋。");
DEF_TEXT(52, "原来，lin_toto想要通过改变洛谷世界的规则，让自己成为这个世界的统治者。");
DEF_TEXT(53, "他利用自己的技术制造了一个强大的程序——黑暗之网，企图控制整个洛谷世界。");
DEF_TEXT(54, "为了阻止lin_toto的阴谋，你决定挑战黑暗之网。");
DEF_TEXT(55, "你来到了黑暗之网的中心——一个被黑暗笼罩的虚拟空间。");
DEF_TEXT(56, "你遇上了 yummy!\n你的rp翻倍了！");
DEF_TEXT(57, "然而，就在这个时候，lin_toto出现了。");
DEF_TEXT(58, "lin_toto的技术高超，他的代码如同利刃般犀利，直逼你的要害！");
DEF_TEXT(59, "就在你即将被lin_toto的攻击逼入绝境时，一道光芒从天而降，kkksc03出现了。");
DEF_TEXT(60, "他身披长袍，手持法杖，眼神中透露出威严和智慧。");
DEF_TEXT(61, "kkksc03看着你，微笑着说：“年轻人，你的勇气和智慧我都看在眼里。现在，是时候展现我们神界的力量了。");
DEF_TEXT(62, "说着，kkksc03轻轻一挥法杖，一道强大的能量波向lin_toto袭去。");
DEF_TEXT(63, "lin_toto虽然强大，但在kkksc03的攻击下也不得不暂时退却。");
DEF_TEXT(64, "你趁机喘了口气，感激地看着kkksc03。");
DEF_TEXT(65, "你回复了 1 rp!");
DEF_TEXT(66, "“多谢前辈相助！”你说道。");
DEF_TEXT(67, "kkksc03点了点头，说道：“年轻人，你的成长我都看在眼里。但这场战斗还需要你自己的努力。我只能暂时为你争取到一些时间。”");
DEF_TEXT(68, "你明白了kkksc03的意思，再次挺起胸膛，向lin_toto发起了攻击！");
DEF_TEXT(69, "kkksc03说道：“yummy会和你并肩作战。”");
DEF_TEXT(70, "在kkksc03的帮助下，你成功地抵挡住了lin_toto的攻击，并逐渐占据了上风。");
DEF_TEXT(71, "经过一场激烈的战斗，你终于找到了黑暗之网的核心程序。");
DEF_TEXT(72, "你凭借着智慧和勇气，成功地破解了它。");
DEF_TEXT(73, "随着一阵光芒闪过，黑暗之网被彻底摧毁，lin_toto的阴谋也被彻底粉碎。");
DEF_TEXT(74, "lin_toto在失败后，愤怒地咆哮着，但已无法改变结果。");
DEF_TEXT(75, "他意识到，自己的力量在神界的英雄们面前显得如此渺小。");
DEF_TEXT(76, "最终，他选择了逃离洛谷世界，寻找新的栖息地。");
DEF_TEXT(77, "战斗结束后，kkksc03再次出现在你的面前。他微笑着看着你，说道：“恭喜你成功阻止了lin_toto的阴谋。你的表现让我非常骄傲。”");
DEF_TEXT(78, "大战结束后，洛谷世界逐渐恢复了平静。");
DEF_TEXT(79, "人界的平衡得以维持，神界的英雄们也得到了应有的赞誉和尊敬。");
DEF_TEXT(80, "你和yummy也因为这次冒险而结下了深厚的友谊。");
DEF_TEXT(81, "在神界的日子里，你和yummy继续并肩作战，帮助神界解决了许多难题。");
DEF_TEXT(82, "你们的智慧和勇气成为了神界的传奇故事。");
DEF_TEXT(83, "而那些曾经嫉妒和仇恨你们的魔界生物也在他们的影响下逐渐改变了自己的心态，开始追求更高的境界和更美好的未来。");
DEF_TEXT(84, "然而，对于你和yummy来说，你们的冒险并没有结束。暗夜魔君在lin_toto的召唤下觉醒了······");

DEF_OPTION(1, "自己做");
DEF_OPTION(2, "看题解");
DEF_OPTION(3, "手模");
DEF_OPTION(4, "小颓一下");
DEF_OPTION(5, "学习做法");
DEF_OPTION(6, "超题解");
DEF_OPTION(7, "读档");
DEF_OPTION(8, "存档");
DEF_OPTION(9, "存档 1");
DEF_OPTION(10, "存档 2");
DEF_OPTION(11, "存档 3");
DEF_OPTION(12, "存档 4");
DEF_OPTION(13, "切题");
DEF_OPTION(14, "大颓一下");

char* textPtr = text1;
int stage, renderFlag, textStage, textIndex, textLine, textLen = sizeof text1,
	choose, subStage, firstChoose, rp = 1, renderEndFlag;
bool stageFlag, allowStage, startFlag, selectFlag, renderOptionsFlag;
std::vector<std::pair<char*,int> >options;

int saveChoose, saveFirstChoose;
bool renderSaveOptionsFlag, saveFlag, saveConfirmFlag;
std::vector<std::pair<char*,int> >saveOptions;

/* STG Flags */
struct Bullet
{
	double x, y, speed, theta, dt;	
};

struct PlayerBullet
{
	double x, y;
	bool flip;
};

struct Enemy
{
	double 	x, y;
	int type, frame, health;
};

double playerPosX,playerPosY;
bool stgFlag,upFlag,downFlag,leftFlag,rightFlag, shiftFlag, shootFlag;
int animationFrame, animationType, lastAnimationType, frameCounter, blinkFlag, endFlag, stgStage;
std::vector<Bullet>bullets;
std::vector<PlayerBullet>playerBullets;
std::vector<Enemy>enemies;
int fps,timer,lastFps;
/*************/

void LoadImage()
{
	std::FILE* file = std::fopen("assets.dat","rb");
	for(int i=0;i<58*56*3;i++)img2[i] = fgetc(file);
	for(int i=0;i<256*256*3;i++)thImg1[i] = fgetc(file);
	for(int i=0;i<512*512*3;i++)thImg2[i] = fgetc(file);
	std::fclose(file); 
}

struct Color{
	double r,g,b;
};

inline double calcPosX(double x)
{
	return (x-HALF_WIDTH)/HALF_WIDTH;
}

inline double calcPosY(double y)
{
	return -(y-HALF_HEIGHT)/HALF_HEIGHT;
}

void drawRect(double x1, double y1, double x2, double y2, Color color, float alpha)
{
//	glPushMatrix ();
    glBegin (GL_QUADS);
    glColor4f (color.r, color.g, color.b, alpha);   glVertex2f (calcPosX(x1), calcPosY(y1));
    glColor4f (color.r, color.g, color.b, alpha);   glVertex2f (calcPosX(x2), calcPosY(y1));
    glColor4f (color.r, color.g, color.b, alpha);   glVertex2f (calcPosX(x2), calcPosY(y2));
    glColor4f (color.r, color.g, color.b, alpha);   glVertex2f (calcPosX(x1), calcPosY(y2));
    glEnd ();
//    glPopMatrix ();
}

inline void drawPixel(int x, int y, int scale, Color color, float alpha)
{
	drawRect(x, y, x + scale, y + scale, color, alpha);
}

void _drawImageA(unsigned char* img, int imgWidth, int imgHeight, int x0, int y0, int x, int y, int width, int height, int scale, double alpha)
{
	glPushMatrix ();
	for(int i=x0;i<width+x0;i++)
	{
		for(int j=y0;j<height+y0;j++)
		{
			Color color;
			color.r = img[j*imgWidth*3+i*3+2]/255.0f;
			color.g = img[j*imgWidth*3+i*3+1]/255.0f;
			color.b = img[j*imgWidth*3+i*3]/255.0f;
			if (color.r == 0.0f && color.g == 0.0f && color.b == 0.0f) continue;
			drawPixel(x+(i-x0)*scale,y+(j-y0)*scale,scale,color,alpha);
		}
	}
	glPopMatrix ();
}

void _drawImageB(unsigned char* img, int imgWidth, int imgHeight, int x0, int y0, int x, int y, int width, int height, int scale, double alpha)
{
	glPushMatrix ();
	for(int i=x0;i<width+x0;i++)
	{
		for(int j=y0;j<height+y0;j++)
		{
			Color color;
			color.r = img[j*imgWidth*3+i*3+2]/255.0f;
			color.g = img[j*imgWidth*3+i*3+1]/255.0f;
			color.b = img[j*imgWidth*3+i*3]/255.0f;
			if (color.r == 0.0f && color.g == 0.0f && color.b == 0.0f) continue;
			drawPixel(x+(j-y0)*scale,y-(i-x0)*scale,scale,color,alpha);
		}
	}
	glPopMatrix ();
}

void _drawImageC(unsigned char* img, int imgWidth, int imgHeight, int x0, int y0, int x, int y, int width, int height, int scale, double alpha)
{
	glPushMatrix ();
	for(int i=x0;i<width+x0;i++)
	{
		for(int j=y0;j<height+y0;j++)
		{
			Color color;
			color.r = img[j*imgWidth*3+i*3+2]/255.0f;
			color.g = img[j*imgWidth*3+i*3+1]/255.0f;
			color.b = img[j*imgWidth*3+i*3]/255.0f;
			if (color.r == 0.0f && color.g == 0.0f && color.b == 0.0f) continue;
			drawPixel(x+(height-j+y0)*scale,y-(i-x0)*scale,scale,color,alpha);
		}
	}
	glPopMatrix ();
}

inline void drawImage(unsigned char* img, int x, int y, int width, int height, int scale, double alpha)
{
	_drawImageA(img, width, height, 0, 0, x, y, width, height, scale, alpha);
}

void drawOptions(HDC hdc)
{
	if (renderOptionsFlag)
	{
		int pos=0;
		for(auto&option:options)
		{
			if (++pos==choose)
			{
				SetTextColor(hdc,RGB(255,255,255));
				tagRECT rect = {80,310+pos*30,600,500};
				DrawText(hdc,option.first,option.second-1,&rect,DT_SINGLELINE);
			}
			else
			{
				SetTextColor(hdc,RGB(180,180,180));
				tagRECT rect = {80,310+pos*30,600,500};
				DrawText(hdc,option.first,option.second-1,&rect,DT_SINGLELINE);
			}
		}
		renderOptionsFlag = false;
	}
}

void drawText(HDC hdc)
{
	SetTextColor(hdc,RGB(255,255,255));
	SetBkColor(hdc,RGB(0,0,0));
	tagRECT rect = {200,340+textLine*30,600,500};
//	tagRECT rect = {0,0,600,500};
	if (textIndex < textLen)
	{
		DrawText(hdc,textPtr,textIndex++,&rect,DT_WORDBREAK);
	}
	else
	{
		if (selectFlag)
		{
			drawOptions(hdc);
		}
		allowStage = true;
	}
}

void drawCircle(int x, int y, int r, Color color)
{
	const int n = 16;
	glPushMatrix ();
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++)
	{
		glColor3f (color.r, color.g, color.b);
		glVertex2f(calcPosX(r*cos(2*pi*i/n)+x),calcPosY(r*sin(2*pi*i/n)+y));
	}
	glEnd();
	glPopMatrix ();
}

void initDisplay()
{
	DEVMODE DevMode;
	EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS,&DevMode);
	DevMode.dmPelsWidth=800;
	DevMode.dmPelsHeight=600;
	ChangeDisplaySettings(&DevMode, CDS_FULLSCREEN);
}

void drawDescription(HDC hdc)
{
	SetTextColor(hdc,RGB(255,255,255));
	SetBkColor(hdc,RGB(0,0,0));
	tagRECT rect = {200,100,600,500};
	DrawText(hdc,TEXT("本游戏来源于 神犇yzc001开发的改编自 一只小菜包 de 少年陈哲之勇闯洛谷神魔试炼场的 very easy 的小game，是由 蒟蒻BigCookie233 制作的魔改版本。\n由于作者能力有限，游戏有许多bug，请见谅\n本游戏中的图片和音乐来源于 东方风神录 and 东方红魔乡，仅供娱乐。\n\n如果要开始游戏，请按 Z 键。"),-1,&rect,DT_WORDBREAK);
}

void renderEnd(HDC hdc)
{
//	const int W=160,H=195;
//	drawImage(thImg2,HALF_WIDTH - W, HALF_HEIGHT - 80, W, H, 2, 1);
	if (renderEndFlag == 3200)
	{
		glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    	glClear (GL_COLOR_BUFFER_BIT);
    	SwapBuffers (hdc);
		tagRECT rect1 = {200,100,600,500};
		DrawText(hdc,TEXT("感谢您的游玩！"),-1,&rect1,DT_WORDBREAK);
		tagRECT rect2 = {200,130,600,500};
		DrawText(hdc,TEXT("文本来源：少年陈哲之勇闯洛谷神魔试炼场\n作者：一只小菜包"),-1,&rect2,DT_WORDBREAK);
		tagRECT rect3 = {200,200,600,500};
		DrawText(hdc,TEXT("图片来源：东方风神录"),-1,&rect3,DT_WORDBREAK);
		tagRECT rect4 = {200,230,600,500};
		DrawText(hdc,TEXT("音乐来源：东方风神录 and 东方红魔乡"),-1,&rect4,DT_WORDBREAK);
	}
	renderEndFlag--;
	if (!renderEndFlag)
	{
		PostQuitMessage(0);
		return;
	}
}

void stgController()
{
	switch(stgStage)
	{
		case 0:
			if (frameCounter == 1600) endFlag = 100;
			break;
		case 1:
			if (frameCounter == 2400) endFlag = 100;
			break;
		case 2:
		case 3:
			if (frameCounter == 3200) endFlag = 100;
			break;
	}
	if (endFlag != -1)
	{
		if (!endFlag)
		{
			textStage++;
			stgFlag = false;
			PlaySound(NULL,NULL,SND_FILENAME | SND_ASYNC);
			return;
		}
		if (bullets.empty() && enemies.empty()) endFlag -= 5;
	}
	if (endFlag == -1 && frameCounter > 100 && frameCounter%400 < 300)
	{
		switch (stgStage)
		{
			case 0:
				if (frameCounter%90 == 0)
				{
					if (frameCounter%180 == 0)
					{
						Enemy enemy1 = {300, 30, 0, 0, 10};
						enemies.push_back(enemy1);
					}
					else
					{
						Enemy enemy2 = {500, 30, 0, 0, 10};
						enemies.push_back(enemy2);
					}
				}
				break;
			case 1:
				if (frameCounter%120 == 0)
				{
					Enemy enemy1 = {300, 30, 0, 0, 10};
					enemies.push_back(enemy1);
					Enemy enemy2 = {500, 30, 0, 0, 10};
					enemies.push_back(enemy2);
				}
				break;
			case 2:
				if (frameCounter%240 == 0)
				{
					Enemy enemy1 = {300, 30, 0, 0, 10};
					enemies.push_back(enemy1);
					Enemy enemy2 = {500, 30, 0, 0, 10};
					enemies.push_back(enemy2);
				}
				break;
			case 3:
				if (frameCounter%160 == 0)
				{
					Enemy enemy1 = {300, 30, 0, 0, 10};
					enemies.push_back(enemy1);
					Enemy enemy2 = {500, 30, 0, 0, 10};
					enemies.push_back(enemy2);
				}
				break;
		}
	}
}

void enemyController(Enemy enemy)
{
	double dx, dy;
	switch(stgStage)
	{
		case 0:
			if (enemy.frame % 60 == 0)
			{
				for (int ang = 0; ang < 360; ang += 60)
				{
					Bullet bullet = {enemy.x, enemy.y, 2, (double)ang, 0};
					bullets.push_back(bullet);
				}
			}
			break;
		case 1:
			if (enemy.frame % 60 == 0)
			{
				dx = enemy.x - playerPosX;
				dy = enemy.x - playerPosY;
				for (int i = 0; i < 360; i += 60)
				{
					Bullet bullet = {enemy.x, enemy.y, 2, acos(dx / sqrt(dx * dx + dy * dy)) * 180 / pi + i, 0};
					bullets.push_back(bullet);
				}
			}
			break;
		case 2:
		case 3:
			if (enemy.frame % 60 == 0)
			{
				dx = enemy.x - playerPosX;
				dy = enemy.x - playerPosY;
				for (int i = 0; i < 360; i += 30)
				{
					Bullet bullet1 = {enemy.x, enemy.y, 3, (double)i, 0.5f};
					bullets.push_back(bullet1);
					Bullet bullet2 = {enemy.x, enemy.y, 3, (double)i, -0.5f};
					bullets.push_back(bullet2);
				}
			}
			break;
	}
}

void renderStg(HDC hdc)
{
    const double moveSpeed = 6.0f;
    const int leftBorder = 200, rightBorder = 600,
				topBorder = 40, bottomBorder = 560;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < playerBullets.size(); i++)
    {
    	PlayerBullet bullet = playerBullets[i];
    	if (bullet.x < leftBorder - 16)
		{
			playerBullets.erase(playerBullets.begin() + i);
			i--;continue;
		}
		if (bullet.x > rightBorder + 16)
		{
			playerBullets.erase(playerBullets.begin() + i);
			i--;continue;
		}
		if (bullet.y < topBorder - 16)
		{
			playerBullets.erase(playerBullets.begin() + i);
			i--;continue;
		}
		if (bullet.y > bottomBorder + 16)
		{
			playerBullets.erase(playerBullets.begin() + i);
			i--;continue;
		}
		playerBullets[i].y -= 15.0f;
		bullet = playerBullets[i];
		if (!bullet.flip)
		{
			if (endFlag != -1)
    		{
    			_drawImageB(thImg1, 256, 256, 0, 176, bullet.x - 8, bullet.y + 32, 63, 15, 1, endFlag / 100.0f);
			}
			else
			{
				_drawImageB(thImg1, 256, 256, 0, 176, bullet.x - 8, bullet.y + 32, 63, 15, 1, 1);
			}
		}
		else
		{
			if (endFlag != -1)
    		{
    			_drawImageC(thImg1, 256, 256, 0, 176, bullet.x - 8, bullet.y + 32, 63, 15, 1, endFlag / 100.0f);
			}
			else
			{
				_drawImageC(thImg1, 256, 256, 0, 176, bullet.x - 8, bullet.y + 32, 63, 15, 1, 1);
			}
		}
	}
	for (int i = 0; i < enemies.size(); i++)
    {
    	Enemy enemy = enemies[i];
    	if (enemy.x < leftBorder - 16)
		{
			enemies.erase(enemies.begin() + i);
			i--;continue;
		}
		if (enemy.x > rightBorder + 16)
		{
			enemies.erase(enemies.begin() + i);
			i--;continue;
		}
		if (enemy.y < topBorder - 16)
		{
			enemies.erase(enemies.begin() + i);
			i--;continue;
		}
		if (enemy.y > bottomBorder + 16)
		{
			enemies.erase(enemies.begin() + i);
			i--;continue;
		}
		for (int j = 0; j < playerBullets.size(); j++)
    	{
    		PlayerBullet bullet = playerBullets[j];
    		double dx = bullet.x - enemy.x;
			double dy = bullet.y - enemy.y;
			if (dx * dx + dy * dy < 30 * 30)
			{
				enemies[i].health--;
				playerBullets.erase(playerBullets.begin() + j);
				j--;
				if (!enemies[i].health)
				{
					enemies.erase(enemies.begin() + i);
					i--;
					goto ENEMY_DIE;
				}
			}
    	}
    	if ((playerPosX - enemy.x) * (playerPosX - enemy.x)
			+ (playerPosY - enemy.y) * (playerPosY - enemy.y) < 20 * 20)
		{
			blinkFlag = 30;
			bullets.clear();
			rp--;
			if (!rp)
			{
				stgFlag = false;
				PlaySound(NULL,NULL,SND_FILENAME | SND_ASYNC);
				textStage = 80;
				textLine = 0;
				renderFlag = 5;
				textPtr = text39;
				textLen = text39Len;
				return;
			}
			break;
		}
		enemies[i].y += 1.0f;
		enemies[i].frame++;
		enemy = enemies[i];
		enemyController(enemy);
		switch(enemy.type)
		{
			case 0:
				_drawImageA(thImg2, 512, 512, 32*((enemy.frame%20)>>2), 0, enemy.x - 16, enemy.y + 16, 31, 31, 1, 1);
				break;
		}
		ENEMY_DIE:;
	}
	double deltaX = 0.0f,deltaY = 0.0f;
    if (upFlag) deltaY -= moveSpeed; 
	if (downFlag) deltaY += moveSpeed; 
	if (leftFlag) deltaX -= moveSpeed; 
	if (rightFlag) deltaX += moveSpeed; 
	double dist;
	if (blinkFlag) deltaX = 0.0f, deltaY = 0.0f, playerPosX = 400, playerPosY = 400;
	if (deltaX * deltaY != 0.0f) dist = std::sqrt(2);
	else dist = 1.0f;
	if (shiftFlag) dist *= 2.0f;
	deltaX /= dist; deltaY /= dist;
	playerPosX += deltaX;
	playerPosY += deltaY;
	if (playerPosX < leftBorder + 16) playerPosX = leftBorder + 16;
	if (playerPosX > rightBorder - 16) playerPosX = rightBorder - 16;
	if (playerPosY < topBorder + 24) playerPosY = topBorder + 24;
	if (playerPosY > bottomBorder - 24) playerPosY = bottomBorder - 24;
    Color black = {0.0f, 0.0f, 0.0f};
    Color red = {1.0f, 0.0f, 0.0f};
    Color white = {1.0f, 1.0f, 1.0f};
    animationType = 0;
    if(deltaX < 0) animationType = 1;
    if(deltaX > 0) animationType = 2;
	if (lastAnimationType != animationType)
	{
		if (lastAnimationType&&!animationType)
		{
			if (animationFrame > 11)
			{
				animationFrame = 11;
			}
			else if (animationFrame > 1)
			{
				animationFrame--;
			}
			else
			{
				lastAnimationType = animationType;
			}
		}
		else
		{
			animationFrame = 0;
			lastAnimationType = animationType;
		}
	}
	else
	{
		animationFrame++;
		if (animationType)
		{
			if (animationFrame > 31) animationFrame = 12;
		}
		else
		{
			if (animationFrame > 31) animationFrame = 0;
		}
	}
    if (!(blinkFlag&1))
    {
    	if (endFlag != -1)
    	{
    		_drawImageA(thImg1, 256, 256, (animationFrame>>2)*32, lastAnimationType*48, playerPosX - 16, playerPosY - 24, 31, 47, 1, endFlag / 100.0f);
		}
		else
		{
			_drawImageA(thImg1, 256, 256, (animationFrame>>2)*32, lastAnimationType*48, playerPosX - 16, playerPosY - 24, 31, 47, 1, 1);
		}
	}
    if (blinkFlag) blinkFlag--;
	if (shiftFlag)
	{
		drawCircle(playerPosX, playerPosY, 7, red); 
		drawCircle(playerPosX, playerPosY, 4, white); 
	}
	stgController();
	if (shootFlag && frameCounter % 5 == 0)
	{
		PlayerBullet bullet1 = {playerPosX - 12, playerPosY, true};
		playerBullets.push_back(bullet1);
		PlayerBullet bullet2 = {playerPosX + 12, playerPosY, false};
		playerBullets.push_back(bullet2);
	}
	if (blinkFlag) bullets.clear();
    for (int i = 0; i < bullets.size(); i++)
    {
    	Bullet bullet = bullets[i];
    	if (bullet.x < leftBorder - 16)
		{
			bullets.erase(bullets.begin() + i);
			i--;continue;
		}
		if (bullet.x > rightBorder + 16)
		{
			bullets.erase(bullets.begin() + i);
			i--;continue;
		}
		if (bullet.y < topBorder - 16)
		{
			bullets.erase(bullets.begin() + i);
			i--;continue;
		}
		if (bullet.y > bottomBorder + 16)
		{
			bullets.erase(bullets.begin() + i);
			i--;continue;
		}
		bullets[i].theta += bullets[i].dt;
		bullets[i].x += cos(bullets[i].theta / 180 * pi) * bullets[i].speed;
		bullets[i].y -= sin(bullets[i].theta / 180 * pi) * bullets[i].speed;
		bullets[i].speed += 0.03f;
		bullet = bullets[i];
		drawCircle(bullet.x, bullet.y, 10, red);
		drawCircle(bullet.x, bullet.y, 7, white);
		double dx = bullet.x - playerPosX;
		double dy = bullet.y - playerPosY;
		if (dx * dx + dy * dy < 10 * 10)
		{
			blinkFlag = 60;
			bullets.clear();
			rp--;
			if (!rp)
			{
				stgFlag = false;
				PlaySound(NULL,NULL,SND_FILENAME | SND_ASYNC);
				textStage = 32;
				subStage = 5;
				firstChoose = 2;
				choose = 3;
				textLine = 0;
				textPtr = text39;
				textLen = text39Len;
				textIndex = 0;
				return;
			}
			break;
		}
	}
	frameCounter++;
	drawRect(0, 0, WINDOW_WIDTH, topBorder, black, 1);
    drawRect(0, bottomBorder, WINDOW_WIDTH, WINDOW_HEIGHT, black, 1);
    drawRect(0, 0, leftBorder, WINDOW_HEIGHT, black, 1);
    drawRect(rightBorder, 0, WINDOW_WIDTH, WINDOW_HEIGHT, black, 1);
	SwapBuffers(hdc);
}

void render(HDC hdc)
{
	/* OpenGL animation code goes here */
	if (renderFlag)
	{
		renderFlag-=5;
		glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    	glClear (GL_COLOR_BUFFER_BIT);
    	int W,H;
    	switch(stage)
    	{
    		case 1:
    			W=58,H=56;
    			drawImage(img2,
					HALF_WIDTH-W*2,
					HALF_HEIGHT-H*4,
				W,H,4,(100-renderFlag)/100.0f);
    			break;
    		case 2:
    			W=58,H=56;
    			drawImage(img2,
					HALF_WIDTH-W*2,
					HALF_HEIGHT-H*4,
				W,H,4,renderFlag/100.0f);
    			break;
		}
    	SwapBuffers (hdc);
	}
}

void startStg()
{
	frameCounter = 0;
	stgFlag = true;
	endFlag = -1;
	upFlag = false;
	downFlag = false;
	leftFlag = false;
	rightFlag = false;
	shootFlag = false;
	blinkFlag = 60;
	enemies.clear();
	bullets.clear();
	playerBullets.clear();
}

void loadSave(int id)
{
	char s[] = "save0.dat";
	s[4] = id + '0';
	std::FILE* file = std::fopen(s, "r");
	std::fscanf(file, "%d %d %d %d %d", &stage, &textStage, &subStage, &stgStage, &rp);
	std::fclose(file);
}

void dumpSave(int id)
{
	char s[] = "save0.dat";
	s[4] = id + '0';
	std::FILE* file = std::fopen(s, "w");
	std::fprintf(file, "%d %d %d %d %d", stage, --textStage, subStage, stgStage, rp);
	std::fclose(file);
}

void renderSaveOptions(HDC hdc)
{
	if (renderSaveOptionsFlag)
	{
		if (saveConfirmFlag)
		{
			if (saveFirstChoose == 0)
			{
				saveFirstChoose = saveChoose;
				saveConfirmFlag = false;
			}
			else
			{
				if (saveFirstChoose == 1) loadSave(saveChoose);
				else dumpSave(saveChoose);
				saveFirstChoose = saveChoose;
				saveConfirmFlag = false;
				saveFlag = false;
				renderFlag = 5;
				textLine = 0;
				stageFlag = true;
			}
		}
		if (saveFirstChoose == 0)
		{
			saveOptions.clear();
			saveOptions.push_back(std::make_pair(option7, option7Len));
			saveOptions.push_back(std::make_pair(option8, option8Len));
		}
		else
		{
			saveOptions.clear();
			saveOptions.push_back(std::make_pair(option9, option9Len));
			saveOptions.push_back(std::make_pair(option10, option10Len));
			saveOptions.push_back(std::make_pair(option11, option11Len));
			saveOptions.push_back(std::make_pair(option12, option12Len));
		}
		int pos=0;
		for(auto&option:saveOptions)
		{
			if (++pos==saveChoose)
			{
				SetTextColor(hdc,RGB(255,255,255));
				tagRECT rect = {630,310+pos*30,800,500};
				DrawText(hdc,option.first,option.second-1,&rect,DT_SINGLELINE);
			}
			else
			{
				SetTextColor(hdc,RGB(180,180,180));
				tagRECT rect = {630,310+pos*30,800,500};
				DrawText(hdc,option.first,option.second-1,&rect,DT_SINGLELINE);
			}
		}
		renderSaveOptionsFlag = false;
	}
}

void controller(HDC hdc)
{
	if (GetTickCount() - timer < 1000.0f / 60 * fps) return;
	if(renderEndFlag)
	{
		renderEnd(hdc);
		goto CALC_FPS;
	}
	if(stageFlag)
	{
		stageFlag = false;
		allowStage = false;
		switch(textStage)
		{
			case 0:
				playerPosX = 400;
				playerPosY = 400;
				textLine++;
				textPtr = text2;
				textLen = text2Len;
				textIndex = 0;
				textStage++;
				break;
			case 1:
				textLine++;
				textPtr = text3;
				textLen = text3Len;
				textIndex = 0;
				textStage++;
				break;
			case 2:
				renderFlag = 5;
				textLine = 0;
				textPtr = text4;
				textLen = text4Len;
				textIndex = 0;
				textStage++;
				break;
			case 3:
				textLine++;
				textPtr = text5;
				textLen = text5Len;
				textIndex = 0;
				textStage++;
				break;
			case 4:
				renderFlag = 5;
				textLine = 0;
				textPtr = text6;
				textLen = text6Len;
				textIndex = 0;
				textStage++;
				break;
			case 5:
				textLine++;
				textPtr = text7;
				textLen = text7Len;
				textIndex = 0;
				textStage++;
				break;
			case 6:
				textLine+=2;
				textPtr = text8;
				textLen = text8Len;
				textIndex = 0;
				textStage++;
				break;
			case 7:
				textLine++;
				textPtr = text9;
				textLen = text9Len;
				textIndex = 0;
				textStage++;
				break;
			case 8:
				renderFlag = 5;
				textLine = 0;
				textPtr = text10;
				textLen = text10Len;
				textIndex = 0;
				textStage++;
				break;
			case 9:
				textLine+=2;
				textPtr = text11;
				textLen = text11Len;
				textIndex = 0;
				textStage++;
				break;
			case 10:
				textLine+=2;
				textPtr = text12;
				textLen = text12Len;
				textIndex = 0;
				textStage++;
				break;
			case 11:
				renderFlag = 5;
				textLine = 0;
				textPtr = text13;
				textLen = text13Len;
				textIndex = 0;
				textStage++;
				break;
			case 12:
				renderFlag = 5;
				textLine = 0;
				textPtr = text14;
				textLen = text14Len;
				textIndex = 0;
				textStage++;
				break;
			case 13:
				textLine+=2;
				textPtr = text15;
				textLen = text15Len;
				textIndex = 0;
				textStage++;
				break;
			case 14:
				textLine+=2;
				textPtr = text16;
				textLen = text16Len;
				textIndex = 0;
				textStage++;
				break;
			case 15:
				renderFlag = 100;
				textLine = 0;
				textPtr = text17;
				textLen = text17Len;
				textIndex = 0;
				textStage++;
				break;
			case 16:
				subStage = 0; 
				renderFlag = 100;
				stage++;
				textLine = 0;
				textPtr = text18;
				textLen = text18Len;
				textIndex = 0;
				selectFlag = true;
				renderOptionsFlag = true;
				choose = 1;
				options.push_back(std::make_pair(option1,option1Len));
				options.push_back(std::make_pair(option2,option2Len));
				textStage++;
				break;
			case 17:
				textLine = 0;
				textPtr = text21;
				textLen = text21Len;
				textIndex = 0;
				switch(subStage)
				{
					case 0:
						subStage++;
						renderFlag = 5;
						options.clear();
						renderOptionsFlag = true;
						firstChoose = choose;
						switch(choose)
						{
							case 1:
								options.push_back(std::make_pair(option3,option3Len));
								options.push_back(std::make_pair(option4,option4Len));
								break;
							case 2:
								options.push_back(std::make_pair(option5,option5Len));
								options.push_back(std::make_pair(option4,option4Len));
								options.push_back(std::make_pair(option6,option6Len));
								break;
						}
						choose = 1;
						break;
					case 1:
						switch(firstChoose)
						{
							case 1:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text19;
										textLen = text19Len;
										textIndex = 0;
										startStg();
										PlaySound(TEXT("th10_05.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
								}
								break;
							case 2:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text22;
										textLen = text22Len;
										textIndex = 0;
										startStg();
										PlaySound(TEXT("th10_05.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
									case 3:
										renderFlag = 5;
										textLine = 0;
										textPtr = text23;
										textLen = text23Len;
										textIndex = 0;
										textStage++;
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
								}
								break;
						}
						break;
				}
				break;
			case 18:
				renderFlag = 100;
				stage++;
				textLine = 0;
				textPtr = text24;
				textLen = text24Len;
				textIndex = 0;
				rp++;
				PlaySound(TEXT("se_extend.wav"),NULL,SND_FILENAME | SND_ASYNC);
				textStage++;
				break;
			case 19:
				renderFlag = 5;
				textLine = 0;
				textPtr = text25;
				textLen = text25Len;
				textIndex = 0;
				selectFlag = true;
				renderOptionsFlag = true;
				choose = 1;
				subStage = 0;
				options.clear();
				options.push_back(std::make_pair(option1,option1Len));
				options.push_back(std::make_pair(option2,option2Len));
				textStage++;
				break;
			case 20:
				textLine = 0;
				textPtr = text21;
				textLen = text21Len;
				textIndex = 0;
				switch(subStage)
				{
					case 0:
						subStage++;
						renderFlag = 5;
						options.clear();
						renderOptionsFlag = true;
						firstChoose = choose;
						switch(choose)
						{
							case 1:
								options.push_back(std::make_pair(option3,option3Len));
								options.push_back(std::make_pair(option4,option4Len));
								break;
							case 2:
								options.push_back(std::make_pair(option5,option5Len));
								options.push_back(std::make_pair(option4,option4Len));
								options.push_back(std::make_pair(option6,option6Len));
								break;
						}
						choose = 1;
						break;
					case 1:
						switch(firstChoose)
						{
							case 1:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text19;
										textLen = text19Len;
										textIndex = 0;
										startStg();
										PlaySound(TEXT("th10_07.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
								}
								break;
							case 2:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text22;
										textLen = text22Len;
										textIndex = 0;
										startStg();
										PlaySound(TEXT("th10_07.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
									case 3:
										renderFlag = 5;
										textLine = 0;
										textPtr = text23;
										textLen = text23Len;
										textIndex = 0;
										textStage++;
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
								}
								break;
						}
						break;
				}
				break;
			case 21:
				renderFlag = 5;
				textLine = 0;
				textPtr = text24;
				textLen = text24Len;
				textIndex = 0;
				rp++;
				PlaySound(TEXT("se_extend.wav"),NULL,SND_FILENAME | SND_ASYNC);
				textStage++;
				break;
			case 22:
				renderFlag = 5;
				textLine = 0;
				textPtr = text26;
				textLen = text26Len;
				textIndex = 0;
				textStage++;
				break;
			case 23:
				textLine++;
				textPtr = text27;
				textLen = text27Len;
				textIndex = 0;
				textStage++;
				break;
			case 24:
				renderFlag = 5;
				textLine = 0;
				textPtr = text28;
				textLen = text28Len;
				textIndex = 0;
				textStage++;
				break;
			case 25:
				textLine+=2;
				textPtr = text29;
				textLen = text29Len;
				textIndex = 0;
				textStage++;
				break;
			case 26:
				textLine+=2;
				textPtr = text30;
				textLen = text30Len;
				textIndex = 0;
				textStage++;
				break;
			case 27:
				renderFlag = 5;
				textLine = 0;
				textPtr = text31;
				textLen = text31Len;
				textIndex = 0;
				textStage++;
				break;
			case 28:
				textLine++;
				textPtr = text32;
				textLen = text32Len;
				textIndex = 0;
				textStage++;
				break;
			case 29:
				textLine+=2;
				textPtr = text33;
				textLen = text33Len;
				textIndex = 0;
				textStage++;
				break;
			case 30:
				renderFlag = 5;
				textLine = 0;
				textPtr = text21;
				textLen = text21Len;
				textIndex = 0;
				textStage++;
				selectFlag = true;
				renderOptionsFlag = true;
				choose = 1;
				subStage = 0;
				options.clear();
				options.push_back(std::make_pair(option1,option1Len));
				options.push_back(std::make_pair(option2,option2Len));
				break;
			case 31:
				textLine = 0;
				textPtr = text21;
				textLen = text21Len;
				textIndex = 0;
				switch(subStage)
				{
					case 0:
						subStage++;
						renderFlag = 5;
						options.clear();
						renderOptionsFlag = true;
						firstChoose = choose;
						switch(choose)
						{
							case 1:
								options.push_back(std::make_pair(option3,option3Len));
								options.push_back(std::make_pair(option4,option4Len));
								break;
							case 2:
								options.push_back(std::make_pair(option5,option5Len));
								options.push_back(std::make_pair(option4,option4Len));
								options.push_back(std::make_pair(option6,option6Len));
								break;
						}
						choose = 1;
						break;
					case 1:
						switch(firstChoose)
						{
							case 1:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text19;
										textLen = text19Len;
										textIndex = 0;
										subStage = 0;
										stgStage++;
										startStg();
										PlaySound(TEXT("th10_06.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
								}
								break;
							case 2:
								switch(choose)
								{
									case 1:
										renderFlag = 5;
										textLine = 0;
										textPtr = text22;
										textLen = text22Len;
										textIndex = 0;
										subStage = 0;
										stgStage++;
										startStg();
										PlaySound(TEXT("th10_06.wav"),NULL,SND_FILENAME | SND_ASYNC);
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
									case 2:
										renderFlag = 5;
										textLine = 0;
										textPtr = text20;
										textLen = text20Len;
										textIndex = 0;
										subStage = 0;
										choose = 1;
										options.clear();
										options.push_back(std::make_pair(option1,option1Len));
										options.push_back(std::make_pair(option2,option2Len));
										renderOptionsFlag = true;
										break;
									case 3:
										renderFlag = 5;
										textLine = 0;
										textPtr = text23;
										textLen = text23Len;
										textIndex = 0;
										subStage = 0;
										textStage++;
										selectFlag = false; 
										renderOptionsFlag = false;
										break;
								}
								break;
						}
						break;
				}
				break;
			case 32:
				if (firstChoose == 2 && choose == 3)
				{
					switch(subStage)
					{
						case 0:
							renderFlag = 5;
							textLine = 0;
							textPtr = text34;
							textLen = text34Len;
							textIndex = 0;
							break;
						case 1:
							textLine++;
							textPtr = text35;
							textLen = text35Len;
							textIndex = 0;
							break;
						case 2:
							textLine++;
							textPtr = text36;
							textLen = text36Len;
							textIndex = 0;
							break;
						case 3:
							textLine++;
							textPtr = text37;
							textLen = text37Len;
							textIndex = 0;
							break;
						case 4:
							textLine++;
							textPtr = text38;
							textLen = text38Len;
							textIndex = 0;
							break;
						case 5:
							PlaySound(TEXT("th06_17.wav"),NULL,SND_FILENAME | SND_ASYNC);
							renderEndFlag = 3200;
							return;
					}
					subStage++;
				}
				else
				{
					renderFlag = 5;
					textLine = 0;
					textPtr = text24;
					textLen = text24Len;
					textIndex = 0;
					rp++;
					PlaySound(TEXT("se_extend.wav"),NULL,SND_FILENAME | SND_ASYNC);
					textStage++;
				}
				break;
			case 33:
				renderFlag = 5;
				textLine = 0;
				textPtr = text40;
				textLen = text40Len;
				textIndex = 0;
				textStage++;
				break;
			case 34:
				textLine+=2;
				textPtr = text41;
				textLen = text41Len;
				textIndex = 0;
				textStage++;
				break;
			case 35:
				renderFlag = 5;
				textLine = 0;
				textPtr = text42;
				textLen = text42Len;
				textIndex = 0;
				textStage++;
				break;
			case 36:
				textLine+=2;
				textPtr = text43;
				textLen = text43Len;
				textIndex = 0;
				textStage++;
				break;
			case 37:
				renderFlag = 5;
				textLine = 0;
				textPtr = text44;
				textLen = text44Len;
				textIndex = 0;
				textStage++;
				break;
			case 38:
				textLine+=2;
				textPtr = text45;
				textLen = text45Len;
				textIndex = 0;
				textStage++;
				break;
			case 39:
				renderFlag = 5;
				textLine = 0;
				textPtr = text46;
				textLen = text46Len;
				textIndex = 0;
				textStage++;
				break;
			case 40:
				textLine+=2;
				textPtr = text47;
				textLen = text47Len;
				textIndex = 0;
				textStage++;
				break;
			case 41:
				textLine++;
				textPtr = text48;
				textLen = text48Len;
				textIndex = 0;
				textStage++;
				break;
			case 42:
				renderFlag = 5;
				textLine = 0;
				textPtr = text49;
				textLen = text49Len;
				textIndex = 0;
				textStage++;
				break;
			case 43:
				renderFlag = 5;
				options.clear();
				renderOptionsFlag = true;
				textLine = 0;
				textPtr = text21;
				textLen = text21Len;
				textIndex = 0;
				options.push_back(std::make_pair(option13,option13Len));
				options.push_back(std::make_pair(option14,option14Len));
				textStage++;
				subStage = 0;
				choose = 1;
				selectFlag = true; 
				renderOptionsFlag = true;
				break;
			case 44:
				switch(choose)
				{
					case 1:
						textLine = 0;
						textPtr = text22;
						textLen = text22Len;
						textIndex = 0;
						subStage = 0;
						stgStage = 0;
						startStg();
						PlaySound(TEXT("th06_05.wav"),NULL,SND_FILENAME | SND_ASYNC);
						selectFlag = false; 
						renderOptionsFlag = false;
						break;
					case 2:
						stageFlag = true;
						selectFlag = false; 
						renderOptionsFlag = false;
						textStage++;
						break;
				}
				break;
			case 45:
				switch (choose)
				{
					case 1:
						renderFlag = 5;
						textLine = 0;
						textPtr = text24;
						textLen = text24Len;
						textIndex = 0;
						PlaySound(TEXT("se_extend.wav"),NULL,SND_FILENAME | SND_ASYNC);
						textStage++;
						rp++;
						break;
					case 2:
						renderFlag = 5;
						textLine = 0;
						textPtr = text50;
						textLen = text50Len;
						textIndex = 0;
						textStage++;
						break;
				}
				break;
			case 46:
				renderFlag = 5;
				textLine = 0;
				textPtr = text51;
				textLen = text51Len;
				textIndex = 0;
				textStage++;
				break;
			case 47:
				textLine++;
				textPtr = text52;
				textLen = text52Len;
				textIndex = 0;
				textStage++;
				break;
			case 48:
				textLine+=2;
				textPtr = text53;
				textLen = text53Len;
				textIndex = 0;
				textStage++;
				break;
			case 49:
				renderFlag = 5;
				textLine = 0;
				textPtr = text54;
				textLen = text54Len;
				textIndex = 0;
				textStage++;
				break;
			case 50:
				textLine++;
				textPtr = text55;
				textLen = text55Len;
				textIndex = 0;
				textStage++;
				break;
			case 51:
				if (choose == 1)
				{
					renderFlag = 5;
					textLine = 0;
					textPtr = text56;
					textLen = text56Len;
					rp *= 2;
					textIndex = 0;
				} else stageFlag = true;
				textStage++;
				break;
			case 52:
				textLine = 0;
				textPtr = text57;
				textLen = text57Len;
				textIndex = 0;
				subStage = 0;
				stgStage = 1;
				startStg();
				PlaySound(TEXT("th10_03.wav"),NULL,SND_FILENAME | SND_ASYNC);
				break;
			case 53:
				textLine++;
				textPtr = text58;
				textLen = text58Len;
				textIndex = 0;
				textStage++;
				break;
			case 54:
				textLine = 0;
				textPtr = text59;
				textLen = text59Len;
				textIndex = 0;
				subStage = 0;
				stgStage = 2;
				startStg();
				PlaySound(TEXT("th10_04.wav"),NULL,SND_FILENAME | SND_ASYNC);
				break;
			case 55:
				textLine+=2;
				textPtr = text60;
				textLen = text60Len;
				textIndex = 0;
				textStage++;
				break;
			case 56:
				textLine++;
				textPtr = text61;
				textLen = text61Len;
				textIndex = 0;
				textStage++;
				break;
			case 57:
				renderFlag = 5;
				textLine = 0;
				textPtr = text62;
				textLen = text62Len;
				textIndex = 0;
				textStage++;
				break;
			case 58:
				textLine+=2;
				textPtr = text63;
				textLen = text63Len;
				textIndex = 0;
				textStage++;
				break;
			case 59:
				textLine++;
				textPtr = text64;
				textLen = text64Len;
				textIndex = 0;
				textStage++;
				break;
			case 60:
				renderFlag = 5;
				textLine = 0;
				textPtr = text65;
				textLen = text65Len;
				textIndex = 0;
				rp++;
				PlaySound(TEXT("se_extend.wav"),NULL,SND_FILENAME | SND_ASYNC);
				textStage++;
				break;
			case 61:
				renderFlag = 5;
				textLine = 0;
				textPtr = text66;
				textLen = text66Len;
				textIndex = 0;
				textStage++;
				break;
			case 62:
				textLine++;
				textPtr = text67;
				textLen = text67Len;
				textIndex = 0;
				textStage++;
				break;
			case 63:
				renderFlag = 5;
				textLine = 0;
				textPtr = text68;
				textLen = text68Len;
				textIndex = 0;
				textStage++;
				break;
			case 64:
				textLine+=2;
				textPtr = text69;
				textLen = text69Len;
				textIndex = 0;
				textStage++;
				break;
			case 65:
				textLine = 0;
				textPtr = text70;
				textLen = text70Len;
				textIndex = 0;
				subStage = 0;
				stgStage = 3;
				startStg();
				PlaySound(TEXT("th10_10.wav"),NULL,SND_FILENAME | SND_ASYNC);
				break;
			case 66:
				textLine+=2;
				textPtr = text71;
				textLen = text71Len;
				textIndex = 0;
				textStage++;
				break;
			case 67:
				textLine++;
				textPtr = text72;
				textLen = text72Len;
				textIndex = 0;
				textStage++;
				break;
			case 68:
				renderFlag = 5;
				textLine = 0;
				textPtr = text73;
				textLen = text73Len;
				textIndex = 0;
				textStage++;
				break;
			case 69:
				textLine+=2;
				textPtr = text74;
				textLen = text74Len;
				textIndex = 0;
				textStage++;
				break;
			case 70:
				textLine++;
				textPtr = text75;
				textLen = text75Len;
				textIndex = 0;
				textStage++;
				break;
			case 71:
				renderFlag = 5;
				textLine = 0;
				textPtr = text76;
				textLen = text76Len;
				textIndex = 0;
				textStage++;
				break;
			case 72:
				textLine++;
				textPtr = text77;
				textLen = text77Len;
				textIndex = 0;
				textStage++;
				break;
			case 73:
				renderFlag = 5;
				textLine = 0;
				textPtr = text78;
				textLen = text78Len;
				textIndex = 0;
				textStage++;
				break;
			case 74:
				textLine++;
				textPtr = text79;
				textLen = text79Len;
				textIndex = 0;
				textStage++;
				break;
			case 75:
				textLine+=2;
				textPtr = text80;
				textLen = text80Len;
				textIndex = 0;
				textStage++;
				break;
			case 76:
				renderFlag = 5;
				textLine = 0;
				textPtr = text81;
				textLen = text81Len;
				textIndex = 0;
				textStage++;
				break;
			case 77:
				textLine+=2;
				textPtr = text82;
				textLen = text82Len;
				textIndex = 0;
				textStage++;
				break;
			case 78:
				renderFlag = 5;
				textLine = 0;
				textPtr = text83;
				textLen = text83Len;
				textIndex = 0;
				textStage++;
				break;
			case 79:
				textLine+=2;
				textPtr = text84;
				textLen = text84Len;
				textIndex = 0;
				textStage++;
				break;
			case 80:
				PlaySound(TEXT("th06_17.wav"),NULL,SND_FILENAME | SND_ASYNC);
				renderEndFlag = 3200;
				return;
		}
	}
	if (startFlag)
	{
		if (stgFlag)
		{
			renderStg(hdc);
		}
		else
		{
			render(hdc);
			if(!renderFlag)
			{
				if (renderSaveOptionsFlag) renderSaveOptions(hdc);
				drawText(hdc);
			}
		}
	}
	CALC_FPS:
	char fpss[2];
	fpss[1] = lastFps%10+'0';
	fpss[0] = (lastFps/10)%10+'0';
	tagRECT rect1 = {0,0,600,500};
	DrawText(hdc,fpss,sizeof fpss,&rect1,DT_WORDBREAK);
	if (GetTickCount() - timer > 1000)
	{
		timer = GetTickCount();
		lastFps = fps;
		fps = -1;
	}
	fps++;
}


/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;

    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "OpenGLGame";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "OpenGLGame", "颓废的游戏", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
//	  WS_POPUP | WS_VISIBLE,
      0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);
    
	drawDescription(hDC);
//	initDisplay(); 
	LoadImage();

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {   
        	controller(hDC);
        	Sleep(1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
        	saveFlag = !saveFlag;
        	saveChoose = 1;
        	saveFirstChoose = 0; 
            renderSaveOptionsFlag = saveFlag;
            if (!saveFlag)
            {
            	renderFlag = 5;
				textStage--;
				textLine = 0;
			}
            return 0;
        case 0x5a:
        	if (!startFlag)
			{
				startFlag = true;
				renderFlag = 5; 
			} else
			if(saveFlag)
        	{
        		renderSaveOptionsFlag = true;
        		saveConfirmFlag = true;
			}
        	else if(allowStage)
        		stageFlag = true;
			if (stgFlag) shootFlag = true;
        	break;
        case VK_DOWN:
        	if(saveFlag)
        	{
				if(saveChoose < saveOptions.size())
        		{
        			renderSaveOptionsFlag = true;
        			saveChoose++;
				}
			} else
        	if(selectFlag)
        	{
        		if(choose < options.size())
        		{
        			renderOptionsFlag = true;
        			choose++;
				}
			}
			if(stgFlag) downFlag = true;
        	break;
        case VK_UP:
        	if(saveFlag)
        	{
				if(saveChoose > 1)
        		{
        			renderSaveOptionsFlag = true;
        			saveChoose--;
				}
			} else
        	if(selectFlag)
        	{
        		if(choose > 1)
        		{
        			renderOptionsFlag = true;
        			choose--;
				}
			}
			if(stgFlag) upFlag = true;
        	break;
        case VK_LEFT:
        	if(stgFlag) leftFlag = true;
        	break;
		case VK_RIGHT:
			if(stgFlag) rightFlag = true;
        	break;
        case VK_SHIFT:
        	if(stgFlag) shiftFlag = true;
        	break;
        }
        return 0;
    case WM_KEYUP:
    	switch (wParam)
        {
        case 0x5a:
        	if (stgFlag) shootFlag = false;
        	break;
        case VK_DOWN:
			if(stgFlag) downFlag = false;
        	break;
        case VK_UP:
			if(stgFlag) upFlag = false;
        	break;
        case VK_LEFT:
        	if(stgFlag) leftFlag = false;
        	break;
		case VK_RIGHT:
			if(stgFlag) rightFlag = false;
        	break;
        case VK_SHIFT:
        	if(stgFlag) shiftFlag = false;
        	break;
        }
        return 0;
    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}