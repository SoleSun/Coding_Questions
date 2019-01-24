// To find the smallest number with an id greater than the input node's key,
// assuming the nodes have a reference to their parent, one has to do the 
// following:
// * if the given key has a right node, then delve into the right node before 
//   delving into the leftmost node
// * if the given key has no right node, then the inOrder successor is one of
//   the parent nodes, so the node needs a parent node reference.

// * if the given key has no right node and there is no parent reference, then
//   simply traverse the binary search tree, storing the minimum until you reach
//   the input node. 

// Time Complexity of the code is O(n).
