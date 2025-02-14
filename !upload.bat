@echo off
:f
echo ----------------------[AutoUpload] Commiting----------------------
git add -A
git commit -m "Add files via git"
echo ---------------------- [AutoUpload] Pushing ----------------------
git push | set ifSussess = %1
echo [AutoUpload] Successfully executed "git push"
cls
goto f