namespace AlgCour_2_.Objects
{
    public class RBNode
    {
        public int key;
        public RBNode left, right, parent;
        public char color;

        public RBNode(int data)
        {
            key = data;
            color = 'R';
        }

        public override string ToString() => (key.ToString() + color);
    }
}
