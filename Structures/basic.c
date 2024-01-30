#include <stdio.h>
#include<string.h>

typedef struct song{
    char name[100];
    int views;
    char lyrics[1000];

} song;
typedef struct rapper {
    int songs;
    song song[100];
    char name[100];       
}rapper;
void addSong(rapper *name, char* str,char* lyrics){
    song new;
    strcpy(new.name,str);
    strcpy(new.lyrics,lyrics);
    new.views =0;
    name->songs++;
}
int main(){
    rapper krsna;
    krsna.songs =0;
    strcpy(krsna.name,"KR$NA");
    addSong(krsna,"I Guess","Jab Poochein hai kon hai best it's me I guess");

    return 0;
}