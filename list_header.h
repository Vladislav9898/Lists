#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _list {
    int value;
    struct _list *next;
    struct _list *prev; 
} lst;

typedef struct _header {
    size_t size;
    lst *head;
    lst *tail;
} header;

int line_search(header *list, int value);
int push_front(header *list, int value);
int push_back(header *list, int value);
int print_list(char *str, header *list);
int delete_list(header **list);
int delete_elem(header *list, int value);
int half_delete_list(header *list);
int pop_back(header *list);
int pop_front(header *list);