#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fenzi,fenmu;     //change      新的全局变量    储存分数的分子分母 
int ans;             //change      改为全局变量 
/*
  功能：菜单
*/
void Menu()
{
	printf("---------------------------------------------------------------------------------\n");
	printf("***************************欢迎使用小学生四则运算软件!***************************\n");
	printf("*****************Welcome to use the arithmetic device for pupils!****************\n");
	printf("---------------------------------------------------------------------------------\n\n");
	printf("本程序支持分数运算，请输入化简后的分数答案，如1/2,3/5,-4/7\n");
	printf("This procedure supports fractional operation, please enter the simplified answer,suach as 1/2,3/5,-4/7\n\n\n");
	printf("   请输入你想要使用的语言.\n");
	printf("  Please enter the language you want to use.\n\n");
	printf("   1.中文         2.English\n\n"); 
}
void Chinese()
{

	printf("请输入想要生成题目数量.\n"); 
} 
void English()
{

	printf("Plese scanf the number of topics you want.\n");
}
/*
  功能：随机生成算式 
*/ 
int equation(int a)
{   
    int chengchu1(int n[5],int op[4]);       //change    chengchu函数之一 
    int ans; 
	int userans;
    int n[5];//四个随机数 
    int op[4];//三个随机运算符 
    int userfenzi;                             //change      用户输入的分子 
	int userfenmu;                           //change         用户分母 
    char operation[4]={'+','-','*','/'};
    char chuhao;
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
	//防止出现除数为0的情况                  //change      原来令0为1  改成这样数据更随机 
	if(op[1]==3&&n[2]==0) n[2]=rand()%10+1;
	if(op[2]==3&&n[3]==0) n[3]=rand()%10+1;
	if(op[3]==3&&n[4]==0) n[4]=rand()%10+1;
	//防止出现答案不为整数的情况；           //change   删掉了 
	
	
	
	//ans=chengchu(n,op);                    //change   答案小于零我们的程序也可以做  
	//if(ans>=0)
	//{
	//printf("题目:%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
	//}
	//else {
	//equation();
	//printf("erro!\n");
	
	
	switch(0)                             //change   swith(rand()%5)    加入了括号的考虑 
		{
			case 0:
			{
				printf("%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]); 
				ans=chengchu1(n,op);          //change       chengchu函数之一 还要写5个 
				break;  	
			}
			case 1:printf("(%d%c%d)%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 2:printf("%d%c(%d%c%d%)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 3:printf("%d%c%d%c(%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;	
			case 4:printf("(%d%c%d%c%d)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 5:printf("%d%c(%d%c%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
		}
   	if(ans==10001)                                //change       根据有没有分数运算 有不同的用户输入和程序输出 
   	{
   		scanf("%d%c",&userfenzi,&chuhao);
   		
   		if(chuhao=='/')
		   {
		   scanf("%d",&userfenmu); 
   		if(userfenzi==fenzi&&userfenmu==fenmu)
   		{
			if(a==1)printf("答对了!\n");
			else if(a==2) printf("You r right!\n");
			return 1;
		}
		else
		{
			if(a==1) printf("答错了……%d/%d\n",fenzi,fenmu);
   			else if(a==2) printf("Your are wrong... %d/%d\n",fenzi,fenmu);
			return 0;
		}
	}
		else
   		{
   			if(a==1) printf("答错了……%d/%d\n",fenzi,fenmu);
   			else if(a==2) printf("Your are wrong... %d/%d\n",fenzi,fenmu);
   			return 0;
   		}
	
	}
	else
	{  
		scanf("%d%c",&userans,&chuhao);
		if(chuhao=='\n')
		{
		if(userans==ans)
		{
		if(a==1)printf("答对了!\n");
			else if(a==2) printf("You r right!\n");
			return 1;
		}
		else
		{
				if(a==1) printf("答错了……%d\n",ans);
   			else if(a==2) printf("Your are wrong... %d\n",ans);
			return 0;
   		}
   	    }
   	    else
   	    {
   	    	scanf("%d",&userfenmu);
   	    	if(a==1) printf("答错了……%d\n",ans);
   			else if(a==2) printf("Your are wrong... %d\n",ans);
   	    }
   	}
} 
/*
蠢方法算计算答案
*/ 
int chengchu1(int n[5],int op[4])          //change   chengchu函数之一 
{
	int fenshuhuajian();
	int flag=0;
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+(n[3]*n[4]);
			    if(op[3]==3)
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();                //分数化简函数 
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4]+n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]+(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]-n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])+(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=(n[1]*n[2])-n[3]+n[4];
			    if(op[3]==1) ans=(n[1]*n[2])-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]*n[2]*n[3])+n[4];
			    if(op[3]==1) ans=(n[1]*n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]*n[2]*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[2]+n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				} 
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[3]+n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[3]-n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[2]*n[3]*n[4]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=(n[4]-n[3])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(-n[3]-n[4])*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]-n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[2]*n[4]+n[1]*n[3];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			    {
			    	fenzi=n[1]+n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-n[2]*n[3]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)               //根据是否有分数计算  返回不同值 
	return 10001; 
	else
	return ans;	
}
/*
分数化简函数
*/
int fenshuhuajian()
{
	int common(int m,int n);         //计算最大公因数 
	int yinshu;
	if(fenzi==0)                        //分数为0 
	{
		ans=0;
		return 0;
	}
	if(fenzi%fenmu==0)                   //分数可以化成整数 
	{
		ans=fenzi/fenmu;
		return 0;
	}
	else
	{   
		yinshu=common(fenzi,fenmu);
		fenzi=fenzi/yinshu;
		fenmu=fenmu/yinshu;
		if((fenzi>0&&fenmu<0)||(fenzi<0&&fenmu<0))                 // 防止输出 4/-7  和 -5/-6   的情况 
		{
			fenzi=-fenzi;
			fenmu=-fenmu;
		}
		return 1;
	}
} 
/*
计算最大公因数 
*/
int common(int m,int n)
{
	int a,b,temp;
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	a=m;
	b=n;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return(a);
}
 

 
void Cresult(int num,int a)
{
	int score=0,i;
	for(i=0;i<num;i++)
	{
		score=score+equation(a);
	}
	printf("\n你做了%d道题，答对了%d道题，答错了%d道题\n",num,score,num-score);
}
void Eresult(int num,int a)
{
	int score=0,i;
	for(i=0;i<num;i++)
	{
		score=score+equation(a);
	}
	printf("\nYou have done %d questions,%d questions were corret,%d were wrong.\n",num,score,num-score);
}
/*
主程序
*/ 
int main()
{
	int a,num;
	Menu();
	scanf("%d",&a);
	if(a==1) 
	{
	  Chinese();
	  scanf("%d",&num);
	  Cresult(num,a);
    }
    if(a==2)
    {
    	English();
    	scanf("%d",&num);
    	Eresult(num,a);
    }
	return 0;
}
	
	

 
