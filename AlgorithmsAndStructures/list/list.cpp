/*
 * @Author: your name
 * @Date: 2021-03-13 23:17:24
 * @LastEditTime: 2021-03-28 12:34:43
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
    list_node *new_node = NULL;
    assert(current != NULL);

    new_node = (list_node *)malloc(sizeof(list_node));
    new_node->next = NULL;
    new_node->value = data;
    current->next = new_node;
}

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
    insert_end(test, 888);
    show_data(test);
    
    return 0;
}