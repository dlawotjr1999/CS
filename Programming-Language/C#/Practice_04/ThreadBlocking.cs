using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

// Join 메소드 :  현재 스레드 객체의 작업이 완료되거나 종료될 때까지 기본 스레드의 실행을 대기하도록 함
// Join() 메소드를 사용하여 동기화를 작업을 수행할 수 있으며, 특정 스레드 객체의 작업이 종료되었는지 확인할 수 있음
namespace ConsoleApp4
{
    internal class ThreadBlocking
    {
        static void Main()
        {
            Thread MyThread = new Thread(Func);
            MyThread.Start();
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
            MyThread.Join();
            Console.WriteLine("MainThread end..");
        }
        private static void Func()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
        }
    }
}
