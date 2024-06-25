#include <iostream>
#include <limits.h>

using namespace std;

int checkHit(int incomingPage, int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return 1;
    }
    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        cout << queue[i] << "\t";
}

int main()
{
    int frames;
    cout << "Enter the frame size: ";
    cin >> frames;

    int n;
    cout << "Enter the number of pages: ";
    cin >> n;

    int incomingStream[n];
    cout << "Enter the frame: ";
    for (int i = 0; i < n; i++)
    {
        cin >> incomingStream[i];
    }

    int queue[n];
    int distance[n];
    int occupied = 0;
    int pagefault = 0;

    cout << "Page\t Frame1\t Frame2\t Frame3" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << incomingStream[i] << "\t";

        if (checkHit(incomingStream[i], queue, occupied))
        {
            printFrame(queue, occupied);
        }

        else if (occupied < frames)
        {
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;

            printFrame(queue, occupied);
        }
        else
        {
            int max = INT_MIN;
            int index;

            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;

                for (int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];

                    if (queue[j] == incomingStream[k])
                        break;
                }

                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
        }

        cout << endl;
    }

    cout << "Page Fault: " << pagefault;

    return 0;
}