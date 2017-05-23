#include<iostream>
using namespace std;

class Input{
	private:
		int lan_choice;
		int num_choice;
	public:
		Input(int a,int b){
			lan_choice = a;
			num_choice = b; 
		}
		void language(int m);//m：第几句话 
		void number();//判断输入的题目数量是否正确 
		
}; 

class Theme;
class Calculate{
	private:
		float ans;
		int fenmu;
	public:
		void cal_ans(Theme &);
		bool compare_ans(float userans);
		bool compare_ans(int userans);
		bool compare_ans(int userans,int userfenmu);
		void put_ans();
};

class Theme{
	private:
		int num[4];
		int ope[3];
	public:
		void randomOperation();
		void randomNumber();
		void put_equation();
		friend void Calculate::cal_ans(Theme &);
};

class Judge{
	public:
		bool ans_isRight(int ans,int userans);
		bool ans_isE(int ans);
		bool shizi_0(char *p);
		bool judge_number(int sum);
};


