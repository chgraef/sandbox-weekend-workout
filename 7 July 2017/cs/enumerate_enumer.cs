using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace CshConsoleApplication10
{
    static class Extensions
    {
        public static IEnumerable<KeyValuePair<T, Int32>> Enumerate<T>(this IEnumerable<T> enumer, Int32 start = 0)
        {
            if (enumer == null) {
                throw new ArgumentNullException("enumer");
            }
        
            var count = start;

            foreach (var item in enumer) 
            {
                yield return new KeyValuePair<T, int>(item, count);
                ++count;
            }
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

