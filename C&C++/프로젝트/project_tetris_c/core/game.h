#ifndef __GAME_H__
#define __GAME_H__

#include "common.h" // 공통적으로 사용되는 C 표준 헤더 파일(stdio.h, stdint.h 등)을 불러오자. OS 독립적이다.

#include "../config.h"  // 설정 파일은 최 상단에서 불러와야 한다. MCU인지 PC인지를 알아내야 하기 때문에
#include <conio.h> // Windows라면 이 헤더파일을 불러온다.
#include <windows.h>

#include "sound_driver.h"  // (H/W 및 OS 종속적인) driver 관련 헤더파일을 불러온다.
#include "console_driver.h"
#include "key_driver.h"

#include "point.h" // 게임 관련 헤더 파일을 불러온다
#include "colors.h"
//#include "core/images.h" 
#include "blocks.h"
#include "board.h"
#include "stage_info.h"
#include "game_info.h"
#include "game_fsm.h"

#define TASK_MOVE_INTERVAL (DEFAULT_DROP_SPEED-500)
#define TASK_TEST_INTERVAL 10

bool task_move_flag; // 블럭의 이동 플래그
bool task_lock_flag; // 디버그용 플래그

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
