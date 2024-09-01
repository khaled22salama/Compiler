
# Simple Compiler Project

This project implements a basic compiler that performs lexical analysis (tokenization) and syntax analysis (parsing) for a simplified programming language. The compiler identifies keywords, operators, variables, and validates the syntax of language constructs such as variable declarations, control statements, and loops.

## Features

- **Lexical Analysis**: Tokenizes input statements into meaningful units like keywords, identifiers, operators, etc.
- **Syntax Analysis**: Checks the syntax of various programming constructs such as:
  - Variable declarations
  - If-else statements
  - While loops
  - For loops
  - Switch statements
  - Enumerations

## Files

The project consists of the following files:

- **`main.cpp`**: The entry point of the program, which takes a statement as input, tokenizes it, and parses it to check for syntax correctness.
- **`parser.h`**: Header file defining functions for syntax analysis.
- **`parser.cpp`**: Implementation of functions to check the syntax of various language constructs.
- **`scanner.h`**: Header file defining functions for lexical analysis.
- **`scanner.cpp`**: Implementation of functions to tokenize the input string.

## Setup Instructions

To run this project, follow these steps:

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yourusername/compiler-project.git
   cd compiler-project
   ```

2. **Compile the source files**:

   Use a C++ compiler (like `g++`) to compile the source files:

   ```bash
   g++ -o compiler main.cpp parser.cpp scanner.cpp
   ```

3. **Run the program**:

   Run the compiled executable and enter a statement to be analyzed:

   ```bash
   ./compiler
   ```

4. **Input Example**:

   When prompted, enter a statement like:

   ```
   Enter the statement: int x = 5;
   ```

   The program will output whether the syntax of the statement is correct or if there are any syntax errors.

## Project Structure

Here is a brief description of the core components:

- **`main.cpp`**: Handles user input, initiates tokenization, and starts parsing.
- **`scanner.h` and `scanner.cpp`**: Implements functions to identify keywords, operators, delimiters, identifiers, and numbers. The `tokenizer` function tokenizes the input string into a series of tokens.
- **`parser.h` and `parser.cpp`**: Implements functions for syntax analysis. It checks the correctness of different programming constructs such as `if-else`, `while`, `for`, `switch`, etc. The `parser_start` function reads tokens from a file and parses them.

## Examples of Supported Syntax

- **Variable Declaration**: `int x = 5;`
- **If Statement**: `if (x == 6) { y = 7; } else { y = 8; }`
- **While Loop**: `while (x < 5) { x++; }`
- **For Loop**: `for (x = 0; x < 5; x++) { x++; }`
- **Switch Statement**: `switch (x) { case 7: ... }`
- **Enum Declaration**: `enum color { RED, GREEN, YELLOW };`

## Error Handling

The compiler checks for various syntax errors, such as:

- Missing or misplaced semicolons, brackets, or braces.
- Incorrect syntax for statements like `if`, `else`, `while`, `for`, `switch`, and `enum`.
- Unexpected tokens in the input.

## Contribution

If you would like to contribute to this project, feel free to fork the repository and submit a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
