#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#include"��ͷ.h"
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
		cout << problem << endl;                                         //��������ɵ���ʽ
		float answer = ca.calculateResult(problem);                      //�����������ж���
		cin >> user;                                                     //�û������
		j.getdata(user);                                                 //���ݴ���
		sum += j.scan(answer, p1);                                       //�ж�
		i++;
	}
	f.print(sum, p1);                                                    //���ͳ�ƽ��
	return 0; 
}