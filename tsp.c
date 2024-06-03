//Travelling Salesman Problem
#include <stdio.h>
#include <limits.h>

#define N 4

int minDist(int graph[][N], int visited[], int curr){
    int min_index = -1;
    int min = INT_MAX;
    for(int i = 0; i < N; i++){
        if(!visited[i] && graph[curr][i] < min){
            min = graph[curr][i];
            min_index = i;
        }
    }
    return min_index;
}

int tsp(int graph[][N]){
    int visited[N] = {0};
    int cost = 0;
    visited[0] = 1;
    int curr = 0;

    for(int i = 1; i < N; i++){
        int next = minDist(graph, visited, curr);
        if(next == -1){
            printf("\nNo route......");
            return -1;
        }
        cost += graph[curr][next];
        visited[next] = 1;
        curr = next;
    }
    cost += graph[curr][0];
    return cost;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    printf("Minimum cost using Nearest Neighbor: %d\n", tsp(graph));
    return 0;
}
