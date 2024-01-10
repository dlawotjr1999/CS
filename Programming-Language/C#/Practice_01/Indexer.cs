using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    // 인덱서 : 배열 연산자인 []를 통해서 객체를 다를 수 있게 함
    // 지정어 this를 사용하고 []안에 인덱스로 사용되는 매개 변수 선언
    // get 혹은 set 접근자만 정의할 수 있음
    // [indexer-modifiers] returnType this[parameterList] { /* ... */ }의 형태
    class Color
    {
        private string[] color = new string[5];
        public string this[int index]
        {
            get { return color[index]; }
            set { color[index] = value; }
        }
    }
    internal class Indexer
    {
        static void Main()
        {
            Color c = new Color();
            c[0] = "WHITE"; c[1] = "RED";
            c[2] = "YELLOW"; c[3] = "BLUE";
            c[4] = "BLACK";

            for (int i = 0; i < 5; i++)
                Console.WriteLine("Color is " + c[i]);
        }
    }
}
