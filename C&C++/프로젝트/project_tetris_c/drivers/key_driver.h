#ifndef __KEY_DRIVER_H__
#define __KEY_DRIVER_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "key_config.h"
#include "key_code.h"

typedef union _key_t {
    uint16_t all;
    struct {
        uint8_t upper;
        uint8_t lower;
    } bound;
} key_t;

// qqq(1)
// �Լ� �̸��� read_key > key_read�� �ٲ�
void key_init();
//uint16_t read_key();
uint16_t get_key_code();
//void print_key(uint16_t key_val);
void key_print(uint16_t key_val);
//void key_write(); // �Է���ġ�̱� ������ write�� �ʿ����.

uint16_t key_read();

#endif
