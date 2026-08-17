# Course Guide

## CS 3100/5100 - Data Structures and Algorithms

This Course Guide contains the schedule, assignments, and weekly expectations for the course. It is updated as needed throughout the semester and should be checked regularly. I attempt to communicate if/when it is updated but it is ultimately up to you to check it.

> When in doubt, start here.

## How This Course Works

There are many parts to this course and it might seem overwhelming at first. Fortunately, the overall structure is simpler than it initially appears

- Pilot  
This is the main hub where you will access everything. It contains:
    - Slides
    - Quizzes
    - Lecture Notes (OneNote)
    - Homework Links
    - Assignment Links
    - Resources
    - Links to everything you need

- GitHub Classroom  
All Coding Assignments will be completed and submitted with GitHub Classroom. Links to those assignments will be provided in Pilot.

- zyBooks  
This course uses zyBooks as the required textbook for the course. zyBooks is web-based and homework assignments will be completed there. *Don't go straight to zyBooks and sign-up, actual instructions are found in Pilot*

- Course Repository
If you are reading this, you are in the course repository. This repo contains the Course Guide (this document) which will *guide* you through the course. See what I did there?

In this class we will program in C++. Unlike earlier courses you may have taken, there is no separate lab section for CS 3100. However, we will still be working with a similar framework of having **smaller labs** and **larger projects**. 

### Coding Assignments

If you have taken CS 1180 or CS 1181 at WSU, **Coding Assignments** are roughly analogous to the **labs** from those courses.

These are smaller assignments focused on specific programming concepts and implementation details. They typically have shorter turnaround times than Programming Projects.

Unlike some previous courses, Coding Assignments are not necessarily assigned on a strict weekly schedule. There may be weeks with multiple Coding Assignments due. Be sure to regularly check Pilot for due dates and announcements, as deadlines may occasionally shift depending on course progress.


- A1: Setup (tooling, GitHub Classroom)
- A2: Files (.h/.cpp)
- A3: Params and References
- A4: Arrays & Counting
- A5: Dice Roll Simulator
- A6: Classes
- A7: FightSim
- A8: Singly Linked List
- A9: Chaining
- A10: MiniBST

### Programming Projects

**Programming Projects** are significantly larger than Coding Assignments and emphasize program structure, abstraction, and data structure implementation.

The first project will not be assigned until several weeks into the semester. After that, projects will typically be assigned approximately every two weeks, depending on course progress.

Programming Projects require more planning and testing than Coding Assignments, so you are strongly encouraged to begin them early. Due dates for projects are generally less flexible than Coding Assignments deadlines.


- P1: Linked Sequence
- P2: Hash Table
- P3: AVL Tree
- P4: Database Design & Implementation

### Relationship Between Assignments and Projects

Many Coding Assignments are designed to directly support later Programming Projects.

In several cases, completing and understanding a Coding Assignments is effectively preparation for the corresponding project. Students who skip or rush the smaller assignments often struggle significantly more on the projects that build on them.

Examples include:

- A3 (Parameters and References) → later pointer-based data structures
- A8 (Singly Linked List) → P1 (Linked Sequence)
- A9 (Chaining) → P2 (Hash Table)

While projects may require additional design and abstraction beyond the Coding Assignments, the smaller assignments are intended to build the core mechanics incrementally.

---

## How to Use This Guide

Each week lists:

- Topics covered in class
- Assignments and projects
- Quiz Timing

Recommended workflow:

1. Attend class
2. Review examples from the course repository (you are looking at the course repository right now)
3. Complete assignments.
4. Take the weekly quiz.

---

## Course Schedule

This schedule is based on a 14-week semester. Summer semesters are 12 weeks and this outline doesn't map perfectly, but the order of the topics will be the same.

| Week | Topic                                          |
|------|------------------------------------------------|
| 1    | Intro to C++                                   |
| 2    | Parameters and References                      |
| 3    | Arrays, Loops, Randomness                      |
| 4    | Classes & Dynamic Memory                       |
| 5    | Introduction to Data Structures and Algorithms |
| 6    | Searching and Algorithm Analysis               |
| 7    | Hash Tables                                    |
| 8    | Hash Tables (cont.)                            |
| 9    | Binary Trees                                   |
| 10   | Balanced Binary Trees                          |
| 11   | Tries                                          |
| 12   | Heaps                                          |
| 13   | Graphs                                         |
| 14   | Sorting algorithms                             |
| 15   | Final Exam                                     |

## Week-by-Week Details

### Week 1 - Intro to C++

- Course expectations
- Setting up C++ environment
- Basic C++ structure and file organization

#### Coding Assignments
- A1 - Setup
    - Join GitHub Classroom
    - Environment sanity check (CLion, compile + run)
    - Commit, push
- A2 - Files
    - Split program into header and source
    - Write one function
    - Compile cleanly

---

### Week 2 - Parameters and References
- Predict whether a function can modify a variable passed to it
- Explain why a function can or cannot modify a variable to persist after function call
- Recognize difference between values vs. references vs. pointers (not master them)

#### Coding Assignments
- A3 - Parameters and References
    - See values vs. reference behavior
    - Print addresses

#### Quiz 1 (material from Week 1)
- Syntax and compilation errors
- `.h` vs. `.cpp`
- Function structure
- Compile vs. runtime errors

---

### Week 3 - Arrays, Loops, Randomness
- Arrays -> indexed storage, counting structures
- Loop driven reasoning - no guessing iterations, think it through
- Combine functions, loops, arrays into complete program

#### Coding Assignments
- A4 - Arrays & Counting
    - Count occurrences using an array
    - Fixed-size arrays
    - **No** dynamic memory
- A5 - Dice Roll Simulator

#### Quiz 2 (material from Week 2)
- Parameter passing

---

### Week 4 - Classes & Dynamic Memory
- Classes container for data + behavior
- Dynamic memory
    - stack vs. heap lifetime
    - stack memory may be insufficient for data structures, especially when data must outlive a single function call
    - Ownership intuition
    - Memory leaks

#### Coding Assignments
- A6 - Classes
    - `Character` class (HP, attack, print)
    - No combat (yet)
    - File separation (`.h` & `.cpp`)
- A7 - FightSim
    - Bring together P1 (dice rolls) and A6 (`Character` class)

---

### Week 5 - Data Structures
- Continue with coding examples, but we code a data structure
- Although I've already snuck a data structure into the first weeks. What data structure(s) did we use?

#### Coding Assignments
- A8 - Singly Linked List (SLL)
    - Part in-class, part individually

---

### Week 6 - Searching and Algorithm Analysis
- Shift from working on code to the heart of the course, why we even have different data structures and how to we compare them

#### Programming Projects
- P1 Linked Sequence
    - Doubly Linked List

---

### Week 7 - Hash Tables

#### Programming Assignments
- A9 - Chaining

---

### Week 8 - Hash Tables (cont.)

#### Programming Projects
- P2 - Hash Table

---

### Week 9 - Binary Trees

#### Programming Assignments
- A10 - MiniBST

---

### Week 10 - Balanced Binary Trees

#### Programming Projects
- P3 - AVL Tree

---

### Week 11 - Tries

--- 

### Week 12 - Heaps

#### Programming Projects
- P4.1 - Database Design

---

### Week 13 - Graphs

#### Programming Projects
- P4.2 - Database Implementation

---

### Week 14 - Graphs (cont.)

--- 

### Week 15 - Final Exam