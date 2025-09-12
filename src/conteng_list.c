/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conteng_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HaJuYoung(juha) <contemplation.person@gmai +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:15:01 by HaJuYoung(juha)   #+#    #+#             */
/*   Updated: 2025/09/12 17:12:06 by HaJuYoung(juha)  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conteng_list.h"

Conteng_list* new_conteng_list() {
    Conteng_list *list = new_mem(CONTENG_LIST_DEFAULT_CAPACITY);

    if (!list) {
        perror("Failed to allocate memory for list");
        return NULL;
    }
    list->used_capacity = sizeof(Conteng_list);
    list->max_capacity = 512;
    list->node_count = 0;
    list->head = NULL;
    list->tail = NULL;

    list->free_space_head = list + sizeof(Conteng_list);
    list->free_space_head->next = NULL;
    list->free_space_head->capacity = 512 - sizeof(Conteng_list);

    return list;
}

Conteng_bool create_conteng_node(Conteng_list *list, const char *data) {
    Conteng_free_space *free_space = NULL;
    Conteng_free_space *prev_free_prev = NULL;
    Conteng_node *new_node = NULL;
    ssize_t free_space_capacity = 0;
    ssize_t node_size = 0;
    size_t data_size = 0;

    if(!list || !data) {
        fprintf(stderr, "Invalid argument(s) to create_conteng_node\n");
        return CONTENG_FALSE;
    }

    data_size = strlen(data);
    node_size = CONTENG_NODE_SIZE(data_size);
    free_space = list->free_space_head;

    while (free_space) {
        if (free_space->capacity > CONTENG_LIST_MINIMUM_LOCATE_SIZE(data_size)) {
            new_node = free_space;
            free_space = free_space + node_size;
            free_space_capacity = free_space->capacity - node_size;
            new_node->next = NULL;
            new_node->data_size = data_size;
            memcpy(new_node->data, data, data_size);

            
            // TODO: 여유 공간 위치 조정, 여유공간 크기 조정
            // TODO: 노드 할당 및 노드 데이터 복사


            list->free_space_head = free_space + sizeof(Conteng_node) + sizeof(data);
            free_space = free_space + sizeof(Conteng_free_space);

        }
        prev_free_prev = free_space;
        free_space = free_space->next;
    }

    return CONTENG_TRUE;
}