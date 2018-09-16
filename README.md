# Inversions

Calculating the number of inversions in an array or dataset is a measure of how numerically ordered or unordered the dataset is.
This can be useful when comparing datasets for example in collaborative filtering.

I've provided results below for the naive approach which asymptotically is O(n^2) and also a smarter divide and conquer approach which is O(nlog(n)).

Compiler optimisations (denoted by \*\) make a huge difference on the naive O(n^2) approach.

All benchmarks are on:
* 2-core 3GHz i7 Mac Laptop
* 16 GB RAM
* N = 100,000 integers in the dataset
* All figures are the average of 10 runs.

The performance boost is measured relative to the slowest naive case.

| Approach | Time / N | Total Time | Performance Boost |
| :------- | :------: | :--------: | :---------------: |
| Naive    | 230 usec | 22.84 sec  | 1X                |
| Naive*   | 17.6 usec| 1.76 sec   | 13X               |
| Divide & Conquer | .2 usec | 0.020 sec | 1,142X      |
| Divide & Conquer* | .18 usec | 0.018 sec | 1,269X    |

The divide & conquer algorithm is over **1,000 times** faster than the basic approach - WOW!
