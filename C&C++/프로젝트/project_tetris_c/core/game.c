#include "game.h"

uint32_t tick_1ms = 0;

void timer_polling() {
    tick_1ms++;

    if (tick_1ms % TASK_MOVE_INTERVAL == 0) { task_move_flag = true; }
    if (tick_1ms % TASK_TEST_INTERVAL == 0) { task_lock_flag = true; }
    delay_ms(1); // 정확하게 1ms 가 되지는 않지만, 그렇다고 오차가 매우 심한것은 아니라서 적당히 쓸만하다.
}

void init_game(Game* game) {
    show_game_intro(&game->console);

    //static uint32_t dummy_move_cnt = 0; // 디버그용: 스케줄링 시간을 출력하기 위한 용도
    //static uint32_t dummy_test_cnt = 0;
    //printf("Game Started...\r\n");

    // 사운드 초기화 및 플레이
    const char* file_path = "rsc/sounds/sample1.wav";
    play_sound(file_path);
    //stop_sound(); // 개발할때는 정신없으니 음악을 꺼놓자.

    // 미구현
    // show_game_demo(&console); // 데모를 보여주면서 동전 입력을 기다리자.

    // 디스플레이(=윈도우 콘솔창) 초기화

    init_window_console(&game->console);
    show_key_usage(&game->console); // 키 입력 정보를 보여준다.    

    // 보드 초기화   
    init_board(cell_att_arr); // 보드 데이터(=벽 정보, 셀 정보 등)를 인자로받아서 보드를 초기화 한다.

    // 디버그용: 함수가 잘 동작하나 테스트 용
    //clear_line_on_board(gboard);
    // 미구현 혹은 덜 구현된 함수 모음
    // draw_next_block(next_block); // 다음 블럭을 보여주기
    //draw_box(25, 20, 20, 6, "Hello, World !!");

    // 디버깅용 테스트용 블럭 설정
    // 개발시 테스트 하기 위한 용도
    // 내가 원하는 특정 블럭(예를 들면 I) 및 좌표 설정을 하기 위한 용도
    // 
    //block_t test_block;
    //#define TEST_BLOCK_SHAPE SHAPE_I
    //#define BLOCK_TEST_POS_X 5
    //#define BLOCK_TEST_POS_Y 0
    //
    //init_block(&test_block, TEST_BLOCK_SHAPE, BLOCK_TEST_POS_X, BLOCK_TEST_POS_Y);
    //rotate_block(&test_block);
    //print_block_info(&test_block, true);
    //insert_block_to_board(gboard, &random_block, BLOCK_TEST_POS_X, BLOCK_TEST_POS_Y); // aaa insert 함수안에 update가 있다. 제거하자. bbb 제거했다.


    create_and_draw_custom_board(&game->console, hold_block_board, 17, 17);

    create_random_block(&game->first_block);
    init_block(&game->first_block, game->first_block.shape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
    insert_block_to_board(gboard, &game->first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);

    create_random_block(&game->second_block);
    init_custom_board(hold_block_board, 17, 17); // ��ġ���� �°� �ʱ�ȭ
    insert_block_to_custom_board(hold_block_board, &game->second_block, 1, 1); // ���� ����
    draw_custom_board_from_data(&game->console, hold_block_board);

    key_init();
}

void update_game(Game* game) {
    timer_polling();

    // 키 입력이 있는 경우에만 블럭을 이동시켜야 한다.
    // 이전 코드는 이렇게 짰었는데, key_code값을 계속 읽기때문에 아래 코드가 오동작할수 있다.
    //key_code = get_key_code();
    //move_block_by_key_input(gboard, &test_block, key_code);
    //update_board(&console, gboard);

    if (_kbhit()) { // 키 입력이 있는 경우에만 블럭을 이동시켜야 한다.
        game->key_code = get_key_code();

        update_board_by_key_input(&game->console, gboard, &game->first_block, game->key_code);

    }

    // 참고: 이렇게 코딩할경우 블럭이 GAME_SPEED 만큼 내려오는건 맞지만, 키 입력이 GAME_SPEED 만큼 늦게 입력 받아진다.
    // Sleep(GAME_SPEED); 
    // move_block_by_key_input(&console, gboard, &test_block, KEY_DOWN);
    // 즉 이렇게 하면 안된다는 거지
    // 블럭은 1초간격으로 내려오지만, 키입력을 누를때마다 빠르게 받을수 있어야 한다.        

    if (task_move_flag) {
        task_move_flag = false;
        //printf("[%d] Move !!\r\n", ++dummy_move_cnt);
        move_block_by_key_input(&game->console, gboard, &game->first_block, KEY_DOWN);
        update_board(&game->console, gboard);
    }

    //if (task_lock_flag) {
    //    task_lock_flag = false;
    //    printf("[%d] Test !!\r\n", ++dummy_test_cnt);
    //    void lock_block_after_delay(cell_t board[BOARD_HEIGHT][BOARD_WIDTH], block_t * block) {
    //    lock_block_after_delay(gboard, &test_block);
    //}

    if (block_collision) {
        block_collision = false;
        lock_block_after_delay(gboard, &game->first_block);
        update_board_with_line_clear(&game->console, gboard);
        init_block(&game->second_block, game->second_block.shape, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
        game->first_block = game->second_block;
        create_random_block(&game->second_block);
        insert_block_to_custom_board(hold_block_board, &game->second_block, 1, 1);
        draw_custom_board_from_data(&game->console, hold_block_board);
        insert_block_to_board(gboard, &game->first_block, BLOCK_START_POS_X_ON_BOARD, BLOCK_START_POS_Y_ON_BOARD);
    }
}

void end_game(Game* game) {
	// 게임 종료시 처리할 내용을 여기에 작성한다.
	// 예를 들면, 게임 오버시 사운드 재생하기
    
    // 게임 종료시 사운드 중지
    stop_sound();

    init_window_console(&game->console);
    console_set_fore_color(&game->console, WHITE);
    show_game_over(&game->console);
}