#include "./main.h"

int main(int argc, char *argv[]) {
    bool len_cnt = false, draw = false, not_found = false;
    auto cli = (
            clipp::option("--len-cnt").set(len_cnt) % "using len_cnt",
                    clipp::option("--draw").set(draw) % "using draw"
    );
    clipp::parse(argc, argv, cli);
    if (len_cnt) {
        std::cout << "len-cnt" << std::endl;
        std::string result = LenCount::parse(argc, argv);
        std::cout << result << std::endl;
    } else if (draw) {
        std::cout << "not implemented" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

//    auto cli = (());
    return 0;
}