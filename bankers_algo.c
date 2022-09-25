#include<stdio.h>
int main(){
    int n,m,i,j,k,alloc[20][20],max[20][20],avail[20],process[20], safe[20],count,ok,store[20];
    printf("Enter the process number: ");
    scanf("%d",&n);
    printf("Enter the resource number: ");
    scanf("%d",&m);

    printf("Enter the allocations matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the max matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }

    //calculating need matrix
    int need[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Need matrix is: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    //Enter available matrix
    printf("Enter the available matrix: \n");
    for(i = 0; i < m; i++){
        scanf("%d",&avail[i]);
    }
    for(i = 0; i < n; i++){
            process[i] = i+1;
            safe[i] = 0;            //initially all processes are unsafe
    }
    //check safe process
    count = 0;
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
           if(safe[i] == 0){
                 ok = 1;
                 for(j = 0; j < m; j++){
                    if(need[i][j] > avail[j]){
                        ok = 0;
                        break;
                    }
                 }
                 if(ok == 1){
                    store[count] = process[i];
                    safe[i] = 1;
                    count++;
                    for(j = 0; j < m; j ++){
                        avail[j] += alloc[i][j];
                    }
                 }
           }
        }
    }
    if(count == n){
        printf("Safe sequence is: ");
        for(i = 0; i < n; i++){
            printf("%d ",store[i]);
        }
    }else{
        printf("Unsafe sequence!!!!");
    }
}


/*input value
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2
*/
