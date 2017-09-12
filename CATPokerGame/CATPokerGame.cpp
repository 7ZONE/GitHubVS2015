// CATPokerGame.cpp : 定义控制台应用程序的入口点。
/*
Programing : The game of little cat fishs  fish
Date:2017-6-27
Author:ZZQ
Version:2.0
The First Version:baidu
*/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>  
using namespace std;

void shuffle2(int a[])
{
	int m = 52;
	for (int n = 1;n <= 4;n++)
	{
		for (int i = 1;i <= 13;i++)
		{
			a[m--] = i;
		}
	}
	int tmp = 0, p1, p2;
	int cnt = 1023;
	while (cnt--)
	{
		p1 = rand() % 52;
		p2 = rand() % 52;
		tmp = a[p1];
		a[p1] = a[p2];
		a[p2] = tmp;
	}
}
struct queue
{
	int data[1000];
	int head;
	int tail;
};
struct stack
{
	int data[54];
	int top;
};

void main()
{
	srand(unsigned(time(NULL)));
	struct queue q1, q2;
	struct stack s;
	int book[54];
	int i, t;
	int A[54] = { 0 };
	shuffle2(A);
	
	
		//初始化队列  
		q1.head = 1;
		q1.tail = 1;
		q2.head = 1; 
		q2.tail = 1;
		//初始化栈  
		s.top = 0;
		//初始化用来标记的数组，用来标记哪些牌已经在桌上  
		for (i = 0;i <= 52;i++)
		{
			book[i] = 0;
		}
		//分别把牌发给双方
	
		for (int i =0 ;i <26; i++)
		{
			q1.data[q1.tail] = A[i];//0-25
			q1.tail++;
		}
		for (int i = 26;i < 53;i++)
		{
			q2.data[q2.tail] = A[i];//0-25
			q2.tail++;
		}
		cout << "此时小哼手中的牌为：" << endl;
		for (int i = 1;i <=26; i++)
		{
			cout <<"  " << q1.data[i];
		}
		cout << endl;
		cout << "此时小哈手中的牌为：" << endl;

		for (int i = 1;i <= 26; i++)
		{
			cout<<"  " << q2.data[i];
		}
		cout << endl;

		while (q1.head < q1.tail && q2.head < q2.tail)
		{
			t = q1.data[q1.head];       // 第一个人出第一张牌 出队  
			if (0 == book[t])            // 桌上没有这张牌 入栈  
			{
				s.data[++s.top] = t;
				book[t] = 1;        // 并标记桌上已经有牌面为t的牌  
				q1.head++;
			}
			else
			{
				q1.data[q1.tail++] = t;         // 赢牌  
				q1.head++;
				while (s.data[s.top] != t)       // 把相同的牌放到某人手中牌的末尾  
				{
					book[s.data[s.top]] = 0;
					q1.data[q1.tail++] = s.data[s.top--];
				}
			}

			t = q2.data[q2.head];
			if (0 == book[t])
			{
				s.data[++s.top] = t;
				book[t] = 1;
				q2.head++;
			}
			else
			{
				q2.data[q2.tail++] = t;
				q2.head++;
				while (s.data[s.top] != t)
				{
					book[s.data[s.top]] = 0;
					q2.data[q2.tail++] = s.data[s.top--];
				}
			}
		}

		if (q2.head == q2.tail)
		{


			cout << "小哼win " << endl;
			cout << "小哼当前手中的牌是: " << endl;
			for (i = q1.head;i <= q1.tail - 1;i++)

			{
				cout << "  " << q1.data[i];
			}
			cout << endl;
			
			if (s.top>0) //如果桌上有牌则依次输出桌上的牌  
			{
				cout << "桌上的牌是：" << endl;
				for (i = 1;i <= s.top;i++)
				{
					cout << "  " << s.data[i];
				}
				cout << endl;
			}
			else
			cout << "桌上已经没有牌了 " << endl;

		}
		else
		{
			cout << "小哈win " << endl;
			cout << "小哈当前手中的牌是: " << endl;
			for (i = q2.head;i <= q2.tail - 1;i++)
				cout<<"  "<< q2.data[i];
			cout << endl;
			if (s.top>0) //如果桌上有牌则依次输出桌上的牌  
			{
				cout << "桌上的牌是 " << endl;
				for (i = 1;i <= s.top;i++)
				cout <<"  "<< s.data[i] ;
				cout << endl;

			}
			else
			cout << "桌上已经没有牌了 " << endl;


		}
		getchar();

	}




