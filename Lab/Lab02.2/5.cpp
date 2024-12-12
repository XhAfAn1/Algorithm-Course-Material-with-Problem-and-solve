
#include <iostream>

using namespace std;

void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int assignMiceToHoles(int mice[], int holes[], int n) {
    sort(mice, n);
    sort(holes, n);

    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        int time = abs(mice[i] - holes[i]);
        if (time > maxTime) {
            maxTime = time;
        }
    }
    return maxTime;
}

int main() {
    int n;
    cout << "Enter the number of mice and holes: ";
    cin >> n;

    int mice[n], holes[n];
    cout << "Enter positions of mice: ";
    for (int i = 0; i < n; i++) {
        cin >> mice[i];
    }
    cout << "Enter positions of holes: ";
    for (int i = 0; i < n; i++) {
        cin >> holes[i];
    }

    int minTime = assignMiceToHoles(mice, holes, n);
    cout << "Minimum time for all mice to get into holes: " << minTime << endl;

    return 0;
}
