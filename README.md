# RGREP Implementation

## Brief Documentation/Context/Intro
grep is a built-in command-line utility for searching plain-text data sets for lines that match a regular expression. **rgrep** is the restricted version (r stands for restricted). To be in-depth, grep stands for global, regular expression search, and print. It can be given a file or string and asked to match it with some expression. 

There are commands aka RegEx that can act as placeholders or make grep search for various types of strings. It is a very intuitive list of regex, but I only implemented the most basic ones. 

### RegEx

I implement the following regex: `\`, which is a nullifier of other special operators, '+', which is a special operator that searches and nullifies duplicates following the character, '.', which acts as a placeholder for any character, and '?', which allows either 0 or 1 duplicates to follow the character.
