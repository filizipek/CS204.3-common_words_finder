# Common Words Finder

## By Filiz Ipek Oktay - 30780

### Overview

This C++ program utilizes stacks to identify common words between two text files. It prompts users to input file names, reads the files, and displays words that occur in both files along with their occurrence count.

### Features

- **File Input:**
  - Users provide the names of two text files.
  - The program checks file validity and opens them for processing.

- **Word Stacks:**
  - Implements a dynamic stack for storing words from each file separately.
  - Utilizes temporary stacks for proper word ordering.

- **Common Words:**
  - Determines and displays words that occur in both files.
  - Calculates the minimum occurrence count for each common word.

### Usage Instructions

1. **Compile and Run:**
   - Compile the program using a C++ compiler.
   - Run the executable to start the common words finder.

2. **File Input:**
   - Enter the names of the first and second text files when prompted.

3. **Common Words Display:**
   - The program identifies common words and displays their occurrence count.

### Implementation Details

- **Stack Class (DynStack.h):**
  - Defines a dynamic string stack for storing words.
  - Includes methods for push, pop, isEmpty, and finding common words.

- **Main Program (THE3.cpp):**
  - Reads words from each file, maintaining their original order.
  - Utilizes the stack class to find and display common words.
  - Prompts users for input and provides clear instructions.

### Notes

- Ensure file names are entered correctly.
- The program is case-sensitive.
- Feel free to explore, modify, and adapt according to your needs.

### Author

- This program was authored by Filiz İpek Oktay.
- For questions or suggestions, please contact the author.
