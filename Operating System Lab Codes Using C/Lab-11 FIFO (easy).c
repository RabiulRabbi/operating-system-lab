#include<stdio.h>
int main(){
    int l, s[50], frame[10], n, avail, count = 0, i, j, pos=0;
    printf("Enter the length of the string: ");
    scanf("%d",&l);
    printf("Enter the string: ");
    for(i=0; i<l; i++)
        scanf("%d",&s[i]);
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        frame[i]= -1;           //Initially frame is empty, -1 means empty
    printf("\nString\t\t Page Frames\n");
    for(i=0; i<l; i++){
        printf("%d\t\t",s[i]);
        avail = 0;          //suppose page is not available in the frame
        for(j=0; j<n; j++){
            if(frame[j] == s[i]) {      //page matches with frame
                avail = 1;              //This page is available in frame, no need to page fault
                break;
            }
        }
        if(avail == 0)  {           //Only if page is not in the frame
            frame[pos] = s[i];      //Store page in current frame position
            pos = (pos+1) % n;          //pos is increased circular like a queue, so first in first out will occur
            count++;                //counting the number of page fault
            for(j=0; j<n; j++){
                if(frame[j] != -1)
                    printf("%d\t",frame[j]);
            }
        }
        printf("\n");
    }
    printf("\nPage Fault is = %d\n", count);
    return 0;
}


