//
// Created by cw on 12/6/19.
//

#include <iostream>
#include "./include/json.hpp"

using json = nlohmann::json;

int main(int argc, char *argv[]) {
    std::unordered_map<int, int> length_counter;
    length_counter.insert(std::make_pair(2, 3));
    length_counter.insert(std::make_pair(3, 4));
    length_counter.insert(std::make_pair(1, 3));
//    json j(length_counter);
    json arr = json::array();

    for (const auto &lc : length_counter) {
        json j;
        j["length"] = lc.first;
        j["count"] = lc.second;
        j["proportion"] = .1;
        j["dataset"] = "hello";
//        arr.insert(j);
//        std::cout << j.dump(2) << std::endl;
        arr.push_back(j);
    }
    std::cout << arr.dump(2) << std::endl;
//    json j = json::object({
//                                  {"pi", 3.14},
//                                  {1,    2}
//                          });
//    std::cout << j.dump(4) << std::endl;
//    auto j2 = json::parse(R"({"happt": true, "pi": 3.14})");
//    std::cout << j2 << std::endl;
//    auto j3 = j2.dump(2);
//    std::cout << j3 << std::endl;
}