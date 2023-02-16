using System.Xml;

namespace AT01
{
    public class Node
    {
        public Node? Left { get; set; }
        public Node? Right { get; set; }

        public Node(int data)
        {
            this.Data = data;
        }

        int Depth(Node? node)
        {
            if(node == null) return 0;
            else
            {
                int left_depth = Depth(node.Left);
                int right_depth = Depth(node.Right);

                if (left_depth > right_depth)
                    return left_depth + 1;
                else
                    return right_depth + 1;
            }
        }

        public int Data { get; set; }
    }

    public static class Kern
    {
        static Node Inject(Node? root, int data)
        {
            if (root == null) root = new Node(data);
            else if (data <= root.Data) root.Left = Inject(root.Left, data);
            else if (data > root.Data) root.Right = Inject(root.Right, data);

            return root;
        }

        static Node? Find(Node? node, int data)
        {
            if (node == null) return null;

            if(node.Data == data) return node;
            else if(node.Data < data) return Find(node.Right, data);
            else if(node.Data > data) return Find(node.Left, data);

            return node;
        }

        static void Delete(Node? node, int data)
        {
            if (node == null) return;

            if(node.Left == null && node.Right == null)
            {
                if (node.Data == data)
                {
                    return;
                }
                else
                    return;
            }

            Queue<Node> queue = new();

            queue.Enqueue(node);

            Node? temp = null, key_node = null;

            while(queue.Count > 0)
            {
                temp = queue.Peek();
                queue.Dequeue();

                if(temp.Data == data)
                    key_node= temp;
                if(temp.Left != null)
                    queue.Enqueue(temp.Left);
                if(temp.Right != null)
                    queue.Enqueue(temp.Right);
            }

            if(key_node != null)
            {
                int x = temp!.Data;

                DeleteDEEP(node, temp);

                key_node.Data = x;
            }
        }
#pragma warning restore S1144 // Unused private types or members should be removed

        static void DeleteDEEP(Node? node, Node delete_node)
        {
            if (node == null) return;

            Queue<Node> queue = new();

            queue.Enqueue(node);

            while (queue.Count > 0)
            {
                Node? temp = queue.Peek();
                queue.Dequeue();

                if (temp == delete_node)
                {
                    return;
                }
                if (temp.Right != null)
                {
                    if (temp.Right == delete_node)
                    {
                        temp.Right = null;
                        return;
                    }

                    else
                        queue.Enqueue(temp.Right);
                }

                if (temp.Left != null)
                {
                    if (temp.Left == delete_node)
                    {
                        temp.Left = null;
                        return;
                    }
                    else
                        queue.Enqueue(temp.Left);
                }
            }
        }

        static void DTBT(Node? node)
        {
            if(node == null) return;

            Console.Out.WriteLine(node.Data);

            DTBT(node.Left);
            DTBT(node.Right);
        }

        static void RTBT(Node? node)
        {
            if(node == null) return;

            RTBT(node.Left);
            RTBT(node.Right);

            Console.Out.WriteLine(node.Data);
        }

        static void STBT(Node? node)
        {
            if(node == null) return;

            STBT(node.Left);

            Console.Out.WriteLine(node.Data);

            STBT(node.Right);
        }

        public static void Main(string[] args)
        {
            throw new NotImplementedException();
        }
    }
}