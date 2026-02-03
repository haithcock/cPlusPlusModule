# cPlusPlusModule
This is a new repository demonstrating my knowledge in C++. This is a simple binary byte decoder. 


# Overview: 
    - This is a project written in C++ that I made to analyze binaries and return a more human readible text. This is a Byte Decoder. In reverse engineering other programs use a similar system in order to crack software, analyze malware, and other IT related forensics.
# Description
    - The program takes a file and returns its binary bytes into the output file. Any executable compiled binary should work. I tested this using .AppImages on linux and succesfully returned the compiled bytes that make up my tested .AppImage program.
# Purpose:
    - My purpose was to become more familiar with IT forensics that is used in cracking software and malware analysis. 
[Software Demo Video](https://youtu.be/hI6e8BOAClY)

# Development Environment
# tools
    -Code OSS the VS Code open source software alternative without microsoft telemetry data requirements. The operating system I used was CachyOS an ArchLinux distro. The Test file I ran was on a 
# Programming language and libraries
    -Language:C++
    -Libraries: #include <cstdint>
                #include <string>
                #include <vector>
                #include <fstream>
                #include <iostream>
                #include <iomanip>
                #include <ios>
                #include <ostream>



# Useful Websites

{Make a list of websites that you found helpful in this project}

- [C++Documentation]https://learn.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-170

- [GCC online documentation](https://gcc.gnu.org/onlinedocs/)

# Future Work

{Make a list of things that you need to fix, improve, and add in the future.}

- Add: A way to somehow scan for whole strings instead of single letters
- Improve: Testing measures on different file types. I just tested it with the most basic .bin file.
- Improve: Clean up and write better documentation. 