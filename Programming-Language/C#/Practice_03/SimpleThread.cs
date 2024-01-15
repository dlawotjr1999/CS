using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

// 스레드 프로그래밍 순서
// 1. 스레드 몸체에 해당하는 메소드 작성
// 2. 작성된 메소드를 ThreadStart 델리게이트에 연결
// 3. 생성된 델리게이트를 이용하여 스레드 객체를 생성
// 4. 스레드의 실행을 시작(Start() 메소드를 통해 호출)
namespace ConsoleApp3
{
    internal class SimpleThread
    {
        static void ThreadBody()
        {
            for(int i = 0; i < 5; i++) // 1
            {
                Console.WriteLine(DateTime.Now.Second + " : " + i);
                Thread.Sleep(1000);
            }
        }
        static void Main()
        {
            ThreadStart ts = new ThreadStart(ThreadBody); // 2
            Thread t = new Thread(ts);  // 3
            Console.WriteLine("*** Start of Main");
            t.Start();  // 4
            Console.WriteLine("*** End of Main");
        }
    }
}
