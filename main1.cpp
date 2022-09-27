#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define isoCodeLen 3
#define codeLen 3
#define nameLen 1000


typedef struct region_ {
	char isoCode[isoCodeLen];
	char code[codeLen];
	char name[nameLen];

	struct region_* next_region;
} region;

int main() {
	
	const int strLen = 1024;
	const int strAmount = 20000;
	char str[strLen];
	int fieldInd = 0;
	FILE* file;

	region rList;

	//rList.isoCode[0] = '0';

	file = fopen("fips10_4.csv", "r");
	fgets(str, strLen, file);
	fgets(str, strLen, file);

	int i = 0;
	while (str[i] != ',') {
		rList.isoCode[fieldInd] = str[i];
		fieldInd++;
		i++;
	}
	rList.isoCode[fieldInd] = '\0';

	i++;
	fieldInd = 0;
	while (str[i] != ',') {
		rList.code[fieldInd] = str[i];
		fieldInd++;
		i++;
	}
	rList.code[fieldInd] = '\0';

	i++;
	fieldInd = 0;
	while (str[i] != '\0') {
		rList.name[fieldInd] = str[i];
		fieldInd++;
		i++;
	}
	rList.name[fieldInd] = '\0';

	printf("Line read from text: %s", str);
	printf("\nField iso code = %s", rList.isoCode);
	printf("\nField code = %s", rList.code);
	printf("\nField name = %s", rList.name);

	return 0;
}











//if (str[i] != ',')
//rList.isoCode[structInd] = str[i];