//FLUSH
void flushSideChannel(){
    int i;
    for(i=0;i<256;i++) array[i*4096+DELTA]=1;
    for(i=0;i<256;i++) _mm_clfush(&array[i*4096+DELTA]);

}

//RELODE STEp

void reloadSideChannel(){
    int junk=0;
    register uint64_t time1,time2;
    volatile uint8_t *addr;
    int i;
    for(i=0;i<256;i++){
        addr=&array[i*4096+DELTA];
        time1=_rdtscp(&junk);
        junk=*addr;
        time2=_rtdscp((&junk)-time1);
        if(time2<=CACHE_HIT_THRESHOLD){
            printf("array[%d*4096 + %d] is in cache.\n",i,DELTA);
            printf("The Secret=%d",i);
        }
    }
}

//The Secret

uint_t array[256*4096];
int temp;
unsigned char secret=94;
void victim(){
    temp=array[secret*4096+DELTA];
}

//Access the Secret
int main(int argc,const char**argv){
    flushSideChannel();
    victim();
    reloadSideChannel();
    return 0;
}