#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "BSTNode.hpp"
#include "RedBlackTree.hpp"

namespace ft
{
    template <class iter, class T>
	class bidirectionnal_iterator
	{
		public:

			typedef iter         						value_type;
			typedef std::ptrdiff_t  					difference_type;
			typedef T*   								pointer;
			typedef T& 									reference;
			typedef std::bidirectional_iterator_tag		iterator_category;
		
		protected:

			value_type _current;
		public:
		
			bidirectionnal_iterator(): _current()
			{

			}

			bidirectionnal_iterator(const bidirectionnal_iterator &x)
			{
				*this = x;
			}

			bidirectionnal_iterator(value_type x): _current(x)
			{

			}

			~bidirectionnal_iterator()
			{

			}

			value_type get_internal_pointer(void) const
			{
				return _current;
			}

			bidirectionnal_iterator &operator=(const bidirectionnal_iterator &x)
			{
				if (this != &x)
					_current = x._current;
				return (*this);
			}

			bool operator==(const bidirectionnal_iterator &x)
			{
				return (_current._node->value.first == x._current._node->value.first);
			}
	
			bool operator!=(const bidirectionnal_iterator &x)
			{
				return (_current._node->value.first != x._current._node->value.first);
			}

			reference operator*() const
			{
				return (_current._node->value);
			}

			pointer operator->() const
			{
				return (&_current._node->value);
			}

			bidirectionnal_iterator &operator++()
			{
				_current._node = _current.successor(_current._node);
				return (*this);
			}

			bidirectionnal_iterator operator++(int)
			{
				bidirectionnal_iterator tmp(*this);
				_current._node = _current.successor(_current._node);
				return (tmp);
			}

			bidirectionnal_iterator &operator--()
			{
				_current._node = _current.predecessor(_current._node);
				return *this;
			}

			bidirectionnal_iterator operator--(int)
			{
				bidirectionnal_iterator tmp(*this);
				_current._node = _current.predecessor(_current._node);
				return tmp;
			}
		};

	template <class iter, class T, class bidirectionnal_iterator>
	class const_bidirectionnal_iterator
	{
	public:
		typedef iter         					value_type;
		typedef std::ptrdiff_t  				difference_type;
		typedef T*   							pointer;
		typedef T& 								reference;
		typedef std::bidirectional_iterator_tag	iterator_category;
	protected:
		value_type _current;
	public:
		const_bidirectionnal_iterator(): _current()
		{

		}

		const_bidirectionnal_iterator(const const_bidirectionnal_iterator &x)
		{
			*this = x;
		}

		const_bidirectionnal_iterator(pointer x): _current(x)
		{

		}

		const_bidirectionnal_iterator(const bidirectionnal_iterator &other)
		{
			_current = other.get_internal_pointer();
		}

		~const_bidirectionnal_iterator()
		{

		}

		value_type get_internal_pointer(void) const
		{
			return _current;
		}

		const_bidirectionnal_iterator &operator=(const const_bidirectionnal_iterator &x)
		{
			if (this != &x)
				_current = x._current;
			return (*this);
		}

		bool operator==(const const_bidirectionnal_iterator &x) const
		{
			return (_current._node == x._current._node);
		}

		bool operator!=(const const_bidirectionnal_iterator &x) const
		{
			return (_current._node->value.first != x._current._node->value.first);
		}

		reference operator*() const
		{
			return (_current._node->value);
		}

		pointer operator->() const
		{
			return (&_current._node->value);
		}

		const_bidirectionnal_iterator &operator++()
		{
			_current._node = _current.successor(_current._node);
			return (*this);
		}

		const_bidirectionnal_iterator operator++(int)
		{
			const_bidirectionnal_iterator tmp(*this);
			_current._node = _current.successor(_current._node);
			return (tmp);
		}

	/*	const_bidirectionnal_iterator next(void)
		{
			if (_current._node->right != NULL) 
				while (_current._node->right != NULL) 
        			_current._node = _current._node->right;

			value_type y = _current._node->parent;
			while (y != NULL && _current._node->value.first == y->_node->right->value.first) {
				_current = y;
				y = y->_node->parent;
			}
			return y;
		}*/

		const_bidirectionnal_iterator &operator--()
		{
			_current._node = _current.predecessor(_current._node);
			return *this;
		}

		const_bidirectionnal_iterator operator--(int)
		{
			const_bidirectionnal_iterator tmp(*this);
			_current._node = _current.predecessor(_current._node);
			return tmp;
		}
	};
}

#endif