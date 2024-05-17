// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include<stdio.h>
int main()
{
    int a,b,c, choice;
    
    printf("Enter your choice\n");
    printf(" 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n");
    scanf("%d",&choice);
    
    printf("Enter a and b values ");
    scanf("%d %d", &a, &b);

    printf("Inputs: %d %d \n", a, b);
    
    // Add your code here using switch
    switch (choice)
    {
    case 1: 
        printf("Addition\nSum = %d\n", (a+b));
        break;
    case 2:
        printf("Subtraction\nDifference = %d\n", (a-b));
        break;
    case 3:
        printf("Multiplication\nProduct = %d\n", (a*b));
        break;
    case 4:
        if (b == 0){
            printf("Divide by zero error\n");
            break;
        }
        else{
            printf("Division\nQuotient = %d\n", (a/b));
            if(a%b != 0){
                printf("Remainder = %d/%d\n", a%b, b);
            }
        }
        break;
    default:
        printf("Invalid Option\n");
        break;
    }
           
    return 0;
}
