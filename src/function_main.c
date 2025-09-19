#include<stdio.h>
#include<stdlib.h>
#include"make.h"

#define MAXLINE 1024

void print_help(){
    printf("Usage:...\n");
    printf("program  --help\n");
    printf("program --version\n");
    printf("program --where\n"); 
}

void print_version(){
    printf("version(1.0.0)\n");
}

void print_where(){
    printf("project_minimake\n");
}

void print_error(){
    printf("unkown command\n");
    printf("please input true command(--help)\n");
}

void preprocess_makefile(int verbose){
    FILE *fp=fopen("./Makefile","r");
    if(!fp){
        perror("Makefile can not be open");
        exit(1);
    }

    FILE *out=NULL;
    if(verbose){
        out=fopen("./minimake_cleared.mk","w");
        if(!out){
            perror("can not build minimake_clear");
            fclose(fp);
            exit(1);
        }
    }

    char line[MAXLINE];
    while(fgets(line,sizeof(line),fp)){
        rtrim(line);
        remove_comment(line);
        if(is_blank(line)){
            continue;//跳过这行不要输出
        }

        if(verbose&&out){
            fprintf(out,"%s\n",line);
        }//输入到文件中
            
        printf("%s\n",line);
    }
    fclose(fp);
    if(out!=NULL)
    fclose(out);
}
