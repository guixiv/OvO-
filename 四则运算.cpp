#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
  功能：获得题目数量 
*/ 
void Menu()
{
	int num;
	printf("欢迎使用小学生四则运算软件\n");
	printf("请输入想要生成题目数量\n"); 
} 

/*
  功能：随机生成算式 （括号问题还未考虑） 
*/ 
int equation()
{   
    int chengchu(int n[5],int op[4]);
    int ans; int userans;
    int n[5];//四个随机数 
    int op[4];//三个随机运算符 
    char operation[4]={'+','-','*','/'};
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
	//防止出现除数为0的情况 
	if(op[1]==3&&n[2]==0) n[2]=1;
	if(op[2]==3&&n[3]==0) n[3]=1;
	if(op[3]==3&&n[4]==0) n[4]=1;
	//防止出现答案不为整数的情况； 
	if(op[1]==3) n[1]=n[1]*n[2];
	if(op[2]==3) n[2]=n[2]*n[3];
	if(op[3]==3) n[3]=n[3]*n[4];
	ans=chengchu(n,op);
	if(ans>=0)
	{
	printf("题目:%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
	}
	else {
	equation();
	printf("erro!\n");
   }
	scanf("%d",&userans);
	if(userans==ans)
	{
	printf("答对了!\n");
	return 1;
	}
	else
	{
	printf("答错了...%d\n",ans);
	return 0;
   }
} 
/*
蠢方法算计算答案
*/ 
int chengchu( int n[5],int op[4])
{
	int ans;
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]+n[2]+(n[3]/n[4]);
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]+n[2]-(n[3]/n[4]);
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]*n[3]*n[4]);
			    if(op[3]==3) ans=n[1]+(n[2]*n[3]/n[4]);
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]+(n[2]/n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]/n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]/n[3]*n[4]);
			    if(op[3]==3) ans=n[1]+(n[2]/n[3]/n[4]);
		}
	}
	    	if(op[1]==1)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]-n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]+(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]-n[2]+(n[3]/n[4]);
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]-n[2]-(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]-n[2]-(n[3]/n[4]);
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]*n[3]*n[4]);
			    if(op[3]==3) ans=n[1]-(n[2]*n[3]/n[4]);
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]-(n[2]/n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]/n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]/n[3]*n[4]);
			    if(op[3]==3) ans=n[1]-(n[2]/n[3]/n[4]);
		}
	}
			if(op[1]==2)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]*n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])+(n[3]*n[4]);
			    if(op[3]==3) ans=(n[1]*n[2])+(n[3]/n[4]);
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=(n[1]*n[2])-n[3]+n[4];
			    if(op[3]==1) ans=(n[1]*n[2])-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2])-(n[3]*n[4]);
			    if(op[3]==3) ans=(n[1]*n[2])-(n[3]/n[4]);
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]*n[2]*n[3])+n[4];
			    if(op[3]==1) ans=(n[1]*n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]*n[2]*n[3]*n[4];
			    if(op[3]==3) ans=n[1]*n[2]*n[3]/n[4];
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=(n[1]*n[2]/n[3])+n[4];
			    if(op[3]==1) ans=(n[1]*n[2]/n[3])-n[4];
			    if(op[3]==2) ans=n[1]*n[2]/n[3]*n[4];
			    if(op[3]==3) ans=n[1]*n[2]/n[3]/n[4];
		}
	}
		if(op[1]==3)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]/n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]/n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]/n[2]+(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]/n[2]+(n[3]/n[4]);
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]/n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]/n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]/n[2]-(n[3]*n[4]);
			    if(op[3]==3) ans=n[1]/n[2]-(n[3]/n[4]);
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]/n[2]*n[3])+n[4];
			    if(op[3]==1) ans=(n[1]/n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]/n[2]*n[3]*n[4];
			    if(op[3]==3) ans=n[1]/n[2]*n[3]/n[4];
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]/n[2]/n[3]+n[4];
			    if(op[3]==1) ans=n[1]/n[2]/n[3]-n[4];
			    if(op[3]==2) ans=n[1]/n[2]/n[3]*n[4];
			    if(op[3]==3) ans=n[1]/n[2]/n[3]/n[4];
		}
	}	
	return ans; 
	
}
/*
还在探索中的方法 
int chengchu(int ans,int i,int n[5],int op[4])
{
	if(i<=4)
	{
	  if(op[i]==0)
	  {
	  	ans=chengchu(ans,i++,n,op)+n[i+1];
	  }
	  if(op[i]==1)
	  {
	  	chengchu(ans,i++,n,op);
	  	ans=ans-n[i+1];
	  }
	  else
	  {
	  	if(op[i]==2) n[i+1]=ans*n[i+1];
	  	if(op[i]==3) n[i+1]=ans/n[i+1];
	    chengchu(ans,i++,n,op);if(i==3) ans=n[4];
	  }

    }
		  return ans;
}
*/

/*
  功能：计算得分（中途终止运算还未考虑） 
*/
void result(int num)
{
	int score=0,i;
	for(i=0;i<num;i++)
	{
		score=score+equation();
	}
	printf("你做了%d道题，答对了%d道题，答错了%d道题\n",num,score,num-score);
}
/*
主程序
*/ 
int main()
{
	int num;
	Menu();
	scanf("%d",&num);
	result(num);
	return 0;
}
	
	

 
