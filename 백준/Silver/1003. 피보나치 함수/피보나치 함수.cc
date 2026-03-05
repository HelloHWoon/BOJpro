#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct fibo {
	int a;
	int b;
};

void Fibonacci(vector<fibo>& f, int n) {
	if (n == 0) f.push_back(fibo{ 1, 0 });
	else if (n == 1) {
		Fibonacci(f, n - 1);
		f.push_back(fibo{ 0, 1 });
	}
	else {
		Fibonacci(f, n - 1);
		f.push_back(fibo{ f[n - 1].a + f[n - 2].a, f[n - 1].b + f[n - 2].b });
	}
}

int main() {
	int T;

	cin >> T;

	vector<fibo> vec;

	while (T--) {
		int n;

		cin >> n;

		vector<fibo> f;

		Fibonacci(f, n);

		vec.push_back(f.back());
	}

	for (int i = 0; i < vec.size(); i++) cout << vec[i].a << " " << vec[i].b<< endl;


	return 0;
}