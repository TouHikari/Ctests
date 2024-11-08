/*
题目描述
狗爷和小猪正在进行摸鱼游戏。池塘中游动着n条鱼，它们排成了一条直线队列，其中有 m 条锦鲤
每条锦鲤的具体位置已知。狗爷和小猪将轮流进行操作，每一轮中，每人都必须选择并摸走队列开头或
者结尾的一条鱼，这个过程会一直持续，直到队列中仅剩下一条鱼。这时，如果唯一剩下的这条鱼是
条锦鲤，那么狗爷将获得胜利，否则邪恶的小猪将夺走锦鲤。每次游戏中，小猪将进行首次操作。可以
肯定的是，小猪和狗爷俩人都非常聪明，他们总会选择对自己最有利的策略进行游戏。请判定狗爷能否
取得游戏胜利。如果狗爷可以赢得胜利，输出 Goldye。否则，输出 Xiaozhu Hahaha。

输入格式
第一行输入两个正整数 n,m，分别代表鱼的总数和锦鲤的数量。
第二行输入 m 个整数，代表每条锦鲤在队列中的位置。位置编号从1到n。

输出格式
输出一行字符串。如果狗爷可以赢得胜利，输出 Goldye。否则，输出 Xiaozhu Hahaha。

数据范围
1≤m≤n≤10^5

样例 #1                             样例 #2
样例输入 #1 样例输出 #1              样例输入 #2 样例输出 #2
5 2         Goldye                  4 1        Xiaozhu Hahaha
2 4                                 2
*/

#include <stdio.h>

void goldye(int n, int * array);
void xiaozhu(int n, int * array);
void array_move(int num, int * array, int n);
//声明函数

int main(void)
{                                       //输入、输出、调用函数
    int n, m, location;                 //声明鱼的总数n和锦鲤的数量m
    int fish[n];                        //声明鱼队列数组fish，0代表其他鱼，1代表锦鲤
    for (int i = 0; i < n; i++)         //初始化fish
        fish[i] = 0;
    
    printf("Enter the total number of the fish and the number of koi. \n");
    scanf("%d %d", &n, &m);             //输入鱼的总数n和锦鲤的数量m
    printf("Enter the order numbers of koi from small to large. \n");
    for (int i = 0; i < m; i++)
    {                                   //输入锦鲤位置序号并修改数组fish对应位置
        scanf("%d", &location);
        fish[location-1] = 1;
    }

    while (n > 1)
    {                                   //模拟小猪和狗爷各自不断摸鱼的动作
        xiaozhu(n, fish);
        n -= 1;
        if (n > 1)
        {
            goldye(n, fish);
            n -= 1;
        }
    }
    
    if (1 == fish[0])
    {                                   //若剩下的最后一条鱼是锦鲤的输出
        printf("Goldye\n");
    }
    else if (0 == fish[0])
    {                                   //若剩下的最后一条鱼不是锦鲤的输出
        printf("Xiaozhu Hahaha\n");
    }
    
    
    /*
    for (int i = 0; i < n; i++)
    {                                   //***输出测试用***
        printf("%d", fish[i]);
    }
    */

    return 0;
}

void goldye(int n, int * array)
{                                       //狗爷摸鱼模块（摸走离锦鲤最远的鱼）
    int from_start, from_end, num;

    for (int i = 0, from_start = 0; i < n, array[i] == 0; i++)
        from_start = i;
    for (int i = n, from_end = 0; i > 0, array[i] == 0; i--)
        from_end = n - i;
    
    num = from_start <= from_end ? from_start : from_end;
    array_move(num, array, n);
    return;
}

void xiaozhu(int n, int * array)
{                                       //小猪摸鱼模块（摸走锦鲤或离锦鲤最近的鱼）
    int from_start, from_end, num;

    for (int i = 0, from_start = 0; i < n, array[i] == 0; i++)
        from_start = i;
    for (int i = n, from_end = 0; i > 0, array[i] == 0; i--)
        from_end = n - i;
    
    num = from_start >= from_end ? from_start : from_end;
    array_move(num, array, n);
    return;
}

void array_move(int num, int * array, int n)
{                                       //数组删去元素并重新排列
    for (int i = num; i < n - 1; i++)
    {
        array[num] = array[num+1];
    }
    return;
}