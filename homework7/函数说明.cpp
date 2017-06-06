#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include<stdlib.h>
#include <string>
#include <vector>
#include<sstream>
#include <cstring>
#include <unordered_map>
#include <math.h>
#include<cassert>
#include"标头.h"
unordered_map< char, unordered_map < char, char > > Priorities;
#define random() (rand()%100000)

using namespace std;

void filemachine::writefile(char *p0, char *p, int w)
{
	FILE *f;
	if ((f = fopen(p0, "a")) == NULL)
	{
		cout << "can not write" << endl;
	}
	fputs(p, f);
	if (w == 1)
		fputs("\n", f);
}
string creatmachine::combine(string str1, string str2, char k)
{
	string combination;
	combination = str1 + k + str2;
	return combination;
}
string creatmachine::int_string(int number)
{
	int temp = abs(number);
	char str[200];
	_itoa_s(temp, str, 10);
	return str;
}
char Randomoperator::randomOperation()
{
	int j;
	char symbol[1];
	j = random() % 4;
	switch (j) {
	case 0:
		symbol[0] = '+';
		break;
	case 1:
		symbol[0] = '-';
		break;
	case 2:
		symbol[0] = '*';
		break;
	case 3:
		symbol[0] = '/';
		break;
	}
	return symbol[0];
}
char Randomnumber::randomOperation()
{
	int j;
	char symbol[1];
	j = random() % 4;
	switch (j) {
	case 0:
		symbol[0] = '+';
		break;
	case 1:
		symbol[0] = '-';
		break;
	case 2:
		symbol[0] = '*';
		break;
	case 3:
		symbol[0] = '/';
		break;
	}
	return symbol[0];
}
int Randomnumber::randomNunber()
{
	int a = random() % 10 + 1;
	return a;
}
int Randomoperator::randomNunber()
{
	int a = random() % 10 + 1;
	return a;
}
Random * Randomfactory::creatrandom(const int & temp)
{
	if (temp == 1)
	{
		return new Randomoperator();
	}
	if (temp == 0)
	{
		return new Randomoperator();
	}
	else
	{
		assert(false);
	}
	return NULL;
}
int judge::scan(float answer, char *p)
{
	filemachine fi;
	int sum = 0;
	int flag1 = 0; int flag2 = 1;
	char chinese[10] = "正确答案";
	ostringstream ss1;
	ss1 << user;
	string str1 = ss1.str();
	fi.writefile(p, &str1[0], flag2);
	answer = ((int)(((float)answer) * 100 + 0.5)) / 100.0;
	cout << "正确答案 " << answer << endl;
	fi.writefile(p, chinese, flag1);
	ostringstream ss2;
	ss2 << answer;
	string str2 = ss2.str();
	fi.writefile(p, &str2[0], flag2);
	if (user == answer)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void filemachine::print(int right, char *pp)
{
	int flag1 = 0;
	char right1[20] = { 0 };
	char chinese1[10] = "本次作对", chinese2[20] = "道题，感谢您的使用";
	cout << "本次作对" << right << "道题，感谢您的使用" << endl;
	writefile(pp, chinese1, flag1);
	right1[0] = right + '0';
	writefile(pp, &right1[0], flag1);
	writefile(pp, chinese2, flag1);
	//	cout << _thanks << endl;
}
string creatmachine::generateExpression()
{
	int num1, num2, change, count;
	char symbol;
	string str_num1, str_num2, Equation, t;
	Random *temp = NULL;
	temp = Randomfactory::creatrandom(1);
	num1 = temp->randomNunber();
	num2 = temp->randomNunber();
	count = random() % 6 + 2;
	temp = Randomfactory::creatrandom(0);
	symbol = temp->randomOperation();
	str_num1 = int_string(num1);
	str_num2 = int_string(num2);
	Equation = combine(str_num1, str_num2, symbol);          //随机数与随机的符号结合 
	for (count; count>2; count--) 
	{
		symbol = temp->randomOperation();
		str_num1 = Equation;
		change = random() % 2;
		if (change == 0) 
		{
			str_num1 = '(' + str_num1 + ')';
		}
		num2 = random() % 10 + 1;
		str_num2 = int_string(num2);
		change = random() % 2;
		if (change == 0) 
		{
			t = str_num1;
			str_num1 = str_num2;
			str_num2 = t;
		}
		Equation = combine(str_num1, str_num2, symbol);
	}
	//		cout << Equation << "=" << endl;
	string Equation2 = Equation + '=';
	formula = Equation2;
	return Equation2;
}
float calculator::calculateResult(string str)
{
	InitPriorities();                                      //声明优先级比较表 
	vector< float > Operands;                              //运算数栈 
	vector< char > Operators;                              //运算符栈 
	float OperandTemp = 0;
	char LastOperator = 0;                                 //记录上一次所遇到的符号 
	for (int i = 0; i < str.size(); i++) {                 //此循环用于去括号 
		char ch = str[i];
		if ('0' <= ch && ch <= '9') {
			OperandTemp = OperandTemp * 10 + ch - '0';
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
			if (ch != '(' && LastOperator != ')') {         //结合本次和上次所遇见的符号来判断是否需要将当前存储的运算数压入栈 
				Operands.push_back(OperandTemp);
				OperandTemp = 0;
			}
			char Opt2 = ch;
			for (; Operators.size() > 0;) {
				char Opt1 = Operators.back();
				char CompareRet = Priorities[Opt1][Opt2];   //用当前符号与栈顶符号来对算式简化 
				if (CompareRet == '>') {                    //当前的符号的优先级小于栈顶符号时就可以将栈顶符号计算掉并将结果压入栈  
					float Operand2 = Operands.back();
					Operands.pop_back();
					float Operand1 = Operands.back();
					Operands.pop_back();
					Operators.pop_back();
					float Ret = caculate(Operand1, Operand2, Opt1);
					Operands.push_back(Ret);
				}
				else if (CompareRet == '<') {                //当前的符号优先级大于栈顶符号不能进行运算所以跳出循环来存储当前符号 
					break;
				}
				else if (CompareRet == '=') {                //这个是“（”，“） ”结合的情况 所以移除“（”并退出循环 
					Operators.pop_back();
					break;
				}
			}
			if (Opt2 != ')') {
				Operators.push_back(Opt2);
			}
			LastOperator = Opt2;
		}
	}
	if (LastOperator != ')') {                               //接下来就是计算一个不含括号的算式了 
		Operands.push_back(OperandTemp);
	}
	for (; Operators.size() > 0;) {
		float Operand2 = Operands.back();
		Operands.pop_back();
		float Operand1 = Operands.back();
		Operands.pop_back();
		char Opt = Operators.back();
		Operators.pop_back();
		float Ret = caculate(Operand1, Operand2, Opt);
		Operands.push_back(Ret);
	}
	answer = Operands.back();
	return Operands.back();
}
float calculator::caculate(float Operand1, float Operand2, char Operator)
{
	float result = 0;
	if (Operator == '+') {
		result = Operand1 + Operand2;
	}
	if (Operator == '-') {
		result = Operand1 - Operand2;
	}
	if (Operator == '*') {
		result = Operand1*Operand2;
	}
	if (Operator == '/') {
		result = Operand1 / Operand2;
	}
	return result;
}
void filemachine::showTip(char *ptr)
{
	char chinese1[60] = "欢迎使用本程序,已经按照您的要求进行出题。小数请保留两位";
	cout << "欢迎使用本程序,已经按照您的要求进行出题，小数请保留两位。" << endl;
	writefile(ptr, chinese1, 1);
}
void calculator::InitPriorities()
{
	Priorities['+']['-'] = '>';
	Priorities['+']['+'] = '>';
	Priorities['+']['*'] = '<';
	Priorities['+']['/'] = '<';
	Priorities['+']['('] = '<';
	Priorities['+'][')'] = '>';

	Priorities['-']['-'] = '>';
	Priorities['-']['+'] = '>';
	Priorities['-']['*'] = '<';
	Priorities['-']['/'] = '<';
	Priorities['-']['('] = '<';
	Priorities['-'][')'] = '>';

	Priorities['*']['-'] = '>';
	Priorities['*']['+'] = '>';
	Priorities['*']['*'] = '>';
	Priorities['*']['/'] = '>';
	Priorities['*']['('] = '<';
	Priorities['*'][')'] = '>';

	Priorities['/']['-'] = '>';
	Priorities['/']['+'] = '>';
	Priorities['/']['*'] = '>';
	Priorities['/']['/'] = '>';
	Priorities['/']['('] = '<';
	Priorities['/'][')'] = '>';

	Priorities['(']['+'] = '<';
	Priorities['(']['-'] = '<';
	Priorities['(']['*'] = '<';
	Priorities['(']['/'] = '<';
	Priorities['(']['('] = '<';
	Priorities['('][')'] = '=';

	Priorities[')']['+'] = '?';
	Priorities[')']['-'] = '?';
	Priorities[')']['*'] = '?';
	Priorities[')']['/'] = '?';
	Priorities[')']['('] = '?';
	Priorities[')'][')'] = '?';
}
int filemachine::readfile(char *p0)
{
	FILE *f;
	char ch[2];
	if ((f = fopen(p0, "r")) == NULL)
	{
		cout << "Can not open!" << endl;
	}

	fgets(ch, 2, f);
	return ch[0] - '0';
}
void judge::getdata(float f)
{
	user = f;
}