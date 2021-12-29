$cwd = Get-Location 

# Clean the build directory if it exists
if (Test-Path -Path "${cwd}/build") {
    Remove-Item -Path "${cwd}/build" -Recurse -Force
}
    
    
# Make the build directory, change into it and build 
New-Item -ItemType Directory -Force -Path "${cwd}/build"
Set-Location -Path "${cwd}/build"
cmake ../ -G "MinGW Makefiles"
cmake --build . --config Debug --target all -j 10 --

