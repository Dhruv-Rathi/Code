#include <bits/stdc++.h>
using namespace std;
int t[400400];
void build(int id, int l, int r) {
	if (l == r) {
		t[id] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	t[id] = t[id * 2] + t[id * 2 + 1];
}
void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r)
		return;
	if (l == r) {
		t[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, pos, val);
	update(id * 2 + 1, mid + 1, r, pos, val);
	t[id] = t[id * 2] + t[id * 2 + 1];
}
int query(int id, int l, int r, int lq, int rq) {
	if (l > rq || r < lq)
		return 0;
	if (lq <= l && rq >= r)
		return t[id];
	int mid = (l + r) / 2;
	return query(id * 2, l, mid, lq, rq) + query(id * 2 + 1, mid + 1, r, lq, rq);
}
int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<set<int>> v(26);
	for (int i = 0; i < n; i++)
		v[s[i] - 'a'].insert(i);
	int ans = 0;
	build(1, 1, n);
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		char c = s[i];
		int cur = *v[s[i] - 'a'].begin();
		v[s[i] - 'a'].erase(v[s[i] - 'a'].begin());
		// cout << cur << " ";
		int inc = query(1, 1, n, 1, cur + 1);
		int new_cur = cur + inc;
		ans += (new_cur - i);
		update(1, 1, n, 1, 1);
		update(1, 1, n, cur + 1, -1);
	}
	cout << ans << "\n";
}