#include <iostream>

using namespace std;

int search(int key, int frame_items[], int frame_occupied)
{
    for (int i = 0; i < frame_occupied; i++)
        if (frame_items[i] == key)
            return 1;
    return 0;
}

void printOuterStructure(int max_frames)
{
    cout << "Stream ";

    for (int i = 0; i < max_frames; i++)
        cout << "Frame " << i + 1;
}
void printCurrFrames(int item, int frame_items[], int frame_occupied, int max_frames)
{

    cout << endl
         << item << "\t\t";

    for (int i = 0; i < max_frames; i++)
    {
        if (i < frame_occupied)
            cout << frame_items[i] << "\t\t";
        else
            cout << "- \t\t";
    }
}

int predict(int ref_str[], int frame_items[], int refStrLen, int index, int frame_occupied)
{
    int result = -1, farthest = index;
    for (int i = 0; i < frame_occupied; i++)
    {
        int j;
        for (j = index; j < refStrLen; j++)
        {
            if (frame_items[i] == ref_str[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }

        if (j == refStrLen)
            return i;
    }

    return (result == -1) ? 0 : result;
}

void optimalPage(int ref_str[], int refStrLen, int frame_items[], int max_frames)
{
    int frame_occupied = 0;
    printOuterStructure(max_frames);

    int hits = 0;
    for (int i = 0; i < refStrLen; i++)
    {

        if (search(ref_str[i], frame_items, frame_occupied))
        {
            hits++;
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
            continue;
        }

        if (frame_occupied < max_frames)
        {
            frame_items[frame_occupied] = ref_str[i];
            frame_occupied++;
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
        }

        else
        {
            int pos = predict(ref_str, frame_items, refStrLen, i + 1, frame_occupied);
            frame_items[pos] = ref_str[i];
            printCurrFrames(ref_str[i], frame_items, frame_occupied, max_frames);
        }
    }
    cout<<endl;
    cout << "Total Page faults: " << refStrLen - hits;
}

int main()
{
    int max_frames;
    cout << "Enter the frame size: ";
    cin >> max_frames;

    int n;
    cout << "Enter the number of pages: ";
    cin >> n;

    int ref_str[n];
    cout << "Enter the pages in sequence: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ref_str[i];
    }

    int frame_items[max_frames];

    optimalPage(ref_str, n, frame_items, max_frames);
}