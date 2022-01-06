#include <gmock/gmock.h>

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);

    const int32_t l_ret = RUN_ALL_TESTS();

    return l_ret;
}