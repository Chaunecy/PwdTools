#include "pwd_tool.h"

int main(int argc, char *argv[]) {
    bool len_cnt = false, draw = false, not_found = false;
    auto cli = (
            clipp::option("--len-cnt").set(len_cnt) % "using len_cnt",
                    clipp::option("--draw").set(draw) % "using draw"
    );
    clipp::parse(argc, argv, cli);
    std::string result;
    if (len_cnt) {
        result = LenCount::parse(argc, argv);
    } else if (draw) {
        std::cout << "not implemented" << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }
    std::cout << result << std::endl;

    return 0;
}