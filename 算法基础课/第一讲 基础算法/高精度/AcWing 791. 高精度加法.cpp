#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) { // C=A+B, A>=0, B>=0
  if (A.size() < B.size()) return add(B, A);

  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    t += A[i]; // 进位
    if (i < B.size()) t += B[i];
    C.push_back(t % 10);
    t /= 10;
  }
  if (t) C.push_back(t);

  return C;
}

int main() {
  string a, b;
  cin >> a >> b;

  vector<int> A, B; // 由低到高倒着存，方便加减运算
  for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
  for (int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

  auto C = add(A, B);

  for (int i = C.size()-1; i >= 0; i--) printf("%d", C[i]);
  cout << endl;

  return 0;
}