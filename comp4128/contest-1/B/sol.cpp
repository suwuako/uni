#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define space << " " << 
#define pause sleep(1)

char rounds[200100];
char print[200100];

int main() {
  ll n;
  ll turning_index;
  ll num_b = 0;
  ll num_a = 0;
  ll sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rounds[i];
    if (rounds[i] == 'A') num_a++;
    else num_b++;
    sum++;
  }

  char winner, loser;
  int win_count, lose_count;
  if (num_a > num_b) {
    // A wins
    winner = 'A';
    win_count = num_a;
    loser = 'B';
    lose_count = num_b;
  } else {
    // B wins
    winner = 'B';
    win_count = num_b;
    loser = 'A';
    lose_count = num_a;
  }


  // comment out later
  for (int i = 0; i < n; i++) {
    print[i] = '_';
  }


  ll lo = 0;
  ll hi = n - 1;
  ll s = 0;
  print[n] = '\0';
  // find first winner occurence
  while (hi > lo && rounds[hi] != winner) {
    print[hi] = '_';
    hi--;
  }
  s++;
  win_count--;
  print[hi] = winner;
  hi--;

  bool found_win = false;
  bool found_lose = false;
  // take one off each until you cant take one from both until both are 0
  while (win_count > 0 && lose_count > 0) {
    while (win_count > 0 && lose_count > 0) {
      if (rounds[hi] == winner) {
        found_win = true;
        break;
      } else {
        print[hi] = '_';
        hi--;
        lose_count--;
      }
    }

    while (win_count > 0 && lose_count > 0) {
      if (rounds[lo] == loser) {
        found_lose = true;
        break;
      } else {
        print[lo] = '_';
        lo++;
        win_count--;
      }
    }

    if (found_win && found_lose) {
      print[lo] = loser;
      print[hi] = winner;
      win_count--;
      lose_count--;
      lo++;
      hi--;
      s += 2;
      found_win = false;
      found_lose = false;
    } else {
      break;
    }

  }

  cout << s << endl;
  cout << print << endl;
}
