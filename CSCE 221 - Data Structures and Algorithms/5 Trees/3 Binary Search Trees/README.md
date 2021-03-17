# Binary Search Trees
## Video
https://youtu.be/cMFCJv3A4AU

Timestamps are on this one, but it is only 48 minutes long, not as bad as Binary Trees.

## Description
Binary Search Trees are a type of Binary Tree where the nodes must be inserted and removed in particular locations to enable a faster search. A Balanced Binary Search Tree can perform every operation in O(log n) time because the tree's height is h=log n. For this Binary Search Tree which is not necessarily balanced, many functions run in O(h), where h is the tree's height, and h is in O(n) because it can be as unbalanced as a straight line.

## Analysis
`copy` &ndash; O(nh), where n is the number of nodes and h is the height. This is because we call insert for each node which is O(h).

`destroy` &ndash; O(n), this is a textbook postorder traversal of a tree and therefore hits every node one time, running in O(n), where n is the number of nodes in the subtree rooted at `node` in the first call to destroy.

`reset` &ndash; O(1), this function is unsafe and can result in memory leaks, but it effectively assigns two values and therefore runs in O(1) time.

`print` &ndash; O(nh), where n is the number of nodes and h is the height of the tree because every node is visited once and takes at most O(h) iterations of the loop to provide the proper padding. This function becomes more efficient on shorter (less height) trees with the same number of nodes. Because not every node has height h, there may be a smaller lower-bound for you to find for the worst-case runtime.

`empty` &ndash; O(1), trivially.

`size` &ndash; O(1), trivially.

`length` &ndash; O(1), trivially.

Default Constructor &ndash; O(1), trivially.

Copy Constructor &ndash; O(nh), see `copy` helper.

Move Constructor &ndash; O(1), we call `reset` and assign two pointers; this is trivially constant time.

Destructor &ndash; O(n), calls `destroy` from the `root` and then calls `reset`.

Copy Assignment &ndash; O(nh), see Copy Constructor.

Move Assignment &ndash; O(1), see Move Constructor.

`search` &ndash; O(h), where h is the height of the tree. This is an improvement over the Binary Tree's search, but only if the tree is nonlinear.

`insert` &ndash; O(h), starting at the top and working our way down, the worst case is we walk the maximum branch of the tree, of length h.

`ostream` Operator &ndash; O(n*h), see `print`.