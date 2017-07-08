using System;
using System.Collections.Generic;
using System.Linq;

namespace CshConsoleApplication9
{
    static class Extensions
    {
        internal static IEnumerable<T> Compact<T>(this IEnumerable<T> enumer)
        {
            if (enumer == null) {
                throw new NullReferenceException("enumer");
            }

            return enumer.Where((x) => x != null);
        }
    }

    sealed class Program
    {
        private static void PrintWithNulls<T>(IEnumerable<T> enumer)
        {
            if (enumer == null) {
                throw new ArgumentNullException("enumer");
            }

            foreach (var item in enumer) {
                Console.Write("{0} ", item?.ToString() ?? "null");
            }

            Console.WriteLine();
        }

        static void Main(String[] args)
        {
            var strings = new String[] { 
                "Pompey",   null, "Claudius", null, 
                "Caligula", null, null 
            };

            var compactedStrings = strings.Compact();

            PrintWithNulls(strings);
            PrintWithNulls(compactedStrings);

            var numbers = new Int32[] { 0, 1, 2 };
            var numbersCompacted = numbers.Compact();

            PrintWithNulls(numbers);
            PrintWithNulls(numbersCompacted);
        }
    }
}

