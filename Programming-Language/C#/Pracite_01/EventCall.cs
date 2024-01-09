using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// 이벤트 정의 순서 :
// 1. 이벤트 처리기의 형태와 일치하는 delegate 정의
// 2. delegate를 이용하여 이벤트를 선언
// 3. 이벤트 처리기 작성
// 4. 이벤트에 이벤트 처리기를 등록
// 5. 이벤트를 발생(미리 정의된 이벤트는 사용자 행동에 의해 이벤트가 발생)
// * 이벤트가 발생되면 등록된 메소드가 호출되어 이벤트를 처리함
namespace ConsoleApp1
{
    public delegate void MyEventHandler(); // 1
    class Button
    {
        public event MyEventHandler Push; // 2
        public void OnPush()
        {
            if(Push != null) Push(); // 5
        }
    }
    class EventHandlerClass
    {
        public void MyMethod() // 3
        {
            Console.WriteLine("in the EventHandlerClass.MyMehod...");
        }
    }
    internal class EventCall
    {
        public static void Main()
        {
            Button btn = new Button();
            EventHandlerClass obj = new EventHandlerClass();
            btn.Push += new MyEventHandler(obj.MyMethod); // 4
            btn.OnPush();
        }
    }
}
