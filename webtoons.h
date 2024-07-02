#ifndef WEBTOONS_H
#define WEBTOONS_H

#include <vector>
#include <string>

struct Webtoon {
    int id;
    std::string title;
    std::string genre;
    std::string description;

    // default constructor
    Webtoon() : id(0), title(""), genre(""), description("") {}
};

class WebtoonManager {
public:
    // constructor
    WebtoonManager();

    // declarations
    std::string get_webtoons() const;
    void swipe(int webtoon_id, const std::string& action);
    std::string get_user_preferences() const;

private:
    std::vector<Webtoon> webtoons;
    std::vector<int> liked_webtoons;
    std::vector<int> disliked_webtoons;
};

#endif // WEBTOONS_H
