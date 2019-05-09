#include<iostream>

using namespace std;

long long N, d[1000];


void step(int n)
{
	if (d[n] != 0LL)
		return;

	for (int i = 4; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
}

void init()
{
	d[1] = 1LL;
	d[2] = 2LL;
	d[3] = 4LL;
}

int main()
{
	cin >> N; 
	init();

	step(N);

	for(int i=1; i <= N; i++)
		cout << i <<  "번째 계단 오르는 방법 수: " << d[i] << '\n';
	
	return 0;
}