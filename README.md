### ⏱️ Input Size → Expected Time Complexity


|                   Input Size | Target / Usually Acceptable | Usually Too Slow      | Typical Techniques                    |
| ---------------------------: | --------------------------- | --------------------- | ------------------------------------- |
|                     `n ≤ 10` | `O(n!)`, `O(2ⁿ)`            | —                     | Backtracking, permutations            |
|                     `n ≤ 20` | `O(2ⁿ)`, `O(n·2ⁿ)`          | `O(n!)`               | Bitmask, subsets                      |
|                    `n ≤ 100` | `O(n³)`                     | `O(2ⁿ)`               | 3 loops, DP, Floyd-Warshall           |
|                    `n ≤ 500` | `O(n³)`                     | `O(2ⁿ)`               | DP, graph algorithms                  |
|          `n ≤ 1,000` (`10³`) | `O(n²)`                     | `O(n³)`               | Nested loops, DP                      |
|        `n ≤ 5,000` (`5×10³`) | `O(n²)`                     | `O(n³)`               | DP, two pointers                      |
|         `n ≤ 10,000` (`10⁴`) | `O(n log n)`                | `O(n³)`               | Sorting, binary search                |
|        `n ≤ 100,000` (`10⁵`) | `O(n log n)`, `O(n)`        | `O(n²)`               | Sorting, HashMap, two pointers        |
|      `n ≤ 1,000,000` (`10⁶`) | `O(n)`, `O(n log n)`        | `O(n²)`               | Linear scan, hashing                  |
|     `n ≤ 10,000,000` (`10⁷`) | `O(n)`                      | `O(n log n)`         | Linear scan, simple algorithms        |
|    `n ≤ 100,000,000` (`10⁸`) | `O(n)`                      | `O(n log n)`, `O(n²)` | Highly optimized iteration            |
|  `n ≤ 1,000,000,000` (`10⁹`) | `O(log n)`, `O(1)`          | `O(n)`                | Binary search, mathematics            |
| `n > 1,000,000,000` (`10⁹+`) | `O(log n)`, `O(1)`          | `O(n)`                | Math, binary search, divide & conquer |

