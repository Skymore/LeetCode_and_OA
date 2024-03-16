/*
 * 题意：
 * reviews是一组评论，positive_words是一组正面词，negative_words是一组负面词，intensity是一组强度词。
 * 每个review是一句话，每个词是一个单词，单词之间用空格隔开。
 * 评论中的词可能是正面词，也可能是负面词，也可能是强度词，也可能是其他词。
 * 如果评论中的词是正面词，那么评论的分数加1，如果评论中的词是负面词，那么评论的分数减1，如果评论中的词是强度词，那么下一个正面词或者负面词的分数变化会增加1。
 * 求每个评论是"positive"还是"negative"还是"neutral"。
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<string> solution(const vector<string> &reviews, const vector<string> &positive_words,
                        const vector<string> &negative_words, const vector<string> &intensity) {
    map<string, int> word_score;
    set<string> intensity_words;
    vector<string> res;

    // Initialize word scores and intensity words
    for (const auto &word : positive_words) word_score[word] = 1;
    for (const auto &word : negative_words) word_score[word] = -1;
    for (const auto &word : intensity) intensity_words.insert(word);

    for (const auto &review : reviews) {
        istringstream iss(review);
        string word;
        int score = 0, multiplier = 1;

        while (iss >> word) {
            if (intensity_words.find(word) != intensity_words.end()) {
                multiplier = 2; // Increase the multiplier for the next word
            } else {
                auto it = word_score.find(word);
                if (it != word_score.end()) {
                    score += it->second * multiplier;
                    multiplier = 1; // Reset the multiplier after use
                }
            }
        }

        // Determine the sentiment based on the score
        string sentiment = "neutral";
        if (score > 0) sentiment = "positive";
        else if (score < 0) sentiment = "negative";

        res.push_back(sentiment);
    }

    return res;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> reviews = {"I am happy", "I am sad", "I am very happy and sad", "I am very happy and very sad"};
    vector<string> positive_words = {"happy"};
    vector<string> negative_words = {"sad"};
    vector<string> intensity = {"very"};
    vector<string> res = solution(reviews, positive_words, negative_words, intensity);
    for (auto &s : res) {
        cout << s << endl;
    }
    return 0;

}
