#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <webtoons.h>

using namespace std;

// constructor
WebtoonManager::WebtoonManager() {
    // samples
    webtoons = {
        {1, "Webtoon 1", "Genre 1", "1."},
        {2, "Webtoon 2", "Genre 2", "2."}
        // need to figure out a way to scrape data from webtoon LINE and mangaread.org 
        // to add into here
    };
}

vector<int> liked_webtoons;
vector<int> disliked_webtoons;

string get_webtoons() {
    string result;
    for (const auto& webtoon : webtoons) {
        result += to_string(webtoon.id) + "," + webtoon.title + "," + webtoon.genre + "," + webtoon.description + "\n";
    }
    return result;
}

void swipe(int webtoon_id, const string& action) {
    if (action == "like") {
        liked_webtoons.push_back(webtoon_id);
    } else if (action == "dislike") {
        disliked_webtoons.push_back(webtoon_id);
    }
}

string get_user_preferences() {
    string result = "Liked: ";
    for (const auto& id : liked_webtoons) {
        result += to_string(id) + " ";
    }
    result += "\nDisliked: ";
    for (const auto& id : disliked_webtoons) {
        result += to_string(id) + " ";
    }
    return result;
}