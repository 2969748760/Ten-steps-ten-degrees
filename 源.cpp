#include <stdio.h>
#include <graphics.h>  
#include <conio.h>
#include <math.h>

#define PI 3.14159 // PI�궨��
#pragma comment(lib, "winmm.lib")
#define WIDTH 600
#define HIGH 700

IMAGE back, bk2;

//��������
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



// ȫ�ֱ�������
int r[4][4] = { {100,HIGH / 2 - 50,500, HIGH / 2 + 50},{200, 190, 400, 260},{200,460,400, 510},{480,630,580,680} };//������ť�Ķ�ά����
int choice;
int step; // ��ʣ�µĲ�������
int score; // �÷֣�Ҳ����һ����ת�˶��ٶ�
int mode;

struct Round // ����ṹ�壬������ʾ���Ƕ�ָʾ��СԲȦ
{
	float x, y; // СԲ��Բ������
	float r; // СԲ�뾶
	int angleNum;  // ��Ӧ�ĽǶȣ�����ֻ����0,1,2,3����ʾ���� PI/2 ���Ӧ���ĸ��Ƕ�ֵ
};

Round rounds[5][5]; // �ṹ���ά����
TCHAR s[20]; // Ҫ������ַ���


void showOut1() 
{
abcd:;  //����ʹ���� goto �� ��Ϊ��ÿ��ִ���˹��ܺ󷵻ص���һ�����´�ӡ�Ӳ˵� Ҳ�����ø��õ��߼�ʵ��ѭ�� ������goto����

	MOUSEMSG m;//���������� m
	//�˵�
	initgraph(800, 600);            //���廭����СҲ���Ǻڿ��С
	cleardevice();                  //ˢ��һ�� �Ե����Ǹ�system(cls)
	initgraph(800, 600);
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls);
	// ��ͼ������ʼ��
	initgraph(800, 600);

	// ��ȡͼƬ����ͼ����
	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	//setfillcolor(LIGHTBLUE);        //���ú����ú�����������ı�����ɫ �������ó���ǳ��ɫ

	//     (���Ͻ�)x1 y1 (���½�)x2 y2
	/*fillrectangle(190, 80, 600, 130);
	fillrectangle(190, 170, 600, 220);
	fillrectangle(190, 260, 600, 310);
	fillrectangle(190, 350, 600, 400);
	fillrectangle(190, 440, 600, 490);*/
	settextcolor(RED);
	settextstyle(30, 0, L"��������");     //�������ִ�С ��ʽ 
	setbkmode(TRANSPARENT);          // ȥ�����ֱ���

	//������������� ����������ʼλ��x ��ʼλ��y ����������ַ�������
	outtextxy(355, 90, L"ģʽһ");
	outtextxy(355, 180, L"ģʽ��");
	outtextxy(355, 270, L"ģʽ��");
	outtextxy(355, 360, L"ģʽ��");
	outtextxy(335, 450, L"�������˵�");
	//���봥��������ѭ��
	while (1) 
	{

		m = GetMouseMsg();
		if (m.x >= 190 && m.x <= 600 && m.y >= 80 && m.y <= 130) {//�������λ�� �Ƿ���������
			setlinecolor(RED);                                     //����� �����µı߿�Ϊ��ɫ
			rectangle(185, 80, 605, 132);                         //���µı߿�
			if (m.uMsg == WM_LBUTTONDOWN) 
			{
				mode = 2;
				mainTwo();                                   //����ʵ�ֺ� ��ת�� �ͷ
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
		//һ����겻����Ӧλ�� ��������ɫ�߿� ����֮ǰ�ĺ�ɫ�߿�
		/*else {
			setlinecolor(WHITE);
			rectangle(190, 80, 600, 130);
			rectangle(190, 170, 600, 220);
			rectangle(190, 260, 600, 310);
			rectangle(190, 350, 600, 400);
			rectangle(190, 440, 600, 490);
		}*/
	}
abcde:;//����˳���ť ����ת�������˳��Ӳ˵� �������˵�
}
void showOut2() {
abcd:;  //����ʹ���� goto �� ��Ϊ��ÿ��ִ���˹��ܺ󷵻ص���һ�����´�ӡ�Ӳ˵� Ҳ�����ø��õ��߼�ʵ��ѭ�� ������goto����

	MOUSEMSG m;//���������� m

	//�˵�
	initgraph(800, 600);            //���廭����СҲ���Ǻڿ��С
	cleardevice();                  //ˢ��һ�� �Ե����Ǹ�system(cls)
	initgraph(800, 600);
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls);
	// ��ͼ������ʼ��
	initgraph(800, 600);

	// ��ȡͼƬ����ͼ����
	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	setfillcolor(LIGHTBLUE);        //���ú����ú�����������ı�����ɫ �������ó���ǳ��ɫ
	fillrectangle(200, 440, 600, 500);
	settextstyle(30, 0, L"��������");     //�������ִ�С ��ʽ 
	setbkmode(TRANSPARENT);          // ȥ�����ֱ���

	outtextxy(320, 455, L"�������˵�");
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
abcd:;  //����ʹ���� goto �� ��Ϊ��ÿ��ִ���˹��ܺ󷵻ص���һ�����´�ӡ�Ӳ˵� Ҳ�����ø��õ��߼�ʵ��ѭ�� ������goto����

	MOUSEMSG m;//���������� m

	//�˵�
	initgraph(800, 600);            //���廭����СҲ���Ǻڿ��С
	cleardevice();                  //ˢ��һ�� �Ե����Ǹ�system(cls)
	initgraph(800, 600);
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls);
	// ��ͼ������ʼ��
	initgraph(800, 600);

	// ��ȡͼƬ����ͼ����
	loadimage(&bk2, L"pic\\bk2.jpg", 800, 600);
	putimage(0, 0, &bk2);
	setfillcolor(LIGHTBLUE);        //���ú����ú�����������ı�����ɫ �������ó���ǳ��ɫ
	fillrectangle(200, 440, 600, 500);
	settextstyle(30, 0, L"��������");     //�������ִ�С ��ʽ 
	setbkmode(TRANSPARENT);          // ȥ�����ֱ���

	outtextxy(320, 456, L"�������˵�");
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
//���������˵���ʵ�� ʵ�ֵ�ϸ�ں��Ӳ˵������� 
void drawMenu() 
{
abcd:;
	mciSendString(L"close Mumusic", NULL, 0, NULL);//ѭ������
	mciSendString(L"open start.mp3 alias Mumusic", NULL, 0, NULL);//�򿪱�������
	mciSendString(L"play Mumusic repeat", NULL, 0, NULL);//ѭ������
	MOUSEMSG m;
	//�˵�
	initgraph(800, 600);
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls);
	// ��ͼ������ʼ��
	initgraph(800, 600);

	// ��ȡͼƬ����ͼ����

	loadimage(&back, L"pic\\back.jpg", 800, 600);

	putimage(0, 0, &back);
	settextstyle(25, 0, L"��������");//�������ָ�ʽ
	settextcolor(RED);
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(350, 100, L"ѡ��ģʽ");
	outtextxy(360, 207, L"���а�");
	outtextxy(350, 327, L"��Ϸ˵��");
	outtextxy(350, 447, L"�˳���Ϸ");
	settextcolor(RGB(51, 82, 204));
	settextstyle(70, 0, L"��������");
	outtextxy(188, 530, L" ʮ  ��  ��  ��");
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
//������

