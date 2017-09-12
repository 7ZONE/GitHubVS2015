// CATPokerGame.cpp : �������̨Ӧ�ó������ڵ㡣
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
	
	
		//��ʼ������  
		q1.head = 1;
		q1.tail = 1;
		q2.head = 1; 
		q2.tail = 1;
		//��ʼ��ջ  
		s.top = 0;
		//��ʼ��������ǵ����飬���������Щ���Ѿ�������  
		for (i = 0;i <= 52;i++)
		{
			book[i] = 0;
		}
		//�ֱ���Ʒ���˫��
	
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
		cout << "��ʱС�����е���Ϊ��" << endl;
		for (int i = 1;i <=26; i++)
		{
			cout <<"  " << q1.data[i];
		}
		cout << endl;
		cout << "��ʱС�����е���Ϊ��" << endl;

		for (int i = 1;i <= 26; i++)
		{
			cout<<"  " << q2.data[i];
		}
		cout << endl;

		while (q1.head < q1.tail && q2.head < q2.tail)
		{
			t = q1.data[q1.head];       // ��һ���˳���һ���� ����  
			if (0 == book[t])            // ����û�������� ��ջ  
			{
				s.data[++s.top] = t;
				book[t] = 1;        // ����������Ѿ�������Ϊt����  
				q1.head++;
			}
			else
			{
				q1.data[q1.tail++] = t;         // Ӯ��  
				q1.head++;
				while (s.data[s.top] != t)       // ����ͬ���Ʒŵ�ĳ�������Ƶ�ĩβ  
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


			cout << "С��win " << endl;
			cout << "С�ߵ�ǰ���е�����: " << endl;
			for (i = q1.head;i <= q1.tail - 1;i++)

			{
				cout << "  " << q1.data[i];
			}
			cout << endl;
			
			if (s.top>0) //�����������������������ϵ���  
			{
				cout << "���ϵ����ǣ�" << endl;
				for (i = 1;i <= s.top;i++)
				{
					cout << "  " << s.data[i];
				}
				cout << endl;
			}
			else
			cout << "�����Ѿ�û������ " << endl;

		}
		else
		{
			cout << "С��win " << endl;
			cout << "С����ǰ���е�����: " << endl;
			for (i = q2.head;i <= q2.tail - 1;i++)
				cout<<"  "<< q2.data[i];
			cout << endl;
			if (s.top>0) //�����������������������ϵ���  
			{
				cout << "���ϵ����� " << endl;
				for (i = 1;i <= s.top;i++)
				cout <<"  "<< s.data[i] ;
				cout << endl;

			}
			else
			cout << "�����Ѿ�û������ " << endl;


		}
		getchar();

	}




