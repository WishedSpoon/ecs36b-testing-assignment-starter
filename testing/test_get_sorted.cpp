#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 2, 3, 4, 5};

    int *sortedArray = get_sorted(testArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(sortedArray[i], testArray[i]);
    }

    free(sortedArray);
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int testArray[] = {10, 8, 6, 4, 2};
    int sortedTestArray[] = {2, 4, 6, 8, 10};

    int *sortedArray = get_sorted(testArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(sortedArray[i], sortedTestArray[i]) << sortedArray[i] << ": Sorted Array " << sortedTestArray[i] << ": Expected";
    }

    free(sortedArray);
}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int testArray[] =       {2, 7, 4, 1, 5};
    int sortedTestArray[] = {1, 2, 4, 5, 7};

    int *sortedArray = get_sorted(testArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(sortedArray[i], sortedTestArray[i])  << sortedTestArray[i] << ": Sorted Array " << sortedTestArray[i] << ": Expected";
    }

    free(sortedArray);
}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {5, 2, 5, 4, 5};
    int sortedTestArray[] = {2, 4, 5, 5, 5};

    int *sortedArray = get_sorted(testArray, 5);

    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(sortedArray[i], sortedTestArray[i]) << sortedTestArray[i] << ": Sorted Array " << sortedTestArray[i] << ": Expected";
    }

    free(sortedArray);
}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 2, 3};
    get_sorted(testArray, 3);

    for (int i = 0; i < 3; ++i) {
        EXPECT_EQ(testArray[i], testArray[i]) ;
    }
}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 2, 3, 4, 5};
    int *sortedArray = get_sorted(testArray, 5);

    EXPECT_NE(testArray, sortedArray);
    free(sortedArray);
}

//
// RC_GTEST_PROP(GetSortedTests,
//               PropertyAfterSortingValuesAreInAscendingOrder,
//               ( std::vector<int> values)
// ) {
//     /* Check that after sorting an array, the values are in ascending order
//      * Don't forget to free any memory that was dynamically allocated as part of this test
//      */
//
// }
//
// RC_GTEST_PROP(GetSortedTests,
//               PropertyOriginalDoesNotChange,
//               (const std::vector<int>&values)
// ) {
//     /*
//      * Check that the original array was not modified.
//      * Don't forget to free any memory that was dynamically allocated as part of your test.
//      */
//     ;
// }
//
// RC_GTEST_PROP(GetSortedTests,
//               PropertyCopyWasMade,
//               (const std::vector<int>&values)
// ) {
//     /*
//      * Check that the sorted array is copy of the original array in sorted order.
//      * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
//      * Don't forget to free any memory that was dynamically allocated as part of your test.
//      */
//
// }
//










