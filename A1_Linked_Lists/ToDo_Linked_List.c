#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_TITLE 20 
#define MAX_DESCRIPTION 50

struct ToDo {
	int ToDoId;
	char Title[MAX_TITLE];
	char Description[MAX_DESCRIPTION];
	struct ToDo* NextToDo;
};

struct ToDo* AddToDo(struct ToDo* head, int ToDoId, char Title[], char Description[]);
void FindToDoByIndex(struct ToDo* head);
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId);
void PrintToDos(struct ToDo* head);
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
			fgets(toDoTitle, MAX_TITLE, stdin);
			toDoTitle[strcspn(toDoTitle, "\n")] = 0;
			printf("Enter Description: ");
			fgets(toDoDescription, MAX_DESCRIPTION, stdin);
			toDoDescription[strcspn(toDoDescription, "\n")] = 0;

			ToDoListHead = AddToDo(ToDoListHead, toDoId, toDoTitle, toDoDescription);
			break;
		case 2:
			DeleteToDoByToDoId(ToDoListHead, toDoId);
			break;
		case 3:
			FindToDoByIndex(ToDoListHead);		
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
	   
	if (strcpy_s(NewItem->Title, MAX_TITLE, Title) != 0) {
		printf("Error copying title.\n");
		free(NewItem);
		return head;
	}
	if (strcpy_s(NewItem->Description, MAX_DESCRIPTION, Description) != 0) {
		printf("Error copying description.\n");
		free(NewItem);
		return head;
	}
	NewItem->NextToDo = head;
	printf("Successfully added item.\n");
	return NewItem;
}
void FindToDoByIndex(struct ToDo* head) {
	int id = 0;
	struct ToDo* current = head;
	printf("Enter the To Do ID: ");
	scanf_s("%d", &id);
	while ((getchar()) != '\n');
	while (current != NULL) {
		if (current->ToDoId == id) {
			printf("Match Found for ID number %d\n", id);
			printf("------------------------\n");
			printf("%d %s %s", current->ToDoId, current->Title, current->Description);
			printf("------------------------\n");
			return;
		}
		current = current->NextToDo;
	}	
	printf("No match found.\n");
}
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId) {

}
void PrintToDos(struct ToDo* head) {
	struct ToDo* currentToDo = head;

	printf("To Do List\n");
	printf("-----------------------\n");
	while (currentToDo != NULL) {
		printf("-----------------------\n");
		printf("ID: %d\nTitle: %s\nDescription: %s\n", currentToDo->ToDoId, currentToDo->Title, currentToDo->Description);
		currentToDo = currentToDo->NextToDo;
	}
}
void FreeToDoList(struct ToDo* head) {

	struct ToDo* current = head;
	struct ToDo* tempNode = NULL;

	while (current != NULL) {
		tempNode = current->NextToDo;
		free(current);
		current = tempNode;
	}

}