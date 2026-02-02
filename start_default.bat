wt.exe ^
  --title "CMD" -d %~dp0 ; ^
  --title "Host" -d %~dp0 %~dp0\bin\windows_x64\omni_host.exe --config "%~dp0\config\default.xml" ; ^
  --title "Web" -d %~dp0 %~dp0\bin\windows_x64\omni_web.exe --webapp-directory "%~dp0\webui"
