#ifdef NDEBUG
 #undef NDEBUG
 #include <cassert>
 #define NDEBUG
#else
 #include <cassert>
#endif

#include <gmock/gmock.h>
#include <gtest/gtest.h>
