#include<bits/stdc++.h>
using namespace std;
struct process {
    int pid, at, bt, st, ct, wt, tat;
};
int main() {
    int n;
    cout<<"Enter the number of processes:- "<< endl;
    cin >>n;
    vector<process> processes(n);
    for(int i=0; i<n; i++){
        processes[i].pid = i+1;
        cout << "Enter the arrival and burst time for processes " << i+1 << ": ";
        cin >> processes[i].at >> processes[i].bt;
    }
    sort(processes.begin(), processes.end(), [](process a, process b) {
        return a.at < b.at;
    });
    int cur = 0;
    for(int i=0; i<n; i++) {
        processes[i].st = max(cur, processes[i].at);
        processes[i].ct = processes[i].st + processes[i].bt;
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
        cur = processes[i].ct;
    }
    cout << "\nPID\tArrival\tBurst\tStart\tCompletion\tWaiting\tTurnaround\n";
    for(const auto& p: processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.st << "\t" << p.ct << "\t\t" << p.wt << "\t" << p.tat << "\n";
    }
    return 0;
}