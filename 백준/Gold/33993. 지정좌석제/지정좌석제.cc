#include <iostream>
#include <vector>
using namespace std;

/*
입력: 친구의 수, 교실의 크기, 친구 탐색 범위, 친구들의 좌표
출력: 만족도, 해당 좌표

[문제]
교실에서 근처에 가장 친구가 많은 자리를 찾기
이미 친구가 앉은 자리에는 앉을 수 없다.
여러 개면 x y 좌표값이 더 작은 곳 출력(x 우선)

[변수 설명]
R, C: 교실의 크기
N: 교실 내 친구의 수
W: 좌표를 중심으로 하는 정사각형의 범위. W*W 크기이므로 반드시 홀수, 최솟값 3
w: 중심을 기준으로 가장 먼 좌표값에 도달하기 위해 빼거나 더해야 할 값.
Class[R][C]: 교실. 2차원 배열
Satisfaction: 만족도
Lx, Ly: 만족도가 가장 높은 자리의 좌표
*/

void SetWXY(int* wx, int* wy, int w) {
    *wy -= 1;
    if (*wy < -1 * w) {
        *wx -= 1;
        *wy = w;
    }
}

int main() {
    int N, R, C, W;
    int Satisfaction = 0;
    int Lx = 0, Ly = 0;
    

    cin >> N >> R >> C >> W;

    int w = (W - 1) / 2;

    vector<vector<int>> Class(R, vector<int>(C, 0));
    vector<vector<int>> result(R, vector<int>(C, 0));

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        Class[x - 1][y - 1] = 1;
        result[x - 1][y - 1] = -1;
    }
    
    

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Class[i][j] == 0) continue;

            int wx = w, wy = w;
            for (int z = 0; z < W * W; z++) {
                if (i - wx < 0 || j - wy < 0 || i - wx >= R || j - wy >= C) {
                    SetWXY(&wx, &wy, w);
                    continue;
                }

                if (result[i - wx][j - wy] == -1) {
                    SetWXY(&wx, &wy, w);
                    continue;
                }
                
                result[i - wx][j - wy]++;
                if (result[i - wx][j - wy] > Satisfaction) {
                    Satisfaction = result[i - wx][j - wy];
                    Lx = i - wx + 1;
                    Ly = j - wy + 1;
                }
                SetWXY(&wx, &wy, w);
            }
        }
    }
    

    cout << Satisfaction << endl;
    cout << Lx << " " << Ly << endl;
    
    return 0;
}