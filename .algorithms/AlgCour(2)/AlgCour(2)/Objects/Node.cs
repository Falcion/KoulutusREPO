namespace AlgCour_2_.Objects
{
    public class Node
    {
        public int key, height;
        public Node left, right;

        public Node(int data)
        {
            key = data;
            height = 1;
        }

        public override string ToString() => key.ToString();
    }
}
