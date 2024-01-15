using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization;
using System.Threading.Tasks;

[Serializable]
public class DataObject
{
    public int num1;
    public int num2;
}
namespace ConsoleApp3
{
    internal class Serialization
    {
        static void Main()
        {
            DataObject data1 = new DataObject();
            data1.num1 = 1;
            data1.num2 = 2; 

            IFormatter formatter = new BinaryFormatter();

            // Serialization
            Stream streamFileWrite = new FileStream("test.txt", FileMode.Create, FileAccess.Write, FileShare.None);
            formatter.Serialize(streamFileWrite, data1);
            streamFileWrite.Close();

            // Deserializtion
            Stream streamFileRead = new FileStream("test.txt", FileMode.Open, FileAccess.Read, FileShare.None);
            DataObject data2 = (DataObject)formatter.Deserialize(streamFileRead);
            streamFileRead.Close();

            Console.WriteLine("num1 :" + data2.num1);
            Console.WriteLine("num2 : " + data2.num2);
        }
    }
}
