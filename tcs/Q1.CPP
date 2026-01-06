#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct State {
    int R, C, S, TM;
    bool operator>(const State& other) const {
        return TM > other.TM;  
    }
};

bool val(int A, int B, int N, int M) {
    return A >= 0 && A < N && B >= 0 && B < M;
}

int main() {
    int EX, AW, K;
    cin >> EX >> AW;

    vector<vector<int>> SHRKS(EX, vector<int>(AW));
    pair<int, int> ST, DT;

   
    for (int i = 0; i < EX; ++i) {
        for (int j = 0; j < AW; ++j) {
            string C;
            cin >> C;
            if (C == "S") {
                ST = {i, j};
                SHRKS[i][j] = 0;  
            } else if (C == "D") {
                DT = {i, j};
                SHRKS[i][j] = 0;  
            } else {
                SHRKS[i][j] = stoi(C);  
            }
        }
    }

    vector<vector<int>> TMX(EX, vector<int>(AW));
    for (int i = 0; i < EX; ++i) {
        for (int j = 0; j < AW; ++j) {
            cin >> TMX[i][j];
        }
    }

    cin >> K;  

    priority_queue<State, vector<State>, greater<State>> PQR;
    PQR.push({ST.first, ST.second, K, 0});  

    vector<vector<vector<int>>> mt(EX, vector<vector<int>>(AW, vector<int>(K + 1, INT_MAX)));
    mt[ST.first][ST.second][K] = 0;  

    while (!PQR.empty()) {
        State cta = PQR.top();
        int x = cta.R;
        int y = cta.C;
        int S = cta.S;
        int cty = cta.TM;
        PQR.pop();


        if (x == DT.first && y == DT.second) {
            cout << cty << " " << S << endl;
            return 0;
        }

    
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];


            if (val(nx, ny, EX, AW)) {
                
                int nstr = S - 1 - SHRKS[nx][ny];
                
                int tn = cty + TMX[nx][ny];

                
                if (nstr >= 0 && tn < mt[nx][ny][nstr]) {
                    mt[nx][ny][nstr] = tn;
                    PQR.push({nx, ny, nstr, tn});
                }
            }
        }
    }



    cout << "Not Possible" << endl;
    return 0;
}
