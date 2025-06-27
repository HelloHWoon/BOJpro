#include <iostream>
using namespace std;

/*
N = 1) 1층 최솟값: 15, 최댓값: 20, 합: 35
N = 2) 1층 최솟값: 15, 최댓값: 20, 2층 최솟값: 23, 최댓값: 47
모든 층 최솟값: 38, 최댓값: 67, 합: 105
*/
/*
각 층의 주사위 개수는 (N(N+1))/2개.
N층에는 1개의 면이 가려진 주사위가 1개 있음. 다른 층에는 없음
N-i 라고 가정하면 해당 층에는 2개의 면이 가려진 주사위가 2개 있음
4개의 면이 가려진 주사위는 N층 제외 하나씩 있음
i가 2 이상이면 5개의 면이 가려진 주사위가 (i-1)*2개 있음
i가 4 이상일 경우, 모든 면이 가려진 주사위가 N-i일 때의 전채 주사위 수 만큼 있음.
*/

/*
NOD: number of dice. 전체 주사위 개수
*/

class calculator {
private:
    int N, NOD = 0, max = 0, min = 0;
public:
    calculator(int N) : N{ N } {
        for (int i = N; i > 0; i--) {
            NOD = (i * (i + 1)) / 2;
        }
    }
    int Cal() {
        int D1 = 0, D2 = 0, D3 = 0, D4 = 0, D5 = 0;
        for (int i = 0; i < N; i++) {
            D1 = 0, D2 = 0, D3 = 0, D4 = 0, D5 = 0;

            if (i != 0) {
                D2 = 2;
            }
            if (i > 1) {
                D3 = i - 1;
            }
            if (i != 0) {
                D4 = 1;
            }
            else {
                D4 = 0;
            }
            if (i != 0 && i != 1) {
                D5 = (i - 1) * 2;
            }
            else {
                D5 = 0;
            }
            if (i == 0) {
                D1 = 1;
            }
            else {
                D1 = 0;
            }
            
            min += (D1 * 15) + (D2 * 10) + (D3 * 6) + (D4 * 3) + (D5 * 1);
            max += (D1 * 20) + (D2 * 18) + (D3 * 15) + (D4 * 11) + (D5 * 6);
        }
        return min + max;
    }
};

int main() {
    int N;
    cin >> N;
    calculator obj(N);
    cout << obj.Cal() << endl;
}