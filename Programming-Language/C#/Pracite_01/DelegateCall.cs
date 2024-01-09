using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    delegate void DelegateOne();
    delegate void DelegateTwo(int i);
    delegate int Sum(int a, int b);   // Anonymous Method
    class DelegateClass
    {
        public void MethodA()
        {
            Console.WriteLine("In the DelegateClass.Method_A ...");
        }
        public void MethodB(int i) 
        {
            Console.WriteLine("DelegateClass.MethodB, i = " + i);
        }
    }
    internal class DelegateCall
    {
        public static void Main()
        {
            DelegateClass obj = new DelegateClass();
            DelegateOne d1 = new DelegateOne(obj.MethodA);
            DelegateTwo d2 = new DelegateTwo(obj.MethodB);
            d1();   // invoke MethodA() in DelegateClass
            d2(10); // invoke MethodB(10) in DelegateClass

            Sum sum;
            sum = delegate (int a, int b)
            {
                return a + b;
            };

            Console.WriteLine("3 + 4 = {0}", sum(3, 4));
        }
    }
}
