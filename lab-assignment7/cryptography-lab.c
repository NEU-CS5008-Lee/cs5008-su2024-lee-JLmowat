// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
    
    // Add your code here
    for (int i = 0; i<strlen(text); i++) {
        char x = text[i];
        if (x >= 65 && x <= 90){ // Uppercase A-Z
            x = (x - 'A' + key) % 26 + 'A';
            text[i] = x;
        } else if (x >= 97 && x <= 122) { // lowercase a-z
            x = (x - 'a' + key) % 26 + 'a';
            text[i] = x;
        }
    }
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
    
    // Add your code here
    for (int i = 0; i< strlen(text); i++){
        char x = text[i];
        if (x >= 65 && x <= 90){ // Uppercase A-Z
            x = (x - 'A' - key + 26) % 26 + 'A';
            text[i] = x;
        } else if (x >= 97 && x <= 122) { // lowercase a-z
            x = (x - 'a' - key + 26) % 26 + 'a';
            text[i] = x;
        } 
    }
}


/*----------- Main program---------------*/
int main()
{
    
    char text[20] ;
    int keyvalue=3;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input   = %s\n",text);
    
    /*call function to encrypt the data*/
    encrypt(text,keyvalue);
    printf("Encrypted value = %s\n",text);
    
    /*call function to decrypt the data*/
    decrypt(text,keyvalue);
    printf("Decrypted value = %s\n",text);

    
    return 0;
}
