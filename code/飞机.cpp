#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int feiji_x,feiji_y;//???¦Ë??
int zidan_x,zidan_y;//???¦Ë??
int diji_x,diji_y;//?§Ý?¦Ë??
int h,w;
int score=0;//?¡Â?
int c=0;
 
void gotoxy(int x,int y){				//??¦Ë???¦Ë??????????
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}
 
void startup(){
	h=20;
	w=60;
 
	feiji_x=h/2;
	feiji_y=w/2;
 
	zidan_y=feiji_y;
	zidan_x=-1;
 
	diji_y=w/2;
	diji_x=0;
}
void show(){
	int i,j;
	char dad;
	if(c==0){
		printf("======================================\n");
		printf("=           ---????---             =\n");
		printf("=       w,a,s,d------?????????    =\n");
		printf("=           ?????????????         =\n");
		printf("=       j------------???????        =\n");
		printf("=                                    =\n");
		printf("=         ????????????               =\n");
		printf("=                        ----????  =\n");
		printf("======================================\n");
		c++;
		dad=getch();
		system("cls");
	}
	gotoxy(0,0);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(i==feiji_x && j==feiji_y)
				printf("??");
			else if(i==zidan_x && j==zidan_y)
				printf("??");
			else if(i==diji_x && j==diji_y)
				printf("??");
			else 
				printf(" ");
		}
		printf("\n");
	}
	printf("????¡Â??%d",score);
	Sleep(50);
}
void wuguan(){
	static int speed=0;
	if(speed<5)
		speed++;
	if(diji_x>h){
		diji_x=0;
		diji_y=rand()%w;
	}
	
	else{
		if(speed==5){
			diji_x++;
			speed=0;
		}
	}
	zidan_x--;
	if(zidan_y==diji_y&&zidan_x==diji_x){
		diji_x=0;
		zidan_x=-1;
		diji_y=rand()%w;
		score++;
	}
	
 
}
void youguan(){
	char input;
	if(kbhit()){
		input=getch();
		if(input=='w')feiji_x--;
		if(input=='a')feiji_y--;
		if(input=='s')feiji_x++;
		if(input=='d')feiji_y++;
		if(input=='j'){
			zidan_y=feiji_y;
			zidan_x=feiji_x-1;
		}
	}
}
int main(){
	startup();//????
	while(1){
		show();//???????
		wuguan();//???????????
		youguan();//??????§Û????
		if(score==5){
			printf("??????????§µ????\n");
			break;
		}
	}
	return 0;
}

