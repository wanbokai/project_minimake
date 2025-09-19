#include<stdio.h>
#include<string.h>
#include"make.h"
#include"function_main.h"

int main(int argc,char *argv[]){
    if(argc==1){
        //printf("error: lack of input!\n");
        preprocess_makefile(0);
        return 1;
    }

    int verbose=0;
    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"--help")==0){
            print_help();
        }else if(strcmp(argv[i],"--version")==0){
            print_version();
        }else if(strcmp(argv[i],"--where")==0){
            print_where();
        }else if(strcmp(argv[i],"--verbose")==0){
            verbose=1;
            preprocess_makefile(verbose);
        }else{
            print_error();
        }
    }
    
    if(verbose){
        check_makefile();
    }
    
    return 0;
}