using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 제네릭 메소드 : 형 매개변수를 갖는 메소드로 DataType 키워드를 통해 정의
// ex) void Swap<DataType>(DataType x, DataType y) { /* ... */ }
namespace ConsoleApp2
{
    internal class GenericMethod
    {
        static void Swap<DataType>(ref DataType x, ref DataType y)
        {
            DataType temp = x;
            x = y;
            y = temp;
        }
        public static void Main()
        {
            int a = 1, b = 2; double c = 1.5, d = 2.5;
            Console.WriteLine("Before: a = {0}, b = {1}", a, b);
            Swap<int>(ref a, ref b);
            Console.WriteLine("After: a = {0}, b = {1}", a, b);
            Console.WriteLine("Before: c = {0}, d = {1}", c, d);
            Swap<double>(ref c, ref d);
            Console.WriteLine("After: c = {0}, d = {1}", c, d);
        }
    }
}
