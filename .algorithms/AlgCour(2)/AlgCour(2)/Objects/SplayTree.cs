using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace AlgCour_2_.Objects
{
    public class SplayTree : NodeTreePattern
    {
        static Node rotateRight(Node node)
        {
            Node y = node.left;
            node.left = y.right;

            y.right = node;

            return y;
        }

        static Node rotateLeft(Node x)
        {
            Node y = x.right;
            x.right = y.left;

            y.left = x;

            return y;
        }

        public static Node Splay(Node root, int key)
        {
            if (root == null || root.key == key)
                return root;

            // Key lies in left subtree
            if (root.key > key)
            {
                // Key is not in tree, we are done
                if (root.left == null) return root;

                // Left Left
                if (root.left.key > key)
                {
                    root.left.left = Splay(root.left.left, key);

                    root = rotateRight(root);
                }
                else if (root.left.key < key) // Left Right
                {
                    // the key as root of left-right
                    root.left.right = Splay(root.left.right, key);

                    if (root.left.right != null)
                        root.left = rotateLeft(root.left);
                }

                // Do second rotation for root
                return (root.left == null) ? root : rotateRight(root);
            }
            else // Key lies in right subtree
            {
                // Key is not in tree, we are done
                if (root.right == null) return root;

                // Right Left
                if (root.right.key > key)
                {
                    // Bring the key as root of right-left
                    root.right.left = Splay(root.right.left, key);

                    // Do first rotation for root.right
                    if (root.right.left != null)
                        root.right = rotateRight(root.right);
                }
                else if (root.right.key < key)// Zag-Zag (Right Right)
                {
                    // Bring the key as root of
                    // right-right and do first rotation
                    root.right.right = Splay(root.right.right, key);
                    root = rotateLeft(root);
                }

                // Do second rotation for root
                return (root.right == null) ? root : rotateLeft(root);
            }
        }

        // Function to insert a new key k
        // in splay tree with given root
        public static Node Insert(Node root, int k)
        {
            if (root == null) return new Node(k);

            // Bring the closest leaf node to root
            root = Splay(root, k);

            // If key is already present, then return
            if (root.key == k) return root;

            // Otherwise allocate memory for new node
            Node newnode = new Node(k);

            if (root.key > k)
            {
                newnode.right = root;
                newnode.left = root.left;
                root.left = null;
            }
            else
            {
                newnode.left = root;
                newnode.right = root.right;
                root.right = null;
            }

            return newnode; // newnode becomes new root
        }
    }
}
