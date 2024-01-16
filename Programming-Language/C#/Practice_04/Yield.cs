using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    // yield : 호출자에게 컬렉션 데이터를 하나씩 리턴할 떄 사용됨
    // 흔히 Enumerator라고 불리는 이 기능은 집합적인 데이터셋으로부터 데이트를 하나씩 호출자에게 보내는 역할을 함
    public class MyList
    {
        private int[] data = { 1, 2, 3, 4, 5 };
        public IEnumerator GetEnumerator()
        {
            int i = 0;
            while(i < data.Length)
            {
                yield return data[i];
                i++;
            }
        }
        // ...
    }
    internal class Yield
    {
        static void Main()
        {
            // foreach를 활용한 iteration
            var list = new MyList();
            foreach(var item in list)
            {
                Console.WriteLine(item);
            }

            // 수동 iteration
            IEnumerator it = list.GetEnumerator();
            it.MoveNext();
            Console.WriteLine(it.Current);
            it.MoveNext();
            Console.WriteLine(it.Current);
        }
    }
}
