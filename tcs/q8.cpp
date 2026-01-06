#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

const int BOARD_SIZE = 8;

// Directions for Queen, Rook, and Bishop
const vector<pair<int, int>> QUEEN_DIRECTIONS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};
const vector<pair<int, int>> ROOK_DIRECTIONS = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
const vector<pair<int, int>> BISHOP_DIRECTIONS = {
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
};

// Convert column (A-H) to 0-7 index
int colToIndex(char col) {
    return col - 'A';
}

// Check if a position is within the chessboard
bool isValid(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE;
}

// Generate all possible moves for a piece
vector<pair<int, int>> generateMoves(char piece, int row, int col) {
    vector<pair<int, int>> moves;
    const vector<pair<int, int>>* directions;

    if (piece == 'Q') {
        directions = &QUEEN_DIRECTIONS;
    } else if (piece == 'R') {
        directions = &ROOK_DIRECTIONS;
    } else if (piece == 'B') {
        directions = &BISHOP_DIRECTIONS;
    } else {
        return moves;
    }

    for (const auto& dir : *directions) {
        int newRow = row, newCol = col;
        while (true) {
            newRow += dir.first;
            newCol += dir.second;
            if (!isValid(newRow, newCol)) break;
            moves.emplace_back(newRow, newCol);
        }
    }

    return moves;
}

// Recursive function to simulate moves
void simulatePositions(map<char, pair<int, int>>& pieces, int depth, int currentDepth, set<string>& visited) {
    if (currentDepth == depth) {
        // Create a unique board state representation
        string state;
        for (const auto& piece : pieces) {
            state += piece.first;
            state += to_string(piece.second.first) + to_string(piece.second.second) + ";";
        }
        visited.insert(state);
        return;
    }

    map<char, pair<int, int>> initialState = pieces;

    for (auto& piece : pieces) {
        char pieceType = piece.first;
        int row = piece.second.first;
        int col = piece.second.second;

        vector<pair<int, int>> possibleMoves = generateMoves(pieceType, row, col);
        for (const auto& move : possibleMoves) {
            // Ensure no two pieces overlap
            bool overlap = false;
            for (const auto& otherPiece : pieces) {
                if (otherPiece.first != pieceType && otherPiece.second == move) {
                    overlap = true;
                    break;
                }
            }
            if (overlap) continue;

            // Update piece position and simulate next depth
            pieces[pieceType] = move;
            simulatePositions(pieces, depth, currentDepth + 1, visited);
        }

        // Restore the original position
        pieces = initialState;
    }
}

// Main function
int main() {
    string positionsLine;
    getline(cin, positionsLine);

    string depthLine;
    getline(cin, depthLine);

    map<char, pair<int, int>> pieces;
    stringstream ss(positionsLine);
    string piecePos;

    while (ss >> piecePos) {
        char piece = piecePos[0];
        int row = piecePos[2] - '1';
        int col = colToIndex(piecePos[1]);
        pieces[piece] = {row, col};
    }

    int depth = stoi(depthLine);

    set<string> visited;
    simulatePositions(pieces, depth, 0, visited);

    cout << visited.size() << endl;
    return 0;
}
