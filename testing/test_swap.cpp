#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int value1 = 10;
    int value2 = 20;

    swap(&value1, &value2);
    EXPECT_EQ(value1, 20);
    EXPECT_EQ(value2, 10);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */
    const int vals1[] = {10, 20, 30};
    int values1[] = {10, 20, 30};

    const int vals2[] = {30, 20, 10};
    int values2[] = {30, 20, 10};

    swap(&values1[0], &values2[0]);
    EXPECT_EQ(values1[0], 30);
    EXPECT_EQ(values2[0], 10);

    for (int i = 1; i < 3; i++) { // checking to see the rest of the array is the same
        EXPECT_EQ(values1[i], vals1[i]);
        EXPECT_EQ(values2[i], vals2[i]);
    }
}

// RC_GTEST_PROP(SwapTests,
//               PropertySwapTwoValues,
//               (int a_start, int b_start)
// ) {
//     /*
//      * Swap two values and see if the swap was successful.
//      */
// }
//
//
// RC_GTEST_PROP(SwapTests,
//               PropertySwapValuesInArray,
//               (const std::vector<int>& values)
// ) {
//     /*
//      * Swap two values in an array. See that they swapped and the others did not
//      */
// }
