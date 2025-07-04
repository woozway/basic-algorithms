#include <iostream>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N][N];

// 因为每种物品数量有限制，所有不能和完全背包一样计算
// f[i,j] = max(f[i-1,j], f[i-1,j-vi] + wi)不可行
int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];

  for (int i = 1; i <= n; i ++ )
    for (int j = 0; j <= m; j ++ )
      for (int k = 0; k <= s[i] && v[i] * k <= j; k ++ )
        f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);

  cout << f[n][m] << endl;
  return 0;
}