# CS 3100 – *Data Structures and Algorithms*

## Coding Standards

These standards apply to all C++ programs submitted in this course unless an
assignment states otherwise. Assignment-specific requirements take precedence.

Readable, well-organized code is part of a correct solution. A program is not
complete merely because it produces the expected output for one test case.

## 1. Correctness and Assignment Requirements

Before submitting a program, make sure that it:

- Compiles without errors using the compiler and project configuration required
  by the assignment.
- Runs without crashing, entering an infinite loop, locking the system, or
  producing output that does not make sense.
- Follows all requirements in the assignment handout, including required file
  names, class names, function names, parameter lists, return types, and output
  formats.
- Has been tested with normal cases and appropriate boundary cases.
- Manages memory correctly. Programs must not access invalid memory or leave
  dynamically allocated memory unaccounted for.

When the assignment specifies a name or function signature, use it **exactly as
given**. Do not rename required functions, change their parameters, or change
their return types.

If a submitted program has a known problem or limitation, document it in the
file header. Include:

- A description of the problem
- The steps taken to correct it
- Your best assessment of its possible cause

Documenting a problem does not make an incomplete or incorrect program fully
correct, but it gives the reader accurate information about the state of the
submission.

## 2. File Organization

Each source or header file should be arranged in a clear, predictable order.
Include the following elements when they apply:

1. A file header comment containing your name, the assignment or project name,
   the file name, and a brief description of the file's purpose
2. `#include` directives
3. Named constants and any global variables, with comments explaining their
   purpose
4. Class and function declarations, when appropriate
5. Function definitions, each preceded by a function comment
6. The `main` function, preceded by a function comment

### File Header Example

```cpp
// -----------------------------------------------------------------------------
// Name: Student Name
// Project: Project 1 - Example Project
// File: main.cpp
// Description: Reads card data and calculates the damage for each turn.
//
// Known issues: None.
// -----------------------------------------------------------------------------
```

### Header and Source Files

When a project uses separate header and source files:

- Place declarations in the appropriate `.h` file.
- Place function definitions in the corresponding `.cpp` file.
- Do not `#include` a `.cpp` file.
- Prevent a header from being included more than once by using `#pragma once`
  or an include guard.

### Global Variables

Avoid global variables unless they are explicitly required or clearly
appropriate. Information should normally be passed to a function through its
parameters and returned through its return value.

If a global constant or variable is used, place it near the beginning of the
file and include a comment explaining its purpose. Any function that changes a
global variable must document that change as a side effect.

## 3. Functions

### Keep Functions Small and Focused

Each function should perform one clear task. Its code should generally fit on a
single screen. Approximately 50 lines should be treated as the upper limit for
a function.

When a function becomes too long or performs several distinct tasks, divide it
into smaller helper functions. Small functions are easier to understand, test,
debug, and reuse.

Avoid duplicating the same logic in several places. If a meaningful block of
code is repeated, consider moving it into a function.

### Document Every Function

Every student-written function, including `main`, must be preceded by a block
comment that identifies:

- The function's purpose
- Every parameter, including its name, type, and meaning
- The return type and meaning of the returned value
- Any side effects, such as modifying an object passed by reference or changing
  a global variable
- Any known bugs or limitations

Write `None` when a category has no applicable information and including the
category makes the documentation clearer.

### Example of a Well-Documented Function

```cpp
// -----------------------------------------------------------------------------
// cardDamage: Adjusts the damage accumulated during the current turn according
//             to the modifier on a card.
//
// Parameters:
//    card (const std::string&) - The card whose modifier will be applied
//    baseDamage (int)          - The damage accumulated before this card
//
// Returns:
//    int - The damage after applying the card's modifier
//
// Side effects: None.
// Known bugs or limitations: None.
// -----------------------------------------------------------------------------
int cardDamage(const std::string& card, int baseDamage) {
    const std::string cardType = getCardType(card);

    // Add the card's bonus to the damage accumulated so far.
    if (cardType == "bonus") {
        const int cardBonus = getBonus(card);
        return baseDamage + cardBonus;
    }

    // Double the accumulated damage for a multiplier card.
    if (cardType == "x2") {
        return baseDamage * 2;
    }

    // A null card cancels all damage for the turn.
    if (cardType == "Null") {
        return 0;
    }

    // An unmodified card leaves the accumulated damage unchanged.
    return baseDamage;
}
```

## 4. Comments

