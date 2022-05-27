#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct movie {
	char* name;
	char* director;
	char* genre;
	double* vote;
	struct movie* next;
};

#define BUFFER 100

char* readStr();
double* readDouble();

void insert_to_list(struct movie **list);
void print_list(struct movie* list);
void delete_node_from_list(struct movie** list);

int main() {
	
	struct movie *movie_catalogue = NULL;

	insert_to_list(&movie_catalogue);
	print_list(movie_catalogue);
	delete_node_from_list(&movie_catalogue);
	print_list(movie_catalogue);

	return 0;
}


char* readStr() {
	char* newStr = malloc(BUFFER + 1);
	if (newStr == NULL) return NULL;

	fgets(newStr, strlen(newStr), stdin);
	newStr[strlen(newStr) - 1] = '\0';

	return newStr;
}

double* readDouble() {
	char* newStr = malloc(BUFFER + 1);
	if (newStr == NULL) return NULL;

	double* number = malloc(sizeof(*number));
	if (number == NULL) return NULL;

	fgets(newStr, strlen(newStr), stdin);
	newStr[strlen(newStr) - 1] = '\0';

	*number = strtod(newStr, NULL);
	free(newStr);
	return number;
}

void insert_to_list(struct movie **list){


	while (true) {
		printf("Insert movie name, director, genre, vote (name q to exit): \n");
		char* name = readStr();
		if (strcmp(name, "q") == 0) break;

		struct movie* new_node = malloc(sizeof(*new_node));
		if (new_node == NULL) return NULL;

		char* director = readStr();
		char* genre = readStr();
		double* vote = readDouble();

		//add data to node
		new_node->name = name;
		new_node->director = director;
		new_node->genre = genre;
		new_node->vote = vote;
		new_node->next = *list;

		*list = new_node;
	}

}

void print_list(struct movie* list) {
	printf("%-8s%-8s%-8s%8s\n", "NAME", "DIRECTOR", "GENRE", "VOTE");
	while (list != NULL) {
		printf("%-8s%-8s%-8s%8.1f\n", list->name, list->director, list->genre, *list->vote);
		list = list->next;
	}
}

void delete_node_from_list(struct movie** list) {
	struct movie* prev = NULL;
	struct movie* curr = *list;

	printf("insert name movie to delete\n");
	char* nameMovieToDel = readStr();
	
	while (curr != NULL && (strcmp(curr->name, nameMovieToDel) != 0)) {
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL) {
		*list = curr->next;
	}
	else {
		prev = curr->next;
	}

	free(nameMovieToDel);
	nameMovieToDel = NULL;
	free(curr);
}