# 테트리스

--- 

## 1. 프로젝트 구조 개요

```
Project Root
├── core/
│   ├── game.h / game.c          (게임 상태 관리, 엔트리 포인트)
│   ├── board.h / board.c        (게임 보드 관리)
│   ├── blocks.h / blocks.c      (블록 로직 및 충돌 검사)
│   ├── game_fsm.h / game_fsm.c  (게임 상태 머신)
├── drivers/
│   ├── sound_driver.h / c       (사운드 재생)
│   ├── console_driver.h / c     (콘솔 출력, 색상 관리)
│   ├── key_driver.h / c         (키 입력 처리)
├── config.h                     (플랫폼 및 설정 파일)
└── main.c                       (메인 루프)
```

---

## 2. 게임 실행 흐름

### 2.1 초기화: `init_game`

* 콘솔 초기화
* 인트로 화면 출력
* 사운드 설정 및 배경음 시작
* 보드 초기화
* 첫 번째, 두 번째 블록 생성
* Hold 영역 초기화
* 키 입력 초기화

---

### 2.2 메인 루프: `update_game`

* 타이머 폴링(`timer_polling`)을 통해 1ms 단위 작업 스케줄링

* 키 입력 확인:

  * `_kbhit()`로 키 입력 여부 확인
  * `get_key_code()`로 키 값 저장

* 키 입력 처리:

  * `update_board_by_key_input` 호출

    * 입력된 키에 따라 블록 이동, 회전, 하드 드롭 수행
    * 이동/회전 성공 시 즉시 보드 업데이트

* 자동 블록 하강:

  * `task_move_flag`가 `true`인 경우

    * `move_block_by_key_input` 호출
    * `update_board`로 보드 갱신

* 블록 충돌 처리:

  * `block_collision`이 `true`인 경우

    * 블록 고정 (`lock_block_after_delay`)
    * 라인 클리어 (`update_board_with_line_clear`)
    * 다음 블록으로 교체
    * Hold 영역 및 보드 상태 업데이트

---

### 2.3 종료 처리: `end_game`

* 사운드 중지 (`stop_sound`)
* 게임 오버 메시지 출력 (`show_game_over`)
* 콘솔 색상 초기화

---

## 3. 주요 입력 키 동작

| 키 입력  | 동작            |
| ----- | ------------- |
| ← / → | 블록 좌우 이동      |
| ↓     | 블록 한 칸 하강     |
| Space | 하드 드롭 (즉시 바닥) |
| R / ↑ | 블록 회전         |

---

## 4. 타이머 및 게임 속도 제어

* `timer_polling` 함수가 1ms 주기로 호출
* `TASK_MOVE_INTERVAL`마다 `task_move_flag = true`
* `update_game`에서 이 플래그 기준으로 블록 자동 하강
* 게임 속도는 `TASK_MOVE_INTERVAL` 값 조정으로 변경

---

## 5. 블록 및 보드 관리

* `gboard`: 메인 게임 보드 (20 x 12 셀)

* `hold_block_board`: 다음 블록 또는 Hold 영역 보드

* `first_block`: 현재 조작 중인 블록

* `second_block`: 다음에 올 블록

* 충돌 및 라인 클리어 처리

  * 충돌 검사: `check_block_collision_on_board`
  * 라인 클리어: `clear_line_on_board`

* 보드 상태 조작

  * 블록 삽입: `insert_block_to_board`
  * 블록 제거: `remove_current_block_from_board`

---

## 6. 입력 시 보드 업데이트 흐름 요약

1. 사용자가 키를 누르면 `_kbhit()`로 입력 여부 확인
2. `get_key_code()`로 키 값 저장
3. `update_board_by_key_input` 호출

   * 내부적으로 `move_block_by_key_input` 또는 `rotate_block_on_board` 실행
   * 유효한 이동 또는 회전인 경우

     * 보드에서 기존 블록 제거
     * 새로운 위치에 블록 삽입
     * `update_board` 호출로 화면 즉시 반영

입력 시 보드가 즉각 업데이트 되도록 함.
