## Binary Search Tree
* Accommodate the coexistence of identical keys within a single node.
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1024px-Binary_search_tree.svg.png" width="480">


## Red-black Tree
* Accommodate the coexistence of identical keys within a single node.
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Red-black_tree_example_with_NIL.svg/1920px-Red-black_tree_example_with_NIL.svg.png" width="480">

## Memory leak validations
The code in this repository have been validated with the command below and confirmed that memory issues are absent.

`valgrind --leak-check=full --show-leak-kinds=all --verbose --track-origins=yes --log-file=log ./a.out`
## Quick Start
1. `git clone git@github.com:zengbs/trees.git`
2. `cd binary-serach-tree`
3. `make clean`
4. `make`
5. `./bin/a.out`
