#include<iostream>
#include<cmath>
using namespace std;

long long N, d[1000];

long long step(int n)
{
	if (n <= 3)
		return (long long)pow(2, n - 1);

	return step(n - 1) + step(n - 2) + step(n - 3);
}

int main()
{
	cin >> N;
	
	cout << "N번째 계단 오르는 방법 수: " << step(N) << '\n';
	return 0;
}