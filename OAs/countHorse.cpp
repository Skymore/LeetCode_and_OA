/*
There are a lot of horses in the yard, and we want to count how many there are.  Unfortunately, we've only got a recording of the sounds from the yard.  All the horses say "neigh".  The problem is they can "neigh" many times.  The recording from the yard is sadly all mixed together.  So, we need to figure out from the overlapping sounds how many horses there could be.

For example, we've got two horses in the yard, and we hear this "neigneighh".  From this recording, we can successfully deduce there are 2 horses.  Another example is "neighneigh".  From this example, we can only tell there is one horse in the yard.

As an additional complexity, our recording might not be perfect.  If it's a bad recording, we should give "Invalid" as the response.

The input will be given as a string on one line.  The output should be printed on it's own line.

Sample Input
nenigehnieighgh

Sample Output
2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

char next_char(char ch) {
    if (ch == 'n') return 'e';
    if (ch == 'e') return 'i';
    if (ch == 'i') return 'g';
    if (ch == 'g') return 'h';
    if (ch == 'h') return 'n';
    return ' ';
}

int count_horse(string sound) {
    int horse_cnt = 0;
    map<char, vector<int>> horse_dict;
    int horse_index = 0;

    for (char ch : sound) {
        if (ch == 'n' && horse_dict.find('n') == horse_dict.end()) {
            horse_cnt++;
            horse_index = horse_cnt;
        } else {
            // 如果当前字母不是'n'，则需要找到上一个horse的index
            // 如果找不到，则说明不是完整的horse sound
            if (horse_dict.find(ch) == horse_dict.end()) {
                return -1;
            } else {
                horse_index = horse_dict[ch].back();
                horse_dict[ch].pop_back();
                if (horse_dict[ch].empty()) {
                    horse_dict.erase(ch);
                }
            }
        }
        char next = next_char(ch);
        if (horse_dict.find(next) == horse_dict.end()) {
            horse_dict[next] = vector<int>();
        }
        horse_dict[next].push_back(horse_index);
    }

    // 如果最后字母不是'n'，说明不是完整的horse sound
    for (auto [key, value] : horse_dict) {
        if (key != 'n') return -1;
    }

    return horse_cnt;
}

int main() {
    string sound;
    sound = "nenigehnieighgh";
    cout << count_horse(sound) << endl;
    sound = "neighneigh";
    cout << count_horse(sound) << endl;
    sound = "neigneighh";
    cout << count_horse(sound) << endl;
    sound = "n";
    cout << count_horse(sound) << endl;
    sound = "neigh";
    cout << count_horse(sound) << endl;
    sound = " ";
    cout << count_horse(sound) << endl;
    return 0;
}
