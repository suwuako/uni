#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define space << " " << 
#define pause sleep(1)

ll start_times[100100];
ll end_times[100100];

void dump_arr(ll size) {
  for (int i = 0; i < size + 1; i++) {
    cout << start_times[i] << ", ";
  }
  cout << endl;
}

ll medthree(ll start, ll end) {
  ll mid = (start + end) / 2;
  ll arr[3] = {start_times[start], start_times[mid], start_times[end]};
  std::sort(arr, arr + 3);
  if (arr[1] == start_times[start]) {
    return start;
  } else if (arr[1] == start_times[end]) {
    return end;
  } 
  return mid;
}

void swap(ll i, ll j) {
  ll a = start_times[i];
  ll b = start_times[j];
  start_times[i] = b;
  start_times[j] = a;

  ll c = end_times[i];
  ll d = end_times[j];
  end_times[i] = d;
  end_times[j] = c;
}


ll partition(ll start, ll end) {
  ll pivot = medthree(start, end);
  ll pvalue = start_times[pivot];
  swap(start, pivot);
  ll l = start + 1;
  ll r = end;
  while (true) {
    while (l <= r && start_times[l] < pvalue) l++;
    while (l <= r && start_times[r] > pvalue) r--;
    if (l > r) break;
    swap(l, r);
  }
  swap(start, r);
  return r;
}

void quicksort(ll start, ll end) {
  if (start >= end) return;

  ll pivot_index = partition(start, end);
  quicksort(start, pivot_index - 1);
  quicksort(pivot_index + 1, end);
}

int main() {
  // fuck my stupid chungus life i spent three+ hours implementing quicksort for it to be
  // SHIT
  // never using arrays again
  ll meetings;
  cin >> meetings;

  vector<pair<ll,ll>> meow(meetings);
  for (int i = 0; i < meetings; i++)
      cin >> meow[i].first >> meow[i].second;

  sort(meow.begin(), meow.end());
  for (int i = 0; i < meetings - 1; i++) {
      if (meow[i].second > meow[i+1].first) {
          cout << "No\n";
          return 0;
      }
  }
  cout << "Yes\n";

  /*
  for (int i = 0; i < meetings; i++) {
    ll start, end;
    cin >> start >> end;
    start_times[i] = start;
    end_times[i] = end;
  }

  quicksort(0, meetings - 1);
  for (int i = 0; i < meetings - 1; i++) {
    if (end_times[i] > start_times[i+1]) {
      cout << "No\n"; 
      return 0;
    }
  }
  cout << "Yes\n";
  */
}
