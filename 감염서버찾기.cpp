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
	cout << "������ ������ȣ: " << N << '\n';

	// ������ N��° ���� ����
	server[N] = N; 

	// ������ ���� ����-Ŭ���̾�Ʈ ����
	for (int i = 1; i <= TOTAL; i++)
		c_infection(client, server[i]);
	
	// ���� ������ȣ Ȯ��
	for (int i = 1; i <= TOTAL; i++)
	{
		// Ŭ���̾�Ʈ �������η� 10���� �����
		arr_val = 0; 
		for (int j = 0; j < 10; j++)
			if(client[j])
				arr_val += pow(2, j);

		if (i == arr_val)
		{
			cout << "����: " << i << '\n';
			break;
		}
	}

	return 0;
}