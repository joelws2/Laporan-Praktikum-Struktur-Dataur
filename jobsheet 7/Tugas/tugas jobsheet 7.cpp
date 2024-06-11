#include <stdio.h>
#include <stdlib.h>

// Maksimum jumlah simpul/graf yang digunakan
#define MAX_NODES 100

// Mendefinisikan struktur queue
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Inisialisasi queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Cek apakah queue kosong
int isEmpty(struct Queue* queue) {
    if (queue->rear == -1)
        return 1;
    else
        return 0;
}

// Menambah elemen pada queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_NODES - 1)
        printf("\nAntrian Penuh!!");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Menghapus elemen dari queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Antrian kosong");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Fungsi untuk menampilkan jalur BFS
void BFS(int adjacency_matrix[MAX_NODES][MAX_NODES], int source, int nodes) {
    int visited[MAX_NODES] = {0};
    struct Queue* queue = createQueue();

    visited[source] = 1;
    enqueue(queue, source);

    printf("Breadth First Search dimulai dari simpul %d: ", source);

    while (!isEmpty(queue)) {
        int current_node = dequeue(queue);
        printf("%d ", current_node);

        for (int i = 0; i < nodes; i++) {
            if (adjacency_matrix[current_node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    int adjacency_matrix[MAX_NODES][MAX_NODES];
    int nodes, i, j;

    printf("Masukkan jumlah simpul: ");
    scanf("%d", &nodes);

    printf("\nMasukkan matriks adjacency:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }

    int starting_node;
    printf("\nMasukkan simpul awal: ");
    scanf("%d", &starting_node);

    BFS(adjacency_matrix, starting_node, nodes);

    return 0;
}
