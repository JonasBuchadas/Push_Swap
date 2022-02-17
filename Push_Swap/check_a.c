#include "push_swap.h"

static void moves_to_min(t_dlist *a, t_i *inf_a);
static void moves_to_max(t_dlist *a, t_i *inf_a);

void check_a(t_dlist *a, t_i *inf_a)
{
    moves_to_min(a, inf_a);
    moves_to_max(a, inf_a);
}
static void moves_to_min(t_dlist *a, t_i *inf_a)
{
    int     r;
    t_dlist *temp;

    if (!a)
        return ;
    r = 0;
    temp = a;
    while (*(int *)temp->content != inf_a->min)
    {
        temp = temp->next;
        r++;
    }
    inf_a->min_rot = r;
    r = 0;
    temp = a;
    while (*(int *)temp->content != inf_a->min)
	{
		temp = temp->prev;
		r++;
	}
	inf_a->min_rrot = r;
}

static void moves_to_max(t_dlist *a, t_i *inf_a)
{
    int     r;
    t_dlist *temp;

    if (!a)
        return ;
    r = 0;
    temp = a;
    while (*(int *)temp->content != inf_a->max)
    {
        temp = temp->next;
        r++;
    }
    inf_a->max_rot = r;
    r = 0;
    temp = a;
    while (*(int *)temp->content != inf_a->max)
	{
		temp = temp->prev;
		r++;
	}
	inf_a->max_rrot = r;
}