#include<stdio.h>
int LRU(int s[], int frame[], int l, int n, int idx);
int main(){
    int l,s[50],frame[10],n,avail,count=0,i,j,pos=0,full=0;
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
            if(frame[j] == s[i])        //page matches with frame
            {
                avail = 1;              //This page is available in frame, no need to page fault
                break;
            }
        }
        if(avail == 0)  {           //Only if page is not in the frame
            if(full < n) {           //Frames are not full, so simple method
                frame[pos] = s[i];      //Store page in current frame position
                pos++;                      //Move to next position
                full++;                 //Full frame increased
            }
            else{
                pos = LRU(s, frame, l, n, i-1);     //search for least recent frame
                frame[pos] = s[i];                          //store page in least recent pos frame
            }
            count++;                //counting the number of page fault
            for(j=0; j<n; j++){
                if(frame[j] != -1)      //printing frame which don't have -1
                    printf("%d\t",frame[j]);
            }
        }
        printf("\n");
    }
    printf("\nPage Fault is = %d\n", count);
    return 0;
}
int LRU(int s[], int frame[], int l, int n, int idx){
    int ans = 0, oldest = idx, i, j;  //suppose frame-0 is ans, current index is the oldest
    for(i=0; i<n; i++){
        for(j=idx; j>=0; j--){
            if(frame[i] == s[j]){         //this frame is found in the string
                if(j < oldest)        //if this page position is the oldest
                {
                    oldest = j;           //store this page position as oldest
                    ans = i;            //store this frame as ans
                }
               break;                   //break when a frame matches with the string
            }
        }
    }
    return ans;                     //return the Least Recent frame
}





