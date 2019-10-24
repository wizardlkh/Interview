#include<iostream>

using namespace std;

int gcd(int a, int b) // 최대공약수
{
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}

int lcm(int a, int b) // 최소공배수
{
	return a * b / gcd(a, b);
}

int main()
{
	cout << "최대공약수: " << gcd(28, 42) << '\n';
	cout << "최소공배수: " << lcm(28, 42) << '\n';

	return 0;
}