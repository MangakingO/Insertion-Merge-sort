# Sorting Performance Analyzer

**Author**: Oscar Barrios Jimenez  
**Student ID**: 1001953281  

This C program loads integers from a text file, sorts them using **both Merge Sort and Insertion Sort**, and reports the number of elements processed along with the execution time (measured in CPU clock ticks) for each algorithm.

The program is designed to handle large datasets efficiently and includes an optional array printing mode for debugging purposes.

---

## 🔧 Features

- Reads integers from a `.txt` file (one number per line)
- Sorts the data using:
  - **Merge Sort**
  - **Insertion Sort**
- Reports:
  - Number of records processed
  - Sort time (in clock ticks) for each algorithm
- Optional: Print the array before and after sorting (`-DPRINTARRAY`)
- Optimized for large input sizes (tested up to 2 million records)
- Graceful file handling and memory management

---

## 📁 Files

| File Name             | Description                            |
|----------------------|----------------------------------------|
| `Code2_1001953281.c` | Main C source code                     |
| `Makefile`           | For compiling the project easily       |

---

## 🚀 How to Compile

### 🔹 Standard build:
```bash
make

🔹 Build with array printing (for debugging):

make print

🧪 How to Run

./Code2 N1024.txt

Replace N1024.txt with the name of your own input file.
📊 Example Output

1024 records were processed
Merge Sort = 214 Tics
Insertion Sort = 1052 Tics

    The actual time in tics will vary depending on input size and system performance.

📝 Creating Your Own Input File

To run the program, you must create a text file containing a list of integers — one number per line, like this:

42
17
8
93
11

You can create this file using any text editor (e.g., Notepad, VS Code, nano) and save it with a .txt extension.
🔹 Example (N1024.txt)

If you want to test 1,024 numbers, create a file called N1024.txt with 1,024 lines. Each line should contain a single integer:

156
732
401
...

Make sure:

    There are no blank lines

    Only integers are included

    Each number is on its own line

💡 Optional Compilation Flag

You can enable array printing with a compile-time flag:

gcc -DPRINTARRAY -o Code2 Code2_1001953281.c

Or with the Makefile:

make print

This will print the full array before and after sorting (not recommended for large input files).
🧼 Clean Up

To delete the compiled executable:

make clean

📌 Notes

    The input file must be manually created by the user

    Input must follow strict format: 1 integer per line, no blank lines

    The program exits with an error if:

        The file does not exist

        Memory allocation fails

    Sorting is done separately for Merge Sort and Insertion Sort

    Execution time is measured using clock() from <time.h>

📚 License

This project was developed for coursework at the University of Texas at Arlington (UTA), for CSE 1325 - Object Oriented Programming.
