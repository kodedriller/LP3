#include <bits/stdc++.h>
using namespace std;

int sol=0;

bool isSafe(vector<int> &queens, int x, int y) {
    for (int row = 0; row < x; row++) {
        if (queens[row] == y || abs(queens[row] - y) == abs(row - x)) {
            return false;
        }
    }
    return true;
}

void printBoard(vector<int> &queens) {
    int n = queens.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (queens[i] == j)
                cout << "[Q]";
            else
                cout << "[]";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void nQueen(vector<int> &queens, int x, int n) {
    if (x == n) {
        sol++;
        cout<<"Solution number "<<sol<<endl;
        printBoard(queens);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, x, col)) {
            queens[x] = col;
            nQueen(queens, x + 1, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> queens(n, -1);

    nQueen(queens, 0, n);

    cout << "-----------------------";
    cout << "Total Number of Solutions for "<<n<<" queens are "<<sol<<endl;

    return 0;
}


/*

<------  N-Queens Solutions  ----->     <---- time ---->
 N:           Total            Unique     days hh:mm:ss.--
 2:               0                 0                 0.00
 3:               0                 0                 0.00
 4:               2                 1                 0.00
 5:              10                 2                 0.00
 6:               4                 1                 0.00
 7:              40                 6                 0.00
 8:              92                12                 0.00
 9:             352                46                 0.00
10:             724                92                 0.00
11:            2680               341                 0.00
12:           14200              1787                 0.00
13:           73712              9233                 0.00
14:          365596             45752                 0.01
15:         2279184            285053                 0.04
16:        14772512           1846955                 0.22
17:        95815104          11977939                 1.33
18:       666090624          83263591                 9.15
19:      4968057848         621012754              1:21.10
20:     39029188884        4878666808             12:41.56
21:    314666222712       39333324973           1:44:33.37
22:   2691008701644      336376244042          14:45:03.08
23:  24233937684440     3029242658210        5 10:37:12.97


*/