<p align="center">
  <img src="./for_readme/contri.gif" alt="Pixel Art Header" width="100%">
</p>

---

## Contributing to AlgoLang

First off, thanks for taking the time to contribute! AlgoLang started as a personal challenge to turn classroom algorithms into a real working language, and it's awesome to see others interested in building it further.

Since this project is built to be beginner-friendly, we want to keep the code clean and the process simple.

## How Can I Help?

We have a list of features we want to add to make AlgoLang a "real" language:

- [ ] **String Concatenation**: Enable space-separated output logic (e.g., `OUTPUT "The result is " result`) to allow mixing strings and variables on one line.
- [x] **Boolean Logic**: Support `AND` / `OR` in `IF` and `WHILE` statements for more complex conditions.
- [x] **Randomization**: Add a `RANDOM` keyword to generate numbers (e.g., `a_var = RANDOM(1, 100)` assigns a random integer between 1 and 100).
- [ ] **SLEEP Command**: A way to pause execution for a specific duration (e.g., `SLEEP 500` for 500 milliseconds).
- [ ] **Better Error Handling**: Implement more descriptive messages for syntax errors so users know exactly which line caused a crash.

## The Contribution Process

1. **Fork** the repository and create your branch from `main`.
2. **Implement** your changes in the appropriate files within the `src/` and `include/` directories. *(e.g., math and syntax logic goes in `parser.cpp`, command execution goes in `evaluator.cpp`, and jump targets go in `control_flow.cpp`).*
3. **Comment** your code. Try to keep the style consistent with our current "low-level" explanation style.
4. **Compile** your changes using the provided Makefile by running `make` in your terminal. *(Requires a C++ compiler like GCC or Clang).*
5. **CRITICAL: Test Your Changes!** Before submitting a Pull Request, you **must** run every script in the `/example_code` folder.
   - If your changes break the legacy `GOTO` examples or the modern `WHILE` blocks, please fix them before submitting.
   - Also include a new `script` in the `/example_code` folder to test the feature that you have implemented.
6. **Open a Pull Request** with a clear description of what you added or fixed.

## Coding Standards

- **Keep it Simple**: Avoid overly complex C++ templates if a simple loop or conditional works.
- **Maintain Structure**: Since we use a multi-file architecture, please ensure new functions and variables are placed in their correct modules rather than dumping everything into `main.cpp`.
- **Don't break the parser**: Ensure that the core expression evaluation (BODMAS/PEMDAS) still works flawlessly after your changes.

## Bug Reports

If you find a bug (like an infinite loop or a math error), please open an **Issue** and include:
- The AlgoLang code that caused the crash.
- What you expected to happen vs. what actually happened.

Happy Coding!
