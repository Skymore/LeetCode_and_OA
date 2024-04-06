// To render the messenger window, each message must start on a newline. You are also given two integers width and userwidth

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> renderMessenger(vector<vector<string>> messages, int width, int userwidth) {
    vector<string> res;
    res.push_back('+' + string(width, '*') + '+');

    for (vector<string> message : messages) {
        string user = message[0];
        string msg = message[1];
        // 按空格划分msg
        vector<string> words;
        string word = "";
        for (char ch : msg) {
            if (ch == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += ch;
            }
        }

        if (word != "") {
            words.push_back(word);
        }

        auto push_back_to_res = [&res, &width, &user] (string line) {
            if (user == "1") {
                res.push_back('|' + line + string(width - line.size(), ' ') + '|');
            } else {
                res.push_back('|' + string(width - line.size(), ' ') + line + '|');
            }
        };

        // 按照width和userwidth的要求，将words分行
        // "1" 靠左
        // "2" 靠右
        string line = "";
        for (string word : words) {
            if (line.empty()) {
                line += word;
                continue;
            }
            if (line.size() + 1 + word.size() <= userwidth) {
                line += " " + word;
            } else {
                push_back_to_res(line);
                line = word;
            }
        }
        if (!line.empty()) {
            push_back_to_res(line);
        }

    }
    res.push_back('+' + string(width, '*') + '+');

    return res;
}

int main() {
    vector<vector<string>> messages = {
        {"1", "Hello how r u"},
        {"2", "Good ty"},
        {"2", "u"},
        {"1", "me too bro"},
    };
    int width = 15;
    int userwidth = 5;
    vector<string> res = renderMessenger(messages, width, userwidth);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}

/*
messages = [
    ["1", "Hello how r u"],
    ["2", "Good ty"],
    ["2", "u"],
    ["1", "me too bro"],
]
*/