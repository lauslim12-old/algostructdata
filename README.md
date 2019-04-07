# Algorithms and Data Structures
My laboratory works/assignments for Algorithms and Data Structures. This whole repository was coded with C and written in Indonesian language. Feel free to take inspiration from any of my assignments.

# Architecture / Philosophies
* C Programming Language
* Minimal amount of frameworks (simple programs)
* Usage of C algorithms and data structure
* Coded in a Windows 64-bit environment

# Basic C Functions Used
* File Processing
* Pointer and Array Passing
* Structure
* Modular Programming
* Linked List: Singular Linked List, Doubly Linked List, Doubly Circular Linked List

# Algorithms Used
* Basic Sorting: Bubble Sort, Selection Sort, Insertion Sort
* Advanced Sorting: Quick Sort, Merge Sort, Shell Sort, Radix Sort
* Searching: Sequential Search, Binary Search, Interpolation Search

# Program Descriptions
* Week 2 consists of making a 3D-shape volume and area calculator. The results are then stored in a structure which you can call anytime with the history function. Featuring usage of pointers, and structures.
* Week 3 consists of two programs. The first program is a text transformator program that swaps the lowercase sentences to uppercase sentences, uppercase to lowercase sentences, and a switch function that transforms lowercase into uppercase and vice versa. The second program is a 3x3 matrix calculator. This program can multiply, add, and transpose two 3x3 matrices.
* Week 4 consists of three programs. First program is text-trasformator with memory allocation, second program is a matrix calculator with memory allocation. The final and 'big' program is a system/program to rent a room. Rent-a-room is a program which uses Single Linked Lists as its main lifeblood. You can use this program to borrow rooms, delete already borrowed rooms (for now, only deleting all is possible), and display all borrowed rooms. This program illustrates the concepts of adding, deleting, and displaying the contents of Single Linked Lists. Another feature is that you cannot borrow a room which has already been borrowed by someone else. The algorithm for not being able to borrow already borrowed room feature is quite simple but it takes time to wrap your head around it (I've been there too).
* Week 5 is an improvisation of rent-a-room program. I added a feature to delete, and approve requests to rent a room. Deleting the room is an applied concept of deleting in Linked Lists. Approving requests is just a really small feature that improves the beauty of the program.
* Week 6 has two programs. The first program is to sort data from name, weight, and height with basic sorting algorithms like bubble sort, selection sort, and insertion sort. The second program is an improvisation of the Week 5 program. The program uses radix sort to sort the identification number that was inputted in the program.
* Week 7 has a simple program that takes user's name, and 14 last grades. Then, the program will sort the data in either ascending or descending format with more advanced algorithm than Week 6's first program. The algorithms are Quick Sort, Merge Sort, and Shell Sort. The last 10 grades will be calculated and divided by 10 to show the average grade that the user gets. Finally, the program can output all the sorted data inserted into it via a Doubly Linked List.
* Week 8 has two programs. The first program is a very simple program to binary search a data from an array. The second big program is called 'activities'. The program allows you to display a list of data from a file, do ascending sort based on name a data from .txt file with different algorithms, search a data from a .txt file with different algorithms, add a new activity with a randomized ID to a .txt file.

# Installations and Usage
Copy or download the code into your Integrated Developer Environment of your choice, then build and run it. It is as simple as that.

# Bugs
* Week 6's second program radix sort is not working. I do not know why this happens, but feel free to post a pull request if you know how to solve the problem.
* Week 6's second program is unable to insert a new data if you delete the last data in the Linked List. Feel free to post a pull request if you know how to fix this.
* Week 8's activities.c's merge sort is not so efficient as it uses arrays instead of structure. If anyone knows how to pass a struct into the merge sort, then feel free to post a pull request.

# Contribution
If you have any ideas on how to improve the algorithms, feel free to submit a pull request.

# License
This repository has a MIT License.

# Changelog
### Version 1.05 - 07/04/2019
- Week 8 assignment added.
- Readme.md updated.
- Added new sections "Algorithms" and "Basic C Functions" in Readme.md.
- Updated "Architecture / Philosophies" in Readme.md.

### Version 1.04 - 16/03/2019
- Week 7 assignment added.
- Readme.md updated.

### Version 1.03 - 12/03/2019
- Week 6 assignments added.
- Readme.md updated.
- Added the new "Bugs" section in Readme.md.

### Version 1.02 - 05/03/2019
- Week 5 assignment added.
- Readme.md updated.
- Grammar fixes.

### Version 1.01 - 02/03/2019
- Week 4 assignment added.
- Readme.md updated.

### Version 1.00 - 16/02/2019
- Initial release, with Week 2 and Week 3.
