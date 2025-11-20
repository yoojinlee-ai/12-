#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NBOARD 6
#define MAXCOIN 3
#define MAXSHARKSTEP 1
#define SHARKINITPOS 5

// 보드 관련 상태변수 선언
int boardStatus[NBOARD]; // 0: OK, 1: NOK
int boardCoin[NBOARD];
int sharkPosition;

// 보드 초기화 함수
void boardInitBoard(void) {
	int i;
    for(i=0; i<NBOARD; i++) {
        boardStatus[i] = 0;
        boardCoin[i] = 0;
    }
    // 예시: 임의로 3개의 칸에 코인 배치
    int coinCount = 0;
    while (coinCount < MAXCOIN) {
        int idx = rand() % NBOARD;
        if (boardCoin[idx] == 0) {
            boardCoin[idx] = 1;
            coinCount++;
        }
    }
    sharkPosition = SHARKINITPOS;
}

// 보드 상태 출력 함수
void boardPrintBoardStatus(void) {
    printf("[보드 상태] : ");
    int i;
    for(i = 0; i<NBOARD; i++) {
        if(sharkPosition == i)
            printf("S ");
        else if(boardCoin[i])
            printf("C ");
        else
            printf("O ");
    }
    printf("\n");
}

int main() {
    srand((unsigned)time(NULL));  // 랜덤 시드 초기화

    printf("게임을 시작합니다!\n");

    // 보드 초기화
    boardInitBoard();
    boardPrintBoardStatus();

    // (추가: 여기에 게임 루프, 플레이어 이동, 승리조건, 종료 등 구현)
    printf("게임을 종료합니다!\n");
    return 0;
}

