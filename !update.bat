@echo off
:f
echo ----------------------[AutoUpload] Commiting----------------------
git add -A
git commit -m "Updated or added some blogs"
echo -----------------------[AutoUpload] Pushing-----------------------
git push
echo [AutoUpload] Successfully executed "git push"
timeout /t 3
cls
goto f