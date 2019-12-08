// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<cstdio>
#include<cmath>
#include"windows.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
class Get {
private:
	string* p = new string[100];
	string* q = new string[100];
	int s = 0, c = 0;
public:
	~Get(){ delete[] p;
	delete[] q; }
	void getrules();
	void printf1();
	int get_s() {
		return s;
	}
	int get_c() { return c; }
	string* get_p() { return p; }
	string* get_q() { return q; }
};
void Get::getrules()
{
	int flag = 0, l; char m = 0;
	cout << "请选择规则性质（1.奖励 2.惩罚）" << endl;
	cin >> l;
	while (flag == 0)
	{
		if (l == 1)
		{
			cout << "请输入奖励规则内容" << endl;
			cin >> p[s];
			cout << "是否继续添加？Y||y||N||n" << endl;
			char m;
			cin >> m;
			while (m)
			{
				if (m == 'y' || m == 'Y')
				{
					s++;
					cin >> p[s];
					cout << "是否继续添加？Y||y||N||n" << endl;
					cin >> m;
					cout << "请输入奖励规则内容" << endl;
				}
				else if (m == 'n' || m == 'N')
				{
					cout << "是否加入惩罚规则" << endl;
					char e;
					cin >> e;
					if (e == 'y' || e == 'Y')

					{
						l = 2;
						break;
					}
					else
						flag = 1;
					break;
				}
				else
				{
					cout << "格式不正确，请重新输入Y||y,N||n";
					cin >> m;
				}
			}
		}
		else if (l == 2)
		{
			cout << "请输入惩罚规则内容" << endl;
			cin >> q[c];
			cout << "是否继续添加？Y||y||N||n" << endl;
			char m;
			cin >> m;
			while (m)
			{
				if (m == 'y' || m == 'Y')
				{
					c++;
					cin >> q[c];
					cout << "是否继续添加？Y||y||N||n" << endl;
					cin >> m;
					cout << "请输入惩罚规则内容" << endl;

				}
				else if (m == 'n' || m == 'N')
				{
					cout << "是否加入奖励规则" << endl;
					cin >> m;
					if (m == 'y' || m == 'Y')
					{
						l = 1;
						break;
					}
					else
					{
						flag = 1;
						break;
					}
				}
				else
				{
					cout << "格式不正确，请重新输入Y||y,N||n";
					cin >> m;
				}
			}
		}


	}
}
void Get::printf1()
{
	cout << s;
	cout << "-----------规则如下--------------------" << endl;
	cout << "-----------奖励规则--------------------" << endl;
	for (int a = 0; a <= s; a++) 
	{
		cout << a + 1 << '.' << p[a] << endl;
	}
	cout << "---------------惩罚规则----------------" << endl;
	for (int a = 0; a <= c; a++)
	{
		cout << a + 1 << '.' << q[a] << endl;
	}
}
double getG(int* a, int n);
void getdif(double* a, double* b, int n);
void end(double* b, int* compare, int n);
void rank1(int* score, int* c, int* d, int n);
int main()
{
	cout << "********************************************************" << endl;
	cout << "********************欢迎来到黄金点游戏******************" << endl;
	cout << "********************************************************" << endl;
	cout << "按任意键继续" << endl;
	getchar();
	int i, n, m, j;
	double a[20], b[20]; //a保存数字，b保存差值,c保存b数组的值,d为排好序的下标
	int score[20], d[20], c[20];
	int compare[2] = { 0,0 };
	Get A;
	for (i = 0; i < 20; i++)
	{
		a[i] = 0;
		score[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
	}
	cout << "是否添加规则？" << endl;
	char k;
	cin >> k;
	while (k)
	{
		if (k == 'y' || k == 'Y')
		{
			A.getrules();
			break;
		}
		else if (k == 'n' || k == 'N')
		{
			break;
		}
		else
		{
			cout << "格式不正确，请重新输入Y||y,N||n";
			cin >> k;
		}
	}
	A.printf1();
	printf("请输入共进行几轮：");
	scanf_s("%d", &m);
	printf("请输入玩家人数：");
	scanf_s("%d", &n);
	for (j = 0; j < m; j++)
	{
		printf("开始第%d轮游戏\n", j + 1);
		for (i = 0; i < n; i++)
		{
			printf("请输入第%d个玩家的数字:\n", i + 1);
			scanf_s("%lf", &a[i]);

		}


		for (i = 0; i < n; i++)//计算分数
		{
			getdif(a, b, n);
			end(b, compare, n);


			if (b[i] == b[compare[0]])
				score[i] = score[i] + n;
			else if (b[i] == b[compare[1]])//注意用else if
				score[i] = score[i] - 2;
			printf("%d号玩家分数为:%d\n", i + 1, score[i]);
		}
		system("pause");
		system("cls");
	}
	cout << "-----------成绩总排名-----------\n";
	rank1(score, c, d, n);
	for (i = 0; i < n; i++)
	{
		printf("第%d名:%d号玩家%d\n", i + 1, d[i], score[i]);
	}
	cout << "是否生成奖励惩罚" << endl;
	cin >> k;
	if (k == 'y' || k == 'Y')
	{
		
		int h = rand() % ((A.get_s() + 1));
		string* p = A.get_p();
		cout << p[h]<<endl;
	}
	if (k == 'n' || k == 'N')
	{
		cout << "是否生成惩罚措施" << endl;
		char u;
		cin >> u;
		if (u == 'y' || u == 'Y')
		{
			int h = rand() % (A.get_c() + 1);
			string* q =A.get_q();
			cout << q[h]<<endl;
		}
		if (u == 'N' || u == 'n')
		{
			return 0;
		}
	}
	cout << "********************************************************" << endl;
	cout << "********************游戏结束，谢谢体验******************" << endl;
	cout << "********************************************************" << endl;
}



double getG(double* a, int n) //求G值
{
	int i;
	double sum = 0, ave, G;
	for (i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	ave = sum / n;
	G = ave * 0.618;
	return G;
}


void getdif(double* a, double* b, int n) //将差值存在数组b中,defference，val:差值；
{
	int i;
	double difference, val;
	double c = getG(a, n);
	for (i = 0; i < n; i++)
	{
		difference = a[i] - c;
		val = fabs(difference);
		b[i] = val;
	}

}



void end(double* b, int* compare, int n) //通过比较差值的大小，选出最小和最大的。保存最小值和最大值的下标
{
	int i;
	double max, min;
	max = b[0];
	min = b[0];
	for (i = 0; i < n; i++)
	{
		if (min > b[i])
		{
			min = b[i];
			compare[0] = i;//小
		}
		if (max < b[i])
		{
			max = b[i];
			compare[1] = i;//大
		}
	}

}







void rank1(int* score, int* c, int* d, int n)
{
	int i, q, temp = 0;
	for (i = 0; i < n; i++)
	{
		c[i] = score[i];
	}
	for (i = 1; i < n; i++)
		for (q = 0; q < n - i; q++)	//冒泡排序
			if (score[q] < score[q + 1])
			{
				temp = score[q];
				score[q] = score[q + 1];
				score[q + 1] = temp;
			}


	for (i = 0; i < n; i++)
	{ //数组排序并输出原位置
		for (q = 0; q < n; q++)
		{
			if (score[i] == c[q])
			{
				d[i] = q + 1;
				c[q] = -100;
				break;
			}

		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
