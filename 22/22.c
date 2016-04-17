#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** generate_parenthesis(int left_left, int right_left,char* one_result, char** result, int* returnSize) {
	if ((0 == left_left) && (0 == right_left)) {
		char* new_result;
		new_result = (char*)malloc((strlen(one_result) + 1) * sizeof(char));
		strcpy(new_result, one_result);
		result = (char**)realloc(result, (*returnSize + 1) * sizeof(char*));
		result[*returnSize] = new_result;
		*returnSize += 1;
	}

	if (0 < left_left) {
		one_result[strlen(one_result)] = '(';
		result = generate_parenthesis(left_left - 1, right_left, one_result, result, returnSize);
		one_result[strlen(one_result) - 1] = '\0';
	}

	if (0 < right_left) {
		if (right_left > left_left) {
			one_result[strlen(one_result)] = ')';
			result = generate_parenthesis(left_left, right_left - 1, one_result, result, returnSize);
			one_result[strlen(one_result) - 1] = '\0';
		}
	}
	return result;
}

char** generateParenthesis(int n, int* returnSize) {
	char** parenthesises;
	char* one_result;
	int i, length;
	if (0 == n) {
		return NULL;
	}
	length = 2 * n + 1;
	parenthesises = (char**)malloc(sizeof(char*));
	one_result = (char*)malloc(sizeof(char) * length);
	for (i = 0; i < length; i++) {
		one_result[i] = '\0';
	}
	*returnSize = 0;
	parenthesises = generate_parenthesis(n, n, one_result, parenthesises, returnSize);
	return parenthesises;
}

int main() {
	int i, n, returnSize = 0;
	char** parenthesis;
	n = 3;
	parenthesis = generateParenthesis(n, &returnSize);
	for (i = 0; i < returnSize; i++) {
		puts(parenthesis[i]);
	}
	return 0;
}