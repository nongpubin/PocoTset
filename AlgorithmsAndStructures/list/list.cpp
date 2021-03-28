/*
 * @Author: your name
 * @Date: 2021-03-13 23:17:24
 * @LastEditTime: 2021-03-28 12:05:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \npb\AlgorithmsAndStructures\list.cpp
 */

#include <iostream>
#include "stdio.h"
#include "assert.h"


typedef struct node
{
    int value;
    struct node *next;
}list_node;

void show_data(list_node *node);

void create_list(list_node **node)
{
    int value;
    list_node *current;
    list_node *prev;
    printf("please input you want : \r\n");
    while (scanf("%d", &value)==1) 
    {
        while(getchar() != '\n')
			continue;
        printf("malloc new size \r\n");
        current = (list_node *)malloc(sizeof(list_node));
        if(*node == NULL) {
            printf("fisrt node \r\n");
            *node = current;
        } else {
            prev->next = current;
        }
        current->next = NULL;
		current->value = value;
		puts("Enter the next value(q to end):");
		prev = current;
    }
}


void insert_end(list_node *node, int data)
{
    list_node *current = node;
    list_node *prve = NULL;
    assert(current != NULL);

    list_node tmp;
    tmp.next = NULL;
    tmp.value = data;

    while (current->next != NULL) {
        prve = current;
        current = current->next;
    }
    current->next = &tmp;
    prve->value = data;
}

// void insert_head(list_node *node, int data)
// {
//     list_node *current = node;

// }

//遍历输出节点数据
void show_data(list_node *node)
{
    list_node *current = node;
    if(current == NULL) {
        printf("XXXXXXXXX NULL \r\n");
    }
    while(current != NULL) {
        printf("list data : %d \r\n", current->value);
        current = current->next;
    }
}


int main() {
    list_node *test = NULL;
    create_list(&test);
    show_data(test);
    
    return 0;
}