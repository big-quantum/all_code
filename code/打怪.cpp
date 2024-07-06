#include<bits/stdc++.h> 
int x=-1,y=-1;
int nx=7,ny=19;
int key=0;
void a();
void s();
void d();
void f();
void g();
void h();
void j();
int main(int argc, _TCHAR* argv[])
{
	srand(time(0));
	while(1)
	{
		system("cls");
		s();
		g();
		a();
		d();
		h();
		f();
		j();
		Sleep(250);
	}
}
void a()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==0)
			{
				printf("  ");
			}
			if (qipan[i][j]==1)
			{//我方战机
				printf("⊥");
			}
			if(qipan[i][j]==2)
			{//敌方战机
				printf(" ");
			}
			if(qipan[i][j]==4)
			{
				printf("1 ");
			}
		}
	printf("\n");
	}
}
 
 
void j()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==4)
			{
				qipan[i-1][j]=4;
				if(qipan[i-2][j]==2)
				{
					j();
					qipan[i-1][j]=0;
				}
				qipan[i][j]=0;
 
			}
		}
	}
}
void g()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==1)
			{
				qipan[i][j]=0;
			}
		}
	}
 
	qipan[ny][nx]=1;
}
void s()
{	
	
		do 
		{
			x=rand()%15;
			y=rand()%2;
			if((rand()%6)!=0)
				return;
 
		}
		while (qipan[y][x]==2);
		qipan[y][x]=2;
 
}
void d()
{
	int a=0,b=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==2)
			{
					qipan[i+1][j]=3;
					qipan[i][j]=0;
					a++;
			}
		}
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==3)
			{
				qipan[i][j]=2;
				b++;
			}
		}
	}
}
void f()
{
	if(kbhit()!=0)
	{
		while(kbhit()!=0)
			key=getch();
		if(key==72)//上
			ny=ny-1;
		if(key==80)//下
			ny=ny+1;
		if(key==75)//左 
			nx=nx-1;	
		if(key==77)//右
			nx=nx+1;
		if(key==32)
		{
			qipan[ny-1][nx]=4;
		}
	}
}
void h()
{
	int a=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(qipan[i][j]==1)
			{
				a++;
			}
		}
	}
	if(a!=1)
	{
		printf("游戏结束\n");
		system("pause");
		exit(0);
	}
}

