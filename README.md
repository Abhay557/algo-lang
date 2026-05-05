## So what is AlgoLang?

I was being taught to write algorithms in class and I was like "Hmmm, you know what? What if I make this into a programming language? Will be kinda cool ngl, and I can make it in C++ to sort of challenge myself." So I created this repo, made a simple file loading system, and forgot about it. A week or so later I suddenly remembered about this and then pulled an all-nighter finishing it. It works pretty well and even follows the BODMAS rule for arithmetic stuff. For that, I had to learn about something called a recursive descent parser which is used in low-level compilers and stuff, so that was pretty cool. 

Actual image of an algorithm I wrote in class (ignore my handwriting, I was distracted by the pretty girl sitting near me):

<img src="for_readme/from_my_actual_notebook.jpeg" alt="algorithm" width="500"/>

### Currently Available Keywords:

* **START** - defines where the program starts
* **END** - defines where the program stops executing
* **DECLARE** - used to declare variables
* **INPUT** - input integers, floats, and strings. *(I also got dynamic variable allocation working! You just type an input and the interpreter decides on its own what kind of input it is and stores it in that variable. Pretty cool right?)*
* **OUTPUT** - output variables, integers, strings
* **GOTO** - start interpreting from a specific line
* **IF** / **ELIF** / **ELSE** - conditional branching (supports both inline checks and multi-line blocks using **ENDIF**, **ENDELIF**, and **ENDELSE**)
* **WHILE** / **ENDWHILE** - native loop blocks so you don't have to build them manually with GOTO
* **RANDOM** - use `var_name = RANDOM(lower_bound, upper_bound)` to assign a random number to a variable
* **$** - if you want to show a variable's value in output, just type it with **$** and it will show it!
  * *Example:* `var_a = 5`, `OUTPUT "value of var_a = $var_a"`, and the output will look like `"value of var_a = 5"`

### Boolean Logic
Boolean logic inside `IF`/`ELIF` and `WHILE` supports **and**, **or**, and **xor** with fixed precedence rules:
- **and/xor** are evaluated before **or**
- Operators at the same precedence are evaluated left-to-right
- Bracket/parenthesis grouping in conditions is intentionally **not** supported

---

## Examples

### Prime Number Generator
```text
START
DECLARE n, i, j, is_prime, rem
INPUT n
i = 2
IF i > n GOTO 19
j = 2
is_prime = 1
IF j == i GOTO 15
rem = i % j
IF rem == 0 GOTO 13
j = j + 1
GOTO 8
is_prime = 0
GOTO 15
IF is_prime == 0 GOTO 17
OUTPUT i
i = i + 1
GOTO 5
END
```

**Output:**

```cmd
E:\AlgoLang>algo.exe ./src/test.txt
Enter value for n: 10
>> 2
>> 3
>> 5
>> 7

E:\AlgoLang>
```

### Factorial Calculator

```text
START
DECLARE n, fact, i
INPUT n
fact = 1
i = 1
IF i > n GOTO 11
fact = fact * i
i = i + 1
GOTO 6
OUTPUT fact
END
```

**Output:**

```cmd
E:\AlgoLang>algo.exe ./src/factorial.txt
Enter value for n: 5
>> 120

E:\AlgoLang>
```

### Boolean Logic Check (`IF` & `WHILE`)
```text
START
DECLARE i

i = 0

OUTPUT "Boolean IF + WHILE demo"

// WHILE contains and/or/xor but still behaves like i < 5
WHILE i < 5 and 1 == 1 or 1 == 0 xor 1 == 0
    OUTPUT "Inside loop"

    // IF also uses and/or/xor
    IF i < 2 and 2 == 2 xor 1 == 0
        OUTPUT "IF branch (xor involved)"
    ENDIF
    ELIF i >= 2 and i < 4 or 0 == 1
        OUTPUT "ELIF branch (and/or involved)"
    ENDELIF
    ELSE
        OUTPUT "ELSE branch"
    ENDELSE

    i = i + 1
ENDWHILE

OUTPUT "Loop ended"
END
```

