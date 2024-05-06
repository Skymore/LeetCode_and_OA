#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Results {
    string set_name;
    vector<string> selected_cards;
};

map<int, vector<string>> rankToCards;
map<char, vector<string>> suitToCards;
map<int, int> rankCounts;
map<char, int> suitCounts;

// Helper functions
int rankValue(const string& rank) {
    if (rank == "A") return 14;
    if (rank == "K") return 13;
    if (rank == "Q") return 12;
    if (rank == "J") return 11;
    if (rank.size() == 2) return 10; // Handling "10" specifically
    return rank[0] - '0'; // For numeric ranks 2-9
}

int suitValue(char suit) {
    if (suit == 'S') return 4;
    if (suit == 'H') return 3;
    if (suit == 'D') return 2;
    if (suit == 'C') return 1;
    return 0;
}

bool cardCompare(const string& card1, const string& card2) {
    int rank1 = rankValue(card1.substr(0, card1.size() - 1));
    int rank2 = rankValue(card2.substr(0, card2.size() - 1));
    char suit1 = card1.back();
    char suit2 = card2.back();
    if (rank1 != rank2) return rank1 > rank2;
    return suitValue(suit1) > suitValue(suit2);
}

// Find functions
Results findFourOfAKind() {
    for (auto& [_, v] : rankToCards) {
        if (v.size() == 4) {
            return {"Four of a Kind", v};
        }
    }
    return {"", {}};
}

Results findFullHouse() {
    vector<string> v3;
    vector<string> v2;

}




// Assume similar implementations for findFlush, findStraight, findThreeOfAKind, findPair, findHighCard
Results solution(const vector<string>& cards) {
    for (const string& card : cards) {
        int rank = rankValue(card.substr(0, card.size() - 1));
        char suit = card.back();
        rankToCards[rank].push_back(card);
        suitToCards[suit].push_back(card);
    }

    for (auto& [_, v] : suitToCards) {
        sort(v.begin(), v.end(), cardCompare);
    }

    // Call other find functions in order of priority and return the result
    return {"No Set", {}};
}
