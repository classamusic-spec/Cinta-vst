@echo off
echo ============================================
echo CINTA - NUCLEAR CACHE CLEAR
echo ============================================
echo.
echo This will COMPLETELY clear all browser data
echo.
pause

echo Closing ALL browsers...
taskkill /F /IM chrome.exe 2>nul
taskkill /F /IM msedge.exe 2>nul
taskkill /F /IM firefox.exe 2>nul
taskkill /F /IM brave.exe 2>nul
timeout /t 3 /nobreak >nul

echo.
echo DELETING Chrome cache folders...
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Cache" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Code Cache" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\Service Worker" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\Default\GPUCache" 2>nul
rd /s /q "%LocalAppData%\Google\Chrome\User Data\ShaderCache" 2>nul

echo DELETING Edge cache folders...
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Cache" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Code Cache" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\Service Worker" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\Default\GPUCache" 2>nul
rd /s /q "%LocalAppData%\Microsoft\Edge\User Data\ShaderCache" 2>nul

echo.
echo ============================================
echo CACHE COMPLETELY CLEARED!
echo ============================================
echo.
echo NOW:
echo 1. Open browser in INCOGNITO/PRIVATE mode
echo 2. Go to: http://localhost:8081
echo 3. Check console for "Patch version: 1.0.5"
echo.
pause
