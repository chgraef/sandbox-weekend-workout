using System;
using System.Collections.Generic;
using System.Linq;

namespace CshConsoleApplication10
{
    static class Extensions
    {
        private static IEnumerable<Int32> IncrementCount(Int32 start = 0)
        {
            while (true) yield return start++;
        }

        public static IEnumerable<KeyValuePair<Int32, T>> Enumerate<T>(this IEnumerable<T> enumer, Int32 start = 0)
        {
            if (enumer == null) {
                throw new ArgumentNullException("enumer");
            }
            
            return Enumerable.Zip(enumer, IncrementCount(start), 
                                     (x, i) => new KeyValuePair<Int32, T>(i, x));
        }
    }

    sealed class Program
    {
        static void Main(String[] args)
        {
            var emperors = new String[] { "Louis I", "Louis II", "Louis III" };

            foreach (var ordinalAndEmperorPair in emperors.Enumerate(start: -1)) 
            {
                var index   = ordinalAndEmperorPair.Key;
                var emperor = ordinalAndEmperorPair.Value;

                Console.WriteLine("{0}, {1}", index, emperor);
            }
        }
    }
}

