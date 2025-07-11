#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int k, int p) {
  int res = 1 % p;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// O(NlgN) 因为c[a][b] = a!/[(b-a)! * b!]，可以预处理阶乘fact和阶乘的逆infact
int main() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i ++ ) {
    fact[i] = (LL)fact[i - 1] * i % mod;
    infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
  }

  int n;
  scanf("%d", &n);
  while (n -- ) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
  }
  return 0;
}