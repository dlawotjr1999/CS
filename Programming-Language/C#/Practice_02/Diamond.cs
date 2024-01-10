using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    interface IX { void XMethod(int i); }
    interface IY : IX { void YMethod(int i); }
    class A : IX 
    {
        private int a;
        public int PropertyA
        {
            get { return a; }
            set { a = value; }
        }
        public void XMethod(int i) { a = i; }
    }
    class B : A, IY
    {
        private int b;
        public int PropertyB
        {
            get { return b; } set { b = value; }
        }
        public void YMethod(int i) { b = i; }
    }
    internal class Diamond
    {
        public static void Main()
        {
            B obj = new B();
            obj.XMethod(5); obj.YMethod(10);
            Console.WriteLine("a = {0}, b = {1}", obj.PropertyA, obj.PropertyB);
        }
    }
}
