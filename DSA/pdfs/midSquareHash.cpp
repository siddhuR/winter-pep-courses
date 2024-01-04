/* Problem Statement



Reema, a prospective computer science student, 
has developed a keen interest in data structures and algorithms. 
She has just been introduced to the concept of hash functions 
and is eager to build a basic hash table using the mid-square hashing method.

Reema's assignment is to design a program that accepts 
a list of keys as input, employs the Mid-Square Hashing method 
(single digit 0–9) to hash these keys, and organizes them within 
a hash table (size 100). Her goal is to efficiently resolve 
any collisions by implementing linear probing.

Example
Input 
6
13 15 16 17 18 19
Output 
Index 2: Key 15
Index 3: Key 18
Index 5: Key 16
Index 6: Key 13
Index 7: Key 19
Index 8: Key 17

Explanation
Note:
The formula (squared / 10) extracts the last two digits, 
and % 10 ensures middleDigit is within 0 to 9, 
limiting the hash index to the table size.

The midSquareHash function is used to calculate the hash index for each key.
For the key 13, the square is 169, and the middle digit is 6. So, hashIndex is set to 6 % 100 = 6.
For the key 15, the square is 225, and the middle digit is 2. So, hashIndex is set to 2 % 100 = 2.
For the key 16, the square is 256, and the middle digit is 5. So, hashIndex is set to 5 % 100 = 5.
For the key 17, the square is 289, and the middle digit is 8. So, hashIndex is set to 8 % 100 = 8.
For the key 18, the square is 324, and the middle digit is 2. So, hashIndex is set to 2 % 100 = 2. (Collision with key 15)
For the key 19, the square is 361, and the middle digit is 6. So, hashIndex is set to 6 % 100 = 6. (Collision with key 13)

Since there are collisions, linear probing is used to find the next available slot in the hash table.
Key 15 is placed at index 2, Key 18 is placed at index 3, 
Key 16 is placed at index 5, Key 13 is placed at index 6, 
Key 19 is placed at index 7, and Key 17 is placed at index 8.

Note:
The formula (squared / 10) extracts the last two digits, 
and % 10 ensures middleDigit is within 0 to 9, 
limiting the hash index to the table size.

 Input Format 
The first line of input consists of an integer n, 
representing the number of keys to be inserted into the hash table.

The second line of input consists of n integers 
representing the keys that Reema wants to hash.

 Output Format 
The output displays the value for each 
index in the hash table in the following format:
If the slot is occupied, print "Index {i}: Key {k},"
 where {i} is the single-digit index in the hash table
  and {k} is the key stored at that index.
 
 Constraints 
The test cases will fall under the following constraints:
hash table size = 100
1 <= n<= 10
10 <= key <= 100


Sample Input   
5
7 8 9 10 3
Sample Output
Index 0: Key 10
Index 1: Key 3
Index 4: Key 7
Index 6: Key 8
Index 8: Key 9
 */
#include <stdio.h>

int midSquareHash(int key, int tableSize, int r) {
    int squared = key * key;
    int middleDigit = (squared / 10) % 10;
    int hashIndex = middleDigit % tableSize;
    
    return hashIndex;
}

int main() {
    int tableSize = 100;
    int numKeys;
    scanf("%d", &numKeys);
    int keys[numKeys];
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &keys[i]);
    }
    int hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }
    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int hashIndex = midSquareHash(key, tableSize, 1);
        while (hashTable[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % tableSize;
        }
        hashTable[hashIndex] = key;
    }
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: Key %d\n", i, hashTable[i]);
        }
    }
    return 0;
}
