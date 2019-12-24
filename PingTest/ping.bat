:PINGINTERVAL
@ECHO OFF
echo %time% >> D:\PingTest\pinglog.txt
ping 192.168.1.89 -n 1 >> D:\PingTest\pinglog.txt
timeout 1
GOTO PINGINTERVAL