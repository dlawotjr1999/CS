using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class ParameterArray
    {
        // 매개변수 배열 : 실 매개변수의 갯수가 상황에 따라 가변적인 경우
        // ex1) void ParameterArray1(params int[] args) { /* ... */ }
        // ex2) void ParameterArray(params object[] obj) { /* ... */ }
        static void ParamArray(params object[] obj)
        {
            for(int i = 0; i < obj.Length; i++)
                Console.WriteLine(obj[i]);
        }
        static void Main()
        {
            ParamArray(123, "Hello", true, 'A');
        }
    }
}
