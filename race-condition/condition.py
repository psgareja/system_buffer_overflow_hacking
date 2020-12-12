int main(){
    char *fn='/tmp/xyz';
    char buffer[60];
    FILE *fp;
    scan('%50s',buffer);
    if(!access(fn,W_OK)){
        fp=fopen(fn,"a+")
        fwrite("\n",sizeof(char),1,fp);
        fwrite(buffer,sizeof(char),strlen(buffer),fp);
        fclose()
    }
    else{
      printf("No permission\n")
       return 0; 
    }

}