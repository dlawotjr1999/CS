using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    interface IGenericInterface<T>
    {
        void SetValue(T x);
        string GetValueType();
    }
    class GenericClass<T> : IGenericInterface<T>
    {
        private T value;
        public void SetValue(T x)
        {
            value = x;
        }
        public string GetValueType()
        {
            return value.GetType().ToString();
        }
    }
    internal class GenericInterface
    {
        public static void Main()
        {
            GenericClass<Int32> gInteger = new GenericClass<Int32>();
            GenericClass<String> gString = new GenericClass<string>();

            gInteger.SetValue(10);
            gString.SetValue("Text");

            Console.WriteLine(gInteger.GetValueType());
            Console.WriteLine(gString.GetValueType());
        }
    }
}
