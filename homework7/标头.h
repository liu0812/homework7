#include<string>
#include<iostream>
using namespace std;
class creatmachine
{
public:
	string int_string(int number);                                             // int����ת��Ϊ string���� 
	string combine(string str1, string str2, char k);                          //�������ֽ�� 
	string generateExpression();                                               //������ʽ 
private:
	string formula;                                                            //��������ʽ
};
class calculator
{
public:
	float calculateResult(string str);                                          //һ�����㺯�� 
	float caculate(float Operand1, float Operand2, char Operator);              //�������㺯�� 
	void InitPriorities();                                                      //�Ƚ����ȼ����� 
private:
	float answer;                                                               //�洢���
};
class judge
{
public:
	int scan(float answer, char *p);                                             //�û���������д���ļ����ж϶Դ� 
	void getdata(float f);                                                       //�������
private:
	float user;                                                                  //�û������
};
class filemachine
{
public:
	void writefile(char *p0, char *p, int w);                                    //д�뺯�� 
	void print(int right, char *pp);                                             //��� 
	void showTip(char *ptr);                                                    //����˵�� 
	int readfile(char *p0);                                                     //��ȡ�ļ� 
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
	virtual int randomNunber();                                                        //���������  
	virtual char randomOperation();
};
class Randomoperator :public Random
{
public:
	Randomoperator(){}
	~Randomoperator(){}
	virtual char randomOperation();                                                    //�������
	virtual int randomNunber();
};
class Randomfactory
{
public:
	Randomfactory(){}
	~Randomfactory(){}
	static Random *creatrandom(const int & temp);
};