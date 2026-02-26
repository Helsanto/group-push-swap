#include <stdlib.h>
#include <stdio.h>


/* ------------------------------
** TEST PART - TO REMOVE
** ------------------------------ */

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

t_node *new_node(int value)
{
    t_node *n = malloc(sizeof(t_node));
    n->value = value;
    n->index = -1;
    n->next = NULL;
    return n;
}

void push_front(t_node **a, int value)
{
    t_node *n = new_node(value);
    n->next = *a;
    *a = n;
}

void print_stack(t_node *a)
{
    while (a)
    {
        printf("value=%d  index=%d\n", a->value, a->index);
        a = a->next;
    }
}

/* ------------------------------
** END OF TEST PART - TO REMOVE
** ------------------------------ */

/*
** Node structure for stack
** value  -> original integer value
** index  -> normalized rank (0 to n-1)
*/

/* ------------------------------
** TEST PART - TO ADD AFTER TEST
** ------------------------------ */

/*typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;
*/
/* ------------------------------
** END OFTEST PART - TO ADD AFTER TEST
** ------------------------------ */
/*
** Copies all stack values into a dynamically allocated array.
** Returns NULL if malloc fails.
*/
int *stack_to_array(t_node *a, int size)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (a && i < size)
    {
        arr[i++] = a->value;
        a = a->next;
    }
    return (arr);
}

/*
** Simple bubble sort (O(n²)).
** Suitable for push_swap since n is limited (max 500).
*/
void bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

/*
** Finds the position (rank) of value inside sorted array.
** Returns index if found.
** Returns -1 if not found (should never happen if no duplicates).
*/
int find_index(int *sorted, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (sorted[i] == value)
            return (i);
        i++;
    }
    return (-1);
}

/*
** Assigns normalized index to each node in the stack.
** Each node gets its rank in the sorted array.
*/
void assign_indexes(t_node *a, int *sorted, int size)
{
    int idx;

    while (a)
    {
        idx = find_index(sorted, size, a->value);
        a->index = idx;
        a = a->next;
    }
}

/*
** Main normalization function.
**
** Steps:
** 1. Copy stack values into array
** 2. Sort the array
** 3. Assign index (rank) to each node
** 4. Free temporary array
*/
void normalize_stack(t_node *a, int size)
{
    int *arr;

    if (!a || size <= 0)
        return ;
    arr = stack_to_array(a, size);
    if (!arr)
        return ;
    bubble_sort(arr, size);
    assign_indexes(a, arr, size);
    free(arr);
}


/* ------------------------------
** TESTS - REMOVE 
** ------------------------------ */

void test_case(int *values, int size)
{
    t_node *a = NULL;

    for (int i = 0; i < size; i++)
        push_front(&a, values[i]);

    printf("\n=== TEST: ");
    for (int i = 0; i < size; i++)
        printf("%d ", values[i]);
    printf("===\n");

    normalize_stack(a, size);
    print_stack(a);
}

int main(void)
{
    int t1[] = {40, 10, 30, 20};
    int t2[] = {5, -10, 0, 100};
    int t3[] = {3, 2, 1};
    int t4[] = {500, 1, 250, 999, -42};

    test_case(t1, 4);
    test_case(t2, 4);
    test_case(t3, 3);
    test_case(t4, 5);

    return 0;
}

/* ------------------------------
** END OF TESTS - REMOVE 
** ------------------------------ */