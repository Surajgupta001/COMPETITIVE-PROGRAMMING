#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int n){
    string binary = "";

    while(n > 0){
        int remainder = n % 2;
        binary += to_string(remainder);
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary){
    int decimal = 0;
    int base = 1; // Initialize base value to 1, i.e., 2^0

    int len = binary.length();
    for(int i = len - 1; i >= 0; i--){
        if(binary[i] == '1'){
            decimal += base;
        }
        base *= 2; // Update base to the next power of 2
    }
    return decimal;
}

int main(){
    int n;
    cin>>n;
    
    string binary = decimalToBinary(n);
    cout << "Binary representation: " << binary << endl;
    
    int decimal = binaryToDecimal(binary);
    cout << "Decimal representation: " << decimal << endl;
    
    return 0;
}