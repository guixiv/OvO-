#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
  ���ܣ������Ŀ���� 
*/ 
void Menu()
{
	int num;
	printf("��ӭʹ��Сѧ�������������\n");
	printf("��������Ҫ������Ŀ����\n"); 
} 

/*
  ���ܣ����������ʽ ���������⻹δ���ǣ� 
*/ 
int equation()
{   
    int chengchu(int n[5],int op[4]);
    int ans; int userans;
    int n[5];//�ĸ������ 
    int op[4];//������������ 
    char operation[4]={'+','-','*','/'};
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
	//��ֹ���ֳ���Ϊ0����� 
	if(op[1]==3&&n[2]==0) n[2]=1;
	if(op[2]==3&&n[3]==0) n[3]=1;
	if(op[3]==3&&n[4]==0) n[4]=1;
	//��ֹ���ִ𰸲�Ϊ����������� 
	if(op[1]==3) n[1]=n[1]*n[2];
	if(op[2]==3) n[2]=n[2]*n[3];
	if(op[3]==3) n[3]=n[3]*n[4];
	ans=chengchu(n,op);
	if(ans>=0)
	{
	printf("��Ŀ:%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
	}
	else {
	equation();
	printf("erro!\n");
   }
	scanf("%d",&userans);
	if(userans==ans)
	{
	printf("�����!\n");
	return 1;
	}
	else
	{
	printf("�����...%d\n",ans);
	return 0;
   }
} 
/*
������������
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
����̽���еķ��� 
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
  ���ܣ�����÷֣���;��ֹ���㻹δ���ǣ� 
*/
void result(int num)
{
	int score=0,i;
	for(i=0;i<num;i++)
	{
		score=score+equation();
	}
	printf("������%d���⣬�����%d���⣬�����%d����\n",num,score,num-score);
}
/*
������
*/ 
int main()
{
	int num;
	Menu();
	scanf("%d",&num);
	result(num);
	return 0;
}
	
	

 
