# Queue
### First In First Out

- A tool to overcome the speed difference between high speed process and low speed process (ex. buffer)

- front(pull out) / rear(addition)

- linear queue / circular queue / deque(double-ended queue)


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