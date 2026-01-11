#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
[입출력]
입력: 규칙의 수 N
N개의 걸쳐
문자 X, 집합의 원소수 M, 문자 집합 원소 Y
출력: yes or no


[문제]
규칙 맞히기 퀴즈. 규칙은 다음과 같다.

어떤 문자 X의 바로 뒤에는 허용된 문자 혹은 아무것도 오지 않은 상태(문자열 종료)여야 한다.

규칙이 주어지지 않은 문자는 뒤에 무엇이 오든 상관없다.
*/

struct X {
	char x;
	vector<char> Y;
};

int main() {
	int N;

	cin >> N;

	vector<X> X_vec(0);

	for (int i = 0; i < N; i++) {
		char x;
		int y_size;
		cin >> x >> y_size;
		X_vec.push_back(X{x, vector<char>(y_size)});
		for (int j = 0; j < y_size; j++) {
			cin >> X_vec[i].Y[j];
		}
	}

	string S;

	cin >> S;

	bool yon = true;

	for (int i = 0; i < S.size() - 1; i++) {
		for (int j = 0; j < X_vec.size(); j++) {
			if (S[i] == X_vec[j].x) {
				bool confirm = false;
				for (int z = 0; z < X_vec[j].Y.size(); z++) {
					if (S[i + 1] == X_vec[j].Y[z]) {
						confirm = true;
						break;
					}
				}
				if (!confirm) {
					yon = false;
					break;
				}
			}
		}
		if (!yon) break;
	}

	if (yon) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}