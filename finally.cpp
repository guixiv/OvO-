#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int fenzi,fenmu,a;     
int ans,special=0;//special ���ڳ���Ϊ���������� 
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

}
void lan(int a,int b)
{
	char language[1000];
	FILE *pp=fopen("language.txt","r");
	if(a==1) strcpy(language,"Chinese.txt");
	if(a==2) strcpy(language,"English.txt");
	if(a==3) strcpy(language,"Japanese.txt");
	if(a==4) strcpy(language,"Franch.txt");
	if(a==5) strcpy(language,"German.txt");
	int line=1;
	FILE * p=fopen(language,"r");
	char StrLine[100];
	while(!feof(p))
	{
		if(line==b)
		{
			fgets(StrLine,100,p);
			printf("\n%s",StrLine);
		}
		fgets(StrLine,100,p);
		line++;
	}
	fclose(p);
	
}
/*
  ���ܣ����������ʽ 
*/ 
int equation(int a)
{   
    void lan(int a,int b);
    int chengchu1(int n[5],int op[4]);  
	int chengchu2(int n[5],int op[4]);  
	int chengchu3(int n[5],int op[4]);  
	int chengchu4(int n[5],int op[4]);  
	int chengchu5(int n[5],int op[4]);  
	int chengchu6(int n[5],int op[4]);   
    int ans; 
	int userans=10003;
    int n[5];//�ĸ������ 
    int op[4];//������������ 
    int userfenzi=10003;                             //change      �û�����ķ��� 
	int userfenmu;                           //�û���ĸ 
    char operation[4]={'+','-','*','/'};
    char chuhao;
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
	switch(rand()%5)                        //change   swith(rand()%5)    ���������ŵĿ��� 
		{
			case 0:
			{
				ans=chengchu1(n,op);          
				if(ans!=10002)
					printf("%d%c%d%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]); 
				break;  	
			}
			case 1:
			{
				ans=chengchu2(n,op);
				if(ans!=10002)
					printf("(%d%c%d)%c%d%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
				break;
			}
			case 2:
			{
				ans=chengchu3(n,op);  
				if(ans!=10002)
					printf("%d%c(%d%c%d%)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
				break;
			}
			case 3:
			{
				ans=chengchu4(n,op);  
				if(ans!=10002)
					printf("%d%c%d%c(%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
				break;
			}
			case 4:
			{
				ans=chengchu5(n,op);
				if(ans!=10002)  
					printf("(%d%c%d%c%d)%c%d=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
				break;
			}
			case 5:
			{
				ans=chengchu6(n,op); 
				if(ans!=10002) 
					printf("%d%c(%d%c%d%c%d)=",n[1],operation[op[1]],n[2],operation[op[2]],n[3],operation[op[3]],n[4]);
			}
		}
   	if(ans==10001)                                //change       ������û�з������� �в�ͬ���û�����ͳ������ 
   	{
   		scanf("%d%c",&userfenzi,&chuhao);
   		if(userfenzi==10003)
   		{
   			if(getchar()=='e')
   			return 3;
		}
   		else if(chuhao=='/')
		{
		scanf("%d",&userfenmu); 
   		if(userfenzi==fenzi&&userfenmu==fenmu)
   		{
			lan(a,2);
			return 1;
		}
		else
		{
			lan(a,3); 
   			printf("%d/%d\n",fenzi,fenmu);
			return 0;
		}
		}
		else
   		{
   			lan(a,3);
			printf(" %d/%d\n",fenzi,fenmu);
   			return 0;
   		}
	
	}
	else if(ans==10002)
	{
		return 0;
	}
	else
	{  
		scanf("%d%c",&userans,&chuhao);
		if(userans==10003)
		{
			if(getchar()=='e')
			return 3;
		}
		else if(chuhao=='\n')
		{
		if(userans==ans)
		{
		lan(a,2);
			return 1;
		}
		else
		{
			lan(a,3);	
			printf(" %d\n",ans);
			return 0;
   		}
   	    }
   	    else
   	    {
   	    	scanf("%d",&userfenmu);
   	    	lan(a,3);
			("%d\n",ans);
   	    }
   	}
} 
/*
������������
*/ 
int chengchu1(int n[5],int op[4])          
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
	if(flag==0)
	return ans;	
	if(flag==2)
	return 10002;
}


int chengchu2( int n[5],int op[4])        
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
			    if(op[3]==0) ans=(n[1]+n[2])*n[3]+n[4];
			    if(op[3]==1) ans=(n[1]+n[2])*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2])*n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]+n[2])*n[3];
					fenmu=n[4];
					flag=fenshuhuajian(); 
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0)
			    {
			    	fenzi=n[4]*n[3]+n[1]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]+n[2]-(n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=(n[1]+n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]+n[2];
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
			    if(op[3]==2) ans=n[1]-n[2]+n[3]*n[4];
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
			    if(op[3]==2) ans=n[1]-n[2]-n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=(n[1]-n[2])*n[3]+n[4];
			    if(op[3]==1) ans=(n[1]-n[2])*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2])*n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=(n[1]-n[2])*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			     {
			    	fenzi=n[4]*n[3]+n[1]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]-n[2]-(n[3]*n[4]);
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=(n[1]-n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]-n[2];
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
			    if(op[3]==2) ans=n[1]*n[2]+n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]-n[3]-n[4];
			    if(op[3]==2) ans=n[1]*n[2]-n[3]*n[4];
			    if(op[3]==3) 
			     {
			    	fenzi=n[1]*n[2]*n[4]-n[3];
			    	fenmu=n[4];
					flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]*n[3]-n[4];
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
			    	fenzi=n[4]*n[3]+n[1]*n[2];
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
			    	fenzi=n[1]+(n[3]+n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1)
			     {
			    	fenzi=n[1]+(n[3]-n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]+n[2]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]*n[4]+n[3]*n[2];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0)
			     {
			    	fenzi=n[1]-n[3]*n[2]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1)
			     {
			    	fenzi=n[1]-n[3]*n[2]-n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) 
			     {
			    	fenzi=n[1]-n[3]*n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3)
			     {
			    	fenzi=n[1]*n[4]-n[3]*n[2];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			     {
			    	fenzi=n[1]*n[3]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]*n[3]-n[4]*n[2];
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
			    	fenzi=n[1]+n[4]*n[2]*n[3];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) 
			     {
			    	fenzi=n[1]-n[4]*n[2]*n[3]; 
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2)
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/n[2]/n[3]/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu3( int n[5],int op[4])        
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[2]+n[3]+n[1]*n[4]; 
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]+(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]+(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]+(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]+(n[2]/n[3])+n[4];
			     {
			    	fenzi=(n[1]+n[4])*n[3]+n[2]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]+(n[2]/n[3])-n[4];
			     {
			    	fenzi=(n[1]-n[4])*n[3]+n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]+(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]+n[2]*n[4]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]+(n[2]/n[3])/n[4];
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
			    if(op[3]==0) ans=n[1]-(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]-n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]-n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]-(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]-(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]-(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]-(n[2]/n[3])+n[4];
			     {
			    	fenzi=(n[1]+n[4])*n[3]-n[2];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]-(n[2]/n[3])-n[4];
			     {
			    	fenzi=(n[1]-n[4])*n[3]-n[2]; 
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]-(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3]; 
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]-(n[2]/n[3])/n[4];
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
			    if(op[3]==0) ans=n[1]*(n[2]+n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]+n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]+n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1]*(n[2]+n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*(n[2]-n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]-n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]-n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1]*(n[2]-n[3]);
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*(n[2]*n[3])+n[4];
			    if(op[3]==1) ans=n[1]*(n[2]*n[3])-n[4];
			    if(op[3]==2) ans=n[1]*(n[2]*n[3])*n[4];
			    if(op[3]==3) ans=n[1]*(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1]*n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]*(n[2]/n[3])+n[4];
			     {
			    	fenzi=n[1]*n[2]+n[4]*n[3];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]*(n[2]/n[3])-n[4];
			     {
			    	fenzi=n[1]*n[2]-n[4]*n[3];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]*(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]*(n[2]/n[3])/n[4];
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
			    if(op[3]==0) ans=n[1]/(n[2]+n[3])+n[4];
			     {
			    	fenzi=n[1]+(n[2]+n[3])*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]+n[3])-n[4];
			     {
			    	fenzi=n[1]+(n[2]+n[3])*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]+n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]+n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]+n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=(n[2]+n[3])*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]/(n[2]-n[3])+n[4];
			     {
			    	fenzi=n[1]+(n[2]-n[3])*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]-n[3])-n[4];
			     {
			    	fenzi=n[1]-(n[2]-n[3])*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]-n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]-n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]-n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=(n[2]-n[3])*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]/(n[2]*n[3])+n[4];
			     {
			    	fenzi=n[1]+n[4]*n[2]*n[3]; 
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]*n[3])-n[4];
			     {
			    	fenzi=n[1]-n[4]*n[2]*n[3];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]*n[3])*n[4];
			     {
			    	fenzi=n[1]*n[4];
			    	fenmu=n[2]*n[3];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]*n[3])/n[4];
			     {
			    	fenzi=n[1];
			    	fenmu=n[2]*n[3]*n[4];
			    	flag=fenshuhuajian();
			    }
		}
			if(op[2]==3)
		{
			    if(op[3]==0) ans=n[1]/(n[2]/n[3])+n[4];
			     {
			    	fenzi=n[1]*n[3]+n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==1) ans=n[1]/(n[2]/n[3])-n[4];
			     {
			    	fenzi=n[1]*n[3]-n[4]*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==2) ans=n[1]/(n[2]/n[3])*n[4];
			     {
			    	fenzi=n[1]*n[3]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
			    }
			    if(op[3]==3) ans=n[1]/(n[2]/n[3])/n[4];
			     {
			    	fenzi=n[1]*n[3];
			    	fenmu=n[2]*n[4]; 
			    	flag=fenshuhuajian();
			    }
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu4( int n[5],int op[4])     
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
			    if(op[3]==0) ans=n[1]+n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]+n[2]-(n[3]-n[4]);
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
			    if(op[3]==0) ans=n[1]+n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]+n[2]*(n[3]-n[4]);
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
			    	fenzi=n[1]*(n[3]+n[4])+n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]*(n[3]-n[4])+n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*(n[3]*n[4])+n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
			    	fenmu=n[3];
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
			    if(op[3]==2) ans=n[1]-n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-n[2]-(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-n[2]-n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=(n[1]-n[2])*n[4]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]-n[2]*(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]-n[2]*n[3]*n[4];
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
			    	fenzi=n[1]*(n[3]+n[4])-n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*(n[3]-n[4])-n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=n[1]*n[3]*n[4]-n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]-n[2]*n[4];
			    	fenmu=n[3];
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
			    if(op[3]==2) ans=n[1]*n[2]+n[3]*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*n[2]-(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*n[2]-(n[3]*n[4]);
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]*n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*(n[3]+n[4]);
			    if(op[3]==1) ans=n[1]*n[2]*(n[3]-n[4]);
			    if(op[3]==2) ans=n[1]*n[2]*(n[3]*n[4]);
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
			    	fenzi=n[1]*n[2];
			    	fenmu=n[4]+n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[2];
			    	fenmu=n[3]-n[4];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
					fenzi=n[1]*n[2];
			    	fenmu=n[4]*n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]*n[4];
			    	fenmu=n[3];
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
			    	fenzi=n[3]*n[4]*n[2]+n[1];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[4]+n[2]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]-n[2]*(n[3]+n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-n[2]*(n[3]-n[4]);
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
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*(n[3]+n[4]);
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*(n[3]-n[4]);
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
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*(n[3]+n[4]);
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1];
			    	fenmu=n[2]*(n[3]-n[4]);
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
			    	fenmu=n[3]*n[2];
			    	flag=fenshuhuajian();
				}
		}
	}	
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}


