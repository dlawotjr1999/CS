using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class CallByValueRef
    {
        static void Swap(int x, int y)
        {
            int temp;
            temp = x; x = y; y = temp;
            Console.WriteLine("Swap: x = {0}, y = {1}", x, y);
        }
        static void Swap(ref int x, ref int y)
        {
            int temp;
            temp = x; x = y; y = temp;
            Console.WriteLine("Swap: x = {0}, y = {1}", x, y);
        }
        static void Main()
        {
            int x = 1, y = 2;
            Console.WriteLine("Call by Value :");
            Console.WriteLine("Before: x = {0}, y = {1}", x, y);
            Swap(x, y);
            Console.WriteLine("After: x = {0}, y = {1}\n", x, y);

            Console.WriteLine("Call by Reference :");
            Console.WriteLine("Before: x = {0}, y = {1}", x, y);
            Swap(ref x, ref y);
            Console.WriteLine("After: x = {0}, y = {1}", x, y);
        }
    }
}
