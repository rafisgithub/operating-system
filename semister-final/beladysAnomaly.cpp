#include <bits/stdc++.h>

using namespace std;

void pageFaults(int fSize, int* ref, int len) {

    int* arr = new int[fSize];

    // Initialize frames
    for (int i = 0; i < fSize; i++) {
        arr[i] = -1;
    }

    int cnt = 0;       // Page fault count
    int start = 0;     // FIFO pointer

    for (int i = 0; i < len; i++) {

        int var = ref[i];
        bool flag = false;

        // Check if page already exists
        for (int j = 0; j < fSize; j++) {
            if (arr[j] == var) {
                flag = true;
                break;
            }
        }

        // Page fault occurs
        if (!flag) {

            arr[start] = var;
            start = (start + 1) % fSize;

            cnt++;
        }
    }

    cout << "When the number of frames are " << fSize<< ",";
    cout << " the number of page faults are :"<< cnt << endl;

    delete[] arr;
}


int main() {

    cout << "Belady's Anomaly" << endl;

    int refer[] = {1,2,3,4,1,2,5,1,2,3,4,5};

    int len = sizeof(refer) / sizeof(refer[0]);

    int frame_size = 3;
    pageFaults(frame_size, refer, len);

    frame_size = 4;
    pageFaults(frame_size, refer, len);

    return 0;
}