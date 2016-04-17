#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

//test stat() function
int main(int argc, char *args[]){
    
    if(argc < 2){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname>\n", args[0]);
        exit(1);
    }
    
    struct stat st;
    // Here stat() will not distinguish between regular file 
    // and symbol link file, so we use lstat()
    if(lstat(args[1], &st) < 0){
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(1);
    }
    
    /*
    Linux中七种文件和七种宏： 
    普通文件(regular file)                  S_ISREG() 
    目录文件(directory file)            	    S_ISDIR() 
    块特殊文件(block special file)      	 	S_ISBLK() 
    字符特殊文件(charactor special file)  	S_ISCHR() 
    FIFO(named pipe)                 		S_ISFIFO() 
    套接字(socket)                 			S_ISSOCK() 
    符号链接(symbolic link)         			S_ISLNK()
    */
    if(S_ISREG(st.st_mode)){
        printf("%s is regular file\n", args[1]);
    }else if(S_ISLNK(st.st_mode)){
        printf("%s is symbol link file\n", args[1]);
    }else if(S_ISDIR(st.st_mode)){
        printf("%s is a directory\n", args[1]);
    }else if(S_ISBLK(st.st_mode)){
        printf("%s is block file\n", args[1]);
    }else{
        printf("other case.\n");
    }
   
    return 0;
}

