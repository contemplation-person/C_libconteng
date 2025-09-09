#pragma once
#ifndef CONTENG_H
#define CONTENG_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>


#if (defined(__GNUC__) && (__GNUC__ > 2)) || defined(__clang__)

#define let(name, init) __typeof__(init) name = init
#define SWAP(a, b)             \
    do {                       \
        __typeof__(a) _temp = (a); \
        (a) = (b);             \
        (b) = _temp;           \
    } while (0)

#endif


#if ((defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7))) || (defined(__clang__) && (__clang_major__ > 3 || (__clang_major__ == 3 && __clang_minor__ >= 6))) )

#define smart_ptr(ptr) void* ptr __attribute__((cleanup(cleanup_free)))
#define new_mem(size) malloc(size)
#define new_str(str) strdup(str)

static inline void cleanup_free(void *p) {
    free(*(void**)p);
}

#endif

#endif
