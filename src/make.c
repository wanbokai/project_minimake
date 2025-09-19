#include<stdbool.h>
#include<string.h>
#include<ctype.h>

void rtrim(char *line){
    int len=strlen(line);
//isspace判断该字符是否是空格
    while(len>0&&isspace(line[len-1])){
        line[--len]='\0';
    }
}

bool is_blank(const char *line){
    while(*line){
        if(!isspace(*line)){
            return false;
        }
        line++;
    }
    return true;
}

void remove_comment(char *line){
    while(*line){
        if(*line=='#'){
            *line='\0';
        }
        line++;
    }
}

