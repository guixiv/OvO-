#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fenzi,fenmu;     //change      �µ�ȫ�ֱ���    ��������ķ��ӷ�ĸ 
int ans;             //change      ��Ϊȫ�ֱ��� 
/*
  ���ܣ������Ŀ���� 
*/ 
void Menu()
{
	int num;
	printf("��ӭʹ��Сѧ�������������\n");
	printf("������֧�ַ������㣬�����뻯���ķ�������1/2,3/5,-4/7\n");
	printf("��������Ҫ������Ŀ����\n"); 
} 
/*
  ���ܣ����������ʽ 
*/ 
int equation()
{   
    int chengchu1(int n[5],int op[4]);       //change    chengchu����֮һ 
    int chengchu6(int n[5],int op[4]) ;
    int ans; 
	int userans;
    int n[5];//�ĸ������ 
    int op[4];//������������ 
    int userfenzi;                             //change      �û�����ķ��� 
	int userfenmu;                           //change         �û���ĸ 
    char operation[4]={'+','-','*','/'};
    char chuhao;
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
	//��ֹ���ֳ���Ϊ0�����                  //change      ԭ����0Ϊ1  �ĳ��������ݸ���� 
	if(op[1]==3&&n[2]==0) n[2]=rand()%10+1;
	if(op[2]==3&&n[3]==0) n[3]=rand()%10+1;
	if(op[3]==3&&n[4]==0) n[4]=rand()%10+1;
	//��ֹ���ִ𰸲�Ϊ�����������           //change   ɾ���� 
	
	
	
	//ans=chengchu(n,op);                    //change   ��С�������ǵĳ���Ҳ������  
	//if(ans>=0)
	//{
	//printf("��Ŀ:%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
	//}
	//else {
	//equation();
	//printf("erro!\n");
	
	
	switch(5)                             
		{
			case 0:
			{
				printf("��Ŀ:%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]); 
				ans=chengchu1(n,op);          //change       chengchu����֮һ ��Ҫд5�� 
				break;  	
			}
			case 1:printf("��Ŀ:(%d%c%d)%c%d%c%d=?\n",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 2:printf("��Ŀ:%d%c(%d%c%d%)%c%d=?\n",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 3:printf("��Ŀ:%d%c%d%c(%d%c%d)=?\n",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;	
			case 4:printf("��Ŀ:(%d%c%d%c%d)%c%d=?\n",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 5:
			{
			printf("��Ŀ:%d%c(%d%c%d%c%d)=?\n",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			ans=chengchu6(n,op);
			}
		}
   	if(ans==10001)                                //change       ������û�з������� �в�ͬ���û�����ͳ������ 
   	{
   		scanf("%d%c%d",&userfenzi,&chuhao,&userfenmu);
   		if(userfenzi==fenzi&&userfenmu==fenmu)
   		{
			printf("�����!\n");
			return 1;
		}
		else
		{
			printf("�����...%d/%d\n",fenzi,fenmu);
			return 0;
		}
	}
	else
	{  
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
} 
/*
������������
*/ 

int chengchu6( int n[5],int op[4])        
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[3]+(n[1]+n[2])*n[4];       
			    	fenmu=n[4];
			    	flag=fenshuhuajian();  
				} 
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]*n[3]-n[4];
			    if(op[3]==2) ans=n[1]+n[2]*n[3]*n[4];
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
			    if(op[3]==0) ans=n[1]-(n[2]+n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]+n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-(n[2]+n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-(n[2]-n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]-n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-(n[2]-n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-(n[2]*n[3]-n[4]);
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
			    	fenzi=(n[1]-n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
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
			    if(op[3]==0) ans=n[1]*(n[2]+n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]+n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]+n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*(n[2]*n[4]+n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*(n[2]-n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]-n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]-n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*(n[2]*n[4]-n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*(n[2]*n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*(n[2]*n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*(n[2]*n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[2];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*(n[2]+n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]*(n[2]-n[3]*n[4]);
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
			    	fenzi=n[1];
			    	fenmu=n[2]+n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
					fenzi=n[1];
			    	fenmu=n[2]+n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]+n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[3]+n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]-n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[4]-n[3];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]+n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3)
			    {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]+n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]-n[3]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2)
			    {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)             
	return 10001; 
	else
	return ans;	
}

int chengchu1(int n[5],int op[4])          //change   chengchu����֮һ 
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
			    	flag=fenshuhuajian();                //���������� 
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
	if(flag==1)               //�����Ƿ��з�������  ���ز�ֵͬ 
	return 10001; 
	else
	return ans;	
}
/*
����������
*/
int fenshuhuajian()
{
	int common(int m,int n);         //����������� 
	int yinshu;
	if(fenzi==0)                        //����Ϊ0 
	{
		ans=0;
		return 0;
	}
	if(fenzi%fenmu==0)                   //�������Ի������� 
	{
		ans=fenzi/fenmu;
		return 0;
	}
	else
	{   
		yinshu=common(fenzi,fenmu);
		fenzi=fenzi/yinshu;
		fenmu=fenmu/yinshu;
		if((fenzi>0&&fenmu<0)||(fenzi<0&&fenmu<0))                 // ��ֹ��� 4/-7  �� -5/-6   ����� 
		{
			fenzi=-fenzi;
			fenmu=-fenmu;
		}
		return 1;
	}
} 
/*
����������� 
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
	
	

 
