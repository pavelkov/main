namespace structures {

template<typename ValueType> struct simple_list_node
{
	simple_list_node *next;
	ValueType data;
};

template<typename ValueType> struct simple_list
{
public:
	typedef simple_list_node<ValueType> node;
	typedef simple_list_node<ValueType> *nodeptr;

	simple_list() : head(0) { }

	bool is_empty() { return (bool) head; }



private:
	simple_list_node<ValueType> **head;
};

}
