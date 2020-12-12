#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
int main(){
    struct stat_st;
    char content[10];
    char *new_content="New Content";
    void *map;

    int f=open("./zzz",O_RDWR);
    fstat(f,&st);
    //map the file to memory
    map=mmap(NULL,st.st_size,PROT_READ | PROT_WRITE,MAP_SHARED,f,0);
    //Read from the file via the mapped
    memcpy((void*)content,map,10);
    printf("read:%s\n",content);

    //clean up
    munmap(map,st.st_size);
    return 0;




}
