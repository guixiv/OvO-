#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
char *p;
int fenzi, fenmu, a;
int ans;


int readFile(char *q)
{
	int b;
	FILE *fp;
	char c[10000];
	fp = fopen(q, "r");
	fgets(c, 10000, fp);
	int a = atoi(c);
	fclose(fp);
	return a;
}


void writeFile(char b[1000])
{
	FILE *fp;
	fp = fopen(p, "r");
	fputs(b, fp);
	fputs("\n", fp);
	fclose(fp);
}


/*
功能:随机生成数字
*/
void randomNumber(int n[5])
{
	srand(time(NULL));
	n[1] = rand() % 11; n[2] = rand() % 11; n[3] = rand() % 11; n[4] = rand() % 11;
}


/*
功能：随机生成符号
*/
void randomOperation(int op[4])
{
	srand(time(NULL));
	op[1] = rand() % 4; op[2] = rand() % 4; op[3] = rand() % 4;
}

/*
语言选择
*/
int scan()
{
	int a;
	char mm1[] = "miu这种语言啦\n";
	char mm2[] = "再给你一次机会\n";
	cin >> a;
	char m[10];
	sprintf(m, "%d", a);
	writeFile(m);
	if (a<1 || a>5)
	{
		cout << mm1 << endl;
		writeFile(mm1);
		cin >> a;
		char w[10];
		sprintf(w, "%d", a);
		writeFile(w);
	}
	if (a<1 || a>5)
	{
		cout << mm2 << endl;
		writeFile(mm2);
		cin >> a;
		char w[10];
		sprintf(w, "%d", a);
		writeFile(w);
	}
	return a;
}

/*
语言
*/
void lan(int a, int b)
{
	char language[1000];
	if (a == 1) strcpy(language, "C:\\Users\\tongni\\Desktop\\text\\Chinese.txt");
	if (a == 2) strcpy(language, "C:\\Users\\tongni\\Desktop\\text\\English.txt");
	if (a == 3) strcpy(language, "C:\\Users\\tongni\\Desktop\\text\\Japanese.txt");
	if (a == 4) strcpy(language, "C:\\Users\\tongni\\Desktop\\text\\Franch.txt");
	if (a == 5) strcpy(language, "C:\\Users\\tongni\\Desktop\\text\\German.txt");
	int line = 1;
	FILE * p = fopen(language, "r");
	char StrLine[100];
	if ((p = fopen(language, "r")) == NULL)printf("Something Wrong...\n");
	while (!feof(p))
	{
		if (line == b)
		{
			fgets(StrLine, 100, p);
			cout << StrLine << endl;
			writeFile(StrLine);
		}
		fgets(StrLine, 100, p);
		line++;
	}
	fclose(p);
}

