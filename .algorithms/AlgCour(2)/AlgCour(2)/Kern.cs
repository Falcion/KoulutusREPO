using AlgCour_2_.Objects;

namespace AlgCour_2_
{
    public class Kern
    {
        public static void Main(string[] args)
        {
            //TZ1();
            Console.WriteLine("-------------------");
            //TZ2();
            Console.WriteLine("-------------------");
            //TZ45();
        }

        private static void TZ1()
        {
            AVLTree tree = new AVLTree();

            tree.root = tree.insert(tree.root, 10);
            tree.root = tree.insert(tree.root, 20);
            tree.root = tree.insert(tree.root, 30);
            tree.root = tree.insert(tree.root, 40);
            tree.root = tree.insert(tree.root, 50);
            tree.root = tree.insert(tree.root, 25);

            AVLTree.DTBT(tree.root);
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

            AVLTree.DTBT(tree.root);

            Console.WriteLine("-------------------");
            tree.root = tree.deleteNode(tree.root, 10);

            AVLTree.DTBT(tree.root);
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
            root = SplayTree.Insert(root, 25);

            Console.WriteLine("-------------");

            NodeTreePattern.DTBT(root);
        }
    }
}