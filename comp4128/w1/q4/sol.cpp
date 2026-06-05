#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define space << " " << 
#define pause sleep(1);

int quest_points[2 * 1000000] = {};

// returns -1 if impossible, -2 if infinity, returns 1 if true and 0 if false
int verifier(int num_quests, int num_coins, int num_days, int k) {
  // check if Impossible or Infinity
  if (quest_points[0] * num_days < num_coins) {
    cout << "Impossible\n";
    return -1;

  }
  int sum = 0;
  int s = min(num_days, num_quests);
  for (int i = 0; i < s; i++) {
    sum += quest_points[i];
  }
  if (sum >= num_coins) {
    cout << "Infinity\n";
    return -1;
  }

  sum = 0;
  std::map<int, int> visited = {};
  for (int i = 0; i < num_days; i++) {
    for (int j = 0; j < num_quests; j++) {
      if (visited.count(j) == 0) {
        sum += quest_points[j];
        visited.insert({j, i});
        break;
      } else if (visited[j] + k < i) {
        sum += quest_points[j];
        visited[j] = i;
        break;
      }
    }
  }

  if (sum >= num_coins) {
    return 1;
  } else {
    return 0;
  }
}

int32_t cmp(const void * a, const void * b) {
    const int ja = *static_cast<const int*>(a);
    const int jb = *static_cast<const int*>(a);
    if (ja == jb) return 0;
    else if (ja < jb) return -1;
    else return 1; 
}

int32_t main() {
    int test_cases = 0;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        int num_quests, num_coins, num_days;
        cin >> num_quests >> num_coins >> num_days;

        for (int i = 0; i < num_quests; i++) {
            cin >> quest_points[i];
        }

        qsort(quest_points, num_quests, sizeof(long long), [](const void *a, const void *b){
              const int arg1 = *static_cast<const int*>(a);
              const int arg2 = *static_cast<const int*>(b);
              if (arg1 > arg2) return -1;
              if (arg1 < arg2) return 1;
              return 0;
            });

        // bin search
        // find the first occurence of "greater" immediately after a "less"
        bool solved = false;
        int k = num_days / 2;
        int factor = k;
        // solve[i] = -1 if less, 1 if greater 0 if not computed.
        int *solve = (int *) calloc(num_days, sizeof(int));
        while (!solved) {
          if (factor > 1) {
            factor /= 2;
          } else {
            factor = 1;
          }

          int c = verifier(num_quests, num_coins, num_days, k);
          if (c == 1) {
            solve[k] = 1;
            k += factor;
            if (k > num_days - 1)
              k = num_days - 1;

          } else if (c == 0) {
            solve[k] = -1;
            k -= factor;
            if (k < 0)
              k = 0;
          } else {
            k = -1;
            // -1
            break;
          }

          if (k == num_days - 1){
            if (solve[k] == 1) {
              break;
            }
          } else {
            if (solve[k] == 1 && solve[k+1] == -1) {
              break;
            }
          }
        }
        free(solve);
        if (k != -1) 
          cout << k << endl;
    }
}
