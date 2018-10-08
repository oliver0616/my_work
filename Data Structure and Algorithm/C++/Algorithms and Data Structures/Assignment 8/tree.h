#ifndef __TREE_H
#define __TREE_H

#define NUMBER_OF_CHARS 256

// The NodeKind is used to label a tree node as either an nonleaf node (a
// node with children) or a leaf node (a node holding a character).
typedef enum NodeKind {
  leaf,
  nonleaf
} NodeKind;

// This structure represents the frequency of a character encountered in the
// input text. It holds the frequency and the associated character.
typedef struct Frequency {
  // Frequency value:
  int  v;
  // Character:
  unsigned char c;
} Frequency;

// A TreeNode represents a node in the tree. It has a unique id (id) that
// identifies the node, the type (nonleaf/leaf), the frequency, the left
// child, and the right child.
struct Node {
  NodeKind  kind;
  char      ch;
  Node* 	left;
  Node* 	right;

  Node(char c)
  {
	  kind = leaf;
	  ch = c;
  }

  Node(Node* L, Node* R)
  {
	  kind = nonleaf;
	  left = L;
	  right = R;
  }
};

typedef Node* Tree;

#endif