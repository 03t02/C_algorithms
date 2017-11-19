# Linear Search
###### Time Complexity
| Type            | Worst case |
|-----------------|------------|
| **Search**      | O(n)       |

The goal of this simple algorithm is to find an element in an unsorted array, and returns the index of this one.

The process is simple. We take our array, and iterate over it. For earch element, we compare this one to the element that we want to find.

Example: we have an array like this: `[1, 4, 5, 7, 0, 3, 2]`. And we want to know if the number `7` exists in this array. What we have to do is, compare each element to the number `7` until we find this number in our array.

## What if your array is sorted ?
If your array is sorted, you can incredibly decrase the complexity time by using the `binary search` algorithm.
You can know more about this algorithm [here](https://github.com/03t02/C_algorithms/tree/master/Binary%20Search).

### Comparison between these 2 algorithms.

With `100 000 000` elements in an sorted array. And we're searching for the number: `348437`.

| Linear Search| Binary Search|
|--------------|--------------|
| 0.000505     | 0.000008     |

It seems not too much even with the `Linear Search` algorithm. But it is really significant if you have a billions of billions elements to search.