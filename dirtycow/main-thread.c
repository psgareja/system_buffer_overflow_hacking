int main(int argc,char argv[]){
    pthread_t pth1,pth2;
    struct stat,st;
    //open the file in read only mode.
    int f=open("./zzz",O_RDONLY);
    stat(f,&st);
   int map=mmap(NULL,st.st_size,PROT_READ,MAP_PRIVATE,f,0);
    //creating thread

    pthread_create(&pth1,NULL,madviseThread,NULL);
    pthread_create(&pth2,NULL,procselmemThread,TARGET_CONTENT);

    //wait for the thread is finish
    pthread_join(pth1,NULL);
    pthread_join(pth2,NULL);
    return 0;


}