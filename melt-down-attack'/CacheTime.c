//flush the array from cpu cache
for(i=0;i<10;i++)__mm_clflush(&array[i*4096])
//access some of the arra items

array[3*4096]=100;
array[7*4096]=200;
for(i=0;i<10;i++){
    addr=&array[i*4096];
    time1=_rdtscp(&junk); junk=*addr;
    time2=_rdtscp(&junk)-time1;
    printf("Access time for array[%d*4094]:%d cpu cycle\n",i,int(time2)),
}