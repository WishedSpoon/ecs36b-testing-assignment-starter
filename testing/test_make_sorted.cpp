#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 2, 3, 4, 5};
    int copyTestArray[] = {1, 2, 3, 4, 5};

    make_sorted(testArray, 5); //4, 1, 2, 3, 5
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(testArray[i], copyTestArray[i]);
    }
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int reverseTestArray[] = {10, 9, 8, 7, 6};
    int sortedTestArray[] = {6, 7, 8, 9, 10};

    make_sorted(reverseTestArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(reverseTestArray[i], sortedTestArray[i]);
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int randomTestArray[] = {7, 8, 3, 2, 10};
    int sortedTestArray[] = {2, 3, 7, 8, 10};

    make_sorted(randomTestArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(randomTestArray[i], sortedTestArray[i]);
    }
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int randomTestArray[] = {4, 3, 8, 4, 10};
    int sortedTestArray[] = {3, 4, 4, 8, 10};

    make_sorted(randomTestArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(randomTestArray[i], sortedTestArray[i]);
    }
}
//
// RC_GTEST_PROP(MakeSortedTests,
//               PropertyAfterSortingValuesAreInAscendingOrder,
//               ( std::vector<int> values)
// ) {
//     /* Test that after sorting an array, the values are in ascending order
//      * Don't forget to free any memory that was dynamically allocated as part of your test.
//      */
// }
