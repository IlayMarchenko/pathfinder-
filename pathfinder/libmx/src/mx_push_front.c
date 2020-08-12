#include "libmx.h"

void mx_push_front(t_list **list, void *data){

	t_list * new_first_node = (t_list*)malloc(sizeof(t_list));

	new_first_node->data = data;

	new_first_node->next = (*list);

	(*list) = new_first_node;

}

// int main(){
//
// 	t_list *first = mx_create_node("hello");
//
// 	mx_push_front(&first, "first");
// 	mx_push_front(&first, "second");
// 	mx_push_front(&first, "s");
//
// 	while (first) {
// 		printf("%s\n", first->data);
// 		first = first->next;
// 	}
//
//
// 	return 0;
// }
