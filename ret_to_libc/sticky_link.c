//$ sudo sysctl -w fs.protected_symlinks=0


int main(){
    char *fn="/tmp/XYZ";
    FILE=fp;
    fp=fopen(fn,"r");
    if(fp==NULL){
        printf("fopen() call failled\n");
        printf("Reason: %s\n",strerror(errno));
    }
    else{
        printf("fopen() call succeeded \n")
        fclose(fp);
    
    }
    return 0;
}