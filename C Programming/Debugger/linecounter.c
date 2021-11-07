#include <stdio.h>

int main() {
	int lineCount = 0;
	char currentCharacter = getchar();

	while(currentCharacter != EOF) {
		if(currentCharacter == '\n'){
			lineCount++;
		}

		currentCharacter = getchar();
	}

	printf("Line Counter: %d\n", lineCount);
	return 0;

}
