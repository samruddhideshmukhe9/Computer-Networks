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