/*
蠢方法算计算答案
*/
int calculateResult1(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] + (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[3] + (n[1] + n[2])*n[4];
				fenmu = n[4];
				flag = fenshuhuajian();                //分数化简函数 
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] - (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = (n[1] + n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] + (n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = n[1] + (n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] + (n[2] * n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = (n[1] + n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[1] - n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] + n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[4] + n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] - n[2] + (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] - n[2] - (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] - (n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = n[1] - (n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] - (n[2] * n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = (n[1] + n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[1] - n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[4] - n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] + n[3] - n[4];
			if (op[3] == 2) ans = (n[1] * n[2]) + (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = (n[1] * n[2]) - n[3] + n[4];
			if (op[3] == 1) ans = (n[1] * n[2]) - n[3] - n[4];
			if (op[3] == 2) ans = (n[1] * n[2]) - (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = (n[1] * n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = (n[1] * n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] * n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[2] + n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[2] - n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0)
			{
				fenzi = (n[3] + n[4])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[3] - n[4])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[2] * n[3] * n[4] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0)
			{
				fenzi = (n[4] - n[3])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (-n[3] - n[4])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] - n[2] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[2] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0)
			{
				fenzi = n[2] * n[4] + n[1] * n[3];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + n[2] * n[3] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[2] * n[3] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)               //根据是否有分数计算  返回不同值 
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}


int calculateResult2(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[3] + (n[1] + n[2])*n[4];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] + n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = (n[1] + n[2])*n[3] + n[4];
			if (op[3] == 1) ans = (n[1] + n[2])*n[3] - n[4];
			if (op[3] == 2) ans = (n[1] + n[2])*n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] + n[2])*n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[4] * n[3] + n[1] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] + n[2] - (n[3] * n[4]);
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] + n[2])*n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] + n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] - n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] - n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = (n[1] - n[2])*n[3] + n[4];
			if (op[3] == 1) ans = (n[1] - n[2])*n[3] - n[4];
			if (op[3] == 2) ans = (n[1] - n[2])*n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[4] * n[3] + n[1] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[2] - (n[3] * n[4]);
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] - n[2])*n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] - n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] * n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] * n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] * n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] * n[2] * n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] * n[3] - n[4];
			if (op[3] == 2) ans = n[1] * n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[4] * n[3] + n[1] * n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[2] - n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + (n[3] + n[4])*n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] + (n[3] - n[4])*n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] + n[2] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[3] * n[2];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] - n[3] * n[2] + n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[3] * n[2] - n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] - n[3] * n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[3] * n[2];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[3] + n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3] - n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + n[4] * n[2] * n[3];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[4] * n[2] * n[3];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] / n[2] / n[3] / n[4];
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}