void rotateRound(int i, int j) // �Զ�ά������i��j�е�СԲȦ��˳ʱ����ת
{

	rounds[i][j].angleNum -= 1; // ֵ��1
	if (rounds[i][j].angleNum < 0) // ���С��0������Ϊ3
		rounds[i][j].angleNum = 3;
	score += 90; // �÷ּ���90��
}

// ��õ�ǰԲָ�����һ��ԲȦ���
// ��ǰԲ��Ŵ洢������int indexes[2]�У���һ��Բ���Ҳ�洢�����������
// �������һ��ָ���Բ������1�����ָ��߽��ˣ�����0
int GetNextIndexes(int indexes[2])
{
	int i = indexes[0]; // ��ǰԲ��i��j���
	int j = indexes[1]; // 

	// ���ݵ�ǰԲ�ĽǶȣ������һ��СԲȦ�����
	if (rounds[i][j].angleNum == 0) // ָ���ұߵ�СԲȦ
		j++; // right
	else if (rounds[i][j].angleNum == 3) // ָ���±ߵ�СԲȦ 
		i++; // down
	else if (rounds[i][j].angleNum == 2) // ָ����ߵ�СԲȦ 
		j--; // left
	else if (rounds[i][j].angleNum == 1) // ָ���ϱߵ�СԲȦ 
		i--; // up

	indexes[0] = i; // �������и���ָ�����һ��ԲȦ�����
	indexes[1] = j; // 

	if (i >= 0 && i < mode && j >= 0 && j < mode) // ������û��Խ��
		return 1; // ˵��ָ����һ��ԲȦ������1
	else // 
		return 0;
	// û��ָ����ЧԲȦ������0
}

