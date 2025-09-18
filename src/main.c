#include<stdio.h>
#include<string.h>

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

int main(int argc,char *argv[]){
    if(argc==1){
        printf("error: lack of input!\n");
        return 1;
    }

    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"--help")==0){
            print_help();
        }else if(strcmp(argv[i],"--version")==0){
            print_version();
        }else if(strcmp(argv[i],"--where")==0){
            print_where();
        }else{
            print_error();
        }
    }
    return 0;
}