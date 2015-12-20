#include <stdio.h>

void print(char *name, char * code, int l1, int l2){
	int i;
	for (i = 0; i < 9; i++){
		printf(" ");
	}
	for (i = 0; i < l1; i++){
		printf("%c",name[i]);
	}
	for (i = l1; i < 25; i++){
		printf(" ");
	}
	for (i = 0; i < l2; i++){
		printf("%c",code[i]);
	}
	for (i = l2; i < 4; i++){
		printf("0");
	}
	printf("\n");
}

char getCode(char c){
	char code = 0;
	switch(c){
		case 'B':
		case 'P':
		case 'F':
		case 'V':
			code = '1';
			break;
		case 'C':
		case 'S':
		case 'K':
		case 'G':
		case 'J':
		case 'Q':
		case 'X':
		case 'Z':
			code = '2';
			break;
		case 'D':
		case 'T':
			code = '3';
			break;
		case 'L':
			code = '4';
			break;
		case 'M':
		case 'N':
			code = '5';
			break;
		case 'R':
			code = '6';
			break;
		default:
			return '0';
	}
	return code;
}

int main(int argc, char* argv){
	char name[21], code[21];
	char c, lastCode = '0';
	int nameLength = 0,codeLength = 0;

	printf("         NAME                     SOUNDEX CODE\n");
	while((c = getchar()) != EOF){
		if (c == '\n'){
			print(name,code,nameLength,codeLength);
			nameLength = 0;
			codeLength = 0;
			lastCode = '0';
			continue;
		}
		name[nameLength++] = c;
		if (codeLength < 4){
			if (nameLength == 1) {
				code[codeLength++] = c;
				lastCode = getCode(c);
			} else if (c == 'A' || c == 'E' || c == 'I' 
						|| c == 'O' || c == 'U' || c == 'Y' 
						|| c == 'W' || c == 'H'){
				lastCode = '0';
			} else {
				char myCode = getCode(c);
				if (myCode != lastCode && myCode != '0') code[codeLength++] = myCode;
				lastCode = myCode;
			}
		}
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}
