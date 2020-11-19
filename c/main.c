#include<stdio.h>
#include<stdlib.h>

struct link
{
    short data;
    struct link* pre;
    struct link* next;
    struct link* last;
}link_hand;
void append(struct link* this_link)
{
    if (link_hand.last == NULL)
    {
        link_hand.last = this_link;
        link_hand.next = this_link;
        this_link->next = NULL;
        this_link->pre = &link_hand;
        return;
    } else
    {
        this_link->pre = link_hand.last;
        this_link->next = NULL;
        link_hand.last->next = this_link;
        link_hand.last = this_link;
        
        return;
    }


}
int main()
{
    struct link a;
    a.data = 1;
    append(&a);
    
    
    struct link b;
    b.data = 2;
    append(&b);
    
    
    struct link c;
    c.data = 3;
    append(&c);
    
    
    struct link d;
    d.data = 4;
    append(&d);
    
    
    struct link e;
    e.data = 8;
    append(&e);
    struct link* temp = link_hand.next;
    while (1)
    {
        if (temp == NULL)
        {
            break;
        }
        printf("[%d]\n", temp->data);
        temp = temp->next;

    }




    return 0;
}