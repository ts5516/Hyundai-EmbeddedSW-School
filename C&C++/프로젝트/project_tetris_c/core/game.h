#ifndef __GAME_H__
#define __GAME_H__

#include "common.h" // ���������� ���Ǵ� C ǥ�� ��� ����(stdio.h, stdint.h ��)�� �ҷ�����. OS �������̴�.

#include "../config.h"  // ���� ������ �� ��ܿ��� �ҷ��;� �Ѵ�. MCU���� PC������ �˾Ƴ��� �ϱ� ������
#include <conio.h> // Windows��� �� ��������� �ҷ��´�.
#include <windows.h>

#include "sound_driver.h"  // (H/W �� OS ��������) driver ���� ��������� �ҷ��´�.
#include "console_driver.h"
#include "key_driver.h"

#include "point.h" // ���� ���� ��� ������ �ҷ��´�
#include "colors.h"
//#include "core/images.h" 
#include "blocks.h"
#include "board.h"
#include "stage_info.h"
#include "game_info.h"
#include "game_fsm.h"

#define TASK_MOVE_INTERVAL (DEFAULT_DROP_SPEED-500)
#define TASK_TEST_INTERVAL 10

bool task_move_flag; // ���� �̵� �÷���
bool task_lock_flag; // ����׿� �÷���

typedef struct {
    windows_console_t console;
    block_t first_block;
	block_t second_block;
    uint16_t key_code;
} Game;

void timer_polling();
void init_game(Game* game);
void update_game(Game* game);
void end_game(Game* game);

#endif
