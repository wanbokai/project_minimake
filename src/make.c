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

// 判断是否包含冒号
bool is_target_line(const char *line) {
   if(strchr(line,':')!=NULL){
    return true;
   }else {return false;} 
}

//判断是否以tab开头
bool is_command_line(const char *line){
    if(line[0]=='\t'){
        return true;
    }else {return false;}
}
