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
  sort(quest_points, quest_points + num_quests, greater<ll>());

  // could use points[0] but easier to just index precomp[1] to represnet k = 1
  precomputed_cycles[0] = 0;
  for (int i = 1; i <= num_quests; i++) {
    precomputed_cycles[i] = precomputed_cycles[i - 1] + quest_points[i - 1];
  }
}

// bool based on k-days (if we can meet coin limit in k days)
// returns 1 if true, 0 if false
// -1 if impossible or infinity
// O(1)
int checker(ll quests, ll days, ll coins, ll k) {
  ll full_cycles = days / (k+1);
  ll remainder_cycle = days % (k + 1);
  ll cycle_coin = precomputed_cycles[min(quests, k+1)];
  ll max_coins = cycle_coin * full_cycles + precomputed_cycles[min(remainder_cycle, quests)];
  bool ret = max_coins >= coins;
  return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 0;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
      ll num_quests, num_coins, num_days;
      cin >> num_quests >> num_coins >> num_days;

      for (int i = 0; i < num_quests; i++) {
        cin >> quest_points[i];
      }

      // O(n)
      precompute(num_days, num_quests);

      // check if Impossible or Infinity
      ll meow = quest_points[0] * num_days;
      if (meow < num_coins) {
        cout << "Impossible\n";
        continue;

      }
      int s = min(num_days, num_quests);
      ll sum = precomputed_cycles[s];
      if (sum >= num_coins) {
        cout << "Infinity\n";
        continue;
      }
    ll lo = 0;
    ll hi = num_days - 1;
    ll ret;

    while (lo <= hi) {
      ll index = (lo + hi) / 2;
      if (checker(num_quests, num_days, num_coins, index)) {
        ret = index;
        lo = index + 1;
      } else {
        hi = index - 1;
      }
    }
    cout << ret << endl;

    }
}
