# Binary Search

To decrease the search complexity time, we can use the `binary search` instead of [Linear Search](https://github.com/03t02/C_algorithms/tree/master/Linear%20Search).

For an array of `n` elements. You don't have to lopper over the array to find the element that you are searching for. `Linear Search` would take a time complexity of **O(n)**.
With the `Binary Search` the time complexity is **O(log n)**. That's why it's really fast.

With an array of `100 000 000` elements. It would take around 26 steps to find the element.

### How it works ?
`Binary Search` algorithm uses a simple process called `Divide and Conquer`.

First we have to divide our array in half. We determinate which half to use, and work on it.

Let's say, that we have this array: `[23, 34, 35, 37, 45, 56, 67]`. And we want to find the number `56`.

With `Linear Search` algorithm, it would take us 6 steps to find our number here.

**Now, we gonna see how the `Binary Search` algorithm works**

First we gonna divide our array in half at index `3`

```
[23, 34, 35, 37 | 45, 56, 76]
              *
```

The value of the third index here is `37`. And `37` is lower than our number `56`. So we don't have to look at all the numbers from the index 0 until the third index, because we are sure that all the numbers from this range are lower than `56`.

The interesting part here is the other half. From the 4th index until the end. So we repeat the process again.

```
[x, x, x, x | 45, 56, 76]
                   *
```

And now, we have to split in half the second part of our array. Here we gonna devide this array at index `5`. And the value of the 5th index is...`56`.

With `Binary Search`, it would take us only 2 steps to find our number.


### Comparison between these 2 algorithms.

With `100 000 000` elements in an sorted array. And we're searching for the number: `348437`.

| Linear Search| Binary Search|
|--------------|--------------|
| 0.000505     | 0.000008     |

It seems not too much even with the `Linear Search` algorithm. But it is really significant if you have a billions of billions elements to search.
