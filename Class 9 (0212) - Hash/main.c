#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int item;
    struct _node *next;
} t_node;

typedef struct {
    t_node *head;
    t_node *tail;
    int size;
} t_list;

t_list *create_list() {
    t_list *list = (t_list *)malloc(sizeof(t_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int is_empty(t_list *list) {
    return list->size == 0;
}

void append(t_list *list, int item) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    node->item = item;
    node->next = NULL;

    if (is_empty(list)) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
    list->size++;
}

void print_list(t_list *list) {
    t_node *node_aux = list->head;
    while (node_aux != NULL) {
        printf("%d ", node_aux->item);
        node_aux = node_aux->next;
    }
    printf("\n");
}

t_node *search(t_list *list, int item) {
    t_node *node_aux = list->head;
    while (node_aux != NULL) {
        if (node_aux->item == item) {
            return node_aux;
        }
        node_aux = node_aux->next;
    }
    return NULL;
}

void delete(t_list *list, t_node *node_to_be_removed) {
    if (node_to_be_removed == list->head) {
        list->head = node_to_be_removed->next;
        if (list->tail == node_to_be_removed) {
            list->tail = NULL;
        }
        free(node_to_be_removed);
        list->size--;
        return;
    }

    t_node *node_predecessor = list->head;
    while (node_predecessor->next != node_to_be_removed) {
        node_predecessor = node_predecessor->next;
    }

    if (node_to_be_removed == list->tail) {
        list->tail = node_predecessor;
        node_predecessor->next = NULL;
        free(node_to_be_removed);
        list->size--;
    } else {
        node_predecessor->next = node_to_be_removed->next;
        free(node_to_be_removed);
        list->size--;
    }
}

// ========================================================

int hash_function(int key, int size) {
    return (key * 31) % size;
}

typedef struct {
    t_list **buckets;
    int size;
} t_hash_table;

t_hash_table *create_hash_table(int size) {
    t_hash_table *table = (t_hash_table *)malloc(sizeof(t_hash_table));
    table->size = size;
    table->buckets = (t_list **)malloc(size * sizeof(t_list *));
    for (int i = 0; i < size; i++) {
        table->buckets[i] = create_list();
    }
    return table;
}

void insert(t_hash_table *table, int key) {
    int index = hash_function(key, table->size);
    append(table->buckets[index], key);
    printf("Inserido: %d na posicao %d\n", key, index);
}

void remove_key(t_hash_table *table, int key) {
    int index = hash_function(key, table->size);
    t_node *node = search(table->buckets[index], key);
    if (node != NULL) {
        delete(table->buckets[index], node);
        printf("Removido: %d da posicao %d\n", key, index);
    } else {
        printf("Chave %d nao encontrada\n", key);
    }
}

void print_hash_table(t_hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        printf("Bucket %d: ", i);
        print_list(table->buckets[i]);
    }
}

void free_hash_table(t_hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->buckets[i]);
    }
    free(table->buckets);
    free(table);
}

int main() {
    t_hash_table *table = create_hash_table(10);

    insert(table, 10);
    insert(table, 15);
    insert(table, 20);
    insert(table, 25);
    insert(table, 30);
    insert(table, 40);
    insert(table, 50);
    insert(table, 35);
    insert(table, 60);
    insert(table, 45);

    printf("Tabela Hash antes das remocoes:\n");
    print_hash_table(table);

    remove_key(table, 15);
    remove_key(table, 40);

    printf("\nTabela Hash apos remocoes:\n");
    print_hash_table(table);

    free_hash_table(table);
    return 0;
}
