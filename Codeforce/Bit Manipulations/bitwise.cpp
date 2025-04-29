#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;

    cout << "Bitwise OR: " << (a | b | c) << endl;
    cout << "Bitwise AND: " << (a & b & c) << endl;
    cout << "Bitwise XOR: " << (a ^ b ^ c) << endl;

    cout << "Bitwise NOT for a: " << (~a) << endl;
    cout << "Bitwise NOT for b: " << (~b) << endl;
    cout << "Bitwise NOT for c: " << (~c) << endl;
    
    return 0;
}


// ==================== NOTES ====================
/*
XOR: When there are odd numbers of 1's -> 1 NAHI TO else -> 0

A   B  A^B
0   0  0
0   1  1
1   0  1
1   1  0

Properties of XOR:
------------------>
1. A^A = 0 (XOR of a number with itself is 0)
2. A^0 = A (XOR of a number with 0 is the number itself)
3. A^B = B^A (XOR is commutative)
4. A^(B^C) = (A^B)^C (XOR is associative)
*/

/*
NOT: Inverts the bits of a number. For example, if a = 5 (binary 0101), then ~a = -6 (binary 1010 in two's complement representation).
The NOT operation flips all bits, so 0s become 1s and 1s become 0s.

(~n) = -(n+1) in two's complement representation.
*/

/*
Left Shift Operator (<<): Shifts the bits of a number to the left by a specified number of positions. Each left shift operation effectively multiplies the number by 2.

x = 22 -> 101110(Binary)
x << 1 = 1011100 -> 44 (Binary) , i.e. one extra 0 is added to the right side.

In General - (x << n) = x * 2^n and one extra n 0's are added to the right side.
*/ 

/*
Right Shift Operator (>>): Shifts the bits of a number to the right by a specified number of positions. Each right shift operation effectively divides the number by 2.
The right shift operator can be either arithmetic (sign bit is preserved) or logical (fills with 0s).

x = 22 -> 101110(Binary)
x >> 1 = 10111 -> 11 (Binary) , i.e. one bit is removed from the right side.
x >> 2 = 1011 -> 2 (Binary) , i.e. two bits are removed from the right side.

In General - (x >> n) = x / 2^n, effectively removing n bits from the right side.
*/

/*
Tricks and Properties:
---------------------->

1. A + B = (A & B) + (A | B)
2. A - B = (A & ~B) + (A | B)
3. A * B = (A & B) << 1
4. A / B = (A >> 1) + (B << 1)
5. A % B = (A & B) - (A | B)
6. A ^ B = (A & ~B) + (~A & B)
7. A | B = (A & B) + (~A & ~B)
8. A & B = A + B - A ^ B
9. A << n = A * 2^n
10. A >> n = A / 2^n
11. ~A = -A - 1
12. A << 1 = A * 2, i.e., left shifting by 1 bit is equivalent to multiplying by 2.
13. A >> 1 = A / 2, i.e., right shifting by 1 bit is equivalent to dividing by 2.
14. A ^ 0 = A, i.e., XORing with 0 leaves the number unchanged.



Set/Flip/Clear Bits:
--------------------->
1. Set a bit: A = A | (1 << i) (Set the ith bit of A to 1)
2. Clear a bit: A = A & ~(1 << i) (Clear the ith bit of A to 0)
3. Flip a bit: A = A ^ (1 << i) (Toggle the ith bit of A)
4. Check a bit: (A & (1 << i)) != 0 (Check if the ith bit of A is set)
5. A & 1 = 1 (Odd) or 0 (Even)
6. Count set bits: int count = __builtin_popcount(A); (Count the number of set bits in A)
7. Get the ith bit: (A >> i) & 1 (Get the value of the ith bit of A)
8. Get the bit length: int length = sizeof(A) * 8; (Get the number of bits in A)
9. Get the bit representation: for(int j = length - 1; j >= 0; j--) cout << ((A >> j) & 1); (Print the bit representation of A)
10. Get the maximum number of bits: int maxBits = (1 << length) - 1; (Get the maximum number of bits that can be represented in A)
11. Get the minimum number of bits: int minBits = 1; (Get the minimum number of bits that can be represented in A)
12. (A & (A - 1)) == 0 (Check if A is a power of 2)
13. (A & -A) (Get the rightmost set bit of A)
14. (A | (A - 1)) (Set all bits to the right of the rightmost set bit of A)


Brian Kernighan's Algorithm:
=> This algorithm is used to count the number of set bits (1s) in a binary representation of a number.
It works by repeatedly flipping the least significant set bit of the number until the number becomes zero.

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1); // Flip the least significant set bit
        count++;
    }
    return count;
}
int main() {
    int a = 5, b = 3, c = 7;
    cout << "Number of set bits in a: " << countSetBits(a) << endl;
    cout << "Number of set bits in b: " << countSetBits(b) << endl;
    cout << "Number of set bits in c: " << countSetBits(c) << endl;
    return 0;
}
*/