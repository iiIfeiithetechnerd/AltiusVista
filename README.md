# AltiusVista

AltiusVista is an open-source, high-resolution data visualization and system analysis tool designed to bridge the gap between low-level system operations and high-level data interpretation. The project implements a core logic engine in C to handle system-level tasks and file management, while utilizing Python for complex data processing and graphical rendering. C++ is also used to enhance the 3d graphs produced by this program.
<br>
> This project is currently in development, so expect things such as bugs and errors. This project will always be in development.

## Project Anatomy

The repository is structured to separate system logic from data visualization to maintain zero latency and high throughput.

* Logic Engine (C): Handles the fundamental operations, file system checks, and ensures the environment is prepared for data processing.
* Data Analysis (Python): Processes the data extracted by the logic engine to generate high-resolution graphs and insights.
* Cross-Platform Integration: Designed to operate within a Linux environment (optimized for Arch Linux) while maintaining portability for other Unix-like systems.
* While this program is optimized for Linux, specifically Arch Linux, it is also currently being optimized to run on Windows.
## Technical Specifications

### Logic Core (main.c)
The C component serves as the primary controller. It includes:
* Standard I/O and System Libraries: Utilizes <stdio.h>, <stdlib.h>, and <string.h> for memory and string manipulation.
* Environment Verification: Includes logic to detect the presence of required Python dependencies to prevent runtime corruption.
* Execution Control: Manages the lifecycle of the data visualization process.

### Data Visualization (main.py)
The Python component is the analytical layer of the Vista.
* Data Ingestion: Reads processed system data or external datasets.
* Graphical Rendering: Produces visual representations of complex data structures.

## Installation and Deployment

### Prerequisites
To maintain system integrity and ensure the Sovereign operation of the software, the following must be installed:
* GCC (GNU Compiler Collection)
* Python 3.10 or higher
* Required Python modules: matplotlib, seaborn, plotly, pandas

### Build Instructions
1. Clone the repository:

```
git clone https://github.com/iiIfeiithetechnerd/AltiusVista.git
cd AltiusVista
```
   
3. Compile the C logic engine: 

```
gcc main.c -o AltiusVista
```
   
#### For Windows Users 
> [!TIP]
> If you are on Windows, make sure that you have MSYS2 UCRT64 installed. If you don't, download it here: https://www.msys2.org/ (press ctrl +  and click the link on Windows/Linux or cmd + and click the link in MacOS)

##### For source_code/windows_start.c
1. Compile the C program (Ensure you're in UCRT64): 

```
gcc source_code/windows_start.c -o windows_start.exe
```

2. Run the compiled binary: 

```
./windows_start.exe
```

##### For source_code/install_libraries_windows.c
1. Update the package database: 

```
sudo pacman -Syu
```

2. Install the pre-compiled data science libraries: 

```
pacman -S mingw-w64-ucrt-x86_64-python-matplotlib mingw-w64-ucrt-x86_64-python-pandas \mingw-w64-ucrt-x86_64-python-seaborn
```

3. Create a virtual environment: 

```
python -m venv venv
```

4. Install Plotly: 

```
./venv/bin/python -m pip install plotly
```

5. Compile the C program (ensure you're in UCRT64): 

```
gcc source_code/install_libraries_windows.c -o install_libraries_windows.exe
```

6. Run the compiled binary: 

```
./install_libraries_windows.exe
```

* Running windows_start.exe checks if you have python installed. If you do, install_libraries_windows.exe will run, and from there, init.py will run.

#### For Linux users:
<em>Please note that for Linux, the install_libraries.c source code file is still currently being worked on.</em>

##### For Ubuntu:
##### For source_code/windows_start.c
1. Compile the C program: 

```
gcc source_code/linux_start.c -o linux_start.out
```

2. Run the compiled binary: 

```
./linux_start.out
```
   
##### For Arch Linxu:
##### For source_code/windows_start.c
1. Compile the C program: 

```
gcc source_code/linux_start.c -o linux_start.out
```

2. Run the compiled binary: 

```
./linux_start.out
```

## Development Philosophy

AltiusVista is built with an emphasis on:
* Hardened Logic: Minimizing redundant operations within loops to ensure maximum efficiency.
* Surgical Precision: Targeting specific data points for visualization without unnecessary overhead.
* Analytical Stamina: Built to handle large datasets through optimized search and sort algorithms.
* The name itself means "Higher View", as Altius comes from Latin, meaning "High" or "higher", and Vista meaning "vision" or "view".
## License
This project is maintained by iiIfeiithetechnerd with an MIT License.. All rights reserved. Logic and structure are subject to continuous surgical optimization. For more information, view the License: https://github.com/iiIfeiithetechnerd/AltiusVista/blob/main/LICENSE
