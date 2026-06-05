#include <iostream>

using namespace std;

int main() {
    int num_books;
    int total_time;
    int books[1000000] = {};

    cin >> num_books >> total_time;

    for (int i = 0; i < num_books; i++) {
        cin >> books[i];
    }

    // count backwards, greedily grab as big as possible, keep talley. 
    int max_read = 0;
    int running_read = 0;
    int running_total = 0;
    int last_accepted_index = num_books-1;
    for (int i = num_books - 1; i >= 0; i--) {

        if (running_total + books[i] <= total_time) {
            running_read++;
        } else {
            // keep discarding until range is acceptable again
            while (running_total + books[i] > total_time) {
                running_total -= books[last_accepted_index];
                last_accepted_index--;
                running_read--;
            }
            running_read++;
        }
        running_total += books[i];

        if (running_read > max_read) max_read = running_read;
    }

    cout << max_read << endl;
}
