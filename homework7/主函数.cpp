#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include"标头.h"
int main(int argc, char *argv[])
{
	srand(time(0));
	filemachine f;
	
	char *p1 = argv[2];
	char *p0 = argv[1];
	int i = 0, n, sum = 0;
	f.showTip(p1);
	n = f.readfile(p0);
	while (i<n)
	{
		float user;
		creatmachine cr;
		calculator ca;
		judge j;
		string problem = cr.generateExpression();
		cout << problem << endl;                                         //输出所生成的算式
		float answer = ca.calculateResult(problem);                      //计算结果交给判断类
		cin >> user;                                                     //用户输入答案
		j.getdata(user);                                                 //数据传入
		sum += j.scan(answer, p1);                                       //判断
		i++;
	}
	f.print(sum, p1);                                                    //输出统计结果
	return 0; 
}