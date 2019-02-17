#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int ct=1;
	char s[20];

	while(true)
	{
		scanf("%s",s);
		if(!strcmp(s,"#")) return 0;

		printf("Case %d: ",ct++);
		if(!strcmp(s,"HELLO")) printf("ENGLISH\n");
		else if(!strcmp(s,"HOLA")) printf("SPANISH\n");
		else if(!strcmp(s,"HALLO")) printf("GERMAN\n");
		else if(!strcmp(s,"BONJOUR")) printf("FRENCH\n");
		else if(!strcmp(s,"CIAO")) printf("ITALIAN\n");
		else if(!strcmp(s,"ZDRAVSTVUJTE")) printf("RUSSIAN\n");
		else printf("UNKNOWN\n");
	}

	return 0;
}
