@echo off
echo ============================================
echo CINTA - FORCE BROWSER CACHE CLEAR
echo ============================================
echo.
echo This will close your browser and clear cache
echo.
pause

echo Closing all browser processes...
taskkill /F /IM chrome.exe 2>nul
taskkill /F /IM msedge.exe 2>nul
taskkill /F /IM firefox.exe 2>nul
taskkill /F /IM brave.exe 2>nul

echo.
echo Waiting for processes to close...
timeout /t 2 /nobreak >nul

echo.
echo Clearing Chrome cache...
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Cache" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Code Cache" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Service Worker" 2>nul

echo Clearing Edge cache...
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Cache" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Code Cache" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Service Worker" 2>nul

echo.
echo ============================================
echo CACHE CLEARED!
echo ============================================
echo.
echo Now:
echo 1. Open your browser
echo 2. Go to: http://localhost:8081
echo 3. Press Ctrl+Shift+R to hard refresh
echo.
pause
