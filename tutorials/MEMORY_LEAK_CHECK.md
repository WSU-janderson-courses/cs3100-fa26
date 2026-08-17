# Checking for Memory Leaks: Dynamic Memory Allocation and You

## Overview

A memory leak occurs when you lose access to dynamically allocated memory. One likely way for this to happen is when an object that allocates memory on the stack does not release that memory when it goes out of scope. In C++, the destructor is called when an object goes out of scope, and we want to free any memory we have allocated. There are libraries that can check for memory leaks, and some IDEs can, however, this method is an easy way to make sure the destructor is working as intended.

## Loopy

If we create an object in a loop, at the end of each iteration of the loop, the destructor is called. If we do this many times, we can see if the memory our program is using remains the same, or if it blows up. Staying the same means we are correctly releasing memory. Blowing up means we have a memory leak. The loop can look like this:

```
cout << "Pre-memory leak test...";
cout << endl;

for (int i = 0; i < 100000; i++) {
    Sequence s(10);
	for (int i = 0; i < 10; i++) {
		s[i] = to_string(i);
	}
}

cout << "Post-memory leak test...";
cout << endl;
```

## Breakpoints

To see how much memory our program is taking up before and after the loop, we can set debug break points before and after the loop. I put them on the lines that have `cout << endl;`. That way I know the program is paused before the loop, and then that the loop is finished.

## Task Manager

With the program paused at the first breakpoint, open Task Manager (or equivalent on MacOS or Linux), and find your executable. In CLion, the name of your executable is located at the top in between the dropdown with `Debug` and the hammer for build. 

Note the amount of memory your program is using. On Windows, I usually see 0.5 MB. 

Now resume your program, and wait until it stops at the second break point. 

Note again how much memory your program is using. 

If it is the same or similar, within a megabyte or so, you do not have a memory leak. If the memory use increased by several megabytes, you have a memory leak. 

You can increase the number of loop iterations to see if there is a more significant change in case you are unsure.  