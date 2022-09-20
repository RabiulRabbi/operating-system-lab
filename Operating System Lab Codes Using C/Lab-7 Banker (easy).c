#include<stdio.h>

int main()
{
    int n,m,i,j,k,p[20],alloc[20][20],max[20][20],need[20][20],avail[20],safe[20],ans[20], cnt, ok;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter allocation: \n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter max: \n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &max[i][j]);
    printf("Need matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];    //calculating need matrix
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("Enter available: ");
    for(i=0; i<m; i++)
        scanf("%d", &avail[i]);
    for(i=0; i<n; i++)
    {
        p[i] = i+1;             //contains process number
        safe[i] = 0;           //initializing all process as unsafe
    }
    cnt = 0;                    //counting safe processes
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            if(safe[i] == 0)        //checking only for unsafe process
            {
                ok = 1;             //assuming the process would be okay
                for(j=0; j<m; j++)
                {
                    if(need[i][j] > avail[j])       //the process needs more instances than available
                    {
                        ok = 0;                     //this process is not okay yet, so break
                        break;
                    }
                }
                if(ok == 1)                         //if the process is okay
                {
                    ans[cnt] = p[i];                //storing the process number in ans list
                    safe[i] = 1;                    //saying this is safe
                    cnt++;                          //number of safe process increased
                    for(j=0; j<m; j++)
                        avail[j] += alloc[i][j];    //increasing available instances, as this process don't need any
                }
            }
        }
    }
    if(cnt == n)                //if all the processes are safe
    {
        printf("Safe sequence: ");
        for(i=0; i<n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else
        printf("Not safe....!!!\n");
}
