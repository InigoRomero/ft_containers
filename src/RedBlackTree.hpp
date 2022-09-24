#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "pair.hpp"
#include "BSTNode.hpp"

namespace ft
{
  template < class value_type> 
  class RedBlackTree {
    private:
          typedef BSTNode<value_type>               *BSTNodePtr;

    public:
        BSTNodePtr _node;
        BSTNodePtr TNULL;

        RedBlackTree() {
          TNULL = new BSTNode<value_type>;
          TNULL->color = 0;
          TNULL->left = NULL;
          TNULL->right = NULL;
          _node = TNULL;
        }

        void initializeNULLBSTNode(BSTNodePtr node) {
          node->parent = TNULL;
          node->left = TNULL;
          node->right = TNULL;
          node->color = 0;
        }

        // Preorder
        void preOrderHelper(BSTNodePtr node) {
          if (node != TNULL) {
            preOrderHelper(node->left);
            preOrderHelper(node->right);
          }
        }

        // Inorder
        void inOrderHelper(BSTNodePtr node) {
          if (node != TNULL) {
            inOrderHelper(node->left);
            inOrderHelper(node->right);
          }
        }

        // Post order
        void postOrderHelper(BSTNodePtr node) {
          if (node != TNULL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
          }
        }

        BSTNodePtr searchTreeHelper(BSTNodePtr node, int key) {
          if (node == TNULL || key == _node->value) {
            return node;
          }

          if (key < _node->value) {
            return searchTreeHelper(node->left, key);
          }
          return searchTreeHelper(node->right, key);
        }

        // For balancing the tree after deletion
        void deleteFix(BSTNodePtr x) {
          BSTNodePtr s;
          while (x != _node && x->color == 0) {
            if (x == x->parent->left) {
              s = x->parent->right;
              if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                s = x->parent->right;
              }

              if (s->left->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
              } else {
                if (s->right->color == 0) {
                  s->left->color = 0;
                  s->color = 1;
                  rightRotate(s);
                  s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotate(x->parent);
                x = _node;
              }
            } else {
              s = x->parent->left;
              if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                s = x->parent->left;
              }

              if (s->right->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
              } else {
                if (s->left->color == 0) {
                  s->right->color = 0;
                  s->color = 1;
                  leftRotate(s);
                  s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotate(x->parent);
                x = _node;
              }
            }
          }
          x->color = 0;
        }

        void rbTransplant(BSTNodePtr u, BSTNodePtr v) {
          if (u->parent == NULL) {
            _node = v;
          } else if (u == u->parent->left) {
            u->parent->left = v;
          } else {
            u->parent->right = v;
          }
          v->parent = u->parent;
        }

