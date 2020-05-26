rem windows batch commands for WLAN view and connection
@echo off

netsh wlan show networks mode=bssid
netsh wlan show profiles
netsh wlan disconnect
netsh wlan connect ssid=NEFITS-GUEST name=NEFITS-GUEST
