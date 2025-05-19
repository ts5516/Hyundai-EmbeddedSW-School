#ifndef __CELL_H__
#define __CELL_H__

#include "common.h"

#include "console_driver.h"

#include "point.h"
#include "colors.h"

typedef enum _cell_att_t { // cell_attribute_t
	E, // 0 ����� empty
	W, // 1 ��, ���ټ� ����
	I, // 2�����ʹ� �ִ� �Ϲ����� ���ε�, Į�� ǥ���ϱ� ���ؼ�, 
	J, // 3
	L, // 4
	O, // 5
	S, // 6
	T, // 7
	Z, // 8
	//B, // ���� Ȯ��� Bomb // ��ź ��
	//X, // Shadow // ������(?) ��

} cell_att_t;

//typedef enum _cell_att_t { // cell_attribute_t
//	E, // 0 ����� empty
//	W, // 1 ��, ���ټ� ����
//	N, //  2�����ʹ� �ִ� �Ϲ����� ���ε�, Į�� ǥ���ϱ� ���ؼ�, 
//  B
//} cell_att_t;
// �̷��� �ϴ°� ������
// ������ block�� shape �� ���� ĥ�ϴ°� ������

typedef struct _cell_t {
    point_t point; // cell�� ��ġ
    color_t color; // cell�� ����
    cell_att_t att; // cell�� �Ӽ�
	bool fixed;
} cell_t;

void init_cell(cell_t* cell, int x, int y, cell_att_t att, color_t color);
//void draw_one_cell(cell_t* cell, uint32_t x, uint32_t y);
void draw_cell(cell_t* cell, uint32_t x, uint32_t y);
void cell_test(windows_console_t* console);

#endif