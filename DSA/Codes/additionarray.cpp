#include<iostream>
using namespace std;

int sum(int arr[], int n) {
    if (n == 0) {
        return arr[0];
    } else {
        return arr[n] + sum(arr, n - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "Sum of the elements in the array: " << sum(arr, n - 1) << endl;
    return 0;
}

// =====================================

#include <iostream>
using namespace std;

int main() {

    int array[] = {5, 12, 3, 8, 15, 7, 20};
    int count = 0;

    for (int i = 0; i < 7; ++i) {
        if (array[i] > 10) {
            count++;
        }
    }

    cout << "Count of numbers greater than 10: " << count << endl;
    return 0;
}

// ====================================

