using System;
using System.Drawing;

namespace AlgCour_2_.Objects
{
    public class RBTree
    {
        public RBNode root;

        RBNode rotateLeft(RBNode node)
        {
            RBNode x = node.right,
                   y = node.left;

            x.left = node;

            node.right = y;
            node.parent = x;

            if (y != null)
                y.parent = node;

            return x;
        }

        RBNode rotateRight(RBNode node)
        {
            RBNode x = node.left,
                   y = x.right;

            x.right = node;

            node.left = y;
            node.parent = x;

            if (y != null)
                y.parent = node;

            return (x);
        }

        // Respective rotations are performed during traceback
        // rotations are done if flags are true
        bool ll = false,
             rr = false,
             lr = false,
             rl = false;
        RBNode insertHelp(RBNode node, int key)
        {
            // f is true when RED RED conflict is there
            bool f = false;

            if (node == null)
                return (new RBNode(key));
            else if (key < node.key)
            {
                node.left = insertHelp(node.left, key);
                node.left.parent = node;
                if (node != root)
                    if (node.color == 'R' && node.left.color == 'R')
                        f = true;
            }
            else
            {
                node.right = insertHelp(node.right, key);
                node.right.parent = node;
                if (node != root)
                {
                    if (node.color == 'R' && node.right.color == 'R')
                        f = true;
                }
                // also we are checking for RED RED conflicts
            }

            if (ll) // for left rotate
            {
                node = rotateLeft(node);
                node.color = 'B';
                node.left.color = 'R';
                ll = false;
            }
            else if (rr) // for right rotate
            {
                node = rotateRight(node);
                node.color = 'B';
                node.right.color = 'R';
                rr = false;
            }
            else if (rl)  // for right and then left
            {
                node.right = rotateRight(node.right);
                node.right.parent = node;
                node = rotateLeft(node);
                node.color = 'B';
                node.left.color = 'R';

                rl = false;
            }
            else if (lr)  // for left and then right
            {
                node.left = rotateLeft(node.left);
                node.left.parent = node;
                node = rotateRight(node);
                node.color = 'B';
                node.right.color = 'R';
                lr = false;
            }
            // when rotation and recolouring is done flags are reset
            // Now lets take care of RED RED conflict
            if (f)
            {
                if (node.parent.right == node)
                {
                    if (node.parent.left == null || node.parent.left.color == 'B')
                    // case when parent's sibling is black
                    {
                        if (node.left != null && node.left.color == 'R')
                            rl = true;
                        else if (node.right != null && node.right.color == 'R')
                            ll = true;
                    }
                    else // case when parent's sibling is red
                    {
                        node.parent.left.color = 'B';
                        node.color = 'B';
                        if (node.parent != this.root)
                            node.parent.color = 'R';
                    }
                }
                else
                {
                    if (node.parent.right == null || node.parent.right.color == 'B')
                    {
                        if (node.left != null && node.left.color == 'R')
                            this.rr = true;
                        else if (node.right != null && node.right.color == 'R')
                            this.lr = true;
                    }
                    else
                    {
                        node.parent.right.color = 'B';
                        node.color = 'B';
                        if (node.parent != this.root)
                            node.parent.color = 'R';
                    }
                }
                f = false;
            }
            return (node);
        }

        // function to insert data into tree
        public void insert(int data)
        {
            if (root == null)
            {
                root = new RBNode(data);
                root.color = 'B';
            }
            else
                root = insertHelp(root, data);
        }

