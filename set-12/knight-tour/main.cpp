#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

// update the adjacency matrix
void update(vector<vector<int> >& visited, vector<vector<int> >& board, queue<pair<int, int> >& q, int i, int j, int R, int C, int M, int N) {
    vector<pair<int, int> > possibleMoves;

    possibleMoves.push_back(make_pair(M, N));
    possibleMoves.push_back(make_pair(M, -N));
    possibleMoves.push_back(make_pair(-M, N));
    possibleMoves.push_back(make_pair(-M, -N));
    possibleMoves.push_back(make_pair(N, M));
    possibleMoves.push_back(make_pair(N, -M));
    possibleMoves.push_back(make_pair(-N, M));
    possibleMoves.push_back(make_pair(-N, -M));

    for (const auto& move : possibleMoves) {
        int newI = i + move.first;
        int newJ = j + move.second;

        if (newI >= 0 && newI < R && newJ >= 0 && newJ < C) {
            if(visited[newI][newJ] == 0 && board[newI][newJ] == 1) {
                q.push(make_pair(newI, newJ));
                visited[newI][newJ] = true;
            }
        }
    }
}


int main() {
    int R, C, M, N, W;
    cin >> R >> C >> M >> N >> W;

    // create a R x C matrix initialized to 1 
    // for water
    vector<vector<int> > board(R, vector<int>(C, 1));

    // for board
    vector<vector<int> > visited(R, vector<int>(C, 0));

    // input the water squares
    for (int i = 0; i < W; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 0;
    }
    
    // create a queue to pair to store the coordinates of the squares
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    // update the adjacency matrix
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;

        update(visited, board, q, i, j, R, C, M, N);
    }

    int even = 0, odd = 0;

    vector<pair<int, int> > possibleMoves;
    possibleMoves.push_back(make_pair(M, N));
    possibleMoves.push_back(make_pair(M, -N));
    possibleMoves.push_back(make_pair(-M, N));
    possibleMoves.push_back(make_pair(-M, -N));

    // if M != N, consider all 8 possible moves
    if(M != N){
        possibleMoves.push_back(make_pair(N, M));
        possibleMoves.push_back(make_pair(N, -M));
        possibleMoves.push_back(make_pair(-N, M));
        possibleMoves.push_back(make_pair(-N, -M));
    }
    
    // check the number of even and odd squares
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(visited[i][j] == 0){
                continue;
            }
            int count = 0;
            for (const auto& move : possibleMoves) {
                int newI = i + move.first;
                int newJ = j + move.second;

                if (newI >= 0 && newI < R && newJ >= 0 && newJ < C) {
                    if(visited[newI][newJ] == 1 && board[newI][newJ] == 1)
                        count++;
                }
            }
            if(count % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
            // // print the count for each square
            // cout << "i: " << i << " j: " << j << " count: " << count << endl;
        }
    }


    cout << even << " " << odd << endl;

    return 0;
}

/*

Input
The first line contains four integer R,C,M,N, 1 < R,C <= 100, 0 <= M,N <= 50, and M+N > 0. The next line contains
an integer W, 0 <= W < R*C, which is the number of distinct squares filled with water. Each of the next W lines
contain a pair of integer x_i,y_i, 1<=x_i<=R, 1<=y_i<=C, and xi + yi > 2, indicating that the square (x_i,y_i)
is filled with water.
Output
Output two integer separated by space: the number of even and odd valid squares.
Example 1
Input:
3 3 2 1
0
Output:
8 0
(All the squares except for the center one are valid. Each of them can be accessed from two other squares, so they
are all even.)
Example 2
Input:
4 4 1 2
2
4 4
2 2
Output:
4 10

Example 3
Input:
3 3 1 1
0
Output:
1 4

Example 4
Input:
4 4 1 1 
0

Output:
6 2 

Example 5
Input:
10 10 3 1
0

Output:
42 8 
Example 6
Input:
4 4 1 2
0
Output:
8 8 

*/


