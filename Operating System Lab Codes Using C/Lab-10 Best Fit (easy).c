#include<stdio.h>
int main(){
    int b_no,p_no,bsize[10],psize[10],flags[10],alloc[10],temp,lowest=9999,id=9,i,j;
    printf("Enter no. of blocks: ");
    scanf("%d", &b_no);
    printf("Enter size of each block: ");
    for(i = 0; i < b_no; i++)
        scanf("%d", &bsize[i]);
    printf("\nEnter no. of processes: ");
    scanf("%d", &p_no);
    printf("Enter size of each process: ");
    for(i = 0; i < p_no; i++)
        scanf("%d", &psize[i]);
    for(i = 0; i < b_no; i++){
        flags[i] = 0;            //All block are empty
        alloc[i] = -1;               //Block contains no process
    }
    for(i = 0; i < p_no; i++){
        for(j = 0; j < b_no; j++){
            if(flags[j] == 0){       //flag[j] = 0 -> block must be empty; and block size must be greater than process size
                temp = bsize[j] - psize[i];            //temp contains difference of block size and process size
                if(temp >= 0 && temp < lowest){
                    lowest = temp;
                    id = j;                             //storing the process no in id variable, this process has lowest difference
                }
            }
        }
        alloc[id] = i;               //block j contains  i-no. process now
        flags[id] = 1;                           //flag=1, means this block is not empty
        lowest = 9999;              //set impossible lowest for next process
        id = 9;                                 //set impossible id for next process
    }
    printf("\nBlock no.\tBlock Size\tProcess no.\tProcess Size\tUnused Space");
    for(i = 0; i < b_no; i++){
        printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
        if(flags[i] == 1)                      //print process info only if block contains process
            printf("%d \t\t%d \t\t%d",alloc[i]+1, psize[alloc[i]], bsize[i]-psize[alloc[i]]);
        else
            printf("---\t\t---\t\t%d", bsize[i]);
    }
    printf("\n");
}

