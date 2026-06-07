#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define space << " " << 
#define pause sleep(1);

ll quest_points[2 * 1000000] = {};
ll precomputed_cycles[2 * 1000000] = {};

// for n-days apart, (i.e. cannot do the same quest for n days), you would need to pick n
// days starting from the top of quest_points so that means that you would pick days
// quest_pionts[0..n] (n inclusive) so if you sum that its O(n)
//
// the checker then can have a loop of i - n, so it wait nvm we can just do division and
// that O(1)
void precompute(ll days, ll num_quests) {
  qsort(quest_points, num_quests, sizeof(long long), [](const void *a, const void *b){
    const ll arg1 = *static_cast<const long long*>(a);
    const ll arg2 = *static_cast<const ll*>(b);
    if (arg1 > arg2) return -1;
    if (arg1 < arg2) return 1;
    return 0;
  });

  // could use points[0] but easier to just index precomp[1] to represnet k = 1
  precomputed_cycles[0] = 0;
  for (int i = 1; i <= num_quests; i++) {
    precomputed_cycles[i] = precomputed_cycles[i - 1] + quest_points[i - 1];
  }
}

// bool based on k-days (if we can meet coin limit in k days)
// returns 1 if true, 0 if false
// -1 if impossible or infinity
int checker(ll quests, ll days, ll coins, ll k) {
  // check if Impossible or Infinity
  ll meow = quest_points[0] * days;
  if (meow < coins) {
    cout << "Impossible\n";
    return -1;

  }
  int s = min(days, quests);
  ll sum = precomputed_cycles[s];
  if (sum >= coins) {
    cout << "Infinity\n";
    return -1;
  }

  ll full_cycles = days / (k+1);
  ll remainder_cycle = days % (k + 1);
  ll cycle_coin = precomputed_cycles[min(quests, k+1)];
  ll max_coins = cycle_coin * full_cycles + precomputed_cycles[min(remainder_cycle, quests)];
  cout << cycle_coin space full_cycles << endl;
  cout << max_coins << endl;;
  bool ret = max_coins >= coins;
  return ret;
}

int32_t main() {
    int test_cases = 0;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        ll num_quests, num_coins, num_days;
        cin >> num_quests >> num_coins >> num_days;

        for (int i = 0; i < num_quests; i++) {
            cin >> quest_points[i];
        }

        precompute(num_days, num_quests);
        int j = checker(num_quests, num_days, num_coins, 4);
        if (j == 1) {
          cout << "this is doable" << endl;
        } else if (j == 0) {
          cout << "not doable" << endl;
        } 

        // bin search
        // find the first occurence of "greater" immediately after a "less"
        // logn here...
        /*
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

          int c = checker(num_quests, num_days, num_coins, k);
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
          */
    }
}

/*
// im writing some bullshittttt LMAO

// returns -1 if impossible, -2 if infinity, returns 1 if true and 0 if false
// worst case O(num_days * num_quests) given large k
// so basically n^2
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
unused lol

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
        // logn here...
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
*/
