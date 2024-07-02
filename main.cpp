#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <crow.h>
#include <webtoons.cpp>
#include <webtoons.h>

using namespace std;

// not too familiar with Crow yet. Find alternatives?
int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/webtoons")
    ([](){
        return crow::response(get_webtoons());
    });

    CROW_ROUTE(app, "/swipe").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req){
        auto body = req.body;
        auto pos = body.find(",");
        int webtoon_id = stoi(body.substr(0, pos));
        string action = body.substr(pos + 1);

        swipe(webtoon_id, action);

        return crow::response(get_user_preferences());
    });

    app.port(8080).multithreaded().run();
}