int calculateResult3(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + (n[2] + n[3]) + n[4];
			if (op[3] == 1) ans = n[1] + (n[2] + n[3]) - n[4];
			if (op[3] == 2) ans = n[1] + (n[2] + n[3])*n[4];
			if (op[3] == 3) ans = n[1] + (n[2] + n[3]) / n[4];
			{
				fenzi = n[2] + n[3] + n[1] * n[4];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + (n[2] - n[3]) + n[4];
			if (op[3] == 1) ans = n[1] + (n[2] - n[3]) - n[4];
			if (op[3] == 2) ans = n[1] + (n[2] - n[3])*n[4];
			if (op[3] == 3) ans = n[1] + (n[2] - n[3]) / n[4];
			{
				fenzi = n[1] * n[4] + n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] + (n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = n[1] + (n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] + (n[2] * n[3])*n[4];
			if (op[3] == 3) ans = n[1] + (n[2] * n[3]) / n[4];
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0) ans = n[1] + (n[2] / n[3]) + n[4];
			{
				fenzi = (n[1] + n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] + (n[2] / n[3]) - n[4];
			{
				fenzi = (n[1] - n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] + (n[2] / n[3])*n[4];
			{
				fenzi = n[1] * n[3] + n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] + (n[2] / n[3]) / n[4];
			{
				fenzi = n[1] * n[3] * n[4] + n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - (n[2] + n[3]) + n[4];
			if (op[3] == 1) ans = n[1] - (n[2] + n[3]) - n[4];
			if (op[3] == 2) ans = n[1] - (n[2] + n[3])*n[4];
			if (op[3] == 3) ans = n[1] - (n[2] + n[3]) / n[4];
			{
				fenzi = n[1] * n[4] - n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - (n[2] - n[3]) + n[4];
			if (op[3] == 1) ans = n[1] - (n[2] - n[3]) - n[4];
			if (op[3] == 2) ans = n[1] - (n[2] - n[3])*n[4];
			if (op[3] == 3) ans = n[1] - (n[2] - n[3]) / n[4];
			{
				fenzi = n[1] * n[4] - n[2] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] - (n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = n[1] - (n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] - (n[2] * n[3])*n[4];
			if (op[3] == 3) ans = n[1] - (n[2] * n[3]) / n[4];
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0) ans = n[1] - (n[2] / n[3]) + n[4];
			{
				fenzi = (n[1] + n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] - (n[2] / n[3]) - n[4];
			{
				fenzi = (n[1] - n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] - (n[2] / n[3])*n[4];
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] - (n[2] / n[3]) / n[4];
			{
				fenzi = n[1] * n[3] * n[4] - n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * (n[2] + n[3]) + n[4];
			if (op[3] == 1) ans = n[1] * (n[2] + n[3]) - n[4];
			if (op[3] == 2) ans = n[1] * (n[2] + n[3])*n[4];
			if (op[3] == 3) ans = n[1] * (n[2] + n[3]) / n[4];
			{
				fenzi = n[1] * (n[2] + n[3]);
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] * (n[2] - n[3]) + n[4];
			if (op[3] == 1) ans = n[1] * (n[2] - n[3]) - n[4];
			if (op[3] == 2) ans = n[1] * (n[2] - n[3])*n[4];
			if (op[3] == 3) ans = n[1] * (n[2] - n[3]) / n[4];
			{
				fenzi = n[1] * (n[2] - n[3]);
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] * (n[2] * n[3]) + n[4];
			if (op[3] == 1) ans = n[1] * (n[2] * n[3]) - n[4];
			if (op[3] == 2) ans = n[1] * (n[2] * n[3])*n[4];
			if (op[3] == 3) ans = n[1] * (n[2] * n[3]) / n[4];
			{
				fenzi = n[1] * n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0) ans = n[1] * (n[2] / n[3]) + n[4];
			{
				fenzi = n[1] * n[2] + n[4] * n[3];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] * (n[2] / n[3]) - n[4];
			{
				fenzi = n[1] * n[2] - n[4] * n[3];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] * (n[2] / n[3])*n[4];
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] * (n[2] / n[3]) / n[4];
			{
				fenzi = n[1] * n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] / (n[2] + n[3]) + n[4];
			{
				fenzi = n[1] + (n[2] + n[3])*n[4];
				fenmu = n[2] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] / (n[2] + n[3]) - n[4];
			{
				fenzi = n[1] + (n[2] + n[3])*n[4];
				fenmu = n[2] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] / (n[2] + n[3])*n[4];
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] / (n[2] + n[3]) / n[4];
			{
				fenzi = n[1];
				fenmu = (n[2] + n[3])*n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] / (n[2] - n[3]) + n[4];
			{
				fenzi = n[1] + (n[2] - n[3])*n[4];
				fenmu = n[2] - n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] / (n[2] - n[3]) - n[4];
			{
				fenzi = n[1] - (n[2] - n[3])*n[4];
				fenmu = n[2] - n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] / (n[2] - n[3])*n[4];
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] - n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] / (n[2] - n[3]) / n[4];
			{
				fenzi = n[1];
				fenmu = (n[2] - n[3])*n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] / (n[2] * n[3]) + n[4];
			{
				fenzi = n[1] + n[4] * n[2] * n[3];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] / (n[2] * n[3]) - n[4];
			{
				fenzi = n[1] - n[4] * n[2] * n[3];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] / (n[2] * n[3])*n[4];
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] / (n[2] * n[3]) / n[4];
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0) ans = n[1] / (n[2] / n[3]) + n[4];
			{
				fenzi = n[1] * n[3] + n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1) ans = n[1] / (n[2] / n[3]) - n[4];
			{
				fenzi = n[1] * n[3] - n[4] * n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2) ans = n[1] / (n[2] / n[3])*n[4];
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3) ans = n[1] / (n[2] / n[3]) / n[4];
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}


