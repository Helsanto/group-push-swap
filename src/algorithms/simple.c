#include "push_swap.h"

// Find the position in A where the element should be inserted
int find_insert_position(t_stack *a, int index)
{
    t_node *cur = a->top;
    int pos = 0;

    while (cur)
    {
        if (index < cur->index)
            return pos;
        pos++;
        cur = cur->next;
    }
    return pos; // element belongs at the end
}

// Rotate A so that the target position becomes the top
void rotate_a_to_pos(t_stack *a, int pos)
{
    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < a->size)
            rra(a);
}

// Find the position of the smallest element in A
int find_min_position(t_stack *a)
{
    t_node *cur = a->top;
    int pos = 0;
    int best_pos = 0;
    int min = cur->index;

    while (cur)
    {
        if (cur->index < min)
        {
            min = cur->index;
            best_pos = pos;
        }
        pos++;
        cur = cur->next;
    }
    return best_pos;
}

// Rotate A so that the smallest element becomes the top
void rotate_min_to_top(t_stack *a)
{
    int pos = find_min_position(a);

    if (pos <= a->size / 2)
        while (pos-- > 0)
            ra(a);
    else
        while (pos++ < a->size)
            rra(a);
}

// Main insertion-sort-based simple algorithm (O(n²))
void simple_sort(t_stack *a, t_stack *b)
{
    int pos;

    // 1. Move all elements from A to B
    while (a->size > 0)
        pb(a, b);

    // 2. Insert elements back into A in sorted order
    while (b->size > 0)
    {
        int index = b->top->index;

        // Find correct insertion position
        pos = find_insert_position(a, index);

        // Rotate A to bring that position to the top
        rotate_a_to_pos(a, pos);

        // Push element from B to A
        pa(a, b);
    }

    // 3. Rotate A so that the smallest element is at the top
    rotate_min_to_top(a);
}
