#include "game_info.h"

void show_key_usage(windows_console_t* console) {

    // debug
    // 지워도 무방하지만 종종 테스트 및 좌표 계산때문에 필요하다.
    // 최종 릴리즈에서 지워도 된다. 보기 불편해서 주석처리했다.
    cell_test(console);


    display_text(console, "Stage: 1", 25, 4); // 현재 스테이지

    display_text(console, "Target Lines: 9", 25, 6); // 없애야할 목표 라인수
    display_text(console, "Cleard Lines: 1", 25, 7); // 자네가 깬 라인수

    display_text(console, "Difficulty: Easy", 25, 9); // 현재 레벨

    display_text(console, "Difficulty: Easy", 25, 9); // 현재 레벨
    display_text(console, "Highest Cleard Line : 123 (Medium)", 25, 10);
    //▲▼◀▶
    display_text(console, "▲", 26, 13); display_text(console, "ㆍUp: Rotate", 30, 13);
    display_text(console, "◀", 25, 14); display_text(console, "ㆍLeft: Left Move", 30, 14);
    display_text(console, "▶", 27, 14); display_text(console, "ㆍRight: Right Move", 30, 15);
    display_text(console, "▼", 26, 15); display_text(console, "ㆍDown: Soft Drop", 30, 16);
    display_text(console, "ㆍSpace: Hard Drop", 30, 17);
    display_text(console, "ㆍESC: Quit", 30, 18);
    //display_text(console, "carroty.com", 30, 24);
}

void show_game_demo(windows_console_t* console) {
    //display_text(console, "TETRIS", CENTER_X, CENTER_Y);
    display_text(console, "TETRIS", 15, 15);
}

void show_game_start(windows_console_t* console) {
    display_text(console, "GAME START !!", 15, 15);
}

void show_game_over(windows_console_t* console) {
    display_text(console, "-------------------- GAME END --------------------------", 15, 5);
}

void show_high_score(windows_console_t* console) {
    display_text(console, "abc 123", 15, 15);
    display_text(console, "xyz 121", 15, 16);
}

void draw_by_x_y_info_and_color(int x, int y, int z) {
    COORD pos;
    pos.X = (short)(x * 2);
    pos.Y = (short)y;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 콘솔 커서 위치 이동
    SetConsoleCursorPosition(hConsole, pos);

    // 콘솔 색상 설정 (z는 0~15)
    SetConsoleTextAttribute(hConsole, z);

    // 출력
    printf("■");

    // 색상 초기화 (기본 색상: 7)
    SetConsoleTextAttribute(hConsole, 7);
}

void show_game_intro(windows_console_t* console) {
    int selection = 0;

    while (1) {
        system("cls");  // 화면 초기화

        int N = 15;
        int y = 7;
        for (int i = N;i < N + 5;i++) {

            draw_by_x_y_info_and_color(i, y, 4);
        }
        for (int i = N + 6; i < N + 10;i++) {
            draw_by_x_y_info_and_color(i, y, 14);
        }
        for (int i = N + 11; i < N + 16;i++) {
            draw_by_x_y_info_and_color(i, y, 10);
        }
        for (int i = N + 17; i < N + 21;i++) {
            draw_by_x_y_info_and_color(i, y, 1);
        }
        for (int i = N + 24; i < N + 27;i++) {
            draw_by_x_y_info_and_color(i, y, 11);
        }
        for (int i = N + 29; i < N + 32;i++) {
            draw_by_x_y_info_and_color(i, y, 13);
        }


        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 4);
        }
        for (int i = N + 6;i < N + 7;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 10);
        }
        for (int i = N + 17;i < N + 18;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 1);
        }
        for (int i = N + 21;i < N + 22;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 1);
        }
        for (int i = N + 25;i < N + 26;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 11);
        }
        for (int i = N + 28;i < N + 29;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 13);
        }
        for (int i = N + 32;i < N + 33;i++) {
            draw_by_x_y_info_and_color(i, y + 1, 13);
        }


        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 4);
        }
        for (int i = N + 6;i < N + 7;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 10);
        }
        for (int i = N + 17;i < N + 18;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 1);
        }
        for (int i = N + 21;i < N + 22;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 1);
        }
        for (int i = N + 25;i < N + 26;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 11);
        }
        for (int i = N + 28;i < N + 29;i++) {
            draw_by_x_y_info_and_color(i, y + 2, 13);
        }




        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 4);
        }
        for (int i = N + 6;i < N + 9;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 10);
        }
        for (int i = N + 17;i < N + 21;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 1);
        }
        for (int i = N + 21;i < N + 22;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 1);
        }
        for (int i = N + 25;i < N + 26;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 11);
        }
        for (int i = N + 29;i < N + 32;i++) {
            draw_by_x_y_info_and_color(i, y + 3, 13);
        }


        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 4);
        }
        for (int i = N + 6;i < N + 7;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 10);
        }
        for (int i = N + 17;i < N + 18;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 1);
        }
        for (int i = N + 20;i < N + 21;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 1);
        }
        for (int i = N + 25;i < N + 26;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 11);
        }
        for (int i = N + 32;i < N + 33;i++) {
            draw_by_x_y_info_and_color(i, y + 4, 13);
        }


        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 4);
        }
        for (int i = N + 6;i < N + 7;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 10);
        }
        for (int i = N + 17;i < N + 18;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 1);
        }
        for (int i = N + 21;i < N + 22;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 1);
        }
        for (int i = N + 25;i < N + 26;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 11);
        }
        for (int i = N + 28;i < N + 29;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 13);
        }
        for (int i = N + 32;i < N + 33;i++) {
            draw_by_x_y_info_and_color(i, y + 5, 13);
        }


        for (int i = N + 2;i < N + 3;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 4);
        }
        for (int i = N + 6;i < N + 10;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 14);
        }
        for (int i = N + 13;i < N + 14;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 10);
        }
        for (int i = N + 17;i < N + 18;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 1);
        }
        for (int i = N + 22;i < N + 23;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 1);
        }
        for (int i = N + 24;i < N + 27;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 11);
        }
        for (int i = N + 29;i < N + 32;i++) {
            draw_by_x_y_info_and_color(i, y + 6, 13);
        }


        COORD pos;
        pos.X = 60;
        pos.Y = 20;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

        printf("1. start");

        pos.X = 60;
        pos.Y = 22;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

        printf("2. exit");

		set_cursor_visible(console, false); // 커서 숨기기

        char input = _getch();

        if (input == '1') {
            selection = 1;
            break;  // 게임 시작
        }
        else if (input == '2') {
            selection = 2;
            break;  // 게임 종료
        }
    }

    if (selection == 1) {
        system("cls");
        printf("Starting Game...\n");
        Sleep(1000);  // 1초 대기 (효과용)
    }
    else if (selection == 2) {
        system("cls");
        printf("Exiting Game...\n");
        Sleep(1000);
        exit(0);  // 프로그램 종료
    }
}