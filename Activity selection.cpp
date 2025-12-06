#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
 int start[100], finish[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter start time of activity " << i + 1 << ": ";
        cin >> start[i];
        cout << "Enter finish time of activity " << i + 1 << ": ";
        cin >> finish[i];
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (finish[j] > finish[j+1]) {
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }
    cout << "\nSelected Activities (optimal):\n";
    cout << "(" << start[0] << ", " << finish[0] << ") ";
    int lastFinish = finish[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            cout << "(" << start[i] << ", " << finish[i] << ") ";
            lastFinish = finish[i];
            count++;
        }
    }

    cout << "\nTotal selected: " << count << endl;

    return 0;
}