        void deleteBSTNodeHelper(BSTNodePtr node, int key) {
          BSTNodePtr z = TNULL;
          BSTNodePtr x, y;
          while (node != TNULL) {
            if (_node->value == key) {
              z = node;
            }

            if (_node->value <= key) {
              node = node->right;
            } else {
              node = node->left;
            }
          }

          if (z == TNULL) {
            //std::cout << "Key not found in the tree" << std::endl;
            return;
          }

          y = z;
          int y_original_color = y->color;
          if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
          } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
          } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
              x->parent = y;
            } else {
              rbTransplant(y, y->right);
              y->right = z->right;
              y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
          }
          delete z;
          if (y_original_color == 0) {
            deleteFix(x);
          }
        }

		void copyTree(BSTNodePtr &x) {
			if (x->right != NULL || x->left != NULL) {
				BSTNodePtr node = new BSTNode<const value_type>(x->value);
				_node = node;
				_node->color = x->color;
				_node->left   = x->left;
				_node->right  = x->right;
				_node->parent = x->parent;

				copyTree(x->left);
				copyTree(x->right);
			}

        }

        void printHelper(BSTNodePtr _node, std::string indent, bool last) {
          if (_node != TNULL) {
            std::cout << indent;
            if (last) {
            	std::cout << "R----";
            	indent += "   ";
            } else {
              std::cout << "L----";
              indent += "|  ";
            }

            std::string sColor = _node->color ? "RED" : "BLACK";
            std::cout << _node->value.first << "(" << sColor << ")" << std::endl;
            printHelper(_node->left, indent, false);
            printHelper(_node->right, indent, true);
          }
        }

        void preorder() {
          preOrderHelper(this->_node);
        }

        void inorder() {
          inOrderHelper(this->_node);
        }

        void postorder() {
          postOrderHelper(this->_node);
        }

        BSTNodePtr searchTree(int k) {
          return searchTreeHelper(this->_node, k);
        }

        BSTNodePtr minimum(BSTNodePtr node) const {
          while (node->left != TNULL)
            node = node->left;
          return node;
        }

        BSTNodePtr maximum(BSTNodePtr node) const {
          while (node->right != TNULL)
            node = node->right;
          return node;
        }

        BSTNodePtr successor(BSTNodePtr &x) {
          if (x->right != TNULL) {
            return minimum(x->right);
          }

          BSTNodePtr y = x->parent;
          while (y != TNULL && x->value.first == y->right->value.first) {
            x = y;
            y = y->parent;
          }
          return y;
        }

        BSTNodePtr predecessor(BSTNodePtr x) {
          if (x->left != TNULL) {
            return maximum(x->left);
          }

          BSTNodePtr y = x->parent;
          while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
          }

          return y;
        }

        void leftRotate(BSTNodePtr x) {
          BSTNodePtr y = x->right;
          x->right = y->left;
          if (y->left != TNULL) {
            y->left->parent = x;
          }
          y->parent = x->parent;
          if (x->parent == NULL) {
            this->_node = y;
          } else if (x == x->parent->left) {
            x->parent->left = y;
          } else {
            x->parent->right = y;
          }
          y->left = x;
          x->parent = y;
        }

        void rightRotate(BSTNodePtr x) {
          BSTNodePtr y = x->left;
          x->left = y->right;
          if (y->right != TNULL) {
            y->right->parent = x;
          }
          y->parent = x->parent;
          if (x->parent == NULL) {
            this->_node = y;
          } else if (x == x->parent->right) {
            x->parent->right = y;
          } else {
            x->parent->left = y;
          }
          y->right = x;
          x->parent = y;
        }

        // Inserting a node
        BSTNodePtr insert(const value_type& val) {
          BSTNodePtr node = new BSTNode<value_type>(val);
          node->parent = TNULL;
          node->left = TNULL;
          node->right = TNULL;
          node->color = 1;

          BSTNodePtr y = NULL;
          BSTNodePtr x = this->_node;
          while (x != TNULL) {
            y = x;
            if (node->value < x->value) {
              x = x->left;
            } else {
              x = x->right;
            }
          }
          node->parent = y;
          if (y == NULL) {
            _node = node;
          } else if (node->value < y->value) {
            y->left = node;
          } else {
            y->right = node;
          }
          if (node->parent == NULL) {
            node->color = 0;
            return node;
          }
          if (node->parent->parent == NULL) {
            return node;
          }
          return insertFix(node);
        }

        // For balancing the tree after insertion
        BSTNodePtr insertFix(BSTNodePtr k) {
          BSTNodePtr u;
          while (k->parent && k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
              u = k->parent->parent->left;
              if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
              } else {
                if (k == k->parent->left) {
                  k = k->parent;
                  rightRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
              }
            } else {
              u = k->parent->parent->right;
              if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                //std::cout << "Value of k->parent: " << k->parent->value.second << "second parent: " << k->parent->parent->value.second   << "| I am not rotating 2 \n";
                k = k->parent->parent;
              } else {
                if (k == k->parent->right) {
                  k = k->parent;
                  leftRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
              }
            }
            if (k == _node) {
            	break;
            }
          }

          _node->color = 0;

          return (k);
        }

        BSTNodePtr getRoot() {
          return this->_node;
        }

        void deleteBSTNode(value_type value) {
          deleteBSTNodeHelper(this->_node, value);
        }

        void printTree() {
          if (_node) {
            printHelper(this->_node, "", true);
          }
        }
  };
}
#endif
