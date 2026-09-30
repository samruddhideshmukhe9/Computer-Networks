#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator, temp;

    cout << "Enter Data: ";
    cin >> data;

    cout << "Enter Generator: ";
    cin >> generator;

    temp = data;

    // Append zeros
    for (int i = 0; i < generator.length() - 1; i++)
    {
        temp = temp + "0";
    }

    // Modulo-2 division
    for (int i = 0; i <= temp.length() - generator.length(); i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generator.length(); j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get CRC
    string crc = temp.substr(
        data.length(),
        generator.length() - 1
    );

    cout << "\nCRC = " << crc << endl;
    cout << "Transmitted Data = " << data + crc << endl;

    return 0;
}

2. CRC Checker — Receiver Side

This program takes the received/transmitted data and checks whether an error occurred.

:::writing{variant="standard" id="69214" title="CRC Checker / Receiver in C++"}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string received, generator, temp;

    cout << "Enter Received Data: ";
    cin >> received;

    cout << "Enter Generator: ";
    cin >> generator;

    temp = received;

    // Modulo-2 division
    for (int i = 0; i <= temp.length() - generator.length(); i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generator.length(); j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Check remainder
    bool error = false;

    for (int i = temp.length() - (generator.length() - 1);
         i < temp.length(); i++)
    {
        if (temp[i] == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "\nError Detected!" << endl;
    else
        cout << "\nNo Error Detected." << endl;

    return 0;
}

What to call them in your CN practical

Program| Side| Purpose
CRC Generator| Sender| Generates CRC and transmitted data
CRC Checker| Receiver| Checks received data for errors

Important: The generator such as "1001" is the divisor/polynomial. It is an input, not a third program.
