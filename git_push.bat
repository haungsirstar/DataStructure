@echo off
chcp 65001 >nul

REM Change to the script directory
cd /d %~dp0

REM Check if commit message parameter exists
if "%~1"=="" (
    set /p commit_msg=Please enter commit message:
) else (
    set commit_msg=%~1
)

echo Adding all changed files...
git add .

echo Committing with message: %commit_msg%
git commit -m "%commit_msg%"

echo Pushing to remote repository branch main...
git push origin main

pause

