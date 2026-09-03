/**
 * @file main.cpp
 * @brief Our first baby C++ program
 *
 * This file is the first C++ code we did in class. Even though it's very small,
 * it contains several important basic features of C++.
 *
 * 1. #define: This is called a `preprocessor directive`. It is used to declare and define macros. When we
 * say #define MY_VALUE 7, before this file is compiled, the preprocessor finds all instances of "MY_VALUE"
 * in the code, and replaces it with the number `7`. If you look at the file `main.pre` and scroll to the bottom, you
 * can see the line `int v = MY_VALUE;` has been modified to `int v = 7;`. The compiler never sees `MY_VALUE`, only 7.
 *
 * 2. #include <iostream>: This is another preprocessor directive, all of which start with a `#`. #include <iostream>
 * instructs the preprocessor to find the file named `iostream`, copy its contents, and paste them over the
 * #include <iostream> command. This is typically called "including a header file", and many times the filename will
 * have an extension like `.h` or `.hpp`. We **never** want to #include files that end in `.cpp`.
 *
 * 3. int main() : every program needs a `main()` function as the entry point. It returns an int, and just having
 * `return 0;` at the end is fine.
 *
 * 4. std::cout: `cout` is an object that we use to output to the console in C++. the `std` means it is from the
 * C++ standard library, and without it, the compiler will not know what `cout` is. We also need to `#include <iostream>
 * to use `cout`. We output by placing `<<` after `cout` followed by a variable, string literal, number literal, or
 * various other things we will learn about. We can chain things together with `<<`, and `std::endl` will put a
 * new line at the end of the output.
 *
 * 5. Build process: We used this file to demonstrate the build process for C++. Roughly speaking, the steps are:
 *
 * main.cpp ->
 *              preprocessor -> main.pre ->
 *                                          compiler -> main.s
 *                                                              -> assembler -> main.o
 *                                                                                      -> linker -> a.out (executable)
 *
 *
 */
// #
#define MY_VALUE 7

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int v = MY_VALUE;

    return 0;
}
