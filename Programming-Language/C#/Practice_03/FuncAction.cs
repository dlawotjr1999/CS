using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

// Func 델리게이트 : 반환값이 있는 익명 메소드, 무명 함수를 위한 델리게이트 
// Func<parameterType1, paramterType2, ... , returnType>의 형태
// Action 델리게이트 : 반환값이 없는 익명 메소드, 무명 함수를 위한 델리게이트
// Action<parameterType1,parameterType2, ...>의 형태
namespace ConsoleApp3
{
    class FuncClass
    {
        public static int GetNumber()
        {
            return 10;
        }
        public static string ToString(int number) 
        {
            return "Number: " + number;
        }
    }
    class ActionClass
    {
        public static void PrintHello()
        {
            Console.WriteLine("Hello!");
        }
        public static void PrintSum(float a, float b)
        {
            Console.WriteLine("Sum: " + (a + b));
        }
    }
    internal class FuncAction
    {
        static void Main() 
        {
            Func<int> numberFunc = FuncClass.GetNumber;
            int number = numberFunc();
            Console.WriteLine("Number: " + number);

            Func<int, string> toStringFunc = FuncClass.ToString;
            string result = toStringFunc(10);
            Console.WriteLine(result);

            // ----------------------------------------------------

            Action helloAction = ActionClass.PrintHello;
            helloAction();

            Action<float, float> sumAction = ActionClass.PrintSum;
            sumAction(3.5f, 6.5f);
        }


    }
}
