#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 13

// 미로를 표현하는 문자열 배열
char maze[ROWS][COLS] = {
    "1111111111111",
    "10010000000C1",
    "1000011111001",
    "1P00111000001",
    "1111111111111"
};

// 방문한 셀을 표시하기 위한 배열
bool visited[ROWS][COLS];

// 가능한 이동 방향 (상, 하, 좌, 우)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// 미로 범위 내에 있는지 확인하는 함수
bool isValid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// DFS를 사용하여 경로를 찾는 함수
bool findPath(int row, int col) {
    // 목적지에 도달했을 경우
    if (maze[row][col] == 'C') {
        return true;
    }

    // 현재 위치를 방문한 것으로 표시
    visited[row][col] = true;

    // 상하좌우 방향으로 이동을 시도
    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // 새로운 위치가 미로 범위 내에 있고, 이동 가능한 곳이며 아직 방문하지 않았다면
        if (isValid(newRow, newCol) && maze[newRow][newCol] != '1' && !visited[newRow][newCol]) {
            // 재귀적으로 탐색
            if (findPath(newRow, newCol)) {
                return true;
            }
        }
    }

    // 현재 위치에서 목적지까지 가는 경로를 찾지 못한 경우
    return false;
}

int main() {
    int startRow, startCol;

    // 시작점 (P) 찾기
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'P') {
                startRow = i;
                startCol = j;
                break;
            }
        }
    }

    // 방문 배열 초기화
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }

    // 시작점에서 경로 찾기
    if (findPath(startRow, startCol)) {
        printf("도착 지점에 도달 가능합니다.\n");
    } else {
        printf("도착 지점에 도달할 수 없습니다.\n");
    }

    return 0;
}
