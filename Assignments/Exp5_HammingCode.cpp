#include <iostream>
#include <cmath>
using namespace std;


bool isPowerOfTwo(int position) {
    return (position & (position - 1)) == 0;
}

int main() {
    int m;

    cout << "Enter the number of data bits: ";
    cin >> m;

    int r = 0;


    while (pow(2, r) < (m + r + 1)) {
        r++;
    }

    int totalBits = m + r;

    int data[100];
    int hamming[100] = {0};

    cout << "Enter " << m << " data bits: ";
    for (int i = 1; i <= m; i++) {
        cin >> data[i];
    }

   
    int dataIndex = 1;

    for (int position = 1; position <= totalBits; position++) {

        if (!isPowerOfTwo(position)) {
            hamming[position] = data[dataIndex];
            dataIndex++;
        }
    }

    
    for (int parityPosition = 1; parityPosition <= totalBits; parityPosition *= 2) {

        int parity = 0;

        for (int position = 1; position <= totalBits; position++) {

            if ((position & parityPosition) != 0) {
                parity = parity ^ hamming[position];
            }
        }

        hamming[parityPosition] = parity;
    }

  
    cout << "\nNumber of parity bits: " << r << endl;

    cout << "Parity bit positions: ";

    for (int i = 1; i <= totalBits; i++) {
        if (isPowerOfTwo(i)) {
            cout << i << " ";
        }
    }

    cout << "\n\nHamming Code (Sender Side): ";

    for (int i = totalBits; i >= 1; i--) {
        cout << hamming[i];
    }

    cout << endl;

    cout << "\nCodeword positions:\n";

    for (int i = 1; i <= totalBits; i++) {
        cout << "Position " << i << " = " << hamming[i] << endl;
    }

    cout << "\nSender: Hamming code generated successfully." << endl;

    return 0;
}
