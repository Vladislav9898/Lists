#include "list_header.h"

header* create_header() {
    header *tmp = (header*) malloc(sizeof(header));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

lst* tmp_init(){
    lst *tmp = (lst*) malloc(sizeof(lst));
    return tmp;
}

int line_search(header *list, int value){
    if(!list){
        return -1;
    }
    int pos = 0;

    lst *tmp = list->head;
    while(tmp){
        if(value == tmp->value){
            return pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return -2;
}

int push_front(header *list, int value) {
    if(!list){
        return 1;
    }
    lst *tmp = tmp_init();
    tmp->value = value;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
    return 0;
}

int push_back(header *list, int value) {
    if(!list){
        return 1;
    }
    lst *tmp = tmp_init();
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
    return 0;

}

int print_list(char *str, header *list) {
    if(!list || str == 0){
        return 1;
    }
    lst *tmp = list->head;
    printf("%s", str);
    while (tmp) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    return 0;
}

int delete_elem(header *list, int value) {
    if(!list){
        return 1;
    }

    lst *current_list_item = list->head;
    while (current_list_item) {
        lst *tmp = current_list_item;
        current_list_item = current_list_item->next;
        if(value == tmp->value){
            if (tmp->prev) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
            if (!tmp->prev) {
                list->head = tmp->next;
            }
            if (!tmp->next) {
                list->tail = tmp->prev;
            }
            free(tmp);
            list->size--;
        }
    }
    return 0;
}

int delete_list(header **list) {
    if(!(*list)){
        return 1;
    }
    lst *tmp = (*list)->head;
    lst *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
    return 0;
}

int half_delete_list(header *list) {
    if(!list){
        return 1;
    }
    int i = 0;
    lst *current_list_item = list->head;
    while (current_list_item) {
        lst *tmp = current_list_item;
        current_list_item = current_list_item->next;
        if(i % 2 == 0){
            if (tmp->prev) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
            if (!tmp->prev) {
                list->head = tmp->next;
            }
            if (!tmp->next) {
                list->tail = tmp->prev;
            }
            free(tmp);
            list->size--;
        }
        i++;
    }
    return 0;
}

int pop_back(header *list) {
    if(!list || list->tail == NULL) {
        return 1;
    }
    lst *next = NULL;
    int tmp = 0;
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
 
    list->size--;
    return 0;
}

int pop_front(header *list) {
    if(!list || list->head == NULL) {
        return 1;
    }
    lst *prev = NULL;
    int tmp = 0;
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);
 
    list->size--;
    return 0;
}
