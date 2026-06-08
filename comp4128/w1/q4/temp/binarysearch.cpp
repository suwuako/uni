#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int len;
  int arr[10000];
  int target;
  cin >> len;

  for (int i = 0; i < len; i++) {
    cin >> arr[i];
  }
  cout << endl;

  sort(&arr[0], &arr[len]);


}
