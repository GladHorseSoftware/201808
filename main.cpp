#include <iostream>
#include "common.h"

#ifndef ENV_UNITTEST
int main() {
    main1();
    return 0;
}

#else
GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
