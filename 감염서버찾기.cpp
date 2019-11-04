#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#define TOTAL 1000
using namespace std;
int N = 0, arr_val, server[TOTAL + 1]; // 
bool client[11];

void c_infection(bool arr[], int sever_num)
{
	for (int i = 0; i < 10; i++)
		if (sever_num & (1 << i))
			arr[i] = true;
}

int main()
{
	srand((unsigned int)time(NULL));
	N = rand()%1000 + 1;
	cout << "감염된 서버번호: " << N << '\n';

	// 랜덤수 N번째 서버 감염
	server[N] = N; 

	// 로직에 따른 서버-클라이언트 접촉
	for (int i = 1; i <= TOTAL; i++)
		c_infection(client, server[i]);
	
	// 감염 서버번호 확인
	for (int i = 1; i <= TOTAL; i++)
	{
		// 클라이언트 감염여부로 10진수 만들기
		arr_val = 0; 
		for (int j = 0; j < 10; j++)
			if(client[j])
				arr_val += pow(2, j);

		if (i == arr_val)
		{
			cout << "정답: " << i << '\n';
			break;
		}
	}

	return 0;
}