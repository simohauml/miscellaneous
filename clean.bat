@echo clean thumbnails

del /a /f /s /q "*.png"
@echo cleaning thumbnails is done!

@echo clean empty folders
@pause
@echo clean drive C
dir c: /ad /b /s | sort /r >> c:\clean-list.txt
for /f "tokens=*" %%i in (c:\clean-list.txt) rd "%%i"

echo y | del c:\clean-list.txt
@echo cleaning is done!