using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 형 매개변수의 제한 예시
// where T : struct - T는 값 형이어야 함
// where T : class - T는 참조형이어야 함
// where T : new() - T는 매개변수가 없는 생성자가 있어야 함
// where T : MyClass - T는 MyClass의 파생 클래스여야 함
// where T : IMyInterface - T는 IMyInterface를 구현한 클래스여야 함
// where T : U - T는 U에서 파생된 클래스여야 함
namespace ConsoleApp2
{
    class GenericType<T> where T : SystemException
    {
        private T value;
        public GenericType(T v) { value = v; }
        public override string ToString()
        {
            return "Type is " + value.GetType();
        }
    }
    internal class BoundedGeneric
    {
        public static void Main()
        {
            GenericType<NullReferenceException> gNullEx = 
                new GenericType<NullReferenceException>(new NullReferenceException());
            GenericType<IndexOutOfRangeException> gIndexEx = 
                new GenericType<IndexOutOfRangeException>(new IndexOutOfRangeException());
            // GenericType<string> gString = new GenericType<String>("Error"); // error!

            Console.WriteLine(gNullEx.ToString());
            Console.WriteLine(gIndexEx.ToString());
        }
    }
}
