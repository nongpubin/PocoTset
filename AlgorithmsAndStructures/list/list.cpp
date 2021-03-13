/*
 * @Author: your name
 * @Date: 2021-03-13 23:17:24
 * @LastEditTime: 2021-03-13 23:42:45
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


//遍历输出节点数据
void show_data(list_node *node)
{
    list_node *current = node;
    assert(current != NULL);
    while(current != NULL) {
        printf("lsit date : %d \r\n", current->value);
        current = current->next;
    }
}


int main() {
    list_node test;
    test.next = NULL;
    test.value = 2058;
    show_data(&test);
    
    return 0;
}