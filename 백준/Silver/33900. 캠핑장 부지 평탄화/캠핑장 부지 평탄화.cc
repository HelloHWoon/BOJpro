#include <iostream>
using namespace std;

/*
N, M: 산의 크기. 각각 행과 열
R, C: 작업계획도의 크기. 각각 행과 열

산과 작업계획도의 각 원소에는 고도 정보를 가진다.
산의 크기 행렬에서 특정 부분에 작업계획도를 겹쳐 고도정보를 뺀다.
-> 뺀 부분의 모든 고도값이 동일하면 작업 가능하다고 판단.
-> 최종적으로 작업 가능한 부분의 개수 출력.
*/

int main() {
    int N, M, R, C;

    cin >> N >> M >> R >> C;

    int** mountin = new int*[N];
    int** plan = new int*[R];
    int* result = new int[R * C];

    //산 크기 배열 생성
    for (int i = 0; i < N; i++) {
        mountin[i] = new int[M];
    }
    //계획도 크기 배열 생성
    for (int i = 0; i < R; i++) {
        plan[i] = new int[C];
    }

    //산 배열에 고도 값 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mountin[i][j];
        }
    }
    //계획도 배열에 고도 값 입력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> plan[i][j];
        }
    }
    
    //계산
    /*
    산이 3행인 경우, 계획도의 행이 1이면 3번, 2이면 2번, 3이면 1번 검사한다.
    따라서 N-R+1의 식으로 시행횟수를 알 수 있다.
    */
    int count = 0;
    for (int i = 0;; i++) {
        int limi = i + R - 1;
        if (limi == N) break;
        for (int j = 0;; j++) {
            int limj = j + C - 1;
            if (limj == M) break;
            int r_i = 0;
            int i3 = 0, j3 = 0;
            for (int i2 = i; i2 <= limi; i2++) {
                for (int j2 = j; j2 <= limj; j2++) {
                    result[r_i] = mountin[i2][j2] - plan[i3][j3];
                    
                    r_i++;
                    j3++;
                }
                if (j3 == C) {
                    i3++;
                    j3 = 0;
                }
                if (i3 == R) {
                    i3 = 0;
                    j3 = 0;
                }
            }
            r_i = 0;
            bool A = true;
            for (; r_i < R * C; r_i++) {
                if (r_i != R * C - 1) {
                    if (result[r_i] != result[r_i + 1]) {
                        A = false;
                    }
                }
                else {
                    if (result[r_i] != result[0]) A = false;
                }
            }
            if (A == true) count++;
        }
    }
    cout << count << endl;

    //메모리 해제
    for (int i = 0; i < N; i++) {
        delete[] mountin[i];
    }
    for (int i = 0; i < R; i++) {
        delete plan[i];
    }

    delete[] mountin;
    delete[] plan;

    return 0;
}