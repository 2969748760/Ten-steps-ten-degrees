#include <stdio.h>
#include <graphics.h>  
#include <conio.h>
#include <math.h>

#define PI 3.14159 // PI宏定义
#pragma comment(lib, "winmm.lib")
#define WIDTH 600
#define HIGH 700

IMAGE back, bk2;

//函数声明
void drawMenu();
void game();
void gameover();
int gameoverP();
int GetNextIndexes(int indexes[2]);
void mainTwo();
void show();
void showOut1();
void showOut2();
void showOut3();
void update();



// 全局变量定义
int r[4][4] = { {100,HIGH / 2 - 50,500, HIGH / 2 + 50},{200, 190, 400, 260},{200,460,400, 510},{480,630,580,680} };//三个按钮的二维数组
int choice;
int step; // 还剩下的操作步数
int score; // 得分，也就是一共旋转了多少度
int mode;

struct Round // 定义结构体，用来表示带角度指示的小圆圈
{
	float x, y; // 小圆的圆心坐标
	float r; // 小圆半径
	int angleNum;  // 对应的角度，这里只能是0,1,2,3。表示乘以 PI/2 后对应的四个角度值
};

Round rounds[5][5]; // 结构体二维数组
TCHAR s[20]; // 要输出的字符串


void showOut1() 
{
abcd:;  //这里使用了 goto ： 是为了每次执行了功能后返回到第一步重新打印子菜单 也可以用更好的逻辑实现循环 而不用goto函数

	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	initgraph(800, 600);            //定义画布大小也就是黑框大小
	cleardevice();                  //刷新一次 略等于那个system(cls)
	initgraph(800, 600);
	cleardevice();//刷新一次 略等于那个system(cls);
	// 绘图环境初始化
	initgraph(800, 600);

	// 读取图片至绘图窗口
	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	//setfillcolor(LIGHTBLUE);        //设置后面用函数画出方框的背景颜色 这里设置成了浅蓝色

	//     (左上角)x1 y1 (右下角)x2 y2
	/*fillrectangle(190, 80, 600, 130);
	fillrectangle(190, 170, 600, 220);
	fillrectangle(190, 260, 600, 310);
	fillrectangle(190, 350, 600, 400);
	fillrectangle(190, 440, 600, 490);*/
	settextcolor(RED);
	settextstyle(30, 0, L"华文琥珀");     //设置文字大小 格式 
	setbkmode(TRANSPARENT);          // 去掉文字背景

	//下面是输出字体 参数：（起始位置x 起始位置y “带输出的字符串”）
	outtextxy(355, 90, L"模式一");
	outtextxy(355, 180, L"模式二");
	outtextxy(355, 270, L"模式三");
	outtextxy(355, 360, L"模式四");
	outtextxy(335, 450, L"返回主菜单");
	//进入触发条件的循环
	while (1) 
	{

		m = GetMouseMsg();
		if (m.x >= 190 && m.x <= 600 && m.y >= 80 && m.y <= 130) {//检测鼠标的位置 是否满足条件
			setlinecolor(RED);                                     //满足后 设置新的边框为红色
			rectangle(185, 80, 605, 132);                         //画新的边框
			if (m.uMsg == WM_LBUTTONDOWN) 
			{
				mode = 2;
				mainTwo();                                   //功能实现后 跳转到 最开头
			}
		}
		else if (m.x >= 190 && m.x <= 600 && m.y >= 170 && m.y <= 220) {
			setlinecolor(RED);
			rectangle(185, 170, 605, 222);
			if (m.uMsg == WM_LBUTTONDOWN) 
			{
				mode = 3;
				mainTwo();
			}
		}
		else if (m.x >= 190 && m.x <= 600 && m.y >= 260 && m.y <= 310) {
			setlinecolor(RED);
			rectangle(185, 260, 605, 312);
			if (m.uMsg == WM_LBUTTONDOWN) {
				mode = 4;
				mainTwo();
			}
		}
		else if (m.x >= 190 && m.x <= 600 && m.y >= 350 && m.y <= 400) {
			setlinecolor(RED);
			rectangle(185, 350, 605, 402);
			if (m.uMsg == WM_LBUTTONDOWN) {
				mode = 5;
				mainTwo();
			}
		}

		else if (m.x >= 190 && m.x <= 600 && m.y >= 440 && m.y <= 490) {//
			setlinecolor(RED);
			rectangle(185, 440, 605, 492);
			if (m.uMsg == WM_LBUTTONDOWN) 
			{
				goto abcde;
			}
		}
		//一旦鼠标不在相应位置 将画出白色边框 覆盖之前的红色边框
		/*else {
			setlinecolor(WHITE);
			rectangle(190, 80, 600, 130);
			rectangle(190, 170, 600, 220);
			rectangle(190, 260, 600, 310);
			rectangle(190, 350, 600, 400);
			rectangle(190, 440, 600, 490);
		}*/
	}
abcde:;//点击退出按钮 就跳转到这里退出子菜单 返回主菜单
}
void showOut2() {
abcd:;  //这里使用了 goto ： 是为了每次执行了功能后返回到第一步重新打印子菜单 也可以用更好的逻辑实现循环 而不用goto函数

	MOUSEMSG m;//定义鼠标变量 m

	//菜单
	initgraph(800, 600);            //定义画布大小也就是黑框大小
	cleardevice();                  //刷新一次 略等于那个system(cls)
	initgraph(800, 600);
	cleardevice();//刷新一次 略等于那个system(cls);
	// 绘图环境初始化
	initgraph(800, 600);

	// 读取图片至绘图窗口
	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	setfillcolor(LIGHTBLUE);        //设置后面用函数画出方框的背景颜色 这里设置成了浅蓝色
	fillrectangle(200, 440, 600, 500);
	settextstyle(30, 0, L"华文琥珀");     //设置文字大小 格式 
	setbkmode(TRANSPARENT);          // 去掉文字背景

	outtextxy(320, 455, L"返回主菜单");
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 500) {//
			setlinecolor(RED);
			rectangle(190, 435, 610, 505);
			if (m.uMsg == WM_LBUTTONDOWN) {
				goto abcde;
			}
		}
	}
