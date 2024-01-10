using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 예외 처리기의 실행 순서
// 1) try 블록 내에서 예외가 검사되고 또는 명시적으로 예외가 발생하면
// 2) catch 블록을 찾아 처리하고
// 3) 마지막으로 finally 블록을 실행한다
//
// Default 예외 처리기 :
// 시스템 정의 예외가 발생됐는데도 불구하고 프로그래머가 처리하지 않았을 때 작동
// 단순히 에러에 대한 메시지를 출력하고 프로그램을 종료하는 기능
namespace ConsoleApp2
{
    internal class FinallyClause
    {
        static int count = 0;
        static void Main()
        {
            while(true)
            {
                try
                {
                    if (++count == 1) throw new Exception();
                    if (count == 3) break;
                    Console.WriteLine(count + ") No exception");
                } catch(Exception)
                {
                    Console.WriteLine(count + ") Exception thrown");
                } finally
                {
                    Console.WriteLine(count + ") in finally cluase");
                }
            }
            Console.WriteLine("Main program ends");
        }
    }
}