int chengchu5( int n[5],int op[4])     
{
	int fenshuhuajian();
	int flag=0;	
	if(op[1]==0)
	{
		    if(op[2]==0)
		{
			    if(op[3]==0) ans=n[1]+n[2]+n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]+n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]+n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]+n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]+n[2]*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]+n[2]*n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]+n[2+n[3]*n[4]];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]+n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]*n[3]+n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]+n[2];
			    	fenmu=n[4]*n[3];
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
			    if(op[3]==2) ans=(n[1]-n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]-n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]-n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]-n[2]*n[3]-n[4];
			    if(op[3]==2) ans=(n[1]-n[2]*n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]*n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				} 
		}
			if(op[2]==3)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]-n[2]+n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]*n[3]-n[2]-n[3]*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]*n[3]-n[2])*n[4];
			    	fenmu=n[3];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[3]-n[2];
			    	fenmu=n[4]*n[3];
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
			    if(op[3]==2) ans=(n[1]*n[2]+n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]+n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) ans=n[1]*n[2]-n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]-n[3]-n[4];
			    if(op[3]==2) ans=(n[1]*n[2]-n[3])*n[4];
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]*n[2]-n[3];
			    	fenmu=n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) ans=n[1]*n[2]*n[3]+n[4];
			    if(op[3]==1) ans=n[1]*n[2]*n[3]-n[4];
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
			    	fenmu=n[4]*n[3];
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
			    	fenzi=n[1]+n[2]*n[3]+n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1)
			    {
			    	fenzi=n[1]+n[2]*n[3]-n[2]*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]+n[2]*n[3])*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]+n[2]*n[3];
			    	fenmu=n[4]*n[2];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==1)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]+(n[4]-n[3])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==1) 
			    {
			    	fenzi=n[1]-(n[3]+n[4])*n[2];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==2) 
			    {
			    	fenzi=(n[1]-n[2]*n[3])*n[4];
			    	fenmu=n[2];
			    	flag=fenshuhuajian();
				}
			    if(op[3]==3) 
			    {
			    	fenzi=n[1]-n[2]*n[3];
			    	fenmu=n[2]*n[4];
			    	flag=fenshuhuajian();
				}
		}
			if(op[2]==2)
		{
			    if(op[3]==0) 
			    {
			    	fenzi=n[1]*n[3]+n[2]*n[4];
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
	if(flag==1)             
	return 10001; 
	if(flag==0)
	return ans;	
	if(flag==2)
	return 10002;
}


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
	if(flag==0)
	return ans;
	if(flag==2)
	return 10002;	
}



