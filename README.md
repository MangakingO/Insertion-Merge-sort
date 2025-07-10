# Sorting Performance Analyzer

**Author**: Oscar Barrios Jimenez  
**Student ID**: 1001953281  

This C program loads integers from a text file, sorts them using **Insertion Sort**, and reports the number of elements processed along with the execution time (measured in CPU clock ticks). It also supports optional array printing before and after sorting using a preprocessor directive.

---

## 🔧 Features

- Reads integers from a `.txt` file (one number per line)
- Uses **Insertion Sort** to sort the array
- Reports number of records and sort time in clock ticks
- Optional: Print the array before and after sorting with `-DPRINTARRAY` flag
- Clean memory usage and error checking for file I/O

---

## 📁 Files

| File Name             | Description                            |
|----------------------|----------------------------------------|
| `Code2_1001953281.c` | Main source code                       |
| `TestFile.txt`       | Sample input file with integers        |
| `Makefile`           | For compiling the project easily       |

---

## 🚀 How to Compile

### 🔹 Standard build:
```bash
make
🔹 Build with array printing (for debugging):

make print

🧪 How to Run

./Code2 TestFile.txt

You can replace TestFile.txt with any other file containing integers (one per line).
🧼 Clean Up

To delete the compiled output:

make clean

📝 Example Input (TestFile.txt)

42
17
8
93
11

📌 Notes

    Make sure your input .txt file contains one integer per line.

    The program will gracefully exit if the file does not exist or memory allocation fails.

    Works with large datasets (tested up to 2 million records).

💡 Optional Compilation Flag

The code supports an optional compile-time flag:

    -DPRINTARRAY: Enables printing of the array before and after sorting.

Example:

gcc -DPRINTARRAY -o Code2 Code2_1001953281.c

📚 License

This project is for educational purposes as part of coursework in CSE at UT Arlington.
