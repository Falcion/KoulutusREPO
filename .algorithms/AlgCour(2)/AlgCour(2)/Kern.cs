using AlgCour_2_.Objects;

namespace AlgCour_2_
{
    public class Kern
    {
        public static void Main(string[] args)
        {
            //TZ1();
            //Console.WriteLine("-------------------");
            //TZ2();
            //Console.WriteLine("-------------------");
            //TZ45();
            TZ6();
        }

        private static void TZ1()
        {
            AVLTree tree = new AVLTree();
    
            for(int i =0; i < 100; i++)
            {
                tree.root = tree.insert(tree.root, new Random().Next(0, 100));
            }

            DTBT(tree, tree.root);

        }

        public static void DTBT(AVLTree tree, Node node)
        {
            if (node == null) return;

            Console.Out.WriteLine(node + ", " + tree.getBalance(node));

            DTBT(tree, node.left);
            DTBT(tree, node.right);
        }

        private static void TZ2()
        {
            AVLTree tree = new AVLTree();

            tree.root = tree.insert(tree.root, 9);
            tree.root = tree.insert(tree.root, 5);
            tree.root = tree.insert(tree.root, 10);
            tree.root = tree.insert(tree.root, 0);
            tree.root = tree.insert(tree.root, 6);
            tree.root = tree.insert(tree.root, 11);
            tree.root = tree.insert(tree.root, -1);
            tree.root = tree.insert(tree.root, 1);
            tree.root = tree.insert(tree.root, 2);

            DTBT(tree, tree.root);

            Console.WriteLine("DELETE-------------------");
            tree.root = tree.deleteNode(tree.root, 9);

            DTBT(tree, tree.root);
        }

        private static void TZ45()
        {
            RBTree bst = new RBTree();
            bst.insert(55);
            bst.insert(40);
            bst.insert(65);
            bst.insert(60);
            bst.insert(75);
            bst.insert(57);
            RBTree.DTBT(bst.root);

            Console.WriteLine("-------------------");
            bst.deleteNode(40);
            RBTree.DTBT(bst.root);
        }

        private static void TZ6()
        {
            Node root = new(100);

            root.left = new(50);
            root.right = new(200);
            root.left.left = new(40);
            root.left.left.left = new(30);
            root.left.left.left.left = new(20);
            NodeTreePattern.DTBT(root);

            root = SplayTree.Insert(root, 25);

            Console.WriteLine("-------------");

            NodeTreePattern.DTBT(root);

            Console.WriteLine("DELETE");

            root = SplayTree.Delete(root, 20);

            NodeTreePattern.DTBT(root);
        }
    }
}