/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conteng_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HaJuYoung(juha) <contemplation.person@gmai +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:14:53 by HaJuYoung(juha)   #+#    #+#             */
/*   Updated: 2025/09/12 16:45:24 by HaJuYoung(juha)  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTENG_LIST_H
#define CONTENG_LIST_H

#include "conteng_common.h"
#include "conteng_list_inline.h"

typedef struct s_conteng_node {
    struct s_conteng_node *next;
    struct s_conteng_node *prev;
    ssize_t data_size;
    void *data;
} Conteng_node;

typedef struct s_conteng_free_node {
    struct free_node *next;
    ssize_t capacity;
} Conteng_free_space;

typedef struct s_conteng_list {
    ssize_t used_capacity;
    ssize_t max_capacity;
    ssize_t node_count;

    Conteng_free_space *free_space_head;

    Conteng_node *head;
    Conteng_node *tail;
} Conteng_list;

#define CONTENG_LIST_DEFAULT_CAPACITY 512
#define CONTENG_LIST_EXPAND_RATE 2
#define CONTENG_NODE_SIZE(data_size) (sizeof(Conteng_node) + data_size)
#define CONTENG_LIST_MINIMUM_LOCATE_SIZE(data_size) (CONTENG_NODE_SIZE(data_size) + sizeof(Conteng_free_space))
#endif