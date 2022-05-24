//inventorymanager.c
//Insertion, searching, update, delection and printing tasks 
//for managing a store inventory of items, using linked list data structure.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "inventorymanager.h"


int main() {

	printf("STORE INVENTORY MANAGER\n");
	printf("Type menu numbers to do tasks on inventory (0 to exit)\n");

	struct store_item* inventory = NULL;
	while (true) {
		printf("1 - Insert items to the invetory.\n");
		printf("2 - Search an item in the invetory.\n");
		printf("3 - Update stock's item in the invetory.\n");
		printf("4 - Delete an item from the invetory.\n");
		printf("5 - Print all item's invetory.\n");
		printf("0 - Exit.\n\n");

		printf("Insert command: ");
		int menuCode = readInt();

		if (menuCode == 0) break;
		switch (menuCode) {
		case 1: inventory = read_list();
				break;
		case 2: search_into_list(inventory);
				break;
		case 3: update_node_list(inventory);
				break;
		case 4: inventory = delete_node_from_list(inventory);
				break;
		case 5: print_list(inventory);
				break;
		default: printf("Command not valid\n");
		}
	}

	return 0;
}



//FUNCTIONS DEFINITIONS
//---------------------

struct store_item* insert_node_to_list(struct store_item* list, char* name, int stock) {

	//le variabili puntatore hanno automatic storage duration
	struct store_item* new_node = malloc(sizeof(struct store_item)); // segno = nei puntatori significa punta a
	if (new_node == NULL) return NULL;

	new_node->name = name;
	new_node->stock = stock;
	new_node->next = list; //questo punta a dove punta list

	return new_node; //devo ritornare il valore di new_node perché non posso far puntare il nodo della lista del chiamante al nuovo nodo da dentro la funzione perché list é una copia (list = new_node non funziona)
}


void print_list(struct store_item* list) { //variabile list in se è una copia
	printf("%-12s%-s\n", "NAME", "STOCK");
	while (list != NULL) {
		printf("%-12s%-d\n", list->name, list->stock);
		list = list->next;
	}
	printf("\n");
}


struct store_item* search_into_list(struct store_item* list) {
	char* nameItemToFound = NULL;
	printf("Insert item's to search: ");
	nameItemToFound = readStr();

	while (list != NULL && (strcmp(list->name, nameItemToFound) != 0)) {
		list = list->next;
	}
	if (list == NULL) {
		printf("%s not found in the list.\n\n", nameItemToFound);
	} else {
		printf("Item founded.\n");
		printf("%s %d\n\n", list->name, list->stock);
	}

	free(nameItemToFound);
	return list; //ritorna la posizione del nodo trovato o null se non ha trovato niente
}


struct store_item* read_list() {

	struct store_item* new_list = NULL;
	char* name = NULL;
	int stock = 0;

	printf("INSERT ITEM' S NAME AND STOCK QUANTITY (type q to quit)\n");
	while (true) {
		printf("Name?: ");
		name = readStr();
		if (strcmp(name, "q") == 0) break;

		printf("Stock quantity?: ");
		stock = readInt();
		printf("\n");

		new_list = insert_node_to_list(new_list, name, stock);
	}
	

	return new_list;
}


struct store_item* delete_node_from_list(struct store_item* list) {
	struct store_item* prev_node = NULL;
	struct store_item* curr_node = list;

	struct store_item* itemToDelPos = search_into_list(list);

	while (curr_node != NULL && (strcmp(curr_node->name, itemToDelPos->name) != 0)) {
		prev_node = curr_node;
		curr_node = curr_node->next;
	}

	//if nothing is found
	if (curr_node == NULL) return list; 

	//if node to delete is first node
	if (prev_node == NULL) {
		list = curr_node->next;//questa modifica non è direttamente sul puntatore ma sulla copia fatta quando passato come parametro. la variabile puntatore list sparisce quando funzione termina (è una copia del valore che contiente il "vero" puntatore(memaddress list1)). quindi il bisogno di fare return list è per assegnarlo fuori la funzione
	} else {
		prev_node->next = curr_node->next;
	}

	//dealloc founded node
	free(curr_node);
	return list; 
}


void update_node_list(struct store_item* list) {

	struct store_item* itemToUpdPos = search_into_list(list);

	if (itemToUpdPos != NULL) {
		printf("Insert stock quantity to update: ");
		int updStock = readInt();
		itemToUpdPos->stock = updStock;
		printf("Item updated.\n");
	} else printf("Item not updated.\n");
}



char* readStr() {
	char* newStr = malloc(BUFFER + 1);
	if (newStr == NULL) return NULL;

	fgets(newStr, strlen(newStr), stdin);
	newStr[strlen(newStr) - 1] = '\0';

	return newStr;
}

int readInt() {
	int integer = 0;
	char* newStr = malloc(BUFFER + 1);
	if (newStr == NULL) return NULL;

	fgets(newStr, strlen(newStr), stdin);
	newStr[strlen(newStr) - 1] = '\0';
	
	integer = atoi(newStr);
	free(newStr);
	return integer;
}