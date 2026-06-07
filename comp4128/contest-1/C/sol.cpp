#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define space << " " << 
#define pause sleep(1)


const int s = 8;
char chessboard[s][s];


int main() {
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      cin >> chessboard[i][j];
    }
  }

  cout << chessboard << endl;
}
