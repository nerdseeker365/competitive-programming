// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/road-1-63e2e618/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef set<int> si;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi cache;
vvi sets;

int s(const vi &v, int i, int k) {
  if (cache[i][k] != -1) return cache[i][k];
  int c = 0;
  for (int j = 0; j <= k; j++) {
    int a = v[i];
    int b = a + j;
    if (b <= 50) {
      int a = sets[b][i];
      if (a) c = max(c, 1 + s(v, a, k - j));
    }
    b = a - j;
    if (b >= 0) {
      int a = sets[b][i];
      if (a) c = max(c, 1 + s(v, a, k - j));
    }
  }
  cache[i][k] = c;
  return c;
}

int main() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  cache = vvi(n);
  for (int i = 0; i < n; i++) cache[i] = vi(k + 1, -1);
  for (int i = 0; i < n; i++) cin >> v[i];
  sets = vvi(51);
  for (int i = 0; i <= 50; i++) {
    sets[i] = vi(n);
    int a = 0;
    for (int j = n - 1; j >= 0; j--) {
      sets[i][j] = a;
      if (v[j] == i) a = j;
    }
  }
  cout << 1 + s(v, 0, k) << endl;
}
