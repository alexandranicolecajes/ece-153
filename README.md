An expression parser, lexer, and ultimately an interpreter that implements an Abstract Syntax Tree for chained 
variable assignments of binary expressions with either
integer literals or variable identifers as their operands. Currently all variable identifiers will return 0 whenthe AST is traversed.

Expressions are parsed from Infix notation, and the AST is printed in Postfix notation by doing
a pre-order traversal of the AST

The parser implements a stack machine that push or pops BTree* structures.
Leaf Nodes int the AST are operands, or identifers, while non leaf nodes (internal nodes) binary operations
identifed in the BTree.value.type as IS_OP;
