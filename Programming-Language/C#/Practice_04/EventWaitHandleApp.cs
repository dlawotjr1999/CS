using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

// EventWaitHandle : 멀티스레딩 환경에서 스레드 간 통신과 동기화를 위해 사용되며 signal과 non-signal 두 가지의 상태를 가지고 있음
// WaitOne 메소드 : 현재 WaitHandle이 신호를 받을 때까지 현재 스레드를 차단함
// Set 메소드 ; 하나 이상의 대기 중인 스레드가 계속 진행되도록 이벤트 상태를 Signal로 설정(반대 : Reset 메소드)
// 참고 : https://learn.microsoft.com/ko-kr/dotnet/api/system.threading.eventwaithandle?view=net-8.0
namespace ConsoleApp4
{
    internal class EventWaitHandleApp
    {
        static void Main()
        {
            // 첫 번째 인자를 false로 설정하여 non-signal로 개체 상태를 설정
            // 두 번째 인자를 ManualReset으로 설정하여 Set 메소드가 호출되어 개체의 상태가 signal로 바꼈을 때 다시 non-signal 상태로 변하지 않게 함
            // 즉 Reset 메소드를 활용하여 개체 상태를 변화시켜야 함
            EventWaitHandle ewh = new EventWaitHandle(false, EventResetMode.ManualReset);
            Thread MyThread = new Thread(Func);
            MyThread.Start(ewh);
            Console.WriteLine("SubThread start...");
            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
            ewh.WaitOne();
            Console.WriteLine("MainThread end...");
        }
        private static void Func(object obj)
        {
            EventWaitHandle ewh = obj as EventWaitHandle;
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
            ewh.Set();
        }
    }
}