Comments should help a reader understand the design and reasoning of the
program. They should not merely translate each line of C++ into English.

### Use Inline Comments Purposefully

Use inline comments to:

- Introduce each major logical section or block of code
- Explain an algorithm or decision that is not immediately obvious
- Clarify a particularly complex expression or operation
- Explain why unusual code is necessary

Use inline comments sparingly in straightforward procedural code. Avoid
comments that repeat information already obvious from meaningful names and
clear code.

```cpp
// Update the best result only after examining the complete candidate path.
if (currentDistance < shortestDistance) {
    shortestDistance = currentDistance;
}
```

Keep comments accurate. When code changes, update or remove comments that no
longer describe it correctly.

## 5. Indentation and Spacing

### Indent Consistently

Each function, loop, `if` statement, `switch` statement, and other control
construct introduces a new indentation level.

- Use at least three spaces for each indentation level; four spaces are
  recommended.
- Use the same indentation width throughout the program.
- Do not mix tabs and spaces in the same file.
- Align braces consistently.

```cpp
if (isValid) {
    for (int index = 0; index < itemCount; index++) {
        process(items[index]);
    }
}
```

### Use Whitespace to Improve Readability

Use spaces to separate variables, operators, and other syntactic elements. Use
blank lines to separate major sections of code.

```cpp
x=2*x+y;          // Hard to read
x = 2 * x + y;    // Easier to read
```

Do not add spaces merely to create decorative alignment that will be difficult
to maintain.

### Keep Lines a Reasonable Length

Lines longer than approximately 80 characters should be split when doing so
improves readability.

```cpp
const double averageTravelTime =
    totalTravelTime / static_cast<double>(tripCount);
```

## 6. Naming Conventions

### Use Meaningful English Names

Names should describe the information represented by a variable or the action
performed by a function.

```cpp
int numberOfStudents;
double averageScore;
bool containsKey(const std::string& key);
```

Avoid vague names such as `data`, `thing`, `temp`, or `value` when a more
specific name is available. Single-letter names such as `i`, `j`, and `z`
should normally be limited to short, simple loop indexes.

### Use One Style for Multiword Names

Use either camel case or underscores for multiword names. Do not switch between
the two styles within the same program.

```cpp
maximumWordLength  // camel case
maximum_word_length  // underscores
```

Follow any naming style required by the assignment, starter code, or existing
project.

### Use Abbreviations Sparingly

Use an abbreviation only when its meaning will be clear to the reader. Common
abbreviations such as `num` for "number" may be reasonable, but a complete word
is preferable when it makes the name clearer.

Avoid reusing a variable for an unrelated purpose. If unusual circumstances
make reuse necessary, include a comment explaining the change in meaning.

### Use Named Constants

Do not scatter unexplained literal values throughout the program. Give a value
a meaningful constant name when its purpose would otherwise be unclear or when
the same value is used in several places.

```cpp
constexpr int INITIAL_BUCKET_COUNT = 8;
```

## 7. General Code Quality

- Initialize variables before using them.
- Give each variable the smallest practical scope.
- Use braces consistently for the bodies of functions, loops, and conditional
  statements.
- Remove unused variables, unreachable code, temporary debugging output, and
  commented-out code before submitting.
- Prefer clear code over clever code. A straightforward solution that can be
  explained and maintained is better than a shorter but obscure solution.
- Do not ignore warnings that indicate a possible correctness problem.

## 8. Testing Before Submission

Do not rely on a single successful run. Test cases should include, when
applicable:

- Typical input
- Empty input or an empty data structure
- A data structure containing one element
- Minimum and maximum permitted values
- Duplicate values
- Operations performed at the beginning, middle, and end of a structure
- Invalid input when the assignment requires the program to handle it

Before submitting, perform a clean build and run the program using the required
project configuration.

## Submission Checklist

- [ ] Every required file is present and correctly named.
- [ ] The program compiles without errors.
- [ ] The program follows the assignment's required interfaces and output
      format.
- [ ] The program has been tested with normal and boundary cases.
- [ ] Every file has an appropriate file header comment.
- [ ] Every student-written function has the required function comment.
- [ ] Major logical sections are explained where necessary.
- [ ] Names, indentation, spacing, and braces are consistent.
- [ ] Lines are kept to a reasonable length.
- [ ] Debugging code and unused code have been removed.
- [ ] Any known problems are described accurately in the file header.
