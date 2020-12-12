int main(int argc,char *argv[]){
    char *content="New Content ";
    char buffer[30];
    struct stat st;
    void *map;
    if(argc<2)return ;
    //open the file in read only mode;
    int f=open(argv[1],O_RDONLY);
    fstat(f,&st);

    map=mamp(NULL,st.st_size,PROT_READ,MAP_PRIVATE,f,0);
    //map=mmap(NULL,st.st_size,PROT_READ,MAP_SHARED,f,0);
    int fm=open("/proc/self/mem",O_RDWR);

    //write some new content to the memory
    //starting at the 5th byte from the beginning

    lseek(fm,(unitptr_t)map+5,SEEK_SET);
    int result=write(fm,content,strlen(content));
    if(result==-1) printf('write:failed.\n');
    else printf("write:succeed.\n");
    //read the first 29 bytes from the memory
    lseek(fm,(uintptr_t)map,SEEK_SET);
    read(fm,buffer,29); buffer[29]=0;
    printf("read:%s\n",buffer);
    

}