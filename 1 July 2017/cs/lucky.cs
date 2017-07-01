using System;
using System.Linq;

namespace CshConsoleApplication6
{
    class Program
    {
        private static Boolean IsLucky(Int32 value)
        {
            var digits = value.ToString().Select((c) => c - '0');

            if (digits.Count() != 4) {
                throw new ArgumentException("A lucky number may only have exactly 4 digits.");
            }

            return digits.Take(2).Sum() == digits.Reverse().Take(2).Sum();
        }

        static void Main(String[] args)
        {
            Int32 min = 1000;
            Int32 max = 10 * min;

            var luckyNumbers = Enumerable.Range(min, max - min - 1).Where(IsLucky);

            Console.WriteLine(String.Join(" ", luckyNumbers));
        }
    }
}