void startup()  // ��ʼ������
{

	initgraph(600, 700); // �½�����
	mciSendString(L"close Mumusic", NULL, 0, NULL);
	mciSendString(L"open game.mp3 alias Mumusic", NULL, 0, NULL);//�򿪱�������
	mciSendString(L"play Mumusic repeat", NULL, 0, NULL);//ѭ������
	setbkcolor(RGB(50, 50, 50)); // ���ñ�����ɫ
	setlinestyle(PS_SOLID, 3); //  ����������ʽ���߿�
	cleardevice(); // ��ձ���
	BeginBatchDraw(); // ��ʼ��������
	step = 3; // һ�����Բ���10��
	score = 0; // ��ʼΪ0��
	int i, j;
	// ��ʼ�� �趨mode*mode��СԲȦ
	for (i = 0; i < mode; i++)
	{
		for (j = 0; j < mode; j++)
		{
			rounds[i][j].x = 100 + j * 100; // �趨СԲȦ��Բ������
			rounds[i][j].y = 200 + i * 100; // 
			rounds[i][j].r = 30; // �趨СԲȦ�İ뾶
			rounds[i][j].angleNum = 1; // ��ʼ����PI/2�Ƕȣ�Ҳ���Ƕ�������
		}
	}
}

void show() // ���ƺ���
{
	int i, j;
	float angle;
	cleardevice();
	// ������СԲȦ����
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			setlinecolor(RGB(200, 200, 200));  // ����ԲȦΪ�׻�ɫ
			circle(rounds[i][j].x, rounds[i][j].y, rounds[i][j].r); // ��СԲȦ
			setlinecolor(RGB(255, 0, 0)); // ���ýǶ�ָʾ��Ϊ��ɫ
			angle = rounds[i][j].angleNum * PI / 2; // ͨ�������¼�ı����趨��Ӧ�ĽǶ�
			// �����Ǻ����������������
			line(rounds[i][j].x, rounds[i][j].y,
				rounds[i][j].x + rounds[i][j].r * cos(-angle),
				rounds[i][j].y + rounds[i][j].r * sin(-angle));
		}
	}

	setbkmode(TRANSPARENT); // ͸����ʾ����
	int _step = 10 - step;
	swprintf_s(s, _T("%d ��  %d ��"), _step, score);	 // ������ת��Ϊ�ַ���
	settextstyle(50, 0, _T("����")); // �����С����ʽ
	outtextxy(150, 30, s); // ��xyλ������ַ�������
	settextstyle(20, 0, _T("����")); // 
	outtextxy(15, 100, _T("���һ��ԲȦ ��ָ��˳ʱ����ת90��֮�� ָ���ָ��������ת"));
	FlushBatchDraw();
	FlushBatchDraw(); // ��ʼ��������
}

