#include <iostream>
using namespace std;

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int index = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != t[i]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "0" << endl;
        return 0;
    }
    
    bool eqs = true;
    bool eqt = true;
    for (int i = index; i >= 0; i--) {
        if (s[i] != s[index]) {
            eqs = false;
        }
        if (t[i] != t[index]) {
            eqt = false;
        }
    }
    
    if (!eqs && !eqt) {
        cout << "2" << endl;
        cout << "1 " << index+1 << " a" << endl;
        cout << "2 " << index+1 << " a" << endl;
    }
    if (eqs) {
        cout << "1" << endl;
        cout << "2 " << index+1 << " " << s[index] << endl;;
    }
    if (eqt) {
        cout << "1" << endl;
        cout << "1 " << index+1 << " " << t[index] << endl;;
    }
}