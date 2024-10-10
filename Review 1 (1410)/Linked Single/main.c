#include "linkedsingle.c"

int main()
{
    t_list *list = createList();

    printList(list);
    append(list, 2);
    append(list, 5);
    append(list, 13);
    printList(list);

    del(list, 2);
    printList(list);

    append(list, 25);
    printList(list);

    del(list, 25);
    del(list, 5);
    del(list, 13);
    del(list, 2984295);
    printList(list);
    return 0;
}