abcde:;
}
void showOut3() {
abcd:;  //这里使用了 goto ： 是为了每次执行了功能后返回到第一步重新打印子菜单 也可以用更好的逻辑实现循环 而不用goto函数

	MOUSEMSG m;//定义鼠标变量 m

	//菜单
	initgraph(800, 600);            //定义画布大小也就是黑框大小
	cleardevice();                  //刷新一次 略等于那个system(cls)
	initgraph(800, 600);
	cleardevice();//刷新一次 略等于那个system(cls);
	// 绘图环境初始化
	initgraph(800, 600);

	// 读取图片至绘图窗口
	loadimage(&bk2, L"pic\\bk2.jpg", 800, 600);
	putimage(0, 0, &bk2);
	setfillcolor(LIGHTBLUE);        //设置后面用函数画出方框的背景颜色 这里设置成了浅蓝色
	fillrectangle(200, 440, 600, 500);
	settextstyle(30, 0, L"华文琥珀");     //设置文字大小 格式 
	setbkmode(TRANSPARENT);          // 去掉文字背景

	outtextxy(320, 456, L"返回主菜单");
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 200 && m.x <= 600 && m.y >= 440 && m.y <= 500) {//
			setlinecolor(RED);
			rectangle(190, 435, 610, 505);
			if (m.uMsg == WM_LBUTTONDOWN) {
				goto abcde;
			}
		}
	}
