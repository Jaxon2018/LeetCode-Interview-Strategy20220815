#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "string of many words.", s2 = "many"; //s1="string of many words.��"s1("string of many words.")�ȼۡ���������string�๹�캯����
	int i;
	cout << s1 << endl;
	i = s1.find(s2); //����find����������s2��s1�е�λ�á������ﷵ��10����s1��s2��ʼλ����10
	s1.replace(i, 4, "few");//����replace�������ַ���few���滻s1�е�4���ַ���i��ֵ����find�ķ���ֵ��
							//many���ַ����е�λ�ã����ұ�ʾ�滻�����λ�ÿ�ʼ��
	cout << s1 << endl;
	s1.erase(i, 4);   //ɾ����s1�ַ����дӵ�10����ʼ��4���ַ�
	cout << s1 << endl;
	s1.insert(i, "simple ");  //���ַ���"simple"�����ַ���s1�ĵ�10���ַ���λ�á�
	cout << s1 << endl;
}
