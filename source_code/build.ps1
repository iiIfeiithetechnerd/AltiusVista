if (-not (Get-Command "make" -ErrorAction SilentlyContinue)) {
    Write-Host "[-] Make is not installed. Installing Make via winget..." 

    winget install EzWinPorts.Make --silent --accept-source-agreements --accept-package-agreements

    $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")

    if(-not (Get-Command "make" -ErrorAction SilentlyContinue)) {
        Write-Error "[!] Installation completed, however, Make is not found in the PATH. Please restart your terminal!" 
        Exit 1
    }
}

Write-Host "[+] Make is installed. Compiling required files..." 
make windows

if ($LASTEXITCODE -eq 0){
    Write-Host "[+] Compilation successful! Running the application..." 
    & ".\run.ps1"
} else {
    Write-Error "[-] Compilation failed. Please check the output for errors." 
    Exit 1
}