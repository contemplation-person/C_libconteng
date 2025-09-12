/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conteng_common.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HaJuYoung(juha) <contemplation.person@gmai +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:14:51 by HaJuYoung(juha)   #+#    #+#             */
/*   Updated: 2025/09/12 14:44:03 by HaJuYoung(juha)  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTENG_H
#define CONTENG_H

/**
 * gcc version >= 4.7 or clang version >= 3.6
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>


#if (defined(__GNUC__) && (__GNUC__ > 2)) || defined(__clang__)

/**
 * @brief don't use  in a loop, because it declares a new variable each time.
 * Cannot create arrays. Dynamic or variable-length arrays are not supported.
 */
#define let(name, init) __typeof__(init) name = init
#define SWAP(a, b)             \
    do {                       \
        __typeof__(a) _temp = (a); \
        (a) = (b);             \
        (b) = _temp;           \
    } while (0)

#endif


#if ((defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7))) || (defined(__clang__) && (__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ >= 6))) )

static inline void cleanup_free(void *p) {
    free(*(void**)p);
}

/**
 * @brief A  declared with  will be automatically freed when the function ends, so returning it leads to a use-after-free bug. To safely return a pointer, declare it without the cleanup attribute.
 */
#define smart_ptr(ptr) void* ptr __attribute__((cleanup(cleanup_free)))
#define new_mem(size) malloc(size)
#define new_str(str) strdup(str)

#endif

#define FLF __FILE__, __LINE__, __func__

typedef enum e_conteng_bool {
    CONTENG_FALSE = 0,
    CONTENG_TRUE = 1
} Conteng_bool;

#endif
