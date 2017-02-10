#include<iostream>
#include<string.h>
#include<conio.h>
#include "formato.h"

using namespace std;

int main() 
	{
		char tableSign[6][6];		
		inizializateMatrix(tableSign);
		
		openFile(tableSign);		
		printTable(tableSign);
		modTable(tableSign);			
	}
