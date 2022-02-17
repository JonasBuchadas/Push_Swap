#include "push_swap.h"

static void moves_to_min(t_dlist *b, t_i *inf_b);
static void moves_to_max(t_dlist *b, t_i *inf_b);

void check_b(t_dlist *b, t_i *inf_b)
{
    moves_to_min(b, inf_b);
    moves_to_max(b, inf_b);
}
static void moves_to_min(t_dlist *b, t_i *inf_b)
{
    int     r;
    t_dlist *temp;

    if (!b)
        return ;
    r = 0;
    temp = b;
    while (*(int *)temp->content != inf_b->min)
    {
        temp = temp->next;
        r++;
    }
    inf_b->min_rot = r;
    r = 0;
    temp = b;
    while (*(int *)temp->content != inf_b->min)
	{
		temp = temp->prev;
		r++;
	}
	inf_b->min_rrot = r;
}

static void moves_to_max(t_dlist *b, t_i *inf_b)
{
    int     r;
    t_dlist *temp;

    if (!b)
        return ;
    r = 0;
    temp = b;
    while (*(int *)temp->content != inf_b->max)
    {
        temp = temp->next;
        r++;
    }
    inf_b->max_rot = r;
    r = 0;
    temp = b;
    while (*(int *)temp->content != inf_b->max)
	{
		temp = temp->prev;
		r++;
	}
	inf_b->max_rrot = r;
}
