#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define space << " " << 
#define pause sleep(1)


const int s = 8;
uint64_t chessboard;
uint64_t queen_bitmasks[64];

// first is row, second is col
pair<int, int> find_coordinate(int input) {
  int x = input / 8;
  int y = input % 8;
  pair<int, int> ret;
  ret.first = x;
  ret.second = y;
  return ret;
}

void print_board(uint64_t table) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int k = (table >> (i * 8 + j)) & 1;
      if (!k) cout << "." << " ";
      else cout << k << " ";
    }
    cout << endl;
  }
}

// 64! / 60!
// constant time...
int main() {
  // init bitmasks
  // O(64 * 7 )
  for (int i = 0; i < 64; i++) {
    pair<int, int> meow = find_coordinate(i);
    int row = meow.first;
    int col = meow.second;

    for (int r = 0; r < 8; r++) {
      queen_bitmasks[i] |= (1ULL << (r * 8 + col)); // entire column
    }
    for (int c = 0; c < 8; c++) {
      queen_bitmasks[i] |= (1ULL << (row * 8 + c)); // entire row
    }
    for (int d = -7; d <= 7; d++) {
      int nr = row + d, nc = col + d;
      if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8)
        queen_bitmasks[i] |= (1ULL << (nr * 8 + nc)); // main diagonal
      nc = col - d;
      if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8)
        queen_bitmasks[i] |= (1ULL << (nr * 8 + nc)); // anti diagonal
      }
  }

  //input
  for (int i = 0; i < 64; i++) {
    char j;
    cin >> j;
    pair<int, int> ppp = find_coordinate(i);

    if (j == '*') {
      chessboard |= (1ULL << (ppp.first * 8 + ppp.second));
    }
  }

  ll tally = 0;
  pair<int, int> example[4];
  bool set_example = false;
  // ugly...
  for (int q1 = 0; q1 < 64; q1++) {
    uint64_t arggghghhhhh = queen_bitmasks[q1];
    for (int q2 = q1+1; q2 < 64; q2++) {
      uint64_t two = arggghghhhhh | queen_bitmasks[q2];
      for (int q3 = q2+1; q3 < 64; q3++) {
        uint64_t three = two | queen_bitmasks[q3];
        for (int q4 = q3+1; q4 < 64; q4++) {
          uint64_t four = three | queen_bitmasks[q4];
          if ((four & chessboard) == chessboard) {
            if (!set_example) {
              set_example = true;
              example[0] = find_coordinate(q1);
              example[1] = find_coordinate(q2);
              example[2] = find_coordinate(q3);
              example[3] = find_coordinate(q4);
            }
            tally ++;
          }
        }
      }
    }
  }

  cout << tally << endl;;
  if (tally != 0) {
  for (int i = 0; i < 4; i++) {
    pair<int, int> a = example[i];
    cout << (char) ('a' + a.first) << a.second + 1 << endl;
  }
  }

  for (int i = 0;i < 64; i++) {
    cout << queen_bitmasks[i] << endl;
  }

  print_board(5272058195805358472);
}
