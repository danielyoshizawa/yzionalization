#include "reader.h"
#include <iostream>

int main()
{

    yz::reader r;
    r.load("/Users/daniel/Documents/Development/Projects/yzionalization/src/tests/input/en_en.txt", ":");
    std::cout << r.translate("test_string") << std::endl;
    std::cout << r.translate("string_explanation") << std::endl;
    return 0;
}
