#include <cstdio>
#include <vector>
//#include <algorithm>
using namespace std;
const int MAX = 1000;

int main() 
{
	vector<int> prime;
	bool isPrime[MAX + 1];
	fill(isPrime + 2, isPrime + MAX, true);

	for (int i = 2; i <= MAX; i++) 
	{
		if (isPrime[i]) 
			prime.push_back(i);
		for (int j = i * 2; j <= MAX; j += i)
			isPrime[j] = false;
	}
	
	for (int i = 0; i < prime.size(); i++) 
	{
		printf("%4d", prime[i]);

		if (i % 10 == 9)
			printf("\n");
	}
}