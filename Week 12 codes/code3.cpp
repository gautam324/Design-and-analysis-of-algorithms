#include <iostream>
#include <algorithm>

using namespace std;

void generatePermutations(string str) {
    sort(str.begin(), str.end());
    cout << str << endl;

    while (next_permutation(str.begin(), str.end())) {
        cout << str << endl;
    }
}

int main() {
    string str;
    cin >> str;

    generatePermutations(str);

    return 0;
}