int calculateResult4(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[3] + (n[1] + n[2])*n[4];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + n[2] - (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] + n[2] - (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] + n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] + n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] + n[2] * (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] + n[2] * (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] + n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * (n[3] + n[4]) + n[2];
				fenmu = n[4] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * (n[3] - n[4]) + n[2];
				fenmu = n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * (n[3] * n[4]) + n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] + n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] - n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - n[2] - (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] - n[2] - (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] - n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] - n[2] * (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] - n[2] * (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] - n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * (n[3] + n[4]) - n[2];
				fenmu = n[4] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * (n[3] - n[4]) - n[2];
				fenmu = n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] * n[4] - n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] * n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] * n[2] - (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] * n[2] - (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] * n[2] - (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] * n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] * n[2] * (n[3] + n[4]);
			if (op[3] == 1) ans = n[1] * n[2] * (n[3] - n[4]);
			if (op[3] == 2) ans = n[1] * n[2] * (n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[2];
				fenmu = n[4] + n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[2];
				fenmu = n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0)
			{
				fenzi = (n[3] + n[4])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[3] - n[4])*n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[3] * n[4] * n[2] + n[1];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4] * n[2];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] - n[2] * (n[3] + n[4]);
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[2] * (n[3] - n[4]);
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] - n[2] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[2] * n[3];
				fenmu = n[4] * n[2];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * (n[3] + n[4]);
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * (n[3] - n[4]);
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3];
				fenmu = n[4] * n[2];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1];
				fenmu = n[2] * (n[3] + n[4]);
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1];
				fenmu = n[2] * (n[3] - n[4]);
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4];
				fenmu = n[3] * n[2];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}


int calculateResult5(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] + n[3] - n[4];
			if (op[3] == 2) ans = (n[1] + n[2] + n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] + n[2] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] - n[3] - n[4];
			if (op[3] == 2) ans = (n[1] + n[2] - n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] + n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] + n[2] * n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] * n[3] - n[4];
			if (op[3] == 2) ans = (n[1] + n[2] * n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[3] + n[2 + n[3] * n[4]];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3] + n[2] - n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] * n[3] + n[2])*n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] + n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] + n[3] - n[4];
			if (op[3] == 2) ans = (n[1] - n[2] + n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] - n[2] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] - n[3] - n[4];
			if (op[3] == 2) ans = (n[1] - n[2] - n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] - n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] - n[2] * n[3] + n[4];
			if (op[3] == 1) ans = n[1] - n[2] * n[3] - n[4];
			if (op[3] == 2) ans = (n[1] - n[2] * n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] - n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[3] - n[2] + n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3] - n[2] - n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] * n[3] - n[2])*n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] - n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] + n[3] - n[4];
			if (op[3] == 2) ans = (n[1] * n[2] + n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] * n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] - n[3] - n[4];
			if (op[3] == 2) ans = (n[1] * n[2] - n[3])*n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] * n[2] * n[3] + n[4];
			if (op[3] == 1) ans = n[1] * n[2] * n[3] - n[4];
			if (op[3] == 2) ans = n[1] * n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[2] + n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[2] - n[3] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2];
				fenmu = n[4] * n[3];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + n[2] * n[3] + n[2] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] + n[2] * n[3] - n[2] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] + n[2] * n[3])*n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] + n[2] * n[3];
				fenmu = n[4] * n[2];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + (n[4] - n[3])*n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - (n[3] + n[4])*n[2];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = (n[1] - n[2] * n[3])*n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] - n[2] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[3] + n[2] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] + n[2] * n[3] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] - n[2] * n[3] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}


