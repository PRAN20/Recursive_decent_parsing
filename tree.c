#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char token;
char str[102];
int lookahead = 0;

char getToken()
{
    lookahead = lookahead + 1;
    return str[lookahead];
}

void fS();
void fB();

void fA(){
    if(token == 'b'){
        token = getToken();
        if(token == 'a'){
            token = getToken();
        }
        else{
            printf("Error in Parsing");
            exit(0);
        }
    }
        else if(token == 'a' || token == 'c'){
            fS();
            fB();
        }
        else{
            printf("Error in Parsing");
            exit(0);
        }
}

void fS()
{
    if(token == 'a'){
        token = getToken();
        fA();
        fS();
    }
    else if(token == 'c'){
        token = getToken();
    }
    else{
        printf("Error in Parsing");
        exit(0);
    }
}

void fB()
{
    if(token == 'b'){
        token = getToken();
        fA();
    }
    else if(token == 'a' || token == 'c')
        fS();
    else{
        printf("Error in Parsing");
        exit(0);
    }
}



int main() {
    
    scanf("%s",str);
    
    int dollar_pos = 0;
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    
    dollar_pos = i;
    str[dollar_pos] = '$';
    str[dollar_pos+1] = '\0';
    
    token = str[0];
    
    fS();
    
    if(token == '$'){
        printf("Sucessfully Parsed");
    }
    else{
        printf("Error in Parsing");
    }
    
    
    
    return 0;
