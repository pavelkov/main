#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>
#include <cassert>

namespace structures {

template <typename ValueType> struct linked_list_node
{
	ValueType value;

	linked_list_node<ValueType> *next;
};

template <typename ValueType> struct linked_list_iterator
{
public:

	typedef linked_list_iterator<ValueType> self;
	typedef ValueType value_type;
	typedef ValueType& reference;
	typedef ValueType* pointer;

	linked_list_iterator(linked_list_node<ValueType> *_link) : link(_link) {};

	reference operator *()
	{
		return link->value;
	}

	self& operator ++()
	{
		link = link->next;
		return *this;
	}

	self operator ++(int)
	{
		self tmp = *this;
		++ *this;
		return tmp;
	}

	linked_list_iterator() : link(0) {};

	linked_list_node<ValueType> *link;
};

template <typename ValueType> bool operator == (const linked_list_iterator<ValueType>& first,
	const linked_list_iterator<ValueType>& second)
	{
		return first.link == second.link;
	}

template <typename ValueType> bool operator != (const linked_list_iterator<ValueType>& first,
	const linked_list_iterator<ValueType>& second)
	{
		return first.link != second.link;
	}

template <typename ValueType> class linked_list
{
public:
	typedef ValueType value_type;
	typedef linked_list_iterator<ValueType> iterator;

	linked_list<ValueType>():begin_node(0) { }

	~linked_list()
	{
		linked_list_node<ValueType> *current_node = begin_node;

		while(current_node)
		{
			linked_list_node<ValueType> *next_node = current_node->next;
			delete current_node;
			current_node = next_node;
		}
	}

	iterator begin() { return iterator(begin_node); }

	iterator end() { return iterator(); }

	iterator insert_after(iterator pos, const ValueType& value)
	{
		linked_list_node<ValueType> *new_node = new linked_list_node<ValueType> ();
		new_node->value = value;

		if (! begin_node)
			begin_node = new_node;
		else
		{
			new_node->next = pos.link->next;
			pos.link->next = new_node;
		}

		return iterator(new_node);
	}

private:
	linked_list_node<ValueType> *begin_node;
};

}
#endif
