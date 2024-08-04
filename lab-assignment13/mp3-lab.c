// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include<stdio.h>
#include<string.h>

int compression(char arr[], int n, char res[]){
    //insert your code here

    // edge case 
    if(n<1) {
        return 0;
    }

    int i = 0;
    int count;
    int index = 0;
    char current;

    while (i < n) {
        current = arr[i];
        
        // Count number of times the current character repeats
        count = 1;
        while (i+1  < n && current == arr[i+1]) {
            count++;
            i++;
        }

        // Save the current character to results
        res[index++] = current;
        
        
        // If the count is more than 1, store it in the result
        if (count > 1) {
            int num_chars = sprintf(&res[index], "%d", count); // if two digit number
            index += num_chars;
        }
        i++;
    }

    // display the compressed string
    for (int i=0; i < index; i++) {
        printf("%c", res[i]);
    }

    printf("\n");
    return index;
    
}
 
int main()
{
    char a[]="aaaaaaaaaaaaaabbbbcccd";
    char res[50];
    int r,n=strlen(a);//n is the size of input array
    r=compression(a,n,res);
    printf("length of the compressed string:%d\n",r);
    return 0;
}
