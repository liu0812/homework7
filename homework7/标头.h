#include<string>
#include<iostream>
using namespace std;
class creatmachine
{
public:
	string int_string(int number);                                             // int类型转化为 string类型 
	string combine(string str1, string str2, char k);                          //符号数字结合 
	string generateExpression();                                               //生成算式 
private:
	string formula;                                                            //产生的算式
};
class calculator
{
public:
	float calculateResult(string str);                                          //一级计算函数 
	float caculate(float Operand1, float Operand2, char Operator);              //二级计算函数 
	void InitPriorities();                                                      //比较优先级容器 
private:
	float answer;                                                               //存储结果
};
class judge
{
public:
	int scan(float answer, char *p);                                             //用户输入结果并写入文件并判断对错 
	void getdata(float f);                                                       //获得数据
private:
	float user;                                                                  //用户输入答案
};
class filemachine
{
public:
	void writefile(char *p0, char *p, int w);                                    //写入函数 
	void print(int right, char *pp);                                             //输出 
	void showTip(char *ptr);                                                    //程序说明 
	int readfile(char *p0);                                                     //读取文件 
};
class Random
{
public:
	Random(){}
	~Random(){}
	virtual char randomOperation() = 0;
	virtual int randomNunber() = 0;
};
class Randomnumber : public Random
{
public:
	Randomnumber(){}
	~Randomnumber(){}
	virtual int randomNunber();                                                        //产生随机数  
	virtual char randomOperation();
};
class Randomoperator :public Random
{
public:
	Randomoperator(){}
	~Randomoperator(){}
	virtual char randomOperation();                                                    //随机符号
	virtual int randomNunber();
};
class Randomfactory
{
public:
	Randomfactory(){}
	~Randomfactory(){}
	static Random *creatrandom(const int & temp);
};