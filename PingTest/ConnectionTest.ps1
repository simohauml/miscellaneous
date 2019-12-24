$logpath = "D:\PingTest\"
$filename = "PingLog_" + (Get-Date -Format 'yyyy-MM-dd_HH-mm-ss') + ".txt"
$filepath = $logpath + $filename
ping -t 172.31.0.89|Foreach{"{0} - {1}" -f (Get-Date), $_}|Out-File $filepath -Append