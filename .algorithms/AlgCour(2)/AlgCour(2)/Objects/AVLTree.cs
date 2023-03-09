namespace AlgCour_2_.Objects
{
    public class AVLTree : NodeTreePattern
    {
        public Node root;

        int height(Node node)
        {
            if (node == null)
                return 0;
            else
                return node.height;
        }

        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        Node rightRotate(Node y)
        {
            Node x = y.left;
            Node T2 = x.right;

            // rotation
            x.right = y;
            y.left = T2;

            // Update heights
            y.height = max(height(y.left),
                        height(y.right)) + 1;
            x.height = max(height(x.left),
                        height(x.right)) + 1;

            return x;
        }

        Node leftRotate(Node x)
        {
            Node y = x.right;
            Node T2 = y.left;

            // Perform rotation
            y.left = x;
            x.right = T2;

            // Update heights
            x.height = max(height(x.left),
                        height(x.right)) + 1;
            y.height = max(height(y.left),
                        height(y.right)) + 1;

            return y;
        }

        int getBalance(Node N)
        {
            if (N == null)
                return 0;

            return height(N.left) - height(N.right);
        }

        public Node insert(Node node, int key)
        {
            if (node == null)
                return (new Node(key));

            if (key < node.key)
                node.left = insert(node.left, key);
            else if (key > node.key)
                node.right = insert(node.right, key);
            else
                return node;

            node.height = 1 + max(height(node.left),
                                height(node.right));

            int balance = getBalance(node);

            // If this node becomes unbalanced
            if (balance > 1 && key < node.left.key)
                return rightRotate(node);

            // Right Right
            if (balance < -1 && key > node.right.key)
                return leftRotate(node);

            // Left Right
            if (balance > 1 && key > node.left.key)
            {
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }

            // Right Left
            if (balance < -1 && key < node.right.key)
            {
                node.right = rightRotate(node.right);
                return leftRotate(node);
            }

            return node;
        }

        /// <summary>
        /// Given a non-empty binary search tree, return the node with minimum key value found in that tree
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        Node minValueNode(Node node)
        {
            Node current = node;

            // loop down to find the leftmost leaf
            while (current.left != null)
                current = current.left;

            return current;
        }

        public Node deleteNode(Node root, int key)
        {
            if (root == null)
                return root;

            // If the key to be deleted is smaller than the root's key, then it lies in left subtree
            if (key < root.key)
                root.left = deleteNode(root.left, key);
            // If the key to be deleted is greater than the root's key, then it lies in right subtree
            else if (key > root.key)
                root.right = deleteNode(root.right, key);
            // if key is same as root's key, then this is the node to be deleted
            else
            {
                if ((root.left == null) || (root.right == null))
                {
                    Node temp = null;
                    if (temp == root.left)
                        temp = root.right;
                    else
                        temp = root.left;

                    // No child case
                    if (temp == null)
                    {
                        temp = root;
                        root = null;
                    }
                    else
                        root = temp;
                }
                else
                {
                    Node temp = minValueNode(root.right);

                    root.key = temp.key;

                    root.right = deleteNode(root.right, temp.key);
                }
            }

            if (root == null)
                return root;

            root.height = max(height(root.left),
                        height(root.right)) + 1;

            int balance = getBalance(root);

            // Left Left Case
            if (balance > 1 && getBalance(root.left) >= 0)
                return rightRotate(root);

            // Left Right Case
            if (balance > 1 && getBalance(root.left) < 0)
            {
                root.left = leftRotate(root.left);
                return rightRotate(root);
            }

            // Right Right Case
            if (balance < -1 && getBalance(root.right) <= 0)
                return leftRotate(root);

            // Right Left Case
            if (balance < -1 && getBalance(root.right) > 0)
            {
                root.right = rightRotate(root.right);
                return leftRotate(root);
            }

            return root;
        }
    }
}
