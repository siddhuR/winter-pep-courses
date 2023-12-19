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