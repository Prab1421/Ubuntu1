#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 3;  // 3x3 puzzle

// Goal configuration
const vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

struct PuzzleState {
    vector<vector<int>> board;
    int x, y; // Position of the empty tile (0)
    int g, h; // g = cost so far, h = heuristic

    PuzzleState(vector<vector<int>> b, int gx, int gy, int g_cost) {
        board = b;
        x = gx;
        y = gy;
        g = g_cost;
        h = calculateHeuristic();
    }

    int calculateHeuristic() {
        int dist = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] != 0)
                    for (int xg = 0; xg < N; ++xg)
                        for (int yg = 0; yg < N; ++yg)
                            if (goal[xg][yg] == board[i][j])
                                dist += abs(xg - i) + abs(yg - j);
        return dist;
    }

    bool isGoal() const {
        return board == goal;
    }

    string serialize() const {
        string s;
        for (const auto& row : board)
            for (int val : row)
                s += to_string(val);
        return s;
    }

    bool operator>(const PuzzleState& other) const {
        return (g + h) > (other.g + other.h);
    }
};

// Movement directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void printBoard(const vector<vector<int>>& board) {
    for (auto& row : board) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
    cout << "\n";
}

void solve8Puzzle(vector<vector<int>> start) {
    int startX, startY;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (start[i][j] == 0)
                startX = i, startY = j;

    priority_queue<PuzzleState, vector<PuzzleState>, greater<>> pq;
    unordered_set<string> visited;

    PuzzleState startState(start, startX, startY, 0);
    pq.push(startState);
    visited.insert(startState.serialize());

    while (!pq.empty()) {
        PuzzleState current = pq.top();
        pq.pop();

        if (current.isGoal()) {
            cout << "Solved in " << current.g << " moves.\n";
            printBoard(current.board);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
                vector<vector<int>> newBoard = current.board;
                swap(newBoard[current.x][current.y], newBoard[newX][newY]);

                PuzzleState newState(newBoard, newX, newY, current.g + 1);
                string key = newState.serialize();

                if (!visited.count(key)) {
                    pq.push(newState);
                    visited.insert(key);
                }
            }
        }
    }

    cout << "No solution found.\n";
}

int main() {
    vector<vector<int>> start = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };

    cout << "Initial Board:\n";
    printBoard(start);

    solve8Puzzle(start);

    return 0;
}
