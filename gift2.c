#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define NAMELEN 15
#define POPULATION 10

typedef struct {
	char name[NAMELEN];
	int total_money;
} NP;


NP person[POPULATION];
int num;


NP* get_node(char* from) {
	for(int j = 0; j < num; j++) 
	{
		if(strcmp(from, person[j].name) == 0) 
		{
			return &person[j];
		}
	}
	assert(0);

}

int main(void) 
{
	char p_name[NAMELEN];
	int i, k, to_n, money;
	NP *to, *from;

	
	scanf("%d", &num);
	assert(num <= POPULATION);

	for(i = 0; i < num; i++)
	{
		scanf("%s", person[i].name);
		person[i].total_money = 0;
	}	

	for(i = 0; i < num; i++) 
	{
		scanf( "%s %d %d", p_name, &money, &to_n);
		from = get_node(p_name);

		for(k = 0; k < to_n; k++) {
			scanf("%s", p_name);
			to = get_node(p_name);
			from->total_money -= (money/to_n);
			to->total_money += (money/to_n);
		}

	}
	for(i = 0; i < num; i++)
	{
		printf("%s %d\n", person[i].name, person[i].total_money); 
	}

}
