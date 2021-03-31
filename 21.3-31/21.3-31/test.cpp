#include<stdio.h>
void main(){
	char a[100];
	gets_s(a);
	int i;
	for (i = 0;; i++){
		if (a[i] == '\0')
			break;
		if (a[i] >= 65 && a[i] <= 90){
			a[i] += 32;
		}
		else if (a[i] >= 97 && a[i] <= 122){
			a[i] += -32;
		}
		printf("%c", a[i]);
	}
}