void update()  // ���º���
{
	MOUSEMSG m;		 // ���������Ϣ

	if (MouseHit())   // ����������Ϣ
	{
		m = GetMouseMsg();  // ��������Ϣ
		if (step == 0)
			return;
		if (m.uMsg == WM_LBUTTONDOWN && step > 0) // ������������������һ��п��Բ����Ĳ���
		{
			FlushMouseMsgBuffer();
			//Sleep(100);
			step--; // ��������-1
			int clicked_i = int(m.y - 150) / 100; // ��õ�ǰ���ԲȦ�����
			int clicked_j = int(m.x - 50) / 100; // 
			rotateRound(clicked_i, clicked_j);	// �ѵ�ǰԲȦ˳ʱ����ת90��
			show(); // ����
			Sleep(500); // ��ͣ���ɺ���

			int indexes[2] = { clicked_i,clicked_j }; // ����洢���СԲȦ���������
			while (GetNextIndexes(indexes)) // ���ָ�����һ��ԲȦ���������1����һֱ�ظ�ִ����ȥ
			{

				//Sleep(100);
				rotateRound(indexes[0], indexes[1]);	 // ��ָ�����һ��ԲȦҲ��ת90��
				show(); // ����
				Sleep(500); // ��ͣ���ɺ���
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
	putimage(0, 0, &img_bk);//��ʾ����
	int i, event = 0;
	double angle = 0;
	int center_x = WIDTH / 2, center_y = HIGH / 2;
	int R = WIDTH / 2 - 50 - 3;
	int end_x, end_y;

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 4);
	setfillcolor(RGB(195, 201, 201));
	fillcircle(WIDTH / 2, HIGH / 2, WIDTH / 2 - 50);//��Բ

	//cleardevice();//������ȡ���ڱ���ɫ��
	BeginBatchDraw();

	MOUSEMSG m;//���ָ��

	while (1)
	{
		end_x = center_x + R * sin(angle);
		end_y = center_y - R * cos(angle);

		//setfillcolor(WHITE);
		//setlinestyle(PS_SOLID, 4);


		setlinestyle(PS_SOLID, 3);
		setcolor(RED);
		line(center_x, center_y, end_x, end_y);//��ָ��

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
		LOGFONT f;//������ʽָ��
		gettextstyle(&f);						//��ȡ������ʽ
		//_tcscpy(f.lfFaceName, _T("���Ĳ���"));		//��������Ϊ����
		f.lfQuality = ANTIALIASED_QUALITY;	    // �������Ч��Ϊ�����  
		settextstyle(50, 0, _T("�����п�"));					// ����������ʽ
		setbkcolor(RGB(195, 201, 201));
		settextcolor(WHITE);					//BLACK��graphic.hͷ�ļ����汻����Ϊ��ɫ����ɫ����
		drawtext(s, &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
		drawtext(L"�ٴ���Ϸ", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
		drawtext(L"���ز˵�", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
		drawtext(L"�˳�", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ

		FlushBatchDraw();

		Sleep(30);

		setcolor(RGB(195, 201, 201));
		setlinestyle(PS_SOLID, 3);
		line(center_x, center_y, end_x, end_y);//����ָ��
		angle = angle + 2 * PI / 60;//�Ƕȱ仯

		m = GetMouseMsg();//��ȡһ�������Ϣ

		if (m.x >= 200 && m.x <= 400 && m.y >= 190 && m.y <= 260)
		{//�ٴ���Ϸ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 1;                //����ʵ�ֺ� ��ת�� �ͷ
			}
		}
		if (m.x >= 200 && m.x <= 400 && m.y >= 460 && m.y <= 510)
		{//���ز˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 2;                //����ʵ�ֺ� ��ת�� �ͷ
			}

		}
		if (m.x >= 480 && m.x <= 580 && m.y >= 630 && m.y <= 680)
		{//�˳�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return 0;                //����ʵ�ֺ� ��ת�� �ͷ
			}

		}
	}

}

void game()
{
	startup();  // ��ʼ��
	while (1)   // �ظ�ѭ��
	{
		show();  // ����
		update();  // ����
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


void mainTwo() // ������
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
