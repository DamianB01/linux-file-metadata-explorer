# Linux File Metadata Explorer

A lightweight, high-performance C command-line tool designed to recursively explore directories, analyze files, and inspect filesystem metadata on Linux systems.

## Features

- **Metadata Inspection:** View critical file status details including size, type, and permissions.
- **Recursive Directory Exploration:** Efficiently crawl directory structures to catalog files.
- **Formated Output:** Clean and structured console printing for easy text analysis.
- **Lightweight & Fast:** Written in pure C using native Linux system calls for optimal performance.

## Project Structure

- `main.c` - Application entry point and CLI argument handling.
- `catalog_rec.c` / `.h` - Logic for recursive directory traversal and cataloging.
- `file_print.c` / `.h` - Formatting and printing utilities for file metadata.
- `file_type.c` / `.h` - File type identification helpers.
- `CMakeLists.txt` - Build configuration file.

## Compilation & Installation

```bash
gcc -Wall -Wextra -std=c11 -D_DEFAULT_SOURCE -o program5 main.c file_type.c file_print.c catalog_rec.c
```
<img width="746" height="45" alt="Zrzut ekranu 2026-06-27 235751" src="https://github.com/user-attachments/assets/5892f665-2fbf-4dd7-9e08-75a7d621bea2" />


---

## Testing & Usage Examples

After a successful compilation, you can verify and test the tool with the following scenarios:

### Test 1: Single Regular File
Analyze the metadata of a standard file.
```bash
./program5 kalkulator.py
```
<img width="359" height="126" alt="Zrzut ekranu 2026-06-27 235952" src="https://github.com/user-attachments/assets/831bf5a8-bbe5-4919-8759-714aa91bba97" />


### Test 2: Two Arguments (Regular File & Symbolic Link)
Pass multiple paths to check both a regular file and a symbolic link shortcut.
```bash
./program5 duzy1.txt link1
```
<img width="370" height="226" alt="Zrzut ekranu 2026-06-28 000437" src="https://github.com/user-attachments/assets/4505417d-1b91-4046-b5e1-501df32bf4ab" />


### Test 3: Three Arguments (Character Device, Named Pipe/FIFO & Directory)
Test how the application handles distinct Linux file types simultaneously.
```bash
./program5 /dev/null queue Documents
```
<img width="408" height="473" alt="Zrzut ekranu 2026-06-28 000703" src="https://github.com/user-attachments/assets/0d4443e7-ced8-4b00-8572-e4159995aab3" />


### Test 4: No Arguments (Recursive Current Directory Scan)
Run the explorer without any inputs to recursively catalog the current working directory.
```bash
./program5
```
<img width="470" height="762" alt="Zrzut ekranu 2026-06-28 000753" src="https://github.com/user-attachments/assets/0dfa9164-76dd-486b-a384-e28663414dcb" />


### Expected Output Format

The tool displays structured block of information for each file/path analyzed:

- **File Name**
- **File Type** (Regular file, Directory, Symbolic link, Character device, FIFO, etc.)
- **Size** (in bytes)
- **Inode Number** (unique filesystem identifier)
- **Last Access Time** (atime)
- **Last Modification Time** (mtime)

## License

This project is open-source. Feel free to use, modify, and distribute it.
