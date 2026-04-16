#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 2, 3, 4, 5, 6};
    int* copiedArray = copy_array(testArray, 6);

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(testArray[i], copiedArray[i]);
    }
    free(copiedArray);
}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int testArray[] = {6, 5, 4, 4, 5, 6};
    int copyTestArray[] = {6, 5, 4, 4, 5, 6};
    int* copiedArray = copy_array(testArray, 6);

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(testArray[i], copyTestArray[i]);
    }
    free(copiedArray);
}


TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int testArray[] = {1, 1, 1, 1, 1, 1};
    int* copiedArray = copy_array(testArray, 6);

    EXPECT_NE(testArray, copiedArray);
    free(copiedArray);
}

//
// RC_GTEST_PROP(CopyArrayTests,
//               PropertyValuesAreSame,
//               (const std::vector<int>& values)
// ) {
//     /*
//      * Check that the values in the copy are the same as the values in the original array.
//      * Don't forget to free any memory that was dynamically allocated as part of your test.
//      */
//
// }
//
// RC_GTEST_PROP(CopyArrayTests,
//               PropertyOriginalDoesNotChange,
//               (const std::vector<int>&values)
// ) {
//     /*
//      * Check that the  values in the original array did not change.
//      * Don't forget to free any memory that was dynamically allocated as part of your test.
//      */
//
// }
//
// RC_GTEST_PROP(CopyArrayTests,
//               PropertyCopyWasMade,
//               (const std::vector<int>&values)
// ) {
//     /*
//   * Check that a copy was actually made
//   * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
//   * Don't forget to free any memory that was dynamically allocated as part of your test.
//   */
//
// }



