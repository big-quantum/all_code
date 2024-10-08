/*******************************************
用最简单的C语言语句写个推箱子的程序。


********************************************/
#include <stdio.h>  
#include <conio.h>
#include<stdlib.h> 

int map[9][11] = {
    {0,1,1,1,1,1,1,1,1,1,0},  //0代表空地
    {0,1,0,0,0,1,0,0,0,1,0},  //1代表墙
    {0,1,0,4,4,4,4,4,0,1,0},  //3代表目的地
    {0,1,0,4,0,4,0,4,0,1,1},  //4代表箱子
    {0,1,0,0,0,0,0,0,4,0,1},  //5代表人 
    {1,1,0,1,1,1,1,0,4,0,1},
    {1,0,8,3,3,3,3,1,0,0,1},  //2 3 4 5 6 7 8 9 1 0
    {1,0,3,3,3,3,3,0,0,1,1},
    {1,1,1,1,1,1,1,1,1,1,0} };

//绘制地图  //二维数组+switch()
void DrawMap()
{
    //遍历二维数组  //0 打印空格  //1 墙   //3 目的地  //什么结构?
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            //if  else  switch
            switch (map[i][j])
            {
            case 0:
                printf("  ");
                break;
            case 1:
                printf("■");
                break;
            case 3:
                printf("☆");
                break;
            case 4:
                printf("□");
                break;
            case 5:
                printf("♀");  //5人
                break;
            case 7:     //4 + 3  箱子在目的地中
                printf("★");
                break;
            case 8:     // 5 + 3  人在目的地当中   人?
                printf("♀");
                break;
            }
        }
        printf("\n");
    }
}


void PlayGame()
{
    int r, c;  //人的下标  //
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (map[i][j] == 5||map[i][j]==8)   //i j 人的下标?
            {
                r = i;
                c = j;
            }
        }
    }

    char ch;  //字符变量
    ch = getch();  //键盘的输入保存到字符中
    // getch()     getchar()  接收键盘字符
    // getch()直接接收 不显示回文   getchar()显示回文可以修改 enter键结束

    //根据不同的按键  改变不同的值. 分支.
    switch (ch)
    {
    case 'W':  //W A S D方向   72  80  75  77 虚拟键值 ascii  windowVK_UP VK_TAB VK_RETUNE
    case 'w':
    case 72:
        if (map[r - 1][c] == 0|| map[r - 1][c] == 3) 
        {
            map[r - 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)
        {
            if (map[r - 2][c] == 0 || map[r - 2][c] == 3)
            {
                map[r - 2][c] += 4;
                map[r - 1][c] += 1;
                map[r][c] -= 5;
            }
        }



        break;

    case 'S':  //enter按键的作用  确认 返回
    case 's':
    case 80:
        if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
        {
            map[r + 1][c] += 5;
            map[r][c] -= 5;
        }
        else if (map[r + 1][c] == 4 || map[r+ 1][c] == 7)
        {
            if (map[r + 2][c] == 0 || map[r + 2][c] == 3)
            {
                map[r + 2][c] += 4;
                map[r + 1][c] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'A':
    case 'a':
    case 75:
        if (map[r ][c - 1] == 0 || map[r ][c - 1] == 3)
        {
            map[r ][c - 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)
        {
            if (map[r ][c - 2] == 0 || map[r ][c - 2] == 3)
            {
                map[r ][c - 2] += 4;
                map[r ][c - 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;

    case 'D':
    case 'd':
    case 77:
        if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
        {
            map[r][c + 1] += 5;
            map[r][c] -= 5;
        }
        else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)
        {
            if (map[r][c + 2] == 0 || map[r][c + 2] == 3)
            {
                map[r][c + 2] += 4;
                map[r][c + 1] += 1;
                map[r][c] -= 5;
            }
        }
        break;
    }
}

//
int main()  //主函数
{
    while (1)
    {
        system("cls");
        DrawMap();
        PlayGame();
    }

    return 0;
}

//通过按键来实现游戏  ---> 通过按键来改变二维数组的排列顺序.
//思考一个问题? 地图是二维数组来决定的. 人在哪里  二维数组来决定?

/************************************************
//人推箱子  
可以动.    怎么办.  改变元素
        1.人的前面是空地
        2.人的前面是目的地
        3.人的前面是箱子
            3.1 箱子的前面是空地
            3.2 箱子的前面是目的地


            //盘断二维数组中有几个7
            //没有目的地  不对..  人站在目的地
            //有没有4.
****************************************/
