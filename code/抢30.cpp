#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int input(int t);
int copu(int s);
int main()
{
    int tol=0;
    printf("\n* * * * * * * *catch thirty* * * * * * * \n");
    printf("Game Begin\n");
    rand();  /*初始化随机数发生器*/
    /*取随机数决定机器和人谁先走第一步。若为1，则表示人先走第一步*/
    if(rand()%2)
        tol=input(tol);
    while(tol!=30)  /*游戏结束条件*/
        if((tol=copu(tol)) == 30)  /*计算机取一个数，若为30则机器胜利*/
            printf("I lose! \n");
        else
            if((tol=input(tol)) == 30)  /*人取一个数，若为30则人胜利*/
                printf("I lose! \n");
    printf(" * * * * * * * *Game Over * * * * * * * *\n");
    return 0;
}
int input(int t)
{
    int a;
    do{
        printf("Please count:");
        scanf("%d", &a);
        if(a>2 || a<1 || t+a>30)
            printf("Error input,again!");
        else
            printf("You count:%d\n", t+a);
    }while(a>2 || a<1 || t+a>30);
    return t+a;  /*返回当前已经取走的数的累加和*/
}
int copu(int s)
{
    int c;
    printf("Computer count:");
    if((s+1)%3 == 0)  /*若剩余的数的模为1，则取1*/
        printf(" %d\n",++s);
    else
        if((s+2)%3 == 0)
        {
            s+=2;  /*若剩余的数的模为2，则取2*/
            printf(" %d\n",s);
        }
        else
        {
            c=rand()%2+1;  /*否则随机取1或2*/
            s+=c;
            printf(" %d\n",s);
        }
    return s;
}
