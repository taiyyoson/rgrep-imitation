#include "matcher.h"


//helper function 1
/*recursive function matches_leading checks from some point in line (stored in partial_line)
  and if equal to pattern, keeps moving along the pattern
  accounts for all special operators*/
int matches_leading(char *partial_line, char *pattern) {
	//base case, end of pattern, meaning pattern is in line, so return true
	if (*pattern == '\0') {
		return 1;
	}

	//handling special operators (regex)

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

	//special operator ? (preceding char can show up 1 or 0 times)
	if (*(pattern + 1) == '?') {
		//if char shows up in *partial_line 1 time, then increment *partial_line 
		if (*partial_line == *pattern)
			return matches_leading (++partial_line, pattern+2);
		//if char is not in *partial_line, don't increment *partial_line
		else
			return matches_leading (partial_line, pattern+2);
	}
	//backup case for special operator ?
	if (*pattern == '?') {
		if (*(pattern - 1) == *partial_line)
			return matches_leading (++partial_line, pattern+1);
		else
			return matches_leading (partial_line, pattern+1);
	}

	//if program reaches the end of partial_line first, pattern cannot be inside line, return false
	if (*partial_line == '\0') {
		return 0;
	}

	//special operator '.', automatically == *partial_line, so increment no matter what
	if (*pattern == '.') 
		return matches_leading (++partial_line, ++pattern);

	//recursive case, if chars are equal, increment both char arrays
	else if (*partial_line == *pattern) {
		//calling matches_leading
		return matches_leading (++partial_line, ++pattern);
	}
	//if *partial_line != *pattern, return false
	return 0;
}




//main rgrep function
int rgrep_matches(char *line, char *pattern) {
	
	//case of pattern being only null terminator
	if (*pattern == '\0')
		return 1;

	//while NOT end of line
	while (*line != '\0') {

		//a couple cases for *pattern:
		//if *line == *pattern OR
		//if first char in pattern is special operator '.', automatically *line == *pattern
		//if first char in pattern is special operator '\', succeeding char (which could be anything) must == *line
		//if second char in pattern is special operator '?' but preceding char is not in line, char after '?' must == *line
		if (*line == *pattern || *pattern == '.' || (*pattern == '\\' && *(pattern + 1) == *line) || (*(pattern+1) == '?' && *(pattern+2) == *line)) {
			//if 1, the pattern is in line, return true == 1
			if (matches_leading(line, pattern) == 1)
				return 1;
		}
		//if not true (returned 0), keep incrementing line
		line++;
	}

	//end case, pattern not in line
    return 0;
}








