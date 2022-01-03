int consider, notConsider;
// if (len == 0 && sum == 0)
//     return 1;

// if (len == 0 && sum != 0)
//     return 0;

// // When arr Element is Greater than SUM .
// if (arr[len - 1] > sum)
//     return Subset_CountFinder(arr, sum, len - 1); //  Not Consider

// consider = Subset_CountFinder(arr, sum - arr[len - 1], len - 1); //  Consider
// notConsider = Subset_CountFinder(arr, sum, len - 1);             // Not Consider

// return consider + notConsider;