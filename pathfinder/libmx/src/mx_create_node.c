#include "libmx.h"

t_list *mx_create_node(void *data){
	
	t_list* head = NULL;
	head = (t_list*)malloc(sizeof(t_list));

	head->data = data;
	head->next = NULL;

	return head;
}

// int main()
// {
// 	t_list* head = mx_create_node("hello");
// 	printf("%s\n", head->data);
// 	return 0;
// }
