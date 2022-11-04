using System;

namespace Archiver
{
    class Program 
    {         
        static void Main(string[] args)
        {
            string s = "ПРИВЕТ!";
            for (int i = 0; i < s.Length; i++)
            {
                Console.WriteLine(s[i]);
            }
        }
    }
}