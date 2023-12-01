## Binary Search Tree
* Accommodating the coexistence of identical keys within a single node.
<img src="https://upload.wikimedia.org/wikipedia/commons/d/da/Binary_search_tree.svg" width="240">


## Red-black Tree
* Accommodating the coexistence of identical keys within a single node.
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/41/Red-black_tree_example_with_NIL.svg/1920px-Red-black_tree_example_with_NIL.svg.png" width="480">

## Memory Leak Validations
The code in this repository have been validated with the command below and confirmed that memory issue is absent.

`valgrind --leak-check=full --show-leak-kinds=all --verbose --track-origins=yes --log-file=log ./a.out`

## Quick Start
1. `git clone git@github.com:zengbs/trees.git`
2. `cd binary-serach-tree` or `cd red-black-tree`
3. `make clean`
4. `make`
5. `./bin/a.out`
