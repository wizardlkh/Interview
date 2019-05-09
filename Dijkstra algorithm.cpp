// https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;
int node, edge, st, des, weight; 
vector< pair<int,int> > adj[1000];
bool vst[1000] = { false };
vector<int> d;

bool comp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

void dijk_bfs(int node)
{
	int now;

	queue<int> q;
	q.push(node);
	
	while (!q.empty())
	{
		now = q.front();
		q.pop();

		for (int i = 0; i < adj[now].size(); i++)
		{
			if (d[adj[now][i].first] == -1 || d[adj[now][i].first] > d[now] + adj[now][i].second)			
				d[adj[now][i].first] = d[now] + adj[now][i].second;		

			if (vst[adj[now][i].first] == false)
				q.push(adj[now][i].first);			
		}
		vst[now] = true;
	}
}

int main()
{
	cin >> node >> edge; // 6, 9
	
	for (int i = 0; i < edge; i++)
	{
		cin >> st >> des >> weight; // 
		adj[st].push_back({ des , weight });
	}

	for (int i = 1; i <= node; i++)
		sort(adj[i].begin(), adj[i].end(), comp);

	/*
	for (int i = 0; i < adj[1].size(); i++)
		cout << adj[1][i].second << '\n';
	*/	

	d.assign(node+1, -1);
	d[1] = 0;

	cout << '\n';
	for (int i = 1; i <= node; i++)
		cout << "d[" << i << "]: " << d[i] << '\n';

	cout << '\n';
	dijk_bfs(1);
	cout << "dijk_bfs ½ÇÇà ÈÄ: \n";

	for (int i = 1; i <= node; i++)
		cout << "d[" << i << "]: " << d[i] << '\n';

	return 0;
}