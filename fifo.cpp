#include <iostream>
using namespace std;

int main()
{

    int frames;
    cout << "Enter frame size: ";
    cin >> frames;

    int size;
    cout << "Enter the size: ";
    cin >> size;

    int pagefault = 0;

    int incomingStream[size];

    cout << "Enter the pages in sequence: ";
    for (int i = 0; i < size; i++)
    {
        cin >> incomingStream[i];
    }
    cout << endl;

    int m, n, s;

    cout << "Incoming \tFrame 1 \tFrame 2 \tFrame 3";

    int temp[frames];

    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for (m = 0; m < size; m++)
    {

        s = 0;

        for (n = 0; n < frames; n++)
        {

            if (incomingStream[m] == temp[n])
            {
                s++;
                pagefault--;
            }
        }
        pagefault++;
        if ((pagefault <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pagefault - 1) % frames] = incomingStream[m];
        }
        cout << endl;
        cout << incomingStream[m] << "\t\t";
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                cout << temp[n] << "\t\t";
            else
                cout << " - \t\t";
        }
    }
    cout << endl;
    cout << "Total Page Faults: " << pagefault << endl;

    return 0;
}