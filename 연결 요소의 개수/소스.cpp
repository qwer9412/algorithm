#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> link[1001];
bool visit[1001];
void dfs(int cur) {
	if (visit[cur] == true) {
		return;
	}

	visit[cur] = true;

	for (int nxt : link[cur]) {
		dfs(nxt);
	}
}
int main() {
	int n, m;
	int ans = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == true) {
			continue;
		}

		ans++;
		dfs(i);
	}

	printf("%d", ans);
	return 0;
}