int calculateResult6(int n[5], int op[4])
{
	int fenshuhuajian();
	int flag = 0;
	if (op[1] == 0)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] + n[2] + n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] + n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] + n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[3] + (n[1] + n[2])*n[4];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] + n[2] - n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] - n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] - n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = (n[1] + n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] + n[2] * n[3] + n[4];
			if (op[3] == 1) ans = n[1] + n[2] * n[3] - n[4];
			if (op[3] == 2) ans = n[1] + n[2] * n[3] * n[4];
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] + n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = (n[1] + n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[1] - n[4])*n[3] + n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] + n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[4] + n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 1)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] - (n[2] + n[3] + n[4]);
			if (op[3] == 1) ans = n[1] - (n[2] + n[3] - n[4]);
			if (op[3] == 2) ans = n[1] - (n[2] + n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] - n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] - (n[2] - n[3] + n[4]);
			if (op[3] == 1) ans = n[1] - (n[2] - n[3] - n[4]);
			if (op[3] == 2) ans = n[1] - (n[2] - n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = (n[1] - n[2])*n[4] + n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] - (n[2] * n[3] + n[4]);
			if (op[3] == 1) ans = n[1] - (n[2] * n[3] - n[4]);
			if (op[3] == 2) ans = n[1] - (n[2] * n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4] - n[2] * n[3];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = (n[1] - n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = (n[1] + n[4])*n[3] - n[2];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3] - n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[4] - n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 2)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0) ans = n[1] * (n[2] + n[3] + n[4]);
			if (op[3] == 1) ans = n[1] * (n[2] + n[3] - n[4]);
			if (op[3] == 2) ans = n[1] * (n[2] + n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * (n[2] * n[4] + n[3]);
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0) ans = n[1] * (n[2] - n[3] + n[4]);
			if (op[3] == 1) ans = n[1] * (n[2] - n[3] - n[4]);
			if (op[3] == 2) ans = n[1] * (n[2] - n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * (n[2] * n[4] - n[3]);
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0) ans = n[1] * (n[2] * n[3] + n[4]);
			if (op[3] == 1) ans = n[1] * (n[2] * n[3] - n[4]);
			if (op[3] == 2) ans = n[1] * (n[2] * n[3] * n[4]);
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[2];
				fenmu = n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * (n[2] + n[3] * n[4]);
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * (n[2] - n[3] * n[4]);
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[2] * n[4];
				fenmu = n[3];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[2];
				fenmu = n[3] * n[4];
				flag = fenshuhuajian();
			}
		}
	}
	if (op[1] == 3)
	{
		if (op[2] == 0)
		{
			if (op[3] == 0)
			{
				fenzi = n[1];
				fenmu = n[2] + n[3] + n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1];
				fenmu = n[2] + n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1];
				fenmu = n[2] + n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4];
				fenmu = n[3] + n[2] * n[4];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 1)
		{
			if (op[3] == 0)
			{
				fenzi = n[1];
				fenmu = n[2] - n[3] + n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1];
				fenmu = n[2] - n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1];
				fenmu = n[2] - n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[4] - n[3];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 2)
		{
			if (op[3] == 0)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] + n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] - n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1];
				fenmu = n[2] * n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[4];
				fenmu = n[2] * n[3];
				flag = fenshuhuajian();
			}
		}
		if (op[2] == 3)
		{
			if (op[3] == 0)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] + n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 1)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] - n[3] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 2)
			{
				fenzi = n[1] * n[3];
				fenmu = n[2] * n[4];
				flag = fenshuhuajian();
			}
			if (op[3] == 3)
			{
				fenzi = n[1] * n[3] * n[4];
				fenmu = n[2];
				flag = fenshuhuajian();
			}
		}
	}
	if (flag == 1)
		return 10001;
	if (flag == 0)
		return ans;
	if (flag == 2)
		return 10002;
}

