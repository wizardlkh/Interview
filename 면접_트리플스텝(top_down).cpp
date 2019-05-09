#include<iostream>

using namespace std;

long long N, d[1000];


long long step(int n)
{
	if (d[n] != 0LL)
		return d[n];

	d[n] = step(n - 1) + step(n - 2) + step(n - 3);

	return d[n];
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

	for (int i = 1; i <= N; i++)
		cout << i << "��° ��� ������ ��� ��: " << d[i] << '\n';

	return 0;
}