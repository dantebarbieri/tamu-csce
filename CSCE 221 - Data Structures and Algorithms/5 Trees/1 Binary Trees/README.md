# Binary Search Trees
## Video
https://youtu.be/j5AWclm0BJM

I'm putting timestamps on this one because it is ridiculously long.

## Description
Binary Search Trees are a simplistic and generic structure that differs from Linked Lists in that they are no longer linear. A list node can always point to the next node, whereas a Binary Tree Node can point to its left and right child, should they exist. Therefore, there are up to two options for going to the following item at every point in a tree. A key concept for working with all trees is recursion; we'll use it a lot!

Our Binary Search Tree keeps track of its size (not its height) and can `search` for a value. It can also `insert` and `remove` values once the containing node has returned by reference from either a search or an insert. It supports the Rule of 5 (though this hasn't been tested!) and some C++ Standard Template Library (STL) functions such as `empty` and `size`. It flouts other functions such as using `destroy` instead of `clear`, though this is part of the `protected` members instead of the exposed public ones.

Most of the tree is written with the help of `protected` helper functions. It is intended to be extended in the future, which is why it has a `virtual` destructor and *any* `protected` members. If you do not want to extend the tree, then `private` is a better choice for such members.

## Analysis
`copy` &ndash; O(n), where n is the number of nodes below `their_node` in the first call to the function. The reasoning is that it will copy each of the nodes below `their_node`, which it does by calling `insertLeft`, an O(1) operation.

`destroy` &ndash; O(n), this is a textbook postorder traversal of a tree and therefore hits every node one time, running in O(n), where n is the number of nodes in the subtree rooted at `node` in the first call to destroy.

`reset` &ndash; O(1), this function is unsafe and can result in memory leaks, but it effectively assigns two values and therefore runs in O(1) time.

`search` helper &ndash; O(n), this function checks every node in the tree until it finds what it is looking for, which can take O(n) time. You will see that `search` is improved when we introduce an *ordering property*. We can guarantee that there are parts of the tree that will not contain our value and therefore do not need to be searched.

`print` &ndash; O(n*h), where n is the number of nodes and h is the height of the tree because every node is visited once and takes at most O(h) iterations of the loop to provide the proper padding. This function becomes more efficient on shorter (less height) trees with the same number of nodes. Because not every node has height h, there may be a smaller lower-bound for you to find for the worst-case runtime.

`findWithChild` &ndash; O(n), this function is a slightly modified search.

`empty` &ndash; O(1), trivially.

`size` &ndash; O(1), trivially.

`length` &ndash; O(1), trivially.

Default Constructor &ndash; O(1), we assume that heap allocation (`new`) takes constant time.

Copy Constructor &ndash; O(n), we call `copy` with `bt.root`, which means n refers to the size of `bt`, which is the same size as our tree after the copy.

Move Constructor &ndash; O(1), we call `reset` and assign two pointers, this is trivially constant time.

Destructor &ndash; O(n), calls `destroy` from the `root` and then calls `reset`.

Copy Assignment &ndash; O(n), see Copy Constructor.

Move Assignment &ndash; O(1), see Move Constructor.

`search` &ndash; O(n), see `search` helper.

`insertLeft` &ndash; O(1), we assume that heap allocations (`new`) are O(1), and everything else is an assignment of simple types.

`insertRight` &ndash; O(1), we assume that heap allocations (`new`) are O(1), and everything else is an assignment of simple types.

`remove` &ndash; O(n^2*h), we `search` at most n nodes for each removal and `remove` at most n nodes from the tree of height h calling `removeLeft` and `removeRight` for each removal which is where the h comes in.

`removeLeft` &ndash; O(h), we start at the node to remove and walk down the tree until we reach a leaf removing nodes as we go. This can be made more efficient by stopping whenever there is a lone child and dragging them upwards, but that is left as an exercise for the student.

`removeRight` &ndash; O(h), we start at the node to remove and walk down the tree until we reach a leaf removing nodes as we go. This can be made more efficient by stopping whenever there is a lone child and dragging them upwards, but that is left as an exercise for the student.

`ostream` Operator &ndash; O(n*h), see `print`.