int generateExpression()
{
	int n[5] = { 0 };
	int op[4] = { 0 };
	char express[100];
	char operation[4] = { '+','-','*','/' };
	randomNumber(n);
	randomOperation(op);
	int kh = rand() % 5;
	switch (kh)
	{
	case 0:ans = calculateResult1(n, op);
		break;
	case 1:ans = calculateResult2(n, op);
		break;
	case 2:ans = calculateResult3(n, op);
		break;
	case 3:ans = calculateResult4(n, op);
		break;
	case 4:ans = calculateResult5(n, op);
		break;
	case 5:ans = calculateResult6(n, op);
	}
	if (ans != 1002) {
		switch (kh)
		{
		case 0:
			cout << n[1] << operation[op[1]] << n[2] << operation[op[2]] << n[3] << operation[op[3]] << n[4] << '=';
			sprintf(express, "%d%c%d%c%d%c%d=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);
			break;
		case 1:
			cout << '(' << n[1] << operation[op[1]] << n[2] << ')' << operation[op[2]] << n[3] << operation[op[3]] << n[4] << '=';
			sprintf(express, "(%d%c%d)%c%d%c%d=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);
			break;
		case 2:
			cout << n[1] << operation[op[1]] << '(' << n[2] << operation[op[2]] << n[3] << ')' << operation[op[3]] << n[4] << '=';
			sprintf(express, "%d%c(%d%c%d)%c%d=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);
			break;
		case 3:
			cout << n[1] << operation[op[1]] << n[2] << operation[op[2]] << '(' << n[3] << operation[op[3]] << n[4] << ')' << '=';
			sprintf(express, "%d%c%d%c(%d%c%d)=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);
			break;
		case 4:
			cout << '(' << n[1] << operation[op[1]] << n[2] << operation[op[2]] << n[3] << ')' << operation[op[3]] << n[4] << '=';
			sprintf(express, "(%d%c%d%c%d)%c%d=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);
			break;
		case 5:
			cout << n[1] << operation[op[1]] << '(' << n[2] << operation[op[2]] << n[3] << operation[op[3]] << n[4] << ')' << '=';
			sprintf(express, "%d%c(%d%c%d%c%d)=", n[1], operation[op[1]], n[2], operation[op[2]], n[3], operation[op[3]], n[4]);	
		}
		writeFile(express);
		return 1;
	}
	else return 0;
}
/*
生成表达式
*/


/*
分数化简函数
*/
int fenshuhuajian()
{
	int common(int m, int n);       //计算最大公因数 
	int yinshu;
	if (fenmu == 0)
	{
		return 2;
	}
	if (fenzi == 0)                        //分数为0 
	{
		ans = 0;
		return 0;
	}
	else if (fenzi%fenmu == 0)                   //分数可以化成整数 
	{
		ans = fenzi / fenmu;
		return 0;
	}
	else
	{
		yinshu = common(fenzi, fenmu);
		fenzi = fenzi / yinshu;
		fenmu = fenmu / yinshu;
		if ((fenzi>0 && fenmu<0) || (fenzi<0 && fenmu<0))                 // 防止输出 4/-7  和 -5/-6   的情况 
		{
			fenzi = -fenzi;
			fenmu = -fenmu;
		}
		return 1;
	}
}

/*
计算最大公因数
*/
int common(int m, int n)
{
	int a, b, temp;
	if (m<n)
	{
		temp = m;
		m = n;
		n = temp;
	}
	a = m;
	b = n;
	while (b != 0)
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return(a);
}

/*
计算结果
*/

void Menu()
{
	cout << "---------------------------------------------------------------------------------\n" <<
		("*****************Welcome to use the arithmetic device for pupils!****************\n") <<
		("*******        1Chinese  2English  3Japanese  4Franch  5German       **********\n") <<
		("---------------------------------------------------------------------------------\n") << endl;

}

/*
判断用户的答案是否正确
*/

int compare(int a)
{
	char anser[50];
	if (ans != 10002 && ans != 10001)
	{
		sprintf(anser, "%d", ans);
	}
	if (ans == 10001)
	{
		sprintf(anser, "%d/%d", fenzi, fenmu);
	}
	char userans[50];
	cin >> userans;
	if (strcmp(anser, userans) == 0)
	{
		lan(a, 2);
		return 1;
	}
	else if (userans[0] == 'e')
	{
		return 3;
	}
	else
	{
		lan(a, 3);
		cout << anser << endl;
		writeFile(anser);
		return 0;
	}
}


int main(int argc, char *argv[])
{
	int a, num, score = 0, TF;
	Menu();
	a = scan();
	num = readFile(argv[1]);
	char *p = argv[2];
	for (int i = 1; i <= num; i++)
	{
		int m = generateExpression();
		if (m == 0)
		{
			i--;
			break;
		}
		else {
			int w = compare(a);
			if (w == 3) {
				num = i;
			}
			else if (w == 1) score++;
		}
	}
	lan(a, 4);
	cout << num << endl;
	char num1[100];
	sprintf(num1, "%d", num);
	writeFile(num1);
	lan(a, 5);
	cout << score << endl;
	char num2[100];
	sprintf(num2, "%d", score);
	writeFile(num2);
	lan(a, 6);
	cout << num - score << endl;
	char num3[100];
	sprintf(num3, "%d", num-score);
	writeFile(num3);
	return 0;
}