/*
����������
*/
int fenshuhuajian()
{
	int common(int m,int n);       //����������� 
	int yinshu;
	if(fenmu==0)
	{
		special=special+equation(a);
		return 2;	
	} 
	else if(fenzi==0)                        //����Ϊ0 
	{
		ans=0;
		return 0;
	}
	else if(fenzi%fenmu==0)                   //�������Ի������� 
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
 

 
void result(int num,int a)
{
	void lan(int a,int b);
	int score=0,i,equationz;
	for(i=0;i<num;i++)
	{
		equationz=equation(a);
		if(equationz==3)break;
		score=score+equationz;
	}
	score=score+special;
	lan(a,4);
	printf("%d",i);
	lan(a,5);
	printf("%d",score);
	lan(a,6);
	printf("%d",i=score);
}

/*
������
*/ 
int main()
{
	int a,num;
	FILE *f;
	Menu();
	scanf("%d",&a);
	if(a<1||a>5)
    {
    	printf("miu����������\n");
    	scanf("%d",&a); 
    }
    if(a<1||a>5)
	{
		printf("�ٸ���һ�λ���\n");
		scanf("%d",&a); 
	} 
	lan(a,1);
	scanf("%d",&num);
	printf("\n");
	result(num,a);
	/*if(a==1)
	{
	  Chinese();
	  scanf("%d",&num);
	  printf("\n");
	  Cresult(num,a);
    }
    if(a==2)
    {
    	English();
    	scanf("%d",&num);
    	printf("\n");
    	Eresult(num,a);
    }
    */
    if(a!=1&&a!=2)
    {
    	printf("��ӭʹ�ñ�������װ�\(���ء�`)o\n"); 
    }
	return 0;
}

