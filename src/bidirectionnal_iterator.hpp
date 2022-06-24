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

			value_type *_ptr;
		public:
		
			bidirectionnal_iterator(): _ptr(nullptr)
			{

			}

			bidirectionnal_iterator(const bidirectionnal_iterator &x)
			{
				*this = x;
			}

			bidirectionnal_iterator(value_type *x): _ptr(x)
			{

			}

			~bidirectionnal_iterator()
			{

			}

			value_type *get_internal_pointer(void) const
			{
				return _ptr;
			}

			bidirectionnal_iterator &operator=(const bidirectionnal_iterator &x)
			{
				if (this != &x)
					_ptr = x._ptr;
				return (*this);
			}

			bool operator==(const bidirectionnal_iterator &x)
			{
				return (_ptr == x._ptr);
			}
	
			bool operator!=(const bidirectionnal_iterator &x)
			{
				return (_ptr != x._ptr);
			}

			reference operator*() const
			{
				return (_ptr->_node->value);
			}

			pointer operator->() const
			{
				return (&_ptr->_node->value);
			}

			bidirectionnal_iterator &operator++()
			{
				_ptr = _ptr->successor(_ptr->_node);
				return (*this);
			}

			bidirectionnal_iterator operator++(int)
			{
				bidirectionnal_iterator tmp(*this);
				_ptr = _ptr->successor(_ptr->_node);
				return (tmp);
			}

			bidirectionnal_iterator &operator--()
			{
				_ptr->_node = _ptr->predecessor(_ptr->node);
				return *this;
			}

			bidirectionnal_iterator operator--(int)
			{
				bidirectionnal_iterator tmp(*this);
				_ptr->_node = _ptr->predecessor(_ptr->node);
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
		value_type *_ptr;
	public:
		const_bidirectionnal_iterator(): _ptr(nullptr)
		{

		}

		const_bidirectionnal_iterator(const const_bidirectionnal_iterator &x)
		{
			*this = x;
		}

		const_bidirectionnal_iterator(pointer x): _ptr(x)
		{

		}

		const_bidirectionnal_iterator(const bidirectionnal_iterator &other)
		{
			_ptr = other.get_internal_pointer();
		}

		~const_bidirectionnal_iterator()
		{

		}

		value_type *get_internal_pointer(void) const
		{
			return _ptr;
		}

		const_bidirectionnal_iterator &operator=(const const_bidirectionnal_iterator &x)
		{
			if (this != &x)
				_ptr = x._ptr;
			return (*this);
		}

		bool operator==(const const_bidirectionnal_iterator &x) const
		{
			return (_ptr == x._ptr);
		}

		bool operator!=(const const_bidirectionnal_iterator &x) const
		{
			return (_ptr != x._ptr);
		}

		reference operator*() const
		{
			return (_ptr->_node->value);
		}

		pointer operator->() const
		{
			return (&_ptr->_node->value);
		}

		const_bidirectionnal_iterator &operator++()
		{
			_ptr = _ptr->successor(_ptr->_node);
			return (*this);
		}

		const_bidirectionnal_iterator operator++(int)
		{
			const_bidirectionnal_iterator tmp(*this);
			_ptr->_node = _ptr->successor(_ptr->_node);
			return (tmp);
		}

		const_bidirectionnal_iterator &operator--()
		{
			_ptr->_node = _ptr->predecessor(_ptr->node);
			return *this;
		}

		const_bidirectionnal_iterator operator--(int)
		{
			const_bidirectionnal_iterator tmp(*this);
			_ptr->_node = _ptr->predecessor(_ptr->node);
			return tmp;
		}
	};
}

#endif