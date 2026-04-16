#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int testArray[] = {1, 10, 10, 10};
    int minIndex = min_index_of_array(testArray, 4);

    EXPECT_EQ(minIndex, 0);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int testArray[] = {10, 9, 8, 7};
    int minIndex = min_index_of_array(testArray, 4);

    EXPECT_EQ(minIndex, 3);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
    int testArray[] = {10, 8, 7, 8, 10};
    int minIndex = min_index_of_array(testArray, 5);

    EXPECT_EQ(minIndex, 2);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int testArray[] = {10, 8, 8, 8, 10};
    int minIndex = min_index_of_array(testArray, 5);

    EXPECT_EQ(minIndex, 1);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int testArray[] = {10, 8, 8, 8, 10};
    int copyTestArray[] = {10, 8, 8, 8, 10};

    min_index_of_array(testArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(testArray[i], copyTestArray[i]);
    }
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              ()) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              ()) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
}
