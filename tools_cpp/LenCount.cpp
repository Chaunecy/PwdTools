//
// Created by cw on 12/6/19.
//
#include "LenCount.h"


using json = nlohmann::json;

double round(double fraction, int pos) {
    int t = 1;
    for (int i = 0; i < pos; i++) {
        t *= 10;
    }
    return ((double) ((int) (fraction * t))) / t;
}

std::string len_cnt(const std::vector<std::string> &filenames,
                    const std::vector<std::string> &shownames,
                    int length_lower_bound,
                    int length_upper_bound) {

    auto failure = R"({"success":false})";
    if (filenames.size() != shownames.size() || filenames.empty()) {
        return failure;
    }
    std::ifstream ifs;
    json arr = json::array();
    int file_idx = 0;
    for (const auto &filename: filenames) {
        ifs.open(filename);
        if (!ifs.is_open()) {
            continue;
        }
        std::unordered_map<int, int> length_counter;
        std::string line;
        while (getline(ifs, line)) {
            int len = line.size();
            if (len <= length_upper_bound && len >= length_lower_bound) {
                if (length_counter.find(len) == length_counter.end()) {
                    length_counter.insert(std::make_pair(len, 1));
                } else {
                    length_counter.at(len) += 1;
                }
            }
        }
        int total_lines = 0;
        for (const auto &pair: length_counter) {
            total_lines += pair.second;
        }
        if (total_lines == 0) {
            continue;
        }
        for (const auto &pair: length_counter) {
            json j;
            j["length"] = pair.first;
            j["count"] = pair.second;
            j["proportion"] = round((double) pair.second / total_lines * 100, 2);
            j["dataset"] = shownames.at(file_idx);
            arr.push_back(j);
        }
        file_idx += 1;
        ifs.close();
    }
    return arr.dump();
}

std::string LenCount::parse(int argc, char *argv[]) {
    std::vector<std::string> filenames;
    std::vector<std::string> shownames;
    int length_lower_bound = 4;
    int length_upper_bound = 40;
    auto cli = ((clipp::required("-f", "--files") & clipp::values("files", filenames)),
            (clipp::required("-t", "--tags") & clipp::values("tags", shownames)),
            (clipp::option("-l", "--lower") & clipp::value("length_lower_bound", length_lower_bound)),
            (clipp::option("-u", "--upper") & clipp::value("length_upper_bound", length_upper_bound)));
    if (clipp::parse(argc, argv, cli)) {
        std::string result = len_cnt(filenames, shownames, length_lower_bound, length_upper_bound);
        return result;
    } else {
        std::cerr << clipp::usage_lines(cli, "len_count") << std::endl;
        std::exit(1);
    }
}

int main(int argc, char *argv[]) {
    std::cout << LenCount::parse(argc, argv) << std::endl;
    return 0;
}