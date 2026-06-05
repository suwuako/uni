#include <iostream>
using namespace std;

int main() {
    int days;
  
    cin >> days;

    int hunger[100001];
    int prices[100001];

    for (int i = 0; i < days; i++) {
        cin >> hunger[i];
        cin >> prices[i];
    }

    int lowest = prices[0];
    int running_total = 0;
    for (int i = 0; i < days; i++) {
        if (prices[i] < lowest) {
            lowest = prices[i];
        }

        running_total += lowest * hunger[i];
    }

    cout << running_total << "\n";
}
