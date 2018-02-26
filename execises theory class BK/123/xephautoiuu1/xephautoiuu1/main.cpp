#include <iostream>
#include <iomanip>
using namespace std;
int try_Q(int Board[],int N, int i) {
    static int count = 0;
    int check = 1;
    if (i == 0) {
        for (int j = 0; j < N; j++) {
            Board[i] = j;
            if (try_Q(Board, N, i + 1) == 1) {
                cout << "Num of back track: " << count << endl;
                return 1;
            }
            else {
                Board[i] = -N*N - 1;
                count++;
                continue;
            }
        }
    }
    else {
        for (int j = 0; j < N; j++) {
            for (int k = i; k > 0; k--)
                if (j == Board[k - 1]       || j + i == Board[k - 1] + k - 1 ||            j - i == Board[k - 1] - k + 1)	check = 0;
            if (check == 1) {
                Board[i] = j;
                if (try_Q(Board, N, i + 1) == 1) {
                    return 1;
                }
                else {
                    Board[i] = -N*N - 1;
                    count++;
                }
            }
            else {
                check = 1;
                continue;
            }
        }
    }
    if (Board[i] == -N*N - 1) return 0;
    else return 1;
}

int main() {
    int *Board;
    int N;
    cout << "N = ";
    cin >> N;
    Board = new int[N];
    for (int i = 0; i < N; i++) {
        Board[i] = -N*N - 1;
    }
    for (int i=0; i<N ; i++) {
        cout<<Board[i]<<" ";
    }
    cout<<endl;
    try_Q(Board, N, 0);
    for (int i=0; i<N ; i++) {
        cout<<Board[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Board[i] != j) {
                cout << setw(5) << "|" << setw(1) << right << "|";
            }
            else {
                cout << setw(6) << internal << "Q";
            }
        }
        cout << "\t" << Board[i] + 1 << endl;
    }
}