abcde:;
}
//下面是主菜单的实现 实现的细节和子菜单的类似 
void drawMenu() 
{
abcd:;
	mciSendString(L"close Mumusic", NULL, 0, NULL);//循环播放
	mciSendString(L"open start.mp3 alias Mumusic", NULL, 0, NULL);//打开背景音乐
	mciSendString(L"play Mumusic repeat", NULL, 0, NULL);//循环播放
	MOUSEMSG m;
	//菜单
	initgraph(800, 600);
	cleardevice();//刷新一次 略等于那个system(cls);
	// 绘图环境初始化
	initgraph(800, 600);

	// 读取图片至绘图窗口

	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	settextstyle(25, 0, L"华文琥珀");//设置文字格式
	settextcolor(RED);
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(350, 100, L"选择模式");
	outtextxy(360, 207, L"排行榜");
	outtextxy(350, 327, L"游戏说明");
	outtextxy(350, 447, L"退出游戏");
	settextcolor(RGB(51, 82, 204));
	settextstyle(70, 0, L"华文琥珀");
	outtextxy(188, 530, L" 十  步  万  度");
	while (1) {

		m = GetMouseMsg();
		if (m.x >= 300 && m.x <= 500 && m.y >= 90 && m.y <= 140) {
			setlinecolor(RED);
			rectangle(295, 85, 505, 135);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showOut1();
				goto abcd;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 195 && m.y <= 245) {//
			setlinecolor(RED);
			rectangle(295, 190, 505, 240);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showOut2();
				goto abcd;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 320 && m.y <= 370) {//
			setlinecolor(RED);
			rectangle(295, 315, 505, 365);
			if (m.uMsg == WM_LBUTTONDOWN) {
				showOut3();
				goto abcd;
			}
		}
		else if (m.x >= 300 && m.x <= 500 && m.y >= 440 && m.y <= 490) {//
			setlinecolor(RED);
			rectangle(295, 435, 505, 495);
			if (m.uMsg == WM_LBUTTONDOWN) {
				exit(0);
			}
		}
	}
	getchar();
	closegraph();
}
//主函数

void rotateRound(int i, int j) // 对二维数组中i行j列的小圆圈，顺时针旋转
{

	rounds[i][j].angleNum -= 1; // 值减1
	if (rounds[i][j].angleNum < 0) // 如果小于0，再设为3
		rounds[i][j].angleNum = 3;
	score += 90; // 得分加上90度
}

// 获得当前圆指向的下一个圆圈序号
// 当前圆序号存储在数组int indexes[2]中，下一个圆序号也存储在这个数组中
// 如果有下一个指向的圆，返回1；如果指向边界了，返回0
int GetNextIndexes(int indexes[2])
{
	int i = indexes[0]; // 当前圆的i，j序号
	int j = indexes[1]; // 

	// 根据当前圆的角度，获得下一个小圆圈的序号
	if (rounds[i][j].angleNum == 0) // 指向右边的小圆圈
		j++; // right
	else if (rounds[i][j].angleNum == 3) // 指向下边的小圆圈 
		i++; // down
	else if (rounds[i][j].angleNum == 2) // 指向左边的小圆圈 
		j--; // left
	else if (rounds[i][j].angleNum == 1) // 指向上边的小圆圈 
		i--; // up

	indexes[0] = i; // 在数组中更新指向的下一个圆圈的序号
	indexes[1] = j; // 

	if (i >= 0 && i < mode && j >= 0 && j < mode) // 如果序号没有越界
		return 1; // 说明指向了一个圆圈，返回1
	else // 
		return 0;
	// 没有指向有效圆圈，返回0
}