        // Balance the tree after deletion of a node
        private void fixDelete(RBNode node)
        {
            RBNode nodeRight;
            while (node != root && node.color == 'B')
            {
                if (node == node.parent.left)
                {
                    nodeRight = node.parent.right;
                    if (nodeRight.color == 'R')
                    {
                        nodeRight.color = 'B';
                        node.parent.color = 'R';
                        rotateLeft(node.parent);
                        nodeRight = node.parent.right;
                    }

                    if (nodeRight.left.color == 'B' && nodeRight.right.color == 'B')
                    {
                        nodeRight.color = 'R';
                        node = node.parent;
                    }
                    else
                    {
                        if (nodeRight.right.color == 'B')
                        {
                            nodeRight.left.color = 'B';
                            nodeRight.color = 'R';
                            rotateRight(nodeRight);
                            nodeRight = node.parent.right;
                        }

                        nodeRight.color = node.parent.color;
                        node.parent.color = 'B';
                        nodeRight.right.color = 'B';
                        rotateLeft(node.parent);
                        node = root;
                    }
                }
                else
                {
                    nodeRight = node.parent.left;
                    if (nodeRight.color == 'R')
                    {
                        nodeRight.color = 'B';
                        node.parent.color = 'R';
                        rotateRight(node.parent);
                        nodeRight = node.parent.left;
                    }

                    if (nodeRight.right.color == 'B' && nodeRight.right.color == 'B')
                    {
                        nodeRight.color = 'R';
                        node = node.parent;
                    }
                    else
                    {
                        if (nodeRight.left.color == 'B')
                        {
                            nodeRight.right.color = 'B';
                            nodeRight.color = 'R';
                            rotateLeft(nodeRight);
                            nodeRight = node.parent.left;
                        }

                        nodeRight.color = node.parent.color;
                        node.parent.color = 'R';
                        nodeRight.left.color = 'B';
                        rotateRight(node.parent);
                        node = root;
                    }
                }
            }

            node.color = 'R';
        }

        public void deleteNode(int data)
        {
            deleteNodeHelper(this.root, data);
        }

        private void deleteNodeHelper(RBNode node, int key)
        {
            RBNode temp1 = null;
            RBNode p1, p2;
            while (node != null)
            {
                if (node.key == key)
                    temp1 = node;

                if (node.key <= key)
                    node = node.right;
                else
                    node = node.left;
            }

            if (temp1 == null)
            {
                Console.Out.WriteLine("Couldn't find key in the tree");
                return;
            }

            p2 = temp1;

            char p2OriginColor = p2.color;

            if (temp1.left == null)
            {
                p1 = temp1.right;
                rbTransplant(temp1, temp1.right);
            }
            else if (temp1.right == null)
            {
                p1 = temp1.left;
                rbTransplant(temp1, temp1.left);
            }
            else
            {
                p2 = minimum(temp1.right);
                p2OriginColor = p2.color;
                p1 = p2.right;
                if (p2.parent == temp1)
                    p1.parent = p2;
                else
                {
                    rbTransplant(p2, p2.right);
                    p2.right = temp1.right;
                    p2.right.parent = p2;
                }

                rbTransplant(temp1, p2);
                p2.left = temp1.left;
                p2.left.parent = p2;
                p2.color = temp1.color;
            }
            if (p2OriginColor == 0)
            {
                fixDelete(p1);
            }
        }

        public RBNode minimum(RBNode node)
        {
            while (node.left != null)
            {
                node = node.left;
            }
            return node;
        }

        private void rbTransplant(RBNode node1, RBNode? node2)
        {
            if (node1.parent == null)
                root = node2;
            else if (node1 == node1.parent.left)
                node1.parent.left = node2;
            else
                node1.parent.right = node2;

            node2.parent = node1.parent;
        }

        /// <summary>
        /// direct traversal tree showcase
        /// </summary>
        /// <param name="node">given node from start/tree</param>
        public static void DTBT(RBNode? node)
        {
            if (node == null) return;

            Console.Out.WriteLine(node);

            DTBT(node.left);
            DTBT(node.right);
        }

        /// <summary>
        /// reverse traversal tree showcase
        /// </summary>
        /// <param name="node">given node from start/tree</param>
        public static void RTBT(RBNode? node)
        {
            if (node == null) return;

            RTBT(node.left);
            RTBT(node.right);

            Console.Out.WriteLine(node);
        }

        /// <summary>
        /// symmetric/central traversal tree showcase
        /// </summary>
        /// <param name="node">given node from start/tree</param>
        public static void STBT(RBNode? node)
        {
            if (node == null) return;

            STBT(node.left);

            Console.Out.WriteLine(node);

            STBT(node.right);
        }
    }
}
