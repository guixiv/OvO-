#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int fenzi,fenmu,a;     
int ans,special=0;//special ���ڳ���Ϊ���������� 
int n[5];//�ĸ������ 
int op[4];//������������ 
/*
  ���ܣ��˵�
*/
void Menu()
{
	cout<<"---------------------------------------------------------------------------------\n"<<
	("*****************Welcome to use the arithmetic device for pupils!****************\n")<<
	("*******        1Chinese  2English  3Japanese  4Franch  5German       **********\n")<<
	("---------------------------------------------------------------------------------\n")<<endl;

}
int scan()
{
	int a;
	cin>>a;
	if(a<1||a>5)
    {
    	cout<<"miu����������\n"<<endl;
    	cin>>a; 
    }
    if(a<1||a>5)
	{
		cout<<"�ٸ���һ�λ���\n"<<endl;
		cin>>a; 
	} 
	return a;
}


/*
  ���ܣ������������ 
*/ 
void randomNumber()
{
	srand(time(NULL));
	n[1]=rand()%11;n[2]=rand()%11;n[3]=rand()%11;n[4]=rand()%11;
}
/*
	���ܣ�������ɷ���
*/ 

void randomOperation()
{   
	srand(time(NULL));
	op[1]=rand()%4;op[2]=rand()%4;op[3]=rand()%4;
}
/*
	����ѡ��
*/ 
void lan(int a,int b)
{
	char language[1000]; 
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
			cout<<StrLine<<endl;
		}
		fgets(StrLine,100,p);
		line++;
	}
	fclose(p);
	
}
/*
������������
*/ 
int calculateResult1(int n[5],int op[4])          
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


int calculateResult2( int n[5],int op[4])        
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


int calculateResult3( int n[5],int op[4])        
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


int calculateResult4( int n[5],int op[4])     
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


int calculateResult5( int n[5],int op[4])     
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


int calculateResult6( int n[5],int op[4])        
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

int generateExpression(int a)
{    
    int ans; 
	int userans=10003;
    int userfenzi=10003;                             //change      �û�����ķ��� 
	int userfenmu;                           //�û���ĸ 
    char operation[4]={'+','-','*','/'};
    char chuhao;
    randomNumber();
    randomOperation();
		switch(rand()%5)                        //change   swith(rand()%5)    ���������ŵĿ��� 
		{
			case 0:ans=calculateResult1(n,op);break;  	
			case 1:	ans=calculateResult2(n,op);break;
			case 2:ans=calculateResult3(n,op);	break;
			case 3:ans=calculateResult4(n,op);	break;
			case 4:ans=calculateResult5(n,op);break;
			case 5:ans=calculateResult6(n,op); 
		}
				if(ans!=10002) cout<<n[1]<<operation[op[1]]<<n[2]<<operation[op[2]]<<n[3]<<operation[op[3]]<<n[4]<<"="<<endl;

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
		cin>>userfenmu;
   		if(userfenzi==fenzi&&userfenmu==fenmu)
   		{
			lan(a,2);
			return 1;
		}
		else
		{
			lan(a,3); 
			cout<<fenzi<<"/"<<fenmu<<endl<<endl;
			return 0;
		}
		}
		else
   		{
   			lan(a,3);
   			cout<<fenzi<<"/"<<fenmu<<endl<<endl;
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
			cout<<ans<<endl<<endl;
			return 0;
   		}
   	    }
   	    else
   	    {
   	    	cin>>userfenmu;
   	    	lan(a,3);
   	    }
   	}
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
		special=special+generateExpression(a);
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
 

 
void print(int num,int a)
{
	void lan(int a,int b);
	int score=0,i,equationz;
	for(i=0;i<num;i++)
	{
		equationz=generateExpression(a);
		if(equationz==3)break;
		score=score+equationz;
	}
	score=score+special;
	lan(a,4);
	cout<<i<<endl;
	lan(a,5);
	cout<<score<<endl;
	lan(a,6);
	cout<<i-score<<endl;
}


/*
������
*/ 
int main()
{
	int a,num;
	FILE *f;
	Menu();
	a=scan();
	lan(a,1);
	cin>>num;
	cout<<"\n"<<endl;
	print(num,a);
	return 0;
}


