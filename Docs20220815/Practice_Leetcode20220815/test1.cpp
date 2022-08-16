#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "string of many words.", s2 = "many"; //s1="string of many words.和"s1("string of many words.")等价。都调用了string类构造函数。
	int i;
	cout << s1 << endl;
	i = s1.find(s2); //调用find函数，返回s2在s1中的位置。在这里返回10，因s1在s2起始位置是10
	s1.replace(i, 4, "few");//调用replace函数用字符串few来替换s1中的4个字符。i的值就是find的返回值，
							//many在字符串中的位置，并且表示替换从这该位置开始。
	cout << s1 << endl;
	s1.erase(i, 4);   //删除了s1字符串中从第10个开始的4个字符
	cout << s1 << endl;
	s1.insert(i, "simple ");  //把字符串"simple"插入字符串s1的第10个字符的位置。
	cout << s1 << endl;
}
