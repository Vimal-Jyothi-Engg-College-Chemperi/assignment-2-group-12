#include <stdio.h>
struct process {
    int id;
    int timestamp;
};
int main() {
    int n, i, j;
    struct process p[10], temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("\nEnter request timestamps:\n");
    for(i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Process %d timestamp: ", i + 1);
        scanf("%d", &p[i].timestamp);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(p[i].timestamp > p[j].timestamp ||
              (p[i].timestamp == p[j].timestamp && p[i].id > p[j].id)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    printf("\nOrder of file access (Critical Section Execution):\n");
    for(i = 0; i < n; i++) {
        printf("Process %d enters critical section\n", p[i].id);
        printf("Process %d accessing shared file...\n", p[i].id);
        printf("Process %d leaves critical section\n\n", p[i].id);
    }
    return 0;
}