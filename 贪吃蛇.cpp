#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>
#define w 50              //��� 
#define l 20              //���� 
#define wall '#'          // wall��ʾǽ 
#define length 8          //���� 
// w��ʾ���,l��ʾ����,j��ʾ����,k��ʾ����
char a[l][w];//��ͼ 



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





int main(void){
	
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
	}//�����ҵ����ӣ��������ؿ���̨��� 
	
	int j,k,i;
	int hit=77;
	int x[length];
	for(i=0;i<length;i++){
		x[i]=15;
	}
	int y[length];
	for(i=0;i<length;i++){
		y[i]=25-i;
	}
	int direction=4;   //1��ʾ�ϣ�2��ʾ�£�3��ʾ��4��ʾ�� 
	int c=3;
	
	
	while(x[0]!=0&&x[0]!=l-1&&y[0]!=0&&y[0]!=w-1){
		view();
		for(i=0;i<length;i++){
			a[x[i]][y[i]]='*';
		}
		display();
		if(kbhit()){
			hit=getch();
			switch(hit){
				case 87:
				case 119:
				case 72:direction=1; break;//  ����
				case 115:
				case 83:
				case 80:direction=2; break;//  ����
				case 97:
				case 65: 
				case 75:direction=3; break;//  ����
				case 100:
				case 68: 
				case 77:direction=4; break;//  ����
			};
		}
		switch(direction){
			case 1:x[0]--; break;
			case 2:x[0]++; break;
			case 3:y[0]--; break;
			case 4:y[0]++; break;
		}
		for(i=length-1;i>0;i--){
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		Sleep(100);
	}
	printf("YOU FAILED");
	return 0;
}
