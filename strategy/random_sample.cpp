//
// Created by cw on 12/12/19.
//

#include "random_sample.h"


std::string sample(const std::string &file, const std::string &sampled_file, int sample_size,
                   int length_lower_bound, int length_upper_bound) {
    auto failure = R"({"success":false})";
    std::ifstream ifs;
    ifs.open(file);
    if (!ifs.is_open()) {
        std::cerr << file << std::endl;
        std::cerr << "oh shit" << std::endl;
        return failure;
    }
    std::string line;
    std::vector<std::string> passwords;
    while (getline(ifs, line)) {
        int len = line.size();
        if (length_lower_bound <= len && len <= length_upper_bound) {
            passwords.push_back(line);
        }
    }
    std::shuffle(passwords.begin(), passwords.end(), std::mt19937(std::random_device()()));
    std::ofstream ofs(sampled_file, std::ios::out);
    if (!ofs) {
        return failure;
    }
    for (int i = 0, len = std::min(sample_size, (int) passwords.size()); i < len; i++) {
        ofs << passwords.at(i) << std::endl;
    }
    ofs.flush();
    ofs.close();
    auto success = R"({"success":true})";
    return success;
}

std::string RandomSample::parse(int argc, char *argv[]) {
    std::string file;
    std::string sampled_file;
    int sampled_size = 1;
    int length_lower_bound = 1;
    int length_upper_bound = 255;
    auto cmdline = ((clipp::required("-f", "--file") & clipp::value("password file", file)),
            (clipp::required("-s", "--save") & clipp::value("sampled file", sampled_file)),
            (clipp::required("-n", "--size") & clipp::value("sample size", sampled_size)),
            (clipp::option("-l", "--lower") & clipp::value("lower bound", length_lower_bound)),
            (clipp::option("-u", "--upper") & clipp::value("upper bound", length_upper_bound)));
    if (!clipp::parse(argc, argv, cmdline)) {
        std::cerr << clipp::usage_lines(cmdline, "random_sample") << std::endl;
        std::exit(1);
    }
    std::string result = sample(file, sampled_file, sampled_size, length_lower_bound, length_upper_bound);
    return result;
}

int main(int argc, char *argv[]) {
    auto result = RandomSample::parse(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
