#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *source , char *destination){
    char *p = destination;
    while(*source!='\0'){
        *p++ = *source++;
    }
    *p = '\0';
    return destination;
}
void *my_strcat(char *destination, char *str2){
    char* p = destination;
    while(*p!='\0'){
        p++;
    }
    char *p2 = str2;
    while(*p2!='\0'){
        *p++ = *p2++;
    }
    *p = '\0';
}
int my_strcmp(char *str1 , char *str2){
    while(*str1 != '\0' && *str2 !='\0'){
        if(*str1 != *str2){
            return 0;
        } 
        str1++;
        str2++;   
    }
    if(*str1=='\0' && *str2 == '\0'){
        return 1;
    }

    return 0;
}
int my_strlen(char *str1){
    int ans = 0;
    while(*str1!='\0'){
        str1++;
        ans++;
    }
    return ans;
}
int main(){
    char str[80] = "This is a string in C. It is different from other Languages";
    char str1[100] = "World";
    char str2[100] = "World";
    int same =  my_strcmp(str1,str2);
    printf("%d",same);
    my_strcat(str1,str2);
    puts(str1);
    int len = my_strlen(str1);
    printf("%d",len);
}