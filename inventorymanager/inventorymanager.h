#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

//Buffer costant of usr input length
#define BUFFER 100

//struct store_item
//-------------------
//Linked list data structure to 
//manage a list of store's item.
// ----------------------------
//Variables:
//Name: item's name
//Stock: amount of items
struct store_item {
	char* name;
	int stock;
	struct store_item* next;
};


//Functions managing varoius tasks on a linked list
//------------------------------------------------


/// Function: insert insert_node_to_list
/// 
/// Insert item's string name and integer stock quantity to
/// a node of the list store_item.
/// Return the pointer to the first node fo the list.
struct store_item* insert_node_to_list(struct store_item* list, char* name, int stock);


/// Function: insert insert_node_to_list
/// 
/// Print all data of invetory's items.
void print_list(struct store_item* list);


/// Function: search_into_list
/// 
/// Ask to usr what item to found, print result
/// and return pointer to the item found, used
/// for update and delete tasks.
struct store_item* search_into_list(struct store_item* list);


///Function: read_list
/// 
/// Ask to usr to input all data
/// to each node and add it to list
/// one by one.
/// Return the pointer to first node.
struct store_item* read_list();


///Function: delete_node_from_list
/// 
///Ask user what item whan to delete
///and return a pointer to the first node of the list.
///Useful if the node to delete is the first node.
struct store_item* delete_node_from_list(struct store_item* list);


///Function: update_node_list
/// 
/// Ask usr what item whant to change,
/// read new stock value and change it.
void update_node_list(struct store_item* list);


//Input functions useful to not store unwanted character(as newline character or space),
//and be able to pass pointer to string to other functions.
//-----------------------------------------------

char* readStr();

int readInt();

#endif