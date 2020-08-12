#include "libmx.h"

int mx_list_size(t_list *list) {

	t_list *clone = list;
	int result = 0;

	while(clone){
		clone = clone->next;
		result++;
	}

	return result;
}

// t_list *mx_create_node(void *data){
	
// 	t_list* head = NULL;
// 	head = (t_list*)malloc(sizeof(t_list));

// 	head->data = data;
// 	head->next = NULL;

// 	return head;
// }

// void mx_push_back(t_list **list, void *data){
	
// 	t_list* new_last = mx_create_node(data);

// 	new_last->data = data;

//     t_list *temp = *list;

//     while (temp->next != NULL) 
//         temp = temp->next;

//     temp->next = new_last;

//     	if (*list == NULL) 
//     { 
//        *list = new_last; 
//        return; 
//     }
// }

// int main(){

// 	t_list *first = mx_create_node("1");

// 	mx_push_back(&first, "2");
// 	mx_push_back(&first, "3");
// 	mx_push_back(&first, "4");

// 	int res = mx_list_size(first);

// 	while (first) {
// 		printf("%s\n", first->data);
// 		first = first->next;
// 	}

// 	printf("The number of item : %d\n", res);


// 	return 0;
// }
