#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Node;

// land_rows: 세로(n), land_cols: 가로(m)
int solution(int** land, size_t land_rows, size_t land_cols) {
    int n = land_rows;
    int m = land_cols;

    // 덩어리 ID 저장용 배열
    int** comp = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        comp[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            comp[i][j] = -1;
        }
    }

    // 각 덩어리 크기 저장 (최대 n*m개 가능)
    int* compSize = (int*)malloc(sizeof(int) * n * m);
    int compId = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // BFS용 큐
    Node* queue = (Node*)malloc(sizeof(Node) * n * m);

    // 1. 석유 덩어리 분리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && comp[i][j] == -1) {
                int front = 0, rear = 0;
                queue[rear++] = (Node){i, j};
                comp[i][j] = compId;
                int size = 1;

                while (front < rear) {
                    Node cur = queue[front++];
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (land[nx][ny] == 1 && comp[nx][ny] == -1) {
                            comp[nx][ny] = compId;
                            queue[rear++] = (Node){nx, ny};
                            size++;
                        }
                    }
                }

                compSize[compId++] = size;
            }
        }
    }

    int answer = 0;

    // 2. 열별 석유량 계산
    for (int col = 0; col < m; col++) {
        bool* used = (bool*)calloc(compId, sizeof(bool));
        int sum = 0;

        for (int row = 0; row < n; row++) {
            if (land[row][col] == 1) {
                int id = comp[row][col];
                if (!used[id]) {
                    used[id] = true;
                    sum += compSize[id];
                }
            }
        }

        if (sum > answer)
            answer = sum;

        free(used);
    }

    // 메모리 해제
    for (int i = 0; i < n; i++)
        free(comp[i]);
    free(comp);
    free(compSize);
    free(queue);

    return answer;
}
