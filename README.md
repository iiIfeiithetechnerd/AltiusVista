# AltiusVista

## Overview

AltiusVista is an open-source graphing engine built with C and Python. The project name combines Latin roots: "Altius" meaning "High" and "Vista" meaning "View". The intent is to present graphs and data visually in a powerful and polished way.

## Current status

This project is under active development. The current starter workflow is:

- `start.c` checks for an available Python interpreter
- `start.c` launches `source_code/init.py`
- `init.py` is the Python entry point for future graphing and visualization features

## Tech stack

- C: `source_code/start.c`
- Python: `source_code/init.py`
- License: MIT

## Getting started

### Requirements

- A C compiler such as `gcc` or `clang`
- Python installed and available on `PATH`

### Build and run

From the project root:

```sh
cd a:/AltiusVista
gcc source_code/start.c -o altiusvista
./altiusvista
```

On Windows using PowerShell or Command Prompt:

```powershell
cd a:\AltiusVista
gcc source_code\start.c -o altiusvista.exe
.\uild\altiusvista.exe
```

If Python is detected, the program will attempt to launch `source_code/init.py`.

## Project structure

- `source_code/start.c` — C launcher that checks for Python and starts the app
- `source_code/init.py` — Python entry script for the graphing engine
- `LICENSE` — MIT license
- `README.md` — this file

## Contributing

Contributions are welcome. If you want to help:

1. Fork the repository
2. Add features or fixes
3. Submit a pull request

## License

This project is licensed under the MIT License. See `LICENSE` for details.
