#include <iostream>
using namespace std;

/*
입력: 주사위를 굴리는 횟수, 각 주사위 결과
출력: 얻은 각 보상의 개수

[게임의 룰]
한 턴에 주사위를 한 번 굴린다.
주사위를 한 번 굴릴 때마다 1점을 얻는다. P라 하자.
매 턴 시간이 4만큼 흐른다. 시간은 T라 하자.
시간이 240을 초과한 경우, 게임을 종료한다.
게임이 종료되면, 얻은 점수에 따라 보상을 획득한다.
주사위를 다 굴렸음에도 게임이 종료되지 않았다면, 점수에 상관없이 보상을 받을 수 없다.

[보상표]
35 ~ 64) 보상 1
65 ~ 94) 보상 2
95 ~ 124) 보상 3
125 ~ ) 보상 4

[주사위 값에 따른 효과]
1) 즉시 게임 종료
2) P가 1보다 크면 절반으로 감소시킨다. P가 1이면 T를 2 증가시킨다.
3) 효과 없음
4) 해당 턴에만 시간이 56만큼 추가로 흐르게 한다.
5) T가 1보다 크면 P를 1 감소시킨다.
6) P가 32보다 작은 경우 2배 증가시킨다.
*/

void FinishGame(int* result, int* time, int* P, int* T, int* R1, int* R2, int* R3, int* R4) {
    int reward = 0;
    if (*result >= 125) reward = 4;
    else if (*result >= 95) reward = 3;
    else if (*result >= 65) reward = 2;
    else if (*result >= 35) reward = 1;

    switch (reward) {
    case 1:
        *R1 += 1;
        break;
    case 2:
        *R2 += 1;
        break;
    case 3:
        *R3 += 1;
        break;
    case 4:
        *R4 += 1;
        break;
    }

    *result = 0;
    *time = 0;
    *P = 1;
    *T = 4;
}



// P: 점수, T: 시간, N: 주사위 굴리는 횟수, d[]: 주사위 결과값, R1~4: 보상 1~4
// result: 해당 게임의 총점, time: 해당 게임의 흐른 시간
int main() {
    int P = 1, T = 4, R1 = 0, R2 = 0, R3 = 0, R4 = 0;
    int result = 0, time = 0;
    int N;

    cin >> N;

    int* d = new int[N];

    for (int i = 0; i < N; i++) cin >> d[i];

    for (int i = 0; i < N; i++) {

        if (time > 240) FinishGame(&result, &time, &P, &T, &R1, &R2, &R3, &R4);

        switch (d[i]) {
        case 1: 
            FinishGame(&result, &time, &P, &T, &R1, &R2, &R3, &R4);
            break;
        case 2:
            if (P > 1) P /= 2;
            else T += 2;
            break;
        case 4:
            time += 56;
            break;
        case 5:
            if (T > 1) T--;
            break;
        case 6:
            if (P < 32) P *= 2;
        }

        if (d[i] != 1) {
            result += P;
            time += T;
        }

    }

    std::cout << R1 << endl << R2 << endl << R3 << endl << R4 << endl;

    delete[] d;

    return 0;
}