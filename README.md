# Garbage Collector for 42 Projects

## Overview

This project provides a garbage collector designed specifically for 42 projects. A garbage collector (GC) is a memory management tool that automatically reclaims memory that is no longer in use by the program. The GC provided here is tailored for 42 projects, ensuring efficient memory management throughout the program's execution.

## Key Features

- **Automatic memory management:** The garbage collector automatically frees memory as it becomes unreachable, ensuring efficient memory usage.
- **Cleanup on program exit:** The GC cleans up all allocated memory upon program termination, preventing memory leaks.
- **Easy integration:** To use the garbage collector, simply include the provided `.c` and `.h` files in your project and add them to your makefile.
- **Simple usage:** Replace `malloc()` calls with `gc_malloc()` to allocate memory managed by the garbage collector.
- **Manual memory release:** Use `gc_garbage()` function to force the release of memory at specific points in your code.

## Usage Instructions

1. Include the provided `.c` and `.h` files in your project.
2. Add the files to your makefile for compilation.
3. Replace `malloc()` calls in your code with `gc_malloc()` for memory allocation.
4. Include the provided header file (`gc.h`) in your code to use the garbage collector functions.
5. Optionally, replace `free()` calls with `gc_garbage()` to manually release memory.

## Implementation Details

- **Reason for not hooking `malloc()`:** The decision not to hook `malloc()` was made due to compatibility issues with tools like fsanitizer and valgrind, which have their own `malloc()` hooks. Implementing our `gc_malloc()` function ensures compatibility with these tools, allowing for effective memory leak detection during project evaluations.
- **Integration with `libft`:** It is recommended to replace `malloc()` calls with `gc_malloc()` not only in your project but also within the `libft` library for seamless memory management across all functions.

## Developers

This project was developed by **vpeinado** and **imurugar** from 42 Madrid.

---

Feel free to modify and customize this garbage collector to suit your project's needs. If you encounter any issues or have suggestions for improvements, please don't hesitate to reach out to the developers. Happy coding!
