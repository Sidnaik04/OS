#include<iostream>
using namespace std;

int main()
{
    struct fcfs
    {
        int pn[100];
        int bt, wt, tat;
    } b[100];
    int sum1 = 0, sum2 = 0, i, n;
    float avg1 = 0, avg2 = 0;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter processes and burst times: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >>* b[i].pn;
        cin >> b[i].bt;
    }
    b[0].wt = 0;
    for (i = 0; i < n; i++)
    {
        b[i + 1].wt = b[i].bt + b[i].wt;
        b[i].tat = b[i].wt + b[i].bt;
    }
    cout << "Process\t\tBurst Time\t\tWaiting Time\t\tTAT" << endl;
    for (i = 0; i < n; i++)
    {
        sum1 += b[i].wt;
        sum2 += b[i].tat;
        cout <<* b[i].pn << "\t\t" << b[i].bt << "\t\t\t" << b[i].wt << "\t\t\t" << b[i].tat<<endl;
    }
    avg1 = (float)sum1 / n;
    avg2 = (float)sum2 / n;
    cout << "Average Waiting Time = " << avg1<<endl;
    cout << "Average Turnaround time = " << avg2<<endl;
    return 0;
}