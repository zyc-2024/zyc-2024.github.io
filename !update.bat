@echo off
:f
echo ------------------[AutoUpload] Generating Blogs ------------------
pelican content -s publishconf.py -t Flex --ignore-cache
echo ----------------------[AutoUpload] Commiting----------------------
git add -A
git commit -m "Updated some blogs"
echo -----------------------[AutoUpload] Pushing-----------------------
git push
echo [AutoUpload] Successfully executed "git push"
timeout /t 3
cls
goto f