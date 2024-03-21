// ContactsBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

#define EOT -1;

struct BelRow
{
	char Name[12];
	char Fam[15];
	unsigned long Tel;

};

class Bel
{
	BelRow Table[100];
	int TableEnd;
	int CurrentRecord;

public:

	Bel() 
	{
		TableEnd = 0;
	}

	int Append(const char* Name, const char* Fam, unsigned long Tel);
	BelRow* FindRowByName(const char* Name);
	void First();
	int Next();
	int Prev();
	void Last();
	BelRow* Get();


};

int Bel::Append(const char *Name, const char *Fam, unsigned long Tel)
{
	if (TableEnd >= 100)
		return 0;
	strcpy_s(Table[TableEnd].Name, Name);
	strcpy_s(Table[TableEnd].Fam, Fam);
	Table[TableEnd].Tel = Tel;
	TableEnd++;
	return 1;

}

BelRow* Bel::FindRowByName(const char* Name)
{
	for (int i = 0; i < TableEnd; i++)
	{
		if (!strcmp(Table[i].Name, Name)) return &Table[i];
		
	}
	return NULL;
}

void Bel::First()
{
	CurrentRecord = 0;
}

int Bel::Next()
{
	if (TableEnd == 100)
	{
		return EOT;
	}
	else
	{
		CurrentRecord++;
		return CurrentRecord;
	}
}

int Bel::Prev()
{
	if (CurrentRecord == 0)
	{
		return EOT;
	}
	else
	{
		CurrentRecord--;
		return CurrentRecord;
	}

}

void Bel::Last()
{
	CurrentRecord = (TableEnd - 1);
}

BelRow* Bel::Get()
{
	return &Table[CurrentRecord];
}

int main()
{
	Bel Tef;
	Tef.Append("Ivan", "Petrov", 156165);
	Tef.Append("Georgi", "Ivanov", 45243);
	Tef.Append("Peter", "Petrov", 5435455);
	Tef.Append("Naum", "Shopov", 75875);
	Tef.Append("Stoyan", "Stoyanov", 35265);

	BelRow* p;
	
	

	Tef.First();
	Tef.Next();
	Tef.Next();
	Tef.Prev();
	Tef.Last();
	Tef.First();
	p = Tef.Get();

	

	if (p)
	printf("\nName = %s \nFam = %s \nTel = %lu\n", p->Name, p->Fam, p->Tel);
	else
	printf("Error");


}
