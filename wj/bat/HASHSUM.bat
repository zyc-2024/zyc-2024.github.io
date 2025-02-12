@if (@X)==(@Y) @end /* Harmless hybrid line that begins a JScript comment
@goto :Batch

::::
:::: HASHSUM.BAT历史
::::
:::: v1.8 2021-01-19 -改进了当前代码页的检测
::::                    https://www.dostips.com/forum/viewtopic.php?f=3&t=8533
:::: v1.7 2021-01-19 -增加/U选项以支持文件名中的Unicode
:::: v1.6 2019-02-26 -修改/F和/FR以支持非ascii字符
:::: v1.5 2018-02-18 -增加/H、/F、/FR和/NH选项。
:::: v1.4 2016-12-26 -将/A值转换为大写，因为某些Windows
::::版本区分大小写。还改进了JScript文件
::::通过读取1000000字节而不是1字节来提高读取性能。
:::: v1.3 2016-12-17 -错误修复:从临时文件中删除不需要的\r\n
::::用JScript读取stdin而不是FINDSTR。
::::修复帮助忽略历史。
:::: v1.2 2016-12-07 -错误修复:排除FORFILES目录和
::::正确的setlocal/endlocal管理在:getopoptions
:::: v1.1 2016-12-06 -新增/V选项，并修复了一些小错误。
:::: v1.0 2016-12-05 -最初发布
:::
::HASHSUM [/Option [Value]]…[文件]…
:::
:::使用以下任意标准打印或检查文件哈希值
::哈希算法:MD5、SHA1、SHA256、SHA384、SHA512。
:::
:::HASHSUM总是进行二进制读取- \r\n永远不会转换为\n。
:::
:::在没有/C的情况下，HASHSUM计算每个文件的哈希值，并写入
::结果清单。每一行输出由哈希值组成，
:::后接空格和星号，最后接文件名。默认的
::哈希算法为sha256。文件可以包含通配符，但不能包含
:::任意路径信息。
:::
:::如果未给出File，则从标准输入读取并写入哈希值
:::只包含值，不包含末尾的空格、星号和文件名。
:::
:::选项:
:::
::: / ?—将此帮助信息打印到标准输出。
:::
:::    /??-使用MORE打印页面帮助。
:::
::: /V -打印HASHSUM.BAT版本。
:::
::: /H -打印HASHSUM.BAT历史记录。
:::
::: /U - Unicode模式:尝试支持的实验设置
::文件名中的Unicode。如有任何问题，请向DosTips报告
:::论坛网址:https://www.dostips.com/forum/viewtopic.php?f=3&t=7592
:::
::: /A算法
:::
:::指定下列散列算法之一:
::: md5, sha1, sha256, sha384, sha512
:::
::: /P RootPath
:::
:::指定操作的根路径。
:::默认为当前目录。
:::
::: /S -递归到所有子目录。根目录的相对路径
:::包含在文件名输出中。
:::如果与/C一起使用，此选项将被忽略。
:::
::: /I—在文件名输出中包含RootPath。
:::如果与/C一起使用，此选项将被忽略。
:::
::: /T—在每个文件名前写空格，而不是
:::         星号。但是，文件仍然以二进制模式读取。
:::如果与/C一起使用，此选项将被忽略。
:::
::: /C -从file(清单)中读取哈希值和文件名，并进行验证
:::本地文件匹配。文件可以包含/C的路径信息。
:::
:::如果没有给出File，则从标准中读取哈希和文件名
:::         输入。每一行输入必须有一个散列，后跟两个空格，
:::或空格+星号，后跟文件名。
:::
:::如果不指定/A，则算法由
:::文件扩展名。如果扩展不是有效的算法，则
:::该算法是基于第一个哈希值的长度派生的
::: within File。
:::
:::返回ERRORLEVEL 1，如果没有找到清单文件或清单文件无效。
:::或任何本地文件丢失或不匹配中的哈希值
:::舱单。如果找到所有文件并匹配，则返回0。
:::
::: /F文件名
:::
:::当使用/C时，只检查清单中包含
:: string文件名。搜索忽略了大小写。
:::
::: /FR FileRegEx
:::
:::当使用/C时，只检查清单中与
:::FINDSTR正则表达式FileRegEx。搜索忽略了大小写。
:::
::: /NH - (No Headers)使用/C时抑制清单名称列表。
:::
::: /NE - (No Errors)抑制使用/C时的错误消息。
:::
::: /NM - (No Matches)使用/C时禁止列出匹配的文件。
:::
::: /NS - (No Summary)使用“/C”时禁止显示摘要信息。
:::
::: /Q -(静音)使用/C时抑制所有输出。
:::
:::HASHSUM.BAT 1.8版本由Dave Benham编写
:::保存在https://www.dostips.com/forum/viewtopic.php?f=3&t=7592

============= :Batch portion ===========
@echo off
setlocal disableDelayedExpansion

:: Define options
set "options= /A:"" /C: /I: /P:"" /S: /T: /?: /??: /NH: /NE: /NM: /NS: /Q: /V: /H: /U: /F:"" /FR:"" "

:: Set default option values
for %%O in (%options%) do for /f "tokens=1,* delims=:" %%A in ("%%O") do set "%%A=%%~B"
set "/?="
set "/??="

:getOptions
if not "%~1"=="" (
  set "test=%~1"
  setlocal enableDelayedExpansion
  if "!test:~0,1!" neq "/" endlocal & goto :endOptions
  set "test=!options:*%~1:=! "
  if "!test!"=="!options! " (
      endlocal
      >&2 echo Invalid option %~1
      exit /b 1
  ) else if "!test:~0,1!"==" " (
      endlocal
      set "%~1=1"
  ) else (
      endlocal
      set "%~1=%~2"
      shift /1
  )
  shift /1
  goto :getOptions
)
:endOptions

:: Display paged help
if defined /?? (
  (for /f "delims=: tokens=*" %%A in ('findstr "^:::[^:] ^:::$" "%~f0"') do @echo(%%A)|more /e
  exit /b 0
) 2>nul

:: Display help
if defined /? (
  for /f "delims=: tokens=*" %%A in ('findstr "^:::[^:] ^:::$" "%~f0"') do echo(%%A
  exit /b 0
)

:: Display version
if defined /V (
  for /f "delims=: tokens=*" %%A in ('findstr /ric:"^:::hashsum.bat version" "%~f0"') do echo(%%A
  exit /b 0
)

:: Display history
if defined /H (
  for /f "delims=: tokens=*" %%A in ('findstr "^::::" "%~f0"') do echo(%%A
  exit /b 0
)

:: Unicode filename support
set "find=find"
if defined /U (
  for /f "tokens=*" %%A in ('chcp') do for %%B in (%%A) do set "chcp=%%~nB"
  set "find=findstr /l"
  >nul chcp 65001
)

:: If no file specified, then read stdin and write to a temp file
set "tempFile="
if "%~1" equ "" set "tempFile=%~nx0.%time::=_%.%random%.tmp"
if defined tempFile cscript //nologo //E:JScript "%~f0" "%temp%\%tempFile%"

if defined /P cd /d "%/P%" || exit /b 1
if defined /C goto :check

:generate
if defined tempFile cd /d "%temp%"
if not defined /A set "/A=sha256"
if defined /S set "/S=/s"
if defined /T (set "/T= ") else set "/T=*"
call :defineEmpty
if not defined /P goto :generateLoop
if not defined /I goto :generateLoop
if "%/P:~-1%" equ "\" (set "/I=%/P:\=/%") else set "/I=%/P:\=/%/"
set "rtn=0"

:generateLoop
(
  for /f "delims=" %%F in (
    'forfiles %/s% /m "%tempFile%%~1" /c "cmd /c if @isdir==FALSE echo @relpath" 2^>nul'
  ) do for /f "delims=" %%A in (
    'certutil.exe -hashfile %%F %/A% ^| %find% /v ":" ^|^| if %%~zF gtr 0 (echo X^) else echo %empty%'
  ) do (
    set "file=%%~F"
    set "hash=%%A"
    setlocal enableDelayedExpansion
    set "file=!file:~2!"
    if defined tempFile (
      if !hash! equ X (
        set "rtn=1"
        echo ERROR
      ) else echo !hash: =!
    ) else (
      if !hash! equ X (
        set "rtn=1"
        echo ERROR: !/I!!file!
      ) else echo !hash: =! !/T!!/I!!file:\=/!
    )
    endlocal
  )
) || (
  set "rtn=1"
  echo MISSING: %/T%%1
)
shift /1
if "%~1" neq "" goto :generateLoop
if defined tempFile del "%tempFile%"
if defined /U >nul chcp %chcp%
exit /b %rtn%

:check
if defined /Q for %%V in (/NE /NM /NS /NH) do set "%%V=1"
if defined /F if defined /FR (
  >&2 echo ERROR: /F and /FR cannot be combined
  exit /b 1
)
set "searchTemp="
if defined /F (
  set "searchTemp=%temp%\%~nx0.%time::=_%.%random%.search.tmp"
  setlocal enableDelayedExpansion
  (echo(!/F!) > "!%searchTemp!"
  endlocal
  set "file="    & set "freg=rem" & set "norm=rem"
) else if defined /FR (
  set "searchTemp=%temp%\%~nx0.%time::=_%.%random%.search.tmp"
  setlocal enableDelayedExpansion
  (echo(!/FR!) > "!%searchTemp!"
  endlocal
  set "file=rem" & set "freg="    & set "norm=rem"
) else (
  set "file=rem" & set "freg=rem" & set "norm="
)
set /a manifestCnt=missingManifestCnt=invalidCnt=missingCnt=failCnt=okCnt=0

:checkLoop
set "alogorithm=%/A%"
if defined tempFile set "tempFile=%temp%\%tempFile%"
for %%F in ("%tempFile%%~1") do call :checkFile "%%~F"
if defined tempFile del "%tempFile%"
shift /1
if "%~1" neq "" goto :checkLoop

if defined searchTemp del "%searchTemp%"

if not defined /NS (
  echo ==========  SUMMARY  ==========
  echo Total manifests   = %manifestCnt%
  echo Matched files     = %okCnt%
  echo(
  if %missingManifestCnt% gtr 0 echo Missing manifests = %missingManifestCnt%
  if %invalidCnt% gtr 0         echo Invalid manifests = %invalidCnt%
  if %missingCnt% gtr 0         echo Missing files     = %missingCnt%
  if %failCnt% gtr 0            echo Failed files      = %failCnt%
)
if defined /U >nul chcp %chcp%
set /a "1/(missingManifestCnt+invalidCnt+missingCnt+failCnt)" 2>nul && (
  echo(
  exit /b 1
)
exit /b 0

:checkFile
set /a manifestCnt+=1
if not defined /NH if defined tempfile (echo ----------  ^<stdin^>  ----------) else echo ----------  %1  ----------
if not defined algorithm set "/A="
if not defined /A echo *.md5*.sha1*.sha256*.sha384*.sha512*|%find% /i "*%~x1*" >nul && for /f "delims=." %%A in ("%~x1") do set "/A=%%A"
findstr /virc:"^[0123456789abcdef][0123456789abcdef]* [ *][^ *?|<>]" %1 >nul 2>nul && (
  if not defined /NE if defined tempFile (echo *INVALID: ^<stdin^>) else echo *INVALID: %1
  set /a invalidCnt+=1
  exit /b
)
(
  %norm% for /f "usebackq tokens=1* delims=* " %%A in (%1) do (
  %file% for /f "tokens=1* delims=* " %%A in ('type %1 ^| findstr /ilg:"%searchTemp%"') do (
  %freg% for /f "tokens=1* delims=* " %%A in ('type %1 ^| findstr /irg:"%searchTemp%"') do (
    set "hash0=%%A"
    set "fileName=%%B"
    if defined /A (call :defineEmpty) else call :determineFormat
    setlocal enableDelayedExpansion
    set "fileName=!fileName:/=\!"
    for /f "tokens=1* delims=" %%C in (
      'certutil.exe -hashfile "!fileName!" !/A! ^| %find% /v ":" ^|^| if exist "!fileName!" (echo !empty!^) else echo X'
    ) do set "hash=%%C"
    if /i "!hash0!" equ "!hash: =!" (
      if not defined /NM echo OK: !fileName!
      endlocal
      set /a okCnt+=1
    ) else if !hash! equ X (
      if not defined /NE echo *MISSING: !fileName!
      endlocal
      set /a missingCnt+=1
    ) else (
      if not defined /NE echo *FAILED: !fileName!
      endlocal
      set /a failCnt+=1
    )
  )
) 2>nul || if not defined /F if not defined /FR (
  if not defined /NE echo *MISSING: %1
  set /a missingManifestCnt+=1
)
exit /b

:determineFormat
if "%hash0:~127%" neq "" (
  set "/A=SHA512"
) else if "%hash0:~95%" neq "" (
  set "/A=SHA384"
) else if "%hash0:~63%" neq "" (
  set "/A=SHA256"
) else if "%hash0:~39%" neq "" (
  set "/A=SHA1"
) else set "/A=MD5"

:defineEmpty
if /i "%/A%"=="md5" (
  set "empty=d41d8cd98f00b204e9800998ecf8427e"
  set "/A=MD5"
) else if /i "%/A%"=="sha1" (
  set "empty=da39a3ee5e6b4b0d3255bfef95601890afd80709"
  set "/A=SHA1"
) else if /i "%/A%"=="sha256" (
  set "empty=e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
  set "/A=SHA256"
) else if /i "%/A%"=="sha384" (
  set "empty=38b060a751ac96384cd9327eb1b1e36a21fdb71114be07434c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b"
  set "/A=SHA384"
) else if /i "%/A%"=="sha512" (
  set "empty=cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e"
  set "/A=SHA512"
) else (
  echo ERROR: Invalid /A algorithm>&2
  (goto) 2>nul&exit /b 1
)
exit /b


************* JScript portion **********/
var fso = new ActiveXObject("Scripting.FileSystemObject");
var out = fso.OpenTextFile(WScript.Arguments(0),2,true);
var chr;
while( !WScript.StdIn.AtEndOfStream ) {
  chr=WScript.StdIn.Read(1000000);
  out.Write(chr);
}