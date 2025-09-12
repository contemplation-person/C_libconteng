/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HaJuYoung(juha) <jy.h4456@arielnetworks.co +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:15:04 by HaJuYoung(juha)   #+#    #+#             */
/*   Updated: 2025/09/12 12:15:05 by HaJuYoung(juha)  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conteng.h"

typedef struct s_TestStruct {
    int a;
    char* b;
    struct s_TestStruct* next;
} TestStruct;

void test_func() {
    // test: smart_ptr, new_mem, new_str
    smart_ptr(str) = new_str("smart pointer");
    smart_ptr(mem) = new_mem(1024);
    smart_ptr(ts) = new_mem(sizeof(TestStruct));
    TestStruct* test = ts;
    free(str);
    str = NULL;
    test->a = 1;
}

int main() {
    smart_ptr(name) = new_mem(10 * sizeof(int));
    free(name);
    name = NULL;
}
