typedef struct v_list
{
	char *data;
	char piece;
	struct v_list *prev;
	struct v_list *next;
}x_list;

typedef struct head
{
	struct v_list *first_element;
	int lenght;
}head;

int ft_lenline(x_list *piece, int i);
