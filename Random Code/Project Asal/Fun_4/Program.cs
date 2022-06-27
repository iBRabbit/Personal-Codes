using System;
using System.Collections;

namespace Fun_4
{
    class Fun{
        private String name;
        private int valueInt;
        private double valueDouble;

        public Fun(string name, int valueInt, double valueDouble){
            this.name = name;
            this.valueInt = valueInt;
            this.valueDouble = valueDouble;
            Console.WriteLine("Created!");
        }

        public String getName() { return name; }
        public int getInt() { return valueInt; }
        public double getDouble() { return valueDouble; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = new int[100];
            ArrayList arrList = new ArrayList();
            Console.WriteLine(arr.Length);
            arrList.Add(100);
            arrList.Add(1002);
            arrList.Add("Hai");
            Console.WriteLine(arrList.Count);
            Console.WriteLine(arrList[2]);
            for (int i = 0; i < arrList.Count; i++){
                Console.WriteLine(arrList[i]);
            }

            Fun fun1 = new Fun("Felix", 10, 10.0);
            int x = fun1.getInt();
            Console.WriteLine();
        }
    }
}
