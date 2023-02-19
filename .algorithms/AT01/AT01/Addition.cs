using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AT01
{
    public class Client
    {
        public string Name { get; set; }

        public string[]? Numbers { get; set; }

        public Client? Left { get; set; }
        public Client? Right { get; set; }

        public Client(string name, string[]? numbers)
        {
            this.Name = name;
            this.Numbers = numbers;
        }
    }
}
