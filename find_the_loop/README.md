# FIND THE LOOP

Find the loop

Write a function that finds the loop in a linked list.

* Prototype: `listint_t *find_listint_loop(listint_t *head);`
* Returns: The address of the node where the loop starts, or NULL if there is no loop
* You are not allowed to use malloc, free or arrays
* You can only declare a maximum of two variables in your function

**Please use this lists.h:**

```c
#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

#endif
```

---

```bash

alexa@ubuntu:~/find_the_loop$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c -L. -lloop -o main
alexa@ubuntu:~/find_the_loop$ ./main
[0x13700f0] 1024
[0x13700d0] 402
[0x13700b0] 98
[0x1370090] 4
[0x1370070] 3
[0x1370050] 2
[0x1370030] 1
[0x1370010] 0
[0x1370560] 1024
[0x1370540] 402
[0x1370010] 98
[0x1370030] 7
[0x1370050] 6
[0x1370070] 5
[0x1370090] 4
[0x13700b0] 3
[0x13700d0] 2
[0x13700f0] 1
[0x1370110] 0
-> [0x1370030] 7
Loop starts at [0x1370030] 7
alexa@ubuntu:~/find_the_loop$ 
```
