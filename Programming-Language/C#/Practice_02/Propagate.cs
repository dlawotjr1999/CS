using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Propagate
    {
        void Orange()
        {
            int i = 25, j = 0;
            i = i / j;
            Console.WriteLine("End of Orange method");
        }
        void Apple()
        {
            Orange();
            Console.WriteLine("End of Apple method");
        }
        static void Main()
        {
            Propagate p = new Propagate();
            try
            {
                p.Apple();
            }
            catch(ArithmeticException)
            {
                Console.WriteLine("ArithmeticException is processed");
            }
            Console.WriteLine("End of Main");
        }
    }
}
