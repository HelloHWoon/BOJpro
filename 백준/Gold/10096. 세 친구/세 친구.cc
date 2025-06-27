#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
입력: 문자열 U
출력: 문자열 S
문자열 S를 찾을 수 없다면 NOT POSSIBLE 출력
가능한 문자열 S가 여러 개라면 NOT UNIQUE 출력

[문제]
문자열 U가 만들어지는 과정은 다음과 같다.

1. 문자열 S 뒤에 S를 이어붙인다. 이 문자열을 S2라 한다.
2. S2의 특정 부분에 문자 하나를 삽입한다. 삽입된 문자를 Z라 하자.

입력으로 문자열 U가 주어진다. U를 통해 문자열 S를 구하는 프로그램을 작성하라.

U가 만들어지는 경우의 수가 없다면 NOT POSSIBLE 출력
U가 만들어지는 경우의 수가 여러 개라면 NOT UNIQUE 출력

[찾아낸 정보]
문자열의 길이는 기본적으로 홀수이다. S.size() * 2 + 1 이기 때문
-> 위 조건을 만족하지 않으면 NOT POSSIBLE

문자열 U에는 문자열 S에 들어가는 문자가 짝수 개 있다.
-> 문자 Z가 문자열 S에 포함되는 문자라면 홀수 개인 문자가 하나 존재한다.

문자열 U에는 개수가 홀수인 문자가 1개 존재한다
-> 위 조건을 만족하지 않으면 NOT POSSIBLE

개수가 홀수인 문자를 찾아 하나씩 빼본다.
-> 문제 조건을 만족하지만 다른 S가 나온다면 NOT UNIQUE
*/

bool is_S_exist(string str) {
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[(str.size() / 2) + i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int N;

    cin >> N;

    string U;

    cin >> U;

    if (N % 2 == 0) {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }

    vector<char> C;
    int odd_count = 0;
    char odd_char = 0;
    bool only_once = true;

    for (int i = 0; i < U.size(); i++) {
        char z = U[i];
        bool exist = false;

        for (int j = 0; j < C.size(); j++) {
            if (z == C[j]) {
                exist = true;
                break;
            }
        }
        if (exist) continue;
        
        C.push_back(z);

        int count = 0;

        for (int j = i; j < U.size(); j++) {
            if (U[j] == z) {
                count++;
            }
        }

        //문자열 U 내에 홀수개 존재하는 문자 개수 파악
        if (count % 2 == 1) {
            if (odd_count == 0) {
                odd_count++;
                odd_char = z;
            }
            else {
                only_once = false;
                break;
            }
        }
    }
    
    if (!only_once) {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }

    string S;
    bool S_already = false;

    for (int i = 0; i < U.size(); i++) {
        if (U[i] != odd_char) continue;

        string str = U;

        str.erase(i, 1);

        if (is_S_exist(str)) {
            if (!S_already) {
                S = str;
                S_already = true;
            }
            else {
                if(str != S){
                    cout << "NOT UNIQUE" << endl;
                    return 0;
                }
            }
        }
    }

    if (S_already) {
        S.erase(S.size() / 2);

        cout << S << endl;
    }
    else {
        cout << "NOT POSSIBLE" << endl;
    }
    
    
    return 0;
}