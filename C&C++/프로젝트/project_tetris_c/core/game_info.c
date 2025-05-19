#include "game_info.h"

void show_key_usage(windows_console_t* console) {

    // debug
    // ������ ���������� ���� �׽�Ʈ �� ��ǥ ��궧���� �ʿ��ϴ�.
    // ���� ������� ������ �ȴ�. ���� �����ؼ� �ּ�ó���ߴ�.
    cell_test(console);


    display_text(console, "Stage: 1", 25, 4); // ���� ��������

    display_text(console, "Target Lines: 9", 25, 6); // ���־��� ��ǥ ���μ�
    display_text(console, "Cleard Lines: 1", 25, 7); // �ڳװ� �� ���μ�

    display_text(console, "Difficulty: Easy", 25, 9); // ���� ����

    display_text(console, "Difficulty: Easy", 25, 9); // ���� ����
    display_text(console, "Highest Cleard Line : 123 (Medium)", 25, 10);
    //��墸��
    display_text(console, "��", 26, 13); display_text(console, "��Up: Rotate", 30, 13);
    display_text(console, "��", 25, 14); display_text(console, "��Left: Left Move", 30, 14);
    display_text(console, "��", 27, 14); display_text(console, "��Right: Right Move", 30, 15);
    display_text(console, "��", 26, 15); display_text(console, "��Down: Soft Drop", 30, 16);
    display_text(console, "��Space: Hard Drop", 30, 17);
    display_text(console, "��ESC: Quit", 30, 18);
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

    // �ܼ� Ŀ�� ��ġ �̵�
    SetConsoleCursorPosition(hConsole, pos);

    // �ܼ� ���� ���� (z�� 0~15)
    SetConsoleTextAttribute(hConsole, z);

    // ���
    printf("��");

    // ���� �ʱ�ȭ (�⺻ ����: 7)
    SetConsoleTextAttribute(hConsole, 7);
}

void show_game_intro(windows_console_t* console) {
    int selection = 0;

    while (1) {
        system("cls");  // ȭ�� �ʱ�ȭ

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

		set_cursor_visible(console, false); // Ŀ�� �����

        char input = _getch();

        if (input == '1') {
            selection = 1;
            break;  // ���� ����
        }
        else if (input == '2') {
            selection = 2;
            break;  // ���� ����
        }
    }

    if (selection == 1) {
        system("cls");
        printf("Starting Game...\n");
        Sleep(1000);  // 1�� ��� (ȿ����)
    }
    else if (selection == 2) {
        system("cls");
        printf("Exiting Game...\n");
        Sleep(1000);
        exit(0);  // ���α׷� ����
    }
}