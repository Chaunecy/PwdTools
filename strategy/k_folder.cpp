//
// Created by cw on 12/12/19.
//

#include "k_folder.h"

std::string k_folder(const std::string &file, int k,
                     const std::vector<std::string> &training_files,
                     const std::vector<std::string> &testing_files) {
    /**
     * check the bound of k
     */
    if (k > 10) {
        k = 10;
    } else if (k < 2) {
        k = 2;
    }
    if (!(testing_files.size() == training_files.size() && (int) training_files.size() == k)) {
        std::cerr << "params not match: training files != testing files or != k" << std::endl;
        std::exit(1);
    }
    std::ifstream ifs(file);
    if (!ifs.is_open()) {
        std::cerr << "open file: " << file << " failed" << std::endl;
        std::exit(1);
    }
    std::string line;
    std::vector<std::string> passwords;
    while (getline(ifs, line)) {
        passwords.push_back(line);
    }
    std::shuffle(passwords.begin(), passwords.end(), std::mt19937(std::random_device()()));
    int size = passwords.size();
    int batch = size / k;
    for (int i = 0; i < k; i++) {
        std::ofstream ofs_train(training_files.at(i), std::ios::out);
        std::ofstream ofs_test(testing_files.at(i), std::ios::out);
//        auto content = batches.at(i);
        for (int j = 0; j < k; j++) {
            auto it = passwords.begin() + (j * batch);
            auto end = passwords.begin() + std::min((j + 1) * batch, size);
            if (i == j) {
                for (; it != end; it++)
                    ofs_test << *it << '\n';
            } else {
                for (; it != end; it++)
                    ofs_train << *it << '\n';
                ofs_train.flush();
            }
        }
        ofs_train.flush();
        ofs_train.close();
        ofs_test.flush();
        ofs_test.close();
    }
    return "";
}

std::string KFolder::parse(int argc, char **argv) {
    std::string file;
    int k = 2;
    std::vector<std::string> training_files;
    std::vector<std::string> testing_files;
    auto cmdline = (clipp::required("-f", "--file") & clipp::value("password file", file),
            clipp::required("-k", "--k-folder") & clipp::value("k folder", k),
            clipp::required("-t", "--training-files") & clipp::values("training files", training_files),
            clipp::required("-s", "--testing-files") & clipp::values("testing files", testing_files));
    if (clipp::parse(argc, argv, cmdline)) {
        return k_folder(file, k, training_files, testing_files);
    } else {
        std::cerr << clipp::make_man_page(cmdline, "k-folder") << std::endl;
        std::exit(1);
    }
}

int main(int argc, char *argv[]) {
    std::cout << KFolder::parse(argc, argv) << std::endl;
}