void startup()  // 初始化函数
{

	initgraph(600, 700); // 新建画面
	mciSendString(L"close Mumusic", NULL, 0, NULL);
	mciSendString(L"open game.mp3 alias Mumusic", NULL, 0, NULL);//打开背景音乐
	mciSendString(L"play Mumusic repeat", NULL, 0, NULL);//循环播放
	setbkcolor(RGB(50, 50, 50)); // 设置背景颜色
	setlinestyle(PS_SOLID, 3); //  设置线条样式、线宽
	cleardevice(); // 清空背景
	BeginBatchDraw(); // 开始批量绘制
	step = 3; // 一共可以操作10步
	score = 0; // 初始为0度
	int i, j;
	// 初始化 设定mode*mode个小圆圈
	for (i = 0; i < mode; i++)
	{
		for (j = 0; j < mode; j++)
		{
			rounds[i][j].x = 100 + j * 100; // 设定小圆圈的圆心坐标
			rounds[i][j].y = 200 + i * 100; // 
			rounds[i][j].r = 30; // 设定小圆圈的半径
			rounds[i][j].angleNum = 1; // 开始都是PI/2角度，也就是都是向上
		}
	}
}

void show() // 绘制函数
{
	int i, j;
	float angle;
	cleardevice();
	// 对所有小圆圈遍历
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			setlinecolor(RGB(200, 200, 200));  // 设置圆圈为白灰色
			circle(rounds[i][j].x, rounds[i][j].y, rounds[i][j].r); // 画小圆圈
			setlinecolor(RGB(255, 0, 0)); // 设置角度指示线为红色
			angle = rounds[i][j].angleNum * PI / 2; // 通过数组记录的变量设定对应的角度
			// 用三角函数，画出这根红线
			line(rounds[i][j].x, rounds[i][j].y,
				rounds[i][j].x + rounds[i][j].r * cos(-angle),
				rounds[i][j].y + rounds[i][j].r * sin(-angle));
		}
	}

	setbkmode(TRANSPARENT); // 透明显示文字
	int _step = 10 - step;
	swprintf_s(s, _T("%d 步  %d 度"), _step, score);	 // 把整数转换为字符串
	settextstyle(50, 0, _T("宋体")); // 字体大小、样式
	outtextxy(150, 30, s); // 在xy位置输出字符串文字
	settextstyle(20, 0, _T("宋体")); // 
	outtextxy(15, 100, _T("点击一个圆圈 其指针顺时针旋转90度之后 指向的指针依次旋转"));
	FlushBatchDraw();
	FlushBatchDraw(); // 开始批量绘制
}

void update()  // 更新函数
{
	MOUSEMSG m;		 // 定义鼠标消息

	if (MouseHit())   // 如果有鼠标消息
	{
		m = GetMouseMsg();  // 获得鼠标消息
		if (step == 0)
			return;
		if (m.uMsg == WM_LBUTTONDOWN && step > 0) // 如果按下鼠标左键，并且还有可以操作的步数
		{
			FlushMouseMsgBuffer();
			//Sleep(100);
			step--; // 操作步数-1
			int clicked_i = int(m.y - 150) / 100; // 获得当前点击圆圈的序号
			int clicked_j = int(m.x - 50) / 100; // 
			rotateRound(clicked_i, clicked_j);	// 把当前圆圈顺时针旋转90度
			show(); // 绘制
			Sleep(500); // 暂停若干毫秒

			int indexes[2] = { clicked_i,clicked_j }; // 数组存储点击小圆圈的行列序号
			while (GetNextIndexes(indexes)) // 获得指向的下一个圆圈。如果返回1，就一直重复执行下去
			{

				//Sleep(100);
				rotateRound(indexes[0], indexes[1]);	 // 将指向的下一个圆圈也旋转90度
				show(); // 绘制
				Sleep(500); // 暂停若干毫秒
			}
		}
	}
}

void gameover()
{
	mciSendString(L"close Mumusic", NULL, 0, NULL);
	mciSendString(L"open end.mp3 alias Mumusic", NULL, 0, NULL);
	mciSendString(L"play Mumusic", NULL, 0, NULL);
	closegraph();

	choice = gameoverP();

	EndBatchDraw();
	//system("pause");
	closegraph();
}

