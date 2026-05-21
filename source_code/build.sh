cd "$(dirname "$0")"

if ! command -v make &> /dev/null; then

    echo "[-] Make is not installed. Installing Make via apt..."
    sudo apt update && sudo apt install -y make

    if ! command -v make &> /dev/null; then

        echo "[!] Installation completed, however, Make is not found in the PATH. Please restart your terminal!"
        exit 1
    
    fi
fi

echo "[+] Make is installed. Compiling required files..."
make linux

if [ $? -eq 0 ]; then

    echo "[+] Compilation successful! Running the application..."
    chmod +x ./run.sh
    ./run.sh

else

    echo "[-] Compilation failed. Please check the output for errors." >&2
    exit 1

fi