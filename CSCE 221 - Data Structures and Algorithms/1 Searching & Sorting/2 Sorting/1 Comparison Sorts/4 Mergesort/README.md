# Mergesort
## Video
https://youtu.be/_xBYR2eRE0Q

## Description
Mergesort attempts to split a list of data into two sections repeatedly. When everything is either a list containing one element or a list containing 0 elements, the lists merge to form a list of the original's size but in order.

The sorting comes from the `merge` function, whose job it is to take in two sorted lists and to merge them such that the output list contains everything in the input list in sorted order.

All `merge_sort` does is split the list into sub-lists, call `merge_sort` on each of the sub-lists, and then call `merge` to put them together afterward.

## Analysis
Mergesort takes O(log n) time to split the lists and O(n) time to merge them. Therefore, because the merge happens after each split, the analysis is O(n log n).

The code in the video manually creates two sub-vectors in the splitting phase, which is O(n), so it should run in O(n^2) time. You can improve this by rewriting it to sort in-place without copying.