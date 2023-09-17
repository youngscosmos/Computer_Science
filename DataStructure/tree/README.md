# Tree
### hierarchical structure

- node, edge

- root node, subtree

- parent node, child node, sibling, ancestor node, descendent node, terminal node(=leaf node), nonterminal node

- degree : the number of child nodes a node has

- level : (root = level 1) increases by 1 as go down each floor

- height : maximum level the tree has 

- binary tree : A tree in which every node has two subtrees (Empty sets are also possible)

```
* linear queue / circular queue *


create(max_size) : create empty queue that is max size

init(queue) : initalize queue

is_empty(queue) : check empty queue or not

is_full(queue) : check full queue or not

enqueue(queue, a) : add a rear of queue

dequeue(queue, b) : pull out b front of queue

peek(queue) : show element that is front of queue
```
 

```
* deque(double-ended queue) *

create(max_size)

init(deque)

is_empty(deque)

is_full(deque)

add_front(deque, a) : add a front of deque

add_rear(deque, b) : add b rear of deque

delete_front(deque) : return value front of deque and delete

delete_rear(deque) : return value rear of deque and delete

get_front(deque) : return value front of deque without deleting

get_rear(deque) : return value rear of deque without deleting
```