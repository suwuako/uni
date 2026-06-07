#include <iostream>
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
  dump_arr(end);
  while (true) {
    while (start_times[l] < pvalue && l <= r) l++;
    while (start_times[r] > pvalue && l <= r) r--;
    if (l > r) break;
    swap(l, r);
    dump_arr(end);
  }
  swap(start, r);
  return r;
}

void quicksort(ll start, ll end) {
  if (start >= end) return;

  dump_arr(end);
  ll pivot_index = partition(start, end);
  cout << "pivot index " << pivot_index << endl;
  dump_arr(end);
  quicksort(start, pivot_index - 1);
  quicksort(pivot_index + 1, end);
}

int main() {
  ll meetings;
  cin >> meetings;

  for (int i = 0; i < meetings; i++) {
    ll start, end;
    cin >> start >> end;
    start_times[i] = start;
    end_times[i] = end;
  }

  quicksort(0, meetings-1);
}

