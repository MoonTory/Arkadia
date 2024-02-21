@echo off

pushd ..
Vendor\Binaries\Premake\Windows\premake5.exe --file=premake5.lua gmake2
popd
pause