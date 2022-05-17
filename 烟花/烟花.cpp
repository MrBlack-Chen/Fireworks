#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include <mmsystem.h> 
#pragma comment(lib,"winmm.lib")

void HideCursor(int x)
{
	CONSOLE_CURSOR_INFO cursor_info={1,x};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);	
}

void SetColor(int color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void GotoXY(int x,int y)
{
	COORD pos;
	pos.X=x-1;
	pos.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void DrawCircle(int x1,int y1,int r)
{
	double x,y,a=0;
	int i;
	for(i=0;i<120;i++)
	{
		a+=(2*3.1415)/120;
		x=x1+r*sin(a);
		x=x*2;
		y=y1-r*cos(a);
		x=round(x);
		y=round(y);
		if(x>=1 && x<=89 && y>=1 && y<=44)
		{
			GotoXY(x,y);
			printf("·"); 
		}
	}
}

int main() 
{
	system("mode con cols=90 lines=90");
	srand((unsigned int)time(NULL));
	double x1,y1,r;
	int color,flag=1;
	PlaySound("M.wav",NULL,SND_ASYNC|SND_LOOP);
	HideCursor(0);
	SetColor(14);
	GotoXY(40,20);
	printf("虎年快乐，万事胜意"); 
	Sleep(1000);
	system("cls");
	do
	{
		x1=rand() % 10 + 30;
		y1=rand() % 10 + 30;
		for(r=1;r<10;r++)
		{
			color=rand()%15+1; 
			SetColor(color);
			DrawCircle(x1,y1,r);
			SetColor(color+1);
			DrawCircle(x1-15,y1-15,r);
			SetColor(color+2);
			DrawCircle(x1+15,y1+15,r);
			Sleep(100);
			SetColor(0);
			DrawCircle(x1,y1,r);
			DrawCircle(x1-15,y1-15,r);
			DrawCircle(x1+15,y1+15,r);
			if(kbhit())
			{
				flag=0;
				break;
			}
		}		
	}while(flag);
	HideCursor(1);
	return 0;
}
