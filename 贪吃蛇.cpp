#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<windows.h>
#define w 50              //宽度 
#define l 20              //长度 
#define wall '#'          // wall表示墙 
#define length 8          //蛇身长 
// w表示宽度,l表示长度,j表示行数,k表示列数
char a[l][w];//地图 



void display(){
	system("cls");
	int j,k;
	for(j=0;j<l;j++){
		for(k=0;k<w;k++){
			printf("%c",a[j][k]);
		}
		printf("\n");
	}
}//显示界面   根据数组a的值情况,输出界面 

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
}//初始化界面  构建墙和空白区域 





int main(void){
	
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = false; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	}//网上找的轮子，用于隐藏控制台光标 
	
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
	int direction=4;   //1表示上，2表示下，3表示左，4表示右 
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
				case 72:direction=1; break;//  向上
				case 115:
				case 83:
				case 80:direction=2; break;//  向下
				case 97:
				case 65: 
				case 75:direction=3; break;//  向左
				case 100:
				case 68: 
				case 77:direction=4; break;//  向右
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
