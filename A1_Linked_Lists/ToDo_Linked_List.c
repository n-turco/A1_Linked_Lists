#include <stdio.h>
#include <stdlib.h>

struct ToDo {
	int ToDoId;
	char Title[20];
	char Description[50];
	struct ToDo* NextToDo;
};

struct ToDo* AddToDo(struct ToDo* head, int ToDoId, char Title[], char Description[]);
struct ToDo* FindToDoByIndex(struct ToDo* head, int ToDoId);
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId);
struct ToDo* PrintToDos(struct ToDo* head);


int main(void) {
	int userInput = 0;
	struct ToDo* ToDoList = NULL;
	while (1) {
		printf("\nMENU\n");
		printf("Select an option\n");
		printf("Press 1 to add todo item\n");
		printf("Press 2 to Delete todo item\n");
		printf("Press 3 to find todo item\n");
		printf("Press 4 to print todo list\n");
		printf("Press 5 to exit\n");

		scanf_s("%d", & userInput);
		getchar();

		switch (userInput) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
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
	NewItem->Title[20] = Title;
	NewItem->Description[50] = Description;
	NewItem->NextToDo = NULL;

	return NewItem;
}
struct ToDo* FindToDoByIndex(struct ToDo* head, int ToDoId) {

}
struct ToDo* DeleteToDoByToDoId(struct ToDo* head, int ToDoId) {

}
struct ToDo* PrintToDos(struct ToDo* head) {

}