**Output:**

```cmd
Boolean IF + WHILE demo
>> Inside loop
>> IF branch (xor involved)
>> Inside loop
>> IF branch (xor involved)
>> Inside loop
>> ELIF branch (and/or involved)
>> Inside loop
>> ELIF branch (and/or involved)
>> Inside loop
>> ELSE branch
>> Loop ended
```

### Number Analyzer
```text
START
DECLARE num, loops
loops = 0
OUTPUT "Welcome to the Number Analyzer."

//while loop to get 3 numbers and analyze them
WHILE loops < 3
    OUTPUT "Please enter a number:"
    INPUT num
    IF num > 0
        OUTPUT "That is a POSITIVE number."
    ENDIF
    ELIF num < 0
        OUTPUT "That is a NEGATIVE number."
    ENDELIF
    ELSE
        OUTPUT "That is exactly ZERO."
    ENDELSE
    
    loops = loops + 1
ENDWHILE
//this ENDWHILE tells the interpreter that anything
//between WHILE and this falls under WHILE. it acts like {} of modern languages

OUTPUT "Analysis finished. Goodbye!"
END
```

**Output:**

```cmd
E:\AlgoLang>algo.exe ./example_code/number_analyzer.txt
>> Welcome to the Number Analyzer.
>> Please enter a number:
Enter value for num: 42
>> That is a POSITIVE number.
>> Please enter a number:
Enter value for num: -7
>> That is a NEGATIVE number.
>> Please enter a number:
Enter value for num: 0
>> That is exactly ZERO.
>> Analysis finished. Goodbye!

E:\AlgoLang>
```

### NOTICE how the Number Analyzer code is written differently

The Number Analyzer showcases AlgoLang’s move toward modern, structured programming. By replacing manual `GOTO` jumps with `WHILE` and `IF`/`ELIF`/`ELSE` blocks, the script no longer relies on fragile line-counting; instead, the engine "scans" for matching `END` tags to skip or repeat code sections automatically. 

This makes the code much more resilient—you can add blank lines or comments anywhere without breaking the logic. While our `trim()` function filters out messy spaces and tabs to keep the parser happy, the absolute "address" of a line is now irrelevant for this modern style. As long as your blocks are properly closed, the engine handles the navigation, letting you focus on the algorithm rather than the math of the line numbers. You can still use `GOTO` and stuff along with these new additions, we have kept that compatibility.

---

## Installation & Usage

To write and run your own algorithms using AlgoLang:

1. **Clone the repository** to your local machine:
   ```bash
   git clone [https://github.com/omnimistic/algo-lang.git](https://github.com/omnimistic/algo-lang.git)
   ```
2. **Navigate** to the project directory:
   ```bash
   cd algo-lang
   ```
3. **Compile the engine** (Requires a C++ compiler like GCC/MinGW):
   ```bash
   make
   ```
4. **Write your algorithm** in a `.txt` file using the keywords above. Make sure to only use one keyword per line (unless it's an inline statement). Also, if you use `GOTO`, remember that line numbers matter!
5. **Run the executable**, passing your file path as an argument:
   ```cmd
   algo.exe ./path/to/your/file.txt
   ```
   *(Note: On Mac/Linux, run `./algo ./path/to/your/file.txt`)*

---

## Contributing

Well, that's about it. Idk if I am gonna work on this anymore but y'all are free to contribute to it. It's a simple project so it will be good for new programmers instead of jumping into a complex repo.

AlgoLang is a community project! If you want to help make it a "real" language, please check out our [Contributing Guidelines](CONTRIBUTING.md) for a list of to-dos and rules for submitting Pull Requests.

## License

This project is licensed under the [MIT LICENSE](LICENSE) - see the LICENSE file for details.