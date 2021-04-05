/*
 * @Author: your name
 * @Date: 2021-04-05 21:54:16
 * @LastEditTime: 2021-04-05 23:21:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\AlgorithmsAndStructures\list\double.cpp
 */
#include <iostream>
#include "stdio.h"
#include "assert.h"

struct list_node
{
    int data;
    struct list_node *prev;
    struct list_node *next;
};

void init_list(list_node **node, int data)
{
    struct list_node *current = *node;
    current = (struct list_node*)malloc(sizeof(struct list_node));
    if (NULL == *node) {
		printf("init node .\r\n");
        *node = current;
	}
    current->data = data;
    current->next = NULL;
    current->prev = NULL;
}

void insert_end(list_node *node, int data)
{
    struct list_node *current = node;    
    struct list_node *prev = NULL;
    while (current->next != NULL) {
        current = current->next;
    }
    prev = current;
    current = (struct list_node*)malloc(sizeof(struct list_node));
    prev->next = current;
    current->prev = prev;
    current->next = NULL;
    current->data = data;
}

void show_list(list_node *node)
{
    struct list_node *current = node;
    do {   
        printf("list data %d \r\n", current->data);    
        current = current->next;
    } while (current != NULL);
}

int main()
{
    struct list_node *mylist = NULL;
    init_list(&mylist, 18);
    insert_end(mylist, 28);
    show_list(mylist);
 
    return 0;
}

