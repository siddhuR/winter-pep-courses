/*Problem Statement
Ragul is learning about hash tables and wants to implement 
a simple hash table using linear probing to store a collection 
of integer keys. He is looking for your help to write a program 
that takes a size for the hash table and a list of keys as input 
and then applies linear probing to store these keys in the hash table.

Example
Input 
8
6
41 27 63 95 87 34

Output 
1 3 7 0 2 4 

Explanation
The given process involves using a hash function to determine the 
initial index for each key in a hash table, utilizing the modulo 
operation (key%size).

If the calculated index is already occupied, linear probing is
 employed to find the next available slot by incrementing the 
 index and taking the modulo of the size until an empty slot is located.

Key 41 is hashed to index 1, and since the slot is unoccupied, it is stored at index 1, resulting in the output "1."
Key 27 is hashed to index 3, stored at index 3, and the output is "3."
Key 63 is hashed to index 7, and as the slot is available, it's stored at index 7, yielding "7."
However, both key 95 and key 87 hash to index 7, leading to the use of linear probing.
 Key 95 occupies index 0, resulting in the output "0," and key 87 goes to index 1, 
 producing "2."
Finally, key 34 is hashed to index 2, which is unoccupied, and thus, it is stored at
 index 2, resulting in the output "4."

 Input Format 
The first line of input consists of an integer N, representing the size of the hash table.

The second line of input consists of an integer M, representing the number of keys.

The third line of input consists of M space-separated integers, denoting the keys.

 Output Format 
The output displays M space-separated integers, representing the hash indices for each key using the division method.

 Constraints 
The test cases will fall under the following constraints:

1 = N = 10

1 = M = 100

 Sample Input  
5
3 
10 11 12

Sample Output 
0 1 2 
*/
#include <stdio.h>

#define SIZE 100

int calHash(int key, int size) {
    return key % size;
}

int main() {
    int size, numKeys;
    scanf("%d", &size);
    scanf("%d", &numKeys);

    int keys[numKeys];
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    for (int i = 0; i < numKeys; ++i) {
        scanf("%d", &keys[i]);
    }

    for (int i = 0; i < numKeys; ++i) {
    	
        int index = calHash(keys[i], size);
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
        }
        hashTable[index] = keys[i];
        printf("%d ", index);
    }

    return 0;
}
