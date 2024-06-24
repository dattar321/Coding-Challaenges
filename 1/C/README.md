
# ccwc - Character, Word, and Line Counter

ccwc is a command-line tool inspired by the Unix `wc` utility, providing detailed information about text files:

- **Number of Bytes (-c)**: Total size of the file in bytes.
- **Number of Lines (-l)**: Number of lines present in the file.
- **Number of Words (-w)**: Total number of words (separated by spaces, tabs, newlines, or carriage returns).
- **Number of Characters (-m)**: Total number of characters (excluding newlines).

## Usage

Syntax:

```sh
./ccwc [-c|-l|-w|-m] [filename]
```

- `-c`, `-l`, `-w`, and `-m` are flags for specific counts (use only one flag at a time).
- `filename` is the path to the text file you want to analyze.
- Without arguments (flags or filename), ccwc reads from standard input (stdin). Pipe content using `cat` in such cases.

### Examples

Count lines in a file:

```sh
./ccwc -l my_file.txt
```

Count characters from standard input:

```sh
cat another_file.txt | ./ccwc -m
```

Get all counts for a file (without flags):

```sh
./ccwc my_file.txt
```

This displays the number of lines, words, bytes, and the filename.

## Running the Application

### Prerequisites

- **C Compiler**: You'll need a C compiler like GCC installed on your system.

### Compilation

1. Open a terminal or command prompt.
2. Navigate to the directory containing your `ccwc.c` file.
3. Run the following command to compile the source code into an executable:

```sh
gcc -o ccwc ccwc.c wc.c
```

### Execution

Once compilation is successful, you can run the program with:

```sh
./ccwc [arguments]
```

- `./ccwc`: Refers to the compiled executable in the current directory.
- `[arguments]`: Flags (-c, -l, -w, or -m) and/or the filename (as described in the Usage section).

## Additional Notes

- The `ccwc.h` file is assumed to contain the declarations for the counting functions (`numberOfBytes`, `numberOfLines`, `numberOfWords`, and `numberOfChars`). Ensure it's in the same directory as `ccwc.c` for successful compilation.

Feel free to adjust or expand upon this content to fit your specific project details or additional instructions.

