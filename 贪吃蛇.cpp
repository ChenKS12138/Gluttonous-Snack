#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>
#include<time.h>
#define w 50              //��� 
#define l 20              //���� 
#define wall '#'          // wall��ʾǽ 
#define maxlength 100          //����� 
// w��ʾ���,l��ʾ����,j��ʾ����,k��ʾ����
char a[l][w];//��ͼ 
int y[maxlength];
int x[maxlength];
int isFood=0;
int randW=0;
int randL=0;
int foodA=3;
int score=0;



void display(){
	system("cls");
	int j,k;
	for(j=0;j<l;j++){
		for(k=0;k<w;k++){
			printf("%c",a[j][k]);
		}
		printf("\n");
	}
}//��ʾ����   ��������a��ֵ���,������� 

void view(){
	
	int j,k;
	for(j=0;j<l;j++){
		for(k=0;k<w;k++){
			a[j][k]='\x20';
		}
	}
	for(j=0,k=0;k<w;k++) a[j][k]=wall;
	for(j=l-1,k=0;k<w;k++) a[j][k]=wall;
	for(k=0,j=1;j<l-1;j++) a[j][k]=wall;
	for(k=w-1,j=1;j<l-1;j++) a[j][k]=wall;
}//��ʼ������  ����ǽ�Ϳհ����� 

void creatFood(){
	int j,k;
	srand(time(NULL));
	do{
		randW=rand()%w;
		randL=rand()%l;
	}
	while(randW==0||randW>=w-foodA||randL==0||randL>=l-foodA);
	for(j=randL;j<randL+foodA;j++){
		for(k=randW;k<randW+foodA;k++){
			a[j][k]='^';
		};
	};
	isFood=1;
}
void seekFood(){
	int j,k;
	for(j=randL;j<randL+foodA;j++){
		for(k=randW;k<randW+foodA;k++){
			if(j==x[0]&&k==y[0]){
				isFood=0;
				score++;
				return;
			}
		};
	};
}


int main(void){
	
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
	}//�����ҵ����ӣ��������ؿ���̨��� 
	
	int j,k,i;
	int crash=0;
	int tempX,tempY;
	int hit=77;
	for(i=0;i<score+2;i++){
		x[i]=15;
	}
	for(i=0;i<score+2;i++){
		y[i]=25-i;
	}
	int direction=4;   //1��ʾ�ϣ�2��ʾ�£�3��ʾ��4��ʾ�� 
	int c=3;
	
	
	while(x[0]!=0&&x[0]!=l-1&&y[0]!=0&&y[0]!=w-1&&crash!=1){
		view();
		a[x[0]][y[0]]='@';
		for(i=1;i<score+2;i++){
			a[x[i]][y[i]]='*';
		}
		for(j=randL;j<randL+foodA;j++){
			for(k=randW;k<randW+foodA;k++){
				a[j][k]='^';
			};
		};
		seekFood();
		if(isFood==0) creatFood();
		display();
		if(kbhit()){
			hit=getch();
			switch(hit){
				case 87:
				case 119:
				case 72:if(direction==2) break;direction=1; break;//  ����
				case 115:
				case 83:
				case 80:if(direction==1) break;direction=2; break;//  ����
				case 97:
				case 65: 
				case 75:if(direction==4) break;direction=3; break;//  ����
				case 100:
				case 68: 
				case 77:if(direction==3) break;direction=4; break;//  ����
			};
		}
		tempX=x[0];tempY=y[0];
		switch(direction){
			case 1:x[0]--; if(a[x[0]][y[0]]=='*') crash=1; break;
			case 2:x[0]++; if(a[x[0]][y[0]]=='*') crash=1; break;
			case 3:y[0]--; if(a[x[0]][y[0]]=='*') crash=1; break;
			case 4:y[0]++; if(a[x[0]][y[0]]=='*') crash=1; break;
		}
		for(i=score+2-1;i>1;i--){
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[1]=tempX;y[1]=tempY;
		printf("\t\tscore : %d\n",score);
		Sleep(40);
	}
	printf("\t\tYOU FAILED\n");
	printf("\tPLEASE PRESS ENTER TO EXIT\n");
	while(1){
		hit=getch();
		if(hit==13) break;
	}
	return 0;
}
