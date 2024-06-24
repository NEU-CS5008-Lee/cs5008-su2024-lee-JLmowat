// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

// format of document is a bunch of data lines beginning with an integer (rank which we ignore)
// then a ',' followed by a double-quoted string (city name)
// then a ',' followed by a double-quoted string (population) - ignore commas and covert to int; or (X) - convert to 0
// then a lot of entries that are ignored


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAXSTRING 200

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c) {
  if ('0' <= c && c <= '9') {
    return true;
  } else {
    return false;
  }
}

// append character c to string s
void appendChar(char* s, char c) {
  char charToStr[2];           // convert char to string
    charToStr[0] = c;
    charToStr[1] = '\0';          // put NUL to terminate string of one character
    strcat(s, charToStr);
}



int main () {

  char inputLine[MAXSTRING];   // temporary string to hold input line
  char cityStr[MAXSTRING];     // city name
  int  lineNum;                // line number (city rank)
  int  popInt;                 // population
  int  state;                  // FSM state
  int  nextChar;               // index of next character in input string
  char temp[MAXSTRING];        // temp string to build up extracted strings from input characters
  
 
  FILE* fp;
  fp = fopen("pop.csv","r");

  if (fp != NULL) {
    fgets(inputLine, MAXSTRING, fp); // prime the pump for the first line

    // ***** BEGIN FINTITE STATE MACHINE *****
    
    // STARTSTATE: digit -> S1
    // S1: digit -> S1; , -> S2
    // S2: " -> S3
    // S3: !" -> S3; " -> S4
    // S4: , -> S5
    // S5: " -> S6; ( -> ACCEPTSTATE
    // S6: digit -> S6; , -> S6; " -> ACCEPTSTATE; 
    // ACCEPTSTATE: done!
    // else go to ERRORSTATE
    //
    while (feof(fp) == 0){

      nextChar = 0;
      state = STARTSTATE; 
      strcpy(temp,"");       // temp = ""

      if (nextChar >= strlen(inputLine)){
        // if no input string then go to ERRORSTATE
        state = ERRORSTATE;
      } 

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE)) {
        switch (state) {
          case STARTSTATE:
            // look a digit to confirm a valid line
            if (isDigit(inputLine[nextChar])) {
              state = S1;
              appendChar(temp, inputLine[nextChar]);
            } else {
              state = ERRORSTATE;
            }  
            break;

          // ADD YOUR CODE HERE
          case S1: //Collect all the digits at the begining of each line until there is a comma
            if (isDigit(inputLine[nextChar])) {
              // state = S1;
              appendChar(temp, inputLine[nextChar]);
            } else if (inputLine[nextChar] == ',') {
              lineNum = atoi(temp); // convert temp to integer
              strcpy(temp,""); // reset temp to empty
              state = S2;
            } else {
              state = ERRORSTATE;
            }
            break;


          case S2: // Check for a " to start saving the city location
            if (inputLine[nextChar] == '"') {
              state = S3;
              strcpy(cityStr,""); // reset cityStr to empty
            } else {
              state = ERRORSTATE;
            }
            break;

          case S3: // Check for " to end saving the city location
            if (inputLine[nextChar] != '"') {
              appendChar(cityStr, inputLine[nextChar]);
            } else {
              state = S4;
            }
            break;

          case S4: // Check for , for the population numbers
            if (inputLine[nextChar] == ',') {
              state = S5;
            } else {
              state = ERRORSTATE;
            }
            break;

           case S5:
            // Check if population is missing (X) or present "123"
            if (inputLine[nextChar] == '"') {
              state = S6;
            } else if (inputLine[nextChar] == '(') {
              state = ACCEPTSTATE;
              popInt = 0;  // population data is missing
            } else {
              state = ERRORSTATE;
            }
            break;
          
          case S6:
            // gather digits for the population field until the closing quote is found
            if (isDigit(inputLine[nextChar])) {
              appendChar(temp, inputLine[nextChar]);
            } else if (inputLine[nextChar] == ',') {
              // Skip the commas in the population number
            } else if (inputLine[nextChar] == '"') {
              state = ACCEPTSTATE;
              popInt = atoi(temp);  // convert population to integer
            } else {
              state = ERRORSTATE;
            }
            break;


      
            
          case ACCEPTSTATE:
            // nothing to do - we are done!
            break;
            
          default:
            state = ERRORSTATE;
            break;
        } // end switch

        // advance input
        nextChar++;
	
      }	// end while state machine loop

      // ***** END FINITE STATE MACHINE *****
	  

      // process the line - print out raw line and the parsed fields
      printf("> %.60s\n", inputLine);
      printf("[%.30s]: %d\n", cityStr, popInt);

      // get next line
      fgets(inputLine, MAXSTRING, fp);
      
    } // end while file input loop
    

    fclose(fp);
  
  } else {
    printf("File not found!\n");
  }
  
  return 0;
}
