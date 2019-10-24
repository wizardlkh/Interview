#include<iostream>

using namespace std;

int gcd(int a, int b) // �ִ�����
{
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}

int lcm(int a, int b) // �ּҰ����
{
	return a * b / gcd(a, b);
}

int main()
{
	cout << "�ִ�����: " << gcd(28, 42) << '\n';
	cout << "�ּҰ����: " << lcm(28, 42) << '\n';

	return 0;
}