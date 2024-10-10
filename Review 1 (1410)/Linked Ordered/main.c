#include "linkedordered.c"

int main()
{
    t_list *list = createList();

    printList(list);
    append(list, 13);
    append(list, 7);
    append(list, 8);
    printList(list);
    return 0;
}
