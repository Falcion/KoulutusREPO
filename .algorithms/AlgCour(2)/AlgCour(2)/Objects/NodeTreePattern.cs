using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlgCour_2_.Objects
{
    public class NodeTreePattern
    {
        /// <summary>
        /// direct traversal tree showcase
        /// </summary>
        /// <param name="node">given node from start/tree</param>
        public static void DTBT(Node? node)
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
        public static void RTBT(Node? node)
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
        public static void STBT(Node? node)
        {
            if (node == null) return;

            STBT(node.left);

            Console.Out.WriteLine(node);

            STBT(node.right);
        }
    }
}
