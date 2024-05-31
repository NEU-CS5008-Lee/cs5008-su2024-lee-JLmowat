// Jonathan Mowat
// mowat.j@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input1.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here

    // Scan the file into an array
    while(fscanf(fp,"%d", &arr[count])==1){ 
        printf("%d\n", arr[count]);
        count++;
    }
    fclose(fp);

    printf("Count: %d \n", count);
    
    for (i=0; i<count; i++) {
        temp = arr[i];
        for (j=i-1; j>=0 && arr[j]>temp; j--) { // index isn't less than 0 and previos values are bigger than key
            arr[j+1] = arr[j]; // shift
        }
        arr[j+1] = temp;
        
    }
    FILE *op;
    op=fopen("sorted.txt","w");
    if(op==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    for (int i = 0; i < count; i++) {
        fprintf(op, "%d\n", arr[i]);
    }
    //printf("\n");
    fclose(op);

    
    return 0;
}
