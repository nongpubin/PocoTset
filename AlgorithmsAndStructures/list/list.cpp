/*
 * @Author: your name
 * @Date: 2021-03-13 23:17:24
 * @LastEditTime: 2021-04-05 11:46:43
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
    if(current == NULL) {
        printf("insert end is NULL \r\n");
    }
    while (current->next != NULL) {
        current = current->next;
    }
    
    new_node = (list_node *)malloc(sizeof(list_node));
    new_node->next = NULL;
    new_node->value = data;
    current->next = new_node;
}

void delete_data(list_node **node, int data) 
{
    list_node *prev = NULL;
    list_node *current = *node;
    if(current == NULL) {
        printf("list node is null , do nothing \r\n");
        return;
    } 
    
    if(current->value == data) {
        *node = current->next;
        printf("found data %d, delete it \r\n", current->value);
        free(current);	
        return;
    }

    while (NULL != current->next)	{
        prev = current;					// 在p走向下一个节点前先将其保存
		current = current->next;			// 走到下一个节点，也就是循环增量
		// 判断这个节点是不是我们要找的那个节点
		if (current->value == data)
        {
			if (NULL == current->next)
			{
				// 尾节点
				prev->next = NULL;		// 原来尾节点的前一个节点变成新尾节点
                printf("found data %d, delete it \r\n", current->value);
				free(current);					// 释放原来的尾节点的内存
			}
			else
			{
				// 普通节点
				prev->next = current->next;	// 要删除的节点的前一个节点和它的后一个节点相连，这样就把要删除的节点给摘出来了
                printf("found data %d, delete it \r\n", current->value);
				free(current);
			}
            return;
		}
        printf("found data %d,   \r\n", current->value);
       	
    }
    
}

void delete_all(list_node *node)
{
    if(node == NULL) {
        printf("node is NULL, do nothing .\r\n");
        return ;
    }
    list_node *after = node;
    while (after->next != NULL) {
        after = node->next;
        free(node);
    }
    printf("free done .\r\n");    
}

//遍历输出节点数据
void show_data(list_node *node)
{
    list_node *current = node;
    if(current == NULL) {
        printf("current is NULL \r\n");
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
    insert_end(test, 123);
    show_data(test);
    delete_data(&test, 123);
    
    show_data(test);
    // delete_all(test);
    
    return 0;
}