static sigjmp_buf jbuf;
static void catch_segv()
{
    siglongjmp(jbuf,1);//roll back

}
int main()
{
    unsigned long kernel_data_addr=0xf9c98000;
    signal(sigsetjmp(SIGSEGV,catch_segv));
    if(sigsetjmp(jbuf,1)==0){
        char kernel_dat=*(char*)kernel_data_addr;
        printf("kernel data ata address %lu is : %c\n",kernel_data_addr,kernal_data);

    }else{
        printf("Memory access violation!\n");
    }
    printf("Execution\n");
    return 0;
}