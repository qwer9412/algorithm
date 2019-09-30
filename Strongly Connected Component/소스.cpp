#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
#define maxN 10001
vector<int> link[maxN];
vector<int> rev[maxN];
int n, e;
stack<int> order;
bool visit[maxN];
int myGroup[maxN];
vector<int> groupV[maxN];
void makeOrder(int cur) {
	if (visit[cur] == true) {
		return;
	}

	visit[cur] = true;

	for (int nxt : link[cur]) {
		makeOrder(nxt);
	}

	order.push(cur);
}
void makeGroup(int cur, int group) {
	if (visit[cur] == false) {
		return;
	}

	visit[cur] = false;
	myGroup[cur] = group;
	groupV[group].push_back(cur);

	for (int nxt : rev[cur]) {
		makeGroup(nxt, group);
	}
}
int main() {
	scanf("%d %d", &n, &e);
	
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		makeOrder(i);
	}

	int group = 0;
	while (order.empty() == false) {
		int cur = order.top();
		order.pop();

		if (visit[cur] == false) {
			continue;
		}

		makeGroup(cur, group++);
	}

	printf("%d\n", group);
	
	for (int i = 1; i <= n; i++) {
		if (visit[myGroup[i]] == true) {
			continue;
		}

		visit[myGroup[i]] = true;
		sort(groupV[myGroup[i]].begin(), groupV[myGroup[i]].end());

		for (int j : groupV[myGroup[i]]) {
			printf("%d ", j);
		}
		printf("-1\n");
	}

	return 0;
}