#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fenzi,fenmu;     //change      �µ�ȫ�ֱ���    ��������ķ��ӷ�ĸ 
int ans;             //change      ��Ϊȫ�ֱ��� 
/*
  ���ܣ��˵�
*/
void Menu()
{
	printf("---------------------------------------------------------------------------------\n");
	printf("***************************��ӭʹ��Сѧ�������������!***************************\n");
	printf("*****************Welcome to use the arithmetic device for pupils!****************\n");
	printf("---------------------------------------------------------------------------------\n\n");
	printf("������֧�ַ������㣬�����뻯���ķ����𰸣���1/2,3/5,-4/7\n");
	printf("This procedure supports fractional operation, please enter the simplified answer,suach as 1/2,3/5,-4/7\n\n\n");
	printf("   ����������Ҫʹ�õ�����.\n");
	printf("  Please enter the language you want to use.\n\n");
	printf("   1.����         2.English\n\n"); 
}
void Chinese()
{

	printf("��������Ҫ������Ŀ����.\n"); 
} 
void English()
{

	printf("Plese scanf the number of topics you want.\n");
}
/*
  ���ܣ����������ʽ 
*/ 
int equation(int a)
{   
    int chengchu1(int n[5],int op[4]);       //change    chengchu����֮һ 
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
	
	
	switch(0)                             //change   swith(rand()%5)    ���������ŵĿ��� 
		{
			case 0:
			{
				printf("%d%c%d%c%d%c%d=?",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]); 
				ans=chengchu1(n,op);          //change       chengchu����֮һ ��Ҫд5�� 
				break;  	
			}
			case 1:printf("(%d%c%d)%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 2:printf("%d%c(%d%c%d%)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 3:printf("%d%c%d%c(%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;	
			case 4:printf("(%d%c%d%c%d)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);break;
			case 5:printf("%d%c(%d%c%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
		}
   	if(ans==10001)                                //change       ������û�з������� �в�ͬ���û�����ͳ������ 
   	{
   		scanf("%d%c",&userfenzi,&chuhao);
   		
   		if(chuhao=='/')
		   {
		   scanf("%d",&userfenmu); 
   		if(userfenzi==fenzi&&userfenmu==fenmu)
   		{
			if(a==1)printf("�����!\n");
			else if(a==2) printf("You r right!\n");
			return 1;
		}
		else
		{
			if(a==1) printf("����ˡ���%d/%d\n",fenzi,fenmu);
   			else if(a==2) printf("Your are wrong... %d/%d\n",fenzi,fenmu);
			return 0;
		}
	}
		else
   		{
   			if(a==1) printf("����ˡ���%d/%d\n",fenzi,fenmu);
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
		if(a==1)printf("�����!\n");
			else if(a==2) printf("You r right!\n");
			return 1;
		}
		else
		{
				if(a==1) printf("����ˡ���%d\n",ans);
   			else if(a==2) printf("Your are wrong... %d\n",ans);
			return 0;
   		}
   	    }
   	    else
   	    {
   	    	scanf("%d",&userfenmu);
   	    	if(a==1) printf("����ˡ���%d\n",ans);
   			else if(a==2) printf("Your are wrong... %d\n",ans);
   	    }
   	}
} 
/*
������������
*/ 
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
 

 
void Cresult(int num,int a)
{
	int score=0,i;
	for(i=0;i<num;i++)
	{
		score=score+equation(a);
	}
	printf("\n������%d���⣬�����%d���⣬�����%d����\n",num,score,num-score);
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
������
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
	
	

 
