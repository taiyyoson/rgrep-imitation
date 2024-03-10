# RGREP Implementation

## Brief Documentation/Context/Intro
grep is a built-in command-line utility for searching plain-text data sets for lines that match a regular expression. **rgrep** is the restricted version (r stands for restricted). To be in-depth, grep stands for global, regular expression search, and print. It can be given a file or string and asked to match it with some expression. 

There are commands aka RegEx that can act as placeholders or make grep search for various types of strings. It is a very intuitive list of regex, but I only implemented the most basic ones. 

### RegEx

I implement the following regex: `\`, which is a nullifier of other special operators, `+`, which is a special operator that searches and nullifies duplicates following the character, `.`, which acts as a placeholder for any character, and `?`, which allows either 0 or 1 duplicates to follow the character.


## Files
`Makefile`, `matcher.c`, `matcher.h`, `rgrep.c` 

`Makefile` is the file that uses the gcc compiler to run a sanity (test) check with example commands. If the rgrep is implemented correctly, then the Makefile prints "passed sanity check". I wrote all the test cases here to debug and ensure that my hardcoded special operators can handle all variations of strings. 

`matcher.c` is where I implemented rgrep. It uses a main function and a recursive sub-function to match expressions at any point in the line (it goes character-by-character, and returns true if it reaches the base case). An example of the recursion is below:
```
//special operator \ nullifies, check if char after \ is == *partial_line
	if (*pattern == '\\' && *(pattern + 1) == *partial_line)
		//increment pattern by 2 to skip \ operator
		return matches_leading (++partial_line, pattern+2);

	//special operator + increments *partial_line until *partial_line != *pattern
	if (*(pattern + 1) == '+' && *pattern == *partial_line) {
		while (*partial_line == *pattern) {
			++partial_line;
		}
		//increment patttern by 2 to skip + operator
		return matches_leading (partial_line, pattern+2);
		} 
```
Here, I implement the `+` and `\\` special operators. `\\` is a special case, but I will still use it here to show how I use recursion. If some condition is true, I will either modify the current character, or return the function and move to the next character. For reference, `partial_line` is a pointer variable that points to a char array of the original string, and `pattern` is the char array pointer that holds the regex expression.

`matcher.h` is simply a header file for `matcher.c`. It helps with organization and compiling.

`rgrep.c` is the program that calls the functions in `matcher.c`, and uses it to check expressions. It is essentially the `main` function.


## Output
<img width="898" alt="Screenshot 2024-03-09 at 10 03 01 PM" src="https://github.com/taiyyoson/rgrepImitation/assets/123409233/2ef3b4c5-0a67-47a5-9123-c7520a7cc10f">






