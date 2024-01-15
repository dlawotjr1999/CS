using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    delegate int Calculate(int a, int b);
    delegate void DoSomething();
    internal class Lambda
    {
        static void Main()
        {
            Calculate calc = (int a, int b) => a + b;
            // Calculate calc = (a, b) => a + b; (Type Inference)
            DoSomething dolt = () =>
            {
                Console.WriteLine("Do Something...");
                Console.WriteLine("Do Something continue...");
            };

            calc(3, 4);
            dolt();
        }
    }
}
