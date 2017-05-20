#include <stdio.h>
#include <string.h>

char word[20];
static const char ENGLISH[] = "HELLO";
static const char SPANISH[] = "HOLA";
static const char GERMAN[] = "HALLO";
static const char FRENCH[] = "BONJOUR";
static const char ITALIAN[] = "CIAO";
static const char RUSSIAN[] = "ZDRAVSTVUJTE";

int main(int argc, char *argv){
	int ncase = 1;
	while (scanf("%s",word) == 1) {
		if (strcmp (word,"#") == 0) break; 
		else if (strcmp (word,ENGLISH) == 0) printf("Case %d: ENGLISH\n",ncase); 
		else if (strcmp (word,SPANISH) == 0) printf("Case %d: SPANISH\n",ncase); 
		else if (strcmp (word,GERMAN) == 0) printf("Case %d: GERMAN\n",ncase); 
		else if (strcmp (word,FRENCH) == 0) printf("Case %d: FRENCH\n",ncase); 
		else if (strcmp (word,ITALIAN) == 0) printf("Case %d: ITALIAN\n",ncase); 
		else if (strcmp (word,RUSSIAN) == 0) printf("Case %d: RUSSIAN\n",ncase); 
		else  printf("Case %d: UNKNOWN\n",ncase); 
		ncase++;
   	}
	return 0;
}