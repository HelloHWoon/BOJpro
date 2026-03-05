#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void Worm(vector<vector<int>> connected, vector<int>& worm, int p, int* count) {
	for (int i = 0; i < worm.size(); i++) {
		if (connected[p][i] && !worm[i]) {
			*count += 1;
			worm[i] = 1;
			Worm(connected, worm, i, count);
		}
	}
}

int main() {
	int N, M;
	int count = 0;

	cin >> N;
	cin >> M;

	vector<vector<int>> connected( N, vector<int>(N, 0) );
	vector<int> worm( N, 0 );

	for (int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;
		

		connected[a - 1][b - 1] = 1;
		connected[b - 1][a - 1] = 1;
	}

	worm[0] = 1;

	Worm(connected, worm, 0, &count);

	std::cout << count << endl;


	return 0;
}