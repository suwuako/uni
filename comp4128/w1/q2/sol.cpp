#include <iostream>
using namespace std;

// from the starting index in array, find the maximal value up until sign flips
int64_t get_max_in_signed_seq(int *seq, int *index_start, int limit) {
    bool positive = (seq[*index_start] >= 0);
    int *i = index_start;
    int max = seq[*index_start];

    if (positive) {
        while (seq[*i] > 0 && *i < limit) {
            if (max < seq[*i]) {
                max = seq[*i];
            }
            (*i)++;
        }

    } else {
        while (seq[*i] < 0 && *i < limit) {
            if (max < seq[*i]) {
                max = seq[*i];
            }
            (*i)++;
        }
    }

    return max;
}

int main() {
    int sequences; 
    cin >> sequences;


    int sequence_buf[2 * 1000000];
    int seq_no;
    for (int seq = 0; seq < sequences; seq++) {
        cin >> seq_no;
        for (int i = 0; i < seq_no; i++) {
            cin >> sequence_buf[i];
        }

        int64_t running_total = 0;
        int index = 0;
        while (index < seq_no) {
            running_total += get_max_in_signed_seq(sequence_buf, &index, seq_no);
        }
        cout << running_total << "\n";
        /*
        // three cases: check if buf[0] buf[i] signs match
        // if they match, then the longest subseqeunces starts and ends with said signs
        // if they alternate, then check for pos first, then neg first, compare.
        int running_total = 0;
        int index = 0;
        if (sequence_buf[0] > 0 && sequence_buf[seq_no - 1] > 0 || 
            sequence_buf[0] < 0 && sequence_buf[seq_no - 1] < 0) {
            // while sign hasnt changed 
            while (index < seq_no) {
                running_total += get_max_in_signed_seq(sequence_buf, &index, seq_no);
            }
            cout << running_total << "\n";
        } else {
            // try both (start with +ve first)
            while (index < seq_no) {
                running_total += get_max_in_signed_seq(sequence_buf, &index, seq_no);
            }
            index = 0;
            int running_total_two = 0;
            // skip 
        }
        */
    }
}
