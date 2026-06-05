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

  bool unsolved = true;
  int factor = len / 2;
  int current = factor;
  while(unsolved) {
    if (current == 0 && arr[current] == 1) {
      cout << "found target at index " << current << endl;
      break;
    }
    if (arr[current] == 1 && arr[current - 1] == -1) {
      cout << "found target at index " << current << endl;
      break;
    }

    if (arr[current] > target) {
      current -= factor;
    } else if (arr[current] < target) {
      current += factor;
    }
    if (factor > 1) {
      factor /= 2;
    } else {
      factor = 1;
    }
  }
}