int gameoverP()
{
	initgraph(WIDTH, HIGH);
	IMAGE img_bk;
	loadimage(&img_bk, L"background.jpg");
	putimage(0, 0, &img_bk);//显示背景
	int i, event = 0;
	double angle = 0;
	int center_x = WIDTH / 2, center_y = HIGH / 2;
	int R = WIDTH / 2 - 50 - 3;
	int end_x, end_y;

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 4);
	setfillcolor(RGB(195, 201, 201));
	fillcircle(WIDTH / 2, HIGH / 2, WIDTH / 2 - 50);//大圆

	//cleardevice();//清屏（取决于背景色）
	BeginBatchDraw();

	MOUSEMSG m;//鼠标指针

	while (1)
	{
		end_x = center_x + R * sin(angle);
		end_y = center_y - R * cos(angle);

		//setfillcolor(WHITE);
		//setlinestyle(PS_SOLID, 4);


		setlinestyle(PS_SOLID, 3);
		setcolor(RED);
		line(center_x, center_y, end_x, end_y);//画指针

		setfillcolor(RGB(195, 201, 201));
		setcolor(WHITE);
		fillrectangle(r[0][0], r[0][1], r[0][2], r[0][3]);
		fillrectangle(r[1][0], r[1][1], r[1][2], r[1][3]);
		fillrectangle(r[2][0], r[2][1], r[2][2], r[2][3]);
		fillrectangle(r[3][0], r[3][1], r[3][2], r[3][3]);
		RECT R1 = { r[0][0],r[0][1],r[0][2],r[0][3] };
		RECT R2 = { r[1][0],r[1][1],r[1][2],r[1][3] };
		RECT R3 = { r[2][0],r[2][1],r[2][2],r[2][3] };
		RECT R4 = { r[3][0],r[3][1],r[3][2],r[3][3] };
		LOGFONT f;//字体样式指针
		gettextstyle(&f);						//获取字体样式
		//_tcscpy(f.lfFaceName, _T("华文彩云"));		//设置字体为宋体
		f.lfQuality = ANTIALIASED_QUALITY;	    // 设置输出效果为抗锯齿  
		settextstyle(50, 0, _T("华文行楷"));					// 设置字体样式
		setbkcolor(RGB(195, 201, 201));
		settextcolor(WHITE);					//BLACK在graphic.h头文件里面被定义为黑色的颜色常量
		drawtext(s, &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
		drawtext(L"再次游戏", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
		drawtext(L"返回菜单", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示
		drawtext(L"退出", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//在矩形区域R1内输入文字，水平居中，垂直居中，单行显示

		FlushBatchDraw();

		Sleep(30);

		setcolor(RGB(195, 201, 201));
		setlinestyle(PS_SOLID, 3);
		line(center_x, center_y, end_x, end_y);//覆盖指针
		angle = angle + 2 * PI / 60;//角度变化

		m = GetMouseMsg();//获取一条鼠标消息

		if (m.x >= 200 && m.x <= 400 && m.y >= 190 && m.y <= 260)
		{//再次游戏
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 1;                //功能实现后 跳转到 最开头
			}
		}
		if (m.x >= 200 && m.x <= 400 && m.y >= 460 && m.y <= 510)
		{//返回菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 2;                //功能实现后 跳转到 最开头
			}

		}
		if (m.x >= 480 && m.x <= 580 && m.y >= 630 && m.y <= 680)
		{//退出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;                //功能实现后 跳转到 最开头
			}

		}
	}

}

void game()
{
	startup();  // 初始化
	while (1)   // 重复循环
	{
		show();  // 绘制
		update();  // 更新
		if (step == 0)
			break;
	}
	gameover();
	switch (choice)
	{
	case 1:
		game();
		break;
	case 2:
		drawMenu();
		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}


void mainTwo() // 主函数
{
	game();
	gameover();
	switch (choice)
	{
	case 1:
		game();
		break;
	case 2:

		break;
	case 0:
		exit(0);
		break;
	default:
		break;
	}
}
int main()
{
	drawMenu();
}
