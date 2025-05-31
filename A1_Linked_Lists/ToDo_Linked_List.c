#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE 20 
#define MAX_DESCRIPTION 50

struct ToDo {
	int ToDoId;
	char Title[MAX_TITLE];
	char Description[MAX_DESCRIPTION];
	struct ToDo* NextToDo;
};

struct ToDo* AddToDo(struct ToDo* head, int ToDoId, char Title[], char Description[]);
struct ToDo* FindToDoByIndex(struct ToDo* head, int ToDoId);
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId);
struct ToDo* PrintToDos(struct ToDo* head);
void FreeToDoList(struct ToDo* head);


int main(void) {
	int userInput = 0;
	struct ToDo* ToDoListHead = NULL;
	int toDoId = 0;
	char toDoTitle[MAX_TITLE] = { 0 };
	char toDoDescription[MAX_DESCRIPTION] = { 0 };
	while (1) {
		printf("\nMENU\n");
		printf("Select an option\n");
		printf("Press 1 to add todo item\n");
		printf("Press 2 to Delete todo item\n");
		printf("Press 3 to find todo item\n");
		printf("Press 4 to print todo list\n");
		printf("Press 5 to exit\n");
		printf("Enter Number: ");
		scanf_s("%d", &userInput);

		switch (userInput) {
		case 1:
			printf("Adding new Item\n");
			printf("Enter List ID: ");
			scanf_s("%d", &toDoId);
			while ((getchar()) != '\n');
			printf("Enter Title: ");
			scanf_s("%[^\n]19s", &toDoTitle, MAX_TITLE);
			printf("Enter Description: ");
			scanf_s("%[^\n]49s", &toDoDescription, MAX_DESCRIPTION);

			AddToDo(ToDoListHead, toDoId, toDoTitle, toDoDescription);
			break;
		case 2:
			FindToDoByIndex(ToDoListHead, toDoId);
			break;
		case 3:
			DeleteToDoByToDoId(ToDoListHead, toDoId);
			break;
		case 4:
			PrintToDos(ToDoListHead);
			break;
		case 5:
			printf("Program Exiting...");
			FreeToDoList(ToDoListHead);
			return 0;
		default:
			printf("Please select a valid option");
		}

	}

	return 0;
}

struct ToDo* AddToDo(struct ToDo* head, int ToDoId, char Title[], char Description[]) {
	//create space in memory for new node
	struct ToDo* NewItem = (struct ToDo*)malloc(sizeof(struct ToDo));
	if (NewItem == NULL) {
		printf("Memory full.");
		exit(EXIT_FAILURE);
	}

	NewItem->ToDoId = ToDoId;
	NewItem->Title[MAX_TITLE - 1] = Title;
	NewItem->Description[MAX_DESCRIPTION - 1] = Description;
	NewItem->NextToDo = NULL;
	printf("Successfully added item.\n");
	return NewItem;
}
struct ToDo* FindToDoByIndex(struct ToDo* head, int ToDoId) {

}
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId) {

}
struct ToDo* PrintToDos(struct ToDo* head) {

}
void FreeToDoList(struct ToDo* head) {

	struct ToDo* current = head;
	struct ToDo* tempNode;

	while (current != NULL) {
		tempNode = current->NextToDo;
		free(current);
		current = tempNode;
	}

}